#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int randomNumber, regime, numbersOfAttempts = 1, answer, done = 0;
	printf("����� ���������� � ���� '������ �����'.\n");
	printf("�������� �����: 1 - ��������� ���������� �����, 2 - ������������ ���������� �����, ����� ������ ����� - ����� �� ���������.\n");
	printf("������� ����� (�����): ");
	scanf("%d", &regime);
	if (regime == 1)
	{
		srand(time(NULL)); //random
		randomNumber = rand() % 1000 + 1; //random
		//printf("�������� ��������� �����: %d\n", randomNumber);
		printf("��������� �������� ����� � ��������� �� 1 �� 1000. �������� �������� ���, ���� �������.\n");
		while (done == 0)
		{
			printf("������� (%d).\n", numbersOfAttempts);
			printf("����� ���� �������: ");
			scanf("%d", &answer);
			if (answer > randomNumber)
			{
				printf("���������� ����� ������.\n");
				printf("\n");
				numbersOfAttempts++;
			}
			else if (answer < randomNumber)
			{
				printf("���������� ����� ������.\n");
				printf("\n");
				numbersOfAttempts++;
			}
			else if (answer == randomNumber)
			{
				printf("����������! �� ������� �����!\n");
				printf("���� ����� �������: %d \n", numbersOfAttempts);
				printf("\n");
				done = 1;
			}
		}
	}
	else if (regime == 2)
	{
		printf("��������� ����� �� 1 �� 1000, ����� ��������� ��� ������� � ���� � ����.\n");
		printf("���� ��������� �������� ����� - '=', ���� ����� ������ - '>', ���� ����� ������ - '<'.\n");
		printf("������� �����: ");
		scanf("%d", &randomNumber);
		printf("\n");
		if (randomNumber > 1 && randomNumber < 1000)
		{
			//��������� ���������� �����
			answer = rand() % 1000 + 1;
			printf("��������� �������, ��� �����: %d\n", answer);
			printf("���� �����: ");
			//��������� ������ ������� ������ ������������, �������� ������, 
			
		}
		else
		{
			printf("����� �� ������������� ��������� ����������!\n");
		}
	}
	else
	{
		printf("����� ���������.\n");
	}
	system("pause");
}