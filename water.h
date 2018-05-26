#ifndef _water_h_
#define _water_h_

#include "util.h"

void DraweWater(bool drawT, bool drawN, bool drawB);
void updateWater(float dt, bool drawMotion, float speed);
void drawNormal(float x, float z, float a, float k, float zStep, float j);
float calcSineWaveSum(float a, float k, float x, float z, float t);
void drawTagent(float x, float z, float a, float k, float zStep, float j);
void updateWaterSeg(int seg);
void drawBinormals(float x, float z, float a, float k, float zStep, float j);

typedef struct { 
    // Vec3f verti[1];
    float x, y, z, wl, k, a, v, t; 
    int segments;
} sinWave;

#endif