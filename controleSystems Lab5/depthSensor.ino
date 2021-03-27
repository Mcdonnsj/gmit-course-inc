


//class Definition

class DepthSensor{

  private:
  int Pin_Input;
  int Sample_Time;
  int sensorValue;
  float voltage;
  unsigned long nextChangeTime = 0;
  
  public:
//constructor taking inputs from main tab and applying them to class variables
   DepthSensor(byte Pin_Input,int Sample_Time){
    this->Pin_Input = Pin_Input;
    this->Sample_Time = Sample_Time;
   }

//Function for converting an anologue input into a voltage output
   void DataConvert(){
    
    unsigned long currentTime = millis();
    
//data output smoothing
    if(currentTime >= nextChangeTime) {
      
//reads from anologue pin a0 and converts to a voltage
     this->sensorValue = analogRead(Pin_Input);
          
// Convert the analog reading (from 0 - 1023) to a voltage (0 - 5V) and store it in variable voltage
   this-> voltage = sensorValue * (5.0 / 1023.0);
    nextChangeTime = currentTime + Sample_Time;
    }
  }

// Function to return the voltage output to the main tab so it can be printed
   float getvoltage(){
      return voltage;
    }
    int getsensorValue(){
      return sensorValue;
      delay(100);
    }
  
 };
