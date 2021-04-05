#include "whit_PIX.h"
#include "whit_MASK.h"

float heroX;
float heroY;
float heroSpeed;
boolean isDrawn;
int heroDir;
int heroFrame;
Metro heroFrameTimer = Metro(250); //timer creation


void initHero() { // intially sets my hero at the center of the screen 
  heroX = screenW / 2 ;
  heroY = screenH / 2;
  heroSpeed = .5;
  isDrawn = false;
  heroFrame = 0;
}

void drawHero() { 
  heroX = heroX + (joystickBuffer[1] * heroSpeed);
  heroY = heroY + (joystickBuffer[0] * heroSpeed);

  if (joystickBuffer[1] > 0) { // checks if my hero is moving to the right
    heroDir = 0;
  }
  if (joystickBuffer[1] < 0) { // checks if my hero is moving to the left
    heroDir = 1;
  }
  if (joystickBuffer[1] == 0 && heroDir == 0) { // sets right facing frame
    heroFrame = 1;
  }
  if (joystickBuffer[1] == 0 && heroDir == 1) { // sets left facing frame
    heroFrame = 6;
  }

  if (joystickBuffer[1] == 1 && heroDir == 0) { // cycles through my frames when my hero is moving to the right
    if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 3;
      heroFrame = heroFrame + 1;
    }
  }

  if (joystickBuffer[1] == -1 && heroDir == 1) {// cycles through my frames when my hero is moving to the left
    if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 7;
      if (heroFrame < 5) {
        heroFrame = 5;
      }
    }
  }

  if (buttonBuffer[1] == 1) { // right attack
    heroFrame = 4;
  }
  if (buttonBuffer[3] == 1) { // left attack
    heroFrame = 8;
  }

  if (heroX + 32 > 318 ) { // side wall bounding
    heroX = 318 - 32;
  }
  if (heroX < 2) {
    heroX = 2;
  }
  if (heroY + 32 > 238) { // top and bottom wall bounding
    heroY = 238 - 32;
  }
  if (heroY  < 2) {
    heroY = 2 ;
  }

  drawLevel(0);

  if (isDrawn == false) {
    tft.updateScreen();
    isDrawn = true;
  }

  tft.setClipRect(heroX - 5, heroY - 5, 37, 37);
  tft.drawRGBBitmap(heroX, heroY, whit_PIX[heroFrame], whit_MASK[heroFrame], 32, 32);
  tft.updateScreen();


}
