#include <stdio.h>
#include <math.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Russian");
	int type = 0;
	double x1, y1, r1;
	double x2, y2, r2, s;
	float k;
	printf("������ ���������� �����(x1,y1) � ������(r1) ������ ����������: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);								//��������� scanf_s ��� ��� ������-�� ������ ������ ��� ������������� scanf(#define _CRT_SECURE_NO_WARNING) �� ��������
	printf("������ ���������� �����(x2,y2) � ������(r2) ������ ����������: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);

	if ((r1 > 0) && (r2 > 0)) {
		s = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		
		if ((s) > (r1 + r2)) {
			printf("���������� �� ����� ����� �����");
			type = 1;
		}
		if ((s) == (r1 + r2)) {
			printf("���������� �������� ������� �������");
			type = 2;
				}
		if (((r1 > r2) && (r1) == (s + r2)) || ((r2 > r1) && (r2) == (s + r1))) {
			printf("���������� �������� ���������� �������");
			type = 3;
			}
		if (((r1 > r2) && (r1)-(s + r2) > 0) || ((r2 > r1) && (r2)-(s + r1) > 0)) {
			printf("���������� �������� ������� ��������� ������ ������� ��� ���� ������� �� ����������");
			type = 4;
			}
		if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
			printf("���������� ���������");
			type = 5;
			}
		if (type == 0)
			printf("���������� ������������");
	}
	else 
		printf("������ ����� ������");
	scanf_s("%f", &k);  //��� ����, ����� ������� ���������� �� �����������, �� ���� ��������� ��� �����-���� ������ ��������

}
	