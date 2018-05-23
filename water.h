#ifndef _water_h_
#define _water_h_

#include "util.h"

void DraweWater(bool drawT, bool drawN, float seg);
void updateWater(float dt, bool drawMotion, float speed);
void drawNormal(float x, float z, float a, float k, float zStep, float j);

typedef struct { 
    // Vec3f verti[1];
    float x, y, z, wl, k, a, v, t; 
    const int segments;
} sinWave;

#endif