#include <ESP32Servo.h>
#include <WiFi.h>
#include "arduino_secret.h"

Servo myServo;
const int servoPin = 2;
WiFiServer socketServer(8080);

void setup() {
  Serial.begin(115200);
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
  myServo.write(40);

  WiFi.begin(SECRET_SSID, SECRET_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  socketServer.begin();
}

void loop() {
  WiFiClient client = socketServer.available();
  if (client) {
    Serial.println("Connected");
    while (client.connected()) {
      if (client.available()) {
        char command = client.read();
        if (command == '1') {
          myServo.write(40);
          Serial.println("On");
        } else if (command == '0') {
          myServo.write(15);
          Serial.println("Off");
        }
      }
    }
    client.stop();
    Serial.println("Disconnected");
  }
}