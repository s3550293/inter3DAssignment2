#include "island.h"

Vec3f *vertices;
int nv;

void DrawCrust(){
    float land[4] ={0.82f,0.71f,0.55f,1.0f};
    float white[4] ={1.0f,1.0f,1.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, land);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, land);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,1000);
    float z_Next, z, x, y;
    float segments = 15;
    float xStep = 10.0 / segments;               
    float zStep = 10.0 / segments;
    glColor4f(0.82,0.71,0.55,1);
    for (int j = 0; j < segments; j++) {
        glBegin(GL_TRIANGLE_STRIP);
        z = -5 + j * zStep;
        for (int i = 0; i <= segments; i++) {
            x = -5.0 + i * xStep;
            y = 0;
            glNormal3f(x,y,z);
            glVertex3f(x,y,z);
            z_Next = -5 + (j+1) * zStep;
            glVertex3f(x,y,z_Next);
        }
        glEnd();                 
    }
    DrawIsland();

}

void DrawIsland(){
    glutSolidSphere(1.3, 25, 25);
}
