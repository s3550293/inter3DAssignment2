#include "main.h"

float angle = -45;

void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if (global.OSD)
        displayHUD();
    // light();
    glPushMatrix();
        camera(angle);
        xyz();
        // light();
        DraweWater(true,true,64);
        // DrawCrust();
        // drawPlayer();
        glDisable(GL_DEPTH_TEST);
        
        glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    global.frames++;
    if(global.debug){
        printf("\ndisplay\n");
        printf("%s\n",gluErrorString(glGetError()));
    }

    glutSwapBuffers();
}

void light(){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightpos[] = {5,8,1,0};
    glLightfv(GL_LIGHT0,GL_POSITION, lightpos);
}


/*
    Displays the XYZ axis
*/
void xyz(void){
        glBegin(GL_LINES);
        /* glColor3f(red,green,blue);*/
        glColor3f(0,1,0);
        /* glVertex3f(x,y,z);*/
        glVertex3f(0,0,0);
        glVertex3f(0,5,0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(5,0,0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,5);
        glEnd();
}

void camera(int rotaion){
    glTranslatef(0,-1.5,-7.5);
    glRotatef(40,1,0,0);
    glRotatef(rotaion,0,1,0);
}

/*
    Keybaord Input proccessing
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
    // case 'Q':
        exit(EXIT_SUCCESS);
        break;
    case 'a':
    // case 'Q':
        angle += 1;
        break;
    case 'd':
    // case 'Q':
        angle -= 1;
        break;
    default:
        break;
    }
}

void mouseMotion(int x, int y){
    printf("%d , %d\n",(x/2)%360,(x/2)%360);
}

/*
    Function to update time Delta Time and objects positions
*/
void idle(void){
    static float lastT = -1.0;
    float dt;
    
    t = glutGet(GLUT_ELAPSED_TIME) / (float)milli - global.startTime;
    
    if (lastT < 0.0) {
        lastT = t;
        return;
    }
    
    dt = t - lastT;
    if (global.debug)
        printf("%f %f\n", t, dt);
    if (global.go){
        updateWater(dt,true, 0.7);
    }
    lastT = t;
    
    /* Frame rate */
    dt = t - global.lastFrameRateT;
    if (dt > global.frameRateInterval) {
        global.frameRate = global.frames / dt;
        global.lastFrameRateT = t;
        global.frames = 0;
    }
    deltaT = dt;
    if (global.debug)
        printf("DT: %f",deltaT);
    glutPostRedisplay();
}


/*
    Displays the FPS, the length at which a frame is displayed
    and the number of vertices in the sin wave
*/
void displayHUD(){
    char buffer[30];
    char *bufp;
    int w, h;
    
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    /* Set up orthographic coordinate system to match the 
       window, i.e. (0,0)-(w,h) */
    w = glutGet(GLUT_WINDOW_WIDTH);
    h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    /* Frame rate */
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 15);
    snprintf(buffer, sizeof buffer, "fr (f/s): %6.0f", global.frameRate);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    /* Time per frame */
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 30);
    snprintf(buffer, sizeof buffer, "ft (ms/f): %5.0f", 1.0 / global.frameRate * 1000.0);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 45);
    snprintf(buffer, sizeof buffer, "tess: %5.0f", WATERSEG);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    /* Pop modelview */
    glPopMatrix();  
    glMatrixMode(GL_PROJECTION);
    
    /* Pop projection */
    glPopMatrix();  
    glMatrixMode(GL_MODELVIEW);
    
    /* Pop attributes */
    glPopAttrib();
}

void reshape(int w, int h){
    printf("Window Size: %d,%d\n",w,h);
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)(w/h), 0.01f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Assignment 1 Island Battle!");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
    //glutMotionFunc(mouseMotion); //This calls the mouse motion when the a mouse button is clicked
    glutPassiveMotionFunc(mouseMotion); // This calls the mouse motion when the mouse moves in the window (No click needed) 
    playerIni();
    glutMainLoop();
    
    return EXIT_SUCCESS;
}