/*
 *  Functions to create objects in the scene
 */

#include "material.h"

/*~~~~~~~~~~~~~~~~~~~~ wall ~~~~~~~~~~~~~~~~~~~~*/

void wall (double thickness)
{
 //draw thin wall waith top = xz-plane, corner at origin
	glPushMatrix();
		glTranslatef (0.5, 0.5*thickness, 0.5);
		glScalef(1.0, thickness, 1.0);
		glutSolidCube(1.0);
	glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ table leg ~~~~~~~~~~~~~~~~~~~~*/

void tableleg(double thick, double len)
{
   	glPushMatrix();
		glTranslatef (0, len/2, 0);
		glScalef(thick, len, thick);
		glutSolidCube(1.0);
    glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ table ~~~~~~~~~~~~~~~~~~~~*/

void table (double topWid, double topThick, double legThick, double legLen)
{
// draw the table top and four legs
	double dist;
    glPushMatrix();
		glTranslatef (0, legLen, 0);
		addMaterial(0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2);
		glScalef(topWid, topThick, topWid);
		glutSolidCube(1.0);
	glPopMatrix();
	dist = 0.95 * topWid/2.0 - legThick/2.0;

	glPushMatrix();    
		glTranslatef (dist, 0, dist);
		tableleg(legThick, legLen);

		glTranslatef (0, 0, -2*dist);
		tableleg(legThick, legLen);

		glTranslatef (-2*dist, 0, 2*dist);
		tableleg(legThick, legLen);

		glTranslatef (0, 0, -2*dist);
		tableleg(legThick, legLen);

    glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ chair ~~~~~~~~~~~~~~~~~~~~*/

void chair (double topWid, double topThick, double legThick, double legLen)
{
// draw the chair seat,four legs, and back rest
	double dist;
	glPushMatrix();
		glTranslatef(0.4, 0, 0.8); //chair location
		addMaterial(0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2);
		glPushMatrix();
			glTranslatef (0, legLen, 0);
			glScalef(topWid, topThick, topWid);
			glutSolidCube(1.0);
		glPopMatrix();
		dist = 0.95 * topWid/2.0 - legThick/2.0;

		glPushMatrix();    
			glTranslatef (dist, 0, dist);
			tableleg(legThick, 2*legLen);

			glTranslatef (0, 0, -2*dist);
			tableleg(legThick, legLen);

			glTranslatef (-2*dist, 0, 2*dist);
			tableleg(legThick, 2*legLen);

			glPushMatrix();
				glTranslatef(.085, 2*legLen, 0);
				glScalef(topWid + .025, topWid/2.0, topThick);
				glutSolidCube(1.0);
			glPopMatrix();

			glTranslatef (0, 0, -2*dist);
			tableleg(legThick, legLen);

		glPopMatrix();
	glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ teapot ~~~~~~~~~~~~~~~~~~~~*/

void drawTeapot(GLdouble size)
{
	glPushMatrix();
		glTranslatef (0.4, 0.4, 0.6);
		addMaterial(0.329412, 0.223529, 0.027451,
		  0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843,
		  0.21794872);
		glutSolidTeapot(size);
	glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ sphere ~~~~~~~~~~~~~~~~~~~~*/

void drawSphere(GLdouble radius, GLint longitude, GLint latitude)
{
	glPushMatrix();
		glTranslatef (0.9, 0.15, 0.6);
		addMaterial(0.0, 0.05, 0.05, 0.4, 0.5, 0.5, 0.04, 0.7, 0.7, .078125);
		glutSolidSphere(radius, longitude, latitude);
	glPopMatrix();
}

/*~~~~~~~~~~~~~~~~~~~~ lamp ~~~~~~~~~~~~~~~~~~~~*/

void lamp()
{
	GLUquadric *quad = gluNewQuadric();
	glPushMatrix();
		glTranslatef(0.89, 0.025, 0.1);
		addMaterial(0.05375, 0.05, 0.06625, 0.18275, 0.17, 0.22525, 0.332741, 0.328634, 0.346435, 0.3);
		glPushMatrix();
			glScalef(0.2, 0.025, 0.2);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.3, 0.0); 
			glScalef(0.025, 0.6, 0.025);
			glutSolidCube(1.0);
		glPopMatrix();
		glTranslatef(0.0, 0.6, 0.0);
		addMaterial(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(quad, 0.15, 0.05, 0.3,	16, 16);
	glPopMatrix();
}