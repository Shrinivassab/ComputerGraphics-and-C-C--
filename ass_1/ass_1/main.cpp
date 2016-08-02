#include <gl/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include "car_main.cpp""
#define PI 3.14

int a, b;
int Tree_base, Tree_leaf;
int apt;
int House_2, House_1;
float rtri = -1.7;

void init()
{
	// This Will Clear The Background Color To Black
	//glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 800, 0, 600.0);
	glClearDepth(1.0);                // Enables Clearing Of The Depth Buffer

}

void resize(int Width, int Height)
{
	if (Height == 0)                // Prevent A Divide By Zero If The Window Is Too Small
		Height = 1;

	glViewport(0, 0, Width, Height);        // Reset The Current Viewport And Perspective Transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (GLfloat)Width / (GLfloat)Height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius)
{
	GLint i;
	GLdouble theta;
	GLint circle_points = 800;
	//int rad = 30;
	glBegin(GL_POLYGON);
	for (i = 0; i<circle_points; i++)
	{
		theta = 2 * PI*i / circle_points;

		glVertex2f(centerx + radius	*cos(theta), centery + radius*sin(theta));
	}
	glEnd();

}

void cloud(float k, int m)
{

	glColor3f(1.0, 1.0, 1.0);
	MyCircle2f(95 + m, 555, k * 40);
	MyCircle2f(45 + m, 540, k * 30);
	MyCircle2f(75 + m, 515, k * 25);
	MyCircle2f(95 + m, 500, k * 10);
	MyCircle2f(120 + m, 515, k * 25);
	MyCircle2f(145 + m, 545, k * 25);

}

void sun()
{
	float r = 50;
	glColor3f(1.0, 1.0, 0);
	glTranslatef(1.7, 1.7, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(r * cos(i * PI / 180), r * sin(i * PI / 180));

	}
	glEnd();
	glTranslatef(-1.7, -1.7, 0.0);


}
void apartment()
{
	//Apartment side wall

	apt = glGenLists(1);
	glNewList(apt, GL_COMPILE);

	//glTranslatef(1.0,0.5,0.0);

	glColor3f(0.53, 0.12, 0.47);
	glBegin(GL_POLYGON);
	glVertex2i(50, 400);
	glVertex2i(120, 400);
	glVertex2i(120, 250);
	glVertex2i(50, 250);
	glEnd();

	glColor3f(1, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(120, 400);
	glVertex2i(155, 430);
	glVertex2i(155, 280);
	glVertex2i(120, 250);
	glEnd();

	//Apartment roof

	glColor3f(0.73, 0.16, 0.96);
	glBegin(GL_POLYGON);
	glVertex2i(50, 400);
	glVertex2i(120, 400);
	glVertex2i(155, 430);
	glVertex2i(85, 430);
	glEnd();


	//Road for apartment
	glColor3f(0.184314, 0.309804, 0.309804);
	glBegin(GL_POLYGON);
	glVertex2i(75, 250);
	glVertex2i(93, 250);
	glVertex2i(43, 180);
	glVertex2i(25, 180);
	glEnd();




	//Aptartment door
	glColor3f(0.94, 0.81, 0.99);
	glBegin(GL_POLYGON);
	glVertex2i(75, 290);
	glVertex2i(93, 290);
	glVertex2i(93, 250);
	glVertex2i(75, 250);
	glEnd();

	//Apartment lock
	glColor3f(0.53, 0.12, 0.47);
	glBegin(GL_POLYGON);
	glVertex2f(84, 270);
	glVertex2f(89, 280);
	glVertex2f(89, 270);
	glVertex2f(84, 280);
	glEnd();

	glEndList();
	glCallList(apt);
}

void lawn()
{
	//lawn_1

	glColor3f(0.0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 250);
	glVertex2i(265, 250);
	glVertex2i(220, 180);
	glVertex2i(0, 180);
	glEnd();
	glColor3f(0.184314, 0.309804, 0.309804);
	glBegin(GL_POLYGON);
	glVertex2i(265, 250);
	glVertex2i(285, 250);
	glVertex2i(245, 180);
	glVertex2i(220, 180);
	glEnd();
	//lawn_2

	glColor3f(0.0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2i(285, 250);
	glVertex2i(540, 250);
	glVertex2i(510, 180);
	glVertex2i(245, 180);
	glEnd();




	//lawn_3

	glColor3f(0.0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2i(560, 250);
	glVertex2i(800, 250);
	glVertex2i(800, 180);
	glVertex2i(535, 180);
	glEnd();

	glColor3f(0.184314, 0.309804, 0.309804);
	glBegin(GL_POLYGON);
	glVertex2i(540, 250);
	glVertex2i(560, 250);
	glVertex2i(535, 180);
	glVertex2i(510, 180);
	glEnd();
	//big lawn

	glColor3f(0.0, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 100);
	glVertex2i(800, 100);
	glVertex2i(800, 0);
	glVertex2i(0, 0);
	glEnd();

	glColor3f(0.184314, 0.309804, 0.309804);
	glBegin(GL_POLYGON);
	glVertex2i(0, 180);
	glVertex2i(800, 180);
	glVertex2i(800, 100);
	glVertex2i(0, 100);
	glEnd();

	//Road Lines
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2);
	
	glBegin(GL_LINES);
	glVertex2i(50, 140);
	glVertex2i(100, 140);
	glVertex2i(250, 140);
	glVertex2i(300, 140);
	glVertex2i(450, 140);
	glVertex2i(500, 140);
	glVertex2i(650, 140);
	glVertex2i(700, 140);
	glEnd();
	


}
void house_1()
{
	//Roof top
	House_1 = glGenLists(1);
	glNewList(House_1, GL_COMPILE);
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_TRIANGLES);
	glVertex2i(275, 350);
	glVertex2i(250, 300);
	glVertex2i(300, 300);
	glEnd();

	//Door Wall

	glColor3f(0.825, .649, 0.524);

	glBegin(GL_POLYGON);
	glVertex2i(250, 300);
	glVertex2i(300, 300);
	glVertex2i(300, 250);
	glVertex2i(250, 250);
	glEnd();


	//Polygonal Roof
	glColor3f(0.957059, 0.174706, 0.184706);
	glBegin(GL_POLYGON);
	glVertex2i(275, 350);
	glVertex2i(325, 350);
	glVertex2i(350, 300);
	glVertex2i(300, 300);
	glEnd();

	// Window wall
	//glColor3f(0.825, .649, 0.524);
	glColor3f(0.65, .049, 0.24);
	glBegin(GL_POLYGON);
	glVertex2i(300, 300);
	glVertex2i(350, 300);
	glVertex2i(350, 250);
	glVertex2i(300, 250);
	glEnd();


	//door

	glColor3f(0.35, 0.16, 0.14);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glVertex2i(265, 280);
	glVertex2i(285, 280);
	glVertex2i(285, 250);
	glVertex2i(265, 250);
	glEnd();

	//door lock
	glColor3f(0.647059, 0.164706, 0.164706);
	glBegin(GL_POLYGON);
	glVertex2i(270, 270);
	glVertex2i(275, 270);
	glVertex2i(275, 263);
	glVertex2i(270, 263);
	glEnd();

	//Window
	glColor3f(0.827059, 0.514706, 0.584706);
	glBegin(GL_POLYGON);
	glVertex2f(310, 260);
	glVertex2f(335, 260);
	glVertex2f(335, 285);
	glVertex2f(310, 285);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(100);
	glVertex2f(310, 272);
	glVertex2f(335, 272);
	glVertex2f(322, 260);
	glVertex2f(322, 285);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.35, 0.16, 0.14);

	glVertex2f(300, 250);
	glVertex2f(300, 300);
	glVertex2f(250, 250);
	glVertex2f(250, 300);
	glVertex2f(350, 250);
	glVertex2f(350, 300);
	glVertex2f(250, 300);
	glVertex2f(350, 300);

	glEnd();


	glEndList();
	glCallList(House_1);
}

void house_2()
{
	//2 house basement
	House_2 = glGenLists(1);
	glNewList(House_2, GL_COMPILE);
	glColor3f(0.825, .649, 0.524);
	glBegin(GL_POLYGON);
	glVertex2i(650, 320);
	glVertex2i(450, 320);
	glVertex2i(450, 250);
	glVertex2i(650, 250);
	glEnd();

	//2 house  top
	glColor3f(0.65, .049, 0.24);
	glBegin(GL_POLYGON);
	glVertex2i(650, 320);
	glVertex2i(450, 320);
	glVertex2i(500, 370);
	glVertex2i(600, 370);
	glEnd();

	//Door
	glColor3f(0.65, .049, 0.24);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glVertex2i(540, 280);
	glVertex2i(560, 280);
	glVertex2i(560, 250);
	glVertex2i(540, 250);
	glEnd();

	//Window
	glColor3f(0.65, .049, 0.24);
	glBegin(GL_POLYGON);
	glVertex2f(480, 270);
	glVertex2f(510, 270);
	glVertex2f(510, 295);
	glVertex2f(480, 295);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(100);
	glVertex2f(480, 282);
	glVertex2f(510, 282);
	glVertex2f(495, 295);
	glVertex2f(495, 270);
	glEnd();
	glColor3f(0.65, .049, 0.24);
	glBegin(GL_POLYGON);
	glVertex2f(600, 270);
	glVertex2f(630, 270);
	glVertex2f(630, 295);
	glVertex2f(600, 295);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(100);
	glVertex2f(600, 282);
	glVertex2f(630, 282);
	glVertex2f(615, 295);
	glVertex2f(615, 270);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0.65, .049, 0.24);;
	glVertex2f(450, 250);
	glVertex2f(450, 320);
	glVertex2f(530, 250);
	glVertex2f(530, 300);
	glVertex2f(530, 300);
	glVertex2f(540, 320);
	glVertex2f(570, 250);
	glVertex2f(570, 300);
	glVertex2f(570, 300);
	glVertex2f(560, 320);
	glVertex2f(650, 250);
	glVertex2f(650, 320);
	glEnd();

	glColor3f(0.825, .649, 0.524);
	glBegin(GL_POLYGON);
	glVertex2i(545, 270);
	glVertex2i(550, 270);
	glVertex2i(550, 260);
	glVertex2i(545, 260);
	glEnd();

	//Roof top line
	glColor3f(0.825, .649, 0.524);
	glLineStipple(2, 0x00FF);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	glVertex2f(460,330);
	glVertex2f(650,330);
	glEnd();
	//glDisable(GL_LINE_STIPPLE);
	//glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	glVertex2f(470, 340);
	glVertex2f(630, 340);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(480, 350);
	glVertex2f(620, 350);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(500, 360);
	glVertex2f(600, 360);
	glEnd();

	glDisable(GL_LINE_STIPPLE);





	glEndList();

	glCallList(House_2);

}

void tree_leaf(float a, float b, float radius)
{
	// radius = 17.0;
	//tree leaf
	Tree_leaf = glGenLists(1);
	glNewList(Tree_leaf, GL_COMPILE);
	glColor3f(0.0, 0.5, 0);
	glTranslatef(0.0 + a, 0.0 + b, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(radius * cos(i * PI / 180), radius * sin(i * PI / 180));

	}
	glEnd();
	glEndList();

	glCallList(Tree_leaf);
}
void tree_base(float a, float b)
{
	//tree base

	Tree_base = glGenLists(1);
	glNewList(Tree_base, GL_COMPILE);
	glColor3f(0.36, 0.25, 0.20);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2i(25 + a, 250 + b);
	glVertex2i(25 + a, 290 + b);
	glEnd();
	glEndList();

	glCallList(Tree_base);
}
void C_tree(int	a, int b)
{
	glColor3f(0, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(735 + a, 370 + b);
	glVertex2f(785 + a, 370 + b);
	glVertex2f(760 + a, 400 + b);
	glEnd();
}

void window(int a, int b)
{
	glColor3f(0.87, 0.58, 0.98);
	glBegin(GL_POLYGON);
	glVertex2f(475 + b, 275 + a);
	glVertex2f(500 + b, 275 + a);
	glVertex2f(500 + b, 300 + a);
	glVertex2f(475 + b, 300 + a);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(100);
	glVertex2f(475 + b, 288 + a);
	glVertex2f(500 + b, 288 + a);
	glVertex2f(488 + b, 275 + a);
	glVertex2f(488 + b, 300 + a);
	glEnd();
}

void line_stipple()
{
	glColor3f(0.825, .649, 0.524);
	glLineStipple(2, 0xAAAA);
	glLineWidth(10);
	glEnable(GL_LINE_STIPPLE);
	glVertex2f(0, 500);
	glVertex2f(500, 300);
	glEnd();
	glFlush();
}

void car()
{
	float r = 12;
	float R = 5;
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
	//glLoadIdentity();                // Reset The View

	//glTranslatef(x, y, z); 
	glTranslatef(rtri, -0.9, 1.0);        // Move Left 1.5 Units And Into The Screen 6.0  
	//glPushMatrix();

	glBegin(GL_POLYGON);                // start drawing a polygon

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(100, 100, 0.0);
	glVertex3f(150, 100, 0.0);
	glVertex3f(150, 145, 0.0);
	glVertex3f(140, 160, 0.0);
	glVertex3f(100, 175, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);

	glVertex2f(100, 100);
	glVertex2f(150, 100);
	glVertex2f(150, 100);
	glVertex2f(150, 145);
	glVertex2f(150, 145);
	glVertex2f(140, 160);
	glVertex2f(140, 160);
	glVertex2f(100, 175);
	glVertex2f(100, 175);
	glVertex2f(100, 100);
	glEnd();

	//front of truck
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(160, 100);
	glVertex2f(210, 100);
	glVertex2f(210, 110);
	glVertex2f(200, 125);
	glVertex2f(180, 140);
	glVertex2f(160, 140);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(160, 100);
	glVertex2f(210, 100);
	glVertex2f(210, 100);
	glVertex2f(210, 110);
	glVertex2f(210, 110);
	glVertex2f(200, 125);
	glVertex2f(200, 125);
	glVertex2f(180, 140);
	glVertex2f(180, 140);
	glVertex2f(160, 140);
	glVertex2f(160, 140);
	glVertex2f(160, 100);
	glEnd();
	//joining*/
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(150, 100);
	glVertex2f(160, 100);
	glVertex2f(160, 120);
	glVertex2f(150, 120);
	glEnd();
	//glass
	glColor3f(0.0, 0.498039, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(170, 122);
	glVertex2f(190, 122);
	glVertex2f(180, 134);
	glVertex2f(170, 134);
	glEnd();

	glColor3f(0.0, 0.498039, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(195, 122);
	glVertex2f(203, 122);
	glVertex2f(185, 136);
	glVertex2f(187, 136);
	glEnd();

	// lines for the front art of the truck
	//glEnable(GL_LINE_STIPPLE);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);
	//glLineStipple(1, 0x1C47);
	glBegin(GL_LINES);
	glVertex2f(100, 110);
	glVertex2f(150, 110);
	glVertex2f(160, 110);
	glVertex2f(210, 110);
	glVertex2f(167, 100);
	glVertex2f(167, 140);
	glVertex2f(195, 110);
	glVertex2f(195, 118);
	glVertex2f(195, 118);
	glVertex2f(180, 140);
	glEnd();
	//glDisable(GL_LINE_STIPPLE);

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(90, 105);
	glVertex2f(100, 105);
	glEnd();
	//smoke

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(85, 105);
	glEnd();
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(80, 105);
	glEnd();
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2f(73, 105);
	glEnd();




	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.3, 0.32, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(r * cos(i * PI / 180), r * sin(i * PI / 180));

	}
	glEnd();
	glTranslatef(0.17, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(r * cos(i * PI / 180), r * sin(i * PI / 180));

	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-0.17, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(R * cos(i * PI / 180), R * sin(i * PI / 180));

	}
	glEnd();
	glTranslatef(0.17, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= 360; i++) { // iterates through degrees



		glVertex2f(R * cos(i * PI / 180), R * sin(i * PI / 180));

	}
	glEnd();

	


	// we're done with the polygon (smooth color interpolation)
	//wheel();

	rtri = rtri + 0.0005;                    // Increase The Rotation Variable For The Triangle
	if (rtri > .4)
		rtri = -2;
	//glTranslatef(rtri, -0.9, 1.0);

	// Decrease The Rotation Variable For The Quad
	//glTranslatef(-x, -y, -z);
	// swap the buffers to display, since double buffering is used.
	glutSwapBuffers();
	glutPostRedisplay();
	//glPopMatrix();

}

void display()

{
	//glColor3f(1.0,1.0,1.0);
	glClearColor(0.196078, 0.85, 1.0, 0.0);
	//glClear(GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	sun();

	cloud(1, 30);
	cloud(1.1, 250);
	lawn();
	apartment();
	house_2();
	house_1();

	window(85, -385);
	window(40, -385);
	window(40, -420);
	window(85, -420);

	C_tree(0, -40);
	C_tree(0, -60);
	C_tree(0, -80);

	tree_base(0, 0);
	tree_base(180, 0);
	tree_base(380, 0);
	tree_base(670, 0);
	tree_base(735, 0);


	tree_leaf(0.06, 1, 17);
	tree_leaf(0.45, 0, 17);
	tree_leaf(0.5, 0, 17);
	tree_leaf(0.73, 0, 17);
	//line_stipple(); 

	//car();



	glFlush();

}
/* The main drawing function. */

/* The function called whenever a key is pressed. */
void keyPressed(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		glutIdleFunc(car);

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glutIdleFunc(NULL);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(120, 10);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Village");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(keyPressed);
	init();
	glutMainLoop();
	return 0;
}