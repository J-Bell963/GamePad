



void updateHealth() {
  if (heroHealth == 0) { // if the hero has no health, pulls up death screen
    curMode = -3;
  }
  if (heroHealth == 1) {
    tft.setClipRect(0, 0, 60, 20);
    tft.drawRGBBitmap(0, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.drawRGBBitmap(20, 0, BackGroundTiles_PIX[0x22], 20, 20);
    tft.drawRGBBitmap(40, 0, BackGroundTiles_PIX[0x22], 20, 20);
    tft.updateScreen();
  }
  if (heroHealth == 2) {
    tft.setClipRect(0, 0, 60, 20);
    tft.drawRGBBitmap(0, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.drawRGBBitmap(20, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.drawRGBBitmap(40, 0, BackGroundTiles_PIX[0x22], 20, 20);
    tft.updateScreen();
  }
  if (heroHealth == 3) {
    tft.setClipRect(0, 0, 60, 20);
    tft.drawRGBBitmap(0, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.drawRGBBitmap(20, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.drawRGBBitmap(40, 0, BackGroundTiles_PIX[0x21], 20, 20);
    tft.updateScreen();
  }
  tft.updateScreen();
}
