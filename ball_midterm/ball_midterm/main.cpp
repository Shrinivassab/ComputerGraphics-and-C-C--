#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>
#include <windows.h>

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
#define PI 3.14
using namespace std;

float ballx, bally, balldirx, balldiry;

void initgame()
{
	ballx = 470;
	bally = 300;
	balldirx = 4;
	balldiry = 4;
}


void menu(int num){
	if (num == 0){
		glutDestroyWindow(window);
		exit(0);
	}
	else{
		value = num;
	}
	glutPostRedisplay();
}
void createMenu(void){
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("45 Degree", 2);
	glutAddMenuEntry("135 Degree", 3);
	glutAddMenuEntry("225 Degree", 4);
	glutAddMenuEntry("315 Degree", 5);
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Stop", 1);
	glutAddSubMenu("Billiard Ball Motion", submenu_id);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void moveball_315()
{
	ballx = ballx + balldirx;

	//check if the ball hit the wall
	if (ballx + 5 > 850 || ballx - 5 < 80)
	{
		balldirx = -balldirx;
	}



	bally = bally + balldiry;
	if (bally + 5 > 500 || bally - 5 < 100)
	{
		balldiry = -balldiry;
	}

}

void moveball_225()
{
	ballx = ballx + balldirx;

	//check if the ball hit the wall
	if (ballx + 5 > 850 || ballx - 5 < 80)
	{
		balldirx = -balldirx;
	}

	bally = bally - balldiry;
	if (bally + 5 > 500 || bally - 5 < 100)
	{
		balldiry = -balldiry;
	}

}

void moveball_135()
{
	ballx = ballx - balldirx;

	//check if the ball hit the wall
	if (ballx + 5 > 850 || ballx - 5 < 80)
	{
		balldirx = -balldirx;
	}

	bally = bally + balldiry;
	if (bally + 5 > 500 || bally - 5 < 100)
	{
		balldiry = -balldiry;
	}

}
void moveball_45()
{
	ballx = ballx - balldirx;

	//check if the ball hit the wall
	if (ballx + 5 > 850 || ballx - 5 < 80)
	{
		balldirx = -balldirx;
	}

	bally = bally - balldiry;
	if (bally + 5 > 500 || bally - 5 < 100)
	{
		balldiry = -balldiry;
	}

}
void board()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(80, 100);
	glVertex2f(850, 100);
	glVertex2f(850, 500);
	glVertex2f(80, 500);
	glEnd();

}
void drawball()
{
	int Q = 13;
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(ballx + Q * cos(i * PI / 180), bally + Q * sin(i * PI / 180));

	}
	glEnd();

}

//This Function is called every 33 milli seconds beacause of the gluttimerFunc(33, update, 0);
void updategame(int value)
{
	glutTimerFunc(33, updategame, 0);//call update function after 33 milliseconds so it will be called 30 time a second because 1000 / 33 = 30

	//moveball_315();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	board();
	drawball();
	if (value == 1)
	{
		return;
	}

	else if (value == 2)
	{
		glPushMatrix();
		glutTimerFunc(33, updategame, 1);
		moveball_45();
		glPopMatrix();
	}
	else if (value == 3)
	{
		glPushMatrix();
		glutTimerFunc(33, updategame, 1);
		moveball_135();
		glPopMatrix();
	}
	else if (value == 4)
	{
		glPushMatrix();
		glutTimerFunc(33, updategame, 1);
		moveball_225();
		glPopMatrix();
	}
	else if (value == 5)
	{
		glPushMatrix();
		glutTimerFunc(33, updategame, 1);
		moveball_315();
		glPopMatrix();
	}
	
	glFlush();
	glutSwapBuffers();
}

void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 960, 600, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv)
{
	initgame();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 10);
	glutInitWindowSize(960, 600);
	window= glutCreateWindow("Billiards");
	createMenu();
	glClearColor(0.36 ,0.25 ,0.20, 0.0);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIgnoreKeyRepeat(1);
	//(KeyDownPress);
	//glutKeyboardUpFunc(KeyUpPress);
	glutIdleFunc(display);
	glutTimerFunc(33, updategame, 0); //call update function after 33 milliseconds
	//glutFullScreen();
	glutMainLoop();
	return ;
}