# Wave generator on Arduino

様々な波を出力できます

![](/sine_wave.png)

## Wave type
- 正弦波
- 方形波
- のこぎり波
- 三角波
- 台形波

## function list
- setter
```
void Update
void SetAmplitude
void SetCycle
void SetFrequency
void SetAngularFrequency
```
- getter
```
double GetSine
double GetSquare
double GetSawtooth
double GetTriangle
double GetTrapezoidal 
```

# Usage
引数で波形の位相を表現できます

台形波は3つ目の引数で切り取る高さを指定すると出力できます


