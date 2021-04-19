#include "roach_MASK.h"
#include "roach_PIX.h"


Metro enemyFrameTimer = Metro(250); //timer creation
Metro enemyBrainTimer = Metro(1000);

int enemyMargin = 1;
int enemyHealth = 2;
int enemySmart = 3;
float enemyX = 0;
float enemyY = 0;
float enemyXDir = 0;
float enemyYDir = 0;
float enemySpeed = .5;
int enemyW = 32;
int enemyH = 32;
int enemyFrame = 0;
boolean enemyStatus = true;

void drawEnemy() { // draws my enemy
  if (enemyStatus == true) { // draws my enemy if its still alive
    if (enemyBrainTimer.check() == true) { // the AI behind my enemies movements
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

    if (checkMove(curMode, nextX, nextY, enemyW, enemyH) == true) { // checks to see if my enemies next move is a playable area
      enemyX = nextX;
      enemyY = nextY;
    }
    if (enemyXDir == 1) { // cycles through my frames when my enemy is moving to the right
      enemyFrame = 0;
      if (enemyFrameTimer.check()) {
        enemyFrame = 1;
      }
    }
    if (enemyXDir == -1) { // cycles through my frames when my enemy is moving to the left
      enemyFrame = 4;
      if (enemyFrameTimer.check()) {
        enemyFrame = 5;
      }
    }
 // draws my enemy
    tft.setClipRect(enemyX - enemyMargin, enemyY - enemyMargin, 37, 37);
    drawLevel(curMode);
    tft.drawRGBBitmap(enemyX, enemyY, roach_PIX[enemyFrame], roach_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen( );
  }
}
