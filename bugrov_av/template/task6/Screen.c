#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "all.h"
void menu()
{
	int away;
	int ans;//����� ������������
	char c;
	do {
		printf("======================== MENU =========================\n");
		printf("�������� �����: \n1 - ����������� ������ �������\n");
		printf("2 - �������� �����������\n");
		printf("0 - ����� �� ���������\n");
		printf("======================== MENU =========================\n");
		ans = cleaner(0, 2);
		away = 1;
		switch (ans)
		{
		case 0:
			printf("�� ����� �������, ��� ������ �����?\n");
			printf("���� ��, �� ������� 0\n");
			printf("E��� ���, �� ������� ����� ������ ������\n");
			scanf("%c", &c);
			ans = c - '0';
			if (ans)
				away--;
			break;
		case 1: case 2:
			mode(ans);
			printf("���� �� ������� ����������, ������� 0, ���� ���, �� ����� ������ �������\n\n");
			away = getch();
			away -= '0';
			break;
		}
	} while (!away);
	printf("��� ������� ��������� ������� ����� ������� . . .\n");
	getch();
}
db db_cleaner(db min)
{
	db ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%lf", &ans);
		if ((!clean) || ans < min)
			printf("������ �����\n");
	} while (getchar() != '\n' || !clean || ans < min);
	return ans;
}
int cleaner(int min, int max)
{
	int ans;//����� ������������
	int clean;//����� ��������� ������� �����
	do
	{
		clean = scanf("%d", &ans);
		if (!clean || ans<min || ans>max)
			printf("������ �����\n");
	} while (getchar() != '\n' || !clean || ans<min || ans>max);
	return ans;
}
operation choice()
{
	int ans;//����� ������������
	db(*funk)(db) = NULL;//����� ��������� ��������
	printf("�������� ����� �������, ������� ������� ���������:\n");
	printf("1 - �������\n");
	printf("2 - �����\n");
	printf("3 - ���������� (e^x) \n");
	printf("4 - ���������� ������ �� 1+�\n");
	printf("5 - ����������\n");
	printf("6 - ����������� - ��������������� �������\n");
	printf("7 - ��������������� �����\n");
	printf("8 - ��������������� �������\n");
	printf("9 - ����������� �������� �� 1+x\n");
	printf("0 - ����� � ����\n");
	ans = cleaner(0, 9);
	switch (ans)/////////////////////////////////
	{
	case 0:
		printf("\n");
		menu();
		break;
	case 1:
		funk = cos;
		break;
	case 2:
		funk = sin;
		break;
	case 3:
		funk = exp;
		break;
	case 4:
		funk = sqrt;
		break;
	case 5: 
		funk = atan;
		break;
	case 6:
		funk = atanh;
		break;
	case 7:
		funk = sinh;
		break;
	case 8:
		funk = cosh;
		break;
	case 9:
		funk = log;
		break;
	}
	return funk;
}
void mode(int a)
{
	db acc;// �������� ���������� (����� ������������ � ���� ��������, ������� �������)
	int count;//���������� ���������
	db x;//�������� �������
	operation funk = NULL;//��������� ��������� ������� ��� ������ �����������
	sum res;//��������� ���������� ����
	int nmax;//������������ ����� ���������
	db t1, t2;//��� ��������� �������
	int sq;//��� �������� �����
	a--;
	if (a)
		printf("======================== ������ ����� =========================\n");
	else
		printf("======================== ������ ����� =========================\n");
	funk = choice();
	printf("������� ����� �, � ������� ����� ��������� �������, ������� ������� ������� ����� �� �����\n");
	printf("��� ����������� ����� � ������������ ��������� x �� ������ �� ������ �������\n");
	printf("��� ������������ � ����������� �� ������ ������ �������\n");
	if (funk == sqrt || funk == atanh || funk == atan || funk == log)
	{
		if (funk == sqrt || funk == log)
		do {
			sq = 0;
			x = db_cleaner(-1.0);
			if (x > 1.0)
			{
				sq = 1;
				printf("������ �����\n");
			}
		} while (sq);
		if (funk == atanh || funk == atan)
			do {
				sq = 0;
				x = db_cleaner(-0.999999);
				if (x >= 1.0)
				{
					sq = 1;
					printf("������ �����\n");
				}
			} while (sq);
	}
	else
		x = db_cleaner(-10000000.0);
	if (a)
	{
		printf("������� ����� �������������, �� ����������� 25\n");
		nmax = cleaner(1, 25);
		printf("======================== ������ ����� =========================\n\n");
		head(x, funk);
		t1 = omp_get_wtime();
		for (count = 1; count <= nmax; count++)
		{
			res = polinom(0.0, count, x, funk);
			printer(count, x, res.s, funk);
		}
		t2 = omp_get_wtime() - t1;
		printf("\n���� ������� ���� ��������� � �������� �� %0.6lf �������\n\n", t2);
		printf("============================ ��������� =============================\n\n");
	}
	else
	{
		printf("������� �������� ���������� � ���� ���������� ����� �� 0,000001\n");
		acc = db_cleaner(0.000001);
		printf("������� ���������� ��������� ���� � ���� ������ ����� �� 1 �� 1000\n");
		count = cleaner(1, 1000);
		printf("======================== ������ ����� =========================\n\n");
		t1 = omp_get_wtime();
		res = polinom(acc, count, x, funk);
		t2 = omp_get_wtime() - t1;
		head(x, funk);		
		printer(res.count, x, res.s, funk);		
		printf("\n��� ������� ��� �������� �� %0.6lf �������\n\n", t2);
		printf("============================ ��������� =============================\n\n");
	}
}