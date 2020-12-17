#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "Types.h"
#include "Calculating.h"
db db_cleaner(db min)
{
	db ans;//ответ пользователя
	int clean;//чтобы корректно считать число
	do
	{
		clean = scanf("%lf", &ans);
		if ((!clean) || ans < min)
			printf("Ошибка ввода\n");
	} while (getchar() != '\n' || !clean || ans < min);
	return ans;
}
int cleaner(int min, int max)
{
	int ans;//ответ пользователя
	int clean;//чтобы корректно считать число
	do
	{
		clean = scanf("%d", &ans);
		if (!clean || ans<min || ans>max)
			printf("Ошибка ввода\n");
	} while (getchar() != '\n' || !clean || ans<min || ans>max);
	return ans;
}
operation choice()
{
	int ans;//ответ пользователя
	db(*funk)(db) = NULL;//выбор эталонной функциич
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
		main();
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
	sum res;//результат вычисления ряда
	int nmax;//максимальное число слагаемых
	a--;
	if (a)
		printf("\nВы выбрали второй режим\n");
	else
		printf("\nВы выбрали первый режим\n");
	funk = choice();
	printf("Введите точку х, в которой будет вычислена функция\n");
	if (funk == sqrt)
		x = db_cleaner(-1.0);
	else
		x = db_cleaner(-10000000.0);
	if (a)
	{
		printf("\n");
		printf("Введите число экспериментов\n");
		nmax = cleaner(1, 25);
		head(x, funk);
		for (count = 1; count <= nmax; count++)
		{
			res = polinom(0.0, count, x, funk);
			printer(count, x, res.s, funk);
		}
	}
	else
	{
		printf("Введите точность вычисления в виде десятичной дроби от 0.000001\n");
		acc = db_cleaner(-100.0);
		printf("Введите количество слагаемых ряда в виде целого числа от 1 до 1000\n");
		count = cleaner(1, 1000);
		res = polinom(acc, count, x, funk);
		head(x, funk);
		printer(res.count, x, res.s, funk);
	}
}