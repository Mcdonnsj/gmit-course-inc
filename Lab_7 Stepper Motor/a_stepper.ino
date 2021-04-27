
  /*#define is a the same as using int only with end you need to use = and ; eg #define PinA 8
                                                                                int MotorSpeed = 0;
                                                                                */
  #define PinA 8
  #define PinB 9
  #define PinC 10
  #define PinD 11
  #define SpeedInputPin A0
  #define CWButton 2
  #define CCWButton 3
  #define NUMBER_OF_STEPS_PER_REV 512
  

  int MotorSpeed = 0;
  int CWButtonState = 0;
  int CCWButtonState = 0;
  aStepper motorStep = aStepper(PinA ,PinB ,PinC ,PinD);
  

  

  void setup() {
        pinMode(CWButton,INPUT); 
        pinMode(CCWButton,INPUT);
  }
  


  void loop() {
    
        //This reads the state of the pushbutton
        CWButtonState = digitalRead(CWButton);
        CCWButtonState = digitalRead(CCWButton);
        
        //If the pushbutton is pressed ButtonState goes High
        if(CWButtonState == HIGH){
          
         //Runs the Stepper Motor Forward for 1 Revolution
        for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
              MotorSpeed = analogRead(SpeedInputPin);
              float Speed = MotorSpeed * (5.0/1023);
              motorStep.StepForward(Speed); 
          }
        }
        
        //When pushbutton is not pressed ButtonState goes Low
        if(CCWButtonState == HIGH){
          
        //This Runs the Stepper Motor in Reverse for 1 Revolution
        for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
              MotorSpeed = analogRead(SpeedInputPin);
              float Speed = MotorSpeed * (5.0/1023);
              motorStep.StepReverse(Speed);    
          }
        }
  }
