//The hunt for Dr.Z
//Jason Bell || 03/29/21
//CRT 360 Advanced Prototyping || GamePad

#include "screen.h"
#include "frames.h"
#include "tile.h"
#include "controls.h"
#include "hero.h"

void setup() {
  Serial.begin(9600);
  initScreen();
  initControls();
  initHero();
}

void loop() {
  checkFrame();
  getControls();
  drawHero();
 
}
