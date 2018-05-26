#ifndef _boat_h_
#define _boat_h_

#include "util.h"

bool createBoat(float x, float y, float z, float m);
void DrawBoat();
void updateBoat(float y, float m, int index);
float boatx(int index);
float boatz(int index);

#endif