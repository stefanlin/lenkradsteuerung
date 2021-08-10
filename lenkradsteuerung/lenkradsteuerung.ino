
#include <AccelStepper.h>
AccelStepper motorLenkrad(AccelStepper::DRIVER); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial.begin(9600);
  Serial.println("Lenkradsteuerung Aktiv");

  motorLenkrad.setMaxSpeed(8000);
  motorLenkrad.setAcceleration(500);
  
}

void loop() {
  
  motorLenkrad.run();
  sensorValue = analogRead(analogInPin);
  
  outputValue = map(sensorValue, 0, 1023, -8000, 8000);

  if(outputValue > 0 && outputValue < 1000){
    outputValue = 0;
  }

  if(outputValue < 0 && outputValue > -1000){
    outputValue = 0;
  }

  motorLenkrad.move(outputValue);

  //Serial.println(outputValue);
}
