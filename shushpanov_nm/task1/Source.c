#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

void main()
{
	//%
	setlocale(LC_ALL, "Rus");
	int heightWallDvp, weidthWallDvp, heightSideWallDsp, depthSideWallDsp, weightCoverPlatesDsp, depthCoverPlatesDsp,
		heightOverheadDoorsTree, weidthOverheadDoorsTree, shelves; //������������ ������ � ��
	int const DISTANCE_BETWEEN_SHELVES=40;
	float const THICKNESS_DVP = 0.5, THICKNESS_DSP = 1.5, THICKNESS_TREE = 1; //������� � ��
	float const DENSITY_DSP, DENSITY_DVP, DENSITY_TREE; //
	printf("������ ����� ���� �� 180 �� 220, � ������ �� 80 �� 120.\n");
	printf("������� ������ (��) ������ ��������� ������: \n");
	scanf("%d", &heightWallDvp);
	printf("������� ������ (��) ������ ��������� ������: \n");
	scanf("%d", &weidthWallDvp);
	printf("������� ������� (��) ��������: \n");
	scanf("%d", &depthSideWallDsp);
	printf("������� ������� (��) ������� � ������ ��������� ������: \n");
	scanf("%d", &depthCoverPlatesDsp);
	if (((heightWallDvp >= 180) && (heightWallDvp <= 220)) || (weidthWallDvp >= 80) && (weidthWallDvp <= 120))
	{
		heightSideWallDsp == heightWallDvp; //������ ����� ������� ������ �� ����� ������ �������� ������ ��������� ������� � ������ ������
		heightOverheadDoorsTree == heightWallDvp; //������ ������
		weidthOverheadDoorsTree == weidthWallDvp; //����� ������ ������

	}
	else
	{
		printf("������� �������� ������.\n");
	}
	system("pause");	
}