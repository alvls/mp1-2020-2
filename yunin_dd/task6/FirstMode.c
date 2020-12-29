#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <locale.h>
#include "FirstMode.h"

int FirstFunctionMode()
{
	int choicefun = 0, countmem = 0, i = 0;
	double arg = 0, argu, accuracy = 0.0000001, result = 0, etalon = -1000, rasn, tempmn = 0, ymno;
	printf("Добро пожаловать в первый режим.\n");
	printf("В программе доступны следующие функции:\n(1) Sin(x) \n(2) Cos(x) \n(3) Exp(x) \n(4) Coth(x) \n(5) Sh(x) \n(6) Ch(x) \n");
	printf("Введите номер функции, значение которой вы хотите рассчитать:\n");
	while ((choicefun < 1) || (choicefun > 6))
	{
		scanf_s("%d", &choicefun);
		if ((choicefun < 1) || (choicefun > 6))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	printf("Введите значение аргумента для функции (Пример: 1,54):\n");
	scanf_s("%lf", &argu);
	printf("Введите количесто членов в ряде:\n");
	while ((countmem < 1) || (countmem > 1000))
	{
		scanf_s("%d", &countmem);
		if ((countmem < 1) || (countmem > 1000))
		{
			printf("Введено неверное число!Повторите ввод.\n");
		}
	}
	printf("Введите точность вычисления для функции (Пример: 0,001):\n");
	while (accuracy < 0.000001)
	{
		scanf_s("%lf", &accuracy);
		if (accuracy < 0.000001)
		{
			printf("Введено неверное значение!Повторите ввод.\n");
		}
	}
	switch (choicefun)
	{
	case 1:
		arg = argu;
		if (fabs(argu) > 2 * M_PI)
		{
			arg = fmod(argu, 2 * M_PI);
		}
		tempmn = FirstElementFunPointer(arg, FirstElemSin);
		etalon = EtalonFunPointer(arg, EtalonSin);
		result = CalculateSin(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Sin(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", argu);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 2:
		arg = argu;
		if (fabs(argu) > 2 * M_PI)
		{
			arg = fmod(argu, 2 * M_PI);
		}
		tempmn = FirstElementFunPointer(arg, FirstElemCos);
		etalon = EtalonFunPointer(arg, EtalonCos);
		result = CalculateCos(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Cos(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", argu);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 3:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemExp);
		etalon = EtalonFunPointer(arg, EtalonExp);
		result = CalculateExp(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Exp(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 4:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemCoth);
		etalon = EtalonFunPointer(arg, EtalonCoth);
		result = CalculateCoth(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Coth(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 5:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemSh);
		etalon = EtalonFunPointer(arg, EtalonSh);
		result = CalculateSh(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Sh(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 6:
		arg = argu;
		tempmn = FirstElementFunPointer(arg, FirstElemCh);
		etalon = EtalonFunPointer(arg, EtalonCh);
		result = CalculateCh(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Ch(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	}
	rasn = fabs(result - etalon);
	printf("\t\t\t\t\tТаблица выходных данных\n");
	printf("(1) Вычисленное эталонное значение = %lf\n", etalon);
	printf("(2) Вычисленный результат = %lf\n", result);
	printf("(3) Разность между эталонным значением и вычесленным значением = %lf\n", rasn);
	printf("(4) Количество членов, используемых при разложении в формуле Тейлора = %d\n", i);
	return 1;
}

double FirstElementFunPointer(double x, double(*foo)(double))
{
	double firstel;
	firstel = foo(x);
	return firstel;
}

double FirstElemSin(double x)
{
	return x;
}

double FirstElemSh(double x)
{
	return x;
}

double FirstElemCh(double x)
{
	return 1;
}

double FirstElemCos(double x)
{
	return 1;
}

double FirstElemExp(double x)
{
	return 1;
}

double FirstElemCoth(double x)
{
	return (1 / x);
}

double EtalonFunPointer(double x, double(*foo)(double))
{
	double etalon;
	etalon = foo(x);
	return etalon;
}

double EtalonSin(double x)
{
	double arg, etalon;
	etalon = sin(x);
	return etalon;
}

double EtalonCh(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	temp2 = exp(-x);
	etalon = ((temp1 + temp2) / 2);
	return etalon;
}

double EtalonSh(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	temp2 = exp(-x);
	etalon = (temp1 - temp2) / 2;
	return etalon;
}

double EtalonCos(double x)
{
	double arg, etalon;
	etalon = cos(x);
	return etalon;
}

double EtalonExp(double x)
{
	double etalon;
	etalon = exp(x);
	return etalon;
}

double EtalonCoth(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	temp2 = exp(-x);
	etalon = ((temp1 + temp2) / (temp1 - temp2));
	return etalon;
}

double CalculateExp(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, ymno;
	long j;
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionExp(x, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}

double MnozhitelFunctionExp(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (x / i);
	}
	return vivod;
}

double CalculateSh(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = x;
	res = arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionSh(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}

double MnozhitelFunctionSh(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (((x * x)) / (2 * i * (2 * i + 1)));
		return vivod;
	}
}

double CalculateSin(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = x;
	res = arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionSin(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionSin(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = ((-(x * x)) / (2 * i * (2 * i + 1)));
		return vivod;
	}
}

double CalculateCos(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = x;
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionCos(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionCos(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = ((-(x * x)) / (2 * i * (2 * i - 1)));
	}
	return vivod;
}

double CalculateCh(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = x;
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionCh(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionCh(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (((x * x)) / (2 * i * (2 * i - 1)));
	}
	return vivod;
}

double Bink(int n, int k)
{
	double result = 1;
	for (unsigned i = 1; i <= n - k; i++)
		result *= (double)(k + i) / (double)(i);
	return result;
}

double Bernulli(int n)
{
	if (n > 255)
		n = 255;
	double ber[256] = { 0 };
	ber[0] = 1.;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			ber[i] += Bink(i + 1, j + 1) * ber[i - j];
		ber[i] *= (-1.) / (double)(i + 1);
	}
	return ber[n];
}

double CalculateCoth(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res = 0, arg, fact = 1, res1 = 0, ymno1, secondtemp, firsttemp;
	int j;
	arg = x;
	res = 1 / arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = (*i);
		double berni = Bernulli(2 * j) / Bernulli(2 * j - 2);
		if (i == 1)
		{
			firsttemp = 1;
		}
		else
		{
			firsttemp = arg * arg;
		}
		ymno1 = (1.0) / (2 * j * (2 * j - 1));
		fact *= ymno1;
		secondtemp = pow(4, j);
		res1 = berni * fact * secondtemp * arg * firsttemp;
		res += res1;
	}
	return res;
}