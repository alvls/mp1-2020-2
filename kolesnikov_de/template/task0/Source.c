#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <locale.h>
#include <stdio.h> 
void main() {
	setlocale(LC_ALL, "Russian");
	double rb,rs,distance,r1,r2,x1,x2,y1,y2;
    printf("������� ������ 1 ����������(x,y,r)");	
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	printf("������� ������ 2 ����������(x,y,r)");
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
		printf("���������� ���������");
		return;
	}
	if (distance < rb - rs) 
	{
		printf("���� ���������� ����� ������ ������");
	}
	else
	{
		if (distance = rb - rs) {
			printf("���������� �������� ���������� �������");
			
		}
		else {
			if (distance = rb + rs) {
				printf("���������� �������� ������� ������� � 1 �����");
			}
			if (rb - rs < distance < rb + rs) {
				printf("���������� �������� ������� ������� � 2 ������");
			}
			else printf("���������� ������� ���� �� �����");

		}

	}

		


}