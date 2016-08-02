#include <math.h>
#include <GL/glut.h>
//used for glut init - don't really do anything!
int argc = 1;
char *argv = "";
//float speed = 1.0;
#define SCREENWIDTH 640
#define SCREENHEIGHT 480
//structure for vectors
typedef struct
{
	GLfloat x, y;
	
	void normalise()
	{
		float length = sqrt(pow(x, 2) + pow(y, 2));
		x = x / length;
		y = y / length;


	}
} vector;

//structure for animated objects
typedef struct
{
	float x, y;
	vector velocity;
	GLfloat speed;

} animObject;

//create a cat, rat {x, y, velocity, speed}
animObject cat = { 100, 100, 0.0, 1.0, 0.05 };
animObject rat = { 500, 400, 0.0, 1.0, 0 };
//cat’s velocity
vector v;
float R; //aspect ratio of the world window

void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
	//reset aspect ratio
	R = fabs((right - left) / (top - bottom));
}

/*double turnAngle(vector v1, vector v2)
{
	double angle = 0;
	if (cat.velocity.x*v.x + cat.velocity.y*v.y > 0.1)
	{
		double angle = acos(cat.velocity.x*v.x + cat.velocity.y*v.y) * 180 / 3.14;
		/*if ((v1.x*v2.y - v1.y*v2.x) < 0)
			return -angle;
		else if ((v1.x*v2.y - v1.y*v2.x) > 0)
			return angle; 

		
	}
	
	return angle;
} */

double turnAngle(vector v1, vector v2)
{
	double angle = acos(cat.velocity.x*v.x + cat.velocity.y*v.y)
		* 180 / 3.14;  //convert to degrees

	//if z of cross product is negative
	if ((v1.x*v2.y - v1.y*v2.x) < 0)
		return -angle;
	//if z of cross product is positive
	else  if ((v1.x*v2.y - v1.y*v2.x) > 0)
		return angle;

	//if z is 0 then no turn angle
	return 0;
}
void setViewport(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	glViewport((int)left, (int)bottom,
		(int)(right - left),
		(int)(top - bottom));
}
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);
	setWindow(0, 640, 0, 480);
	setViewport(0, 640, 0, 480);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	
	GLfloat speed = 0.001;

	v.x = rat.x - cat.x;
	v.y = rat.y - cat.y;
	v.normalise();
	cat.velocity.normalise();
	cat.x += (v.x );
	cat.y += (v.y );
	//cat.x += v.x * speed;
	//cat.y += v.y * speed;
	
	//
	//cat.y += v.y;
	
	

	//draw rat
	glColor3f(1.0, 0.5, 0.5); //pink
	glPushMatrix();
	glRecti(rat.x, rat.y, rat.x + 10, rat.y + 10);
	glPopMatrix();
	//draw cat
	glColor3f(0.8, 0.5, 0.2); //brown
	glPushMatrix();
	glTranslated(cat.x, cat.y, 0);
	glRotated(turnAngle(cat.velocity, v), 0, 0, 1);
	glTranslated(-cat.x, -cat.y, 0);
	//head
	glRecti(cat.x + 8, cat.y + 40, cat.x + 32, cat.y + 60);
	//ears
	glBegin(GL_LINE_STRIP);
	glVertex2i(cat.x + 8, cat.y + 60);
	glVertex2i(cat.x + 10, cat.y + 70);
	glVertex2i(cat.x + 20, cat.y + 60);
	glVertex2i(cat.x + 25, cat.y + 70);
	glVertex2i(cat.x + 32, cat.y + 60);
	glEnd();
	//body
	glRecti(cat.x, cat.y, cat.x + 40, cat.y + 40);
	//tail
	glBegin(GL_LINE_STRIP);
	glVertex2i(cat.x + 20, cat.y);
	glVertex2i(cat.x + 22, cat.y - 10);
	glVertex2i(cat.x + 15, cat.y - 30);
	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void myMouse(int button, int state, int x, int y)
{
	//if left button clicked move the rat
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		rat.x = x;
		rat.y = SCREENHEIGHT - y;
	}
}

void myReshape(GLsizei W, GLsizei H)
{
	if (R > W / H) //use global window aspect ratio
		setViewport(0, W, 0, W / R);
	else
		setViewport(0, H*R, 0, H);
}
void myIdle()
{
	glutPostRedisplay();
}
int main()
{
	glutInit(&argc, &argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Mouse Chase");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	myInit();
	glutMouseFunc(myMouse);
	glutMainLoop();
	return 1;
}