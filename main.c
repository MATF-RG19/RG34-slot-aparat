#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

float Xeye=0.7, Yeye=0, Zeye=2.8;
int a=0, b=0, c=0, d=0, e=0, f=0, g=0;

static void on_display(void);
static void on_reshape(int width,int height);
static void on_keyboard(unsigned char key, int x, int y);
static void setting_light(void);
static void draw_coordinate_lines(void);
static void draw_element_fire();
static void draw_diamond(void);
static void draw_green(void);
static void congrats(int i);
static void on_timer(int value);
static void draw_star(double boja1, double boja2, double boja3);

static int window_width, window_height;
static float vreme;
static int timer_active;

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
    
case 'q':
/* Zavrsava se program. */
exit(0);
break;

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
    
case  'k':
    srand(time(NULL));
    a=rand()%3+1;
    b=rand()%3+1;
    c=rand()%3+1;
    glutPostRedisplay();
break;

case 'l':
    srand(time(NULL));
    a=rand()%3+1;
    b=a;
    c=a;
    glutPostRedisplay();
break;

case  'n':
    srand(time(NULL));
    d=rand()%4+1;
    e=rand()%4+1;
    f=rand()%4+1;
    g=rand()%4+1;
    glutPostRedisplay();
break;

case  'm':
    srand(time(NULL));
    d=rand()%4+1;
    e=d;
    f=d;
    g=d;
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


void setting_light(){
    // Pozicija svetla
    GLfloat light_position[] = { -1, -1, -1, 0 };

    // Ambijentalna komponenta svetlosti
    GLfloat light_ambient[] = { 1, 1, 0.9, 1 };

    // Difuzna komponenta svetlosti
    GLfloat light_diffuse[] = { 0.7, 0, 0.4, 1 };
    
    // Spekularna komponenta svetlosti
    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1,};

    // Koeficijenti ambijentalne refleksije materijala
    GLfloat ambient_coeffs[] = { 1, 1, 0.9, 1 };

    // Koeficijenti difuzne refleksije materijala
    GLfloat diffuse_coeffs[] = { 0.7, 0, 0.4, 1 };

    // Koeficijenti spekularne refleksije materijala
    GLfloat specular_coeffs[] = { 1, 1, 0.9, 0 };

    // Koeficijent glatkosti materijala
    GLfloat shininess = 20;

    // Brise se prethodni sadrzaj prozora
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Ukljucuje se osvjetljenje i podesavaju parametri svetla
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    // Podesavaju se parametri materijala
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glEnable(GL_COLOR_MATERIAL);
}

static void on_display(void)
{
    setting_light();
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
//-----------------ELEMENTI-NA-SCENI----------------------------------------
    draw_coordinate_lines();
    //kocka prva
    glPushMatrix();
        glScalef(1.4, 0.5, 0.5);
        glColor3f(0, 0.3, 0.7);
        glutSolidCube(2);
     glPopMatrix();
    
     //kocka druga
     glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glColor3f(0, 0.3, 0.7);
        glTranslatef(-1.8,0,2);
        glutSolidCube(2);
     glPopMatrix();
     
    //trouglasta prizma
      glPushMatrix();
          glTranslatef(0.1,0,0.5);
          glRotatef(90, 0, 1, 0);
          glRotatef(90, 0, 0, 1);
          glColor3f(0, 0.3, 0.7);

    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
        
        //gornja konzola
        glColor3f(0,0,0.4);
        glVertex3f(0.45, 0.5, 0.02);
        glVertex3f(-0.45, 0.5, 0.02);
        glVertex3f(-0.45,0,0.52);
        glVertex3f(0.45,0,0.52);
        
         //donja kozola
         glColor3f(0,0,0.4);
         glVertex3f(0.45, 1, -0.51);
         glVertex3f(-0.45, 1, -0.51);
         glVertex3f(-0.45, 0.55, 0.02);
         glVertex3f(0.45,0.55, 0.02);
        
        glColor3f(0, 0.3, 0.7);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0.8,0.9);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

//-------------------------PRVA-IGRA----------------------------------
    if(a==0 && b==0 && c==0){
    glPushMatrix();
    glTranslatef(0.5, 0.28, 0.8);
    draw_element_fire();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5, 0, 0.8);
    draw_diamond();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5, -0.28, 0.8);
    draw_green();
    glPopMatrix();}
    
    switch (a){

    case 1:
    glPushMatrix();
    glTranslatef(0.5, 0.28, 0.8);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.5, 0.28, 0.8);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.5, 0.28, 0.8);
    draw_green();
    glPopMatrix();
    break;
    }

    switch (b){

    case 1:
    glPushMatrix();
    glTranslatef(0.5, 0, 0.8);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.5, 0, 0.8);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.5, 0, 0.8);
    draw_green();
    glPopMatrix();
    break;
    }
    
    switch (c){

    case 1:
    glPushMatrix();
    glTranslatef(0.5, -0.28, 0.8);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.5, -0.28, 0.8);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.5, -0.28, 0.8);
    draw_green();
    glPopMatrix();
    break;
    }
    
    if(a==b && b==c && a!=0)
        congrats(1);
//-------------------------DRUGA-IGRA-----------------------------------------
     if(d==0 && e==0 && f==0 && g==0){
    
    glPushMatrix();
    glTranslatef(0.1, 0.3, 1.4);
    glColor3f(0.6, 0.3, 0.9);
    glutSolidSphere(0.1, 50, 50); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1, 0.1, 1.4);
    glColor3f(0, 0.8, 0.2);
    glutSolidSphere(0.1, 50, 50);   
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1, -0.1, 1.4);
    glColor3f(0.9, 0.2, 0.8);
    glutSolidSphere(0.1, 50, 50);   
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1, -0.3, 1.4);
    glColor3f(1, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 50);
    glPopMatrix();
    }
    
    switch (d){
        case 1:
        glPushMatrix();
        glTranslatef(0.1, 0.3, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(0.1, 0.3, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(0.1, 0.3, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(0.1, 0.3, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    
    switch (e){
        case 1:
        glPushMatrix();
        glTranslatef(0.1, 0.1, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(0.1, 0.1, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(0.1, 0.1, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(0.1, 0.1, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    
    switch (f){
        case 1:
        glPushMatrix();
        glTranslatef(0.1, -0.1, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(0.1, -0.1, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(0.1, -0.1, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(0.1, -0.1, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    switch (g){
        case 1:
        glPushMatrix();
        glTranslatef(0.1, -0.3, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(0.1, -0.3, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(0.1, -0.3, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(0.1, -0.3, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    } 
    
    if(d==e && e==f && f==g && d!=0)
        congrats(2);
    
    glutSwapBuffers();
}
//---------------------TIMER-------------------------------------------------
void on_timer(int value)
{
    if (value != 0)
        return;

    vreme+=0.1;

    glutPostRedisplay();

    if (timer_active)
        glutTimerFunc(1, on_timer, 0);
}
//-------------------CONGRATS---------------------------------------------
void congrats(int i)
{
    if(i==1){
    srand(time(NULL));
    vreme=0;
    
    glutTimerFunc(1, on_timer, 0);
    timer_active=1;
    
    for(int j=1; j<=150; j++){
        
        double rr=rand()%100, bb=rand()%100, gg=rand()%100;
        rr/=100;
        bb/=100;
        gg/=100;
        
        glPushMatrix();
        glColor3f(rr, bb, gg);
        glTranslatef(rr+0.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr+0.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.05, 50, 50);
        glPopMatrix();
     }
     timer_active=0;
    } 
     else if(i==2){
         
    srand(time(NULL));
    vreme=0;
    
    glutTimerFunc(1, on_timer, 0);
    timer_active=1;
    
    for(int j=1; j<=150; j++){
        
        double rr=rand()%100, bb=rand()%100, gg=rand()%100;
        rr/=100;
        bb/=100;
        gg/=100;
        
        glPushMatrix();
        glColor3f(rr, bb, gg);
        glTranslatef(rr+0.5+vreme, bb+0.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr+0.5+vreme, bb-1.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb+0.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb-1.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb+0.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb-1.5+vreme, gg+vreme);
        draw_star(rr, bb, gg);
        glPopMatrix();
     }
     timer_active=0;
    }
}
//----------------------ZVEZDA---------------------------------------------
void draw_star(double boja1, double boja2, double boja3)
{
    glPushMatrix();
    glScalef(0.03, 0.03, 0.03);
    glColor3f(boja1, boja2, boja3);
    glBegin(GL_TRIANGLES);
         glVertex3f(0, 1.5, 0);
         glVertex3f(-0.5, 0.5, 0);
         glVertex3f(0.5, 0.5, 0);
         glEnd();
         
         glBegin(GL_TRIANGLES);
         glVertex3f(-0.5, 0.5, 0);
         glVertex3f(-1.5, 0, 0);
         glVertex3f(-0.5, -0.5, 0);
         glEnd();
         
         glBegin(GL_TRIANGLES);
         glVertex3f(0.5, -0.5, 0);
         glVertex3f(1.5, 0, 0);
         glVertex3f(0.5, 0.5, 0);
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex3f(-0.5, -0.5, 0);
         glVertex3f(0, -1.5, 0);
         glVertex3f(0.5, -0.5, 0);
         glEnd();
         
         glColor3f(boja1+0.1, boja2-0.1, boja3-0.1);
         glBegin(GL_QUADS);
         glVertex3f(-0.5, -0.5, 0);
         glVertex3f(0.5, -0.5, 0);
         glVertex3f(0.5, 0.5, 0);
         glVertex3f(-0.5, 0.5, 0);
         glEnd();
    glPopMatrix();
}
//---------------------VATRA------------------------------------------------
void draw_element_fire()
{
        glPushMatrix();
         glTranslatef(-0.5, -0.3, -0.35);
          glScalef(0.5, 0.4, 0.4);
        
        glBegin( GL_TRIANGLE_STRIP);
            glColor3f( 1.0, 0, 0);
            
            glVertex3f(1.2,0.75,1);
            glVertex3f(1.1, 0.92, 0.8);
            
            glVertex3f(1,1,1);
            glVertex3f(0.9,0.92,0.8);
            
            glVertex3f(0.8,0.85,1);
            glVertex3f(0.8,0.75,0.8);
            
            glVertex3f(0.8,0.65,1);
            glVertex3f(0.9,0.52,0.8);       
            
            glVertex3f(1,0.5,1);
            glVertex3f(1.1, 0.52, 0.8);
            
            glVertex3f(1.2,0.75,1);
        glEnd();
        
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(1, 0.7, 0.1);
        
            glVertex3f(1.2,0.75,1);
            glVertex3f(1,0.9,1.1);
            glVertex3f(0.85,0.8,1.1);
            glVertex3f(0.85,0.7,1.1);
            glVertex3f(1,0.6,1.1);
        glEnd();
        
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(1,0.2,0);
            
            glVertex3f(1.2,0.75,1);
            glVertex3f(1,1,1);
            glVertex3f(0.8,0.85,1);
            glVertex3f(0.8,0.65,1);
            glVertex3f(1,0.5,1);
        glEnd();
        
        //zuti deo
         glBegin(GL_TRIANGLE_FAN);
            glColor3f(1,0.2,0);
            
            glVertex3f(1.2,0.75,1);
            glVertex3f(1.1, 0.92, 0.8);
            glVertex3f(0.9,0.92,0.8);
            glVertex3f(0.8,0.75,0.8);
            glVertex3f(0.9,0.52,0.8);       
            glVertex3f(1.1, 0.52, 0.8);
        glEnd();
        
        glPopMatrix();
    
}
//----------------------DIJAMANT------------------------------------------
void draw_diamond(void)
{
        glPushMatrix();
        glTranslatef(-0.4, -0.5, -0.5);
        glScalef(0.5, 0.5, 0.5);
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.2, 0.8, 1);
        
        glVertex3f(1, 1, 1);
        glVertex3f(0.8, 1.2, 1.2);
        glVertex3f(0.8, 0.8, 1.2);
        glVertex3f(0.8, 0.8, 0.8);
        glVertex3f(0.8, 1.2, 0.8);       
        glVertex3f(0.8, 1.2, 1.2);
        glEnd();
        
        
         glBegin(GL_TRIANGLE_FAN);
         glColor3f(0, 0.8, 0.7);
         glVertex3f(0.6, 1, 1);
         glVertex3f(0.8, 1.2, 1.2);
         glVertex3f(0.8, 0.8, 1.2);
         glVertex3f(0.8, 0.8, 0.8);
         glVertex3f(0.8, 1.2, 0.8);       
         glVertex3f(0.8, 1.2, 1.2);
         glEnd();
         
         glPopMatrix();
     
}
//---------------------ZELENA SFERA----------------------------------------
void draw_green(void)
{
    glPushMatrix();
    
//     glTranslatef(0.3, 0, 1);
    glColor3f(0, 0.8, 0.4);
    glutSolidSphere(0.1, 50, 50);
    
    glPopMatrix();
}
//------------------------DUGME--------------------------------------------
// void draw_button(void)
// {
//     
//     
// }
//------------------------KOORDINATNI--------------------------------------
void draw_coordinate_lines(void)
{
       glColor3f(1.0,0.0,0.0); // red x
    glBegin(GL_LINES);
    // x aix
 
    glVertex3f(-4.0, 0.0f, 0.0f);
    glVertex3f(4.0, 0.0f, 0.0f);
 
    // arrow
    glVertex3f(4.0, 0.0f, 0.0f);
    glVertex3f(3.0, 1.0f, 0.0f);
 
    glVertex3f(4.0, 0.0f, 0.0f);
    glVertex3f(3.0, -1.0f, 0.0f);
    glEnd();
    glFlush();
 
 
    // y 
    glColor3f(0.0,1.0,0.0); // green y
    glBegin(GL_LINES);
    glVertex3f(0.0, -4.0f, 0.0f);
    glVertex3f(0.0, 4.0f, 0.0f);
 
    // arrow
    glVertex3f(0.0, 4.0f, 0.0f);
    glVertex3f(1.0, 3.0f, 0.0f);
 
    glVertex3f(0.0, 4.0f, 0.0f);
    glVertex3f(-1.0, 3.0f, 0.0f);
    glEnd();
    glFlush();
 
    // z 
    glColor3f(0.0,0.0,1.0); // blue z
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0f ,-4.0f );
    glVertex3f(0.0, 0.0f ,4.0f );
 
    // arrow
    glVertex3f(0.0, 0.0f ,4.0f );
    glVertex3f(0.0, 1.0f ,3.0f );
 
    glVertex3f(0.0, 0.0f ,4.0f );
    glVertex3f(0.0, -1.0f ,3.0f );
    glEnd();
    glFlush();
}
