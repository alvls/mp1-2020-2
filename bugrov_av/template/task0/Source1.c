#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	float x1, y1, x2, y2, r1, r2; 
	float d; // ��� ����������
	unsigned short int met = 1;
	setlocale(LC_ALL, "Russian");
	printf("������� x1\n");
	scanf_s("%f", &x1);
	printf("������� y1\n");
	scanf_s("%f", &y1);
	printf("������� r1\n");
	scanf_s("%f", &r1);
	printf("������� x2\n");
	scanf_s("%f", &x2);
	printf("������� y2\n");
	scanf_s("%f", &y2);
	printf("������� r2\n");
	scanf_s("%f", &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));// ����� ����� �������, ���� math.h ���������, �� ���-�� �� ����������
	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("������ ����������\n");
	else
	{
		if (d < r1 + r2)
		{
			if (r1 == d + r2)
			{
				printf("������ ���������� �������� ������ ���������� �������\n");
				met--;
			}
			if (r2 == d + r1)
			{
				printf("������ ���������� �������� ������ ���������� �������\n");
				met--;
			}
			if (r1 + d < r2)
			{
				printf("������ ���������� ������� �� ������\n");
				met--;
			}
			if (r2 + d < r1)
			{
				printf("������ ���������� ������� � ������\n");
				met--;
			}
			if (met == 1)
			{
				printf("���������� ������������ � ���� ������\n");
			}
		}
		else

		{
			if (d > r1 + r2)
				printf("���������� �� ����� ����� �����\n");
			else
			if (d == r1 + r2)
				printf("���������� �������� ���� ����� � ����� �����\n");
		}
	}
	system("pause");
}