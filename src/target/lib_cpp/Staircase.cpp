class Staircase {
public:
	Staircase();
	//reporting functions
	int     getCurrentValue(); //returns the current value of the staircase
    int     getStartValue();
	int     getIteration(); //returns the current iteration of the staircase
	int     getBackwardStepSize();
	int		getForwardStepSize();
	int     getStepRatio();
	bool    getUseForwardLimit();
	bool    getUseBackwardLimit();
	int     getForwardLimit();
	int     getBackwardLimit();
    int     getSuccessCounter();
    int     getStaircaseDirection(); // gets the direction the staircase moves for successful trials
    
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
    void setBackwardStepSize(int step);
	void setForwardStepSize(int step);
    void setRatio(int ratio);
	void setUseForwardLimit(bool b);
	void setUseBackwardLimit(bool b);
	void setForwardLimit(int limit);
	void setBackwardLimit(int limit);
	void setSuccessCounter(int ctr);
    void setStaircaseDirection(int dir); // sets the direction the staircase moves in for successful trials
    
	void    setStaircaseDefault();
    void    Staircase::setStaircaseDefault(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int dir);
	void    setStaircaseParams();
    void    Staircase::setStaircaseParams(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int successCounter,int dir);
protected:
	int     current_value;
    int     start_value;
	int     iteration;
	int     step_size_backward;
	int		step_size_forward;
	int     step_ratio;
	bool    use_forward_limit;
	bool    use_backward_limit;
	int     forward_limit;
	int     backward_limit;
    int     success_counter;
    int     direction;
    
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
    int     default_direction;
    
};

Staircase::Staircase() { 
	current_value=0;
    start_value=0;
	iteration=0;
	step_size_forward = 1;
	step_size_backward = 1;
	step_ratio=3;//settles at success rate of ~75% in a psychometric task
	use_forward_limit=1;
	use_backward_limit=1;
	forward_limit=16;// default value for angular psychometric tasks
	backward_limit=0;// default value for angular psychometric tasks
    success_counter=0;
    direction = 1; // default direction (1) means larger stimuli with successes
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
    default_direction = 1;

}

void Staircase::restart() {
	//copies values from defaults into staircase parameters and resets the iteration counter
	current_value       =   default_current_value;
    start_value         =   default_start_value;
	iteration           =   default_iteration;
	step_size_forward   =   default_step_size;
	step_size_backward  =   default_step_size;
	step_ratio          =   default_step_ratio;
	use_forward_limit   =   default_use_forward_limit;
	use_backward_limit  =   default_use_backward_limit;
	forward_limit       =   default_forward_limit;
	backward_limit      =   default_backward_limit;
    success_counter     =   0;
    direction           =   default_direction;
}
// Set staircase parameters
void    Staircase::setCurrentValue(int value)           {	current_value       = value;        }
void    Staircase::setStartValue(int startValue)        {	start_value         = startValue;   }
void    Staircase::setIteration(int iter)               {   iteration           = iter;         }
void    Staircase::setForwardStepSize(int step)         {	step_size_forward   = step;         }
void    Staircase::setBackwardStepSize(int step)        {	step_size_backward  = step;         }
void    Staircase::setRatio(int ratio)                  {	step_ratio          = ratio;        }
void    Staircase::setUseForwardLimit(bool b)			{	use_forward_limit   = b;            }
void    Staircase::setUseBackwardLimit(bool b)			{	use_backward_limit  = b;            }
void    Staircase::setForwardLimit(int limit)           {	forward_limit       = limit;        }
void    Staircase::setBackwardLimit(int limit)          {	backward_limit      = limit;        }
void    Staircase::setSuccessCounter(int counter)		{	success_counter     = counter;      }
void    Staircase::setStaircaseDirection(int dir)       {   direction           =   dir;        }
// Get parameters
int     Staircase::getCurrentValue()                    {	return current_value;               }
int     Staircase::getStartValue()                      {   return start_value;                 }
int     Staircase::getIteration()                       {	return iteration;                   }
int     Staircase::getForwardStepSize()                 {	return step_size_forward;           }
int     Staircase::getBackwardStepSize()                {	return step_size_backward;          }
int     Staircase::getStepRatio()                       {	return step_ratio;                  }
bool    Staircase::getUseForwardLimit()                 {	return use_forward_limit;           }
bool    Staircase::getUseBackwardLimit()                {	return use_backward_limit;          }
int     Staircase::getForwardLimit()                    {	return forward_limit;               }
int     Staircase::getBackwardLimit()                   {	return backward_limit;              }
int     Staircase::getSuccessCounter()                  {	return success_counter;             }
int     Staircase::getStaircaseDirection()              {   return direction;                   }

void  Staircase::setStaircaseDefault(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int dir){
	default_current_value           =       currentValue;
    default_start_value             =       startValue;
    default_iteration               =       iter;
	default_step_size               =       stepSize;
	default_step_ratio              =       ratio;
	default_use_forward_limit       =       useForwardLimit;
	default_use_backward_limit      =       useBackwardLimit;
	default_forward_limit           =       forwardLimit;
	default_backward_limit          =       backwardLimit;
    default_direction               =       dir;
}
void  Staircase::setStaircaseParams(int currentValue, int startValue,int iter,int stepSize, int ratio,bool useForwardLimit,bool useBackwardLimit,int forwardLimit,int backwardLimit,int successCounter,int dir){
	current_value                   =       currentValue;
    start_value                     =       startValue;
    iteration                       =       iter;
    step_size_forward               =       stepSize;
    step_size_backward              =       stepSize;
	step_ratio                      =       ratio;
	use_forward_limit               =       useForwardLimit;
	use_backward_limit              =       useBackwardLimit;
	forward_limit                   =       forwardLimit;
	backward_limit                  =       backwardLimit;
    success_counter                 =       successCounter;
    direction                       =       dir;
}


void Staircase::stepForward() {
	this->iteration++;
	//If we are using limits, check whether the limit was hit
	if (this->use_forward_limit && (this->current_value + this->step_size_forward > this->forward_limit)) {
		//if the limit was hit, set current value to forward_limit
		this->current_value = this->forward_limit;
    }else{
        //step the value
        this->current_value += step_size_forward;
	}
}

void Staircase::stepBackward() {
	this->iteration++;
	//If we are using limits, check whether the limit was hit
	if (this->use_backward_limit && (this->current_value - this->step_size_backward < this->backward_limit)) {
		//if the limit was hit, set current value to backward_limit
		this->current_value = this->backward_limit;
    }else{
		//step the value
        this->current_value -= step_size_backward;
	}
}

void Staircase::addSuccess(){
   this->success_counter++;
   if(this->success_counter>=this->step_ratio){
        this->success_counter=0;
        if(this->direction <=0){
            this->stepBackward();
        }else {
            this->stepForward();
        }
   }
}
void Staircase::addFailure(){
    if(this->direction <=0){
        this->stepForward();
    }else {
        this->stepBackward();
    }
}
