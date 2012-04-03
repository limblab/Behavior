#ifndef _BEHAVIOR_H
#define _BEHAVIOR_H 1

#include "simstruc.h"

#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74
#define STATE_DATA_BLOCK 255

class TrialCounter {
public:
	int successes;
	int failures;
	int aborts;
	int incompletes;

	TrialCounter();
};

class Timer {
public:
	Timer();
	void reset(SimStruct *S);
	real_T elapsedTime(SimStruct *S);
private:
	real_T start_time;
};

class Point {
public:
    Point();
    Point(real_T x, real_T y);
    
	real_T x, y;
};

class Target {
public:
	virtual void copyToOutputs(real_T *u, int offset) = 0;
	virtual bool cursorInTarget(double x, double y) = 0;
	virtual bool cursorInTarget(Point *p) = 0;

	static int Color(int red, int green, int blue);
};

class RectangleTarget : public Target {
public: 
	RectangleTarget();
	RectangleTarget(double left, double top, double right, double bottom, int type);
	void copyToOutputs(real_T *u, int offset);
	bool cursorInTarget(double x, double y);
	bool cursorInTarget(Point *p);

	double left, right, top, bottom, type;
};

class CircleTarget : public Target {
public:
	CircleTarget();
	CircleTarget(double centerX, double centerY, double radius);
	void copyToOutputs(real_T *u, int offset);
	bool cursorInTarget(double x, double y);
	bool cursorInTarget(Point *p);

	double centerX, centerY, radius;
};

class SquareTarget : public Target {
public:
	SquareTarget();
	SquareTarget(double centerX, double centerY, double width, int color);
	void copyToOutputs(real_T *u, int offset);
	bool cursorInTarget(double x, double y);
	bool cursorInTarget(Point *p);

	double centerX, centerY, width;
    int color;
};

class Outputs {
public:
	Point force;
	int status[5];
	int word;
	Target *targets[2];
	int reward;
	int tone_counter;
	int last_tone_id;
	int version[4];
	Point position;
};

class Random {
public:
	Random();
	double getDouble(double low, double high);
	double getDouble(); // defaults zero to one
	double getGaussian(double mean, double var); 
	double getGaussian(); // mean zero, var one
	int getInteger(int low, int high);
	unsigned long getUL();
private:
	unsigned long z, w, jsr, jcong;
	unsigned long kiss();
};

class Behavior {
public:
	Behavior();
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);

protected:
	void updateParameters(SimStruct *S);
	void setNumParams(int n);
	void readInputs(SimStruct *S);

	void updateTrialCounters();
	void writeOutputs(SimStruct *S);

	void setState(int state);
	int getState();
	bool isNewState();

	void playTone(int ToneID);

	int numParams;
	double* paramValues;

	int tone_counter;
	int last_tone_id;

	/* trial counters */
	TrialCounter *trialCounter;
	int masterResetCounter;

	Outputs *outputs;

	Timer *stateTimer;
	Random *random;

	/* databurst */
	/* TODO: add this */

	Target *nullTarget;

	Point *cursor;

	Point *force;
	Point *catchForce;

	SimStruct *S;

private:
	int state;
	bool state_changed;
};

#endif /* _BEHAVIOR_H */



