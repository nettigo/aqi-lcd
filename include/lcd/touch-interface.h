#if FRONTEND_LCD
#ifndef _LCD_TOUCH_INTERFACE_H
#define _LCD_TOUCH_INTERFACE_H

#include <TFT_eSPI.h>

#include "lcd/interface.h"

class TouchInterface {
  public:
  TouchInterface(TFT_eSPI *tft, Interface *interface);
  void update();
  
  private:
  TFT_eSPI *tft;
  Interface *interface;
  boolean touchDisplayed;
};

#endif
#endif