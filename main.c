#include "main.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(WIRE){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (global.OSD)
        displayHUD();
    // light();
    
    glPushMatrix();
        camera();
        glDisable(GL_LIGHTING);
        xyz();
        if(LIGHT){
            light();
        }else{
            glDisable(GL_LIGHTING);
        }
        DrawBoat();
        DrawCrust();
        drawPlayer();
        DraweWater(TAN,NORMAL,BI);
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
    
    GLfloat lightpos[] = {1,2,-1,0};
    GLfloat lightpos_2[] = {-1,2,-1,0};
    glLightfv(GL_LIGHT0,GL_POSITION, lightpos);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1,GL_POSITION, lightpos_2);
    float blue[4] ={0.18f,0.54f,0.75f,1.0f};
    float white[4] ={1.0f,1.0f,1.0f,1.0f};
    glLightfv (GL_FRONT_AND_BACK, GL_AMBIENT, blue);
    glLightfv (GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
    glLightfv (GL_FRONT_AND_BACK, GL_SPECULAR, white);
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

void camera(){
    glTranslatef(0,-1.6,-4);
    glRotatef(UPDOWN,1,0,0);
    glRotatef(angle,0,1,0);
}

/*
    Keybaord Input proccessing
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(EXIT_SUCCESS);
        break;
    case '+':
        WATERSEG *= 2; 
        break;
    case '=':
        WATERSEG *= 2; 
        break;
    case '-':
        if(WATERSEG > 4){
           WATERSEG /= 2; 
        }
        break;
    case 'T':
        if(TAN){
            TAN = false;
        }else{
            TAN = true;
        }
        break;
    case 'B':
        if(BI){
            BI = false;
        }else{
            BI = true;
        }
        break;
    case 'Y':
        if(TEX){
            TEX = false;
        }else{
            TEX = true;
        }
        break;
    case 'N':
        if(NORMAL){
            NORMAL = false;
        }else{
            NORMAL = true;
        }
        break;
    case 'W':
        if(WIRE){
            WIRE = false;
        }else{
            WIRE = true;
        }
        break;
    case 'P':
        if(global.go){
            global.go = false;
        }else{
            global.go = true;
        }
        break;
    case 'O':
        if(global.OSD){
            global.OSD = false;
        }else{
            global.OSD = true;
        }
        break;
    case 'L':
        if(LIGHT){
            LIGHT = false;
        }else{
            LIGHT = true;
        }
        break;
    default:
        break;
    }
}

void keyboardSpec(int key, int x, int y){
    switch (key){
    case GLUT_KEY_LEFT:
        angle += 1;
        break;
    case GLUT_KEY_RIGHT:
        angle -= 1;
        break;

    case GLUT_KEY_UP:
        UPDOWN += 1;
        break;
    case GLUT_KEY_DOWN:
        UPDOWN -= 1;
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
        updateWaterSeg(WATERSEG);
    }
    updatePlayer(angle);
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
    // if( (int)t % 8 == 0 ){
    //     randX = rand() % 6 - 3;
    //     randZ = rand() % 6 - 3;
    //     printf("%s\n","Spawn Boat");
    //     createBoat(randX,floatObjectY(randX,randZ),randZ,floatObjectM(randX,randZ));
    // }
    for( int i = 0; i< MAX; i++){
        // float y = 0;
        float m = 0;
        // float y = floatObjectY(boatx(i),boatz(i));
        // float m = floatObjectM(boatx(i),boatz(i));
        // updateBoat(y,m,i);s
    }
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
    snprintf(buffer, sizeof buffer, "tess: %5d", WATERSEG);
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

void init()
{
    /* In this program these OpenGL calls only need to be done once,
      but normally they would go elsewhere, e.g. display */

    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    // glDisable(GL_TEXTURE_2D);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Assignment 1 Island Battle!");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboardSpec);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glEnable(GL_NORMALIZE);
    glutMotionFunc(mouseMotion); //This calls the mouse motion when the a mouse button is clicked
    // glutPassiveMotionFunc(mouseMotion); // This calls the mouse motion when the mouse moves in the window (No click needed) 
    srand((unsigned int)time(NULL));
    glutMainLoop();
    
    return EXIT_SUCCESS;
}