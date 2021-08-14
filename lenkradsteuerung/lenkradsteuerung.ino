
#include <AccelStepper.h>
AccelStepper motorLenkrad(AccelStepper::DRIVER); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5


const int rotation = A0;  // turn
const int xAxe = A1;  // left / right
const int yAxe = A2;  // up / down

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial.begin(9600);
  Serial.println("Lenkradsteuerung Aktiv");

  motorLenkrad.setMaxSpeed(4000);
  motorLenkrad.setAcceleration(8000);
  
}

void loop() {
  const int TRIM = 1000;
  
  motorLenkrad.run();
  sensorValue = analogRead(yAxe);
  
  outputValue = map(sensorValue, 0, 1023, -4000, 4000);
  motorLenkrad.run();

  if(outputValue > 0){
    if(outputValue < TRIM)
      outputValue = 0;
    else
      outputValue -= TRIM;
  }else{
    if(outputValue > -TRIM)
      outputValue = 0;
    else
      outputValue += TRIM;
  }
  motorLenkrad.run();
  motorLenkrad.move(outputValue);
  motorLenkrad.run();
  //Serial.println(outputValue);

}
