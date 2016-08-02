#include <stdio.h>
#include "Header.h"

int main()
{
	float height, width, window_cost, window_sell, house_cost;
	int no_of_windows, windows_count;

	height = get_value(MIN_HEIGHT,MAX_HEIGHT);
	width = get_value(MIN_WIDTH, MAX_WIDTH);

	window_cost = height*width;
	printf("The cost of window %f",&window_cost);
}