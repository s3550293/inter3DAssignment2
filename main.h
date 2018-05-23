#ifndef _main_h_
#define _main_h_

#include "util.h"
#include "water.h"

void drawLine();
void xyz(void);
void idle();
void reshape(int width, int height);
void displayHUD();
void camera();

bool SHOW_T = false;
bool SHOW_N = false;
bool WAVEMOTION = true;
float WATERSEG = 64;

float redBoatX = -0.5;
float blueBoatX = 0.5;

float redCannonAng = 315;
float blueCannonAng = 45;

float islandCannonAng = 90;

float rBHealth = 0.50;
float bBHealth = 0.50;
float iHealth = 0.50;

const float g = -1.5;
const int milli = 1000;

typedef struct {
    bool debug;
    bool wire;
    bool go;
    float startTime;
    bool OSD;
    int frames;
    float frameRate;
    float frameRateInterval;
    float lastFrameRateT;
} global_t;

float deltaT = 0;

global_t global = { false, false, true, 0.0, true, 0, 0.0, 0.2, 0.0 };

float rT = 0;
float bT = 0;
float iT = 0;
float t = 0;


#endif