#include <Servo.h>
int buttonPin = 4;
int ServoPin = 9;
int buttonState = 0;
int lockState=0;
int prevButton = 0;
Servo myServo;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //10 and 60, 60->10 is locking
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
}
