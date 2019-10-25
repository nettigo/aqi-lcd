#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

#include "clock.h"
#include "model.h"
#include "fetcher.h"
#include "web-config.h"

boolean connected = false;

TFT_eSPI tft = TFT_eSPI();

XPT2046_Touchscreen ts(TOUCH_CS);

void wifiConnected(Config config) {
  tft.fillScreen(0);
  initClock(config.timeZoneOffset);
  initFetcher(config.sensorUrl, config.sensorType);
  connected = true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("AQI LCD is starting!");

  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(0);

  initWebConfig(&wifiConnected, &tft);
}

void loop(void) {
  webConfigLoop();
  if (connected) {
    updateDisplay(&tft);
    updateClock(&tft);
    TS_Point p = ts.getPoint();
    if (ts.touched()) {
      
    }
  }
}