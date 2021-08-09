
#include <AccelStepper.h>
#include <Encoder.h>

Encoder handrad(5, 6);
AccelStepper motorLenkrad; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup() {
  Serial.begin(9600);
  Serial.println("Lenkradsteuerung Aktiv");
  
  motorLenkrad.setMaxSpeed(100);
  motorLenkrad.setAcceleration(20);

  handrad.write(0);
}

long oldPosition  = -999;

void loop() {
    long diff = handrad.read();
    handrad.write(0);
    Serial.println(diff);
    motorLenkrad.move(diff);
    motorLenkrad.run();
}
