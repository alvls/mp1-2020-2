#define _USE_MATH_DEFINES
#define COUNT_NUM_FOR_BERNULLI 1000
//����������� ���������
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <locale.h>
#include "FirstMode.h"
#include "Interactive.h"
#include "SecondMode.h"

//double FunSin(double x, int count, double accu, double eta, double* res, int* i);
//sin,cos,exp,coth,ln(1+x),arctg,arcctg,sh,ch,arcsin,arccos
//����������� (1+x)^1/2,tg,ctg,tan,cot
			//������� �������


void main()
{
	int choice = 0, vivod = 0;
	setlocale(LC_ALL, "Rus");
	//�������, ������� ��������� ����������.
	//�������, ������� ������� ������.(����������� ������� ������) �� ����� :(
	vivod = Menu();
	if (vivod == 1)
	{
		Instraction();
		system("pause");
		system("cls");
		printf("������ ����� ������������ � ����������� �� ������������� ��������� ������� ���������� � ������!\n");
		choice = ChoiceMode();
	}
	else if (vivod == 2)
	{
		choice = ChoiceMode();
	}
	else
	{
		printf("�������, �� ����������� ���� ����������. �� ��������!\n");
		return;
		system("pause");
	}
	switch (choice)
	{
	case 1:
		vivod = FirstFunctionMode();
		break;
	case 2:
		vivod = SecondFunctionMode();
		break;
	}
	printf("\n\n\n\t��������� ��������� ������� �������!\n");
	system("pause");
	system("cls");
	choice = -1;
	printf("������� \"1\", ���� �� ������ ���������� �������� � ����������.\n������� \"0\", ���� ������ ��������� ������.\n");
	while ((choice < 0) || (choice > 1))
	{
		scanf_s("%d", &choice);
		if ((choice < 0) || (choice > 1))
		{
			printf("����� ������� �� �������������, ������� \"1\" - ��� ����������� ������ ���������, \"0\" - ��� ���������� ������ ���������.\n");
		}
	}
	if (choice == 1)
	{
		system("cls");
		main();
	}
	else
	{
		printf("�������, �� ����������� ���� ����������. �� ��������!\n");
		system("pause");
	}
}