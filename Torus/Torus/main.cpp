#include <GL/freeglut.h>
#include <GL/GL.h>



void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glutWireTorus(0.5, 3.0, 15, 40);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0, 0, 0); glVertex3f(10,0,0);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0, 0, 0); glVertex3f(0,10,0);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(0, 0, 0); glVertex3f(0,0,10);
	glEnd();
	glFlush();

}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(280,1,4,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4,6,5,0,0,0,0,1,0);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(840,420);
	glutCreateWindow("Torus");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;

}