#define _CRT_SECURE_NO_WARNINGS
#define PI 3.1415926535
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
	double res; //значение
	double accuracy; //точность
	double reference; //эталон
	double differ; //разность
	int n; //количество элементов в разложении
}data_f;

void print_functions()
{
	printf("Выберите функцию:\n");
	printf("1)Sin(x)\n");
	printf("2)Cos(x)\n");
	printf("3)Exp(x)\n");
	printf("4)Arctg(x)\n");
	printf("5)Arcctg(x)\n");
}

void printf_result(data_f result)
{
	printf("Вычисленное значение: %lf\n", result.res);
	printf("Эталонное значение: %lf\n", result.reference);
	printf("Разница: %lf\n", result.differ);
	printf("Количество слагаемых: %d\n", result.n);
}

data_f TSin(double x, double accurancy, int n)
{
	data_f function;
	int i = 0;
	double reference = sin(x);
	double result = x;
	double temp = x;
	int count = 1;

	for (i = 1; fabs(result - reference) > accurancy && i < n; i++)
	{
		temp *= (-1.0) * (x * x) / ((2 * i) * (2 * i + 1));
		result += temp;
		count++;
	}
	function.res = result;
	function.differ = fabs(result - reference);
	function.accuracy = accurancy;
	function.reference = reference;
	function.n = count;
	return function;
}

data_f TCos(double x, double accurancy, int n)
{
	data_f function;
	int i = 0;
	double reference = cos(x);
	double result = 1;
	double temp = 1;
	int count = 1;

	for (i = 1; fabs(result - reference) > accurancy && i < n; i++)
	{
		temp *= (-1.0) * (x * x) / (2 * i * (2 * i - 1));
		result += temp;
		count++;
	}
	function.res = result;
	function.differ = fabs(result - reference);
	function.accuracy = accurancy;
	function.reference = reference;
	function.n = count;
	return function;
}

data_f TExp(double x, double accurancy, int n)
{
	data_f function;
	int i = 0;
	double reference = exp(x);
	double result = 1;
	double temp = 1;
	int count = 1;

	for (i = 1; fabs(result - reference) > accurancy && i < n; i++)
	{
		temp *= 1.0 * x / i;
		result += temp;
		count++;
	}
	function.res = result;
	function.differ = fabs(result - reference);
	function.accuracy = accurancy;
	function.reference = reference;
	function.n = count;
	return function;
}

data_f TArctg(double x, double accurancy, int n)
{
	data_f function;
	int i = 0;
	double reference = atan(x);
	double result = x;
	double temp = x;
	int count = 1;

	for (i = 1; fabs(result - reference) > accurancy && i < n; i++)
	{
		temp *= (-1.0) * (x * x) * (2 * (i - 1) + 1) / (2 * i + 1);
		result += temp;
		count++;
	}
	function.res = result;
	function.differ = fabs(result - reference);
	function.accuracy = accurancy;
	function.reference = reference;
	function.n = count;
	return function;
}

data_f TArcctg(double x, double accurancy, int n)
{
	data_f function = TArctg(x, accurancy, n); //разложение арктангенса для данной точки
	double reference = PI / 2 - atan(x); //эталон
	double result = PI / 2 - function.res; //приведение значения арктангенса к арккотангенсу
	function.res = result; //значение арккотангеса 
	function.differ = fabs(result - reference); //разница с эталонным
	function.reference = reference; //эталон
	return function;
}


data_f(*select())() //выбор функции
{
	int choice;
	data_f(*funct[])(double x, double accurancy, int n) = { TSin, TCos, TExp, TArctg, TArcctg };

	print_functions();
	scanf_s("%d", &choice);
	while (choice > 5 && choice < 1)
	{
		printf("Ошибка выбора функции, попробуйте еще раз\n");
		scanf_s("%d", &choice);
	}
	return funct[choice - 1];
}

void single_mode()
{

	double x; //точка
	double accurancy; //точность
	int n; //количество слагаемых
	data_f result; // структура с результатом измерений
	data_f(*choice)();//содержит ссылку на функцию

	choice = select();
	if (choice == TArctg || choice == TArcctg)
	{
		printf("Точка в которой нужно вычислить значение(|x|<=1): ");
		scanf_s("%lf", &x);
		while (x < -1 || x>1)
		{
			printf("|x|<=1, попробуйте еще раз:");
			scanf_s("%lf", &x);
		}
	}
	else
	{
		printf("Точка в которой нужно вычислить значение: ");
		scanf_s("%lf", &x);
	}
	printf("\nТочность (>= 0.000001)(через запятую): ");
	scanf_s("%lf", &accurancy);
	while (accurancy < 0.000001)
	{
		printf("Слишком маленькая точность, попробуйте еще раз:");
		scanf_s("%lf", &accurancy);
	}
	printf("\nЧисло элементов ряда (N - от 1 до 1000): ");
	scanf_s("%d", &n);
	while (n < 1 || n>1000)
	{
		printf("Ошибка выбора числа элементов ряда, попробуйте еще раз:");
		scanf_s("%d", &n);
	}
	result = choice(x, accurancy, n);
	printf_result(result);
}


void serial_mode()
{
	double x;
	int i = 0;
	int n;
	data_f result; // структура с результатом измерений
	data_f(*choice)();//содержит ссылку на функцию

	choice = select();
	if (choice == TArctg || choice == TArcctg)
	{
		printf("Точка в которой нужно вычислить значение(|x|<=1): ");
		scanf_s("%lf", &x);
		while (x < -1 || x>1)
		{
			printf("|x|<=1, попробуйте еще раз:");
			scanf_s("%lf", &x);
		}
	}
	else
	{
		printf("Точка в которой нужно вычислить значение: ");
		scanf_s("%lf", &x);
	}
	printf("\nЧисло элементов ряда (N - от 1 до 25): ");
	scanf_s("%d", &n);
	while (n < 1 || n>25)
	{
		printf("Ошибка выбора числа элементов ряда, попробуйте еще раз:");
		scanf_s("%d", &n);
	}
	printf("N \t\t\t");
	printf("Значение функции\t\t\t\t");
	printf("Разница между эталонным значением\n");
	for (i = 1; i <= n; i++)
	{
		result = choice(x, 0.00000000000000001, i); // 2 параметр - точность, чтобы выполнилось условие fabs(result - reference) > accurancy
		printf("%-2d\t %30.7lf           %40.7lf\n", i, result.res, result.differ);
	}

}

void main()
{
	setlocale(LC_ALL, "Russian");
	int mode = 3;

	while (mode != 0)
	{
		printf("Выберите режим работы:\n");
		printf("1)Однократный расчет функции в заданной точке\n");
		printf("2)Серийный эксперимент\n");
		scanf_s("%d", &mode);
		while (mode != 1 && mode != 2)
		{
			printf("Ошибка выбора режима, попробуйте еще раз:");
			scanf_s("%d", &mode);
		}
		switch (mode)
		{
		case 1:
			single_mode();
			break;
		case 2:
			serial_mode();
			break;
		}
		printf("Хотите изменить режим? 1-Да 0-Нет\n");
		scanf_s("%d", &mode);
		while (mode != 1 && mode!=0)
		{
			printf("Ошибка выбора попробуйте еще раз\n");
			scanf_s("%d", &mode);
		}
	}
	system("pause");
}