/*
 *  Function to add materials to objects in the scene
 */

#include <GL/glut.h>

/* add the material specified by the parameters */

void addMaterial(GLfloat ambr, GLfloat ambg, GLfloat ambb,
   GLfloat difr, GLfloat difg, GLfloat difb,
   GLfloat specr, GLfloat specg, GLfloat specb, GLfloat shine)
{
   GLfloat mat[4];

   glPushMatrix();
	   mat[0] = ambr; mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0;
	   glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	   mat[0] = difr; mat[1] = difg; mat[2] = difb;
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	   mat[0] = specr; mat[1] = specg; mat[2] = specb;
	   glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	   glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
   glPopMatrix();
}