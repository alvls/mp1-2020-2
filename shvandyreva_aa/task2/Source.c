/*����������� ��������� ������� �����.

� ��������� ������ ���� ������������� ��� ������.

����� 1. ��������� ����������� ��������� ����� �� ��������� �� 1 �� 1000.
������������ ������ ������� �������, �� ������� ��������� ��������: ����������� ����� ������,
����������� ����� ������, ��������. ������ �����������, ����� ������������ ������� �����.
����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������.

����� 2. ������������ ���������� ����� �� ��������� �� 1 �� 1000 � ������ ���.
��������� �������� ��������� �����, ������ �� ����� �������, �� ������� ������������ ������ >,
< ��� =. ������ �����������, ����� ��������� ������� �����.
����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������.

� ������ 2 �������, ��� ������������ ����� ���� ������.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	int a, b, num, c, q, m = 1;
	int seed = 0;
	int i = 0;
	char e;
	setlocale(LC_ALL, "rus");
	printf("���� ������ �����. \n - ���� �� ������, ����� ������� ����� 1, �� ������� 1; \n - ���� ������ ������� ����� 2, �� ������� 2. \n ");
	scanf_s("%d", &a);
	if (a == 1)
	{
		printf("�� ������� ������ �����. ��������� ����� �� 0 �� 1000 \n");
		srand(time(NULL));
		int num = rand() % 1000 + 1;
		printf("%d \n", num);
		printf("������� ����� \n");
		scanf_s("%d", &c);
		while (c != num)
		{
			if (c > num)
				printf("���������� ����� ������ \n");
			if (c < num)
				printf("���������� ����� ������ \n");
			printf("������� ������ ����� \n");
			scanf_s("%d", &c);
			i++;
		}
		i++;
		printf("������� \n");
		printf("����� �������: %d", i);
		scanf_s("%d", &q);
	}
	if (a == 2) //������� ���������� �������, ���� ������ ����� ������� 
	{
		printf("�� ������� ������ �����, ��������� ����� �� 0 �� 1000 ����� \n");
		scanf_s("%d", &b);
		if ((b >= 1) && (b <= 1000))
		{
			int left = 1, right = 1000;
			int num = (left + right) / 2;
			printf("��������� ������, ��� ��� ����� ");
			printf("%d \n", num);
			printf("������ >,< ��� =\n");
			scanf_s("%s", &e, 2);
			i = 1;
			while (e != '=')
			{

				if (e == '>')
					left = num;
				if (e == '<')
					right = num;
				num = (left + right) / 2;
				printf("��������� ������, ��� ��� ����� \n");
				printf("%d \n", num);
				printf("������ >,< ��� =");
				scanf_s("%s", &e, 2);
				i++;
			}
			printf("��������� ������� ����� \n");
		}
		else
			printf("�� �������� �����, ������� ������� �� ������� ��������� �� 0 �� 1000 \n");
		printf("����� �������: %d", i);
		scanf_s("%d", &q);
	}
	else
		printf("������ ������ ���");
}
	/* if (a == 2) //��� ����� ������, ��� ��������� ��������� ������, �� ��-���� ��������� 
	{
		printf("�� ������� ������ �����, ��������� ����� �� 0 �� 1000 ����� \n");
		scanf_s("%d", &b);
		if ((b >= 1) && (b <= 1000))
		{
			int left = 1, right = 1000;
			int num = left + rand() % right + 1;
			printf("��������� ������, ��� ��� ����� ");
			printf("%d \n", num);
			printf("������ >,< ��� =\n");
			scanf_s("%s", &e, 2);
			i = 1;
			while (e != '=')
			{

				if (e == '>')
					left = num;

				if (e == '<')
					right = num;
				num = left + rand() % (right - left + 1);
				printf("��������� ������, ��� ��� ����� \n");
				printf("%d \n", num);
				printf("������ >,< ��� =");
				scanf_s("%s", &e, 2);
				i++;

			}
			printf("��������� ������� ����� \n");
		}
	*/