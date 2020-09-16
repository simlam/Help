#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"

int max(int x, int y, int z) {
  int m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}

int min(int x, int y, int z){
  int m = x > y ? y : x;
  m = m > z ? z : m;
  return m;
}

int toGrayScaleAverage(int r, int g, int b) {
  //TODO: test this, it may be wrong!
  int avg = (r + g + b) / 3;
  return avg;
}

int toGrayScaleLightness(int r, int g, int b){
  int max = r >  g ? r : g;
  max = max > b ? max : b;
  int min = r > g ? g : r;
  min = min > b ? b : min;
  int light = (max + min) / 2;
  return light;

}

int toGrayScaleLuminosity(int r, int g, int b){
  int lum = (0.21 * r) + (0.72 * g) + (0.07 * b);
  return lum;
}

int toSepiaRed(int r, int g, int b){
  return (0.393 * r) + (0.769 * g) + (0.189 * b);
}

int toSepiaBlue(int r, int g, int b){
  return (0.349 * r) + (0.686 * g) + (0.168 * b);
}

int toSepiaGreen(int r, int g, int b){
  return (0.272 * r) + (0.534 * g) + (0.131 * b);
}
