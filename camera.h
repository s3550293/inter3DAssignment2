#ifndef _camera_h_
#define _camera_h_

#include "util.h"
typedef struct camera {
    vec3f position;
    vec3f view;
    float rotate;
    float fov;
} Camera;

Camera createCamera(int height, int width);
void updateCamera();

#endif