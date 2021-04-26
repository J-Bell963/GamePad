#include <gfxfont.h>

#include "Graphic_PIX.h"
#include "Graphic_MASK.h"

boolean initDead;
boolean initIntro;
boolean initIntro2;
boolean initLvl1;
boolean initLvl2;
boolean initLvl3;
boolean initLvl4;
boolean initLvl5;
boolean initLvl6;
boolean initWin;

void initMode() {
  curMode = -2;
  initDead = false;
  initIntro = false;
  initIntro2 = false;
  initLvl1 = false;
  initLvl2 = false;
  initLvl3 = false;
  initLvl4 = false;
  initLvl5 = false;
  initLvl6 = false;
  initWin = false;
}


void introScreen() { // my intro screen
  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.fillScreen(ILI9341_BLACK);
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
    heroHealth = 3;
    delay(1000);
  }

  if (buttons[0].fell()) {
    curMode = -1;
    initIntro = false;
  }
}

void introScreen2() {
  if (initIntro2 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.setCursor(125, 90);
    tft.setTextColor(ILI9341_YELLOW);
    tft.setTextSize(5);
    tft.print(".");
    tft.setCursor(50, 100);
    tft.setTextSize(2);
    tft.print("Left");
    tft.setCursor(40, 120);
    tft.setTextSize(2);
    tft.print("Attack");
    tft.setCursor(165, 90);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(5);
    tft.print(".");
    tft.setCursor(215, 100);
    tft.setTextSize(2);
    tft.print("Right");
    tft.setCursor(210, 120);
    tft.setTextSize(2);
    tft.print("Attack");
    tft.setCursor(145, 70);
    tft.setTextColor(ILI9341_BLUE);
    tft.setTextSize(5);
    tft.print(".");
    tft.setCursor(40, 40);
    tft.setTextSize(2);
    tft.print("Interact/Change level");
    tft.setCursor(145, 110);
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(5);
    tft.print(".");
    tft.setCursor(95, 180);
    tft.setTextSize(2);
    tft.print("Start game");
    tft.updateScreen();
    initIntro2 = true;
  }
  if (buttons[2].fell()) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    curMode = 0;
    initIntro2 = false;
  }
}

void deadScreen() {
  if (initDead == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(90, 100);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.print("YOU DIED");
    tft.updateScreen();
    initDead = true;
  }
  if (buttonBuffer[2] == 1) {
    curMode = -2;
    initDead = false;
  }
}

void firstLevel() {// draws my courtyard level

  if (initLvl1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    heroX = 150;
    heroY = 75;
    enemyHealth = 2;
    enemyStatus = true;
    tft.updateScreen();

    initLvl1 = true;
  }
  drawLevel(0);
  updateHealth();
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
  updateHealth();
  fight();
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
  updateHealth();
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
    enemyX = 150;
    enemyY = 150;
    enemyHealth = 2;
    tft.updateScreen();

    initLvl4 = true;
  }

  drawLevel(3);
  updateHealth();
  fight();
  drawEnemy();
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
  updateHealth();
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
    DRX = 200;
    DRY = 50;
    tft.updateScreen();
    initLvl6 = true;
  }
  drawLevel(5);
  updateHealth();
  drawDR();
  drawHero();

  if (interaction[curMode][curTile] == 0x05 && buttons[0].rose()) {
    curMode = 4;
    initLvl6 = false;
    heroX = 280;
    heroY = 110;
  }
  if (interaction[curMode][curTile] == 0x08 && buttons[0].rose()) {
    curMode = 6;
    initLvl6 = false;
  }
}

void winScreen() {
  if (initWin == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(30, 100);
    tft.setTextColor(ILI9341_PINK);
    tft.setTextSize(3);
    tft.print("YOU FOUND DR.Z");
    tft.updateScreen();
    initWin = true;
  }
  if (buttonBuffer[2] == 1) {
    curMode = -2;
    initWin = false;
  }
}

void runMode() { // finite state machine that controls my levels
  switch (curMode) { // switch case of my levels
    case -3: deadScreen(); break;
    case -2: introScreen(); break;
    case -1: introScreen2(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
    case 6: winScreen(); break;
  }
}
