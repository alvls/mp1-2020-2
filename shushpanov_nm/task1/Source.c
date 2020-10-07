#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int heightWallDvp, widthWallDvp, heightSideWallDsp, depthSideWallDsp, widthCoverPlatesDsp, depthCoverPlatesDsp,
		heightOverheadDoorsTree, widthOverheadDoorsTree, shelves; //������������ ������ � ��, � shelves - ���������� ����� (����� ������� ���������)
	float const DISTANCE_BETWEEN_SHELVES=41.5;
	float weight1, weight2, weight3, weight4, weight5, weightCupboard;
	float const THICKNESS_DVP = 0.5, THICKNESS_DSP = 1.5, THICKNESS_TREE = 1; //������� � ��
	float const DENSITY_DSP = 0.00072, DENSITY_DVP = 0.00082, DENSITY_TREE = 0.00081; //
	printf("������ �� 180 �� 220, ������ ����� ���� �� 80 �� 120, � ������� �� 50 �� 90.\n");
	printf("������� ������ (��) ������ ��������� ������: \n");
	scanf("%d", &heightWallDvp);
	printf("������� ������ (��) ������ ��������� ������: \n");
	scanf("%d", &widthWallDvp);
	printf("������� ������� (��): \n");
	scanf("%d", &depthSideWallDsp);
	if (((heightWallDvp >= 180) && (heightWallDvp <= 220)) || ((widthWallDvp >= 80) && (widthWallDvp <= 120)) 
		|| ((depthSideWallDsp >= 50)) && (depthSideWallDsp <= 90))
	{
		heightSideWallDsp = heightWallDvp; //������ ����� ������� ������ �� ����� ������ �������� ������ ��������� ������� � ������ ������
		heightOverheadDoorsTree = heightWallDvp; //������ ������
		widthOverheadDoorsTree = widthWallDvp; //����� ������ ������
		widthCoverPlatesDsp = widthWallDvp; //������ (�������/������) ������
		depthCoverPlatesDsp = depthSideWallDsp; //�������
		weight1 = DENSITY_DVP * (heightWallDvp * widthWallDvp * THICKNESS_DVP); //����� ������ ������
		weight2 = 2 * DENSITY_DSP * depthSideWallDsp * (heightSideWallDsp - 2 * THICKNESS_DSP) * THICKNESS_DSP; //����� ������� ������
		weight3 = 2 * DENSITY_DSP * widthCoverPlatesDsp * depthCoverPlatesDsp * THICKNESS_DSP; //����� ������ (�����/���)
		weight4 = DENSITY_TREE * widthOverheadDoorsTree * heightOverheadDoorsTree * THICKNESS_TREE; //����� ������
		shelves = ((heightWallDvp - 2 * THICKNESS_DSP) / DISTANCE_BETWEEN_SHELVES); // ���������� �����
		weight5 = shelves * DENSITY_DSP * (widthWallDvp - 2 * THICKNESS_DSP) * depthSideWallDsp * THICKNESS_DSP; //����� �����
		weightCupboard = weight1 + weight2 + weight3 + weight4 + weight5;
		printf("\n");
		printf("����� ������ ������: %.2f ��\n", weight1);
		printf("����� ������� ������: %.2f ��\n", weight2);
		printf("����� ������ (�����/���): %.2f ��\n", weight3);
		printf("����� ������: %.2f ��\n", weight4);
		printf("���������� �����: %d ��\n", shelves);
		printf("����� �����: %.2f ��\n", weight5);
		printf("\n");
		printf("����� �����: %.2f ��\n", weightCupboard);
	}
	else
	{
		printf("������� �������� ������.\n");
	}
	system("pause");	
}