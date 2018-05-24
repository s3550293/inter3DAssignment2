#include "water.h"

sinWave waves = {
    0, 0, 0, 0.5, (2 * M_PI / 7), 0.15, 0, 0, 100, 
};

void DraweWater(bool drawT, bool drawN, float seg){
    float z;
    float t = 0;
    float xStep = 10.0 / waves.segments;               
    float zStep = 10.0 / waves.segments;
    // glDisable(GL_DEPTH_TEST);
    glColor4f(0.0,0.6,0.6,.7);
    glPushMatrix();
        glTranslatef(0,0.5,0);
        for (int j = 0; j < waves.segments; j++) {
            glBegin(GL_TRIANGLE_STRIP);
            float cyan[4] ={0.6f,0.6f,0.6f,0.0f};
            // glMaterialfv(GL_FRONT_AND_BACK, GL_POSITION, cyan);
            waves.z = -5 + j * zStep;
            glEnable(GL_NORMALIZE);
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                // waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, waves.z, waves.t);
                glVertex3f(waves.x,waves.y,waves.z);
                z = -5 + (j+1) * zStep;
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
                glVertex3f(waves.x,waves.y,z);
            }
            glEnd();              
        }
    // glEnable(GL_DEPTH_TEST); 


    glColor3f(1,1,0);
    for (int j = 0; j < waves.segments+1; j++) {
        waves.z = -5 + j * zStep;
        for (int i = 0; i <= waves.segments; i++) {
            waves.x = -5.0 + i * xStep;
            waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
            drawNormal(waves.x,waves.z,waves.a,waves.k,zStep,j);
        }                
    }
    glPopMatrix();
}

void updateWater(float dt, bool drawMotion, float speed){
    waves.v += (dt * speed);
    waves.t = dt += waves.t;
}

/*
    Function called to draw the normal of a singular vertex
*/
void drawNormal(float x, float z, float a, float k, float zStep, float j){
    float y;
    float dx = 1;
    float w = .25 * M_PI;
    float dy = a * k * sin(((k*x)*x)+((k*z)*z)+(w*waves.t));
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
    glBegin(GL_LINES);
    glVertex3f(x,y,z);
    glVertex3f(x - dy, y + dx, z);
    glEnd();
}

float calcSineWaveSum(float a, float k, float x, float z, float t){
    // A * sin(k * x + w * t)
    // A * sin(kx * x + kz * z + w * t)
    // waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
    float w = .25 * M_PI;
    // float y = a * sin((k * x) + (w * t));
    float y = a * sin(((k*x)*x)+((k*z)*z)+(w*t));
    return y;
}