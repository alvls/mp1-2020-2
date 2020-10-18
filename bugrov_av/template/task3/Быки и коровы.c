#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*Разработать программу, реализующую игру «Быки и коровы».
Требования(правила)
Играют два игрока(человек и компьютер).
Игрок выбирает длину загадываемого числа – n(от 2 до 5). proverit'
Компьютер «задумывает» n - значное число с неповторяющимися цифрами.
Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами.
Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров) и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков).
Игрок делает попытки, пока не отгадает всю последовательность или не сдастся.
Пример
Пусть n = 4.
Пусть задумано число «3219».
Игрок ввел число «2310».
Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции). switch switch*/
#define num 5
void main()
{
	char c;
	int n, i = 0, igrok, t; // n знаков в числе; i - счётчик; igrok - число игрока; t - дополнительный счётчик; 
	unsigned short zagad[num] = { 0 }, x, p[num] = { 0 }, bik = 0, kor = 0; // zagad - загаданное компьютером число; x - случайное число; p пользовательское число; bik - число быков; kor  - число коров;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("Давайте сыграем в игру \"Быки и коровы\"\n");
	printf("Введите количество цифр в числе\n");
nachalo: 
	scanf("%d", &n);
	if (n < 2 || n > 5)
	{
		printf("Вы ввели неправильное число, введите снова\n");
		goto nachalo;
	}
	zagad[i] = rand() % 9 + 1;	
	for (i = 1; i < n; i++) // Генерация числа
	{
	met1:
		x = rand() % 10; // создание очередной цифры
		zagad[i] = x;
		for (t = 0; t < i; t++)
		{
			if (zagad[i] == zagad[t]) // проверка на равенство 
				goto met1;
		}
	}
	do
	{ 
		printf("Введите число\n");
		scanf("%d", &igrok);
		for (i = 0; i < n; i++)
		{
			p[n-1-i] = igrok % 10;
			igrok /= 10;
		}
		for (i = 0; i < n; i++) // проверка сходства с числом пользователя
		{
			if (zagad[i] == p[i]) // для полного сходства (место и цифра)
				bik++;
			else
			{
				for (t = 0; t < n; t++)
				{
					if (zagad[i] == p[t]) // сходство только цифры
					{
						kor++;
						break;
					}

				}
			}
		}
		if (bik < n)
		{
			switch (bik)
			{
			case 0: case 5:
				switch (kor)
				{
				case 0: case 5:
					printf("%d быков и %d коров\n", bik, kor);
					break;
				case 1:
					printf("%d быков и %d корова\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d быков и %d коровы\n", bik, kor);
					break;
				}
				break;
			case 1:
				switch (kor)
				{
				case 0: case 5:
					printf("%d бык и %d коров\n", bik, kor);
					break;
				case 1:
					printf("%d бык и %d корова\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d бык и %d коровы\n", bik, kor);
					break;
				}
				break;
			case 2: case 3: case 4:
				switch (kor)
				{
				case 0: case 5:
					printf("%d быка и %d коров\n", bik, kor);
					break;
				case 1:
					printf("%d быкa и %d корова\n", bik, kor);
					break;
				case 2: case 3: case 4:
					printf("%d быкa и %d коровы\n", bik, kor);
					break;
				}
				break;
			}
			/*for (i = 0; i < n; i++)
			{
				printf("%d", zagad[i]);
				
			}
			printf("\n");
			for (i = 0; i < n; i++)
			{
				printf("%d", p[i]);
			}
			printf("\n");
			*/
			bik = 0;
			kor = 0;
		}
		else
		{
			c = ' ';
			printf("И это правильный ответ!");
			printf("Вы победили, поздравляю!\n");
			printf("Вы проявили много терпения и показали навыки игры в эту очень увлекательную игру\n");
			break;
		}
		printf("Если вы сдаётесь, введите пробел, в любом другом случае продолжаем игру\n");
		c = getch();
	} while (c != ' ');
	if (bik < n)
	{
		printf("Это было число ");
		for (i = 0; i < n; i++)
		{
			printf("%d", zagad[i]);
		}
		printf("\n");
	}
	system("pause");
}