/* 
 * Depth CLASS DEFINITION
 */
class DepthSensor {
  private:

  byte PIN_Sensor;

  unsigned long timeInterval;

  float voltage = PIN_Sensor * (5.0/1023.0);
  float distance = -22*voltage+60; //Calculations
  float distance1 = (0.1064*(pow(voltage,4)))-(7.321*(pow(voltage,3)))+(45.118*(pow(voltage,2)))-(98.843*voltage)+85.045; 
  float x = voltage;

  public:
    DepthSensor(byte PIN_Sensor, unsigned long timeInterval) {

      this->timeInterval = timeInterval;
      this->x = x;
      this->distance = distance;
      this->distance1 = distance1;

      pinMode(PIN_Sensor, OUTPUT);
    }

   // Code
    void DepthCheck() {
     Serial.print("distance = "); Serial.print(distance);
     Serial.print("   voltage = ");Serial.print(voltage);
     Serial.println(" ");Serial.print("   distance1 = ");
     Serial.print(distance1);Serial.print("           ");
      }

};
