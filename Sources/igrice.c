#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#include "../Headers/igrice.h"
#include "../Headers/crtanje.h"


//----------------------------PRVA-------------------------------------------
void prva_igra(int a, int b, int c, double alfa){
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
    
}

//-------------------------DRUGA-IGRA-----------------------------------------
void druga_igra(int d, int e, int f, int g, double beta){
    //stanje na pocetku
    if(d==0 && e==0 && f==0 && g==0){
    glPushMatrix();
    glRotatef(2, 0, 1, 0);
    glTranslatef(-0.1, 0.3, 1.4);
    glColor3f(0.4, 0.1, 0.8);
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
        glColor3f(0.4, 0.1, 0.8);
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
        glColor3f(0.4, 0.1, 0.8);
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
        glColor3f(0.4, 0.1, 0.8);
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
        glColor3f(0.4, 0.1, 0.8);
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

}
//---------------------------------KONFETE-----------------------------------
 void konfete(int vreme, int i){
     
    vreme=(vreme%1000)/1000;
    
    for(int j=1; j<=100; j++){
        double rr=rand()%100, bb=rand()%100, gg=rand()%100;
        rr/=100;
        bb/=100;
        gg/=100;

        glPushMatrix();
        glColor3f(rr, bb, gg);
        glTranslatef(rr+0.5+vreme, bb+0.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr+0.5+vreme, bb-1.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb+0.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-0.5+vreme, bb-1.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb+0.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(rr-1.5+vreme, bb-1.5+vreme, gg+vreme);
        switch (i){
            case 1:
                glutSolidSphere(0.04, 50, 50);
            break;
            case 2:
                draw_star(rr, bb, gg);
            break;}
        glPopMatrix();
                            }
 }
