#define _CRT_SECURE_NO_WARNINGS
#define TEN_DIVISIONS 10
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, dublerN = 0, resultUser, resultProg, done = 0, doneGame = 0, randomInterval, date, dateProg, dateUser, dateVerification, powVerification, count = 0, powRandom, power, number, cow, bull;
	char key;
	//int *mas;
	printf("�������� ������ ������������� ����� �� 2 �� 5: ");
	scanf("%d", &n);
	//mas = (int*)malloc(n * sizeof(int));
	if (n >= 2 && n <= 5)
	{
		randomInterval = pow(TEN_DIVISIONS, n);
		printf("��������� ���������� �����...\n");
		srand(time(NULL));
		while (done == 0)
		{
			count = 0;
			resultProg = rand() % randomInterval;
			date = resultProg;
			for (int i = n; i > 0; i--)
			{
				power = i - 1;
				powRandom = pow(TEN_DIVISIONS, power);
				date = resultProg / powRandom % 10;
				if ((date == 0) && (power == n - 1))
				{
					count++;
					break;
				}
				for (int j = i - 1; j > 0; j--)
				{
					powVerification = pow(TEN_DIVISIONS, (j - 1));
					dateVerification = resultProg / powVerification % 10;
					if (date == dateVerification)
					{
						count++;
						break;
					}
				}
			}
			if (count == 0)
			{
				done = 1;
			}
			else
			{
				continue;
			}
		}
		//printf("���������� �����: %d", resultProg);
		//printf("\n");
		printf("����� ��������...\n");
		printf("���� ����������..\n");
		printf("\n������� ����:\n");
		printf("���������� �����, ��������� ����� ��� �������� '���' - ������� ����� � ������� �����; \n'������' - ������� �����, �� �������� �������.\n");
		while (doneGame == 0)
		{
			printf("\n���� ������ ����� �� ����, �� ������� 'ESC'!\n");
			printf("���� �� �� �� ������ �������� �� ����, �� ������� ����� ������ �������!\n");
			key = getch();
			if (key != 27)
			{
				printf("������� ����� �����, ����� ����� �� �����������: ");
				scanf("%d", &resultUser);
				printf("\n");
				date = resultUser;
				while (date > 0)
				{
					dublerN++;
					date = date / 10;
				}
				done = 0;
				while (done == 0)
				{
					count = 0;
					date = resultUser;
					for (int i = n; i > 0; i--)
					{
						power = i - 1;
						powRandom = pow(TEN_DIVISIONS, power);
						date = resultUser / powRandom % 10;
						if ((date == 0) && (power == n - 1))
						{
							count++;
							break;
						}
						for (int j = i - 1; j > 0; j--)
						{
							powVerification = pow(TEN_DIVISIONS, (j - 1));
							dateVerification = resultUser / powVerification % 10;
							if (date == dateVerification)
							{
								count++;
								break;
							}
						}
					}
					if (count == 0)
					{
						done = 1;
					}
					else
					{
						break;
					}
				}
				if ((dublerN == n) && (count == 0))
				{
					dublerN = 0;
					cow = 0;
					bull = 0;
					for (int i = n; i > 0; i--)
					{
						power = i - 1;
						powRandom = pow(TEN_DIVISIONS, power);
						dateProg = resultProg / powRandom % 10;
						dateUser = resultUser / powRandom % 10;
						if (dateProg == dateUser)
						{
							bull++;
						}
						for (int j = n; j > 0; j--)
						{
							powVerification = pow(TEN_DIVISIONS, (j - 1));
							dateUser = resultUser / powVerification % 10;
							if (dateUser == dateProg)
							{
								cow++;
							}
						}
					}
					if (bull == n)
					{
						doneGame = 1;
						switch (bull)
						{
							case 2:
							{
								printf("����������, �� �������� �����! � ��� ��� '����'!\n");
								break;
							}
							case 3:
							{
								printf("����������, �� �������� �����! � ��� ��� '����'!\n");
								break;
							}
							case 4:
							{
								printf("����������, �� �������� �����! � ��� ������ '����'!\n");
								break;
							}
							case 5:
							{
								printf("����������, �� �������� �����! � ��� ���� '�����'!\n");
								break;
							}
						}
					}
					else
					{
						cow = cow - bull;
						switch (cow)
						{
							case 1:
							{
								printf("���� '������'..\n");
								break;
							}
							case 2:
							{
								printf("��� '������'..\n");
								break;
							}
							case 3:
							{
								printf("��� '������'..\n");
								break;
							}
							case 4:
							{
								printf("������ '������'..\n");
								break;
							}
							case 5:
							{
								printf("���� '�����'..\n");
								break;
							}
							default:
							{
								printf("�� �� ������� �� ����� '������'..\n");
								break;
							}
						}
						switch (bull)
						{
							case 1:
							{
								printf("���� '���'..\n");
								break;
							}
							case 2:
							{
								printf("��� '����'..\n");
								break;
							}
							case 3:
							{
								printf("��� '����'..\n");
								break;
							}
							case 4:
							{
								printf("������ '����'..\n");
								break;
							}
							case 5:
							{
								printf("���� '�����'..\n");
								break;
							}
							default:
							{
								printf("�� �� ������� �� ������ '����'..\n");
								break;
							}
						}
					}
				}
				else
				{
					printf("����� ������ �������� �� %d ���� � ����� �� ������ �����������!.\n", n);
					dublerN = 0;
				}
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		printf("����� �� ������������� ���������� �� 2 �� 5 ��� ������ ����������� ������.\n");
	}
	printf("����� ���������...\n");
	system("pause");
}