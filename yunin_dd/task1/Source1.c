/*#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	const double THICKNESSDVP = 0.005, THICKNESSDSP = 0.015, THICKNESSTREE = 0.01, RASBETWEENSHELF = 0.4;
	/*
	* THICKNESSDVP - ������� ���.
	* THICKNESSDSP - ������� ���.
	* THICKNESSTREE - ������� ������.
	* RASBETWEENSHELF - ���������� ����� �������.
	*/
	/*const long COUNTSIDEWALL = 2, COUNTULWALL = 2;
	/*
	* COUNTSIDEWALL - ���������� ������� ����;
	* COUNTULWALL - ���������� ������� � ������ ����;
	*/
	//const long DENSITYDSP = 720, DENSITYDVP = 820, DENSITYTREE = 810;
	/*
	* DENSITYDSP - ��������� ���.
	* DENSITYDVP - ��������� ���.
	* DENSITYTREE - ��������� ������.
	*/
	//double h, w, d;
	/*
	*h - ������ �����, ������� ������� �������������.
	*w - ������ �����, ������� ������� �������������.
	*d - ������� �����, ������� ������� �������������.
	*/
	int coutshelf,a;
	/*
	*����� ����� � �����.
	*/
	//double vdsp, vdvp, vtree, itogmass, vdsp1, vdsp2, vdsp3;
	/*
	* vdsp - ����� ���������� �� ���.
	* vdvp - ����� ���������� �� ���.
	* vtree - ����� ���������� �� ������.
	* itogmass - ����� ����� �����.
	* vdsp1 - ����� �����.
	* vdsp2 - ����� ������� � ������ �����.
	* vdsp3 - ����� ������� �����.
	*/
	/*printf("\t����� ���������� � ���������, ������� ���������� ����� �����!\n");
	printf("��������! ������ � ��������� ����� ������� � ������, ��� ���������� ������� � ����� ������ ����������� ������ ','\n");
	printf("�������� �������� ������ ����� �� 1.8 � �� 2.2 �!\n");
	printf("������� ������ ����� h:");//������� ��������� � ������ �� 1.8� �� 2.2� .
	scanf_s("%lf", &h);
	while ((h < 1.8) || (h > 2.2))
	{
		printf("\t������ �������� ������!\n���������� ��������� ������������ ����� ������ � ��������� ��������� ��� ���!(�������� ���������� � ������)\n");
		printf("��������! ������ � ��������� ����� ������� � ������, ��� ���������� ������� � ����� ������ ����������� ������ ','\n");
		printf("�������� �������� ������ ����� �� 1.8 � �� 2.2 �!\n");
		printf("������� ������ ����� h:");//������� ��������� � ������ �� 1.8� �� 2.2� .
		scanf_s("%lf", &h);
	}
	printf("�������� �������� ������ ����� �� 0.8 � �� 1.2 �!\n");
	printf("������� ������ ����� w:");//������� ��������� � ������ �� 0.8� �� 1.2� .
	scanf_s("%lf", &w);
	while ((w < 0.8) || (w > 1.2))
	{
		printf("\t������ �������� ������!\n���������� ��������� ������������ ����� ������ � ��������� ��������� ��� ���!(�������� ���������� � ������)\n");
		printf("�������� �������� ������ ����� �� 0.8 � �� 1.2 �!\n");
		printf("������� ������ ����� w:");//������� ��������� � ������ �� 0.8� �� 1.2� .
		scanf_s("%lf", &w);
	}
	printf("�������� �������� ������� ����� �� 0.5 � �� 0,9 �!\n");
	printf("������� ������� ����� d:");//������� ��������� � ������ �� 0.5� �� 0.9� .
	scanf_s("%lf", &d);
	while ((d < 0.5) || (d > 0.9))
	{
		printf("\t������ �������� ������!\n���������� ��������� ������������ ����� ������ � ��������� ��������� ��� ���!(�������� ���������� � ������)\n");
		printf("�������� �������� ������� ����� �� 0.5 � �� 0,9 �!\n");
		printf("������� ������� ����� d:");//������� ��������� � ������ �� 0.5� �� 0.9� .
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
	printf("���������� ����� � ����� = %d", coutshelf);
	printf(" ����.\n");
	printf("����� ����� = ");
	printf("%lf", itogmass);
	printf(" ��.");
	scanf_s("%d", &a);
}*/