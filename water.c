#include "water.h"

sinWave waves = {
    0, 0, 0, 0.5, (2 * M_PI / 1.4), 0.15, 0, 0, 70, 
};

void DraweWater(bool drawT, bool drawN, float seg){
    float z;
    float t = 0;
    float xStep = 10.0 / waves.segments;               
    float zStep = 10.0 / waves.segments;
    glEnable(GL_BLEND);
    glColor4f(0.0,0.6,0.6,.7);
    glPushMatrix();
        glTranslatef(0,0.5,0);
        for (int j = 0; j < waves.segments; j++) {
            glBegin(GL_TRIANGLE_STRIP);
            float cyan[4] ={0.0f,0.6f,0.6f,0.7f};
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cyan);
            waves.z = -5 + j * zStep;
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
                glVertex3f(waves.x,waves.y,waves.z);
                z = -5 + (j+1) * zStep;
                glVertex3f(waves.x,waves.y,z);
            }
            t += 0.03;
            glEnd();              
        }
    glDisable(GL_BLEND);   


    glColor3f(1,1,0);
    for (int j = 0; j < waves.segments+1; j++) {
        waves.z = -5 + j * zStep;
        for (int i = 0; i <= waves.segments; i++) {
            waves.x = -5.0 + i * xStep;
            waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
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
    float dy = a * k * cos(((k * x) + (1 * waves.t)) + waves.v);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin(((k * x) + (1 * waves.t)) + waves.v);
    glBegin(GL_LINES);
    glVertex3f(x,y,z);
    glVertex3f(x - dy, y + dx, z);
    glEnd();
}