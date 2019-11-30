#include <stdlib.h>
#include <GL/glut.h>

float Xeye=0.7, Yeye=0, Zeye=2.8;

static void on_display(void);
static void on_reshape(int width,int height);
static void on_keyboard(unsigned char key, int x, int y);

static int window_width, window_height;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(1200, 1200);
    glutInitWindowPosition(500, 900);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    glClearColor(1,0.7,0.6, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    glutMainLoop();

    return 0;
}


void on_keyboard(unsigned char key, int x, int y)
{
switch (key){

case 's':
Zeye += 0.1;
glutPostRedisplay();
break;

case 'w':
Zeye -= 0.1;
glutPostRedisplay();
break;

case 'a':
Xeye -= 0.1;
glutPostRedisplay();
break;

case 'd':
Xeye += 0.1;
glutPostRedisplay();
break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glViewport(0, 0, window_width, window_height);
    
    //podesava se projekcija
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1, 10);
    
    //podesava se vidna tacka
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Xeye, Yeye, Zeye,0,0,0,1,0,0);   
//----------------------------------------------------------------
    //kocka prva
    glPushMatrix();
        glScalef(1.4, 0.5, 0.5);
        glColor3f(0.4, 0.1, 0.4);
        glutSolidCube(2);
     glPopMatrix();
    
     //kocka druga
     glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(-1.8,0,2);
        glColor3f(0.4, 0.1, 0.4);
        glutSolidCube(2);
     glPopMatrix();
     
    //trouglasta prizma
      glPushMatrix();
          glTranslatef(0.1,0,0.5);
          glRotatef(90, 0, 1, 0);
          glRotatef(90, 0, 0, 1);
         glColor3f(0.4, 0.1, 0.4);

    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
        
        //konzola
        glColor3f(1,0.9,0.8);
        glVertex3f(0.45, 0.5, 0.02);
        glVertex3f(-0.45, 0.5, 0.02);
        glVertex3f(-0.45,0,0.52);
        glVertex3f(0.45,0,0.52);
        
//         //donju kvadrat
//         glColor3f(1,0.9,1);
//         glVertex3f(0.45, 1, -0.51);
//         glVertex3f(-0.1, 1, -0.51);
//         glVertex3f(-0.1, 0.55, 0.02);
//         glVertex3f(0.45,0.55, 0.02);
        
        glColor3f(0.4, 0.1, 0.4);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
        
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}
