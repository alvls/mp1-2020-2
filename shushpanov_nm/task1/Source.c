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
	printf("Ўирина может быть от 180 до 220, а высота от 80 до 120.\n");
	printf("¬ведите высоту (см) задней накладной стенки: \n");
	scanf("%d", &heightWallDvp);
	printf("¬ведите ширину (см) задней накладной стенки: \n");
	scanf("%d", &widthWallDvp);
	printf("¬ведите глубину (см): \n");
	scanf("%d", &depthSideWallDsp);
	if (((heightWallDvp >= 180) && (heightWallDvp <= 220)) || (widthWallDvp >= 80) && (widthWallDvp <= 120))
	{
		heightSideWallDsp = heightWallDvp; //высота одной боковой стенки из общей высоты вычитаем высоту накладных верхней и нижней стенки
		heightOverheadDoorsTree = heightWallDvp; //высота дверей
		widthOverheadDoorsTree = widthWallDvp; //обща€ ширина дверей
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
		printf("ћасса задней стенки: %.2f \n", weight1);
		printf("ћасса боковых стенок: %.2f \n", weight2);
		printf("ћасса крышек (вверх/низ): %.2f \n", weight3);
		printf("ћасса дверей: %.2f \n", weight4);
		printf(" оличество полок: %d \n", shelves);
		printf("ћасса полок: %.2f \n", weight5);
		printf("\n");
		printf("ћасса шкафа: %.2f \n", weightCupboard);
	}
	else
	{
		printf("¬ведены неверные данные.\n");
	}
	system("pause");	
}