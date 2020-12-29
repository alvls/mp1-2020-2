#include <stdio.h>  
#include <locale.h>
#include <math.h>
#include "Funct.h"


int mode()//функция выбора режима работы
{
	int n;
	printf("Выберите режим работы:\n");
	printf("1.Однократный расчет функции в заданной точке.\n2.Серийный эксперимент.\n0.Выйти.\n");
	scanf_s("%d", &n);
	return n;
}
int choice()//выбор функци
{
	int n;
	printf("Выберите фунцкию:\n");
	printf("1.sin(x).\n2.cos(X)\n3.exp(x)\n4.sh(X)\n");
	scanf_s("%d", &n);
	return n;


}

void mode2(double ch[], double kx,int n)//вывод на консоль информации в режиме 2
{
	char c = ' ';
	double x;
	int i;
	printf("Эталонное значение = %.15lf\n", kx);
	printf("Коли-во слагаемых.    Оценка значения функции.    Разница между оценочным и эталонным значением функции.\n");
	for (i = 0; i < n; i++)
	{
		x = fabs(kx - ch[i]);
		printf("%-21d %-27.15lf %.15lf\n", i + 1, ch[i], x);
	}
}
void mode1(double kx, double y, int j, int n,int k)//вывод на консоль информации в режиме 1
{
	if (j == n)
		printf("Рассчет значиний выполнился до исчерпания введенного вами числа слагаемых.\n");
	if (j!=n)
		printf("Рассчет значиний выполнился до достижения заданной вами точности.\n");
	
	printf("Эталонное значение = %.*lf\n",k+1, kx);
	printf("Вычисленная оценка значений = %.*lf\n",k+1, y);
	printf("Разница между оценочным и эталонным значением функции = %.*lf\n", k+3,fabs(y - kx));
	printf("Количество вычисленных слагаемых = %d\n", j);



}
int menu()//выбор дальнейшего действия после подсчета функции
{
	int n;
	printf("Выберите дальнейшее действие\n");
	printf("1.Посчитать новую функцию.\n0.Выйти\n");
	scanf_s("%d", &n);
	return n;

}
void clean()//очистка потока воода
{

	int c;
	do
	{
		c = getchar();
	} while ((c != '\n') && (c != EOF));

}




void main()
{
l:
	
	
	setlocale(LC_ALL, "Russian");
	double kx = 0;//эталонное значение
	double t=0,tmp;//t-переменная для задания точности,tmp-временная переменная
	int m, r, n, k = 0;//m-режим работы,r-выбор функции,n-число слагаемых,k-порядок числа t(точности)
	double x=0;//вводимое x

	m = mode();//выбор режима
	if (m == 0)
		return;
	r = choice();//выбор функции
	
	
	if (m== 1)
	{
		printf("Задайте точность вычислений >= 0.000001\n");
		scanf_s("%lf", &t);
		clean();
		tmp = t;
		while (tmp != 1)//подсчет порядка t,используется для более наглядного вывода результатов на консоль в режиме 1(кол-во знаков после запятой)
		{
			tmp = tmp * 10;
			k++;
		}
		
	}
	printf("Задайте число элементов ряда для выполнения рассчетов\n");
	scanf_s("%d", &n);
	printf("Введите значение x\n");
	scanf_s("%lf", &x);

	switch (r)//вызов функции рассчета значений 
	{
	case 1:
		kx = sin(x);
		funct(m, n, t, k,x, kx , siny);
		break;
	case 2:
		kx = cos(x);
		funct(m, n, t, k,x,kx,cosy);
		break;
	case 3:
		kx = exp(x);
		funct(m, n, t, k,x,kx,expy);
		break;
	case 4:
		kx= (exp(x) - exp(-x)) / 2;
		funct(m, n, t, k,x,kx,sinhy);
		break;



	}


	if (menu() == 1)//конечное меню предлагающее выйти либо начать рассчет новой функции
		goto l;
	else
		return;
}

