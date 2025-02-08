#include <Servo.h>

Servo myServo;
const int buttonPin = 2;
int buttonState = 0;
bool isSpinning = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(9);
  myServo.write(90);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    isSpinning = !isSpinning;
    delay(200);
  }

  if (isSpinning) {
    myServo.write(120);
  } else {
    myServo.write(90);
  }
}
