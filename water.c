#include "water.h"

sinWave waves = {
    0, 0, 0, 0.5, (2 * M_PI / 7), 0.25, 0, 0, 100, 
};

void DraweWater(bool drawT, bool drawN, bool drawB){
    float z;
    float t = 0;
    float xStep = 10.0 / waves.segments;               
    float zStep = 10.0 / waves.segments;
    // glDisable(GL_DEPTH_TEST);
    
    glPushMatrix();
        float cyan[4] ={0.45f,0.76f,0.75f,0.7f};
        float white[4] ={1.0f,1.0f,1.0f,0.7f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cyan);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyan);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,50);
        glColor4f(0.45f,0.76f,0.75f,0.7f);
        glTranslatef(0,0.5,0);
        for (int j = 0; j < waves.segments; j++) {
            glBegin(GL_TRIANGLE_STRIP);
            waves.z = -5 + j * zStep;
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                // waves.y = waves.a * sin(((waves.k * waves.x) + (1 * waves.t)) + waves.v);
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, waves.z, waves.t);
                glNormal3f(waves.x,waves.y,waves.z);
                glVertex3f(waves.x,waves.y,waves.z);
                z = -5 + (j+1) * zStep;
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
                // glNormal3f(waves.x,waves.y,z);
                glVertex3f(waves.x,waves.y,z);
            }
            glEnd();              
        }
    // glEnable(GL_DEPTH_TEST); 

    if(drawN){
        glColor3f(1,1,0);
        for (int j = 0; j < waves.segments+1; j++) {
            waves.z = -5 + j * zStep;
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
                drawNormal(waves.x,waves.z,waves.a,waves.k,zStep,j);
            }                
        }
    }
    if(drawT){
        glColor3f(1,0,1);
        for (int j = 0; j < waves.segments+1; j++) {
            waves.z = -5 + j * zStep;
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
                drawTagent(waves.x,waves.z,waves.a,waves.k,zStep,j);
            }                
        }
    }
    if(drawB){
        glColor3f(1,0,1);
        for (int j = 0; j < waves.segments+1; j++) {
            waves.z = -5 + j * zStep;
            for (int i = 0; i <= waves.segments; i++) {
                waves.x = -5.0 + i * xStep;
                waves.y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
                drawBinormals(waves.x,waves.z,waves.a,waves.k,zStep,j);
            }                
        }
    }
    glPopMatrix();
}

void updateWater(float dt, bool drawMotion, float speed){
    waves.v += (dt * speed);
    waves.t = dt += waves.t;
}

void updateWaterSeg(int seg){
    waves.segments = seg;
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


/*
    Function called to draw the tangent of a singular vertex
*/
void drawTagent(float x, float z, float a, float k, float zStep, float j){
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
    glVertex3f(x + dx, y + dy, z);
    glEnd();
}

void drawBinormals(float x, float z, float a, float k, float zStep, float j){
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
    glVertex3f(x, y + dy, z + dx);
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

/*
    Function called to draw the normal of a singular vertex
*/
float floatObjectM(float x, float z){
    float val = 180.0 / M_PI;
    float y;
    float dx = 1;
    float w = .25 * M_PI;
    float dy = waves.a * waves.k * sin(((waves.k*x)*x)+((waves.k*z)*z)+(w*waves.t));
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dy /= t;
    dx /= t;
    y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
    float x2 = x - dy;
    float y2 = y + dx;
    float m = atan((x-x2)/(y-y2)) * val;
    return -m;
}
/*
    Returns the y position to the corresponding
*/
float floatObjectY(float x, float z){
    float y = calcSineWaveSum(waves.a, waves.k, waves.x, z, waves.t);
    return y;
}