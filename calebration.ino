#include <Servo.h>

Servo myservo;
int servoPin = 2;

void setup() {
  Serial.begin(115200);
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
  Serial.println("MG996R Calibration");
  Serial.println("Type an angle (0-180) to calibrate the servo");
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    if (angle >= 0 && angle <= 180) {
      Serial.print("Calibrating to ");
      Serial.println(angle);
      myServo.write(angle);
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
