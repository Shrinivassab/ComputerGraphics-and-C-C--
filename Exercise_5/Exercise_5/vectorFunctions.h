/*
 *  Vector Functions for calculating normals
 */
#include <math.h>

void VectorFromPoints(float pointA[3], float pointB[3], float vectorAB[3])
{
    vectorAB[0] = pointB[0] - pointA[0];
    vectorAB[1] = pointB[1] - pointA[1];
    vectorAB[2] = pointB[2] - pointA[2];
}

float VectorMagnitude(float vector[3])
{

	float temp;

	temp = vector[0]*vector[0];
	temp += vector[1]*vector[1];
	temp += vector[2]*vector[2];

	return(sqrt(temp));
}

void VectorCrossProduct(float x[3], float y[3], float xCrossy[3])
{

	xCrossy[0] = x[1]*y[2] - x[2]*y[1] ;
	xCrossy[1] = x[2]*y[0] - x[0]*y[2];
	xCrossy[2] = x[0]*y[1] - x[1]*y[0] ;

}

void VectorNormalize(float vector[3], float normalizedVector[3])
{
	float temp;

	temp = VectorMagnitude(vector);

	normalizedVector[0] = vector[0]/temp;
	normalizedVector[1] = vector[1]/temp;
	normalizedVector[2] = vector[2]/temp;
}

void invertNormalizedVector(float normalizedVector[3])
{
	normalizedVector[0] *= -1;
	normalizedVector[1] *= -1;
	normalizedVector[2] *= -1;
}
