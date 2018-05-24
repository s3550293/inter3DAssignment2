#include "player.h"
GLUquadric * qobj;

void playerIni() {
    qobj = gluNewQuadric();
    // gluQuadricNormals(qobj, GLU_SMOOTH);
}


void drawPlayer() {
    float x, y, z;
    float theta, phi;
    float r = 0.5;
    float stacks = 3;
    float slices = 50;
    float n = 20;
    float zStep = 2.0 / n;
    glColor4f(1.0, 1.0, 0.6, 1);
    glPushMatrix();
    glTranslatef(0, 0.4, 0);
    glRotatef(90, 1, 0, 0);
    for (int j = 0; j <= stacks; j++) {
        glBegin(GL_TRIANGLE_STRIP);
        phi = j / (float) n * M_PI;
        for (int i = 0; i <= slices; i++) {
            theta = i / (float) n * 2.0 * M_PI;
            x = r * cos(theta);
            y = r * sin(theta);
            z = -1 + (j) * zStep;
            glVertex3f(x,y,z);
            z = -1 + (j+1) * zStep;
            glVertex3f(x,y,z);
        }
        glEnd();
    }
    glPushMatrix();
    float x1, y1, x2, y2;
    float angle;
    glTranslatef(-0.5, -0.6, -1);
    x1 = 0.5, y1 = 0.6;
    glColor3f(1.0, 1.0, 0.6);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0 ; angle < 361.0 ; angle += 0.2) {
        x2 = x1 + sin(angle) * r;
        y2 = y1 + cos(angle) * r;
        glVertex2f(x2, y2);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}