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
	printf("������� ����� ������: ");
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
		printf("%d\n", N);
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
		printf("�� �������! �� ������� %i", t);
		printf(" �����");
		if (t%10==1)
			printf("��\n");
		else 
			if ((t%10==2)|| (t % 10 == 3)|| (t % 10 == 4))
				printf("��\n");
			else 
				  printf("��\n");
	}
	else if (number == 2)
	{
		printf("��������� ����� �� 1 �� 1000 � ������� ��� \n");
		scanf_s("%d", &N);
		while (N != s) //����������� �������� "������ ���� � �������".
		{
			printf("%d \n", s);
			printf("���� ���������� ����� ������, ������� <. ���� ���������� ����� ������, ������� > \n");
			b = getchar();
			b = getchar();
			step = step / 2; //����������, ���������� �� ��������, � ������� ����� ���������� �����, ���������� ������������� �� ������ ������. � ������ ����� �������� ��������
			if (b == '<')
			{
				if (step % 2 == 0)
					s = s + step;
				else
					s = s + step+1;
				t2++;
			}
			else
			{
				if (b == '>')
				{
					if (step % 2 == 0)
						s = s - step;
					else
						s = s - step-1;
					t2++;
				}
				else
					printf("������ ������������ ������, ���������� ��� ��� \n");
			} 
		} 
		printf("����� �������: %d \n", t2);
	}
	else
	{
		printf("������ ������������ ����� ������\n");
	}
	system("pause");
}