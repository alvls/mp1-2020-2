#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int n, a, ugad, lev, i = 0, num;//n - ����� ������ ������; a - �������������� ������� �����; ugad - �������������� ����������; lev - ��������� �����; i - �������; num - ��������� �����;
	char c;// ������, ����������� ��� ���������� � ������
	setlocale(LC_ALL, "Russian");
	printf("������� ������� � ���� \"������ �����\"\n");
	printf("����� ����� ���� �������� �� 1 �� 1000\n");
met1: srand(time(NULL));
	num = rand() % 1000 + 1;
	a = -1;
	printf("�������� �����:\n 1 - B� ���������� �����,���������� ����������\n 2 - ��������� ���������� �����, ������� ������� �����\n");
	scanf("%d", &n);
	system("CLS");
	if (n != 2 && n != 1)
	{
		printf("��� ����� ����������� ���� � ���� ������������. � ���� ������� ������ �������� ����� ����\n");
		goto met1;
	}
	switch (n)
	{
	case 1:
		printf("������� �������������� ����o\n");
		while (a != num)
		{
			scanf("%d", &a);
			i++;
			if (a < num)
			{
				printf("���������� ����� ������\n");
			}
			else
				if (a > num)
				{
					printf("���������� ����� ������\n");
				}
		}
		printf("�� ������� � %d-�� �������, ����������!\n", i);
		i = 0;
		break;
	case 2:
		printf("��������� �����\n");
		printf("���� ���������� ���� ����� ������, �� ������ <, ���� ������, �� �������� >, ���� �� �������, �� =\n");
	met3:	lev = 500;
		ugad = lev;
	met2:
		i++;
		lev = (lev + 1) / 2;
		if (i == 8)
			lev = 1;
		printf("��� ����� %d?\n", ugad);
		scanf("%c", &c);
		scanf("%c", &c);
		switch (c)
		{
		case '<':
			ugad -= lev;
			goto met2;
		case '>':
			ugad += lev;
			goto met2;
		case'=':
			printf("��������� ������ � %d-�� �������, ��������� �������� � ������� ������!\n", i);
			i = 0;
			break;
		default:
			printf("�� ������ ���� �����������, �� � ���������� ���� ��������\n");
			printf("����� ����������� ����� ��� �������������� �������\n");
			i = 0;
			goto met3;
		}
	}
	printf("���� �� ������ ��� ��� �������, �� ������� ����\n");
	c = getch();
	system("CLS");
	if (c == '0')
		goto met1;
	printf("������� �� ����! ��������� �� ������� ������ ������ ������ ��������� ���� ���!\n");
	system("pause");
}