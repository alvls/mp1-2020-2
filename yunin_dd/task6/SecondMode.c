#define _USE_MATH_DEFINES
#define COUNT_NUM_FOR_BERNULLI 51
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <locale.h>
#include "FirstMode.h"
#include "SecondMode.h"

long double Bernulli_numbers[COUNT_NUM_FOR_BERNULLI] = { 1, 0.5 , 0.166666,  0.0,  -0.033333333 , 0,  0.0238095, 0, -0.0333333, 0, 0.0757575,  0,  -0.253113,  0, 1.1666666, 0,  -7.092156, 0, 54.9711779,  0,
	-529.12424,  0,  6192.12318,  0, -86580.25311, 0,  1425517.166,  0,  -27298231.067,  0, 601580873.900, 0,  -15116315767.09, 0,  429614643061.16, 0,  -13711655205088.332,  0,  488332318973593.2,  0,
	 -19296579341940068.1486,  0,  841693047573682615,  0, -40338071854059455413.07, 0, 2115074863808199160560.14,  0,  -120866265222965259346027.31,  0, 7500866746076964366855720.07 };


int CalculateAndPrintDataForCoth(double etal, double* tempmno, int countexperim, double x)
{
	long i, j = 1;
	double arg, res = 0, ymno, rasn, berni, res1 = 0, firsttemp, fact = 1, secondtemp;
	arg = x;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; i < countexperim; i++)
	{
		if (i == 0)
		{
			res = *tempmno;
			rasn = fabs(res - etal);
			printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
			continue;
		}
		int k = 2 * i;
		berni = Bernulli_numbers[k];
		if (i == 1)
		{
			firsttemp = 1;
		}
		else
		{
			firsttemp = arg * arg;
		}
		ymno = (1.0) / (2 * j * (2 * j - 1));
		fact *= ymno;
		secondtemp = pow(4, j);
		res1 = berni * fact * secondtemp * arg * firsttemp;
		res += res1;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForCos(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	arg = x;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionCos(arg, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForExp(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionExp(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForCh(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionCh(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForSh(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double  res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; i < countexperim; i++)
	{
		ymno = MnozhitelFunctionSh(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.10lf|%50.10lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForSin(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	arg = x;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionSin(arg, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.10lf|%50.10lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;

}
int SecondFunctionMode()
{
	int choicefunction = 0, countexp = 0, vivod;
	double arg = 0, argu, tempmn, etalon;
	printf("Добро пожаловать во второй режим!\n");
	printf("В программе доступны следующие функции:\n(1) Sin(x) \n(2) Cos(x) \n(3) Exp(x) \n(4) Coth(x) \n(5) Sh(x) \n(6) Ch(x) \n");
	printf("Введите номер функции, значение которой вы хотите рассчитать:\n");
	while ((choicefunction < 1) || (choicefunction > 6))
	{
		scanf_s("%d", &choicefunction);
		if ((choicefunction < 1) || (choicefunction > 6))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	printf("Введите значение аргумента для функции:\n");
	scanf_s("%lf", &argu);
	printf("Введите количество экспериментов, которое хотите провести:\n");
	while ((countexp < 1) || (countexp > 25))
	{
		scanf_s("%d", &countexp);
		if ((countexp < 1) || (countexp > 25))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	switch (choicefunction)
	{
	case 1:
		arg = argu;
		if (fabs(argu) > 2 * M_PI)
		{
			arg = fmod(argu, 2 * M_PI);
		}
		tempmn = FirstElementFunPointer(arg, FirstElemSin);
		etalon = EtalonFunPointer(arg, EtalonSin);
		vivod = CalculateAndPrintDataForSin(etalon, &tempmn, countexp, arg);
		break;
	case 2:
		arg = argu;
		if (fabs(argu) > 2 * M_PI)
		{
			arg = fmod(argu, 2 * M_PI);
		}
		tempmn = FirstElementFunPointer(arg, FirstElemCos);
		etalon = EtalonFunPointer(arg, EtalonCos);
		vivod = CalculateAndPrintDataForCos(etalon, &tempmn, countexp, arg);
		break;
	case 3:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemExp);
		etalon = EtalonFunPointer(arg, EtalonExp);
		vivod = CalculateAndPrintDataForExp(etalon, &tempmn, countexp, arg);
		break;
	case 4:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemCoth);
		etalon = EtalonFunPointer(arg, EtalonCoth);
		vivod = CalculateAndPrintDataForCoth(etalon, &tempmn, countexp, arg);
		break;
	case 5:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemSh);
		etalon = EtalonFunPointer(arg, EtalonSh);
		vivod = CalculateAndPrintDataForSh(etalon, &tempmn, countexp, arg);
		break;
	case 6:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemCh);
		etalon = EtalonFunPointer(arg, EtalonCh);
		vivod = CalculateAndPrintDataForCh(etalon, &tempmn, countexp, arg);
		break;
	}
	return 1;
}