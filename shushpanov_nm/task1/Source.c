#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int heightWallDvp, widthWallDvp, heightSideWallDsp, depthSideWallDsp, widthCoverPlatesDsp, depthCoverPlatesDsp,
		heightOverheadDoorsTree, widthOverheadDoorsTree, shelves; //пользователь вводит в см, а shelves - количество полок (будет считать программа)
	float const DISTANCE_BETWEEN_SHELVES=41.5;
	float weight1, weight2, weight3, weight4, weight5, weightCupboard;
	float const THICKNESS_DVP = 0.5, THICKNESS_DSP = 1.5, THICKNESS_TREE = 1; //считаем в см
	float const DENSITY_DSP = 0.00072, DENSITY_DVP = 0.00082, DENSITY_TREE = 0.00081; //
	printf("Высота от 180 до 220, ширина может быть от 80 до 120, а глубина от 50 до 90.\n");
	printf("Введите высоту (см) задней накладной стенки: \n");
	scanf("%d", &heightWallDvp);
	printf("Введите ширину (см) задней накладной стенки: \n");
	scanf("%d", &widthWallDvp);
	printf("Введите глубину (см): \n");
	scanf("%d", &depthSideWallDsp);
	if (((heightWallDvp >= 180) && (heightWallDvp <= 220)) || ((widthWallDvp >= 80) && (widthWallDvp <= 120)) 
		|| ((depthSideWallDsp >= 50)) && (depthSideWallDsp <= 90))
	{
		heightSideWallDsp = heightWallDvp; //высота одной боковой стенки из общей высоты вычитаем высоту накладных верхней и нижней стенки
		heightOverheadDoorsTree = heightWallDvp; //высота дверей
		widthOverheadDoorsTree = widthWallDvp; //общая ширина дверей
		widthCoverPlatesDsp = widthWallDvp; //ширина (верхних/нижних) крышек
		depthCoverPlatesDsp = depthSideWallDsp; //глубина
		weight1 = DENSITY_DVP * (heightWallDvp * widthWallDvp * THICKNESS_DVP); //масса задней стенки
		weight2 = 2 * DENSITY_DSP * depthSideWallDsp * (heightSideWallDsp - 2 * THICKNESS_DSP) * THICKNESS_DSP; //масса боковых стенок
		weight3 = 2 * DENSITY_DSP * widthCoverPlatesDsp * depthCoverPlatesDsp * THICKNESS_DSP; //масса крышек (вверз/низ)
		weight4 = DENSITY_TREE * widthOverheadDoorsTree * heightOverheadDoorsTree * THICKNESS_TREE; //масса дверей
		shelves = ((heightWallDvp - 2 * THICKNESS_DSP) / DISTANCE_BETWEEN_SHELVES); // количество полок
		weight5 = shelves * DENSITY_DSP * (widthWallDvp - 2 * THICKNESS_DSP) * depthSideWallDsp * THICKNESS_DSP; //масса полок
		weightCupboard = weight1 + weight2 + weight3 + weight4 + weight5;
		printf("\n");
		printf("Масса задней стенки: %.2f кг\n", weight1);
		printf("Масса боковых стенок: %.2f кг\n", weight2);
		printf("Масса крышек (вверх/низ): %.2f кг\n", weight3);
		printf("Масса дверей: %.2f кг\n", weight4);
		printf("Количество полок: %d шт\n", shelves);
		printf("Масса полок: %.2f кг\n", weight5);
		printf("\n");
		printf("Масса шкафа: %.2f кг\n", weightCupboard);
	}
	else
	{
		printf("Введены неверные данные.\n");
	}
	system("pause");	
}