/*#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	const double THICKNESSDVP = 0.005, THICKNESSDSP = 0.015, THICKNESSTREE = 0.01, RASBETWEENSHELF = 0.4;
	/*
	* THICKNESSDVP - Толщина ДВП.
	* THICKNESSDSP - Толщина ДСП.
	* THICKNESSTREE - Толщина дерева.
	* RASBETWEENSHELF - Расстояние между полками.
	*/
	/*const long COUNTSIDEWALL = 2, COUNTULWALL = 2;
	/*
	* COUNTSIDEWALL - Количество боковых стен;
	* COUNTULWALL - Количество верхних и нижних стен;
	*/
	//const long DENSITYDSP = 720, DENSITYDVP = 820, DENSITYTREE = 810;
	/*
	* DENSITYDSP - Плотность ДСП.
	* DENSITYDVP - Плотность ДВП.
	* DENSITYTREE - Плотность Дерева.
	*/
	//double h, w, d;
	/*
	*h - Высота шкафа, которая задаётся пользователем.
	*w - Ширина шкафа, которая задаётся пользователем.
	*d - Глубина полок, которая задаётся пользователем.
	*/
	int coutshelf,a;
	/*
	*Число полок в шкафу.
	*/
	//double vdsp, vdvp, vtree, itogmass, vdsp1, vdsp2, vdsp3;
	/*
	* vdsp - Объём материалов из ДСП.
	* vdvp - Объём материалов из ДВП.
	* vtree - Объём материалов из Дерева.
	* itogmass - Общая масса шкафа.
	* vdsp1 - Объём полок.
	* vdsp2 - Объём верхней и нижней полки.
	* vdsp3 - Объём боковых полок.
	*/
	/*printf("\tДобро пожаловать в программу, которая определяет массу шкафа!\n");
	printf("Внимание! Данные в программу нужно вносить в метрах, для разделения дробной и целой частей используйте символ ','\n");
	printf("Диапазон значений высоты шкафа от 1.8 м до 2.2 м!\n");
	printf("Введите высоту шкафа h:");//Укажите значаение в метрах от 1.8м до 2.2м .
	scanf_s("%lf", &h);
	while ((h < 1.8) || (h > 2.2))
	{
		printf("\tОшибка введённых данных!\nПожалуйста проверьте правильность своих данных и запустите программу ещё раз!(Значение указывайте в метрах)\n");
		printf("Внимание! Данные в программу нужно вносить в метрах, для разделения дробной и целой частей используйте символ ','\n");
		printf("Диапазон значений высоты шкафа от 1.8 м до 2.2 м!\n");
		printf("Введите высоту шкафа h:");//Укажите значаение в метрах от 1.8м до 2.2м .
		scanf_s("%lf", &h);
	}
	printf("Диапазон значений ширины шкафа от 0.8 м до 1.2 м!\n");
	printf("Введите ширину шкафа w:");//Укажите значаение в метрах от 0.8м до 1.2м .
	scanf_s("%lf", &w);
	while ((w < 0.8) || (w > 1.2))
	{
		printf("\tОшибка введённых данных!\nПожалуйста проверьте правильность своих данных и запустите программу ещё раз!(Значение указывайте в метрах)\n");
		printf("Диапазон значений ширины шкафа от 0.8 м до 1.2 м!\n");
		printf("Введите ширину шкафа w:");//Укажите значаение в метрах от 0.8м до 1.2м .
		scanf_s("%lf", &w);
	}
	printf("Диапазон значений глубины шкафа от 0.5 м до 0,9 м!\n");
	printf("Введите глубину шкафа d:");//Укажите значаение в метрах от 0.5м до 0.9м .
	scanf_s("%lf", &d);
	while ((d < 0.5) || (d > 0.9))
	{
		printf("\tОшибка введённых данных!\nПожалуйста проверьте правильность своих данных и запустите программу ещё раз!(Значение указывайте в метрах)\n");
		printf("Диапазон значений глубины шкафа от 0.5 м до 0,9 м!\n");
		printf("Введите глубину шкафа d:");//Укажите значаение в метрах от 0.5м до 0.9м .
		scanf_s("%lf", &d);
	}
	coutshelf = (int)((h - (2 * THICKNESSDSP)) / (RASBETWEENSHELF + THICKNESSDSP));
	itogmass = 0;
	vdvp = h * w * THICKNESSDVP;
	vdsp1 = (coutshelf * THICKNESSDSP * d * (w - (2 * THICKNESSDSP)));
	vdsp2 = (COUNTULWALL * THICKNESSDSP * d * w);
	vdsp3 = (COUNTSIDEWALL * THICKNESSDSP * d * (h - (2 * THICKNESSDSP)));
	vdsp = (vdsp1 + vdsp2 + vdsp3);
	vtree = w * h * THICKNESSTREE;
	itogmass = ((DENSITYDSP * vdsp) + (DENSITYDVP * vdvp) + (DENSITYTREE * vtree));
	printf("Количество полок в шкафу = %d", coutshelf);
	printf(" штук.\n");
	printf("Масса шкафа = ");
	printf("%lf", itogmass);
	printf(" кг.");
	scanf_s("%d", &a);
}*/