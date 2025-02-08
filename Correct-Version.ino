#include <Servo.h>

Servo myServo;
const int buttonPin = 2;
int buttonState = 0;
bool isSpinning = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(9);
  myServo.write(93);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    delay(50);
    if (digitalRead(buttonPin) == LOW) {
      isSpinning = !isSpinning;
      while (digitalRead(buttonPin) == LOW);
    }
  }

  if (isSpinning) {
    myServo.write(120);
  } else {
    myServo.write(93);
  }
}
