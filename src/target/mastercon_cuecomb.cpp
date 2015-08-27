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

	real_T bump_directions_list[] = {3.14107, -3.11133, -3.08046, -3.04951, -3.01844, -2.98723, -2.95583, -2.9242, -2.89225, -2.86286, -2.83367, 
		-2.80439, -2.77504, -2.74561, -2.71614, -2.68661, -2.65705, -2.62745, -2.59783, -2.56818, -2.53851, -2.50882, 
		-2.47911, -2.44939, -2.41965, -2.3899, -2.36014, -2.33036, -2.30056, -2.27075, -2.24093, -2.21108, -2.18122, 
		-2.15134, -2.12143, -2.09151, -2.06156, -2.03159, -2.00182, -1.97292, -1.94391, -1.91477, -1.88553, -1.85618, 
		-1.82672, -1.79718, -1.76753, -1.7378, -1.70798, -1.67807, -1.64809, -1.61803, -1.58789, -1.55768, -1.52741, 
		-1.49708, -1.46669, -1.43625, -1.40576, -1.37523, -1.34466, -1.31406, -1.28344, -1.25279, -1.22214, -1.19147, 
		-1.16081, -1.13014, -1.09949, -1.06885, -1.03823, -1.00763, -0.977055, -0.946515, -0.916011, -0.885546, -0.855122, 
		-0.824742, -0.794409, -0.764124, -0.733888, -0.703702, -0.673567, -0.643482, -0.613447, -0.583461, -0.553524, 
		-0.523634, -0.493789, -0.463989, -0.43423, -0.404511, -0.37483, -0.345185, -0.315574, -0.285996, -0.256449, 
		-0.226933, -0.197446, -0.167991, -0.138568, -0.10918, -0.0798299, -0.0505248, -0.0212724, 0.00791643, 0.0370271, 
		0.0660403, 0.0949305, 0.123664, 0.152194, 0.180459, 0.209049, 0.239913, 0.270678, 0.301359, 0.331969, 0.362518, 
		0.393016, 0.42347, 0.453889, 0.484276, 0.514636, 0.544975, 0.575293, 0.605595, 0.635881, 0.666154, 0.696413, 
		0.726658, 0.756891, 0.787111, 0.817317, 0.847509, 0.877685, 0.907845, 0.937989, 0.968113, 0.998219, 1.02831, 
		1.05837, 1.08857, 1.11973, 1.15076, 1.18167, 1.21247, 1.24316, 1.27376, 1.30425, 1.33466, 1.36498, 1.39521, 
		1.42535, 1.45542, 1.48541, 1.51532, 1.54517, 1.57495, 1.60467, 1.63432, 1.66393, 1.69348, 1.72299, 1.75247, 
		1.7819, 1.81131, 1.84069, 1.87005, 1.89939, 1.92873, 1.95806, 1.9874, 2.01674, 2.04609, 2.07545, 2.10484, 
		2.13424, 2.16368, 2.19315, 2.22265, 2.25219, 2.28177, 2.31139, 2.34106, 2.37077, 2.40053, 2.43034, 2.4602, 
		2.49011, 2.52006, 2.55007, 2.58012, 2.61022, 2.64036, 2.67055, 2.70078, 2.73104, 2.76135, 2.79169, 2.82207, 
		2.85248, 2.88292, 2.91339, 2.94388, 2.97441, 3.00497, 3.03556, 3.06618, 3.09684, 3.12755};

            
	real_T bump_magnitudes_list[] = {0.968387, 1.01631, 1.07016, 1.13101, 1.20023, 1.27957, 1.37129, 1.47841, 1.60501, 
		1.56425, 1.50941, 1.45961, 1.41428, 1.37294, 1.33517, 1.30062, 1.26897, 1.23997, 1.21339, 1.18901, 1.16666,
		1.1462, 1.12747, 1.11037, 1.09478, 1.08061, 1.06778, 1.05622, 1.04587, 1.03667, 1.02857, 1.02154, 1.01554, 
		1.01054, 1.00652, 1.00345, 1.00134, 1.00016, 0.991098, 0.946663, 0.906759, 0.870777, 0.838212, 0.808647, 
		0.781731, 0.75717, 0.734712, 0.714143, 0.695279, 0.677962, 0.662055, 0.647437, 0.634005, 0.621667, 0.610344,
		0.599965, 0.590467, 0.581796, 0.573904, 0.566748, 0.56029, 0.554497, 0.549339, 0.544792, 0.540832, 0.53744,
		0.534601, 0.532299, 0.530525, 0.529268, 0.528522, 0.528282, 0.528546, 0.529314, 0.530587, 0.532371, 0.534671,
		0.537496, 0.540857, 0.54477, 0.54925, 0.554318, 0.559997, 0.566316, 0.573304, 0.580999, 0.589441, 0.598678,
		0.608763, 0.619757, 0.631731, 0.644764, 0.658946, 0.674384, 0.691196, 0.709522, 0.729521, 0.751381, 0.775318, 
		0.801587, 0.830491, 0.862387, 0.897704, 0.936958, 0.980777, 1.02993, 1.08539, 1.14834, 1.22033, 1.30334, 1.39998,
		1.51378, 1.60588, 1.54929, 1.49779, 1.45081, 1.40785, 1.36849, 1.33239, 1.29922, 1.26871, 1.24065, 1.21481, 1.19103,
		1.16915, 1.14903, 1.13056, 1.11361, 1.0981, 1.08395, 1.07107, 1.05941, 1.04891, 1.03951, 1.03116, 1.02384, 1.0175,
		1.01212, 1.00767, 1.00413, 1.00148, 0.993379, 0.947336, 0.906212, 0.869318, 0.836087, 0.806052, 0.778821, 0.754067, 
		0.731511, 0.710918, 0.692084, 0.674834, 0.659019, 0.644507, 0.631183, 0.618947, 0.607713, 0.597403, 0.587949, 
		0.579291, 0.571377, 0.56416, 0.557599, 0.551658, 0.546304, 0.541511, 0.537253, 0.533511, 0.530265, 0.527502,
		0.525207, 0.523373, 0.521989, 0.521052, 0.520558, 0.520506, 0.520897, 0.521733, 0.52302, 0.524765, 0.526978,
		0.52967, 0.532855, 0.536551, 0.540776, 0.545553, 0.550908, 0.556868, 0.563468, 0.570743, 0.578736, 0.587492, 
		0.597066, 0.607516, 0.618908, 0.63132, 0.644836, 0.659554, 0.675585, 0.693055, 0.712111, 0.732919, 0.755674, 
		0.780602, 0.807967, 0.838079, 0.871309, 0.908095, 0.94896};
            
            
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


