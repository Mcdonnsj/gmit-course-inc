//Pin definations
#define PIN_Anologue A0
#define PIN_LED1 3
#define servoPin 9

// CLASS VARIABLES DECLARATION

//Passes data to the class constructor
Blinker blink1 = Blinker(PIN_LED1, 1000, 1000);
DepthSensor Depth1 = DepthSensor(PIN_Anologue, 1000);
ServoMotor servomotor1 = ServoMotor(servoPin,1);
  
void setup() {
//sets the serial monitor to 9600 baud rate
Serial.begin(9600); 
}

void loop() {
//calls blinking led program  
  blink1.check();
//calls Depth sensor program  
  Depth1.DataConvert();

//Prints out the resulting voltage and analog readings to the screen on the serial monitor
  Serial.print("Voltage :"); Serial.print(Depth1.getvoltage());
  Serial.println(" ");Serial.print("Analog reading :");Serial.print(Depth1.getsensorValue()); Serial.print(" ");

 //calls servo motor control using depth sensor values
  servomotor1.ServoAngle(Depth1.getsensorValue());

}
