#include "whit_PIX.h"
#include "whit_MASK.h"

float heroX;
float heroY;
int heroW = 32;
int heroH = 32;
float heroSpeed;
boolean isDrawn;
int heroDir;
int heroFrame;
int heroHealth = 3;
int curTileX;
int curTileY;
int curTile;
Metro heroFrameTimer = Metro(250); //timer creation


void initHero() { // intially sets my hero at the center of the screen
  heroX = screenW / 2 ;
  heroY = screenH / 2;
  heroSpeed = 0.75;
  isDrawn = false;
  heroFrame = 0;
}

void drawHero() { // draws my hero
  float nextX = heroX + (float(joystickBuffer[1]) * heroSpeed);
  float nextY = heroY + (float(joystickBuffer[0]) * heroSpeed);

  if (checkMove(curMode, nextX, nextY, heroW, heroH) == true) {// checks to see if the next move is in the bounds of the game
    heroX = nextX;
    heroY = nextY;
  }

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
    if (heroFrameTimer.check()) {
      heroFrame = 1;
    }
  }
  if (buttonBuffer[3] == 1) { // left attack
    heroFrame = 8;
    if (heroFrameTimer.check()) {
      heroFrame = 5;
    }
  }

  tft.setClipRect(heroX - 1, heroY - 1, 33, 33);
  tft.drawRGBBitmap(heroX, heroY, whit_PIX[heroFrame], whit_MASK[heroFrame], heroW, heroH);
  tft.updateScreen( );



  curTileX = heroX / tileSize;
  curTileY = heroY / tileSize;
  curTile = curTileX + (curTileY * tileW);

}
