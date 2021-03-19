#include <math.h>
#include <PID_v1.h>
#define PIN_INPUT 0
#define PIN_OUTPUT 3
int pinOut = 10;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
 
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

void setup() {
  //initialize the variables we're linked to
 Input = analogRead(PIN_INPUT);
 Setpoint = 100;
 Serial.begin(9600);
 pinMode(10, OUTPUT);
  //turn the PID on
 myPID.SetMode(AUTOMATIC);
}
 


void loop() {             
  int val;                
  double temp;            
  val=analogRead(0);      
  temp=Thermistor(val);   
  Serial.print("Temperature = ");
  Serial.print(temp);   
  Serial.println(" F");
  if (temp >= 150){
  digitalWrite(pinOut, LOW);
  Input = analogRead(PIN_INPUT);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  }
  else {
    digitalWrite(pinOut, HIGH);
  }
  delay(500);            
}
