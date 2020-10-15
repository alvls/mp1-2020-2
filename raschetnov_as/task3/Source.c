#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	
#include <stdio.h>
void main()
{
	int thoughts = 0, i = 0, n, k = 0, p = 0, s = 0, q = 0, z = 0, number1 = 0, copy, copy2 = 0;
	int counter = 0;
	int c;
	int arr1[10], arr2[10], array[5];
	printf("Desription of the game:\n");
	printf("You have to guess program's number following simple steps: quantity of cows means how much digits of number you guessed and quantity of bulls means how much digits on the right positions of number you guessed\n");
	printf("Enter number length:\n");
	q = scanf("%d", &n);
	while (q != 1 || n < 2 || n > 5)
	{
		printf("You entered wrong symbol or your number is out of range, try again:\n");
		printf("Enter number length:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			q = scanf("%d", &n);
		}
	}
	q = 0;
	srand(time(NULL));
	switch (n)
	{
	case 2:
		while (s != 1)
		{
			z = 9 * pow(10, (n - 1));
			number1 = pow(10, (n - 1)) + rand() % z;
			copy = number1;
			for (i = 0; i < n; i++)
			{
				array[i] = copy % 10;
				copy /= 10;
			}
			if (array[0] != array[1])
				s = 1;
		}
		break;
	case 3:
		while (s != 1)
		{
			z = 9 * pow(10, (n - 1));
			number1 = pow(10, (n - 1)) + rand() % z;
			copy = number1;
			for (i = 0; i < n; i++)
			{
				array[i] = copy % 10;
				copy /= 10;
			}
			if (array[0] != array[1] && array[0] != array[2] && array[1] != array[2])
				s = 1;
		}
	case 4:
		while (s != 1)
		{
			z = 9 * pow(10, (n - 1));
			number1 = pow(10, (n - 1)) + rand() % z;
			copy = number1;
			for (i = 0; i < n; i++)
			{
				array[i] = copy % 10;
				copy /= 10;
			}
			if (array[0] != array[1] && array[0] != array[2] && array[0] != array[3] && array[1] != array[2] && array[1] != array[3] && array[2] != array[3])
				s = 1;
		}
	case 5:
		while (s != 1)
		{
			z = 9 * pow(10, (n - 1));
			number1 = pow(10, (n - 1)) + rand() % z;
			printf("%d", number1);
			printf("\n");
			copy = number1;
			for (i = 0; i < n; i++)
			{
				array[i] = copy % 10;
				copy /= 10;
			}
			if (array[0] != array[1] && array[0] != array[2] && array[0] != array[3] && array[0] != array[4] && array[1] != array[2] && array[1] != array[3] && array[1] != array[4] && array[2] != array[3] && array[2] != array[4] && array[3] != array[4])
				s = 1;
		}

	}
	copy2 = number1;
	for (i = 0; i < n; i++)
	{
		arr1[i] = copy2 % 10;
		copy2 /= 10;
	}
	while (p != n)
	{
		p = 0;
		s = 0;
		printf("Tell me your thoughts about number:\n");
		q = scanf("%d", &thoughts);
		while (q != 1)
		{
			printf("You entered wrong symbol or your number is out of range, try again:\n");
			printf("Tell me your thoughts about number:\n");
			while ((c = getchar()) != '\n' && c != EOF);
			{
				q = scanf("%d", &thoughts);
			}
		}
		for (i = 0; i < n; i++)			// число пользователя разложено по разрядам и запомнено в массив.		
		{
			arr2[i] = thoughts % 10;
			thoughts = thoughts / 10;
		}
		for (k = 0; k < n; k++) 		// проверка на коров.
		{
			for (i = 0; i < n; i++)
			{
				if (arr1[i] == arr2[k])
					s++;
			}
		}
		printf("Cows: %d", s);
		printf("\n");
		for (i = 0; i < n; i++)			// проверка на быков.
		{
			if (arr1[i] == arr2[i])
				p++;
		}
		printf("Bulls: %d", p);
		printf("\n");
		counter++;
	}
	printf("You guessed my number!\n");
	printf("It took you %d tries to guess my number", counter);
}