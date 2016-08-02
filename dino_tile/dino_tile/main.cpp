#include <windows.h> // use proper includes for your system\

#include <math.h>

#include <GL/glut.h>
#include <fstream>
using namespace std;
//#include "canvas/"


const int screenWidth = 640; // width of screen window in pixels

const int screenHeight = 480; // height of screen window in pixels
GLdouble A, B, C, D; // values used for scaling and shifting


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
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 0, 480.0); // set a fixed window


	//	FILL OUT THIS PORTION FOR WINDOW A
	//	FILL OUT THIS PORTION FOR WINDOW A
	//	FILL OUT THIS PORTION FOR WINDOW A


	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if ((i) % 1 == 0) // if (i + j) is even
				setWindow(0.0, 640.0, 0.0, 480.0); // right side up window
			else
				setWindow(0.0, 640.0, 480.0, 0.0); // upside down window
			glViewport(i * 64, j * 44, 64, 44); // set the next viewport
			drawPolyLineFile("Brontoi.dat"); // draw it again
		}


	glEnd();
	glFlush();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Tiling"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}