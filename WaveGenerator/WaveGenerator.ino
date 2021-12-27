#define AMPLITUDE 50

#include "WaveGenerator.h"
WaveGenerator wave(1000, AMPLITUDE);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel serialLed(20, 13, NEO_RGB + NEO_KHZ800);
void setup() {
  serialLed.begin();
  Serial.begin(115200);
}

void loop() {
  wave.Update();
  int cut = AMPLITUDE * 2 / 3;
  for (int i = 0; i < 20; i++)
    serialLed.setPixelColor(i, wave.GetTrapezoidal(0, 0, cut), wave.GetTrapezoidal(1000, 0, cut), wave.GetTrapezoidal(2000, 0, cut));
  Serial.print(wave.GetSquare(  0, 0, 30));    Serial.print("\n");
  Serial.print(wave.GetSquare(100, 0, 10)); Serial.print("\t");
  Serial.print(wave.GetSquare(200, 0, 10)); Serial.print("\n");
  delay(5);
  serialLed.show();
}
