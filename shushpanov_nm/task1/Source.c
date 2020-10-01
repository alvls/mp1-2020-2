#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

void main()
{
	//%
	setlocale(LC_ALL, "Rus");
	int heightWallDvp, weidthWallDvp, heightSideWallDsp, depthSideWallDsp, weightCoverPlatesDsp, depthCoverPlatesDsp,
		heightOverheadDoorsTree, weidthOverheadDoorsTree, shelves; //пользователь вводит в см
	int const DISTANCE_BETWEEN_SHELVES=40;
	float const THICKNESS_DVP = 0.5, THICKNESS_DSP = 1.5, THICKNESS_TREE = 1; //считаем в см
	float const DENSITY_DSP, DENSITY_DVP, DENSITY_TREE; //
	printf("Ширина может быть от 180 до 220, а высота от 80 до 120.\n");
	printf("Введите ширину (см) задней накладной стенки: \n");
	scanf("%d", &heightWallDvp);
	printf("Введите высоту (см) задней накладной стенки: \n");
	scanf("%d", &weidthWallDvp);
	printf("Введите глубину (см) боковины: \n");
	scanf("%d", &depthSideWallDsp);
	printf("Введите глубину (см) верхней и нижней накладной крышки: \n");
	scanf("%d", &depthCoverPlatesDsp);
	if (((heightWallDvp >= 180) && (heightWallDvp <= 220)) || (weidthWallDvp >= 80) && (weidthWallDvp <= 120))
	{
		heightSideWallDsp == heightWallDvp; //высота одной боковой стенки из общей высоты вычитаем высоту накладных верхней и нижней стенки
		heightOverheadDoorsTree == heightWallDvp; //высота дверей
		weidthOverheadDoorsTree == weidthWallDvp; //общая ширина дверей

	}
	else
	{
		printf("Введены неверные данные.\n");
	}
	system("pause");	
}