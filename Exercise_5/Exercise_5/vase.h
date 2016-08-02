/*
 *  Creates a Vase for the scene, scales it to the appropriate size,
 *  and calculates the normal vectors for lighting
 */

#include <GL/glut.h>
#include "vectorFunctions.h"


GLdouble Vase[12][3] = { {0, 0, 0},
						{1.5, 0, 0},
						{2.75, 0.6, 0},
						{3.75, 1.6, 0},
						{4.25, 3, 0},
						{4, 4.5, 0},
						{3.3, 5.7, 0},
						{2.6, 7, 0},
						{2, 8.4, 0},
						{2, 9.9, 0},
						{2.3, 11.3, 0},
						{2.7, 12, 0} };

GLdouble VaseA[12][3];
GLdouble VaseB[12][3];
GLdouble VaseC[12][3];

void vase()
{
	float AB[3], AC[3],OrthogonalABC[3], normalizedABC[3];//vectors
	float pointA[3], pointB[3], pointC[3];

	int i, j, k;
	double x, theta, temp, temp2;
	double c; /*radians */

	c=3.14159/180.0;  /*degree to radian convertor */

	for(i=0; i<12; i++)
	{
		for(j=0; j<3; j++)
		{
			VaseA[i][j] = Vase[i][j];
			VaseB[i][j] = Vase[i][j];

			if(i<11)
				VaseC[i][j] = Vase[i+1][j+1];
		}
	}

	for(theta=0.0; theta<=360.0; theta+=15.0)
	{
		for(i=0; i<12; i++)
		{
			x = Vase[i][0];
			for(j=0; j<3; j+=2)
			{
				temp = Vase[i][j];

				if(i<11)
					temp2 = Vase[i+1][j+1];
			
				if(j == 0) {
					temp = x*cos(c*theta);
					temp2 = x*cos(c*theta);
				} else {
					temp = x*(-sin(c*theta));
					temp2 = x*(-sin(c*theta));
				}
			
				VaseB[i][j] = temp;
				VaseC[i][j] = temp2;
			}
		}

		glPushMatrix();
			glTranslatef(0.6, 0.3, 0.3);
			glScalef(0.02, 0.02, 0.02);
			glBegin(GL_QUAD_STRIP);
			for(k=11; k>=0; k--)
			{
				pointA[0] = VaseA[k][0]; pointA[1] = VaseA[k][1]; pointA[2] = VaseA[k][2];
				pointB[0] = VaseB[k][0]; pointB[1] = VaseB[k][1]; pointB[2] = VaseB[k][2];
				pointC[0] = VaseC[k][0]; pointC[1] = VaseC[k][1]; pointC[2] = VaseC[k][2];

				VectorFromPoints(pointA, pointB , AB);
				VectorFromPoints(pointA, pointC , AC);
				VectorCrossProduct(AB,AC,OrthogonalABC);
				VectorNormalize(OrthogonalABC, normalizedABC);
				invertNormalizedVector(normalizedABC);

				glNormal3fv(normalizedABC);glVertex3dv(VaseA[k]);
				glNormal3fv(normalizedABC);glVertex3dv(VaseB[k]);
			}
			glEnd();
		glPopMatrix();

		for(i=0; i<12; i++)
		{
			for(j=0; j<3; j+=2)
			{
				VaseA[i][j] = VaseB[i][j];
			}
		}
	}
}