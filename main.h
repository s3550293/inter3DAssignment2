#ifndef _main_h_
#define _main_h_

#include "util.h"
#include "water.h"
#include "island.h"
#include "player.h"

void drawLine();
void xyz(void);
void idle();
void reshape(int width, int height);
void displayHUD();
void camera();
void light();
void keyboardSpec(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
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

bool NORMAL = false;
bool TAN = false;
bool WIRE = true;
bool LIGHT = false;
bool TEX = false;
bool BI = false;

int WATERSEG = 128;
float angle = -45;
float UPDOWN = 45;



#endif