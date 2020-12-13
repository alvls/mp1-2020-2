/*Разработать программу, позволяющую выполнять расчет значений для некоторого набора функций в заданной точке с заданной погрешностью за счет разложения этих функций в ряд Тейлора.

Программа должна работать в двух режимах :
Однократный расчет функции в заданной точке.
Серийный эксперимент.
При работе в режиме 1 пользователь должен иметь возможность :

выбрать функцию,
задать точку x, в которой необходимо вычислить значение,
задать точность вычисления(>= 0.000001),
задать число элементов ряда для выполнения расчета(N - от 1 до 1000).
Расчет оценки значения выбранной функции выполняется либо до достижения заданной точности, либо до исчерпания введенного числа слагаемых.По результатам расчета программа должна вывести следующую информацию :

эталонное значение(полученное с использованием встроенных математических функций языка программирования С),
вычисленную оценку значения функции,
разницу между оценкой и эталонным значением,
количество слагаемых, которое было вычислено.
При работе в режиме 2 пользователь должен иметь возможность :

выбрать функцию,
задать точку x, в которой необходимо вычислить значение,
задать число экспериментов(NMax - от 1 до 25).
По результатам расчета программа должна вывести следующую информацию :

эталонное значение(полученное с использованием встроенных математических функций языка программирования С),
таблицу из NMax строк со следующими столбцами : кол - во слагаемых(от 1 до NMax), вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
Технические требования :

Каждый студент должен реализовать расчет функций sin(x), cos(x), exp(x) и одной уникальной функции из списка ниже.Номер требуемой функции совпадает с номером в списке группы.
По желанию можно выбрать дополнительные функции, кроме 4 - х обязательных.
Расчет функций должен быть реализован в виде функций языка С.
В программе должен быть использован тип указатель на функцию.
В программе желательно использовать модули.
Уникальные функции :
1Квадратный корень из 1 + х - (1 + x) ^ (1 / 2)////////////////////////
2Логарифм от 1 + х - ln(1 + x)
3Тангенс - tg(x)
4Котангенс - ctg(x)
5Арксинус - arcsin(x)
6Арккосинус - arccos(x)
7Арктангенс - arctg(x)
8Арккотангенс - arcctg(x)
9Гиперболический синус - sh(x)
10Гиперболический косинус - ch(x)
11Гиперболический тангенс - th(x)
12Гиперболический котангенс - cth(x)
13Обратный гиперболический синус - arsh(x)
14Обратный гиперболический тангенс - arth(x)
15Секанс - sec(x)
16Косеканс - csc(x)*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/// <summary>
/// Включить модули /////////////////////////////////////////////////////////////////////////////////////////////////////////
/// (сначала нажать два слэша, Enter, затем долгое нажатие на клавишу со слэшем)
/// </summary>
/// 
#define MIN 0.000001
#include "Calculating.h"
void menu();
void mode1();
void mode2();
void mode(int);
//int proverka();
typedef double db;
typedef db(*operation)(db);
//db polinom();
int cleaner();
int cleaner();
db db_cleaner();
operation choice();
void printer();
void head(double, operation);


void main()
{	/// <summary>
	/// 
	/// </summary>
	/// 
	setlocale(LC_ALL, "Russian");
	printf("Вы зашли в программу, раскладывающую функцию в ряд Тейлора\n");
	menu();
	system("pause");
}
db db_cleaner()
{
	db ans;//ответ пользователя
	int clean;//чтобы корректно считать число
	do
	{
		clean = scanf("%lf", &ans);
		if ((!clean) || ans < MIN)
			printf("Ошибка ввода\n");
	} while (getchar() != '\n' && !clean && ans < MIN);
	return ans;
}
int cleaner(int min, int max)
{
	int ans;//ответ пользователя
	int clean;//чтобы корректно считать число
	do
	{
		clean = scanf("%d", &ans);
		if (!clean && (ans<min || ans>max))
			printf("Ошибка ввода\n");
	} while (getchar() != '\n' && !clean && (ans<min || ans>max));
	return ans;
}
void menu()
{
	int away;
	int ans;//ответ пользователя
	printf("\n");
	printf("Выберите режим: \n1 - Однократный расчёт функции\n");
	printf("2 - Серийный эксперимент\n");
	printf("0 - Выход из программы\n");
	ans = cleaner(0, 2);
	do {
		away = 0;
		switch (ans)
		{
		case 0:
			printf("Вы точно уверены, что хотите выйти?\n");
			printf("Если да, то нажмите 0");
			printf(", если нет, то нажмите любой другой символ\n");
			ans = cleaner(-128, 256);
			if (!ans)
				printf("Всего доброго, хорошего настроения!\n");
			else
				away++;
			break;
		case 1:
			printf("Вы выбрали первый режим\n");
			mode(1);
			//mode1();
			break;
		case 2:
			printf("Вы выбрали второй режим\n");
			mode(2);
			//mode2();
			break;
		}
	} while (away);
}
operation choice()
{
	int ans;//ответ пользователя
	db(*funk)(db)= NULL;//выбор эталонной функциич
	printf("Выберите номер функции, которую желаете вычислить:\n");
	printf("1 - Косинус\n");
	printf("2 - Синус\n");
	printf("3 - Экспонента (e^x) \n");
	printf("4 - Квадратный корень из 1+х\n");
	printf("0 - Выход в меню\n");
	ans = cleaner(0, 4);
	switch (ans)/////////////////////////////////
	{
	case 0:
		printf("\n");
		menu();
		break;
	case 1:
		printf("\n");
		funk = cos;
		break;
	case 2:
		printf("\n");
		funk = sin;
		break;
	case 3:
		printf("\n");
		funk = exp;
		break;
	case 4:
		printf("\n");
		funk = sqrt;
		break;
	}
	return funk;
}
void mode(int a)
{
	db acc;// точность вычисления (задаёт пользователь в виде величины, меньшей единицы)
	int count;//количество слагаемых
	db x;//аргумент функции
	operation funk = NULL;//получение эталонной функции для выбора программной
	db res;//результат вычисления ряда
	int nmax;//максимальное число слагаемых
	a--;
	funk = choice();
	printf("Введите точку х, в которой будет вычислена функция\n");
	x = db_cleaner();
	if (a)
	{
		printf("\n");
		printf("Введите число экспериментов\n");
		nmax = cleaner(1, 25);
		head(x, funk);
		for (count = 1; count <= nmax; count++)
		{
			res = polinom(0.0, count, x, funk);
			printer(count, x, res, funk);
		}/////////////////////
	}
	else
	{
		printf("Введите точность вычисления в виде десятичной дроби от 0.000001\n");
		acc = db_cleaner();
		printf("Введите количество слагаемых ряда в виде целого числа от 1 до 1000\n");
		count = cleaner(1, 1000);
		res = polinom(acc, count, x, funk);
		head(x, funk);
		printer(count, x, res, funk);
	}
}
db polinom(db acc, int count, db x, db(*etalon)(db))
{
	long long int i;
	long long fact = 1;//факториал
	long double Teilor;//значение ряда Тейлора
	int (*do_it)(db, db, db, db(*etalon)(db)) = proverka;
	db* elem;
	elem = (db*)malloc(sizeof(db) * (count+1));
	elem[0] = 1;
	if (etalon == cos || etalon == sin)
	{
		const db x2 = x * x;//для умножения икс^k на икс во второй
		long long n;//для факториала
		if (etalon == cos)
		{
			x = 1;
			n = 0;
		}
		else
		{
			n = 1;
		}
		Teilor = x;
		if (acc != 0.0)
			for (i = 1; i < count && proverka(acc, x, Teilor, etalon); i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (long double)fact;
			}
		else
			for (i = 1; i < count; i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (db)fact;
			}
	}
	else
	{
		Teilor = 1.0;
		const db x1 = x;
		if (etalon == exp)
		{
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++)
				{
					fact *= i;
					x *= x1;
					Teilor = Teilor + x / (long double)fact;
					//Teilor = Teilor + x / fact;
					printf("Teilor=%lf\n", Teilor);/////////////////////////////////////////////////////////////////////////
				}
			else
				for (i = 1; i <= count; i++)
				{
					//fact *= i;
					// x *= x1;
					elem[i]= (elem[i - 1] * x) / (i+1);
					//Teilor = Teilor + elem[i];//x / (long double)fact;
				}
			for(i=0;i<=count;i++)
				Teilor = Teilor + elem[i];
			free(elem);
		}
		else
		{
			long long difact = -1;//факториал удвоенного числа
			long long chet = 1;//идёт в знаменатель в виде 4 i-той степени
			long long znam;//штука, идущая в знаменатель
			long long fact2 = 1;//квадрат факториала
			long long n = 2;//для факториала
			//Full формула: ((-1)^i * (2i)! * x^i) / ((1-2i) * (i!)^2 * (4^i)), 0<=i<=n
//Small формула: (difact * x) / (znam * fact2 * chet);
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					//Teilor += (x * difact) / (znam * fact2 * chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
			else
				for (i = 1; i < count; i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					//Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
		}
	}
	return Teilor;
}
int proverka(db acc, db x, db Teilor, db(*etalon)(db))
{
	db x1 = x;
	if (etalon != sqrt)
		x1 = etalon(x);
	else
		x1 = etalon(x + 1.0);
	x1 -= Teilor;
	if (x1 < 0.0)
		x1 *= -1.0;
	//printf("x1=%lf\n", x1);
	return (x1 > acc) ? 1 : 0;
}
void printer(int count,db x, db Teilor, db(*etalon)(db))////////////////////////////////////////////сделать отступы
{
	int i;
	db module;// модуль разности эталонного значения и оценки значения функции
	int sec = count;//для расчёта отступа
	if (etalon != sqrt)
		module = etalon(x);
	else
		module = etalon(1 + x);
	module -= Teilor;
	if (module < 0.0)
		module *= -1;
	for (i = 0; i < 5; i++)
		printf(" ");
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%d", count);/////////////////////////////////сделано написание count
	for (sec = 0; sec < 6 - i; sec += 2)
		printf(" ");
	if (!(sec % 2))
		printf(" ");
	if (Teilor < 0.0)
		sec = 9;
	else
		sec = 10;
	for (i = 0; i < sec; i++)
		printf(" ");
	sec = (int)Teilor;
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%0.6lf", Teilor);/////////////////////////////////сделано написание Teilor
	for (i = 0; i < 13; i++)
		printf(" ");////////////////////////////////////////////////////сделать отступы
	printf("%-1.6lf", module);
	printf("\n");
}
void head(double x, operation funk)
{
	int i;
	printf("\nЭталонное значение, вычисленное профессионалами: ");
	printf("%lf\n\n", funk(x));
	printf("ЧИСЛО СЛАГАЕМЫХ");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("ЗНАЧЕНИЕ РЯДА");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("МОДУЛЬ РАЗНОСТИ");
	printf("\n");
	for (i = 0; i < 23; i++)
		printf(" ");
	printf("ТЕЙЛОРА");
	for (i = 0; i < 8; i++)
		printf(" ");
	printf("РЯДА И ЭТАЛОНА");
	printf("\n");
}