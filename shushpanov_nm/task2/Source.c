#define _CRT_SECURE_NO_WARNINGS
#define RAND_MAX 1000
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Восстановление task2
void main()
{
	setlocale(LC_ALL, "Rus");
	int randomNumber, numbersOfAttempts = 1, answer, regime, done = 0, min = 1, max = 1000;
	char prompt;
	printf("Добро пожаловать в игру 'Угадай число'.\n");
	printf("Выберите режим: 1 - программа загадывает число, 2 - пользователь загадывает число, любое другое число - выход из программы.\n");
	printf("Введите число (режим): ");
	scanf("%d", &regime);
	switch (regime)
	{
		case 1:
		{
			srand(time(NULL)); //random
			randomNumber = rand() % 1000 + 1; //random
			printf("Программа загадала число в диапазоне от 1 до 1000. Попробуй отгадать его, если сможешь.\n");
			while (done == 0)
			{
				printf("Попытка (%d).\n", numbersOfAttempts);
				printf("Введи свою догадку: ");
				scanf("%d", &answer);
				if (answer > randomNumber)
				{
					printf("Загаданное число меньше.\n");
					printf("\n");
					numbersOfAttempts++;
				}
				else if (answer < randomNumber)
				{
					printf("Загаданное число больше.\n");
					printf("\n");
					numbersOfAttempts++;
				}
				else if (answer == randomNumber)
				{
					printf("Поздравляю! Вы угадали число!\n");
					printf("Ваше число попыток: %d \n", numbersOfAttempts);
					printf("\n");
					done = 1;
				}
			}
			break;
		}
		case 2:
		{
			printf("Загадайте число от 1 до 1000, чтобы компьютер мог сыграть с вами в игру.\n");
			printf("Если компьютер отгадает число - '=', если число больше - '>', если число меньше - '<'.\n");
			printf("Введите число: ");
			scanf("%d", &randomNumber);
			printf("\n");
			if (randomNumber > 1 && randomNumber < 1000)
			{
				srand(time(NULL));
				answer = rand() % max + min;
				while (done == 0)
				{
					printf("\n");
					printf("Попытка (%d).\n", numbersOfAttempts);
					printf("Программа считает, что число: %d\n", answer);
					printf("Ваш ответ: ");
					getchar(); //чтобы не выводил текст до по 2 раза в командную строку
					scanf("%c", &prompt); //пробовал выводить через "%s" - перегружает переменную, но тогда не нужна "69" строка
					printf("\n");
					switch (prompt)
					{
						case '>':
						{
							printf("Число больше.\n");
							min = answer;
							answer = (max + min) / 2;
							numbersOfAttempts++;
							break;
						}
						case '<':
						{
							printf("Число меньше.\n");
							max = answer;
							answer = (max + min) / 2;
							numbersOfAttempts++;
							break;
						}
						case '=':
						{
							printf("Компьютер отгадал ваше число!\n");
							printf("Число попыток компьютера: %d \n", numbersOfAttempts);
							done = 1;
							break;
						}
						default:
						{
							printf("Неизвестный оператор! Возможные операторы: < , > , = .\n");
							break;
						}
					}
				}
			}
			else
			{
				printf("Число не соответствует заданному промежутку!\n");
			}
		}
		default:
		{
			printf("Конец программы.\n");
			break;
		}
	}
	system("pause");
}
