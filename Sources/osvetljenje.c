#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#include "../Headers/osvetljenje.h"

void setting_light(){
    glShadeModel(GL_SMOOTH);
    
    GLfloat light_position[] = { 1, -1, 1, 0 };

    GLfloat light_ambient[] = { 1, 1, 0.9, 1 };
    GLfloat light_diffuse[] = { 0.7, 0, 0.4, 1 };
    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1,};


    GLfloat ambient_coeffs[] = { 1, 1, 0.9, 1 };
    GLfloat diffuse_coeffs[] = { 0.7, 0, 0.4, 1 };
    GLfloat specular_coeffs[] = { 1, 1, 0.9, 0 };

    GLfloat shininess = 50;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glEnable(GL_COLOR_MATERIAL);
}
