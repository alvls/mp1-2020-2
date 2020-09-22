#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <locale.h>
#include <stdio.h> 
void main() {
	setlocale(LC_ALL, "Russian");
	double rb,rs,distance,r1,r2,x1,x2,y1,y2;
    printf("Введите данные 1 окружности(x,y,r)");	
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	printf("Введите данные 2 окружности(x,y,r)");
	scanf("%lf %lf %lf", &x2, &y2, &r2);
	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

	
	if (r1 > r2) {
		rb = r1;
		rs = r2;

	}
	else {
		rb = r1;
		rs = r2;
	}
	if ((rb == rs) & (distance == 0)) 
	{
		printf("Окружности совпадают");
		return;
	}
	if (distance < rb - rs) 
	{
		printf("одна окружность лежит внутри другой");
	}
	else
	{
		if (distance = rb - rs) {
			printf("Окружности касаются внутренним образом");
			
		}
		else {
			if (distance = rb + rs) {
				printf("Окружности касаются внешним образом в 1 точке");
			}
			if (rb - rs < distance < rb + rs) {
				printf("Окружности касаются внешним образом в 2 точках");
			}
			else printf("Окружности удалены друг от друга");

		}

	}

		


}