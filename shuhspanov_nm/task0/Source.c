#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main()
{
	float x1, x2, y1, y2, r1, r2, r, d, max, min;
	printf("Enter the coordinates of the center of the first circle: ");
	scanf("%f %f", &x1, &y1);
	printf("Enter the radius of the first circle: ");
	scanf("%f", &r1);
	printf("Enter the coordinates of the center of the second circle: ");
	scanf("%f %f", &x2, &y2);
	printf("Enter the radius of the second circle: ");
	scanf("%f", &r2);
	d = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	r = r1 + r2;
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("The circles match.\n");
	}
	else if (d == r)
	{
		printf("One point of intersection of circles.\n");
	}
	else if (d > r)
	{
		printf("Circles do not intresect.\n");
	}
	else if ((d < r) && (d != 0))
	{
		printf("Two points of intresection of circles.\n");
	}

	if (r1 > r2)
	{
		max = r1;
		min = r2;
	}
	else if (r1 <= r2)
	{
		min = r1;
		max = r2;
	}

	if (d + min < max)
	{
		printf("The circle is in the circle.\n");
	}
	
	system("pause");
}