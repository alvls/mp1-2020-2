#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N, number, s=500;//s-����������, � ������� ������������ ��������, ������� ��������� ������� �� ������ ������
	int P;//� ��� ������������ �������� �����, ���������� ������������� �� ������ ������
	int t = 1;//������� ������� ������
	int t2 = 1;//������� ������� ������
	int step=500;//����������, ���������� �� ��������, � ������� ����� ���������� �����, ���������� ������������� �� ������ ������.
	char b;//����������, � ������� ������������ ����� < >, �������� ������������� �� ������ ������
	setlocale(LC_ALL, "Russian");
	printf("� ������ ������ ��������� ����������� ��������� ����� �� ��������� �� 1 �� 1000. �� ������ ������� �������, �� ������� ��������� ��������: ����������� ����� ������, ����������� ����� ������, ��������. ������ �����������, ����� ��       �������� �����. \n");
	printf("�� ������ ������ �� ����������� ����� �� ��������� �� 1 �� 1000 � ������� ���. ��������� �������� ��������� �����,      ������ �� ����� �������, �� ������� �� ������� >, < ��� =. ������ �����������, ����� ��������� ������� �����.\n");
	printf("������� ����� ������ ������: \n");
	scanf_s("%d", &number);
	while ((number != 1) && (number != 2))
	{
		printf("������� ������������ �������� ������ ������, ����������� ������: ");
		scanf_s("%d", &number);
	}
	if (number == 1)
	{
		srand(time(NULL));
		N = rand() % 1000 + 1;
		printf("����������� �������� ����� �� 1 �� 1000 \n");
		scanf_s("%d", &P);
		while (N != P) 
		{
			if (N > P)
			{
				printf("���������� ����� ������ \n");
			}
			else
				if (N < P)
				{
					printf("��������� ����� ������ \n");
				}
			t++;
			printf("����������� �������� ��� ���: ");
			scanf_s("%d", &P);
		} 
		printf("�� �������! ����� �������: %d\n", t);
	}
	else if (number == 2)
	{
		printf("��������� ����� �� 1 �� 1000 � ������� ��� \n");
		scanf_s("%d", &N);
		while (N != s) //����������� �������� "������ ���� � �������".
		{
			printf("%d \n", s);
			printf("���� ���������� ����� ������, ������� >. ���� ���������� ����� ������, ������� < \n");
			b = getchar();
			b = getchar();
			step = step / 2; //����������, ���������� �� ��������, � ������� ����� ���������� �����, ���������� ������������� �� ������ ������. � ������ ����� �������� ��������
			if (b == '>')
			{
				if (step % 2 == 0)
					s = s + step+1;
				else
					s = s + step;
				t2++;
			}
			else
			{
				if (b == '<')
				{
					if (step % 2 == 0)
						s = s - step-1;
					else
						s = s - step;
					t2++;
				}
				else
					printf("������ ������������ ������, ���������� ��� ��� \n");
			} 
		} 
		printf("%d \n", s);
		printf("����� �������: %d \n", t2);
	}
	else
	{
		printf("������ ������������ ����� ������\n");
	}
	system("pause");
}