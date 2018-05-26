#include "boat.h"

void createBoat(){

}

void DrawBoat(){
    float red[4] ={1.0f,0.0f,0.0f,1.0f};
    float white[4] ={1.0f,1.0f,1.0f,1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,1000);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    //Top
    glNormal3f( 0.1, 0.1,-0.075);
    glVertex3f( 0.1, 0.1,-0.075);
    glNormal3f(-0.1, 0.1,-0.075);
    glVertex3f(-0.1, 0.1,-0.075);
    glNormal3f(-0.1, 0.1, 0.075);
    glVertex3f(-0.1, 0.1, 0.075);
    glNormal3f( 0.1, 0.1, 0.075);
    glVertex3f( 0.1, 0.1, 0.075);
    //Bottom
    glNormal3f( 0.1,-0.1, 0.075);
    glVertex3f( 0.1,-0.1, 0.075);    
    glNormal3f(-0.1,-0.1, 0.075);
    glVertex3f(-0.1,-0.1, 0.075);    
    glNormal3f(-0.1,-0.1,-0.075);
    glVertex3f(-0.1,-0.1,-0.075);   
    glNormal3f( 0.1,-0.1,-0.075);
    glVertex3f( 0.1,-0.1,-0.075);   
    //Front
    glNormal3f( 0.1, 0.1, 0.075);
    glVertex3f( 0.1, 0.1, 0.075);
    glNormal3f(-0.1, 0.1, 0.075);
    glVertex3f(-0.1, 0.1, 0.075);
    glNormal3f(-0.1,-0.1, 0.075);
    glVertex3f(-0.1,-0.1, 0.075);
    glNormal3f( 0.1,-0.1, 0.075);
    glVertex3f( 0.1,-0.1, 0.075);
    //Back
    glNormal3f( 0.1,-0.1,-0.075);
    glVertex3f( 0.1,-0.1,-0.075);
    glNormal3f(-0.1,-0.1,-0.075);
    glVertex3f(-0.1,-0.1,-0.075);
    glNormal3f(-0.1, 0.1,-0.075);
    glVertex3f(-0.1, 0.1,-0.075);
    glNormal3f( 0.1, 0.1,-0.075);
    glVertex3f( 0.1, 0.1,-0.075);
    //Let
    glNormal3f(-0.1, 0.1, 0.075);
    glVertex3f(-0.1, 0.1, 0.075);
    glNormal3f(-0.1, 0.1,-0.075);
    glVertex3f(-0.1, 0.1,-0.075);
    glNormal3f(-0.1,-0.1,-0.075);
    glVertex3f(-0.1,-0.1,-0.075);
    glNormal3f(-0.1,-0.1, 0.075);
    glVertex3f(-0.1,-0.1, 0.075);
    //Right
    glNormal3f( 0.1,-0.1,-0.075);
    glVertex3f( 0.1,-0.1,-0.075);
    glNormal3f( 0.1,-0.1, 0.075);
    glVertex3f( 0.1,-0.1, 0.075);
    glNormal3f( 0.1, 0.1, 0.075);
    glVertex3f( 0.1, 0.1, 0.075);
    glNormal3f( 0.1, 0.1,-0.075);
    glVertex3f( 0.1, 0.1,-0.075);
  glEnd();
  glPushMatrix();
            float x, y, z;
            float theta, phi;
            float r = 0.02;
            float stacks = 1;
            float slices = 20;
            float n = 20;
            float zStep = 2.0 / n;
            glRotatef(-45,1,0,0);
            glTranslatef(0,0.06,1.05);

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
        glPopMatrix();
}

void updateBoat(){

}