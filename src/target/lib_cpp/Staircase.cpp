class Staircase {
public:
	Staircase();
	//reporting functions
	double  getCurrentValue(); //returns the current value of the staircase
    double  getStartValue();
	int     getIteration(); //returns the current iteration of the staircase
	double  getStepSize();
	double  getStepRatio();
	bool    getUseForwardLimit();
	bool    getUseBackwardLimit();
	double  getForwardLimit();
	double  getBackwardLimit();

	void restart(); //copies values in param variables into actual staircase variables
	//step functions
	void stepForward(); // incriments the current value and the iteration
	void stepBackward(); // decriments the current value and incriments the iteration
    void addSuccess(); 
    void addFailure();
    
    
	//variable setting functions
    void setCurrentValue(double currentValue);
	void setStartValue(double startValue);
    void setIteration(int iter);
    void setStepSize(double step);
    void setRatio(double ratio);
	void setUseForwardLimit(bool b);
	void setUseBackwardLimit(bool b);
	void setForwardLimit(double limit);
	void setBackwardLimit(double limit);
    
	void setStaircaseDefault();
    void  Staircase::setStaircaseDefault(double currentValue, double startValue,int iter,double stepSize, double ratio,bool useForwardLimit,bool useBackwardLimit,double forwardLimit,double backwardLimit);
	void setStaircaseParams();
    void  Staircase::setStaircaseParams(double currentValue, double startValue,int iter,double stepSize, double ratio,bool useForwardLimit,bool useBackwardLimit,double forwardLimit,double backwardLimit,int successCounter);
protected:
	double current_value;
    double start_value;
	int iteration;
	double step_size;
	double step_ratio;
	bool use_forward_limit;
	bool use_backward_limit;
	double forward_limit;
	double backward_limit;
    int success_counter;
	// These defaults describe the requested behavior but will not
	// take effect until Staircase::restart() is called.
	double default_current_value;
    double default_start_value;    
    int default_iteration;
	double default_step_size;
    double default_step_ratio;
	bool default_use_forward_limit;
	bool default_use_backward_limit;
	double default_forward_limit;
	double default_backward_limit;
};

Staircase::Staircase() { 
	current_value=0;
    start_value=0;
	iteration=0;
	step_size=1;
	step_ratio=3;//settles at success rate of ~75% in a psychometric task
	use_forward_limit=1;
	use_backward_limit=1;
	forward_limit=90;// default value for angular psychometric tasks
	backward_limit=0;// default value for angular psychometric tasks
    success_counter=0;
	//initialize default variables to same values
	default_current_value=0;
    default_start_value=0;
	default_iteration=0;
	default_step_size=1;
	default_step_ratio=3;
	default_use_forward_limit=1;
	default_use_backward_limit=1;
	default_forward_limit=90;
	default_backward_limit=0;

}

void Staircase::restart() {
	//copies values from defaults into staircase parameters and resets the iteration counter
	current_value       =   default_current_value;
    start_value         =   default_start_value;
	iteration           =   default_iteration;
	step_size           =   default_step_size;
	step_ratio          =   default_step_ratio;
	use_forward_limit   =   default_use_forward_limit;
	use_backward_limit  =   default_use_backward_limit;
	forward_limit       =   default_forward_limit;
	backward_limit      =   default_backward_limit;
    success_counter     =   0;
}
// Set staircase parameters
void    Staircase::setCurrentValue(double value)		{	current_value       = value;        }
void    Staircase::setStartValue(double startValue)     {	start_value         = startValue;   }
void    Staircase::setIteration(int iter)               {   iteration           = iter;         }
void    Staircase::setStepSize(double step)             {	step_size           = step;         }
void    Staircase::setRatio(double ratio)				{	step_ratio          = ratio;        }
void    Staircase::setUseForwardLimit(bool b)			{	use_forward_limit   = b;            }
void    Staircase::setUseBackwardLimit(bool b)			{	use_backward_limit  = b;            }
void    Staircase::setForwardLimit(double limit)		{	forward_limit       = limit;        }
void    Staircase::setBackwardLimit(double limit)		{	backward_limit      = limit;        }
void    Staircase::setSuccessCounter(int counter)		{	success_counter     = counter;      }
// Get parameters
double  Staircase::getCurrentValue()                    {	return current_value;               }
double  Staircase::getStartValue()                      {   return start_value;                 }
int     Staircase::getIteration()                       {	return iteration;                   }
double  Staircase::getStepSize()                        {	return step_size;                   }
double  Staircase::getStepRatio()                       {	return step_ratio;                  }
bool    Staircase::getUseForwardLimit()                 {	return use_forward_limit;           }
bool    Staircase::getUseBackwardLimit()                {	return use_backward_limit;          }
double  Staircase::getForwardLimit()                    {	return forward_limit;               }
double  Staircase::getBackwardLimit()                   {	return backward_limit;              }
void    Staircase::getSuccessCounter()                  {	return success_counter;             }

void  Staircase::setStaircaseDefault(double currentValue, double startValue,int iter,double stepSize, double ratio,bool useForwardLimit,bool useBackwardLimit,double forwardLimit,double backwardLimit){
	default_current_value           =       currentValue;
    default_start_value             =       startValue;
    default_iteration               =       iter;
	default_step_size               =       stepSize;
	default_step_ratio              =       ratio;
	default_use_forward_limit       =       useForwardLimit;
	default_use_backward_limit      =       useBackwardLimit;
	default_forward_limit           =       forwardLimit;
	default_backward_limit          =       backwardLimit;
}
void  Staircase::setStaircaseParams(double currentValue, double startValue,int iter,double stepSize, double ratio,bool useForwardLimit,bool useBackwardLimit,double forwardLimit,double backwardLimit,int successCounter){
	current_value                   =       currentValue;
    start_value                     =       startValue;
    iteration                       =       iter;
    step_size                       =       stepSize;
	step_ratio                      =       ratio;
	use_forward_limit               =       useForwardLimit;
	use_backward_limit              =       useBackwardLimit;
	forward_limit                   =       forwardLimit;
	backward_limit                  =       backwardLimit;
    success_counter                 =       successCounter;
}


void Staircase::stepForward() {
	this->iteration++;
	//If we are using limits, check whether the limit was hit
	if (use_forward_limit && (current_value+stepSize>forward_limit)) {
		//if the limit was hit, ignore the step
    }else{
        //step the value
        current_value += step_size;
	}
}

void Staircase::stepBackward() {
	this->iteration++;
	this->current_value -= this->step_size;
	//If we are using limits, check whether the limit was hit
	if (this->use_backward_limit && (this->current_value-this->step_size<this- > backward_limit)) {
		//if the limit was hit, ignore the step
    }else
		//step the value
        current_value -= step_size;
	}
}

void Staircase::addSuccess(){
   this->success_counter++;
   if(this->success_counter==this->step_ratio){
       this->success_counter=0;
       this->stepForward();
   }
}
void Staircase::addFailure(){
    this->stepBackward();
}
