#define MAX_WINDOW 20

//Define a function

float get_value(float max, float min)
{
	float temp;
	do
	{
		printf("Calculate the width");
		scanf("%f",&temp);
	//temp = max*min;

	} while (temp<max*min);
	return temp;
}