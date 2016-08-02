#include <stdio.h>
#include<iostream>
#include<conio.h>
#include <stdarg.h>
#include <math.h>
//#include <GL/glut.h>
#include <GL/freeglut.h>
//#include <GL/freeglut_ext.h>
// Function Prototypes

void display();
void Keys();
void mouse();
void MouseWheel();

// Global Variables

double rotate_y = 0;
double rotate_x = 0;
double zoom = 0.5;

// display() Callback function

void display()
{

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Other Transformations
	//glTranslatef( 0.3, 0.0, 0.0 );      
	//glRotatef( 180, 0.0, 1.0, 0.0 );    

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	//Zoom in and out according to mouse wheel movement
	glScalef(zoom, zoom, 1.0f);

	// Other Transformations
	//glScalef( 1.5, 1.5, 0.0 );          // Not included

	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5, -0.5, -0.5);      // P1 is red
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5, 0.5, -0.5);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5, 0.5, -0.5);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, -0.5);      // P4 is purple

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();

}

//Callback Function

void Keys(int key, int x, int y)
{

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 10;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 10;

	else if (key == GLUT_KEY_UP)
		rotate_x += 10;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 10;

	//  Request display update
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
	//Right arrow - increase rotation by 5 degree
	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
	{
		rotate_y += 10;
	}
	//Left arrow - decrease rotation by 5 degree
	else if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		rotate_y -= 10;
	}
	/*else if(state == GLUT_DOWN && button == 3)
	{
	rotate_x += 5;
	}
	else if(state == GLUT_DOWN && button == 4)
	{
	rotate_x -= 5;
	}*/

	glutPostRedisplay();

}

/*void MouseWheel(int wheel, int direction, int x, int y)
{
wheel=0;
if (direction==-1)
{
rotate_x -= 10;
}
else if (direction==+1)
{
rotate_x += 10;
}

glutPostRedisplay();

}*/

void MouseWheel(int wheel, int direction, int x, int y)
{
	wheel = 0;
	if (direction == -1)
	{
		zoom -= 0.5;

	}
	else if (direction == +1)
	{
		zoom += 0.5;
	}

	glutPostRedisplay();

}

/*void reshape(GLsizei width, GLsizei height)
{
if (height == 0)
height = 1;                // To prevent divide by 0
GLfloat aspect = (GLfloat)width / (GLfloat)height;

// Set the viewport to cover the new window
glViewport(0, 0, width, height);

// Set the aspect ratio of the clipping volume to match the viewport
glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
glLoadIdentity();             // Reset
// Enable perspective projection with fovy, aspect, zNear and zFar
gluPerspective(50.0f, aspect, 0.1f, 100.0f);
}*/

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0, GLfloat(w) / GLfloat(h), 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

}
// main() function

int main(int argc, char* argv[])
{

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Set the width and height of the window 
	glutInitWindowSize(500, 500);

	// Set the position of the window 
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("Cube");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	//glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(Keys);
	glutMouseFunc(mouse);
	glutMouseWheelFunc(MouseWheel);

	//Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

}