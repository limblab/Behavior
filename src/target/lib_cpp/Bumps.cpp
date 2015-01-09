/*
 * $Id: $
 *
 * Classes to set up and run bumps
 */

/**
 * Abstract bump generator class with common functions.
 */
class BumpGenerator {
    public:
        BumpGenerator();	
        void start(SimStruct *S);
        void stop();
        virtual bool isRunning(SimStruct *S) = 0;
        virtual Point getBumpForce(SimStruct *S) = 0; /**< Used in feedforward force bumps > */
        virtual Point getBumpForce(SimStruct *S,Point vel, Point pos) = 0; /**< Used in PD bumps only. */
        double direction; /**< Gets or sets the direction the bump will act in. */    

    protected:
        Timer *timer;    /**< Tracks how long the bump has been running. */
        bool is_running; /**< keeps track of whether the bump is running */

    private:        
};

/** Default constructor */
BumpGenerator::BumpGenerator() {
	this->timer = new Timer();
	this->is_running = false;
}

void BumpGenerator::start(SimStruct *S) {
	is_running = true;
	timer->reset(S);
	timer->start(S);
}

void BumpGenerator::stop() {
	is_running = false;
	timer->stop();
}

/**
 * Generates a square wave bump.
 */
class SquareBumpGenerator : public BumpGenerator {
public:
	SquareBumpGenerator();
	virtual Point getBumpForce(SimStruct *S);	
    virtual Point getBumpForce(SimStruct *S,Point vel, Point pos);
	virtual bool isRunning(SimStruct *S);

	double duration;
	double magnitude;
};

/**
 * Constructs a square wave bump generator with defautl duration and 
 * magnitude of zero.
 */
SquareBumpGenerator::SquareBumpGenerator() {
	duration = 0.0;
	magnitude = 0.0;
}

/**
 * Required isRunning method. 
 * @return whether the bump is running (active).
 */
bool SquareBumpGenerator::isRunning(SimStruct *S) {
	return timer->isRunning() && timer->elapsedTime(S) < duration;
}

/**
 * Required getBumpForce method. 
 * @return the force of the bump for the current time step.
 */
Point SquareBumpGenerator::getBumpForce(SimStruct *S) {
    Point p;
    
	if (this->is_running) {
		double m = this->magnitude;
		p.x = m * cos(this->direction);
		p.y = m * sin(this->direction);
	} else {
		p = Point(0,0);
	}
	return p;        
}

Point SquareBumpGenerator::getBumpForce(SimStruct *S, Point vel, Point pos) {
    return(this->getBumpForce(S));
}

/**
 * Generates a trapezoidal wave bump.
 */
class TrapBumpGenerator : public BumpGenerator {
public:
	TrapBumpGenerator();

	virtual Point getBumpForce(SimStruct *S);	
    virtual Point getBumpForce(SimStruct *S,Point vel, Point pos);
	virtual bool isRunning(SimStruct *S);
	
	double rise_time;
	double hold_duration;
	double peak_magnitude;
};

/**
 * Constructs a trapezoid wave bump generator with default duration and 
 * magnitude of zero.
 */
TrapBumpGenerator::TrapBumpGenerator() {
	rise_time = 0;
	hold_duration = 0;
	peak_magnitude = 0;
}

/**
 * Required isRunning method. 
 * @return whether the bump is running (active).
 */
bool TrapBumpGenerator::isRunning(SimStruct *S) {
	return timer->isRunning() && timer->elapsedTime(S) < 2*rise_time+hold_duration;
}

/**
 * Required getBumpForce method. 
 * @return the magnitude of the bump for the current time step.
 */
Point TrapBumpGenerator::getBumpForce(SimStruct *S) {
    Point p;
    double m;
	double et;   // Elapsed time
	double efet; // Elapsed falling-edge time.

	if (!this->isRunning(S)) { // get stupid case out of the way
		m = 0.0;
	} else {
        et = (double)timer->elapsedTime(S);
        if (et < rise_time) {
            m = et * peak_magnitude / rise_time;
        } else if (et < rise_time + hold_duration) {
            m = peak_magnitude;
        } else if (et < 2 * rise_time + hold_duration) {
            efet = et - rise_time - hold_duration;
            m = (rise_time - efet) * peak_magnitude / rise_time;
        } else {
            m = 0.0;
        }
    }
    
    p.x = m * cos(this->direction);
    p.y = m * sin(this->direction);
    return p;
}

Point TrapBumpGenerator::getBumpForce(SimStruct *S, Point vel, Point pos) {
    return(this->getBumpForce(S));
}

/**********************************************
 * Sine wave generator
 **********************************************/ 

/**
 * This class is not working correctly.
 */
class CosineBumpGenerator : public BumpGenerator {
public:
	CosineBumpGenerator();

	virtual Point getBumpForce(SimStruct *S);	
    virtual Point getBumpForce(SimStruct *S,Point vel, Point pos);
	virtual bool isRunning(SimStruct *S);
	
	double rise_time;
	double hold_duration;
	double peak_magnitude;
};


/**
 * Constructs a sine wave bump generator with default duration and 
 * magnitude of zero.
 */
CosineBumpGenerator::CosineBumpGenerator() {
	rise_time = 0;
	hold_duration = 0;
	peak_magnitude = 0;
}

/**
 * Required isRunning method. 
 * @return whether the bump is running (active).
 */
bool CosineBumpGenerator::isRunning(SimStruct *S) {
	return timer->isRunning() && timer->elapsedTime(S) < 2*rise_time+hold_duration;
}

/**
 * Required getBumpForce method. 
 * @return the magnitude of the bump for the current time step.
 */
Point CosineBumpGenerator::getBumpForce(SimStruct *S) {
    Point p;
	double et;   // Elapsed time
	double efet; // Elapsed falling-edge time.
    double m;    // Magnitude

	if (!this->isRunning(S)) { // get stupid case out of the way
		m = 0.0;
	} else {
        et = (double)timer->elapsedTime(S);
        efet = et - rise_time - hold_duration;

        if (et < rise_time) {
            m = peak_magnitude * (1 - cos(PI * et / rise_time)) / 2;
        } else if (et < rise_time + hold_duration) {
            m = peak_magnitude;
        } else if (et < 2 * rise_time + hold_duration) {
            m =  peak_magnitude * (1 + cos(PI * efet / rise_time)) / 2;
        } else {
            m = 0.0;
        }
    }
    p.x = m * cos(this->direction);
    p.y = m * sin(this->direction);
    return p; 
}

Point CosineBumpGenerator::getBumpForce(SimStruct *S, Point vel, Point pos) {
    return(this->getBumpForce(S));
}

/**
 * Generates a velocity controlled bump.
 */
class PDBumpGenerator : public BumpGenerator {
public:
	PDBumpGenerator();
    virtual Point getBumpForce(SimStruct *S);
	virtual Point getBumpForce(SimStruct *S, Point vel, Point pos);	
	virtual bool isRunning(SimStruct *S);

	double duration;
    Point initial_position;
    Point desired_position;
	double bump_vel;
    double vel_gain;
    double pos_gain;
};

/**
 * Constructs a velocity bump generator with default velocity, 
 * duration, gains, etc. of zero. 
 */
PDBumpGenerator::PDBumpGenerator() {
	duration = 0.0;
    initial_position = Point(0,0);
    desired_position = Point(0,0);
	bump_vel = 0.0;
    vel_gain = 0.0;
    pos_gain = 0.0;
}

/**
 * Required isRunning method. 
 * @return whether the bump is running (active).
 */
bool PDBumpGenerator::isRunning(SimStruct *S) {
	return timer->isRunning() && timer->elapsedTime(S) < duration;
}

/**
 * Required getBumpForce method. 
 * @return the force of the bump for the current time step.
 */

Point PDBumpGenerator::getBumpForce(SimStruct *S) {
    Point p;
    p = Point(0,0);    
	return (p);
}

Point PDBumpGenerator::getBumpForce(SimStruct *S, Point vel, Point pos) {
    if (timer->elapsedTime(S)<0.002){
        this->initial_position = pos;
    }
    if (timer->elapsedTime(S)>(this->duration/2) &&
            timer->elapsedTime(S)<(this->duration/2+0.002)){
        this->initial_position = pos;
    }
    
    Point p;
    if (timer->elapsedTime(S)<(this->duration/2)){
        this->desired_position.x = this->initial_position.x + 
            bump_vel * timer->elapsedTime(S) * cos(this->direction);
        this->desired_position.y = this->initial_position.y + 
            bump_vel * timer->elapsedTime(S) * sin(this->direction);
        p.x = (bump_vel*cos(this->direction)-vel.x)*vel_gain + 
                (desired_position.x - pos.x)*pos_gain;
        p.y = (bump_vel*sin(this->direction)-vel.y)*vel_gain + 
                (desired_position.y - pos.y)*pos_gain;
    } else {
        this->desired_position.x = this->initial_position.x + 
            bump_vel * timer->elapsedTime(S) * cos(this->direction + PI);
        this->desired_position.y = this->initial_position.y + 
            bump_vel * timer->elapsedTime(S) * sin(this->direction + PI);
        p.x = -(bump_vel*cos(this->direction)-vel.x)*vel_gain + 
                (initial_position.x - pos.x)*pos_gain;
        p.y = -(bump_vel*sin(this->direction)-vel.y)*vel_gain + 
                (initial_position.y - pos.y)*pos_gain;
    }
    
	return ( this->isRunning(S) ? p : Point(0,0) );
}


/* Position Controlled Bump */

/**
 * Generates a position controlled bump.
 */
class PosBumpGenerator : public BumpGenerator {
public:
	PosBumpGenerator();
    virtual Point getBumpForce(SimStruct *S);
	virtual Point getBumpForce(SimStruct *S, Point vel, Point pos);	
	virtual bool isRunning(SimStruct *S);

	double duration;
	double distance;
    Point initial_position;
    Point desired_position;
	Point desired_velocity;
	double desired_posmag;
	double desired_velmag;
    double vel_gain;
    double pos_gain;
};

/**
 * Constructs a velocity bump generator with default velocity, 
 * duration, gains, etc. of zero. 
 */
PosBumpGenerator::PosBumpGenerator() {
	distance = 0.0;
	duration = 0.0;
    initial_position = Point(0,0);
    desired_position = Point(0,0);
	desired_velocity = Point(0,0);
	desired_posmag = 0.0;
	desired_velmag = 0.0;
    vel_gain = 0.0;
    pos_gain = 0.0;
}

/**
 * Required isRunning method. 
 * @return whether the bump is running (active).
 */
bool PosBumpGenerator::isRunning(SimStruct *S) {
	return timer->isRunning() && timer->elapsedTime(S) < duration;
}

/**
 * Required getBumpForce method. 
 * @return the force of the bump for the current time step.
 */

Point PosBumpGenerator::getBumpForce(SimStruct *S) {
    Point p;
    p = Point(0,0);    
	return (p);
}

Point PosBumpGenerator::getBumpForce(SimStruct *S, Point vel, Point pos) {
    if (timer->elapsedTime(S)<0.002){
        this->initial_position = pos;
    }

	this->desired_posmag = this->distance/(2*PI)*(sin(2*PI*timer->elapsedTime(S)/this->duration + PI) + 
												      2*PI*timer->elapsedTime(S)/this->duration);
	this->desired_velmag = this->distance/this->duration*(cos(2*PI*timer->elapsedTime(S)/this->duration + PI) + 1);

	this->desired_position.x = this->initial_position.x + this->desired_posmag*cos(this->direction);
	this->desired_position.y = this->initial_position.y + this->desired_posmag*sin(this->direction);

	this->desired_velocity.x = this->desired_velmag*cos(this->direction);
	this->desired_velocity.y = this->desired_velmag*sin(this->direction);
        
    Point p;

    p.x = (desired_velocity.x-vel.x)*vel_gain + 
            (desired_position.x - pos.x)*pos_gain;
    p.y = (desired_velocity.y-vel.y)*vel_gain + 
            (desired_position.y - pos.y)*pos_gain;

	return ( this->isRunning(S) ? p : Point(0,0) );
}
