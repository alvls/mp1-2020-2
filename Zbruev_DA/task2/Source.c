#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N, number, s=500;//s-���������
	int P;//� ��� ������������ ������� ������������
	int t = 0;
	int i = 0;
	char b;
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
		printf(" ������� \n");
	}
	else if (number == 2)
	{
		printf("��������� ����� �� 1 �� 1000 � ������� ��� \n");
		scanf_s("%d", &N);
		while (N != s)
		{
			printf("%d \n", s);
			printf("���� ���������� ����� ������, ������� <. ���� ���������� ����� ������, ������� > \n");
			b = getchar();
			b = getchar();
			if (b == '<')
			{
				s = s + s / 2;
				i++;
			}
			else
			{
				if (b == '>')
				{
					s = s - s / 2;
					i++;
				}
				else
					printf("������ ������������ ������, ���������� ��� ��� \n");
			} 
		} 
		printf("����� �������: %d \n", i);
	}
	else
	{
		printf("������ ������������ ����� ������\n");
	}
	system("pause");
}