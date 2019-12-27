#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

//---------------------DUGME-------------------------------------------------
void draw_button(double a, double b, double c)
{
 glPushMatrix();
 glColor3f(0.4, 0.4, 0.9);
 glTranslatef(a, b, c);
 glutSolidSphere(0.1, 50, 50);
 glPopMatrix();
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
        glColor3f(0, 0.8, 0.9);
        
        glVertex3f(1, 1, 1);
        glVertex3f(0.8, 1.2, 1.2);
        glVertex3f(0.8, 0.8, 1.2);
        glVertex3f(0.8, 0.8, 0.8);
        glVertex3f(0.8, 1.2, 0.8);       
        glVertex3f(0.8, 1.2, 1.2);
        glEnd();
        
        
         glBegin(GL_TRIANGLE_FAN);
         glColor3f(0, 0.7, 1);
         glVertex3f(0.6, 1, 1);
         glVertex3f(0.8, 1.2, 1.2);
         glVertex3f(0.8, 0.8, 1.2);
         glVertex3f(0.8, 0.8, 0.8);
         glVertex3f(0.8, 1.2, 0.8);       
         glVertex3f(0.8, 1.2, 1.2);
         glEnd();
         
         glPopMatrix();
     
}
//---------------------ZELENA-SFERA----------------------------------------
void draw_green(void)
{
    glPushMatrix();
    
    glColor3f(0.4, 1, 0.4);
    glutSolidSphere(0.1, 50, 50);
    
    glPopMatrix();
}
//-----------------ELEMENTI-NA-SCENI----------------------------------------
    
void elementi_scene(void){
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
}
