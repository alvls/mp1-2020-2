//Определить, каково взаимное расположение двух окружностей на плоскости с заданными координатами центров и радиусами. 
//Исходные данные должны вводиться пользователем. Результат программа должна выводить на экран.

//Окончательная версия программы

#include <stdio.h>
#include <math.h> //Как я понял, нужна для извлечения квадратного корня

void main()
{
	//Объявление переменных

	double xone, yone, rone;//x1, y1 - координаты центра окружности 1; r1 - радиус данной окружности
	double xtwo, ytwo, rtwo;//x2, y2 - координаты центра окружности 2; r2 - радиус данной окружности
	double cline; //длина линии, соединяющей центры окружностей
	int pos; //позиция относительно других, будет пояснено в середине кода
	//double pr;//переменная для доп проверок и просмотра промежуточных значений - не для релиза
	
	//Кладу в значение радиусов отрицательное число, чтобы программа работала исправно на моменте сбора положительных значений этих переменных

	rone = -10;
	rtwo = -11;

	//Сбор нужной информации

	printf("Warning! 1.5 != 1,5\n\n");

	printf("Enter the coordinates of the center of the first circle (x1;y1)\n\t"); //Введите координаты центра первой окружности
	scanf_s("%lf %lf",&xone,&yone);
	
	
	while (rone <= 0) //программа ожидает значение радиуса, большего чем 0
		{
			printf("Enter the radius of the first circle (necessarily greater than zero)\n\t");
			scanf_s("%lf", &rone);
		}
	
	printf("Enter the coordinates of the center of the second circle (x2;y2)\n\t"); //Введите координаты центра второй окружности
	scanf_s("%lf %lf",&xtwo,&ytwo);
	
	while (rtwo <= 0) //программа ожидает значение радиуса, большего чем 0
		{
			printf("Enter the radius of the second circle (necessarily greater than zero)\n\t");
			scanf_s("%lf", &rtwo);
		}
	
	//Обработка полученной информации
	cline = sqrt((xone - xtwo) * (xone - xtwo) + (yone - ytwo)*(yone - ytwo));

	//Данный блок нужен чисто для моего удобства - не для релиза
	
	system("cls"); //Очистка командной строки, чтобы вывести значения всех переменных без захламлённого экрана 
	
	printf("Entered variable values\n"); //Введённые значения переменных
	printf("x1 = %lf\n", xone);
	printf("y1 = %lf\n", yone);
	printf("r1 = %lf\n", rone);
	printf("x2 = %lf\n", xtwo);
	printf("y2 = %lf\n", ytwo);
	printf("r2 = %lf\n", rtwo);
	printf("Length of the line connecting the centers of the circles = %lf\n\n", cline); //Длина линии, соединяющей центры окружностей

	//Всевозможное расположение окружностей: 
	// pos=1 - совпадают ( значения соответствующих переменных равны ) 
	// pos=2 - пересекаются в одной точке внешним образом ( cline=r1+r2 )
	// pos=3 - пересекаются в одной точке внутренним образом ( cline=|r1-r2|; Модуль потому что мы из большего вычитаем меньшее, но какой из радиусов будет больше заранее неизвестно )
	// pos=4 - не пересекаются вовсе, ибо они расположены в разных местах относительно друг друга ( cline>r1+r2 )
	// pos=5 - одна окружность внутри другой ( cline<|r1-r2|; Модуль аналогично; Су)
	// pos=6 - пересекаются в двух точках (можно вывести как оставшийся вариант, что я и сделаю благодаря переменной pos; на всякий случай условие: |r1-r2|<cline<r1+r2)

	pos = 6; //Это оставшийся вариант после проверки всех предыдущих возможных позиций, если pos останется равна 6, то окружности пересекаются
		
	if ((xone == xtwo) && (yone == ytwo) && (rone == rtwo))
	{
		pos = 1;
	}
	
	//Так как модуль работает только для int, то придётся сделать двойную развилку

	if (rone > rtwo)
	{
		if (cline == (rone - rtwo))
		{
			pos = 3;
		}
		if (cline < (rone - rtwo))
		{
			pos = 5;
		}
	}
	if (rone < rtwo)
	{
		if (cline == (rtwo - rone))
		{
			pos = 3;
		}
		if (cline < (rtwo - rone))
		{
			pos = 5;
		}
	}

	if (cline == (rone + rtwo))
	{
		pos = 2;
	}
	if (cline > (rone + rtwo))
	{
		pos = 4;
	}

	//printf("pos = %d\n",pos); //не для релиза

	switch (pos)
	{
	case 1:
	{
		printf("The circles are equal"); //Окружности совпадают
		break;
	}
	case 2:
	{
		printf("Circles intersect at one point externally"); //Окружности пересекаются в одной точке внешним образом
		break;
	}
	case 3:
	{
		printf("Circles intersect at one point internally"); //Окружности пересекаются в одной точке внутренним образом
		break;
	}
	case 4:
	{
		printf("The circles are located in different places relative to each other"); //Окружности расположены в разных местах относительно друг друга
		break;
	}
	case 5:
	{
		printf("One circle inside another circle"); //Одна окружность внутри другой
		break;
	}
	case 6:
	{
		printf("The circles intersect at two points"); //Окружности пересекаются в двух точках
		break;
	}
	}
	
	scanf_s("%lf",&xone); //Можно было написать и короче, зато на этом коде я закрепил уже пройденный материал
}
