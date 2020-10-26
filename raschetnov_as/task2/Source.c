#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int gamemodechooser, countsuccess = 0, c, p = 0;
	int number, i = 1, k = 1, u = 1, s = 0;
	int answer;
	int randomnumber, guess, scanfcounter = 0, res = 0;
	printf("Description of the gamemodes:\ngamemode1: You have to enter a number and program will try to guess it.\ngamemode2: You have to guess program's number.\n");
	printf("Choose gamemode: press 1 for gamemode1 or any other numbers for gamemode2:\n");
	countsuccess = scanf("%d", &gamemodechooser);
	while (countsuccess != 1 || gamemodechooser != 1 && gamemodechooser != 2)
	{
		printf("Your entered wrong symbol, try again:\nChoose gamemode: press 1 for gamemode1 or 2 for gamemode2\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			countsuccess = scanf("%d", &gamemodechooser);
		}
	}
	if (gamemodechooser == 1)
	{
		printf("Enter a number between 1 and 1000 and program will try to guess it:\n");
		s = scanf("%d", &number);
		while (s != 1 || number < 1 || number > 1000)
		{
			printf("Your entered wrong symbol or your number is out of range, try again\nEnter number and program will try to guess it:\n");
			while ((c = getchar()) != '\n' && c != EOF);
			{
				s = scanf("%d", &number);
			}
		}
		s = 0;
		printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", 1000 / 10 * i);
		s = scanf("%d", &answer);
		while (s != 1 || gamemodechooser != 1 && gamemodechooser != 2)
		{
			printf("Your entered wrong symbol, try again:\n");
			printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", 1000 / 10 * i);
			while ((c = getchar()) != '\n' && c != EOF);
			{
				s = scanf("%d", &answer);
			}
		}
		while (answer != 2)
		{
			if (i < 10)
			{
				i++;
				printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", 1000 / 10 * i);
				s = scanf("%d", &answer);
				while (s != 1 || answer != 2 && answer != 1)
				{
					printf("Your entered wrong symbol, try again:\n");
					printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", 1000 / 10 * i);
					while ((c = getchar()) != '\n' && c != EOF);
					{
						s = scanf("%d", &answer);
					}
				}
			}
			else
			{
				printf("You cheated. The game is over");
			}
		}
		s = 0;
		answer = 0;
		printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + k * 10));
		s = scanf("%d", &answer);
		while (s != 1 || answer != 2 && answer != 1)
		{
			printf("Your entered wrong symbol, try again:\n");
			printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + k * 10));
			while ((c = getchar()) != '\n' && c != EOF);
			{
				s = scanf("%d", &answer);
			}
		}
		while (answer != 2)
		{
			if (k < 10)
			{
				k++;
				printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + k * 10));
				s = scanf("%d", &answer);
				while (s != 1 || answer != 2 && answer != 1)
				{
					printf("Your entered wrong symbol, try again:\n");
					printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + k * 10));
					while ((c = getchar()) != '\n' && c != EOF);
					{
						s = scanf("%d", &answer);
					}
				}
			}
			else
			{
				printf("You cheated. The game is over");
			}
		}
		s = 0;
		answer = 0;
		printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + (k - 1) * 10 + u));
		s = scanf("%d", &answer);
		while (s != 1 || answer != 2 && answer != 1)
		{
			printf("Your entered wrong symbol, try again:\n");
			printf("Is your number more or less(same) then %d ?\nType 1 if more(same) and 2 if less:\n", (1000 / 10 * (i - 1) + (k - 1) * 10 + u));
			while ((c = getchar()) != '\n' && c != EOF);
			{
				s = scanf("%d", &answer);
			}
		}
		while (answer != 2)
		{
			if (u < 10)
			{
				u++;
				printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + (k - 1) * 10 + u));
				s = scanf("%d", &answer);
				while (s != 1 || answer != 2 && answer != 1)
				{
					printf("Your entered wrong symbol, try again:\n");
					printf("Is your number more or less(same) then %d ?\nType 1 if more and 2 if less(same):\n", (1000 / 10 * (i - 1) + (k - 1) * 10 + u));
					while ((c = getchar()) != '\n' && c != EOF);
					{
						s = scanf("%d", &answer);
					}
				}
			}
			else
			{
				printf("You cheated. The game is over.");
			}
		}
		printf("Your number is: %d\n", 100 * (i - 1) + 10 * (k - 1) + u);
		printf("It took me only %d tries to guess your number:\n", i + k + u);
	}
	else if (gamemodechooser == 2)
	{
		srand(time(NULL));
		randomnumber = rand() % (1000 - 1) + 1;
		printf("Tell me your guesses about number:\n");
		scanfcounter = scanf("%d", &guess);
		while (scanfcounter != 1)
		{
			printf("Wrong symbol, try again:\nTell me your guesses about number:\n");
			while ((c = getchar()) != '\n' && c != EOF);
			{
				scanfcounter = scanf("%d", &guess);
			}
		}
		scanfcounter = 0;
		while (res != 1)
		{
			if (guess > randomnumber)
			{
				printf("Your number is more than mine, keep trying:\n");
				p++;
				scanfcounter = scanf("%d", &guess);
				while (scanfcounter != 1)
				{
					printf("Wrong symbol, try again:\nTell me your guesses about number:\n");
					while ((c = getchar()) != '\n' && c != EOF);
					{
						scanfcounter = scanf("%d", &guess);
					}
				}
			}
			else if (guess < randomnumber)
			{
				printf("Your number is less than mine, keep trying:\n");
				p++;
				scanfcounter = scanf("%d", &guess);
				while (scanfcounter != 1)
				{
					printf("Wrong symbol, try again:\nTell me your guesses about number:\n");
					while ((c = getchar()) != '\n' && c != EOF);
					{
						scanfcounter = scanf("%d", &guess);
					}
				}
			}
			else
			{
				printf("You guessed my number, congratulations!\n");
				p++;
				printf("It took you only %d tries to do that:\n", p);
				res = 1;
			}
		}
	}
}
