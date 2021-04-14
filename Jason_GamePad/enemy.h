#include "roach_MASK.h"
#include "roach_PIX.h"


Metro enemyFrameTimer = Metro(250); //timer creation
Metro enemyBrainTimer = Metro(1000);

int enemyMargin = 1;
int enemyStatus = 1;
int enemyHealth = 1;
int enemySmart = 3;
float enemyX = 0;
float enemyY = 0;
float enemyXDir = 0;
float enemyYDir = 0;
float enemySpeed = .5;
int enemyW = 32;
int enemyH = 32;
int enemyFrame = 0;

void drawEnemy() {
  if (enemyBrainTimer.check() == true) {
    int brain = random(0, enemySmart);
    if (brain == 0) {
      enemyXDir = random(-1, 2);
      enemyYDir = random(-1, 2);
    }
    else {
      if (heroX < enemyX) {
        enemyXDir = -1;
      }
      if (heroX > enemyX) {
        enemyXDir = 1;
      }
      if (heroY < enemyY) {
        enemyYDir = -1;
      }
      if (heroY > enemyY) {
        enemyYDir = 1;
      }
    }
  }
  float nextX = enemyX + (enemyXDir * enemySpeed);
  float nextY = enemyY + (enemyYDir * enemySpeed);

  if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) {
    enemyX = nextX;
    enemyY = nextY;
  }
  if (enemyXDir == -1) { // cycles through my frames when my enemy is moving to the right
    if (enemyFrameTimer.check()) {
      enemyFrame = (enemyFrame + 1) % 2;
      enemyFrame = 0;
    }
  }
  if (enemyXDir == 1) { // cycles through my frames when my enemy is moving to the left
    if (enemyFrameTimer.check()) {
      enemyFrame = (enemyFrame + 1) % 5;
      if (enemyFrame <4) {
        enemyFrame = 4;
      }
    }
  }
  tft.setClipRect(enemyX - enemyMargin, enemyY - enemyMargin, 37, 37);
  drawLevel(curMode);
  tft.drawRGBBitmap(enemyX, enemyY, roach_PIX[heroFrame], roach_MASK[heroFrame], enemyW, enemyH);
  tft.updateScreen( );

}
