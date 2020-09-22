#include <stdio.h> 
void main() {
	setlocale(LC_ALL, "Russian");
	float rb,rs,distance,r1,r2,x1,x2,y1,y2;
    printf("Введите данные 1 окружности(x,y,r)");	
	scanf("%f %f %f", &x1, &y1, &r1);

	printf("Введите данные 2 окружности(x,y,r)");
	scanf("%f %f %f", &x2, &y2, &r2);
	distance = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
	if (r1 > r2) {
		rb = r1;
		rs = r2;

	}
	else {
		rb = r1;
		rs = r2;
	}
	if (distance < rb - rs) 
	{
		printf("одна окружность лежит внутри другой");
		return;
	}
	else
	{
		if (distance = rb - rs) {
			printf("Окружности касаются внутренним образом");
			return;
			
		}
		else {
			if (distance = rb + rs) {
				printf("Окружности касаются внешним образом в 1 точке");
				return;
			}
			if (rb - rs < distance < rb + rs) {
				printf("Окружности касаются внешним образом в 2 точках");
				return;
			}
			else printf("Окружности удалены друг от друга");
			return;


		}

	}

		


}