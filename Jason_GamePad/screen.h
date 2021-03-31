#include <SPI.h>
#include <ILI9341_t3n.h>
#include <Metro.h>
#define TFT_DC  9
#define TFT_CS  10
#define TFT_RST 8
ILI9341_t3n tft = ILI9341_t3n(TFT_CS, TFT_DC, TFT_RST);
#define screenW  320
#define screenH  240
DMAMEM uint16_t screenBuffer[screenW * screenH];       // Screen Buffer

Metro timer2 = Metro(2000); //timer creation
boolean flip = true; // boolean to help screenTeest()


void initScreen() {
  tft.begin();                            // Connect to LCD Screen
  tft.setRotation(3);                   // Rotate Screen 270 Degrees

  tft.setFrameBuffer(screenBuffer);   // Initialize Frame Buffer
  tft.useFrameBuffer(1);                // Use Frame Buffer

  tft.fillScreen(ILI9341_BLACK);      // Clear Screen
  //Serial.println("done!");
}

void screenTest() { // checks to see of 2 seconds has passed, if it has it flips the 'flip' boolean, changing the color on the screen.
  if (timer2.check()) {
    flip = !flip;
  }
  if (flip == true) {
    tft.fillScreen(ILI9341_BLACK);
    tft.updateScreen();
    //Serial.println("black");
  }
  else {
    tft.fillScreen(ILI9341_WHITE);
    tft.updateScreen();
    //Serial.println("white");
  }
}
