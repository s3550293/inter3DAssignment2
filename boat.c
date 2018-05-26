#include "boat.h"

boatObj arr_balls[MAX] = {
    {0,0,0},{0,0,0},0,0,0
};

bool createBoat(float x, float y, float z, float m){
    for( int i = 0; i< MAX; i++){
        if(arr_balls[i].a == 0){
            arr_balls[i].pos.x = x;
            arr_balls[i].pos.y = y;
            arr_balls[i].pos.z = z;
            arr_balls[i].m = m;
            return true;
        }
    }
    return false;
}

void DrawBoat(){
    for( int i = 0; i< MAX; i++){
        if(arr_balls[i].a != 0){
            glPushMatrix();
                glTranslatef(arr_balls[i].pos.x,arr_balls[i].pos.x,arr_balls[i].pos.x);
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
            glPopMatrix();
        }
    }
}

void updateBoat(float y, float m, int index){
    if(!(arr_balls[index].a == 0)){
        arr_balls[index].pos.y = y;
        arr_balls[index].m = m;
    }
}

float boatx(int index){
    if(!(arr_balls[index].a == 0)){
        return arr_balls[index].pos.x;
    }
    return 0;
}

float boatz(int index){
    if(!(arr_balls[index].a == 0)){
        return arr_balls[index].pos.z;
    }
    return 0;
}