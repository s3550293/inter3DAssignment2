#include "island.h"

Vec3f *vertices;
int nv;

void DrawCrust(){
    float z_Next, z, x, y;
    float segments = 15;
    float xStep = 10.0 / segments;               
    float zStep = 10.0 / segments;
    glColor4f(0.0,1.6,0.6,1);
    for (int j = 0; j < segments; j++) {
        glBegin(GL_TRIANGLE_STRIP);
        z = -5 + j * zStep;
        for (int i = 0; i <= segments; i++) {
            x = -5.0 + i * xStep;
            y = 0;
            glVertex3f(x,y,z);
            z_Next = -5 + (j+1) * zStep;
            glVertex3f(x,y,z_Next);
        }
        glEnd();                 
    }
    DrawIsland();

}

void DrawIsland(){
    // float a = 0.3;
    // float x, z, y;
    // float k = (2 * M_PI / 3);
    // float n = 40;
    // float zStep = 2.0/n;
    // float xStep = 2.0/n;
    // for (int j = 0; j < n; j++) {
    //         glBegin(GL_TRIANGLE_STRIP);
    //         // float cyan[4] ={0.0f,0.6f,0.6f,0.7f};
    //         // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cyan);
    //         z = -1 + j * zStep;
    //         for (int i = 0; i <= n; i++) {
    //             x = -1.0 + i * xStep;
    //             // waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
    //             y = calcIslandHeight(a, k, x, z);
    //             glVertex3f(x,y,z);
    //             float z_next = -1 + (j+1) * zStep;
    //             y = calcIslandHeight(a, k, x, z);
    //             glVertex3f(x,y,z_next);
    //         }
    //         glEnd();              
    //     }
    glColor4f(1.0,0.6,0.6,1);
    glutSolidSphere(1.3, 25, 25);
}
