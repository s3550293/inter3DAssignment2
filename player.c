#include "player.h"

int playerAngle = 0;

void drawPlayer() {
    glPushMatrix();
        glRotatef(-playerAngle-75,0,1,0);
        float blue[4] ={0.18f,0.54f,0.75f,1.0f};
        float white[4] ={1.0f,1.0f,1.0f,1.0f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10);
        float x, y, z;
        float theta, phi;
        float r = 0.5;
        float stacks = 3;
        float slices = 50;
        float n = 20;
        float zStep = 2.0 / n;
        /*
            Bottom
        */
        glColor3f(0.27, 0.51, 0.71);
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
                    glNormal3f(x,y,z);
                    glVertex3f(x,y,z);
                    z = -1 + (j+1) * zStep;
                    glNormal3f(x,y,z);
                    glVertex3f(x,y,z);
                }
                glEnd();
            }   
        glPopMatrix();
        /*
            Bottom Lid
        */
        glPushMatrix();
            float x1, y1, x2, y2;
            float angle;
            glTranslatef(-0.5,1.4,-0.6);
            glRotatef(90,1,0,0);
            x1 = 0.5, y1 = 0.6;
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1, y1);
            for (angle = 0.0 ; angle < 360.0 ; angle += 1) {
                x2 = x1 + sin(angle) * r;
                y2 = y1 + cos(angle) * r;
                glVertex2f(x2, y2);
            }
            glEnd();
        glPopMatrix();
            /*
                Cube
            */
        glPushMatrix();
            glTranslatef(0,1.55,0);
            glutSolidCube(.5);
        glPopMatrix();
        // Top
        glPushMatrix();
            r = 0.25;
            stacks = 4;
            slices = 50;
            glTranslatef(0, 1.8, .75);
            for (int j = 0; j <= stacks; j++) {
                glBegin(GL_TRIANGLE_STRIP);
                phi = j / (float) n * M_PI;
                for (int i = 0; i <= slices; i++) {
                    theta = i / (float) n * 2.0 * M_PI;
                    x = r * cos(theta);
                    y = r * sin(theta);
                    z = -1 + (j) * zStep;
                    glNormal3f(x,y,z);
                    glVertex3f(x,y,z);
                    z = -1 + (j+1) * zStep;
                    glNormal3f(x,y,z);
                    glVertex3f(x,y,z);
                }
                glEnd();
            }
        glPopMatrix();
        //Side 1
        glPushMatrix();
            glTranslatef(0,1.2,0.25);
            x1 = 0, y1 = 0.6;
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1, y1);
            for (angle = 0.0 ; angle < 60.0 ; angle += 1) {
                x2 = x1 + sin(angle) * r;
                y2 = y1 + cos(angle) * r;
                glNormal3f(x2, y2, 0);
                glVertex2f(x2, y2);
            }
            glEnd();
        glPopMatrix();
        //Side 2
        glPushMatrix();
            glTranslatef(0,1.2,-0.25);
            x1 = 0, y1 = 0.6;
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x1, y1);
            for (angle = 0.0 ; angle < 60.0 ; angle += 1) {
                x2 = x1 + sin(angle) * r;
                y2 = y1 + cos(angle) * r;
                glVertex2f(x2, y2);
            }
            glEnd();
        glPopMatrix();
        //Cannon
        glPushMatrix();
            r = 0.07;
            stacks = 4;
            slices = 40;
            glRotatef(90,1,0,0);
            glRotatef(70,0,1,0);
            glTranslatef(1.7, 0,-0.25);
            for (int j = 0; j <= stacks; j++) {
                glBegin(GL_TRIANGLE_STRIP);
                phi = j / (float) n * M_PI;
                for (int i = 0; i <= slices; i++) {
                    theta = i / (float) n * 2.0 * M_PI;
                    x = r * cos(theta);
                    y = r * sin(theta);
                    z = -1 + (j) * zStep;
                    glNormal3f(x,y,z);
                    glVertex3f(x,y,z);
                    z = -1 + (j+1) * zStep;
                    glVertex3f(x,y,z);
                }
                glEnd();
            }
        glPopMatrix();
    glPopMatrix();
}

void updatePlayer(int angle){
    playerAngle = angle;
}

void drawNormals(){

}