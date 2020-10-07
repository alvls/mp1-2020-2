#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N, number, s=500;//s-сравнение
	int P;//в нее записывается попытка пользователя
	int t = 0;
	int i = 0;
	char b;
	setlocale(LC_ALL, "Russian");
	printf("Введите номер режима: ");
	scanf_s("%d", &number);
	while ((number != 1) && (number != 2))
	{
		printf("Введено некорректное значение номера режима, попытайтесь заново: ");
		scanf_s("%d", &number);
	}
	if (number == 1)
	{
		srand(time(NULL));
		N = rand() % 1000 + 1;
		printf("%d\n", N);
		printf("Попытайтесь отгадать число от 1 до 1000 \n");
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
			t++;
			printf("Попытайтесь отгадать еще раз: ");
			scanf_s("%d", &P);
		} 
		printf("Вы угадали! Вы сделали %i", t);
		printf(" попыток \n");
	}
	else if (number == 2)
	{
		printf("Загадайте число от 1 до 1000 и введите его \n");
		scanf_s("%d", &N);
		while (N != s)
		{
			printf("%d \n", s);
			printf("Если загаданное число больше, введите <. Если загаданное число меньше, введите > \n");
			b = getchar();
			b = getchar();
			if (b == '<')
			{
				s = s + s / 2;
				i++;
			}
			else
			{
				if (b == '>')
				{
					s = s - s / 2;
					i++;
				}
				else
					printf("Введен некорректный символ, попробуйте еще раз \n");
			} 
		} 
		printf("Число попыток: %d \n", i);
	}
	else
	{
		printf("Введен некорректный номер режима\n");
	}
	system("pause");
}