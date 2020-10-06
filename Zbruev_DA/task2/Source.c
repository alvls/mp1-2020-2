#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N, number;
	int P;//в нее записывается попытка пользователя
	setlocale(LC_ALL, "Russian");

	printf("Введите номер режима: ");
	scanf_s("%d", &number);
	if (number == 1)
	{
		srand(time(NULL));
		N = rand() % 1000 + 1;
		printf("%d\n", N);
		printf("Попытайтесь отгдать: ");
		scanf_s("%d", &P);
		while (N != P)
		{
			if (N > P)
			{
				printf("Загаданное число больше \n");
			}
			else
				if (N < P)
				{
					printf("Загаданое число меньше \n");
				}
			printf("Попытайтесь отгдать еще раз: ");
			scanf_s("%d", &P);
		} 
		printf("Вы угадали! +100 к интеллекту \n");
	}
	else if (number == 2)
	{



	}
	else
	{
		printf("Ошибка ввода");
	}
	system("pause");
}