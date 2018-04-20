class Staircase {
public:
	Staircase();
	//reporting functions
	int     getCurrentValue(); //returns the current value of the staircase
    int     getStartValue();
	int     getIteration(); //returns the current iteration of the staircase
	int     getStepSize();
	int     getStepRatio();
	bool    getUseForwardLimit();
	bool    getUseBackwardLimit();
	int     getForwardLimit();
	int     getBackwardLimit();
    int     getSuccessCounter();

	void    restart(); //copies values in param variables into actual staircase variables
	//step functions
	void    stepForward(); // incriments the current value and the iteration
	void    stepBackward(); // decriments the current value and incriments the iteration
    void    addSuccess(); 
    void    addFailure();
    
	//variable setting functions
    void setCurrentValue(int currentValue);
	void setStartValue(int startValue);
    void setIteration(int iter);
    void setStepSize(int step);
    void setRatio(int ratio);
	void setUseForwardLimit(bool b);
	void setUseBackwardLimit(bool b);
	void setForwardLimit(int limit);
	void setBackwardLimit(int limit);
	void setSuccessCounter(int ctr);
    
	void    setStaircaseDefault();
    void    Staircase::setStaircaseDefault(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit);
	void    setStaircaseParams();
    void    Staircase::setStaircaseParams(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int successCounter);
protected:
	int     current_value;
    int     start_value;
	int     iteration;
	int     step_size;
	int     step_ratio;
	bool    use_forward_limit;
	bool    use_backward_limit;
	int     forward_limit;
	int     backward_limit;
    int     success_counter;
	// These defaults describe the requested behavior but will not
	// take effect until Staircase::restart() is called.
	int     default_current_value;
    int     default_start_value;    
    int     default_iteration;
	int     default_step_size;
    int     default_step_ratio;
	bool    default_use_forward_limit;
	bool    default_use_backward_limit;
	int     default_forward_limit;
	int     default_backward_limit;
};

Staircase::Staircase() { 
	current_value=0;
    start_value=0;
	iteration=0;
	step_size=1;
	step_ratio=3;//settles at success rate of ~75% in a psychometric task
	use_forward_limit=1;
	use_backward_limit=1;
	forward_limit=16;// default value for angular psychometric tasks
	backward_limit=0;// default value for angular psychometric tasks
    success_counter=0;
	//initialize default variables to same values
	default_current_value=0;
    default_start_value=0;
	default_iteration=0;
	default_step_size=1;
	default_step_ratio=3;
	default_use_forward_limit=true;
	default_use_backward_limit=true;
	default_forward_limit=16;
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
void    Staircase::setCurrentValue(int value)           {	current_value       = value;        }
void    Staircase::setStartValue(int startValue)        {	start_value         = startValue;   }
void    Staircase::setIteration(int iter)               {   iteration           = iter;         }
void    Staircase::setStepSize(int step)                {	step_size           = step;         }
void    Staircase::setRatio(int ratio)                  {	step_ratio          = ratio;        }
void    Staircase::setUseForwardLimit(bool b)			{	use_forward_limit   = b;            }
void    Staircase::setUseBackwardLimit(bool b)			{	use_backward_limit  = b;            }
void    Staircase::setForwardLimit(int limit)           {	forward_limit       = limit;        }
void    Staircase::setBackwardLimit(int limit)          {	backward_limit      = limit;        }
void    Staircase::setSuccessCounter(int counter)		{	success_counter     = counter;      }
// Get parameters
int     Staircase::getCurrentValue()                    {	return current_value;               }
int     Staircase::getStartValue()                      {   return start_value;                 }
int     Staircase::getIteration()                       {	return iteration;                   }
int     Staircase::getStepSize()                        {	return step_size;                   }
int     Staircase::getStepRatio()                       {	return step_ratio;                  }
bool    Staircase::getUseForwardLimit()                 {	return use_forward_limit;           }
bool    Staircase::getUseBackwardLimit()                {	return use_backward_limit;          }
int     Staircase::getForwardLimit()                    {	return forward_limit;               }
int     Staircase::getBackwardLimit()                   {	return backward_limit;              }
int     Staircase::getSuccessCounter()                  {	return success_counter;             }

void  Staircase::setStaircaseDefault(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit){
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
void  Staircase::setStaircaseParams(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int successCounter){
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
	if (this->use_forward_limit && (this->current_value + this->step_size > this->forward_limit)) {
		//if the limit was hit, ignore the step
    }else{
        //step the value
        this->current_value += step_size;
	}
}

void Staircase::stepBackward() {
	this->iteration++;
	//If we are using limits, check whether the limit was hit
	if (this->use_backward_limit && (this->current_value - this->step_size < this->backward_limit)) {
		//if the limit was hit, ignore the step
    }else{
		//step the value
        this->current_value -= step_size;
	}
}

void Staircase::addSuccess(){
   this->success_counter++;
   if(this->success_counter>=this->step_ratio){
       this->success_counter=0;
       this->stepForward();
   }
}
void Staircase::addFailure(){
    this->stepBackward();
}
