#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	
#include <stdio.h>
#include<time.h>
void main()
{
	int thoughts = 0, i = 0, n, k = 0, p = 0, s = 0, q = 0, z = 0, number1 = 0, copy = 0;
	int counter = 0, counter2 = 1, j = 0;
	int c;
	int arr1[10], arr2[10];
	printf("Desription of the game:\n");
	printf("You have to guess program's number following simple steps: quantity of cows means how much digits of number you guessed and quantity of bulls means how much digits on the right positions of number you guessed\n");
	printf("Enter number length between 2 and 5:\n");
	q = scanf("%d", &n);
	while (q != 1 || n < 2 || n > 5)
	{
		printf("You entered wrong symbol or your number is out of range, try again:\n");
		printf("Enter number length between 2 and 5:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			q = scanf("%d", &n);
		}
	}
	q = 0;
	srand(time(NULL));
	while (counter2 != 0)
	{
		z = 9 * pow(10, (n - 1));
		number1 = pow(10, (n - 1)) + rand() % z;
		copy = number1;
		for (i = 0; i < n; i++)
		{
			counter2 = 0;
			arr1[i] = copy % 10;
			copy /= 10;
		}
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
				if (arr1[i] == arr1[j])
					counter2++;
		}
	}
	while (p != n)
	{
		p = 0;
		s = 0;
		printf("Tell me your thoughts about number or press 6 for shameful concede:\n");
		q = scanf("%d", &thoughts);
		if (thoughts == 6)
		{
			printf("You lost, the number is %d", number1);
			break;
		}
		else
		{
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
			for (i = 0; i < n; i++)			// проверка на быков.
			{
				if (arr1[i] == arr2[i])
					p++;
			}
			printf("Bulls: %d", p);
			printf("\n");
			counter++;
			for (k = 0; k < n; k++) 		// проверка на коров.
			{
				for (i = 0; i < n; i++)
				{
					if (arr1[i] == arr2[k])
						s++;
				}
			}
			printf("Cows: %d", s - p	);
			printf("\n");
		}
	}
	if (thoughts != 6)
	{
		printf("You guessed my number!\n");
		printf("It took you %d tries to guess it", counter);
	}
}