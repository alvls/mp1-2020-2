#include <stdio.h>
#include <locale.h>
//#include <iostream>
void main()
{
	float x1, y1, r1, x2, y2, r2, count; 
	setlocale(LC_ALL, "Russian");
	printf("¬ведите координаты центра первой окружности и ее радиус через пробел: ");
	count = scanf_s("%f, %f, %f", &x1, &y1, &r1);//проверку сделать
	while ((count != 3) && (r1<=0))
	{
		printf("ќшибка ввода, попытайтесь заново: \n");
		count = scanf_s("%f, %f, %f", &x1, &y1, &r1);
	}
	printf("¬ведите координаты центра второй окружности и ее радиус через пробел: ");
	count = scanf_s("%f, %f, %f", &x2, &y2, &r2);//проверку сделать
	while (count != 3)
	{
		printf("ќшибка ввода, попытайтесь заново: \n");
		count = scanf_s("%f, %f, %f", &x2, &y2, &r2);
	}






}