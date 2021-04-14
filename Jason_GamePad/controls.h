#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[4] {0, 1, 2, 3};
int buttonBuffer[4] {0, 0, 0, 0};
int joystickPins[2] {A0, A1};
int joystickBuffer[2] {0, 0};

int thisJoyX;
int thisJoyY;

void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

void getControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      buttonBuffer[i] = 1;
    }
    else {
      buttonBuffer[i] = 0;
    }
  }

  // centerpoint X is 494 - 550, centerpoint Y is 494 - 560
  thisJoyX = analogRead(joystickPins[0]);
  thisJoyY = analogRead(joystickPins[1]);

  if (thisJoyX < 480) {
    joystickBuffer[0] = -1;
  }
  else if (thisJoyX > 481 && thisJoyX < 560) {
    joystickBuffer[0] = 0;
  }
  else if (thisJoyX > 561) {
    joystickBuffer[0] = 1;
  }

  if (thisJoyY < 480) {
    joystickBuffer[1] = 1;
  }
  else if (thisJoyY > 481 && thisJoyY < 560) {
    joystickBuffer[1] = 0;
  }
  else if (thisJoyY > 561) {
    joystickBuffer[1] = -1;
  }
//  Serial.print(buttonBuffer[0]);
//  Serial.print(", ");
//  Serial.print(buttonBuffer[1]);
//  Serial.print(", ");
//  Serial.print(buttonBuffer[2]);
//  Serial.print(", ");
//  Serial.print(buttonBuffer[3]);
//  Serial.print(", ");
//  Serial.print(joystickBuffer[1]);
//  Serial.print(", ");
//  Serial.println(joystickBuffer[0]);
}
