#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int randomNumber, regime, numbersOfAttempts = 1, answer, done = 0;
	printf("Добро пожаловать в игру 'Угадай число'.\n");
	printf("Выберите режим: 1 - программа загадывает число, 2 - пользователь загадывает число, любое другое число - выход из программы.\n");
	printf("Введите число (режим): ");
	scanf("%d", &regime);
	if (regime == 1)
	{
		srand(time(NULL)); //random
		randomNumber = rand() % 1000 + 1; //random
		//printf("Тестовое загаданое число: %d\n", randomNumber);
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
	}
	else if (regime == 2)
	{
		printf("Загадайте число от 1 до 1000, чтобы компьютер мог сыграть с вами в игру.\n");
		printf("Если компьютер отгадает число - '=', если число больше - '>', если число меньше - '<'.\n");
		printf("Введите число: ");
		scanf("%d", &randomNumber);
		printf("\n");
		if (randomNumber > 1 && randomNumber < 1000)
		{
			//Программа отгадывает число
			answer = rand() % 1000 + 1;
			printf("Программа считает, что число: %d\n", answer);
			printf("Вашь ответ: ");
			//считывать символ который введет пользователь, изменить рандом, 
			
		}
		else
		{
			printf("Число не соответствует заданному промежутку!\n");
		}
	}
	else
	{
		printf("Конец программы.\n");
	}
	system("pause");
}