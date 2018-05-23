#include "island.h"

Vec3f *vertices;
int nv;

void drawIsland(){
    // float x,z;
    // float y = 0;
    // float n = 10;
    // float xStep = 2.5 / n;               
    // float zStep = 2.5 / n;
    // glColor4f(0.0,0.6,0.6,.7);
    // for (int j = 0; j < waves.segments; j++) {
    //     glBegin(GL_QUAD_STRIP);
    //     waves.z = -1 + j * zStep;
    //     for (int i = 0; i <= waves.segments; i++) {
    //         waves.x = -1.0 + i * xStep;
    //         waves.y = waves.a * sin((waves.k * waves.x ) + waves.v);
    //         glVertex3f(waves.x,waves.y,waves.z);
    //         // waves.z = -1 + (j+1) * zStep;
    //         glVertex3f(waves.x,waves.y,waves.z);
    //     }
    //     glEnd();                 
    // }
}

void createIsland(){
    nv = ((10+1)*(10+1));
    Vec3f *vertex;
    vertices = calloc(nv, sizeof(Vec3f));
    float x,y,z;
    float n = 15;
    float xStep = 2.0 / n;                
    float zStep = 2.0 / n;
    vertex = vertices;
    y = 0;
    for (int j = 0; j < n; j++) {
        z = -1.0 + j * zStep;
        for (int i = 0; i <= n; i++) {
            x = -1.0 + i * xStep;
            vertex->x = x;
            vertex->y = y;
            vertex->z = z;
            vertex++;
        }              
    }
}