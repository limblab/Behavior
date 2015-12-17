/* $Id: mastercon_cuecomb.cpp 2015-01-07
 *
 * Master Control block for behavior: cue combination on the circle
 */
 
//#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_cuecomb
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL	0
#define STATE_CT_ON		1
#define STATE_CT_HOLD	2
#define STATE_BUMP_OUT  3
#define STATE_BUMP_IN	4
#define STATE_CT_DELAY	5
#define STATE_MOVEMENT	6
#define STATE_OT_HOLD	7

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */
	
#define DATABURST_VERSION ((byte)0x01) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {

	real_T master_reset;
	// Time Bounds for various timers
	real_T center_hold_l;
	real_T center_hold_h;
	real_T center_delay_l;
	real_T center_delay_h;
	real_T intertrial;
	real_T movement_time;	  // maximum allowed movement time
	real_T failure_lag;       // penalty lag for failed movements

	real_T movement_length;   // i.e. movement length
	real_T target_size;       // width of center target
	real_T OT_size;			  // size of outer target
	real_T OT_depth;
	real_T center_X_offset;   // offset of the center along x axis
	real_T center_Y_offset;   // offset of the center along y axis

	// parameters determining the visual uncertainty
	real_T prior_mean;
	real_T prior_kap;

	// currently supports up to four feedback cloud uncertainties
	real_T cloud_kap_one;
	real_T cloud_kap_two;
	real_T cloud_kap_three;
	real_T cloud_kap_four;
	// relative frequency of occurrence for each cloud (arbitrary units)
	real_T cloud_freq_one;
	real_T cloud_freq_two;
	real_T cloud_freq_three;
	real_T cloud_freq_four;
	
	// up to three different bump levels
	real_T use_random_bump;
	real_T random_bump_low;
	real_T random_bump_high;
	real_T bump_mag_one;
	real_T bump_mag_two;
	real_T bump_mag_three;
	// relative frequency of occurence for each bump magnitude
	real_T bump_freq_one;
	real_T bump_freq_two;
	real_T bump_freq_three;

	real_T bump_duration;
	real_T bump_duration_back;
	real_T Gain_pos;
	real_T Gain_vel;

	real_T cloud_one_blank_mode; // toggles blank feedback (no cloud) for "cloud one"

	real_T slice_size;    // size of each slice in cloud
	real_T slice_number;	 // number of slices in the cloud

	real_T delay_catch_freq;
	real_T delay_catch_l;
	real_T delay_catch_h;
	
	real_T use_cohack_mode;
	real_T cohack_tgtnum;

	real_T stim_prob;

	real_T pos_filt; 
	real_T vel_filt;

	real_T NoReturn;

	real_T feedback_win;

	real_T training;

	real_T use_force_bump;
	real_T force_rise_time;
	real_T force_peak_time;
    
    real_T bump_sampling_method;  // 0 for equally sampled bumps in cartesian space, 1 for equally sampled bumps in joint space.
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME cuecombBehavior
class cuecombBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	cuecombBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    Point cursorOffset;

	PosBumpGenerator *bump;
	CosineBumpGenerator *bumpF;

	bool stim_trial;
	
	// Your behavior's instance variables
	Point  center_offset; // center target offset
	double current_trial_shift;  // current trial displacement
	double  target_shift;  // current trial cursor shift
	Point  cursor_end_point; // current trial end point
	double cursor_extent;  // distance from center in direction of target
	double current_trial_bumpmag; // current trial bump magnitude

	double  slice_points[10];
	double current_target_stdev; // current trial feedback variance
	bool   cloud_blank;       // toggles current trial, blank feedback
	bool   cohack_mode;
	bool   random_bump_mode;
	bool   force_bump_mode;

	Point bump_offset;

	double center_hold_time, center_delay_time, outer_hold_time;

	Point  previous_position; // for calculating speed
	double previous_time_point;

	double x_pos;
	double y_pos;
	double x_pos_old;
    double y_pos_old;
    
	double x_vel;
	double y_vel;
    double x_vel_old;
    double y_vel_old;
    
	CircleTarget    *centerTarget;
	ArcTarget		*outerTarget;
	ArcTarget		*targetBar;
	ArcTarget		*cloud[10];
	SquareTarget    *timerTarget;
	LocalParams     *params;

	// helper functions
	void doPreTrial(SimStruct *S);
	void updateCursorExtent(SimStruct *S); // updates cursor extent (used for windowing)

};

cuecombBehavior::cuecombBehavior(SimStruct *S) : RobotBehavior() {

	int i;
	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(55);

	this->bindParamId(&params->master_reset,		0);
	
	this->bindParamId(&params->center_hold_l,		1);
	this->bindParamId(&params->center_hold_h,		2);

	this->bindParamId(&params->center_delay_l,		3);
	this->bindParamId(&params->center_delay_h,		4);
	this->bindParamId(&params->intertrial,			5);
	this->bindParamId(&params->movement_time,		6);	 
	this->bindParamId(&params->failure_lag,			7);       
	this->bindParamId(&params->movement_length,		8);  
	this->bindParamId(&params->target_size,			9);       
	this->bindParamId(&params->OT_size,				10);			
	this->bindParamId(&params->OT_depth,			11);
	this->bindParamId(&params->center_X_offset,		12);   
	this->bindParamId(&params->center_Y_offset,		13);   
	this->bindParamId(&params->prior_mean,			14);
	this->bindParamId(&params->prior_kap,			15);
	
	this->bindParamId(&params->cloud_kap_one,		16);
	this->bindParamId(&params->cloud_kap_two,		17);
	this->bindParamId(&params->cloud_kap_three,		18);
	this->bindParamId(&params->cloud_kap_four,		19);

	this->bindParamId(&params->cloud_freq_one,		20);
	this->bindParamId(&params->cloud_freq_two,		21);
	this->bindParamId(&params->cloud_freq_three,	22);
	this->bindParamId(&params->cloud_freq_four,		23);

	this->bindParamId(&params->cloud_one_blank_mode,24); 
	this->bindParamId(&params->slice_size,			25);    
	this->bindParamId(&params->slice_number,		26);	
	
	this->bindParamId(&params->delay_catch_freq,	27);
	this->bindParamId(&params->delay_catch_l,		28);
	this->bindParamId(&params->delay_catch_h,		29);
	this->bindParamId(&params->use_cohack_mode,		30);
	this->bindParamId(&params->cohack_tgtnum,		31);
	
	this->bindParamId(&params->use_random_bump,		32);	
	this->bindParamId(&params->random_bump_low,		33);
	this->bindParamId(&params->random_bump_high,	34);

	this->bindParamId(&params->bump_mag_one,		35);
	this->bindParamId(&params->bump_mag_two,		36);
	this->bindParamId(&params->bump_mag_three,		37);

	this->bindParamId(&params->bump_freq_one,		38);
	this->bindParamId(&params->bump_freq_two,		39);
	this->bindParamId(&params->bump_freq_three,		40);

	this->bindParamId(&params->bump_duration,		41);
    this->bindParamId(&params->Gain_pos,			42);
	this->bindParamId(&params->Gain_vel,			43);

	this->bindParamId(&params->stim_prob,			44);

	this->bindParamId(&params->pos_filt,			45);
	this->bindParamId(&params->vel_filt,			46);

	this->bindParamId(&params->bump_duration_back,	47);
	this->bindParamId(&params->NoReturn,			48);
	
	this->bindParamId(&params->feedback_win,		49);
	this->bindParamId(&params->training,			50);

	this->bindParamId(&params->use_force_bump,		51); 
	this->bindParamId(&params->force_rise_time,		52); 
	this->bindParamId(&params->force_peak_time,		53);
    
    this->bindParamId(&params->bump_sampling_method, 54);


	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

	centerTarget	= new CircleTarget(0,0,0,0);
	outerTarget		= new ArcTarget(0,0,0,0,5);
	targetBar		= new ArcTarget(0,0,0,0,8);
	timerTarget		= new SquareTarget(0,0,0,0);

	for (i=0; i<10; i++) {
		cloud[i] = new ArcTarget(0,0,0,0,5);
	}
	this->stim_trial = false;

	this->bump = new PosBumpGenerator();
	this->bumpF = new CosineBumpGenerator();


	x_pos_old = 0;
    y_pos_old = 0;
    
    x_vel_old = 0;
    y_vel_old = 0;

	cursor_extent		 = 0.0;
	current_trial_shift  = 0.0;
	current_target_stdev = 0.0;
	target_shift         = 0.0;
	center_offset.x	     = 0.0;
	center_offset.y	     = 0.0;
	previous_position.x  = 0.0;
	previous_position.y  = 0.0;
	cursor_end_point.x   = 0.0;
	cursor_end_point.y   = 0.0;
	center_hold_time     = 0.0;
	center_delay_time    = 0.0;
	outer_hold_time	     = 0.0;
	previous_time_point  = 0.0;
	bump_offset.x		 = 0.0;
	bump_offset.y		 = 0.0;
	cloud_blank          = false;
	cohack_mode			 = false;
	random_bump_mode	 = false;
    
    // % Code for getting string of values in Matlab. Copy it below.
    //     temp = num2str(cart_angles_even(1),6)
    //     for i = 2:210
    //         temp = [temp ', ' num2str(cart_angles_even(i),6)];
    //     end

}
void cuecombBehavior::updateCursorExtent(SimStruct *S){
	cursor_extent = sqrt((inputs->cursor.x-bump_offset.x)*(inputs->cursor.x-bump_offset.x)
					   + (inputs->cursor.y-bump_offset.y)*(inputs->cursor.y-bump_offset.y));
}

void cuecombBehavior::doPreTrial(SimStruct *S) {
	int i;
	double total_cloud_freq;
	double actual_freq_one;
	double actual_freq_two;
	double actual_freq_three;
	double actual_freq_four;
	double cloud_rand;
	double bump_rand;
	double act_bf_one;
	double act_bf_two;
	double act_bf_three;
	double total_bump_freq;
	double vel_from_dist;
    
    //real_T bump_directions_list_even_joint_space[] = {0.159638, 0.174352, 0.188741, 0.202835, 0.216661, 0.230247, 0.243616, 0.256794, 0.269803, 
    //    0.282665, 0.295401, 0.308032, 0.320577,
    //    0.333056, 0.345487, 0.35789, 0.370283, 0.382685, 0.395114, 0.40759, 0.42013, 0.432756, 0.445486, 0.458342, 0.471343, 0.484514, 
    //    0.497875, 0.511452, 0.525271, 0.539357, 0.55374, 0.568449, 0.583518, 0.598981, 0.614876, 0.631243, 0.648125, 0.665569, 0.683628, 0.702355,
    //    0.721813, 0.742068, 0.763191, 0.785261, 0.808365, 0.832598, 0.858062, 0.884871, 0.913147, 0.943024, 0.974646, 1.00817, 1.04376, 1.08158,
    //    1.12183, 1.16469, 1.21033, 1.25893, 1.31063, 1.36556, 1.42377, 1.48527, 1.54994, 1.61759, 1.68788, 1.76038, 1.8345, 1.90958, 1.98492,
    //    2.05977, 2.13344, 2.20531, 2.27486, 2.3417, 2.40555, 2.46624, 2.52371, 2.57797, 2.62911, 2.67723, 2.72249, 2.76506, 2.8051, 2.84279, 
    //    2.87832, 2.91183, 2.94349, 2.97345, 3.00184, 3.02879, 3.05443, 3.07885, 3.10216, 3.12445, -3.13738, -3.11689, -3.09719, -3.07822,
    //    -3.05991, -3.04221, -3.02507, -3.00845, -2.9923, -2.97658, -2.96125, -2.94629, -2.93165, -2.91732, -2.90325, -2.88942, -2.87581,
    //    -2.8624, -2.84915, -2.83605, -2.82308, -2.81022, -2.79744, -2.78472, -2.77206, -2.75942, -2.7468, -2.73416, -2.7215, -2.70879, -2.69602,
    //    -2.68316, -2.6702, -2.65711, -2.64388, -2.63048, -2.61689, -2.60308, -2.58904, -2.57473, -2.56013, -2.54521, -2.52993, -2.51427, -2.49818,
    //    -2.48164, -2.46459, -2.44699, -2.4288, -2.40997, -2.39043, -2.37013, -2.34901, -2.32698, -2.30399, -2.27993, -2.25474, -2.2283, -2.20052,
    //    -2.17129, -2.1405, -2.10801, -2.07371, -2.03746, -1.99914, -1.9586, -1.91574, -1.87044, -1.8226, -1.77216, -1.71908, -1.66338, -1.60513, 
    //    -1.54445, -1.48153, -1.41666, -1.35017, -1.28248, -1.21403, -1.14533, -1.07689, -1.00921, -0.942764, -0.877967, -0.815179, -0.754683, 
    //    -0.696684, -0.641316, -0.588645, -0.538679, -0.491377, -0.446664, -0.404437, -0.364574, -0.326941, -0.291402, -0.257816, -0.226048, 
    //     -0.195964, -0.167438, -0.140352, -0.114594, -0.0900582, -0.0666492, -0.044277, -0.0228586, -0.00231785, 0.0174158, 0.0364073, 0.0547164, 
    //     0.0723983, 0.0895042, 0.106081, 0.122173, 0.137819, 0.153059};

	real_T bump_directions_list[] = {-3.14141, -3.11149, -3.08155, -3.05158, -3.0216, -2.99265, -2.96366, -2.93456, -2.90534, -2.87602, -2.84659, -2.81707, 
    -2.78745, -2.75774, -2.72794, -2.69806, -2.66809, -2.63805, -2.60793, -2.57774, 
    -2.54749, -2.51717, -2.48679, -2.45636, -2.42589, -2.39537, -2.36481, -2.33422, 
    -2.3036, -2.27296, -2.24231, -2.21165, -2.18098, -2.15031, -2.11966, -2.08901, 
    -2.05838, -2.02778, -1.9972, -1.96665, -1.93614, -1.90566, -1.87523, -1.84484, 
    -1.81449, -1.78419, -1.75394, -1.72375, -1.6936, -1.6635, -1.63345, -1.60345, 
    -1.5735, -1.5436, -1.51375, -1.48393, -1.45416, -1.42443, -1.39474, -1.36509,
    -1.33547, -1.30588, -1.27633, -1.24681, -1.21731, -1.18785, -1.15842, -1.12902, 
    -1.09966, -1.07034, -1.04107, -1.01187, -0.982736, -0.953696, -0.924771, -0.895994,
    -0.867406, -0.839065, -0.81105, -0.780299, -0.74951, -0.718809, -0.688182, -0.657618,
    -0.627108, -0.596643, -0.566216, -0.535821, -0.505454, -0.47511, -0.444787, -0.414481,
    -0.384191, -0.353915, -0.323653, -0.293403, -0.263167, -0.232944, -0.202734, -0.172539,
    -0.142359, -0.112194, -0.0820465, -0.0519169, -0.0218061, 0.00828503, 0.0383557,
    0.0684053, 0.099443, 0.130503, 0.161443, 0.192271, 0.222992, 0.253613, 0.284136, 
    0.314565, 0.344904, 0.375156, 0.405323, 0.43541, 0.465418, 0.495352, 0.525216, 0.555012,
    0.584744, 0.614417, 0.644035, 0.673603, 0.703124, 0.732605, 0.762049, 0.791461,
    0.820848, 0.850214, 0.879563, 0.908902, 0.938236, 0.967568, 0.996906, 1.02625, 1.05561,
    1.08499, 1.11439, 1.14382, 1.17328, 1.20277, 1.2323, 1.26187, 1.29148, 1.32114, 1.35084,
    1.38059, 1.41038, 1.44023, 1.47012, 1.50007, 1.53006, 1.5601, 1.59019, 1.62032, 1.6505,
    1.68071, 1.71097, 1.74127, 1.7716, 1.80197, 1.83237, 1.8628, 1.89326, 1.92375, 1.95427,
    1.98482, 2.0154, 2.04602, 2.07667, 2.10737, 2.13812, 2.16893, 2.19982, 2.2308, 2.26191,
    2.29317, 2.32464, 2.35636, 2.38777, 2.41688, 2.4461, 2.4754, 2.50478, 2.53422, 2.56371,
    2.59325, 2.62282, 2.65243, 2.68206, 2.71172, 2.7414, 2.77109, 2.8008, 2.83053, 2.86027,
    2.89003, 2.91979, 2.94958, 2.97938, 3.00919, 3.03902, 3.06887, 3.09874, 3.12863};

            
	real_T bump_magnitudes_list[] = {1.00746, 1.00415, 1.00179, 1.00037, 0.999894, 
    0.957621, 0.916617, 0.879678, 0.846278, 0.815978, 0.788412, 
    0.763271, 0.740295, 0.719259, 0.699973, 0.682273, 0.666015, 0.651076, 0.637349, 
    0.624738, 0.613161, 0.602545, 0.592827, 0.583948, 0.57586, 0.568519, 0.561885,
    0.555924, 0.550605, 0.545903, 0.541794, 0.538258, 0.535278, 0.53284, 0.530931, 
    0.529542, 0.528665, 0.528295, 0.52843, 0.529068, 0.530212, 0.531864, 0.53403,
    0.536719, 0.539942, 0.543711, 0.548043, 0.552958, 0.558478, 0.564629, 0.571442,
    0.578952, 0.587198, 0.596225, 0.606087, 0.616841, 0.628556, 0.641309, 0.655187, 
    0.670291, 0.686737, 0.70466, 0.724213, 0.745574, 0.768955, 0.794598, 0.822794, 
    0.853883, 0.888275, 0.926463, 0.969041, 1.01674, 1.07047, 1.13137, 1.20087, 
    1.28082, 1.37367, 1.48266, 1.61224, 1.56332, 1.51057, 1.46248, 1.41853, 1.37828,
    1.34137, 1.30748, 1.27631, 1.24764, 1.22125, 1.19696, 1.1746, 1.15404, 1.13515, 
    1.11782, 1.10195, 1.08746, 1.07426, 1.0623, 1.0515, 1.04182, 1.03321, 1.02563, 
    1.01904, 1.01342, 1.00873, 1.00495, 1.00208, 1.00008, 0.958667, 0.916351, 0.878428,
    0.844304, 0.813488, 0.78557, 0.760208, 0.737111, 0.716034, 0.696765, 0.679124, 
    0.662954, 0.648118, 0.634499, 0.621993, 0.610509, 0.599968, 0.5903, 0.581443, 0.573343,
    0.565951, 0.559224, 0.553127, 0.547625, 0.54269, 0.538297, 0.534424, 0.531053, 0.528166,
    0.525753, 0.523801, 0.522302, 0.521251, 0.520643, 0.520477, 0.520754, 0.521475, 0.522646,
    0.524272, 0.526364, 0.528932, 0.531989, 0.535552, 0.539639, 0.544272, 0.549475, 0.555277,
    0.561709, 0.568807, 0.576611, 0.585166, 0.594525, 0.604743, 0.615887, 0.628029, 0.641252,
    0.655651, 0.671333, 0.688421, 0.707054, 0.727395, 0.749629, 0.773975, 0.800686, 0.83006, 
    0.862449, 0.898275, 0.938042, 0.982362, 1.03198, 1.08783, 1.15107, 1.22315, 1.30597, 
    1.40201, 1.51455, 1.60577, 1.54703, 1.49379, 1.4454, 1.40133, 1.36112, 1.32436,
    1.29072, 1.2599, 1.23166, 1.20576, 1.18202, 1.16026, 1.14033, 1.12211, 1.10548, 
    1.09033, 1.07658, 1.06414, 1.05296, 1.04296, 1.0341, 1.02633, 1.01961, 1.01392, 1.00921};
            
            
//     {-1.17459, -1.16971, -1.16496, -1.16031, -1.15575, -1.15128, -1.14689, -1.14257,
//         -1.1383, -1.13408, -1.12991, -1.12577, -1.12166, -1.11756, -1.11348, -1.1094, -1.10532, -1.10122, -1.09711, -1.09298,
//         -1.08881, -1.0846, -1.08034, -1.07603, -1.07165, -1.06719, -1.06265, -1.05802, -1.05327, -1.04841, -1.04341, -1.03826,
//         -1.03295, -1.02745, -1.02176, -1.01584, -1.00967, -1.00323, -0.996479, -0.989389, -0.981919, -0.974022, -0.965648, -0.956736,
//         -0.947217, -0.937008, -0.926014, -0.914121, -0.901193, -0.887066, -0.871542, -0.854378, -0.835274, -0.813852, -0.789639,
//         -0.762024, -0.730218, -0.693178, -0.649512, -0.597331, -0.534033, -0.456, -0.358204, -0.233848, -0.0746482, 0.126202, 0.36486,
//         0.616319, 0.846037, 1.03586, 1.1862, 1.30442, 1.3982, 1.47364, 1.53528, 1.58642, 1.62943, 1.66608, 1.69766, 1.72518, 1.74937,
//         1.77083, 1.79, 1.80726, 1.8229, 1.83715, 1.85021, 1.86224, 1.87337, 1.88372, 1.89338, 1.90243, 1.91094, 1.91897, 1.92657,
//         1.93379, 1.94067, 1.94724, 1.95353, 1.95957, 1.96539, 1.971, 1.97643, 1.98169, 1.98681, 1.99179, 1.99664, 2.00139, 2.00605,
//         2.01061, 2.0151, 2.01953, 2.02389, 2.02821, 2.03249, 2.03674, 2.04096, 2.04517, 2.04936, 2.05356, 2.05776, 2.06197, 2.0662,
//         2.07046, 2.07476, 2.0791, 2.08349, 2.08795, 2.09247, 2.09708, 2.10178, 2.10658, 2.11149, 2.11653, 2.12172, 2.12706, 2.13257,
//         2.13828, 2.1442, 2.15036, 2.15678, 2.16349, 2.17052, 2.17792, 2.18571, 2.19396, 2.20271, 2.21203, 2.22199, 2.23268, 2.24419,
//         2.25666, 2.27022, 2.28504, 2.30133, 2.31934, 2.33938, 2.36184, 2.38719, 2.41604, 2.44917, 2.48755, 2.53247, 2.58555, 2.64888,
//         2.72507, 2.81723, 2.92867, 3.06221, -3.06436, -2.88723, -2.69679, -2.504, -2.32069, -2.15601, -2.01444, -1.8961, -1.79851, -1.71822,
//         -1.65188, -1.59662, -1.55013, -1.51061, -1.47666, -1.44722, -1.42145, -1.3987, -1.37845, -1.36031, -1.34394, -1.32908, -1.31552,
//         -1.30307, -1.29158, -1.28094, -1.27104, -1.26179, -1.25311, -1.24495, -1.23723, -1.22993, -1.22298, -1.21637, -1.21004, -1.20398,
//         -1.19816, -1.19254, -1.18712, -1.18186, -1.17676};

       
        
	cohack_mode = params->use_cohack_mode;
	random_bump_mode = params->use_random_bump;
	force_bump_mode = params->use_force_bump;

	// Get Random target location (Prior Shift)
	current_trial_shift = (params->prior_mean)*PI/180 + random->getVonMises(params->prior_kap);

	// If in center out hack mode, set the "shift" to one of a set number of potential locations
	if (cohack_mode){        
        if (params->bump_sampling_method == 0){
            current_trial_shift = 2*PI*random->getInteger(1,params->cohack_tgtnum)/params->cohack_tgtnum;
        } else if ((params->bump_sampling_method == 1)||(params->bump_sampling_method == 2)){
            i = random->getInteger(0,209);
            current_trial_shift = bump_directions_list[i];
        } else {
            // Non-implemented methods yet, will keep bumping at direction zero.
            current_trial_shift = 0;
        }		
	}

	// Get bump magnitude
	if (params->bump_sampling_method == 2){
		current_trial_bumpmag = bump_magnitudes_list[i];
	}else if (random_bump_mode){
		current_trial_bumpmag = random->getDouble(params->random_bump_low,params->random_bump_high);
	}else{		
		bump_rand = random->getDouble();  	// generate a random number between 0 and 1
		total_bump_freq  = fabs(params->bump_freq_one)+fabs(params->bump_freq_two)+
			fabs(params->bump_freq_three);
		// in case of divide by zero
		if (total_bump_freq == 0){
			total_bump_freq = 1.0;
		}

		// recalculate frequencies 
		act_bf_one   = fabs(params->bump_freq_one)/total_bump_freq;
		act_bf_two   = fabs(params->bump_freq_two)/total_bump_freq;
		act_bf_three = fabs(params->bump_freq_three)/total_bump_freq;
		
		if (bump_rand <= act_bf_one){
			current_trial_bumpmag = params->bump_mag_one;
		} else if (bump_rand <= act_bf_one+act_bf_two){
			current_trial_bumpmag = params->bump_mag_two;
		} else if (bump_rand <= act_bf_one+act_bf_two+act_bf_three){
			current_trial_bumpmag = params->bump_mag_three;
		} else {
			// by default, no bump
			current_trial_bumpmag = 0.0;
		}
	}

	center_offset.x = params->center_X_offset;
	center_offset.y = params->center_Y_offset;

	// Calculate the Target Shift    
    target_shift = current_trial_shift;   
    
	/* Select whether this will be a stimulation trial */
    this->stim_trial=(this->random->getDouble() < params->stim_prob);

	// Set up the Bump	
	if (this->stim_trial){
		current_trial_bumpmag=0;
	}

	this->bump->distance = current_trial_bumpmag;
	this->bump->direction = target_shift;
    this->bump->duration = params->bump_duration;
    this->bump->vel_gain = params->Gain_vel;
    this->bump->pos_gain = params->Gain_pos;

	this->bumpF->direction		= target_shift;
	this->bumpF->rise_time		= params->force_rise_time;
	this->bumpF->hold_duration  = params->force_peak_time;
	this->bumpF->peak_magnitude = current_trial_bumpmag;

	// Set up Visual Target
	cloud_rand = random->getDouble(); // Generate random number between 0 and 1
	total_cloud_freq  = fabs(params->cloud_freq_one)+fabs(params->cloud_freq_two)+
		fabs(params->cloud_freq_three)+fabs(params->cloud_freq_four);
	// in case of divide by zero
	if (total_cloud_freq == 0){
		total_cloud_freq = 1.0;
	}
	// recalculate frequencies 
	actual_freq_one   = fabs(params->cloud_freq_one)/total_cloud_freq;
	actual_freq_two   = fabs(params->cloud_freq_two)/total_cloud_freq;
	actual_freq_three = fabs(params->cloud_freq_three)/total_cloud_freq;
	actual_freq_four  = fabs(params->cloud_freq_four)/total_cloud_freq;
	
	if (cloud_rand <= actual_freq_one){
		current_target_stdev = params->cloud_kap_one;
		// Using Variance One, so check if this trial should be blanked feedback
		cloud_blank = params->cloud_one_blank_mode;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two){
		current_target_stdev = params->cloud_kap_two;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three){
		current_target_stdev = params->cloud_kap_three;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three+actual_freq_four){
		current_target_stdev = params->cloud_kap_four;
		cloud_blank = false;
	} else {
		// by default, no feedback is shown
		current_target_stdev = 0.0;
		cloud_blank = true;
	}

	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
			// For 1D clouds, since targets are at 0, 90, 180, 270....
			slice_points[i] = random->getVonMises(current_target_stdev);
	}

	// Set Up The Targets

	centerTarget->centerX = 0.0;//+center_offset.x ;
	centerTarget->centerY = 0.0;//+center_offset.y ;
	centerTarget->radius   = params->target_size;
	centerTarget->color   = Target::Color(255, 0, 0);

	outerTarget->r = params->movement_length;
	outerTarget->theta = target_shift;
	outerTarget->span   = (params->OT_size)*PI/180;
	outerTarget->height = params->OT_depth;

	targetBar->r  = params->movement_length;
	targetBar->theta  = 0; 
	targetBar->span    = 2*PI-0.00001;
	targetBar->height = params->OT_depth+.1;

	timerTarget->centerX = 14.25;
	timerTarget->centerY = 10.55 ;
	timerTarget->width   = 0.8;
	timerTarget->color   = Target::Color(255, 255, 255);

	for (i=0; i<10; i++) {
		cloud[i]->r      = params->movement_length;
		cloud[i]->theta  = target_shift + slice_points[i];
		cloud[i]->span   = (params->slice_size)*PI/180;
		cloud[i]->height = params->OT_depth;
	}

	// Initialize the cloud and cursor extent
	updateCursorExtent(S);


	// Randomized Timers
	center_hold_time  = random->getDouble(params->center_hold_l, params->center_hold_h);
	
	// if this is a center delay catch trial, calculate the delay time based on catch bounds
	if (random->getDouble() <= params->delay_catch_freq)
	{
		center_delay_time = random->getDouble(params->delay_catch_l, params->delay_catch_h);
	}
	else
	{
		center_delay_time = random->getDouble(params->center_delay_l, params->center_delay_h);
	}
	
	outer_hold_time = params->intertrial;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('C');
	db->addByte('C');
	db->addByte('B');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)current_trial_shift);
	db->addFloat((float)params->prior_kap);
	db->addFloat((float)this->current_trial_bumpmag);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_duration_back);
	db->addByte((byte)this->stim_trial);
	db->addFloat((float)current_target_stdev);
	db->addFloat((float)params->slice_number);
	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
		db->addFloat((float)slice_points[i]);
	}
    db->start();
}

void cuecombBehavior::update(SimStruct *S) {

    x_pos = x_pos_old*(1-params->pos_filt) + inputs->cursor.x * params->pos_filt;
    y_pos = y_pos_old*(1-params->pos_filt) + inputs->cursor.y * params->pos_filt;
    
    x_vel = x_vel_old*(1-params->vel_filt) + ((x_pos-x_pos_old)/.001)*params->vel_filt;
    y_vel = y_vel_old*(1-params->vel_filt) + ((y_pos-y_pos_old)/.001)*params->vel_filt;   

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK:
			if (db->isDone()) {
				setState(STATE_CT_ON);
			}
			break;
		case STATE_CT_ON:
			/* first target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > center_hold_time) {
				
				if (!force_bump_mode){
					this->bump->start(S);
				} else { 
					this->bumpF->start(S);
				}
				setState(STATE_BUMP_OUT);
			}
			break;
		case STATE_BUMP_OUT:
			if (force_bump_mode){
				if (!this->bumpF->isRunning(S)) {
					setState(STATE_CT_DELAY);
				}
			} else {
			
				if (!this->bump->isRunning(S)){
					this->bump->direction = target_shift + PI;
					if (params->NoReturn){
						this->bump->distance = 0;
						if (params->training){
							bump_offset.x = 0.0;
							bump_offset.y = 0.0;
						} else {
							bump_offset = inputs->cursor;
						}
					} else { 
						this->bump->distance = current_trial_bumpmag;
						bump_offset.x = 0.0;
						bump_offset.y = 0.0;
						this->bump->duration = params->bump_duration_back;
					}
					this->bump->duration = params->bump_duration;
					this->bump->start(S);
					setState(STATE_BUMP_IN);
				}

			}
			break;
		case STATE_BUMP_IN:
			if (!this->bump->isRunning(S)){
				setState(STATE_CT_DELAY);
			}
			break;
		case STATE_CT_DELAY:
			if ((!centerTarget->cursorInTarget(inputs->cursor.x-bump_offset.x,
											  inputs->cursor.y-bump_offset.y)) && !params->training) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} 
			else if (stateTimer->elapsedTime(S) >= center_delay_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_time) {
				setState(STATE_INCOMPLETE);
			} else if (cursor_extent > params->movement_length-(params->OT_depth*0.50)) {
				if (params->NoReturn){
					cursor_end_point.x = inputs->cursor.x - bump_offset.x;
					cursor_end_point.y = inputs->cursor.y - bump_offset.y;
				} else {
					cursor_end_point=inputs->cursor;
				}
				setState(STATE_OT_HOLD);
			}
			break;  		
		case STATE_OT_HOLD:
			if (outerTarget->cursorInTarget(cursor_end_point)){
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (!outerTarget->cursorInTarget(cursor_end_point)) {
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			}
			break;
		case STATE_FAIL:         
			if (stateTimer->elapsedTime(S) > (params->intertrial+params->failure_lag)) {
				setState(STATE_PRETRIAL);
			}
			break;
		
		case STATE_ABORT:
			if (force_bump_mode){
				this->bumpF->stop();
			} else{
			this->bump->stop();
			}
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_REWARD:
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_INCOMPLETE:
			if (force_bump_mode){
				this->bumpF->stop();
			} else{
			this->bump->stop();
			}
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
	// assign the current position and time point to previous position
	previous_position = inputs->cursor;
	previous_time_point = stateTimer->elapsedTime(S);
}

void cuecombBehavior::calculateOutputs(SimStruct *S) {
    updateCursorExtent(S);
	
	/* declarations */
    Point bf;
	int i;
	real_T x_force_bump;
    real_T y_force_bump;           
    Point Posbump_force;
    // Position bump
	if (force_bump_mode){
		Posbump_force = this->bumpF->getBumpForce(S,Point(x_vel,y_vel),Point(x_pos,y_pos));
	} else {
		Posbump_force = this->bump->getBumpForce(S,Point(x_vel,y_vel),Point(x_pos,y_pos));
	}
    x_force_bump = Posbump_force.x;
    y_force_bump = Posbump_force.y;    

    
	/* force (0) */
	if (force_bump_mode){
		if (this->bumpF->isRunning(S)) {
			outputs->force.x = x_force_bump;
			outputs->force.y = y_force_bump;
		} else {
			outputs->force = inputs->force;
		}
	}else{
		if (this->bump->isRunning(S)) {
			outputs->force.x = x_force_bump;
			outputs->force.y = y_force_bump;
		} else {
			outputs->force = inputs->force;
		}
	}
	/* status (1) */
 	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
 	outputs->status[3] = trialCounter->failures;
 	outputs->status[4] = trialCounter->incompletes;
    
//     /* Debugging */
//     outputs->status[0] = 10000*target_shift;
  
	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_CT_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_BUMP_OUT:
				outputs->word = WORD_BUMP(0);
				break;
			case STATE_BUMP_IN:
				outputs->word = WORD_BUMP(1);
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_CT_DELAY:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_GO_CUE;
				break;
			case STATE_OT_HOLD:
				outputs->word = WORD_OUTER_TARGET_HOLD;
				break;
			case STATE_REWARD:
				outputs->word = WORD_REWARD;
				break;
			case STATE_ABORT:
				outputs->word = WORD_ABORT;
				break;
			case STATE_FAIL:
				outputs->word = WORD_FAIL;
				break;
			case STATE_INCOMPLETE:
				outputs->word = WORD_INCOMPLETE;
				break;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* target_pos (3) */
	// Center Target (0)
	if (getState() == STATE_CT_ON ||
		getState() == STATE_CT_HOLD ||
		getState() == STATE_BUMP_OUT ||
		getState() == STATE_BUMP_IN ||
		getState() == STATE_CT_DELAY) {
			outputs->targets[0] = (Target *)centerTarget;
	}else{
		outputs->targets[0] = nullTarget;
	}

	// Outer target (correct) and Target Bar (1-2)
	if (	getState() == STATE_CT_HOLD		||
			getState() == STATE_CT_DELAY	||
			getState() == STATE_BUMP_OUT	||
			getState() == STATE_BUMP_IN		||
			getState() == STATE_MOVEMENT){
		
		outputs->targets[1] = (Target *)outerTarget;
		outputs->targets[2] = (Target *)targetBar;
	} else if (getState() == STATE_OT_HOLD ||
			   getState() == STATE_REWARD  ||
			   getState() == STATE_FAIL) {

		outputs->targets[1] = (Target *)targetBar;
		outputs->targets[2] = (Target *)outerTarget;

	}else {
		outputs->targets[2] = nullTarget;
		outputs->targets[1] = nullTarget;
	}


	// Targets 3 through 12 Target Cloud (3-12)

	if (!cloud_blank &&
		(getState() == STATE_BUMP_OUT || 
		getState() == STATE_BUMP_IN || 
		((getState() == STATE_CT_DELAY || 
		getState() == STATE_MOVEMENT) &&
		cursor_extent < params->feedback_win))) {
		for (i = 0; i<params->slice_number; i++) {
			outputs->targets[3+i] = cloud[i];
		}
	} else {
		for (i = 0; i<params->slice_number; i++) {
			outputs->targets[3+i] = nullTarget;
		}
	}
		
	
	/* Timer Dot */
	if ( getState() == STATE_CT_ON	 ||
		 getState() == STATE_CT_HOLD ||
		 getState() == STATE_BUMP_OUT ||
		 getState() == STATE_MOVEMENT ||
		 getState() == STATE_OT_HOLD) {
	
		if (stateTimer->elapsedTime(S) < 0.25) {
			outputs->targets[14] = (Target *)timerTarget;
		} else {
			outputs->targets[14] = nullTarget;
		} 
	} else {
		outputs->targets[14] = nullTarget;
	}

	/* reward (4) */
	outputs->reward = (isNewState() && (getState() == STATE_REWARD));

	/* tone (5) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* cursor position (7) */
	if (getState() == STATE_BUMP_OUT ||
		getState() == STATE_BUMP_IN){
		if (params->training){
			outputs->position.x = inputs->cursor.x;
			outputs->position.y = inputs->cursor.y;
		} else {
			outputs->position = Point(100000,100000);
		}
	} else if ( getState() == STATE_OT_HOLD ||
				getState() == STATE_REWARD ||
			    getState() == STATE_FAIL) {
		outputs->position = cursor_end_point;
	} else if ( getState() == STATE_CT_DELAY ||
				getState() == STATE_MOVEMENT ||
				getState() == STATE_ABORT    ||
				getState() == STATE_INCOMPLETE) {
		outputs->position.x = inputs->cursor.x - bump_offset.x;
		outputs->position.y = inputs->cursor.y - bump_offset.y;
	} else {
		outputs->position = inputs->cursor;
	}

	x_pos_old = x_pos;
    y_pos_old = y_pos;    
    x_vel_old = x_vel;
    y_vel_old = y_vel;
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


