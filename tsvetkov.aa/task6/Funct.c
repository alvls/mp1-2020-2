#include "Funct.h"
#include <math.h>
double siny(double x, int i)//слагаемое для синуса
{
	double y;
	y = (pow(-1, i) * (pow(x, 2 * i + 1) / factorial(2 * i + 1)));
	return y;
}
double cosy(double x, int i)//слагаемое для косинуса
{
	double y;
	y = (pow(-1, i) * (pow(x, 2 * i) / factorial(2 * i)));
	return y;
}
double expy(double x, int i)//слагаемое для exp
{
	double y;
	y = (pow(x, i) / factorial(i));
	return y;
}
double sinhy(double x, int i)//слагаемое для гиперб.синуса
{
	double y;
	y = (pow(x, 2 * i + 1) / factorial(2 * i + 1));
	return y;
}
double factorial(int n)//функция вычисления факториала,которая понадобится для рядов тефлора
{
	if (n == 0 || n == 1) return 1;
	return (n * factorial(n - 1));
}
void funct(int m, int n, double t, int k, double x, double kx, double (*fun)(double, int))//рассчет значения функции в точке x, используется указатель на функции слагаемых указанные выше, в зависимости от выбора функции передается определенная функция подсчета слагаемого в формуле тейлора
{//m-режим,n-кол-во слагаемых,t-заданная точность,k-порядок t,x-точка в которой надо вычислить
	double* ch;//массив для режима 2,записывает значение функции на каждом шаге



	ch = (double*)malloc(n * sizeof(double));

	double  y = 0, yx = 0;//y-значение функции по тейлору,yx-значение члена ряда тейлора(слагаемое)
	int i, j = 0;//счетчики,j- подсчитывает сколько было вычеслено слагаемых в режиме 1



	for (i = 0; i < n; i++)
	{
		yx = fun(x, i);
		if (m == 2)
		{
			y = y + yx;
			ch[i] = y;

		}

		if (m == 1)
		{

			if (fabs(yx) < t)
				break;
			else
			{
				y = y + yx;
				j++;
			}
		}

	}

	if (m == 2)
		mode2(ch, kx, n);
	if (m == 1)
		mode1(kx, y, j, n, k);
	if (m == 2)
		free(ch);
}