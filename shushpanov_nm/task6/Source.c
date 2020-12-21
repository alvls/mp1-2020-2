//11. ��������������� ������� - th(x)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include "FunctionCalculate.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int MenuMode();
int MenuFunction();
void FirstMode(double(*pointFunc)(long int, double, double, double));
void SecondMode(double(*pointFunc)(long int, double, double, double));
double FunctionSin(long int numberOfElements, double x, double referenceValue, double calculationAccuracy);
double FunctionCos(long int numberOfElements, double x, double referenceValue, double calculationAccuracy);
double FunctionExpiration(long int numberOfElements, double x, double referenceValue, double calculationAccuracy);
double FunctionHyporbolicTangentWithE(long int numberOfElements, double x, double referenceValue, double calculationAccuracy);
double FunctionHyporbolicTangentWithBernoulli(long int numberOfElements, double x, double referenceValue, double calculationAccuracy);

char* modes[] = { "1. ����� (� �������� �������� ����������)", "2. ����� (� �������� ����� �������������)" };
char* functions[] = { "1. sin(x)", "2. cos(x)", "3. exp(x)", "4. th(x) � ������� ������� E", "5. th(x) � ������� ����� ��������"};

int numberOfElements, numberOfExperiments;
double calculationAccuracy, referenceValue, originalValue;

int MenuMode()
{
	int size = sizeof(modes) / sizeof(char*);
	int mode, done = 1;
	printf("\n������ ���������:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s \n", modes[i]);
	}
	while (done)
	{
		printf("\n");
		printf("�������� ���� �� �������: ");
		scanf("%d", &mode);
		if (mode == 1 || mode == 2)
		{
			done = 0;
		}
		else
		{
			printf("������ ������ �� ����������! ����������, ���������� ��� ���...\n");

		}
	}
	printf("\n��������� �����: %s\n", modes[mode - 1]);
	return mode;
}

int MenuFunction()
{
	int size = sizeof(functions) / sizeof(char*);
	int selectedFunction, done = 1;
	printf("\n������� ���������:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s \n", functions[i]);
	}
	while (done)
	{
		printf("\n");
		printf("�������� ���� �� �������: ");
		scanf("%d", &selectedFunction);
		if (selectedFunction == 1 || selectedFunction == 2 || selectedFunction == 3 || selectedFunction == 4 || selectedFunction == 5)
		{
			done = 0;
		}
		else
		{
			printf("����� ������� �� ����������! ����������, ���������� ��� ���...\n");

		}
	}
	printf("\n��������� �������: %s\n", functions[selectedFunction - 1]);
	return selectedFunction;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int mode, selectedFunction, done = 1, exitMode, doneExit = 1;
	double x;
	double(*pointFunc)(long int, double, double, double);
	pointFunc = NULL;
	printf("����� ���������� � ��������� �� ���������� �������� ������� � �������� ������������.\n");
	while (done)
	{
		exitMode = 0, doneExit = 1;
		mode = MenuMode();
		selectedFunction = MenuFunction();
		printf("\n������� �������� ��� X � ������� (1,3 � �.�.): ");
		scanf("%lf", &x);
		switch (selectedFunction)
		{
			case 1:
			{
				pointFunc = FunctionSin;
				x = x * (M_PI / 180);
				printf("�������� X � ��������: %f\n", x);
				referenceValue = sin(x);
				originalValue = x;
				break;
			}
			case 2:
			{
				pointFunc = FunctionCos;
				x = x * (M_PI / 180);
				printf("�������� X � ��������: %f\n", x);
				referenceValue = cos(x);
				originalValue = x;
				break;
			}
			case 3:
			{
				pointFunc = FunctionExpiration;
				referenceValue = exp(x);
				originalValue = x;
				break;
			}
			case 4:
			{
				pointFunc = FunctionHyporbolicTangentWithE;
				//x = x * (M_PI / 180);
				//printf("�������� X � ��������: %f\n", x);
				referenceValue = tanh(x);
				originalValue = x;
				break;
			}
			case 5:
			{
				pointFunc = FunctionHyporbolicTangentWithBernoulli;
				//x = x * (M_PI / 180);
				//printf("�������� X � ��������: %f\n", x);
				referenceValue = tanh(x);
				originalValue = x;
				break;
			}
		}
		switch (mode)
		{
			case 1:
			{
				FirstMode(pointFunc);
				break;
			}
			case 2:
			{
				SecondMode(pointFunc);
				break;
			}
		}
		printf("\n������ ����������� ��� ���?\n\n�������� ����:\n1. ����������� ������ �������\n2. ����� �� ���������\n\n");
		while (doneExit)
		{
			printf("������� ����� ����: ");
			scanf("%d", &exitMode);
			switch (exitMode)
			{
				case 0:
				{
					break;
				}
				case 1:
				{
					doneExit = 0;
					break;
				}
				case 2:
				{
					doneExit = 0;
					done = 0;
					break;
				}
				default:
				{
					printf("\n������ ������ ���� �� ����������, ����������, ���������� ��� ���.\n\n");
					break;
				}
			}
		}
	}
	printf("\n�� ������ �������! ������� ��� ���������������� ����� ����������!\n\n");
	system("pause");
}

void FirstMode(double(*pointFunc)(long int, double, double, double))
{
	int done = 1;
	while (done)
	{
		printf("\n������� �������� ���������� (>= 0,000001): ");
		scanf("%lf", &calculationAccuracy);
		if (calculationAccuracy >= 0.000001)
		{
			done = 0;
		}
		else
		{
			printf("\n�������� �������� ����������, ���������� ��� ���!\n\n");
		}
	}
	done = 1;
	while (done)
	{
		printf("\n������� ����� ��������� ���� (N - �� 1 �� 1000): ");
		scanf("%d", &numberOfElements);
		if (numberOfElements >= 1 && numberOfElements <= 1000)
		{
			done = 0;
		}
		else
		{
			printf("\n����� ��������� ����� ��������� �������� �� 1 �� 1000, ���������� ��� ���!\n\n");
		}
	}
	printf("\n��������� ��������: %f\n\n", referenceValue);
	printf("���������� ���������     ����������� ������ �������     ����������� ����������\n");
	pointFunc(numberOfElements, originalValue, referenceValue, calculationAccuracy);
}

void SecondMode(double(*pointFunc)(long int, double, double, double))
{
	int doneSecondMode = 1;
	while (doneSecondMode)
	{
		printf("\n������� ���������� ������������� (N - �� 1 �� 25): ");
		scanf("%d", &numberOfExperiments);
		if (numberOfExperiments >= 1 && numberOfExperiments <= 25)
		{
			doneSecondMode = 0;
		}
		else
		{
			printf("\n����� ������������� ����� ��������� �������� �� 1 �� 25, ���������� ��� ���!\n\n");
		}
	}
	printf("\n��������� ��������: %f\n\n", referenceValue);
	printf("���������� ���������     ����������� ������ �������     ����������� ����������\n");
	for (int i = 0; i < numberOfExperiments; i++)
	{
		pointFunc(i + 1, originalValue, referenceValue, calculationAccuracy);
	}
}
