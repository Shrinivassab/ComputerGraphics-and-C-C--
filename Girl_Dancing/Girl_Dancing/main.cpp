#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>
#define PI 3.1415926535898
int spinning = 0, d = 1;
float angle = 0;
float power = 0;
double r = 1;
double g = 1;
double b = 0;

void spin()
{
	if (angle <= 0)
	{
		d = 1;
	}
	else if (angle >= 30)
	{
		d = 0;
	}
	if (d == 1)
	{
		angle += power;
	}
	if (d == 0)
	{
		angle -= power;
	}

	glutPostRedisplay();
}

void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius)
{
	GLint i;
	GLdouble theta;
	GLint circle_points = 900;
	glBegin(GL_POLYGON);
	for (i = 0; i<circle_points; i++)
	{
		theta = 2 * PI*i / circle_points;

		glVertex2f(centerx + radius*cos(theta), centery + radius*sin(theta));
	}
	glEnd();
}

void MyEclipse2f(GLfloat centerx, GLfloat centery, GLfloat rx, GLfloat ry)
{
	GLint i;
	GLdouble theta;
	GLint circle_points = 100;
	glBegin(GL_POLYGON);
	for (i = 0; i <= circle_points; i++)
	{
		theta = 2 * PI*i / circle_points; // angle in radians
		glVertex2f(centerx + rx*cos(theta), centery + ry*sin(theta));
	}
	glEnd();
}

void SDCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius)
{
	GLint i;
	GLdouble theta;
	GLint circle_points = 900;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.5, 0.80);
	glVertex2f(centerx, centery);
	glColor3f(1.0, 0.91, 0.18);
	for (i = 0; i<circle_points; i++)
	{
		theta = 2 * PI*i / circle_points;
		glVertex2f(centerx + radius*cos(theta), centery + radius*sin(theta));
	}
	glEnd();
}

void hairLeft()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(50, 240);
	glVertex2i(40, 210);
	glVertex2i(30, 180);
	glVertex2i(30, 160);
	glVertex2i(30, 140);
	glVertex2i(35, 125);
	glVertex2i(40, 140);
	glVertex2i(45, 160);
	glVertex2i(60, 210);
	glVertex2i(80, 240);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(80, 240);
	glVertex2i(65, 210);
	glVertex2i(62, 190);
	glVertex2i(62, 160);
	glVertex2i(70, 140);
	glVertex2i(100, 95);
	glVertex2i(100, 110);
	glVertex2i(96, 140);
	glVertex2i(90, 170);
	glVertex2i(90, 200);
	glVertex2i(92, 220);
	glVertex2i(96, 240);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(80, 290);
	glVertex2i(50, 240);
	glVertex2i(80, 240);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(148, 370);
	glVertex2i(135, 360);
	glVertex2i(80, 290);
	glVertex2i(80, 240);
	glVertex2i(96, 240);
	glVertex2i(160, 360);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(120, 300);
	glVertex2i(175, 430);
	glVertex2i(180, 475);
	glVertex2i(185, 495);
	glVertex2i(200, 495);
	glVertex2i(185, 420);
	glVertex2i(175, 395);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(200, 495);
	glVertex2i(185, 420);
	glVertex2i(175, 395);
	glVertex2i(215, 360);
	glVertex2i(220, 370);
	glVertex2i(250, 430);
	glVertex2i(280, 495);
	glEnd();

	glColor3f(0.0, 0.2, 0.85);

	glBegin(GL_POLYGON);
	glVertex2f(166.5, 402.0);
	glVertex2i(150, 350);
	glVertex2i(160, 240);
	glVertex2i(218, 360);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(160, 360);
	glVertex2i(135, 330);
	glVertex2i(120, 300);
	glVertex2i(102, 260);
	glVertex2i(96, 240);
	glVertex2i(160, 240);
	glVertex2i(165, 360);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(100, 110);
	glVertex2i(96, 140);
	glVertex2i(90, 170);
	glVertex2i(90, 200);
	glVertex2i(92, 220);
	glVertex2i(96, 240);
	glVertex2i(130, 240);
	glVertex2i(132, 170);
	glVertex2i(125, 140);
	glVertex2i(125, 110);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(100, 110);
	glVertex2i(100, 95);
	glVertex2i(115, 85);
	glVertex2i(135, 75);
	glVertex2i(130, 95);
	glVertex2i(125, 110);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(132, 170);
	glVertex2i(145, 180);
	glVertex2i(140, 140);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(150, 210);
	glVertex2i(130, 195);
	glVertex2i(132, 170);
	glVertex2i(145, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(130, 240);
	glVertex2i(160, 240);
	glVertex2i(150, 210);
	glVertex2i(130, 195);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(218, 359);
	glVertex2i(175, 395);
	glVertex2i(200, 495);
	glVertex2i(280, 495);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(150, 370);
	glVertex2i(150, 350);
	glVertex2i(160, 370);
	glVertex2i(175, 395);
	glVertex2i(165, 405);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(193, 495);
	glVertex2i(185, 495);
	glVertex2i(143, 369);
	glVertex2i(129, 353);
	glVertex2i(112, 333);
	glVertex2i(113, 334);
	glVertex2i(94, 310);
	glVertex2i(82, 293);
	glVertex2i(69, 273);
	glVertex2i(51, 241);
	glVertex2i(44, 224);
	glVertex2i(37, 204);
	glVertex2i(32, 183);
	glVertex2i(28, 163);
	glVertex2i(29, 139);
	glVertex2i(34, 120);
	glVertex2i(40, 144);
	glVertex2i(45, 163);
	glVertex2i(49, 180);
	glVertex2i(53, 196);
	glVertex2i(57, 208);
	glVertex2i(64, 221);
	glVertex2i(69, 228);
	glVertex2i(77, 240);
	glVertex2i(71, 225);
	glVertex2i(67, 216);
	glVertex2i(64, 205);
	glVertex2i(62, 194);
	glVertex2i(61, 183);
	glVertex2i(60, 165);
	glVertex2i(63, 154);
	glVertex2i(70, 139);
	glVertex2i(78, 125);
	glVertex2i(85, 114);
	glVertex2i(98, 96);
	glVertex2i(104, 92);
	glVertex2i(118, 83);
	glVertex2i(135, 74);
	glVertex2i(130, 89);
	glVertex2i(125, 104);
	glVertex2i(124, 118);
	glVertex2i(124, 135);
	glVertex2i(127, 153);
	glVertex2i(130, 165);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(196, 310);
	glVertex2i(160, 240);
	glVertex2i(150, 210);
	glVertex2i(150, 210);
	glVertex2i(145, 180);
	glVertex2i(145, 180);
	glVertex2i(140, 140);
	glVertex2i(131, 168);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(195, 307);
	glVertex2i(280, 493);
	glEnd();

}

void hairRight()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(520, 420);
	glVertex2i(583, 190);
	glVertex2i(617, 190);
	glVertex2i(615, 210);
	glVertex2i(610, 230);
	glVertex2i(602, 250);
	glVertex2i(598, 270);
	glVertex2i(590, 290);
	glVertex2i(580, 310);
	glVertex2i(570, 330);
	glVertex2i(560, 350);
	glVertex2i(550, 360);
	glVertex2i(540, 380);
	glVertex2i(530, 400);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(595, 190);
	glVertex2i(583, 190);
	glVertex2i(580, 170);
	glVertex2i(580, 140);
	glVertex2i(598, 160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(595, 190);
	glVertex2i(598, 160);
	glVertex2i(598, 150);
	glVertex2i(617, 150);
	glVertex2i(619, 170);
	glVertex2i(617, 190);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(598, 150);
	glVertex2i(617, 150);
	glVertex2i(610, 130);
	glVertex2i(608, 110);
	glVertex2i(595, 110);
	glVertex2i(598, 130);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(595, 110);
	glVertex2i(608, 110);
	glVertex2i(600, 90);
	glVertex2i(590, 70);
	glVertex2i(590, 90);
	glEnd();

	glColor3f(0.0, 0.2, 0.85);
	glBegin(GL_POLYGON);
	glVertex2i(420, 490);
	glVertex2i(500, 330);
	glVertex2i(520, 420);
	glVertex2i(490, 515);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(520, 420);
	glVertex2i(530, 400);
	glVertex2i(560, 310);
	glVertex2i(520, 270);
	glVertex2i(500, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(520, 276);
	glVertex2i(560, 310);
	glVertex2i(575, 260);
	glVertex2i(580, 230);
	glVertex2i(520, 230);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(520, 230);
	glVertex2i(510, 190);
	glVertex2i(583, 190);
	glVertex2i(579, 230);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(510, 190);
	glVertex2i(480, 110);
	glVertex2i(480, 90);
	glVertex2i(520, 190);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(520, 190);
	glVertex2i(515, 120);
	glVertex2i(520, 60);
	glVertex2i(560, 100);
	glVertex2i(580, 140);
	glVertex2i(580, 170);
	glVertex2i(583, 190);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(500, 330);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(615, 210);
	glVertex2i(610, 230);
	glVertex2i(602, 250);
	glVertex2i(598, 270);
	glVertex2i(590, 290);
	glVertex2i(580, 310);
	glVertex2i(570, 330);
	glVertex2i(560, 350);
	glVertex2i(555, 360);
	glVertex2i(543, 380);
	glVertex2i(530, 400);
	glVertex2i(521, 417);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(580, 140);
	glVertex2i(598, 160);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(617, 150);
	glVertex2i(619, 170);
	glVertex2i(617, 190);
	glVertex2i(614, 212);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(618, 152);
	glVertex2i(610, 131);
	glVertex2i(608, 110);
	glVertex2i(600, 90);
	glVertex2i(590, 70);
	glVertex2i(590, 90);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(420, 490);
	glVertex2i(500, 330);
	glVertex2i(520, 420);
	glVertex2i(490, 515);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(520, 415);
	glVertex2i(490, 515);
	glEnd();



	glBegin(GL_LINE_STRIP);
	glVertex2i(520, 270);
	glVertex2i(500, 330);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(519, 276);
	glVertex2i(520, 230);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(520, 230);
	glVertex2i(510, 190);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(510, 190);
	glVertex2i(480, 110);
	glVertex2i(480, 90);
	glVertex2i(520, 190);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(520, 190);
	glVertex2i(515, 120);
	glVertex2i(520, 60);
	glVertex2i(560, 102);
	glVertex2i(580, 140);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(472, 510);
	glVertex2i(489, 514);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(597, 159);
	glVertex2i(597, 139);
	glVertex2i(596, 119);
	glVertex2i(594, 108);
	glVertex2i(589, 89);
	glEnd();

}

void body()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(340, 310);
	glVertex2i(335, 305);
	glVertex2i(390, 255);
	glVertex2i(320, 259);
	glVertex2i(385, 255);
	glVertex2i(380, 290);
	glVertex2i(375, 318);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(340, 310);
	glVertex2i(335, 305);
	glVertex2i(338, 285);
	glVertex2i(350, 295);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(350, 295);
	glVertex2i(360, 312);
	glVertex2i(375, 318);
	glVertex2i(365, 285);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(325, 215);
	glVertex2i(315, 255);
	glVertex2i(290, 245);
	glVertex2i(299, 201);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(325, 215);
	glVertex2i(310, 260);
	glVertex2i(390, 255);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(325, 215);
	glVertex2i(355, 185);
	glVertex2i(380, 200);
	glVertex2i(395, 225);
	glVertex2i(383, 255);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(349, 295);
	glVertex2i(339, 310);
	glVertex2i(334, 306);
	glVertex2i(338, 287);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(349, 295);
	glVertex2i(360, 312);
	glVertex2i(375, 318);
	glVertex2i(364, 286);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(336, 297);
	glVertex2i(319, 260);
	glVertex2i(310, 260);
	glVertex2i(312, 255);
	glVertex2i(290, 246);
	glVertex2i(299, 202);
	glVertex2i(325, 216);
	glVertex2i(354, 184);
	glVertex2i(384, 204);
	glVertex2i(394, 225);
	glVertex2i(383, 251);
	glVertex2i(390, 256);
	glVertex2i(383, 262);
	glVertex2i(375, 318);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(335, 311);
	glVertex2i(373, 318);
	glEnd();
}

void armleft()
{
	glColor3f(1.0, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex2i(335, 295);
	glVertex2i(342, 310);
	glVertex2i(308, 310);
	glVertex2i(300, 300);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 290);
	glVertex2i(308, 310);
	glVertex2i(295, 311);
	glVertex2i(290, 295);
	glEnd();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(290, 295);
	glVertex2i(295, 311);
	glVertex2i(205, 395);
	glVertex2i(175, 310);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(175, 310);
	glVertex2i(205, 395);
	glVertex2i(190, 400);
	glVertex2i(160, 310);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(185, 385);
	glVertex2i(170, 398);
	glVertex2i(165, 398);
	glVertex2i(172, 385);
	glVertex2i(160, 392);
	glVertex2i(150, 395);
	glVertex2i(142, 370);
	glVertex2i(149, 395);
	glVertex2i(141, 388);
	glVertex2i(140, 380);
	glVertex2i(142, 370);
	glVertex2i(160, 360);
	glVertex2i(177, 355);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(342, 310);
	glVertex2i(307, 310);
	glVertex2i(294, 312);
	glVertex2i(205, 395);
	glVertex2i(190, 401);
	glVertex2i(160, 311);
	glVertex2i(289, 295);
	glVertex2i(299, 290);
	glVertex2i(304, 300);
	glVertex2i(334, 295);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(306, 309);
	glVertex2i(304, 300);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(295, 311);
	glVertex2i(289, 297);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(204, 395);
	glVertex2i(175, 311);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(185, 385);
	glVertex2i(170, 398);
	glVertex2i(165, 398);
	glVertex2i(172, 385);
	glVertex2i(160, 392);
	glVertex2i(150, 395);
	glVertex2i(149, 395);
	glVertex2i(141, 388);
	glVertex2i(140, 380);
	glVertex2i(142, 370);
	glVertex2i(160, 360);
	glVertex2i(177, 355);
	glEnd();
}

void armright()
{
	glColor3f(1.0, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex2i(379, 295);
	glVertex2i(405, 305);
	glVertex2i(400, 330);
	glVertex2i(375, 318);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(405, 300);
	glVertex2i(415, 305);
	glVertex2i(410, 335);
	glVertex2i(400, 330);
	glEnd();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(415, 305);
	glVertex2i(520, 330);
	glVertex2i(510, 410);
	glVertex2i(406, 364);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(520, 330);
	glVertex2i(535, 330);
	glVertex2i(520, 418);
	glVertex2i(510, 414);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(520, 408);
	glVertex2i(530, 415);
	glVertex2i(540, 420);
	glVertex2i(545, 418);
	glVertex2i(547, 415);
	glVertex2i(539, 408);
	glVertex2i(558, 410);
	glVertex2i(561, 408);
	glVertex2i(562, 400);
	glVertex2i(561, 390);
	glVertex2i(560, 380);
	glVertex2i(550, 371);
	glVertex2i(530, 370);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(375, 318);
	glVertex2i(409, 335);
	glVertex2i(406, 364);
	glVertex2i(510, 410);
	glVertex2i(510, 414);
	glVertex2i(519, 418);
	glVertex2i(535, 331);
	glVertex2i(520, 331);
	glVertex2i(415, 305);
	glVertex2i(405, 301);
	glVertex2i(404, 304);
	glVertex2i(379, 295);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(399, 330);
	glVertex2i(405, 302);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(405, 364);
	glVertex2i(415, 306);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(510, 413);
	glVertex2i(520, 332);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(520, 408);
	glVertex2i(530, 415);
	glVertex2i(540, 420);
	glVertex2i(545, 418);
	glVertex2i(547, 415);
	glVertex2i(539, 408);
	glVertex2i(558, 410);
	glVertex2i(561, 405);
	glVertex2i(562, 400);
	glVertex2i(561, 390);
	glVertex2i(560, 380);
	glVertex2i(550, 371);
	glVertex2i(530, 370);
	glEnd();
}

void nectie()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(350, 295);
	glVertex2i(340, 290);
	glVertex2i(342, 277);
	glVertex2i(358, 280);
	glVertex2i(360, 290);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(338, 285);
	glVertex2i(360, 290);
	glVertex2i(360, 250);
	glVertex2i(333, 225);
	glVertex2i(323, 250);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 293);
	glVertex2i(340, 289);
	glVertex2i(336, 282);
	glVertex2i(362, 282);
	glVertex2i(359, 289);
	glVertex2i(349, 294);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(336, 282);
	glVertex2i(323, 250);
	glVertex2i(333, 226);
	glVertex2i(359, 250);
	glVertex2i(362, 282);
	glEnd();
}

void hair()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(240, 340);
	glVertex2i(260, 300);
	glVertex2i(255, 322);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(240, 340);
	glVertex2i(260, 300);
	glVertex2i(260, 330);
	glVertex2i(252, 350);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(410, 380);
	glVertex2i(410, 353);
	glVertex2i(408, 310);
	glVertex2i(418, 365);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(418, 365);
	glVertex2i(408, 310);
	glVertex2i(425, 345);
	glEnd();
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(185, 545);
	glVertex2i(195, 530);
	glVertex2i(210, 540);
	glVertex2i(210, 520);
	glVertex2i(230, 535);
	glVertex2i(230, 510);
	glVertex2i(255, 535);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(155, 430);
	glVertex2i(170, 460);
	glVertex2i(200, 490);
	glVertex2i(230, 510);
	glVertex2i(238, 488);
	glVertex2i(215, 475);
	glVertex2i(180, 450);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(238, 488);
	glVertex2i(215, 475);
	glVertex2i(210, 460);
	glVertex2i(205, 450);
	glVertex2i(200, 440);
	glVertex2i(198, 430);
	glVertex2i(194, 410);
	glVertex2i(190, 390);
	glVertex2i(192, 370);
	glVertex2i(200, 355);
	glVertex2i(204, 380);
	glVertex2i(220, 400);
	glVertex2i(220, 420);
	glVertex2i(225, 445);
	glVertex2i(230, 460);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(238, 488);
	glVertex2i(230, 460);
	glVertex2i(225, 445);
	glVertex2i(230, 410);
	glVertex2i(240, 375);
	glVertex2i(245, 390);
	glVertex2i(250, 410);
	glVertex2i(260, 440);
	glVertex2i(270, 460);
	glVertex2i(280, 480);
	glVertex2i(345, 505);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(280, 495);
	glVertex2i(288, 480);
	glVertex2i(290, 460);
	glVertex2i(293, 450);
	glVertex2i(295, 440);
	glVertex2i(300, 430);
	glVertex2i(303, 420);
	glVertex2i(350, 430);
	glVertex2i(347, 460);
	glVertex2i(345, 505);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(303, 420);
	glVertex2i(310, 430);
	glVertex2i(313, 400);
	glVertex2i(320, 390);
	glVertex2i(330, 380);
	glVertex2i(335, 375);
	glVertex2i(340, 370);
	glVertex2i(350, 370);
	glVertex2i(350, 430);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(345, 505);
	glVertex2i(385, 440);
	glVertex2i(425, 375);
	glVertex2i(430, 430);
	glVertex2i(430, 480);
	glVertex2i(420, 495);
	glVertex2i(405, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(405, 515);
	glVertex2i(420, 495);
	glVertex2i(449, 465);
	glVertex2i(450, 500);
	glVertex2i(440, 510);
	glVertex2i(429, 530);
	glVertex2i(420, 540);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(420, 540);
	glVertex2i(400, 500);
	glVertex2i(380, 555);
	glVertex2i(360, 560);
	glVertex2i(340, 560);
	glVertex2i(320, 558);
	glVertex2i(290, 550);
	glVertex2i(255, 535);
	glVertex2i(230, 510);
	glVertex2i(238, 488);
	glVertex2i(280, 490);
	glVertex2i(345, 505);
	glVertex2i(405, 505);
	glEnd();

	glColor3f(0.0, 0.2, 0.85);
	glBegin(GL_POLYGON);
	glVertex2i(230, 460);
	glVertex2i(220, 450);
	glVertex2i(210, 430);
	glVertex2i(192, 370);
	glVertex2i(200, 355);
	glVertex2i(204, 380);
	glVertex2i(208, 380);
	glVertex2i(230, 460);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(230, 460);
	glVertex2i(202, 400);
	glVertex2i(210, 389);
	glVertex2i(215, 380);
	glVertex2i(220, 370);
	glVertex2i(230, 350);
	glVertex2i(225, 370);
	glVertex2i(223, 400);
	glVertex2i(220, 420);
	glVertex2i(225, 445);
	glVertex2i(230, 460);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(225, 445);
	glVertex2i(220, 420);
	glVertex2i(220, 400);
	glVertex2i(220, 390);
	glVertex2i(225, 380);
	glVertex2i(240, 340);
	glVertex2i(240, 375);
	glVertex2i(230, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(282, 482);
	glVertex2i(273, 460);
	glVertex2i(265, 450);
	glVertex2i(260, 440);
	glVertex2i(250, 410);
	glVertex2i(245, 390);
	glVertex2i(240, 375);
	glVertex2i(240, 340);
	glVertex2i(250, 325);
	glVertex2i(252, 350);
	glVertex2i(253, 370);
	glVertex2i(260, 400);
	glVertex2i(265, 430);
	glVertex2i(270, 450);
	glVertex2i(272, 460);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(325, 410);
	glVertex2i(335, 375);
	glVertex2i(340, 370);
	glVertex2i(360, 360);
	glVertex2i(350, 370);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(347, 460);
	glVertex2i(345, 430);
	glVertex2i(350, 370);
	glVertex2i(360, 360);
	glVertex2i(350, 430);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(385, 440);
	glVertex2i(410, 380);
	glVertex2i(430, 335);
	glVertex2i(425, 375);
	glVertex2i(410, 400);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(430, 480);
	glVertex2i(430, 460);
	glVertex2i(430, 430);
	glVertex2i(425, 375);
	glVertex2i(430, 335);
	glVertex2i(440, 370);
	glVertex2i(442, 430);
	glVertex2i(440, 460);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(420, 495);
	glVertex2i(435, 470);
	glVertex2i(440, 460);
	glVertex2i(450, 430);
	glVertex2i(448, 465);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(450, 500);
	glVertex2i(448, 465);
	glVertex2i(450, 430);
	glVertex2i(453, 410);
	glVertex2i(460, 405);
	glVertex2i(460, 410);
	glVertex2i(460, 440);
	glVertex2i(460, 470);
	glVertex2i(458, 482);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(247, 326);
	glVertex2i(260, 300);
	glVertex2i(259, 328);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(298, 431);
	glVertex2i(304, 418);
	glVertex2i(314, 399);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(283, 481);
	glVertex2i(249, 324);
	glVertex2i(230, 366);
	glVertex2i(229, 352);
	glVertex2i(210, 387);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(240, 340);
	glVertex2i(260, 300);
	glVertex2i(260, 330);
	glVertex2i(254, 350);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(410, 380);
	glVertex2i(410, 353);
	glVertex2i(406, 310);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(407, 310);
	glVertex2i(425, 345);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(185, 545);
	glVertex2i(195, 530);
	glVertex2i(210, 520);
	glVertex2i(230, 510);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(155, 430);
	glVertex2i(170, 460);
	glVertex2i(200, 490);
	glVertex2i(230, 510);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(215, 473);
	glVertex2i(155, 431);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(215, 475);
	glVertex2i(210, 460);
	glVertex2i(205, 450);
	glVertex2i(200, 440);
	glVertex2i(198, 430);
	glVertex2i(194, 410);
	glVertex2i(190, 390);
	glVertex2i(192, 370);
	glVertex2i(200, 355);
	glVertex2i(204, 380);
	glVertex2i(211, 387);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(285, 481);
	glVertex2i(290, 460);
	glVertex2i(293, 450);
	glVertex2i(295, 440);
	glVertex2i(299, 430);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(328, 382);
	glVertex2i(334, 376);
	glVertex2i(359, 360);
	glVertex2i(350, 425);
	glVertex2i(347, 460);
	glVertex2i(345, 505);
	glVertex2i(385, 440);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(313, 400);
	glVertex2i(320, 390);
	glVertex2i(330, 380);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(358, 374);
	glVertex2i(350, 430);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(385, 440);
	glVertex2i(410, 380);
	glVertex2i(430, 335);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(430, 335);
	glVertex2i(440, 370);
	glVertex2i(442, 430);
	glVertex2i(440, 452);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(420, 495);
	glVertex2i(435, 470);
	glVertex2i(440, 460);
	glVertex2i(450, 430);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glVertex2i(405, 515);
	glVertex2i(420, 495);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(450, 500);
	glVertex2i(440, 510);
	glVertex2i(429, 530);
	glVertex2i(420, 540);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(450, 430);
	glVertex2i(453, 410);
	glVertex2i(460, 405);
	glVertex2i(460, 410);
	glVertex2i(460, 440);
	glVertex2i(460, 470);
	glVertex2i(458, 482);
	glVertex2i(448, 501);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(420, 540);
	glVertex2i(380, 555);
	glVertex2i(360, 560);
	glVertex2i(340, 560);
	glVertex2i(320, 558);
	glVertex2i(290, 550);
	glVertex2i(255, 535);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(185, 545);
	glVertex2i(210, 540);
	glVertex2i(230, 535);
	glVertex2i(255, 535);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(238, 488);
	glVertex2i(230, 460);
	glVertex2i(228, 445);
	glVertex2i(227, 390);
	glVertex2i(229, 366);
	glEnd();
}

void mouse()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(313, 332);
	glVertex2i(385, 345);
	glVertex2i(380, 352);
	glVertex2i(375, 360);
	glVertex2i(370, 365);
	glVertex2i(316, 355);
	glVertex2i(314, 350);
	glVertex2i(313, 340);
	glEnd();

	glColor3f(1.0, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2i(320, 310);
	glVertex2i(315, 320);
	glVertex2i(313, 332);
	glVertex2i(320, 340);
	glVertex2i(330, 345);
	glVertex2i(340, 349);
	glVertex2i(350, 350);
	glVertex2i(360, 353);
	glVertex2i(370, 353);
	glVertex2i(380, 349);
	glVertex2i(385, 353);
	glVertex2i(390, 326);
	glVertex2i(390, 330);
	glVertex2i(380, 328);
	glVertex2i(370, 324);
	glVertex2i(350, 320);
	glVertex2i(330, 325);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(320, 312);
	glVertex2i(315, 320);
	glVertex2i(314, 328);
	glVertex2i(313, 336);
	glVertex2i(313, 347);
	glVertex2i(316, 357);
	glVertex2i(322, 358);
	glVertex2i(333, 357);
	glVertex2i(343, 358);
	glVertex2i(358, 362);
	glVertex2i(370, 366);
	glVertex2i(376, 359);
	glVertex2i(382, 351);
	glVertex2i(387, 342);
	glVertex2i(388, 334);
	glVertex2i(389, 325);
	glVertex2i(350, 320);
	glVertex2i(320, 312);

	glEnd();
}

void mouse2()
{
	glColor3f(1.0, 0.0, 0.5);
	MyEclipse2f(342.0, 335.0, 8.0, 13.0);
}

void eye()
{

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(6);
	glBegin(GL_LINE_STRIP);
	glVertex2i(260, 405);
	glVertex2i(305, 385);
	glVertex2i(262, 359);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(405, 425);
	glVertex2i(360, 390);
	glVertex2i(409, 371);
	glEnd();



	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex2i(250, 468);
	glVertex2i(290, 440);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(355, 445);
	glVertex2i(410, 489);
	glEnd();
}

void eye2()
{
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.5);
	glBegin(GL_LINES);
	glVertex2i(250, 468);
	glVertex2i(290, 440);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(355, 445);
	glVertex2i(410, 489);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	MyEclipse2f(290.0, 380.0, 25.0, 30.0);
	MyEclipse2f(380.0, 395.0, 25.0, 30.0);

	glColor3f(1.0, 1.0, 1.0);
	MyEclipse2f(290.0, 370.0, 20.0, 25.0);
	MyEclipse2f(380.0, 388.0, 20.0, 25.0);

	glColor3f(0.0, 0.0, 0.5);
	MyEclipse2f(290.0, 380.0, 18.0, 28.0);
	MyEclipse2f(380.0, 395.0, 18.0, 28.0);

	glColor3f(0.0, 0.0, 0.3);
	MyEclipse2f(293.0, 375.0, 10.0, 15.0);
	MyEclipse2f(383.0, 390.0, 10.0, 15.0);


	glColor3f(1.0, 1.0, 1.0);
	MyCircle2f(280.0, 390.0, 5.0);
	MyCircle2f(370.0, 405.0, 5.0);
}

void face()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(250, 520);
	glVertex2i(252, 350);
	glVertex2i(260, 328);
	glVertex2i(270, 320);
	glVertex2i(280, 315);
	glVertex2i(290, 311);
	glVertex2i(300, 310);
	glVertex2i(310, 310);
	glVertex2i(320, 310);
	glVertex2i(340, 310);
	glVertex2i(370, 318);
	glVertex2i(390, 323);
	glVertex2i(400, 330);
	glVertex2i(410, 335);
	glVertex2i(410, 380);
	glVertex2i(410, 520);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(252, 349);
	glVertex2i(256, 338);
	glVertex2i(259, 330);
	glVertex2i(268, 322);
	glVertex2i(278, 316);
	glVertex2i(288, 312);
	glVertex2i(296, 310);
	glVertex2i(310, 310);
	glVertex2i(318, 310);
	glVertex2i(320, 310);
	glVertex2i(334, 310);
	glVertex2i(349, 310);
	glVertex2i(363, 314);
	glVertex2i(379, 318);
	glVertex2i(398, 329);
	glVertex2i(409, 335);
	glEnd();

}

void hoofung()
{
	glColor3f(0.42, 0.42, 0.42);
	glBegin(GL_POLYGON);
	glVertex2i(200, 530);
	glVertex2i(190, 470);
	glVertex2i(215, 470);
	glVertex2i(240, 520);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(190, 470);
	glVertex2i(200, 420);
	glVertex2i(220, 420);
	glVertex2i(215, 470);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(430, 550);
	glVertex2i(450, 558);
	glVertex2i(485, 475);
	glVertex2i(460, 470);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(460, 470);
	glVertex2i(485, 475);
	glVertex2i(480, 390);
	glVertex2i(460, 390);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(430, 550);
	glVertex2i(430, 480);
	glVertex2i(457, 480);
	glEnd();

	glColor3f(1.0, 0.3, 0.3);
	glLineWidth(5.5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(215, 525);
	glVertex2i(205, 470);
	glVertex2i(210, 430);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(440, 554);
	glVertex2i(475, 475);
	glVertex2i(470, 395);
	glEnd();

	glColor3f(0.42, 0.42, 0.42);
	glBegin(GL_POLYGON);
	glVertex2i(440, 460);
	glVertex2i(440, 380);
	glVertex2i(475, 380);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(440, 460);
	glVertex2i(440, 380);
	glVertex2i(450, 380);
	glEnd();

	glColor3f(1.0, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2i(450, 400);
	glVertex2i(442, 390);
	glVertex2i(442, 380);
	glVertex2i(450, 380);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(200, 530);
	glVertex2i(190, 470);
	glVertex2i(215, 470);
	glVertex2i(240, 520);
	glVertex2i(190, 470);
	glVertex2i(200, 420);
	glVertex2i(220, 420);
	glVertex2i(215, 470);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(440, 460);
	glVertex2i(440, 380);
	glVertex2i(450, 380);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(485, 475);
	glVertex2i(480, 390);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(430, 550);
	glVertex2i(450, 558);
	glVertex2i(485, 475);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(430, 550);
	glVertex2i(459, 480);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(430, 550);
	glVertex2i(429, 530);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(458, 407);
	glVertex2i(458, 388);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(450, 380);
	glVertex2i(450, 400);
	glVertex2i(442, 390);
	glVertex2i(442, 380);
	glVertex2i(450, 380);
	glEnd();
}

void legleft()
{
	glColor3f(1.0, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex2i(295, 210);
	glVertex2i(270, 195);
	glVertex2i(280, 172);
	glVertex2i(310, 190);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(220, 140);
	glVertex2i(200, 170);
	glVertex2i(190, 170);
	glVertex2i(185, 165);
	glVertex2i(185, 160);
	glVertex2i(190, 150);
	glVertex2i(200, 140);
	glVertex2i(210, 135);
	glEnd();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(280, 172);
	glVertex2i(270, 195);
	glVertex2i(200, 170);
	glVertex2i(205, 160);
	glVertex2i(210, 150);
	glVertex2i(220, 140);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(294, 210);
	glVertex2i(269, 195);
	glVertex2i(200, 171);
	glVertex2i(193, 170);
	glVertex2i(187, 169);
	glVertex2i(185, 165);
	glVertex2i(185, 158);
	glVertex2i(190, 150);
	glVertex2i(197, 143);
	glVertex2i(202, 140);
	glVertex2i(209, 137);
	glVertex2i(217, 141);
	glVertex2i(279, 172);
	glVertex2i(310, 191);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(200, 170);
	glVertex2i(204, 162);
	glVertex2i(209, 152);
	glVertex2i(218, 141);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(269, 195);
	glVertex2i(279, 172);
	glEnd();

}

void legright()
{
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(330, 80);
	glVertex2i(325, 70);
	glVertex2i(328, 60);
	glVertex2i(340, 51);
	glVertex2i(350, 53);
	glVertex2i(360, 60);
	glVertex2i(365, 70);
	glVertex2i(363, 80);
	glEnd();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(338, 150);
	glVertex2i(330, 80);
	glVertex2i(333, 75);
	glVertex2i(340, 70);
	glVertex2i(350, 70);
	glVertex2i(360, 75);
	glVertex2i(363, 80);
	glVertex2i(370, 150);
	glEnd();

	glColor3f(1.0, 0.9, 0.7);
	glBegin(GL_POLYGON);
	glVertex2i(345, 180);
	glVertex2i(340, 150);
	glVertex2i(350, 145);
	glVertex2i(360, 145);
	glVertex2i(368, 150);
	glVertex2i(370, 180);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(344, 180);
	glVertex2i(339, 151);
	glVertex2i(337, 149);
	glVertex2f(328.5, 78);
	glVertex2i(324, 71);
	glVertex2i(327, 61);
	glVertex2i(336, 52);
	glVertex2i(340, 51);
	glVertex2i(350, 53);
	glVertex2i(358, 57);
	glVertex2i(363, 67);
	glVertex2i(365, 72);
	glVertex2i(364, 76);
	glVertex2f(371.5, 151);
	glVertex2i(369, 151);
	glVertex2f(371.5, 180);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(338, 151);
	glVertex2i(347, 146);
	glVertex2i(359, 146);
	glVertex2i(369, 150);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(329, 78);
	glVertex2i(336, 71);
	glVertex2i(349, 71);
	glVertex2i(363, 78);
	glEnd();
}

void skirt()
{
	glColor3f(0.2, 0.3, 0.4);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(350, 260);
	glVertex2i(430, 200);
	glVertex2i(420, 180);
	glVertex2i(400, 170);
	glVertex2i(380, 170);
	glVertex2i(360, 170);
	glVertex2i(340, 170);
	glVertex2i(320, 180);
	glVertex2i(300, 190);
	glVertex2i(280, 200);
	glVertex2i(260, 220);
	glVertex2i(260, 240);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(430, 200);
	glVertex2i(420, 180);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(420, 180);
	glVertex2i(400, 170);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(400, 170);
	glVertex2i(380, 170);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(380, 170);
	glVertex2i(360, 170);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(360, 170);
	glVertex2i(340, 170);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(340, 170);
	glVertex2i(320, 180);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(320, 180);
	glVertex2i(300, 190);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(300, 190);
	glVertex2i(280, 200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(280, 200);
	glVertex2i(260, 220);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 260);
	glVertex2i(260, 220);
	glVertex2i(260, 240);
	glEnd();
}

void moon()
{
	glColor3f(1.0, 0.91, 0.18);
	MyCircle2f(900, 550, 120);
	glColor3f(0.2, 0.8, 1.0);
	MyCircle2f(830, 550, 120);
}

void star()
{
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	glVertex2i(45, 355);
	glVertex2i(35, 330);
	glVertex2i(50, 330);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(50, 330);
	glVertex2i(75, 330);
	glVertex2i(55, 315);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(55, 315);
	glVertex2i(65, 285);
	glVertex2i(40, 305);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(40, 305);
	glVertex2i(15, 285);
	glVertex2i(25, 315);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(25, 315);
	glVertex2i(10, 330);
	glVertex2i(35, 330);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(40, 305);
	glVertex2i(25, 315);
	glVertex2i(35, 330);
	glVertex2i(50, 330);
	glVertex2i(55, 315);
	glEnd();
}

void cloud()
{
	glColor3f(1.0, 1.0, 1.0);
	MyCircle2f(95, 555, 40);
	MyCircle2f(45, 540, 30);
	MyCircle2f(75, 515, 25);
	MyCircle2f(95, 500, 10);
	MyCircle2f(120, 515, 25);
	MyCircle2f(145, 545, 25);
}

void windows()
{
	glColor3ub(255, 255, 255);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(48, 50);
	glVertex2i(48, 70);
	glVertex2i(63, 50);
	glVertex2i(63, 70);
	glVertex2i(80, 30);
	glVertex2i(80, 50);
	glVertex2i(210, 50);
	glVertex2i(210, 70);
	glVertex2i(210, 30);
	glVertex2i(210, 90);
	glVertex2i(230, 50);
	glVertex2i(230, 70);
	glVertex2i(230, 30);
	glVertex2i(330, 50);
	glVertex2i(330, 70);
	glVertex2i(330, 30);
	glVertex2i(330, 30);
	glVertex2i(465, 50);
	glVertex2i(465, 70);
	glVertex2i(465, 30);
	glVertex2i(465, 90);
	glVertex2i(450, 60);
	glVertex2i(480, 60);
	glVertex2i(540, 40);
	glVertex2i(715, 30);
	glVertex2i(715, 50);
	glVertex2i(715, 70);
	glVertex2i(755, 30);
	glVertex2i(755, 50);
	glVertex2i(775, 40);
	glVertex2i(850, 50);
	glVertex2i(850, 30);
	glVertex2i(870, 50);
	glVertex2i(870, 30);
	glVertex2i(920, 45);
	glVertex2i(920, 30);
	glVertex2i(920, 60);
	glVertex2i(1035, 45);
	glVertex2i(1035, 30);
	glVertex2i(1035, 60);
	glVertex2i(1035, 75);
	glVertex2i(1035, 90);
	glVertex2i(1150, 50);
	glVertex2i(1150, 70);
	glVertex2i(1150, 30);
	glVertex2i(1150, 90);
	glVertex2i(1130, 50);
	glVertex2i(1130, 70);
	glVertex2i(1130, 30);
	glEnd();

}

void windows2()
{
	glColor3ub(135, 33, 135);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(48, 50);
	glVertex2i(48, 70);
	glVertex2i(63, 50);
	glVertex2i(63, 70);
	glVertex2i(80, 30);
	glVertex2i(80, 50);
	glVertex2i(210, 50);
	glVertex2i(210, 70);
	glVertex2i(210, 30);
	glVertex2i(210, 90);
	glVertex2i(230, 50);
	glVertex2i(230, 70);
	glVertex2i(230, 30);
	glVertex2i(330, 50);
	glVertex2i(330, 70);
	glVertex2i(330, 30);
	glVertex2i(330, 30);
	glVertex2i(465, 50);
	glVertex2i(465, 70);
	glVertex2i(465, 30);
	glVertex2i(465, 90);
	glVertex2i(450, 60);
	glVertex2i(480, 60);
	glVertex2i(540, 40);
	glVertex2i(715, 30);
	glVertex2i(715, 50);
	glVertex2i(715, 70);
	glVertex2i(755, 30);
	glVertex2i(755, 50);
	glVertex2i(775, 40);
	glVertex2i(850, 50);
	glVertex2i(850, 30);
	glVertex2i(870, 50);
	glVertex2i(870, 30);
	glVertex2i(920, 45);
	glVertex2i(920, 30);
	glVertex2i(920, 60);
	glVertex2i(1035, 45);
	glVertex2i(1035, 30);
	glVertex2i(1035, 60);
	glVertex2i(1035, 75);
	glVertex2i(1035, 90);
	glVertex2i(1150, 50);
	glVertex2i(1150, 70);
	glVertex2i(1150, 30);
	glVertex2i(1150, 90);
	glVertex2i(1130, 50);
	glVertex2i(1130, 70);
	glVertex2i(1130, 30);
	glEnd();

}

void bd()
{
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(20, 50);
	glVertex2i(20, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(40, 0);
	glVertex2i(40, 100);
	glVertex2i(70, 80);
	glVertex2i(70, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(70, 0);
	glVertex2i(70, 60);
	glVertex2i(90, 60);
	glVertex2i(90, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(120, 0);
	glVertex2i(120, 30);
	glVertex2i(150, 70);
	glVertex2i(180, 70);
	glVertex2i(180, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(180, 0);
	glVertex2i(180, 50);
	glVertex2i(200, 50);
	glVertex2i(200, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(200, 0);
	glVertex2i(200, 100);
	glVertex2i(230, 100);
	glVertex2i(300, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(310, 0);
	glVertex2i(310, 90);
	glVertex2i(350, 90);
	glVertex2i(350, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(330, 0);
	glVertex2i(360, 30);
	glVertex2i(400, 30);
	glVertex2i(430, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(430, 0);
	glVertex2i(430, 50);
	glVertex2i(550, 50);
	glVertex2i(550, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(450, 0);
	glVertex2i(450, 100);
	glVertex2i(480, 100);
	glVertex2i(480, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(430, 0);
	glVertex2i(430, 80);
	glVertex2i(500, 80);
	glVertex2i(500, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(500, 0);
	glVertex2i(500, 90);
	glVertex2i(530, 100);
	glVertex2i(530, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(550, 0);
	glVertex2i(550, 80);
	glVertex2i(570, 80);
	glVertex2i(580, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(0, 30);
	glVertex2i(600, 30);
	glVertex2i(600, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(600, 0);
	glVertex2i(600, 90);
	glVertex2i(620, 100);
	glVertex2i(625, 130);
	glVertex2i(630, 100);
	glVertex2i(650, 90);
	glVertex2i(650, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(650, 0);
	glVertex2i(650, 50);
	glVertex2i(680, 50);
	glVertex2i(680, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(680, 0);
	glVertex2i(680, 100);
	glVertex2i(700, 80);
	glVertex2i(700, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(770, 0);
	glVertex2i(770, 60);
	glVertex2i(790, 60);
	glVertex2i(790, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(820, 0);
	glVertex2i(820, 30);
	glVertex2i(850, 70);
	glVertex2i(880, 70);
	glVertex2i(880, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(980, 0);
	glVertex2i(980, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(700, 0);
	glVertex2i(700, 90);
	glVertex2i(730, 100);
	glVertex2i(730, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(740, 0);
	glVertex2i(740, 80);
	glVertex2i(770, 80);
	glVertex2i(770, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(900, 0);
	glVertex2i(900, 80);
	glVertex2i(940, 80);
	glVertex2i(940, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(950, 0);
	glVertex2i(950, 60);
	glVertex2i(980, 60);
	glVertex2i(980, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1010, 0);
	glVertex2i(1010, 90);
	glVertex2i(1040, 110);
	glVertex2i(1035, 150);
	glVertex2i(1040, 105);
	glVertex2i(1060, 90);
	glVertex2i(1060, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1100, 0);
	glVertex2i(1100, 30);
	glVertex2i(1130, 100);
	glVertex2i(1160, 100);
	glVertex2i(1160, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1180, 0);
	glVertex2i(1180, 50);
	glVertex2i(1200, 50);
	glVertex2i(1200, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(1200, 0);
	glVertex2i(1200, 100);
	glVertex2i(1230, 100);
	glVertex2i(1300, 0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(550, 0);
	glVertex2i(550, 30);
	glVertex2i(1200, 30);
	glVertex2i(1200, 0);
	glEnd();

}

void palisade()
{
	glColor3f(1.0, 0.5, 1.0);
	glBegin(GL_QUAD_STRIP);
	glVertex2i(0, 0);
	glVertex2i(0, 15);
	glVertex2i(50, 0);
	glVertex2i(50, 15);
	glVertex2i(1200, 0);
	glVertex2i(1200, 15);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	glVertex2i(0, 0);
	glVertex2i(0, 10);
	glVertex2i(50, 0);
	glVertex2i(50, 10);
	glVertex2i(100, 0);
	glVertex2i(100, 10);
	glVertex2i(150, 0);
	glVertex2i(150, 10);
	glVertex2i(200, 0);
	glVertex2i(200, 10);
	glVertex2i(250, 0);
	glVertex2i(250, 10);
	glVertex2i(300, 0);
	glVertex2i(300, 10);
	glVertex2i(350, 0);
	glVertex2i(350, 10);
	glVertex2i(400, 0);
	glVertex2i(400, 10);
	glVertex2i(450, 0);
	glVertex2i(450, 10);
	glVertex2i(500, 0);
	glVertex2i(500, 10);
	glVertex2i(550, 0);
	glVertex2i(550, 10);
	glVertex2i(600, 0);
	glVertex2i(600, 10);
	glVertex2i(650, 0);
	glVertex2i(650, 10);
	glVertex2i(700, 0);
	glVertex2i(700, 10);
	glVertex2i(750, 0);
	glVertex2i(750, 10);
	glVertex2i(800, 0);
	glVertex2i(800, 10);
	glVertex2i(850, 0);
	glVertex2i(850, 10);
	glVertex2i(900, 0);
	glVertex2i(900, 10);
	glVertex2i(950, 0);
	glVertex2i(950, 10);
	glVertex2i(1000, 0);
	glVertex2i(1000, 10);
	glVertex2i(1050, 0);
	glVertex2i(1050, 10);
	glVertex2i(1100, 0);
	glVertex2i(1100, 10);
	glVertex2i(1150, 0);
	glVertex2i(1150, 10);
	glVertex2i(1200, 0);
	glVertex2i(1200, 10);
	glEnd();

	glColor3f(0.3, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	glVertex2i(0, 0);
	glVertex2i(0, 5);
	glVertex2i(50, 0);
	glVertex2i(50, 5);
	glVertex2i(1200, 0);
	glVertex2i(1200, 5);
	glEnd();

}

void miku()
{
	hairLeft();
	hairRight();
	hoofung();
	glPushMatrix();
	glTranslatef(350.0, 300.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-350.0, -300.0, 0.0);
	armleft();
	armright();
	glPopMatrix();

	face();

	hair();
	glPushMatrix();
	glTranslatef(320.0, 220.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-320.0, -220.0, 0.0);
	legleft();
	legright();
	skirt();
	glPopMatrix();
	body();
	nectie();
}

void rainbow()
{
	glColor3f(1.0, 0.0, 1.0);
	MyCircle2f(770, 100, 600);
	glColor3f(0.0, 0.0, 1.0);
	MyCircle2f(750, 100, 600);
	glColor3f(0.0, 1.0, 1.0);
	MyCircle2f(730, 100, 600);
	glColor3f(0.0, 1.0, 0.0);
	MyCircle2f(710, 100, 600);
	glColor3f(1.0, 1.0, 0.0);
	MyCircle2f(690, 100, 600);
	glColor3f(1.0, 0.5, 0.0);
	MyCircle2f(670, 100, 600);
	glColor3f(1.0, 0.0, 0.0);
	MyCircle2f(650, 100, 600);
	glColor3f(0.2, 0.8, 1.0);
	MyCircle2f(620, 100, 600);

	SDCircle2f(20.0, 550.0, 100.5);
}

void tranform()
{
	glPushMatrix();
	glTranslatef(500.0, -100.0, 0.0);
	glScalef(1.2, 1.2, 1.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(240.0, 230.0, 0.0);
	glScalef(0.7, 0.7, 1.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900.0, 100.0, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1100.0, -100.0, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(700.0, -100.0, 0.0);
	cloud();
	glPopMatrix();


}

void tranformbd()
{

	glPushMatrix();
	glTranslatef(10.0, 40.0, 0.0);
	glColor3ub(234, 166, 234);
	bd();
	windows();
	glPopMatrix();

	glColor3ub(183, 117, 221);
	glPushMatrix();
	glTranslatef(-50.0, 15.0, 0.0);
	bd();
	windows();
	glPopMatrix();


}

void tranformstar()
{
	glPushMatrix();
	glTranslatef(500.0, -100.0, 0.0);
	glScalef(1.2, 1.2, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30.0, 400.0, 0.0);
	glScalef(0.7, 0.7, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(110.0, 290.0, 0.0);
	glScalef(0.5, 0.5, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600.0, 200.0, 0.0);
	glScalef(0.7, 0.7, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400.0, 350.0, 0.0);
	glScalef(0.8, 0.8, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(650.0, 350.0, 0.0);
	glScalef(0.3, 0.3, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(800.0, 250.0, 0.0);
	glScalef(0.3, 0.3, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(680.0, 450.0, 0.0);
	glScalef(0.6, 0.6, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1050.0, 300.0, 0.0);
	glScalef(0.8, 0.8, 1.0);
	star();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1100.0, 230.0, 0.0);
	glScalef(0.5, 0.5, 1.0);
	star();
	glPopMatrix();

}

void tranformarm()
{
	armleft();
	armright();
}

void tranformleg()
{
	legleft();
	legright();
	skirt();
}

void bg1()
{
	moon();
}

void bg2()
{
	rainbow();
}

void tranformeye()
{
	if (d == 1)
		eye();
	else
		eye2();
}

void tranformmouse()
{
	if (d == 1)
		mouse();
	else
		mouse2();
}

void tranformbg()
{
	if (d == 1)
		bg1();
	else
		bg2();
}

void tranformwindow()
{
	if (d == 1)
		windows();
	else
		windows2();
}

void menu(int value)
{
	switch (value) {
	case 1: power = 0.1231;
		break;
	case 2: power = 0.5;
		break;
	case 3: power = 0.8;
		break;
	case 4: power = 1;
		break;

	case 999: exit(0);
		break;
	}
}

void display(void)
{
	glClearColor(0.2, 0.8, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0, angle, 0.0);
	tranformbg();
	glPopMatrix();

	glPushMatrix();
	tranformbd();
	star();
	tranformstar();
	glColor3ub(135, 33, 135);
	bd();
	palisade();
	tranformwindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, angle, 0.0);
	tranform();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, angle, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(angle, 0.0, 0.0);
	miku();
	tranformeye();
	tranformmouse();
	glPopMatrix();


	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		r = 1; g = 0; b = 1;
		display();
		break;

	case '2':
		r = 0; g = 0; b = 1;
		display();
		break;

	case '3':
		r = 0; g = 1; b = 1;
		display();
		break;

	case '4':
		r = 0; g = 1; b = 0;
		display();
		break;

	case '5':
		r = 1; g = 1; b = 0;
		display();
		break;

	case '6':
		r = 1; g = 0.5; b = 0;
		display();
		break;

	case '7':
		r = 1; g = 0; b = 0;
		display();
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("MOUSE :: LEFT CLICK btn=%d state=%d x=%d y=%d\n", btn, state, x, 700 - y);
		//exit(0);
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("MOUSE :: RIGHT CLICK btn=%d state=%d x=%d y=%d\n", btn, state, x, 700 - y);

	}
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		printf("MOUSE :: MIDDLE CLICK btn=%d state=%d x=%d y=%d\n", btn, state, x, 700 - y);
	}
}

int main(int argc, char** argv)
{
	printf("How to use\n");
	printf("press 1 on keyboard -> Purple Star. \n");
	printf("press 2 on keyboard -> Blue Star. \n");
	printf("press 3 on keyboard -> Blue Sky Star \n");
	printf("press 4 on keyboard -> Green Star \n");
	printf("press 5 on keyboard -> Yellow Star \n");
	printf("press 6 on keyboard -> Orange Star \n");
	printf("press 7 on keyboard -> Red Star \n");
	printf("press Esc on keyboard -> Exit \n");
	printf("Click Right Mouse -> Submenu \n");
	printf("Click Submenu -> No.1 Miku Move Slow \n");
	printf("Click Submenu -> No.2 Miku Move Normal \n");
	printf("Click Submenu -> No.3 Miku Move Fast \n");
	printf("Click Submenu -> Turbo Miku Move Turbo \n");
	printf("Click Submenu -> Quiz -> Exit \n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 680);
	glutInitWindowPosition(30, 40);
	glutCreateWindow("project 55160365");
	gluOrtho2D(0.0, 1200.0, 0.0, 680.0);
	glutCreateMenu(menu);
	glutAddMenuEntry("No.1", 1);
	glutAddMenuEntry("No.2", 2);
	glutAddMenuEntry("No.3", 3);
	glutAddMenuEntry("Turbo", 4);
	glutAddMenuEntry("Quit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}