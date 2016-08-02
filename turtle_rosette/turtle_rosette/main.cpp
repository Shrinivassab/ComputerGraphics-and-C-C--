#include <stdio.h>
#include <cstdlib>
#include <GL/freeglut.h>
#include <cmath>
using namespace std;
int screenWidth = 500;
int screenHeight = 500;


void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);				
	glColor3f(1.0, 0.5,0.0); 					
	glPointSize(3.0);							
	glViewport(0.0, 0.0, 500.0, 500.0);		
	//set up a world window to screen transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);

}

void rosette()
{
	double angle;						
	double angleInc = 3 * 3.14159265/ 6.0;	
	double inc = 5.0 / 100;		
	double radius = 5.0/ 100.0;			
		
	glClear(GL_COLOR_BUFFER_BIT);

	for (int j = 0; j <= 100; j++)
	{
		angle = j* (3.14159265 / 45.0);
		glBegin(GL_LINE_STRIP);
		for (int k = 0; k <= 100; k++)
		{
			angle += angleInc;
			glVertex2d(radius * cos(angle), radius *sin(angle));

		}
		glEnd();
		radius =radius + inc;
		
	}
	
	glutSwapBuffers();

	glFlush();
}

float h = 1.2, w = 1.2;

void zoom(unsigned char key, int x, int y)
{
	float cx = 0.0, cy = 0.0;	
	int NumFrames = 10;	
	printf("%d", key);
	if (key == 27)
		exit(0);
	if (key == 114)
	{
		w -= 0.1;
		h -= 0.1;
		
			gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
			rosette();
	}
	else if (key == 101)
	{	
		w += 0.1;
		h += 0.1;
		
			gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
			rosette();
	
	}
	else if (key == 56)
	{
		glTranslatef(0.0,1,0.0);
		//gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
		rosette();
	}
	else if (key == 52)
	{
		glTranslatef(-1, 0.0, 0.0);
		//gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
		rosette();
	}
	else if (key == 54)
	{
		glTranslatef(1, 0.0, 0.0);
		//gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
		rosette();
	}
	else if (key == 53)
	{
		glTranslatef(0.0, -1, 0.0);
		//gluOrtho2D(cx - w, cx + w, cy - h, cy + h);
		rosette();
	}

}


int main(int argc, char** argv)
{

	//initialize the OpenGL Utility Toolkit
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	//specify the window position 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("rosette_zoom");
	glutDisplayFunc(rosette);
	glutKeyboardFunc(zoom);
	myinit();
	glutMainLoop();
	return 0;
}