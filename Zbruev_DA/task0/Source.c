#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	int count;
	float x1, y1, r1, x2, y2, r2; 
	setlocale(LC_ALL, "Russian");
	printf("Введите координаты центра первой окружности и ее радиус через пробел: ");
	count = scanf_s("%f, %f, %f", &x1, &y1, &r1);//проверку сделать
	while ((count != 3) && (r1<=0))
	{
		printf("Ошибка ввода, попытайтесь заново: \n");
		count = scanf_s("%f, %f, %f", &x1, &y1, &r1);
	}
	printf("Введите координаты центра второй окружности и ее радиус через пробел: ");
	count = scanf_s("%f, %f, %f", &x2, &y2, &r2);//проверку сделать
	while (count != 3)
	{
		printf("Ошибка ввода, попытайтесь заново: \n");
		count = scanf_s("%f, %f, %f", &x2, &y2, &r2);
	}
	if ((r1 == r2) && ((y1 == y2) && (x1 == x2)))
	{
		printf("Окружности совпадают");
	}
	else
		if (((r2 > r1) || (r2 < r1)) && (y1 == y2) && (x1 == x2))
		{
			printf("одна окружность лежит внутри другой");
		}
	if ((r1 + r2) < sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	{
		printf("окружности лежат вне друг друга ");
	}

	if ((r1 + r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	{
		printf("окружности касаются друг друга извне");
	}
	else 
		if (fabs(r1 - r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
		{
			printf("окружности касаются друг друга изнутри");
		}

	






}