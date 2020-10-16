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
	printf("Выберите длинну загадываемого числа от 2 до 5: ");
	scanf("%d", &n);
	//mas = (int*)malloc(n * sizeof(int));
	if (n >= 2 && n <= 5)
	{
		randomInterval = pow(TEN_DIVISIONS, n);
		printf("Компьютер загадывает число...\n");
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
		//printf("Загаданное число: %d", resultProg);
		//printf("\n");
		printf("Число загадано...\n");
		printf("Игра начинается..\n");
		printf("\nПравила игры:\n");
		printf("Угадывайте число, программа будет вам говорить 'бык' - угадана цифра и позиция цифры; \n'корова' - угадана цифра, но неверная позиция.\n");
		while (doneGame == 0)
		{
			printf("\nЕсли хотите выйти из игры, то нажмите 'ESC'!\n");
			printf("Если же вы не хотите выходить из игры, то нажмите любую другую клавишу!\n");
			key = getch();
			if (key != 27)
			{
				printf("Введите число такое, чтобы цифры не повторялись: ");
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
								printf("Поздравляю, вы отгадали число! У вас два 'быка'!\n");
								break;
							}
							case 3:
							{
								printf("Поздравляю, вы отгадали число! У вас три 'быка'!\n");
								break;
							}
							case 4:
							{
								printf("Поздравляю, вы отгадали число! У вас четыре 'быка'!\n");
								break;
							}
							case 5:
							{
								printf("Поздравляю, вы отгадали число! У вас пять 'быков'!\n");
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
								printf("Одна 'корова'..\n");
								break;
							}
							case 2:
							{
								printf("Две 'коровы'..\n");
								break;
							}
							case 3:
							{
								printf("Три 'коровы'..\n");
								break;
							}
							case 4:
							{
								printf("Четыре 'коровы'..\n");
								break;
							}
							case 5:
							{
								printf("Пять 'коров'..\n");
								break;
							}
							default:
							{
								printf("Вы не угадали ни одной 'коровы'..\n");
								break;
							}
						}
						switch (bull)
						{
							case 1:
							{
								printf("Один 'бык'..\n");
								break;
							}
							case 2:
							{
								printf("Два 'быка'..\n");
								break;
							}
							case 3:
							{
								printf("Три 'быка'..\n");
								break;
							}
							case 4:
							{
								printf("Четыре 'быка'..\n");
								break;
							}
							case 5:
							{
								printf("Пять 'быков'..\n");
								break;
							}
							default:
							{
								printf("Вы не угадали ни одного 'быка'..\n");
								break;
							}
						}
					}
				}
				else
				{
					printf("Число должно состоять из %d цифр и цифры не должны повторяться!.\n", n);
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
		printf("Число не соответствует промежутку от 2 до 5 или введен неизвестный символ.\n");
	}
	printf("Конец программы...\n");
	system("pause");
}