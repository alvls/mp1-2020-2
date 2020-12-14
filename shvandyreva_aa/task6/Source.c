#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

char* menu[] = { "МЕНЮ:","1 - Режим 1", "2 - Режим 2" };
char* function[] = {"1 - sin(x)","2 - cos(x)","3 - exp(x)","4 - ch(x)"};

void privetstvie()
{
	printf("Добро Пожаловать в программу, позволяющую выполнять расчет значений для некоторого набора функций в заданной точке с заданной погрешностью за счет разложения этих функций в ряд Тейлора.");
	printf("\n\nЭта программа имеет два режима работы.");
	printf("\n\nПо результатам расчета при работе в Режиме 1 программа выведет следующую информацию:\n - эталонное значение (полученное с использованием встроенных математических функций языка программирования С),\n - вычисленную оценку значения функции,\n - разницу между оценкой и эталонным значением,\n - количество слагаемых, которое было вычислено.");
	printf("\n\nПо результатам расчета при работе в Режиме 2 программа выведет следующую информацию:\n - эталонное значение (полученное с использованием встроенных математических функций языка программирования С),\n - таблицу из NMax строк со следующими столбцами: кол - во слагаемых(от 1 до NMax), вычисленную оценку значения функции, разницу между оценкой и эталонным значением.");
	printf("\n");
}
void menu_regime() //меню режимов
{
	int menu_size = sizeof(menu) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", menu[i]);
}
int regime_choice() //выбор из режима + проверка 
{
	int choice;
	printf("\nКаким режимом желаете воспользоваться?   ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 3) //проверка правильности введенных пользователем данных
	{
		printf("\nВы неправильно ввели номер меню, введите, пожалуйста, ещё раз:   ");
		scanf_s("%d", &choice);
	}
		printf("\nВы выбрали <%s>\n\n", menu[choice]);
	return choice;
}
void menu_function() //меню функций
{
	int menu_size = sizeof(function) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", function[i]);
}
int function_choice() //выбор функции + проверка 
{
	int choice;
	printf("\nВыберите функцию:   ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 4) //проверка правильности введенных пользователем данных
	{
		printf("\nФункции с таким номером нет в меню, пожалуйста, введите номер ещё раз:   ");
		scanf_s("%d", &choice);
	}
		printf("\nВы выбрали <%s>\n\n", function[choice-1]);
	return choice;
}
//--------------------------функции-----------------------------//
void sinus(double x, float E, long int count)
{
	int i;
	double etalon = sin(x);
	double function = x;
	double slagaemoe = x;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe = (-1) * slagaemoe * x * x / ((2 * i - 1) * (2 * i - 2));
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void cosinus(double x, float E, long int count)
{
	int i;
	double etalon = cos(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) >= E); i++)
	{
		slagaemoe = (-1) * slagaemoe * x * x / ((2 * i - 2) * (2 * i - 3));
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void exponenta(double x, float E, long int count)
{
	int i;
	double etalon = exp(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe *=  x / (i - 1);
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void coshinus(double x, float E, long int count)
{
	int i;
	double etalon = cosh(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe *= (x / (i - 1));
		if (i % 2 == 1)
			function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
//-------------------------режимы-------------------------------//
void regime_one(void(*f)(double, float, int), double x, double etalon)
{
	float E;
	int k;
	printf("\nВведите точность вычисления (>= 0,000001):   ");
	scanf_s("%f", &E);
	printf("\nВведите количество слагаемых от 1 до 1000:   ");
	scanf_s("%d", &k);
	printf("\nЭталонное значение:   %lf\n", etalon);
	printf("\nКол-во слагаемых   Вычисленная оценка функции   Разница между оценкой и эталоном\n");
	f(x, E, k);
	printf("\nДо свидания!\n");
}
void regime_two(void(*f)(double, float, int), double x, double etalon)
{
	int experience, i;
	printf("\nВведите количество экспериментов от 1 до 25:   ");
	scanf_s("%d", &experience);
	printf("\nЭталонное значение:   %lf\n", etalon);
	printf("\nКол-во слагаемых   Вычисленная оценка функции   Разница между оценкой и эталоном\n");
	for (i = 0; i < experience; i++)
		f(x, -2 , i + 1); //отрицательная точность, чтобы выводились все слагаемые 
	printf("\nДо свидания!\n");
}

void main()
{
	setlocale(LC_ALL, "rus");
	int choice_function, regime; //номер выбранной функции и режим
	double x, exact; //точка Х и точность
	double etalon;

	double (*function[5]) (double, float, long int);
	function[0] = sinus;
	function[1] = cosinus;
	function[2] = exponenta;
	function[3] = coshinus;

	privetstvie();
	menu_regime();
	regime = regime_choice();
	menu_function();
	choice_function = function_choice();
	printf("\nВведите x:   ");
	scanf_s("%lf", &x);
	
	switch (choice_function)
	{
	case 1:
		function[0];
		x = x / 180 * M_PI;
		etalon = sin(x);
		break;
	case 2:
		function[1];
		x = x / 180 * M_PI;
		etalon = cos(x);
		break;
	case 3:
		function[2];
		etalon = exp(x);
		break;
	case 4:
		function[3];
		etalon = cosh(x);
		break;
	}
	if (regime == 1)
		regime_one(function[choice_function - 1], x, etalon);
	else
		regime_two(function[choice_function - 1], x, etalon);
	system("pause");
}