#include "water.h"

sinWave waves = {
    0, 0, 0, 0.5, (2 * M_PI / 1.7), 0.25, 0, 0, 15, 
};

// void createWater(){
//     const int seg = waves.segments;
//     float xStep = 2.5 / waves.segments;               
//     float zStep = 2.5 / waves.segments;
//     waves.verti = v
//     for (int j = 0; j < waves.segments; j++) {
//         waves.z = -1 + j * zStep;
//         for (int i = 0; i <= waves.segments; i++) {
//             waves.x = -1.0 + i * xStep;
//             waves.y = waves.a * sin((waves.k * waves.x ) + waves.v);
//             glVertex3f(waves.x,waves.y,waves.z);
//             waves.z *= -1.0;
//             glVertex3f(waves.x,waves.y,waves.z);
//         }
//         glEnd();                 
//     }
// }

void DraweWater(bool drawT, bool drawN, float seg){
    float z;
    float xStep = 2.0 / waves.segments;               
    float zStep = 2.0 / waves.segments;
    glEnable(GL_BLEND);
    glColor4f(0.0,0.6,0.6,.7);
    for (int j = 0; j < waves.segments; j++) {
        glBegin(GL_TRIANGLE_STRIP);
        waves.z = -1 + j * zStep;
        for (int i = 0; i <= waves.segments; i++) {
            waves.x = -1.0 + i * xStep;
            waves.y = waves.a * sin(((waves.k * waves.x) + (2 * 1)) + waves.v);
            glVertex3f(waves.x,waves.y,waves.z);
            z = -1 + (j+1) * zStep;
            glVertex3f(waves.x,waves.y,z);
        }
        glEnd();                 
    }


    glColor3f(1,1,0);
    for (int j = 0; j < waves.segments+1; j++) {
        waves.z = -1 + j * zStep;
        for (int i = 0; i <= waves.segments; i++) {
            waves.x = -1.0 + i * xStep;
            waves.y = waves.a * sin(((waves.k * waves.x) + (2 * 1)) + waves.v);
            drawNormal(waves.x,waves.z,waves.a,waves.k,zStep,j);
        }                
    }
}

void updateWater(float dt, bool drawMotion, float speed){
    waves.v += (dt * speed);
    waves.t = dt;
}

/*
    Function called to draw the normal of a singular vertex
*/
void drawNormal(float x, float z, float a, float k, float zStep, float j){
    float y;
    float dx = 1;
    float dy = a * k * cos(((k * x) + (2 * 1)) + waves.v);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin(((k * x) + (2 * 1)) + waves.v);
    glBegin(GL_LINES);
    glVertex3f(x,y,z);
    float z_Next = -1.0 + (j + 1) * zStep;
    glVertex3f(x - dy, y + dx, z_Next);
    glEnd();
}