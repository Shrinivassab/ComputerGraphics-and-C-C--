#include <windows.h> // use proper includes for your system\

#include <math.h>

#include <GL/glut.h>
#include <fstream>
using namespace std;
//#include "canvas/"
#define PI 3.14



const int screenWidth = 840; // width of screen window in pixels

const int screenHeight = 680; // height of screen window in pixels
GLdouble A, B, C, D; // values used for scaling and shifting

float offset = 0.0f;

void setWindow(float left, float right, float bottom, float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void setViewport(float left, float right, float bottom, float top)
{
	glViewport(left, bottom, right - left, top - bottom);
}


void drawPolyLineFile(char * fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::in); // open the file
	if (inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	GLint numpolys, numLines, x, y;
	inStream >> numpolys; // read the number of polylines
	for (int j = 0; j < numpolys; j++) // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP); // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y; // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // background color is white
	glColor3f(0.0, 1.0, 0.0); // drawing color is black
	glPointSize(10.0); // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); // set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	A = screenWidth / 4.0; // set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void) // plot the sinc function, using world coordinates
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 0, 480.0); // set a fixed window


	//	FILL OUT THIS PORTION FOR WINDOW A
	//	FILL OUT THIS PORTION FOR WINDOW A
	//	FILL OUT THIS PORTION FOR WINDOW A

	float x, y;
	int length = 80;
	float angle = 0.0;
	float angle_stepsize = 0.5;

	// go through all angles from 0 to 2 * PI radians
	while (angle < 2 * 3.14)
	{
		// calculate x, y from a vector with known length and angle
		x = 650 + (length + 20) * cos(angle + offset);
		y = 520 + (length + 20) * sin(angle + offset);

		glViewport(x, y, 60, 50);
		//glRotatef(1,1,0,0);
		glPushMatrix();
		//glTranslatef(x, y, 0.0); // 3. Translate to the object's position.
		//glRotatef(50, 0.0, 0.0, 1.0); // 2. Rotate the object.
		//glTranslatef(-x, -y, 0.0); // 1. Translate to the origin.
		drawPolyLineFile("Brontoi.dat"); // draw it again
		angle += 0.5235987;
		// Draw the object
		glPopMatrix();
		//glRotatef(0, 0, 1, 0);
		//glRotatef(0, 0, 0, 1);

	}
	int r_x, r_y;
	int r_length = 80;
	float r_angle = 0.0;
	float r_angle_stepsize = 0.5;
	float rotate_angle = 0.0;
	

	// go through all angles from 0 to 2 * PI radians
	while (r_angle < 2 * 3.14)
	{
		// calculate x, y from a vector with known length and angle
		r_x = 250 + (length + 20) * cos(r_angle + offset);
		r_y = 520 + (length + 20) * sin(r_angle + offset);


		//glRotatef(1,1,0,0);
		//
		glPushMatrix();
		glTranslatef(300, 250, 0.0); // 3. Translate to the object's position.
		//glPushMatrix();
		glRotatef(-90 + rotate_angle + ((offset * 180) / PI), 0.0, 0.0, 1.0); // 2. Rotate the object.
		glViewport(r_x * 1, r_y * 1, 70, 50);
		glTranslatef(-250, -250, 0.0); // 1. Translate to the origin.
		drawPolyLineFile("Brontoi.dat"); // draw it again
		r_angle += 0.5235987;
		rotate_angle = rotate_angle + 30;

		// Draw the object
		glPopMatrix();



		//rotx = rotx + 30.0;
	}
	
	float r_x1, r_y1;
	//int r_length1 = 80;
	float r_angle1 = 0.0;
	float r_angle_stepsize1 = 0.5;
	float rotate_angle1 = 0.0;
	float rotx1 = 30.0;

	// go through all angles from 0 to 2 * PI radians
	while (r_angle1 < 2 * PI)
	{
		// calculate x, y from a vector with known length and angle
		r_x1 = 250 + (length + 20) * cos(r_angle1 + offset);
		r_y1 = 220 + (length + 20) * sin(r_angle1 + offset);


		//glRotatef(1,1,0,0);
		//
		glPushMatrix();
		glTranslatef(250, 250, 0.0); // 3. Translate to the object's position.
		//glPushMatrix();
		glRotatef(+90 + rotate_angle1 + ((offset * 180) / PI), 0.0, 0.0, 1.0); // 2. Rotate the object.
		glViewport(r_x1, r_y1, 60, 50);
		glTranslatef(-250, -250, 0.0); // 1. Translate to the origin.
		drawPolyLineFile("Brontoi.dat"); // draw it again
		r_angle1 += 0.5235987;
		rotate_angle1 = rotate_angle1 + 30;

		// Draw the object
		glPopMatrix();

		//rotx = rotx + 30.0;
	}

	float r_x2, r_y2;
	//int r_length1 = 80;
	float r_angle2 = 0.0;
	float r_angle_stepsize2 = 0.5;
	float rotate_angle2 = 0.0;
	//float rotx1 = 30.0;

	// go through all angles from 0 to 2 * PI radians
	while (r_angle2 < 2 * PI)
	{
		// calculate x, y from a vector with known length and angle
		r_x2 = 650 + (length + 20) * cos(r_angle2 + offset);
		r_y2 = 220 + (length + 20) * sin(r_angle2 + offset);


		//glRotatef(1,1,0,0);
		//
		glPushMatrix();
		glTranslatef(250, 250, 0.0); // 3. Translate to the object's position.
		//glPushMatrix();
		glRotatef(+180, 0.0, 0.0, 1.0); // 2. Rotate the object.
		glViewport(r_x2, r_y2, 60, 50);
		glTranslatef(-250, -250, 0.0); // 1. Translate to the origin.
		drawPolyLineFile("Brontoi.dat"); // draw it again
		r_angle2 += 0.5235987;
		rotate_angle2 = rotate_angle2 + 30;

		// Draw the object
		glPopMatrix();

		//rotx = rotx + 30.0;
	} 



}

void update(int value)
{

	if (offset >= .52359)
	{
		offset = 0.0;
	}
	offset = offset + 0.05235987755;
	glutSwapBuffers();
	glutPostRedisplay();
	printf("%f", offset);
	glutTimerFunc(1000, update, 0);

}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(120, 10); // set window position on screen
	glutCreateWindow("Tiling"); // open the screen window
	glutTimerFunc(1000, update, 0);

	glutDisplayFunc(myDisplay); // register redraw function	
	myInit();
	glutMainLoop(); // go into a perpetual loop

}