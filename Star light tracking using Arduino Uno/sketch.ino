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

  delay(200);
}
