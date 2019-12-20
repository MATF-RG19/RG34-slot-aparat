#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include "image.h"

#define MAX 1000
#define PI 3.14

#define FILENAME0 "plava_pozadina.bmp"
#define FILENAME1 "ekran.bmp"


#include "kordinatni.h"
#include "crtanje.h"
#include "osvetljenje.h"

static void on_display(void);
static void on_reshape(int width,int height);
static void on_keyboard(unsigned char key, int x, int y);
static void congrats(int i);
static void on_timer(int value);
static void on_mouse(int button, int state, int x, int y);
static void on_timer2(int value);
static void on_timer3(int value);
void drawString(float x, float y, float z, char *string) ;
static void initialize(void);

float Xeye=0.7, Yeye=0, Zeye=4.2;
int a=0, b=0, c=0, d=0, e=0, f=0, g=0;

static int window_width, window_height;
static float vreme;
static int timer_active, timer_active2, timer_active3;
static int broj_kredit=15, broj_pobede=0, broj_pokusaji=0;
static int uzbuna=0;
double alfa=0, beta=0;

static GLuint names[2];


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    

    glutInitWindowSize(1200, 1200);
    glutInitWindowPosition(500, 900);
    glutCreateWindow(argv[0]);
    
    glutKeyboardFunc(on_keyboard);
    glutMouseFunc(on_mouse);
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);

    glClearColor(0.6, 0.6, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    srand(time(NULL));
    initialize();

    glutMainLoop();

    return 0;
}
static void initialize(void)
{
    /* Objekat koji predstavlja teskturu ucitanu iz fajla. */
    Image * image;

    /* Ukljucuju se teksture. */
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    /*
     * Inicijalizuje se objekat koji ce sadrzati teksture ucitane iz
     * fajla.
     */
    image = image_init(0, 0);

    /* Kreira se prva tekstura. */
    image_read(image, FILENAME0);

    /* Generisu se identifikatori tekstura. */
    glGenTextures(3, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

   
    /* Kreira se druga tekstura. */
    image_read(image, FILENAME1);
 
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    image_done(image);

}


static void on_mouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==1){
    
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    
    GLdouble modelview[16];
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        gluLookAt(Xeye, Yeye, Zeye,0,0,0,1,0,0); 
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glPopMatrix();
    
    GLdouble projection[16];
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    
    double winX=(double) x;
    double winY=viewport[3] - (double)y;
    
    double rezs[3];
    double reze[3];
    
    
    
    gluUnProject(winX, winY, 1.0, modelview, projection, 
             viewport, &reze[0], &reze[1], &reze[2]); 
    
    rezs[0] = Xeye;
    rezs[1] = Yeye;
    rezs[2] = Zeye;
    
    //razdaljina centra sfere do prave centar:-0.6, 0.3, 1.5 i -0.6, -0.3, 1.5
    double c1x=-0.6, c1y=0.3, c1z=1.5, distance1=0, distance2=0, korak1=0, korak2=0;
    double vektor_prave[3];
    vektor_prave[0]=reze[0]-rezs[0];
    vektor_prave[1]=reze[1]-rezs[1];
    vektor_prave[2]=reze[2]-rezs[2];

    double norma_vektor_prave=sqrt(pow(vektor_prave[0], 2)+pow(vektor_prave[1], 2)+pow(vektor_prave[2], 2));
    
    korak1=fabs((reze[0]-rezs[0])*(rezs[0]-c1x)+
                  (reze[1]-rezs[1])*(rezs[1]-c1y)+
                  (reze[2]-rezs[2])*(rezs[2]-c1z))/
                  norma_vektor_prave;
    
    double c2x=-0.6, c2y=-0.3, c2z=1.5;
    
    korak2=fabs((reze[0]-rezs[0])*(rezs[0]-c2x)+
                  (reze[1]-rezs[1])*(rezs[1]-c2y)+
                  (reze[2]-rezs[2])*(rezs[2]-c2z))/
                  norma_vektor_prave;
                  
                  
    //rezs + vektor_prave*korak1
    double N1[3], N2[3];
    
    N1[0]=rezs[0] + vektor_prave[0]/norma_vektor_prave*korak1;
    N1[1]=rezs[1] + vektor_prave[1]/norma_vektor_prave*korak1;
    N1[2]=rezs[2] + vektor_prave[2]/norma_vektor_prave*korak1;
    
 
    distance1=sqrt(pow(N1[0]-c1x,2)+pow(N1[1]-c1y, 2)+pow(N1[2]-c1z,2));
    
    N2[0]=rezs[0] + vektor_prave[0]/norma_vektor_prave*korak2;
    N2[1]=rezs[1] + vektor_prave[1]/norma_vektor_prave*korak2;
    N2[2]=rezs[2] + vektor_prave[2]/norma_vektor_prave*korak2;
    
    distance2=sqrt(pow(N2[0]-c2x,2)+pow(N2[1]-c2y, 2)+pow(N2[2]-c2z,2));

    //Proveravamo da li je kliknuto na prvo dugme
    if(distance1<=0.1 && uzbuna==0)
    {
        a=rand()%3+1;
        b=rand()%3+1;
        c=rand()%3+1;
        
        glutTimerFunc(50, on_timer2, 0);
        timer_active2=1;
        
        broj_pokusaji++;
        broj_kredit--;
        if(a==b && b==c && a!=0){
            broj_pobede++;
            broj_kredit=broj_kredit+2;}
            
        glutPostRedisplay();
        timer_active2=0;
        alfa=0;
        
        glutPostRedisplay();
    }
    
    //Proveravamo da li je kliknuto na drugi dugme
    else if(distance2<=0.1 && uzbuna==0 && broj_kredit>=2)
    {
        d=rand()%4+1;
        e=rand()%4+1;
        f=rand()%4+1;
        g=rand()%4+1;
        
        glutTimerFunc(50, on_timer3, 0);
        timer_active3=1;
        
        broj_pokusaji++;
        broj_kredit=broj_kredit-2;
        if(d==e && e==f && f==g && d!=0){
            broj_pobede++;
            broj_kredit=broj_kredit+4;}
            
        glutPostRedisplay();
        timer_active3=0;
        beta=0;
        
        glutPostRedisplay();
        }
    }
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

        //Pobeda u prvoj igri, cheat key
        case 'l':
            a=rand()%3+1;
            b=a;
            c=a;
            glutPostRedisplay();
        break;

        //Pobeda u drugoj igri, cheat key
        case  'm':
            d=rand()%4+1;
            e=d;
            f=d;
            g=d;
            glutPostRedisplay();
        break;

        //Restart igrice
        case 'r':
            uzbuna=0;
            broj_kredit=15;
            broj_pobede=0;
            broj_pokusaji=0;
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
    setting_light();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glViewport(0, 0, window_width, window_height);
    
    
    //podesava se projekcija
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) window_width / window_height, 1, 10);
    //glFrustum(-1, 1, -1, 1, 1, 10);
    
    //podesava se vidna tacka
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Xeye, Yeye, Zeye, 0, 0, 0, 1, 0, 0); 
    
    
//-----------------ELEMENTI-NA-SCENI----------------------------------------
    
    //draw_coordinate_lines();
    
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
    
    draw_button(-0.6, 0.3, 1.5);
    draw_button(-0.6, -0.3, 1.5);
    
//--------------------TEXT--------------------------------------------
    char pokusaji[MAX], kredit[MAX], pobede[MAX];
    
    sprintf(pokusaji, "POKUSAJI: %d", broj_pokusaji);
    sprintf(kredit, "KREDIT: %d", broj_kredit);
    sprintf(pobede, "POBEDE: %d", broj_pobede);
    
    if(broj_kredit<=0){
        drawString(1.2, 0.3, 0.52, "Nemate dovoljno");
        drawString(1.1, 0.3, 0.52, "kredita");
        drawString(1, 0.3, 0.52, pobede);
        drawString(0.8, 0.3, 0.52, "Pritisnite 'r'");
        uzbuna=1;
     }
     
    else{
        drawString(1.2, 0.3, 0.52, pokusaji);
        drawString(1, 0.3, 0.52, kredit);
        drawString(0.8, 0.3, 0.52, pobede);
     }
     
//-------------------------PRVA-IGRA----------------------------------
    //stanje na pocetku
    if(a==0 && b==0 && c==0){
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(0.45, 0.28, 0.9);
    draw_element_fire();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(0.45, 0, 0.9);
    draw_diamond();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(0.45, -0.28, 0.9);
    draw_green();
    glPopMatrix();}
    
    //stanje kada se odigra prva igra
    glPushMatrix();
    glRotatef(alfa, 0, 1, 0);
    
    switch (a){

    case 1:
    glPushMatrix();
    glTranslatef(0.45, 0.28, 0.9);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.45, 0.28, 0.9);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.45, 0.28, 0.9);
    draw_green();
    glPopMatrix();
    break;
    }
    
    switch (b){

    case 1:
    glPushMatrix();
    glTranslatef(0.45, 0, 0.9);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.45, 0, 0.9);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.45, 0, 0.9);
    draw_green();
    glPopMatrix();
    break;
    }
    
    switch (c){

    case 1:
    glPushMatrix();
    glTranslatef(0.45, -0.28, 0.9);
    draw_element_fire();
    glPopMatrix();
    break;
    
    case 2:
    glPushMatrix();
    glTranslatef(0.45, -0.28, 0.9);
    draw_diamond();
    glPopMatrix();
    break;
    
    case 3:
    glPushMatrix();
    glTranslatef(0.45, -0.28, 0.9);
    draw_green();
    glPopMatrix();
    break;
    }
    glPopMatrix();
    
    if(a==b && b==c && a!=0){
        congrats(1);
    }
//-------------------------DRUGA-IGRA-----------------------------------------
    //stanje na pocetku
    if(d==0 && e==0 && f==0 && g==0){
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(-0.1, 0.3, 1.4);
    glColor3f(0.6, 0.3, 0.9);
    glutSolidSphere(0.1, 50, 50); 
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(-0.1, 0.1, 1.4);
    glColor3f(0, 0.8, 0.2);
    glutSolidSphere(0.1, 50, 50);   
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(-0.1, -0.1, 1.4);
    glColor3f(0.9, 0.2, 0.8);
    glutSolidSphere(0.1, 50, 50);   
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(-0.1, -0.3, 1.4);
    glColor3f(1, 0.7, 0.1);
    glutSolidSphere(0.1, 50, 50);
    glPopMatrix();
    }
    
    //stanje kada se odigra druga igra
    glPushMatrix();
    glRotatef(beta, 0, 1, 0);
    
    switch (d){
        case 1:
        glPushMatrix();
        glTranslatef(-0.1, 0.3, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(-0.1, 0.3, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(-0.1, 0.3, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(-0.1, 0.3, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    
    switch (e){
        case 1:
        glPushMatrix();
        glTranslatef(-0.1, 0.1, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(-0.1, 0.1, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(-0.1, 0.1, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(-0.1, 0.1, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    
    switch (f){
        case 1:
        glPushMatrix();
        glTranslatef(-0.1, -0.1, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(-0.1, -0.1, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(-0.1, -0.1, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(-0.1, -0.1, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    }
    switch (g){
        case 1:
        glPushMatrix();
        glTranslatef(-0.1, -0.3, 1.4);
        glColor3f(0.6, 0.3, 0.9);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 2:
        glPushMatrix();
        glTranslatef(-0.1, -0.3, 1.4);
        glColor3f(0, 0.8, 0.2);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 3:
        glPushMatrix();
        glTranslatef(-0.1, -0.3, 1.4);
        glColor3f(0.9, 0.2, 0.8);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
        case 4:
        glPushMatrix();
        glTranslatef(-0.1, -0.3, 1.4);
        glColor3f(1, 0.7, 0.1);
        glutSolidSphere(0.1, 50, 50); 
        glPopMatrix();
            break;
    } 
    glPopMatrix();
    
    if(d==e && e==f && f==g && d!=0){
        congrats(2);
    }
//---------------------------TEKSTURE--------------------------------------------
    //front
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1.4, -0.5, 1.501);

        glTexCoord2f(1, 0);
        glVertex3f(-0.39, -0.5, 1.501);

        glTexCoord2f(1, 1);
        glVertex3f(-0.39, 0.5, 1.501);

        glTexCoord2f(0, 1);
        glVertex3f(-1.4, 0.5, 1.501);
    glEnd();
    
    //back
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1.4, -0.5, -0.501);

        glTexCoord2f(1, 0);
        glVertex3f(1.4, -0.5, -0.501);

        glTexCoord2f(1, 1);
        glVertex3f(1.4, 0.5, -0.501);

        glTexCoord2f(0, 1);
        glVertex3f(-1.4, 0.5, -0.501);
    glEnd();
    
    //top
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(1.401, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(1.401, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(1.401, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(1.401, 0.5, -0.5);
    glEnd();
    
    //bottom
      glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1.401, 0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-1.401, 0.5, 1.5);

        glTexCoord2f(1, 1);
        glVertex3f(-1.401, -0.5, 1.5);

        glTexCoord2f(0, 1);
        glVertex3f(-1.401, -0.5, -0.5);
    glEnd();
    
    //front top
      glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(0.6, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.39, -0.5, 1.5);

        glTexCoord2f(1, 1);
        glVertex3f(-0.39, 0.5, 1.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.6, 0.5, 0.5);
    glEnd();
    
    //konzola gornja
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(0.62, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.13, -0.5, 1);

        glTexCoord2f(1, 1);
        glVertex3f(0.13, 0.5, 1);

        glTexCoord2f(0, 1);
        glVertex3f(0.62, 0.5, 0.5);
    glEnd();
    
    //konzola donja
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(0.12, -0.5, 1.05);

        glTexCoord2f(1, 0);
        glVertex3f(-0.34, -0.5, 1.45);

        glTexCoord2f(1, 1);
        glVertex3f(-0.34, 0.5, 1.45);

        glTexCoord2f(0, 1);
        glVertex3f(0.12, 0.5, 1.05);
    glEnd();
        
    //ekran
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(1.4, -0.5, 0.501);

        glTexCoord2f(1, 0);
        glVertex3f(0.6, -0.5, 0.501);

        glTexCoord2f(1, 1);
        glVertex3f(0.6, 0.5, 0.501);

        glTexCoord2f(0, 1);
        glVertex3f(1.4, 0.5, 0.501);
    glEnd(); 
    glBindTexture(GL_TEXTURE_2D, 0);

    
    glutSwapBuffers();
}

//---------------------TIMER1-------------------------------------------------
void on_timer(int value)
{
    if (value != 0)
        return;

    vreme+=0.1;

    glutPostRedisplay();

    if (timer_active)
        glutTimerFunc(20, on_timer, 0);
}
//---------------------TIMER2-------------------------------------------------
void on_timer2(int value)
{
    if (value != 0)
        return;

    alfa=alfa+2;

    glutPostRedisplay();

    if (timer_active2)
        glutTimerFunc(50, on_timer2, 0);
}
//---------------------TIMER3-------------------------------------------------
void on_timer3(int value)
{
    if (value != 0)
        return;

    beta=beta+2;

    glutPostRedisplay();

    if (timer_active3)
        glutTimerFunc(50, on_timer3, 0);
}
//-------------------CONGRATS---------------------------------------------
void congrats(int i)
{
    if(i==1){
    vreme=0;
    
    glutTimerFunc(150, on_timer, 0);
    timer_active=1;
    
    for(int j=1; j<=100; j++){
        
        double rr=rand()%100, bb=rand()%100, gg=rand()%100;
        rr/=100;
        bb/=100;
        gg/=100;
        
        glPushMatrix();
        glColor3f(rr, bb, gg);
        glTranslatef(rr+0.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr+0.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb+0.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb-1.5+vreme, gg+vreme);
        glutSolidSphere(0.04, 50, 50);
        glPopMatrix();
     
     }
     timer_active=0;
    } 
     else if(i==2){
         
    vreme=0;
    
    glutTimerFunc(100, on_timer, 0);
    timer_active=1;
    
    for(int j=1; j<=100; j++){
        
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
//------------------------------TEXT-------------------------------------------
void drawString(float x, float y, float z, char *string) {
  glColor3f(1,1,1);
  glRasterPos3f(x, y, z);

  for (char* cc = string; *cc != '\0'; cc++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *cc);
  }
}






