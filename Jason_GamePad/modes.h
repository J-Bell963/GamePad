//#include <Adafruit_GFX.h>
//#include <Adafruit_GrayOLED.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include "Graphic_PIX.h"
#include "Graphic_MASK.h"


boolean initIntro;
boolean initLvl1;
boolean initLvl2;
boolean initLvl3;
boolean initLvl4;
boolean initLvl5;
boolean initLvl6;

void initMode() {
  initIntro = false;
  initLvl1 = false;
  initLvl2 = false;
  initLvl3 = false;
  initLvl4 = false;
  initLvl5 = false;
  initLvl6 = false;

}

void introScreen() {
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

  for (int i = 0; i < 4; i++) {
    if (buttonBuffer[i]) {
      curMode = 0;
    }
  }
}


void firstLevel() {

  if (initLvl1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    enemyX = 100;
    enemyY = 100;
    tft.updateScreen();
    initLvl1 = true;
  }
  drawLevel(0);
  //drawEnemy();
  drawHero();
  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl1 = false;
    heroX = 150;
    heroY = 40;
  }
}
void secondLevel() {

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
void thirdLevel() {

  if (initLvl3 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(2);
    tft.updateScreen();
    initLvl3 = true;
  }
  drawLevel(2);
  drawEnemy();
  drawHero();
  if (interaction[curMode][curTile] == 0x02 && buttons[0].rose()) {
    curMode = 1;
    initLvl3 = false;
    heroX = 20;
    heroY = 110;
  }
}
void fourthLevel() {

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
void fifthLevel() {

  if (initLvl5 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(4);
    tft.updateScreen();
    initLvl5 = true;
  }
  drawLevel(4);
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
void sixthLevel() {

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

void runMode() {
  switch (curMode) {
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
  }
}
