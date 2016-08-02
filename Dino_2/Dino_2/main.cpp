/*  drawfile.cpp
*  This program demonstrates the drawing of polylines stored in a file
*  The data file is "dino.dat"
*
*  Click the right button of the mouse to exit.
*/
#include <gl/freeglut.h>
//#include <X11/Xlib.h>
#include <fstream>
#include <math.h>

//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
#include <stdlib.h>
#include <stdio.h>

const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A, B, C, D;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);   // set black background color
	glColor3f(0.0f, 0.0f, 0.0f);       // set the drawing color
	glPointSize(2.0);                  // set dot size 2 x 2
	glMatrixMode(GL_PROJECTION);       // set "camera shape"
	glLoadIdentity();                    // clear the matrix
	// viewing transformation 
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	// set the Worlk Window
	A = screenWidth / 4.0;   //set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;
}

void myDisplay(void)
{
	int i, j;
	const char InputFileName[] = "dino.dat";

	fstream inStream;
	inStream.open(InputFileName, ios::in); // open the file
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);    // clear the screen
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;             // read the number of polylines
	for (j = 0; j < numpolys; j++)
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);        // draw the next polyline
		for (i = 0; i < numLines; i++)
		{
			inStream >> x >> y;    // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();                       // send all out to display
	inStream.close();
}

void myMouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			exit(-1);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);                            // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     // set display mode
	glutInitWindowSize(screenWidth, screenHeight);   // set screen window size
	glutInitWindowPosition(100, 150);       // set window position on screen
	glutCreateWindow(argv[0]);              // open the screen window
	myInit();
	glutDisplayFunc(myDisplay);              // register redraw function
	glutMouseFunc(myMouse);                  // register myMouse function
	glutMainLoop();                          // go into a perpetual loop
	return 0;
}