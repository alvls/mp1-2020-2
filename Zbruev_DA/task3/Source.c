#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
void main()
{
	int n;//���������� ���� � �����
	int t;//�����, ������� �������� �������� ��������� ��� ����������� �����
	int P, step, i, b=0;//b-�����, ������������ �����������; P-����� ������������; step- � ��� ������������ ������� ������� �� 10 �����, ���������� ������������� ��� ��������� � ������ b
	int cow = 0;//���������� �����
	int buffalo = 0;//���������� �����
	int count=1;//������� 
	int arr[N];//������, � ������� ������������ �����, �� ������� ������� ����� b, ������������ �����������
	char c = 0;
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ���� � ����� (�������� �� 2 �� 5): ");
	scanf_s("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("������� ������������ �������� ����� �����, ����������� ������: ");
		scanf_s("%d", &n);
	}
	srand(time(NULL));
	arr[0] = rand() % 9+1;
	for (i = 1; i < N; i++)
		arr[i] = arr[0];
	for (i = 1; i < n; i++)
	{
		do
			{
			  t = rand() % 10;
			} while ((arr[0] == t)|| (arr[1] == t) || (arr[2] == t) || (arr[3] == t) || (arr[4] == t));
		arr[i] = t;
	}
	for (i = 0; i < n; i++)//������ ����� 
		b = b * 10 + arr[i];
	while (1)
	{
		printf("����������� �������� �����, �� ���������� ���������� ����. ���� ������ ���������, ������� 0 \n");
		scanf_s("%d", &P);
		if (P == 0)
		{
			printf("�� ����� �������� ����� %d\n", b);
			printf("����� �������: %d \n", count-1);
			printf("����� ������\n");
			break;
		}
		for (i = n - 1; i >= 0; i--)//���������� ����� P � ������ b, ������� ������� ���������
		{
			step = P % 10;
			P = P / 10;
			if ((step == arr[0]) || (step == arr[1]) || (step == arr[2]) || (step == arr[3]) || (step == arr[4]))
				cow++;
			if (step == arr[i])
			{
				buffalo++;
				cow--;
			}
		}
		if (buffalo == n)
		{
			printf("�� ��������! \n");
			printf("����� �������: %d \n", count);
			break;
		}
		else
		{
			printf("���������� �����: %i\n", cow);
			printf("���������� �����: %i\n", buffalo);
			cow = 0;
			buffalo = 0;
		}
		count++;
	}
	
	system("pause");
}
