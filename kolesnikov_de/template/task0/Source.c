#include <stdio.h> 
void main() {
	setlocale(LC_ALL, "Russian");
	float rb,rs,distance,r1,r2,x1,x2,y1,y2;
    printf("������� ������ 1 ����������(x,y,r)");	
	scanf("%f %f %f", &x1, &y1, &r1);

	printf("������� ������ 2 ����������(x,y,r)");
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
		printf("���� ���������� ����� ������ ������");
		return;
	}
	else
	{
		if (distance = rb - rs) {
			printf("���������� �������� ���������� �������");
			return;
			
		}
		else {
			if (distance = rb + rs) {
				printf("���������� �������� ������� ������� � 1 �����");
				return;
			}
			if (rb - rs < distance < rb + rs) {
				printf("���������� �������� ������� ������� � 2 ������");
				return;
			}
			else printf("���������� ������� ���� �� �����");
			return;


		}

	}

		


}