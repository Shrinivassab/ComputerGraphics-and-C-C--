#include <GL/freeglut.h>
#include <GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE);
	//Line where the tetrahedron will sit
	for (GLfloat i = -2.5; i <= 2.5; i += 2.5)
	{
		glVertex3f(i, 0, 2.5);
		glVertex3f(i, 0, -2.5);
		glVertex3f(2.5, 0, i);
		glVertex3f(-2.5, 0, i);
	}
	glEnd();
	//Draw a tetrahedron
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
	glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
	glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0.1,0.38,0.88,1);
	glClear3f(1.0,1.0,1.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-3);
	glRotatef(50,1,0,0);
	glRotatef(70,0,1,0);
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(80,80);
	glutInitWindowSize(800,480);
	glutCreateWindow("Tetrahedron");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}

