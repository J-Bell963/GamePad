//The hunt for Dr.Z
//Jason Bell || 03/29/21
//CRT 360 Advanced Prototyping || GamePad

int curMode = -1;

#include "screen.h"
#include "frames.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "hero.h"
#include "enemy.h"
#include "modes.h"


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A9));
  initScreen();
  initControls();
  initHero();
  initMode();
  initNeighbors();

}

void loop() {
  //checkFrame();
  getControls();
  runMode();
  tft.updateScreen( );

}
