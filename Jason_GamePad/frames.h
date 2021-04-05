#include <Metro.h>

Metro timer1 = Metro(1000); //timer creation
int count = 0; //loop counter

void checkFrame() { // checks to see if 1 second has passed, if it has it prints out the number of times that loop went around and resets the count to zero (FPS).
  count = count + 1;
  if (timer1.check()) {
    //Serial.println(count);
    count = 0;
  }
}
