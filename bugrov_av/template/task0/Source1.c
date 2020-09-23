#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	float x1, y1, x2, y2, r1, r2; 
	float d; // для расстояния
	unsigned short int met = 1;
	setlocale(LC_ALL, "Russian");
	printf("Введите x1\n");
	scanf_s("%f", &x1);
	printf("Введите y1\n");
	scanf_s("%f", &y1);
	printf("Введите r1\n");
	scanf_s("%f", &r1);
	printf("Введите x2\n");
	scanf_s("%f", &x2);
	printf("Введите y2\n");
	scanf_s("%f", &y2);
	printf("Введите r2\n");
	scanf_s("%f", &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));// хотел через квадрат, ведь math.h позволяет, но что-то не получилось
	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("Полное совпадение\n");
	else
	{
		if (d < r1 + r2)
		{
			if (r1 == d + r2)
			{
				printf("Вторая окружность касается первой внутренним образом\n");
				met--;
			}
			if (r2 == d + r1)
			{
				printf("Первая окружность касается второй внутренним образом\n");
				met--;
			}
			if (r1 + d < r2)
			{
				printf("Первая окружность вложена во вторую\n");
				met--;
			}
			if (r2 + d < r1)
			{
				printf("Вторая окружность вложена в первую\n");
				met--;
			}
			if (met == 1)
			{
				printf("Окружности пересекаются в двух точках\n");
			}
		}
		else

		{
			if (d > r1 + r2)
				printf("Окружности не имеют общих точек\n");
			else
			if (d == r1 + r2)
				printf("Окружности касаются друг друга в одной точке\n");
		}
	}
	system("pause");
}