# Star-Tracking-System-using-Arduino-Uno-
This project uses two analog sensors to control a servo motor. The Arduino reads and compares sensor values; if the left value is higher, the servo turns left, and if the right value is higher, it turns right. If equal, the servo stays centered.
#logic:
If the value of the left sensor is greater than the value of the right sensor, then the servo turns left, and vice versa. If both the values of the sensors are equal, then the servo remains at the center with no movement.
#components:
1. Arduino Uno
2. Servo
3. Jumper wires
4. photoresistor ldr sensors 
#concept:
The Arduino reads the light intensity from the two sensors and compares the values; it rotates the servo corresponding to the direction with the higher value.
#code:
sketch.ino
#include <Servo.h>

Servo myServo;

int leftSensor = A0;
int rightSensor = A1;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {

  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print("  Right: ");
  Serial.println(rightValue);

  int angle = 90; 

  if (leftValue > rightValue) {
    angle = 60;   
  } 
  else if (rightValue > leftValue+20) {
    angle = 120;  
  }

  myServo.write(angle);

#diagram.json

{
  "version": 1,
  "author": "Sadhana S",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 0.6, "left": 9, "attrs": {} },
    {
      "type": "wokwi-photoresistor-sensor",
      "id": "ldr1",
      "top": -64,
      "left": -104.8,
      "attrs": {}
    },
    { "type": "wokwi-photoresistor-sensor", "id": "ldr2", "top": -64, "left": 183.2, "attrs": {} },
    { "type": "wokwi-servo", "id": "servo1", "top": 209.2, "left": 76.8, "attrs": {} }
  ],
  "connections": [
    [ "servo1:GND", "uno:GND.1", "black", [ "h0" ] ],
    [ "ldr1:VCC", "uno:5V", "red", [ "h0" ] ],
    [ "ldr1:AO", "uno:A0", "green", [ "h0" ] ],
    [ "ldr2:AO", "uno:A1", "green", [ "h0" ] ],
    [ "ldr1:GND", "uno:GND.2", "black", [ "h0" ] ],
    [ "ldr2:GND", "uno:GND.3", "black", [ "h0" ] ],
    [ "ldr2:VCC", "uno:5V", "red", [ "h0" ] ],
    [ "servo1:V+", "uno:5V", "green", [ "h0" ] ],
    [ "servo1:PWM", "uno:9", "green", [ "h0" ] ]
  ],
  "dependencies": {}
}
  delay(200);
  
}
