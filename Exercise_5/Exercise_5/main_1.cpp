
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "vase.h"
#include "sceneObjects.h"


bool fogOn = false;
bool lightOn = true;


void display(void)
{
	double winHt = 1.0;

	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat mat_shininess[] = { 50.0 };

	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };


	GLfloat diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse1[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat diffuse2[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat position[] = { 2.0, 6.0, 3.0, 0.0 };
	GLfloat position1[] = { 0.9, 0.8, 0.15, 1.0 };
	GLfloat position2[] = { 1.0, 0.8, 0.2, 1.0 };



	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);



	glClearColor(0.1, 0.1, 0.1, 0.0);


	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT2, GL_POSITION, position2);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2.0, 0, 0.25, 0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	lamp();

	addMaterial(0.1745, 0.01175, 0.01175, 0.61424, 0.04136, 0.04136, 0.727811, 0.626959, 0.626959, 0.6);
	glTranslatef(-1,0.0,0);
	vase();

	glFlush();
	glutSwapBuffers();
}

/* Menu for turning fog and light on and off accessible by right clicking */

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.1, 0.1, 0.1, 0.0);

	
	//glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}