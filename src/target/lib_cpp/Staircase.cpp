

class Staircase {
public:
	Staircase();
	double getValue();
	int getIteration();
	void restart();

	void stepForward();
	void stepBackward();

	void setStep(double step);
	void setStartValue(double startValue);
	void setRatio(int ratio);

protected:
	double step_size;
	double current_value;
	int step_ratio;

	int iteration;

	// These params describe the requested behavior but will not
	// take effect until restart is called.
	double param_step;
	double param_start_value;
	int param_ratio;
};

Staircase::Staircase() { }

double Staircase::getValue() {
	return current_value;
}

void Staircase::restart() {
	step_size = param_step;
	current_value = param_start_value;
	step_ratio = param_ratio;
	iteration = 0;
}

void Staircase::setStep(double step) {
	param_step = step;
}

void Staircase::setStartValue(double startValue) {
	param_start_value = startValue;
}

void Staircase::setRatio(int ratio) {
	param_ratio = ratio;
}

int Staircase::getIteration() {
	return iteration;
}

void Staircase::stepForward() {
	iteration++;
	current_value += step_size;
}

void Staircase::stepBackward() {
	iteration++;
	current_value -= step_size * step_ratio;
}

