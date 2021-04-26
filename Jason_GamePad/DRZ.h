#include "DR_MASK.h"
#include "DR_PIX.h"

int DRX;
int DRY;


void drawDR(){
    tft.setClipRect(DRX - 1, DRY + 1, 33, 33);
  tft.drawRGBBitmap(DRX, DRY, DR_PIX[0], DR_MASK[0], 32, 32);
  tft.updateScreen( );
}
