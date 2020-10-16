#define _CRT_SECURE_NO_WARNINGS
#define RAND_MAX 1000
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//�������������� task2
void main()
{
	setlocale(LC_ALL, "Rus");
	int randomNumber, numbersOfAttempts = 1, answer, regime, done = 0, min = 1, max = 1000;
	char prompt;
	printf("����� ���������� � ���� '������ �����'.\n");
	printf("�������� �����: 1 - ��������� ���������� �����, 2 - ������������ ���������� �����, ����� ������ ����� - ����� �� ���������.\n");
	printf("������� ����� (�����): ");
	scanf("%d", &regime);
	switch (regime)
	{
		case 1:
		{
			srand(time(NULL)); //random
			randomNumber = rand() % 1000 + 1; //random
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
			break;
		}
		case 2:
		{
			printf("��������� ����� �� 1 �� 1000, ����� ��������� ��� ������� � ���� � ����.\n");
			printf("���� ��������� �������� ����� - '=', ���� ����� ������ - '>', ���� ����� ������ - '<'.\n");
			printf("������� �����: ");
			scanf("%d", &randomNumber);
			printf("\n");
			if (randomNumber > 1 && randomNumber < 1000)
			{
				srand(time(NULL));
				answer = rand() % max + min;
				while (done == 0)
				{
					printf("\n");
					printf("������� (%d).\n", numbersOfAttempts);
					printf("��������� �������, ��� �����: %d\n", answer);
					printf("��� �����: ");
					getchar(); //����� �� ������� ����� �� �� 2 ���� � ��������� ������
					scanf("%c", &prompt); //�������� �������� ����� "%s" - ����������� ����������, �� ����� �� ����� "69" ������
					printf("\n");
					switch (prompt)
					{
						case '>':
						{
							printf("����� ������.\n");
							min = answer;
							answer = (max + min) / 2;
							numbersOfAttempts++;
							break;
						}
						case '<':
						{
							printf("����� ������.\n");
							max = answer;
							answer = (max + min) / 2;
							numbersOfAttempts++;
							break;
						}
						case '=':
						{
							printf("��������� ������� ���� �����!\n");
							printf("����� ������� ����������: %d \n", numbersOfAttempts);
							done = 1;
							break;
						}
						default:
						{
							printf("����������� ��������! ��������� ���������: < , > , = .\n");
							break;
						}
					}
				}
			}
			else
			{
				printf("����� �� ������������� ��������� ����������!\n");
			}
		}
		default:
		{
			printf("����� ���������.\n");
			break;
		}
	}
	system("pause");
}