  class aStepper {
  

  private:
  

          byte pinA;
          byte pinB;
          byte pinC;
          byte pinD;
  

  public:
  

   aStepper(byte pinA, byte pinB, byte pinC, byte pinD){
        
          this->pinA = pinA;
          this->pinB = pinB;
          this->pinC = pinC;
          this->pinD = pinD;
  

          pinMode(pinA,OUTPUT);
          pinMode(pinB,OUTPUT);
          pinMode(pinC,OUTPUT);
          pinMode(pinD,OUTPUT);
      }
  

  void Reverse(int d,int c,int b,int a){
  

          digitalWrite(pinA,a);
          digitalWrite(pinB,b);
          digitalWrite(pinC,c);
          digitalWrite(pinD,d);
  }
  

  void Forward(int a,int b,int c,int d){
  

          digitalWrite(pinA,a);
          digitalWrite(pinB,b);
          digitalWrite(pinC,c);
          digitalWrite(pinD,d);
  }
  

  void StepForward(int DELAY){  
          Forward(1,0,0,0);
          delay(DELAY);
          Forward(1,1,0,0);
          delay(DELAY);
          Forward(0,1,0,0);
          delay(DELAY);
          Forward(0,1,1,0);
          delay(DELAY);
          Forward(0,0,1,0);
          delay(DELAY);
          Forward(0,0,1,1);
          delay(DELAY);
          Forward(0,0,0,1);
          delay(DELAY);
          Forward(1,0,0,1);
          delay(DELAY);
  }
   void StepReverse(int DELAY){  
          Reverse(1,0,0,0);
          delay(DELAY);
          Reverse(1,1,0,0);
          delay(DELAY);
          Reverse(0,1,0,0);
          delay(DELAY);
          Reverse(0,1,1,0);
          delay(DELAY);
          Reverse(0,0,1,0);
          delay(DELAY);
          Reverse(0,0,1,1);
          delay(DELAY);
          Reverse(0,0,0,1);
          delay(DELAY);
          Reverse(1,0,0,1);
          delay(DELAY);
  }
  };
