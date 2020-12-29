#define _USE_MATH_DEFINES
#define COUNT_NUM_FOR_BERNULLI 1000
//Подключение библиотек
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
//попробовать (1+x)^1/2,tg,ctg,tan,cot
			//Главная функция


void main()
{
	int choice = 0, vivod = 0;
	setlocale(LC_ALL, "Rus");
	//Функция, которая реализует инструкцию.
	//Функция, которая выводит ошибку.(проработать систему ошибок) не успел :(
	vivod = Menu();
	if (vivod == 1)
	{
		Instraction();
		system("pause");
		system("cls");
		printf("Теперь после ознакомления с инструкцией по использованию программы давайте приступать к работе!\n");
		choice = ChoiceMode();
	}
	else if (vivod == 2)
	{
		choice = ChoiceMode();
	}
	else
	{
		printf("Спасибо, за пользование моей программой. До свидания!\n");
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
	printf("\n\n\n\tПрограмма завершила рассчёт функции!\n");
	system("pause");
	system("cls");
	choice = -1;
	printf("Введите \"1\", если вы хотите продолжить работать с программой.\nВведите \"0\", если хотите завершить работу.\n");
	while ((choice < 0) || (choice > 1))
	{
		scanf_s("%d", &choice);
		if ((choice < 0) || (choice > 1))
		{
			printf("Такой функции не предоставлено, введите \"1\" - для продолжения работы программы, \"0\" - для завершения работы программы.\n");
		}
	}
	if (choice == 1)
	{
		system("cls");
		main();
	}
	else
	{
		printf("Спасибо, за пользование моей программой. До свидания!\n");
		system("pause");
	}
}