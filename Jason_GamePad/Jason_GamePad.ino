//The hunt for Dr.Z
//Jason Bell || 03/29/21
//CRT 360 Advanced Prototyping || GamePad

#include "screen.h"
#include "frames.h"
#include "tile.h"

void setup() {
  Serial.begin(9600);
  initScreen();
}

void loop() {
  checkFrame();
  drawLevel(5);
 
}
