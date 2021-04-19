#include <gfxfont.h>

#include "Graphic_PIX.h"
#include "Graphic_MASK.h"

boolean initDeadScreen;
boolean initIntro;
boolean initLvl1;
boolean initLvl2;
boolean initLvl3;
boolean initLvl4;
boolean initLvl5;
boolean initLvl6;

void initMode() {
  initDeadScreen = false;
  initIntro = false;
  initLvl1 = false;
  initLvl2 = false;
  initLvl3 = false;
  initLvl4 = false;
  initLvl5 = false;
  initLvl6 = false;

}
void deadScreen() {
  if (initDeadScreen == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.setCursor(90, 100);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.print("YOU DIED");
  }
  heroHealth = 3;

  if (buttonBuffer[2] == 1) {
    curMode = -1;

  }
}

void introScreen() { // my intro screen
  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, Graphic_PIX[0], 320, 206);
    tft.setCursor(40, 40);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("The Hunt");
    tft.setCursor(65, 65);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("For");
    tft.setCursor(40, 105);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.print("DR");
    tft.setCursor(90, 90);
    tft.setTextColor(ILI9341_PINK);
    tft.setTextSize(5);
    tft.print("Z");
    tft.updateScreen();
    initIntro = true;
  }
  if (buttonBuffer[0] == 1) {
    curMode = 0;

  }
}


void firstLevel() {// draws my courtyard level

  if (initLvl1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    enemyX = 100;
    enemyY = 100;
    enemyHealth = 2;
    enemyStatus = true;
    tft.updateScreen();
    initLvl1 = true;
  }
  drawLevel(0);
  fight();
  drawEnemy();
  drawHero();

  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl1 = false;
    heroX = 150;
    heroY = 40;
  }
}
void secondLevel() { // draws my atruim level

  if (initLvl2 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(1);
    tft.updateScreen();
    initLvl2 = true;
  }
  drawLevel(1);
  drawHero();

  if (interaction[curMode][curTile] == 0x03 && buttons[0].rose()) {
    curMode = 2;
    initLvl2 = false;
    heroX = 280;
    heroY = 117;
  }
  if (interaction[curMode][curTile] == 0x04 && buttons[0].rose()) {
    curMode = 3;
    initLvl2 = false;
    heroX = 157;
    heroY = 40;
  }
  if (interaction[curMode][curTile] == 0x05 && buttons[0].rose()) {
    curMode = 4;
    initLvl2 = false;
    heroX = 21;
    heroY = 117;
  }
  if (interaction[curMode][curTile] == 0x06 && buttons[0].rose()) {
    curMode = 0;
    initLvl2 = false;
    heroX = 150;
    heroY = 200;
  }
}
void thirdLevel() { // draws my left lab level

  if (initLvl3 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(2);
    enemyX = 100;
    enemyY = 100;
    enemyHealth = 2;
    enemyStatus = true;
    tft.updateScreen();
    initLvl3 = true;
  }

  drawLevel(2);
  fight();
  drawEnemy();
  drawHero();

  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl3 = false;
    heroX = 20;
    heroY = 110;
  }
}
void fourthLevel() { // draws my experiment room level

  if (initLvl4 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(3);
    tft.updateScreen();
    initLvl4 = true;
  }

  drawLevel(3);
  drawHero();
  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl4 = false;
    heroX = 157;
    heroY = 200;
  }
}
void fifthLevel() { // draws my rundown hallway level

  if (initLvl5 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(4);
    enemyX = 100;
    enemyY = 100;
    enemyHealth = 2;
    enemyStatus = true;
    tft.updateScreen();
    initLvl5 = true;
  }

  drawLevel(4);
  fight();
  drawEnemy();
  drawHero();

  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl5 = false;
    heroX = 280;
    heroY = 110;
  }
  if (interaction[curMode][curTile] == 0x07 && buttons[0].rose()) {
    curMode = 5;
    initLvl5 = false;
    heroX = 20;
    heroY = 110;
  }
}
void sixthLevel() { // draws my DR.Z's lab level

  if (initLvl6 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(5);
    tft.updateScreen();
    initLvl6 = true;
  }
  drawLevel(5);
  drawHero();

  if (interaction[curMode][curTile] == 0x05 && buttons[0].rose()) {
    curMode = 4;
    initLvl6 = false;
    heroX = 280;
    heroY = 110;
  }
}

void runMode() { // finite state machine that controls my levels
  switch (curMode) { // switch case of my levels
    case -2: deadScreen(); break;
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
  }
}
