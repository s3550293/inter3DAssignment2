#include "island.h"

Vec3f *vertices;
int nv;

void drawIsland(){
    float z_Next, z, x, y;
    float segments = 15;
    float xStep = 2.0 / segments;               
    float zStep = 2.0 / segments;
    glEnable(GL_BLEND);
    glColor4f(0.0,0.6,0.6,.7);
    for (int j = 0; j < segments; j++) {
        glBegin(GL_TRIANGLE_STRIP);
        z = -1 + j * zStep;
        for (int i = 0; i <= segments; i++) {
            x = -1.0 + i * xStep;
            y = 0;
            glVertex3f(x,y,z);
            z_Next = -1 + (j+1) * zStep;
            glVertex3f(x,y,z_Next);
        }
        glEnd();                 
    }

}
