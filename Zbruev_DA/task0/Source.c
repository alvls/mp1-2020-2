#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	int c;
	float x1, y1, r1, x2, y2, r2;
	r1 = 1;
	r2 = 2;
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ������ ������ ���������� � �� ������ ����� ������: ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	while ((c < 3) || (r1 <= 0))
	{
		printf("������ �����, ����������� ������: \n");
		c = scanf_s("%f %f %f", &x1, &y1, &r1);
	}
	printf("������� ���������� ������ ������ ���������� � �� ������ ����� ������: ");
	c = scanf_s("%f, %f, %f", &x2, &y2, &r2);
	while ((c != 3) || (r2 <= 0))
	{
		printf("������ �����, ����������� ������: \n");
		c = scanf_s("%f, %f, %f", &x2, &y2, &r2);
	}
	if ((r1 == r2) && ((y1 == y2) && (x1 == x2)))
	{
		printf("���������� ���������");
		//res = 1;
	}
	else
		if ((pow((x2 - x1), 2) + pow((y2 - y1), 2)) < pow((r2 - r1), 2))
		{
			printf("���� ���������� ����� ������ ������");
			//res = 2;
		}
		else
			if ((r1 + r2) < sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
			{
				printf("���������� ����� ��� ���� ����� ");
				//res = 3;
			}
			else
				if ((r1 + r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
				{
					printf("���������� �������� ���� ����� �����");
					//res = 4;
				}
				else
					if (fabs(r1 - r2) == sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
					{
						printf("���������� �������� ���� ����� �������");
						//res = 5;
					}
					else
						printf("���������� ������������");
	//system('  pause');
}
