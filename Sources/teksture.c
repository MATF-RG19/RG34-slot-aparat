#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#include "../Headers/teksture.h"

//---------------------------TEKSTURE--------------------------------------------
void teksture(GLuint* names){
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
}
