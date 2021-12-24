/*
        @file   WaveGenerator.h
        @brief  wave generator
        @author CaseyNelson314
        @date   2021/12/24
*/
#pragma once

class WaveGenerator {

    unsigned long time, lastTime;
    double amplitude;
    double cycle;

  public:
    WaveGenerator(double cycle = 0, double amplitude = 0): cycle(cycle), amplitude(amplitude) {}

    void Update() {
      if ((time = millis()) - lastTime > cycle)
        lastTime = time;
    }

    void SetAmplitude(double amplitude) { //振幅
      this->amplitude = amplitude;
    }
    void SetCycle(double cycle) { //波長
      this->cycle = cycle;
    }
    void SetFrequency(double Hz) { //周波数(Hz)
      cycle = (double)1000 / Hz;
    }
    void SetAngularFrequency(double rad_S) { //角周波数(ω = rad / s)
      cycle = (double)1000 / rad_S;
    }

    double GetSine(double xPhase = 0, double yPhase = 0) {//(ms)(ms)
      return amplitude * sin(((time - lastTime - xPhase) * 2 / cycle) * PI) / 2 + yPhase;
    }
    double GetSawtooth(double xPhase = 0, double yPhase = 0) {
      return amplitude * fmod(time - lastTime + (cycle - xPhase), cycle) / cycle + yPhase;
    }
    double GetTriangle(double xPhase = 0, double yPhase = 0) {
      double toMacro = GetSawtooth(xPhase) * 2 - amplitude;
      return abs(toMacro) + yPhase;
    }
    double GetTrapezoidal(double xPhase = 0, double yPhase = 0, double truncation = 0) {
      double toMacro = GetTriangle(xPhase);
      return constrain(toMacro, -truncation, truncation) * amplitude / truncation + yPhase;
    }

};
