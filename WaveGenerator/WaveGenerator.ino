#include "WaveGenerator.h"
WaveGenerator wave(3000, 50);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel serialLed(20, 13, NEO_RGB + NEO_KHZ800);
void setup() {
  serialLed.begin();
  Serial.begin(115200);
}

void loop() {
  wave.Update();
  int cut = 150 / 3;
  for (int i = 0; i < 20; i++)
    serialLed.setPixelColor(i, wave.GetTrapezoidalWave(0, 0, cut), wave.GetTrapezoidalWave(1000, 0, cut), wave.GetTrapezoidalWave(2000, 0, cut));
  Serial.print(wave.GetTrapezoidalWave(0, 0, cut));   Serial.print("\t");
  Serial.print(wave.GetTrapezoidalWave(1000, 0, cut));   Serial.print("\t");
  Serial.print(wave.GetTrapezoidalWave(2000, 0, cut)); Serial.print("\n");
  delay(5);
  serialLed.show();
}
