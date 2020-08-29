#include "LedControl.h"

                          //din clk cs
LedControl lc = LedControl(11, 13, 10, 1);

void setup() {
  lc.shutdown(0, false); 
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() { 
    displayNumber(random(0, 9999));
    delay(1000);
}

void displayNumber( long number) {
  long result;
  int pos = 0 ;
  lc.clearDisplay(0);
  while ( number > 0 ) {
    result = number % 10 ; 
    number = number / 10 ;
    lc.setDigit(0,pos++,result,false);
  }
}
