#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define line 4 // ����� �������� � �����-���� (4)
#define end 47 // ���������� �����  �������� � ������ (47)
#define strok 17 // ����� ������ c���� (17)
const unsigned etalon[strok] = { 9999, 1, 70, 6996, 1234, 2020, 6065, 5432, 2018, 3112, 2019, 1000, 1990, 7770, 1959, 1030, 1945};
const char stroka[strok][end] = { "���������� ����� �������", "����� ������� \"Pobed.net\"", "������� ������� �����","�������� (��������)", "��������� ������� ���������", "����� ����������� (��������)", "���������� ������", "������� ��������" , "���������� ��� \"��� �����o\"", "��������� (��������)", "������ (��������)", "������ ��������� (��������)", "����� \"������, �������!\"", "����� \"������������\"", "�������� (��������)", "�� � ������������ ��������", "����� ������ ���������"}; // ����� ����� � ����� ��������
char strih[line]; //��������� ����������� �����-���
unsigned short pens = 0;//����� someone ���� ������������� ���� ������
int kol_vo[strok]; //���������� ������ ������
float prise[strok] = { 0.0, 100.0, 77.0, 179.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 300.0};// ��������� ���� �� ������ ������ �����-�����
const float standprise[strok] = { 0.0, 100.0, 77.0, 179.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 300.0}; // ������������ ���� �� ������
int skidka[strok]; // ������ ������ � ����� ������ ���������
float sum = 0.0; // �������� �����
unsigned short j = 0;
int flag = 1;
void stringp(int i) // ����� ������
{
	while (stroka[i][j] != '\0')
	{
		printf("%c", stroka[i][j]);
		j++;
	}
	printf("\n");
	j = 0;
}
unsigned translator() //������ �����-����
{
	int i = 0, t;// �������� �������
	unsigned kod;//��������������� �����-���
	unsigned plus;//��������������� ���������� ��� �������������� �����-����
	int flag; // ����� �� ������� �� ������� ���, �������� ��� � ������, �� ������� ������ ������ ���������� ������
	do {
		flag = 0;
		kod = 0;
		do scanf("%c%c%c%c", &strih[0], &strih[1], &strih[2], &strih[3]);
		while (getchar() != '\n');
		if (strih[0] == strih[0] == strih[0] == strih[0] == '0')
			strih[0] = 1;
		for (i = 0; i < line; i++)
		{
			plus = 1;
			if (strih[i] - '0' < 10 && strih[i] - '0' >= 0)
			{
				for (t = line - 1; t > i; t--)
					plus *= 10;
				plus = plus * (strih[i] - '0');
				kod += plus;
			}
			else
			{
				kod = 0;
				flag = 1;
				break;
			}
		}
		for (i = 0; i < strok && !flag; i++)
			if (kod == etalon[i])
			{
				stringp(i);
				break;
			}
		if (i = strok && kod != etalon[i])
		{
			flag = 1;
		}
		if (flag)
		{
			printf("������ �����-���� ��� � ���� ������, ��������� ����\n");
			strih[0] = 'j';
		}
	} while (strih[0] - '0' >= 10 || strih[0] - '0' < 0 || strih[1] - '0' >= 10 || strih[1] - '0' < 0 || strih[2] - '0' >= 10 || strih[2]- '0' < 0 || strih[3] - '0' >= 10 || strih[3] - '0' < 0);
	return kod;
}
void codes()// ����� ��������� �����-����� 
{
	int i = 0;
	setlocale(LC_ALL, "Russian");
	printf("��� %u - ", etalon[i]);
	stringp(i);
	i++;
	printf("��� 000%u - ", etalon[i]);
	stringp(i);
	i++;
	printf("��� 00%u - ", etalon[i]);
	stringp(i);
	i++;
	for (i; i < strok; i++)
	{
		printf("��� %u - ", etalon[i]);
		stringp(i);
	}
	printf("\n");
	printf("����� ���, ���������� �� �����, �������� ���� �����-���� ������\n");
	printf("������� ������ ��������� �� 4 �������, � ����� ����� ������� ��������� ��������� Enter\n\n");
	printf("���� �� ������������ � ����������� � ������ ������� �����-����, ������� �� ����� �������");
	getch();
	system("CLS");
}
float sale(int t) // �������� ������
{
	int a[25];
	int i;
	for (i = 0; i < 25; i++)
	{		 
		a[i] = rand() % 11;
		if (a[i] != 0)
			a[i] *= 5;
		else
		{
			a[24] = 0;
			break;
		}
	}
	i = 24;
	prise[t] *= (1.0 - (a[i] / 100.0));
	skidka[t] = a[i];
}
void summator(int kod) // ��������� ���������� �������
{
	int i;
	for (i = 1; i < strok; i++)
		if (kod == etalon[i])
		{
			kol_vo[i]++;
			break;
		}
}
void check() // ������������ ����
{
	int i;
	printf("\n��� �� ������� � �������� \"������\"\n\n");
	for (i = 0; i < strok; i++)
	{
		if (kol_vo[i])
		{
			stringp(i);
			if ((standprise[i] - prise[i]) != 0)
			{
				printf("����: %3.0f ��� ", standprise[i]);
				printf("���-��: %d ��\n", kol_vo[i]);
				printf("���� �� �������: %3.2f ���\n", prise[i]);
			}
			else 
			{
				printf("����: %3.0f ��� ", standprise[i]);
				printf("���-��: %d ��\n", kol_vo[i]);
			}
			printf("���������: %0.2f ���\n\n", prise[i] * kol_vo[i]);
			sum = sum + prise[i] * kol_vo[i];
		}
	}
}
void main() // ����� � ������������ ������ ����������
{
	int r = 0;
	int i, t;
	unsigned kod;
	setlocale(LC_ALL, "Russian");
	do 
	{
		codes();
		srand(time(NULL));
		for (i = 0; i < strok; i++)
			if (i != 6)
				sale(i);
		do
		{
			kod = translator();
			summator(kod);
		} while (kod != 9999 && kod!=0);
		system("color F0");
		check();
		if (pens)
		{
			printf("���������� ������ - %0.2f ��� (5%%)\n\n", 0.05 * sum);
			sum *= 0.95;
		}
		printf("������ ��������� ������ �� ������:\n");
		for (i = 1; i < strok; i++)
		{
			if (skidka[i] != 0)
			{
				r++;
				while (stroka[i][j] != '\0')
				{
					printf("%c", stroka[i][j]);
					j++;
				}
				j = 0;
				printf(" (%d%%)\n", skidka[i]);
			}
		}
		if (r == 0)
			printf("����a, � ������ ��� :)\n");
		printf("\n�������� �����: ");
		printf("%0.2f ���\n", sum);
		printf("������� �� ������� � ����� ��������!\n");
		system("pause");
		for (i = 0; i < strok; i++)
		{
			prise[i] = standprise[i];
			kol_vo[i] = 0;
			sum = 0.0;
			pens = 0;
		}
		system("color 0F");
	} while (kod!=0);
	printf("�� ���� ��������� ����������� � ����� ��������!\n");
	system("pause");
}
