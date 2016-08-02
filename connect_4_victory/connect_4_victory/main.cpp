#include <gl/freeglut.h>
#include <string.h>

int square, window;

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24
};
//char defaultMessage[] = "GLUT means OpenGL.";
//char *message = defaultMessage;
void init()
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	//clear
	glClear(GL_COLOR_BUFFER_BIT);
	//Define a orthographic 2D matrix
	gluOrtho2D(0.0, 960.0, 0.0, 640.0);
}

void
output(int x, int y, char *string)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void rules()
{

	glColor3f(1.0, 0.3, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(375, 300);
	glVertex2f(575, 300);
	glVertex2f(575, 250);
	glVertex2f(375, 250);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(375, 300);
	glVertex2f(365, 290);
	glVertex2f(365, 240);
	glVertex2f(375, 250);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(375, 250);
	glVertex2f(365, 240);
	glVertex2f(565, 240);
	glVertex2f(575, 250);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	//output(5, 600, " (*)Connect Four (also known as Captain's Mistress, Four Up, Plot Four, Find Four,");
	//output(35, 550, " Fourplay, Four in a Row and Four in a Line) is a two-player connection game in which");
	//output(40, 500, "the players first choose a color and then take turns dropping colored discs from the top");
	//output(43, 450, "into a seven-column, six-row vertically suspended grid.");
	output(250, 400, "(***) CONGRATULATION YOU WON(***) ");
	//output(0, 350, "(*)The objective of the game is to connect four of one's own discs of the same color next ");
	//output(35, 300, "to each other vertically, horizontally, or diagonally.");
	//output(0, 250, "(*) Connect Four is a strongly solved game.");
	//output(0, 200, "(*)The first player can always win by playing the right moves.");
	output(400, 270, "PLAY AGAIN");
	glPopMatrix();



	glFlush();
	glutSwapBuffers();

}

void display()
{
	//glColor3f(1.0,0.5,0.5);
	//button();

	glFlush();

}
void keypressed(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON&& state == GLUT_UP)
	{
		{if (x >= 250 && x <= 750)
			if (y >= 320 && y <= 400)
			{
				glPushMatrix();
				glutIdleFunc(rules);
				glPopMatrix();

			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (x >= 750)
		{
			glutIdleFunc(display);
		}
	}


}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 10);
	glutInitWindowSize(960, 640);
	glutCreateWindow("Connect 4");
	init();
	glutDisplayFunc(rules);
	glutMouseFunc(keypressed);
	glutMainLoop();
	//return 0;
}
