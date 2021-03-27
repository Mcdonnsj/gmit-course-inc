#include <Servo.h>

class ServoMotor{

  private:
  byte servoPin;
  unsigned long timeOn;
  Servo servomotor1;
  
  public:
  //class constructor
    ServoMotor(byte servoPin,unsigned long timeOn){
      pinMode(servoPin, OUTPUT);
      this->servoPin = servoPin;
      this->timeOn = timeOn;       
    }
    
  void ServoAngle(int angle){
      servomotor1.attach(servoPin);       //attaches the output pin to the servo control
      angle = map(angle, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
      servomotor1.write(angle);                  // sets the servo position according to the scaled value
      delay(timeOn);
     
     }

};
