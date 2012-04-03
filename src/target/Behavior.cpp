
#include "Behavior.h"
#include <math.h>

#include "simstruc.h"

#ifndef SquareTargetType
#define SquareTargetType 11
#endif

#ifndef NullTargetType
#define NullTargetType 0
#endif

#ifndef CircleTargetType
#define CircleTargetType 10
#endif 

/***************************************************
 * Targets
 ***************************************************/

int Target::Color(int r, int g, int b) {
	return ( 256*256*r + 256*g + b );
}

RectangleTarget::RectangleTarget() {
	this->left = 0.0;
	this->right = 0.0;
	this->bottom = 0.0; 
	this->top = 0.0;
	this->type = 0;
}

RectangleTarget::RectangleTarget(double left, double top, double right, double bottom, int type) {
	this->left = left;
	this->right = right;
	this->bottom = bottom; 
	this->top = top;
	this->type = type;
}

bool RectangleTarget::cursorInTarget(double x, double y) {
	return ( (x > this->left) && (x < this->right) && 
		(y > this->bottom) && (y < this->top) );
}

bool RectangleTarget::cursorInTarget(Point *p) {
	return this->cursorInTarget(p->x, p->y);
}

void RectangleTarget::copyToOutputs(real_T *u, int offset) {
	u[0+offset] = this->type;
	u[1+offset] = this->left;
	u[2+offset] = this->top;
	u[3+offset] = this->right;
	u[4+offset] = this->bottom;
}

SquareTarget::SquareTarget() {
	this->centerX = 0.0;
	this->centerY = 0.0;
	this->width = 0.0;
	this->color = 0;
}

SquareTarget::SquareTarget(double centerX, double centerY, double width, int color) {
	this->centerX = centerX;
	this->centerY = centerY;
	this->width = width;
	this->color = color;
}

bool SquareTarget::cursorInTarget(double x, double y) {
	return ( (x > centerX - width/2) && (x < centerX + width/2) && 
		(y > centerY - width/2) && (y < centerY + width/2) );
}

bool SquareTarget::cursorInTarget(Point *p) {
	return this->cursorInTarget(p->x, p->y);
}


void SquareTarget::copyToOutputs(real_T *u, int offset) {
	u[0+offset] = (real_T)(SquareTargetType);
	u[1+offset] = (real_T)(centerX - width / 2);
	u[2+offset] = (real_T)(centerY + width / 2);
	u[3+offset] = (real_T)(centerX + width / 2);
	u[4+offset] = (real_T)this->color;
}

CircleTarget::CircleTarget() {
	this->centerX = 0.0;
	this->centerY = 0.0; 
	this->radius = 0.0;
}

CircleTarget::CircleTarget(double centerX, double centerY, double radius) {
	this->centerX = centerX;
	this->centerY = centerY; 
	this->radius = radius;
}

bool CircleTarget::cursorInTarget(double x, double y) {
	return ( sqrt( (this->centerX-x)*(this->centerX-x) + (this->centerY-y)*(this->centerY-y) ) < radius );
}

bool CircleTarget::cursorInTarget(Point *p) {
	return this->cursorInTarget(p->x, p->y);
}

void CircleTarget::copyToOutputs(real_T *u, int offset) {
	u[0+offset] = (real_T)(CircleTargetType);
	u[1+offset] = (real_T)(centerX);
	u[2+offset] = (real_T)(centerY);
	u[3+offset] = (real_T)(centerX + radius);
	u[4+offset] = (real_T)(0.0);
}

TrialCounter::TrialCounter() {
	this->successes = 0;
	this->failures = 0;
	this->incompletes = 0;
	this->aborts = 0;
}

/*********************************************************
 * Behavior 
 ************************************************************/

Behavior::Behavior() {
	numParams = 0;
	state = 0;
	state_changed = true;
	tone_counter = 0;
	last_tone_id = 0;
	this->trialCounter = new TrialCounter();
	masterResetCounter = 0;
	this->stateTimer = new Timer();
	cursor = new Point();
	this->random = new Random();
	this->nullTarget = (Target *)(new RectangleTarget(0, 0, 0, 0, NullTargetType));
}

void Behavior::updateParameters(SimStruct *S) {
	int i;
	for (i=0; i < this->numParams; i++) {
		this->paramValues[i] = mxGetScalar(ssGetSFcnParam(S, i));
	}
}

void Behavior::setNumParams(int n) {
	this->numParams = n;
	this->paramValues = new double[n];
}

int Behavior::getState() {
	return this->state;
}

void Behavior::setState(int s) {
	this->state = s;
	this->state_changed = true;
	this->stateTimer->reset(S);
}

bool Behavior::isNewState() {
	return this->state_changed;
}

void Behavior::updateTrialCounters() {
	if (state == STATE_REWARD && state_changed)
		this->trialCounter->successes++;

	if (state == STATE_FAIL && state_changed)
		this->trialCounter->failures++;

	if (state == STATE_INCOMPLETE && state_changed)
		this->trialCounter->incompletes++;

	if (state == STATE_ABORT && state_changed)
		this->trialCounter->aborts++;
}

void Behavior::readInputs(SimStruct *S) {
	InputRealPtrsType uPtrs;

	/* cursor */
	uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
	cursor->x = *uPtrs[0];
	cursor->y = *uPtrs[1];

	/* input force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 2);
    force->x = *uPtrs[0];
    force->y = *uPtrs[1];
    
    /* catch input force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 3);
    catchForce->x = *uPtrs[0];
    catchForce->y = *uPtrs[1];
}

void Behavior::update(SimStruct *S) {
	this->readInputs(S);
	this->state_changed = false;
	this->S = S;
	this->random->getUL(); // burn a number of the pRNG
}

void Behavior::playTone(int toneId) {
	this->last_tone_id = toneId;
	this->tone_counter++;
}

void writePoint(real_T *u, Point *p) {
	u[0] = (real_T)p->x;
	u[1] = (real_T)p->y;
}

void Behavior::writeOutputs(SimStruct *S) {
	int i;
	real_T *uPtrs;

	// force
	uPtrs = ssGetOutputPortRealSignal(S, 0);
	writePoint(uPtrs, &(outputs->force));

	// status
	uPtrs = ssGetOutputPortRealSignal(S, 1);
	for (i = 0; i<5; i++) {
		uPtrs[i] = (real_T)outputs->status[i];
	}

	// word
	uPtrs = ssGetOutputPortRealSignal(S, 2);
	uPtrs[0] = (real_T)outputs->word;

	// targets
	uPtrs = ssGetOutputPortRealSignal(S, 3);
	outputs->targets[0]->copyToOutputs(uPtrs, 0);
	outputs->targets[1]->copyToOutputs(uPtrs, 5);

	// reward
	uPtrs = ssGetOutputPortRealSignal(S, 4);
	uPtrs[0] = (real_T)(outputs->reward ? 1.0 : 0.0);
	
	// tone
	uPtrs = ssGetOutputPortRealSignal(S, 5);
	uPtrs[0] = (real_T)outputs->tone_counter;
	uPtrs[1] = (real_T)outputs->last_tone_id;

	// version
	uPtrs = ssGetOutputPortRealSignal(S, 6);
	for (i = 0; i<4; i++) {
		uPtrs[i] = outputs->version[i];
	}

	// position
	uPtrs = ssGetOutputPortRealSignal(S, 7);
	writePoint(uPtrs, &(outputs->position));
}

/*****************************************
 * Timer
 ******************************************/

Timer::Timer() {
	start_time = 0.0;
}

void Timer::reset(SimStruct *S) {
	this->start_time = (real_T)ssGetT(S);
}

real_T Timer::elapsedTime(SimStruct *S) {
	return ((real_T)(ssGetT(S)) - this->start_time);
}


/******************************************
* Random
*********************************************/

Random::Random() {
	z = 362436069;
	w = 521288629;
	jsr = 123456789;
	jcong = 380116160;
}

unsigned long Random::kiss() {
	unsigned long mwc, cong, shr3;

	this->w = 18000*(w&65535)+(w>>16);
	this->z = 36969*(z&65535)+(z>>16);
	mwc = ((this->z)<<16) + this->w;

	this->jcong = 69069 * this->jcong + 1234567;
	cong = this->jcong;

	this->jsr = (this->jsr)^((this->jsr)<<17);
	this->jsr = (this->jsr)^((this->jsr)>>13);
	this->jsr = (this->jsr)^((this->jsr)<<5);
	shr3 = this->jsr;

	return ((mwc^cong)+shr3);
}

double Random::getDouble(double low, double high) {
	return (low + (high-low) * getDouble());
}

/* returns a number in (0, 1) */
double Random::getDouble() {
	return ( 2.328306e-10 * (double)kiss() );
}

double Random::getGaussian(double mean, double var) {
	return mean + var*getGaussian();
}

double Random::getGaussian() {
	double a = getDouble();
	double b = getDouble();
	return sqrt(-2*log(a))*cos(2*3.141592654*b);
}

/* don't use this for very big ranges 
 * (anything less than a million or so should be fine) */
int Random::getInteger(int low, int high) {
	unsigned long range = high - low + 1;
	return low + (getUL() % range);
}

unsigned long Random::getUL() {
	return kiss();
}
