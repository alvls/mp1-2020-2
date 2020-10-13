#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
void main()
{
	int n;//количество цифр в числе
	int t;//
	int P, ost, step, i, h, b=0;//P-число пользователя
	int clon;//в нее записывается копия числа P
	int cow = 0;
	int buffalo = 0;
	int arr[N];//
	char c = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите количество цифр в числе (значение от 2 до 5): ");
	scanf_s("%d", &n);
	while ((n < 2) || (n > 5))
	{
		printf("Введено некорректное значение длины числа, попытайтесь заново: ");
		scanf_s("%d", &n);
	}
	srand(time(NULL));
	arr[0] = rand() % 9+1;
	for (i = 1; i < N; i++)
		arr[i] = arr[0];
	for (i = 1; i < n; i++)
	{
			do
			{
				t = rand() % 10;
			} while ((arr[0] == t)|| (arr[1] == t) || (arr[2] == t) || (arr[3] == t) || (arr[4] == t));
		arr[i] = t;
	}
	for (i = 0; i < n; i++)//строим число 
		b = b * 10 + arr[i];
	                                        printf("Число b:%i \n", b);
	while (1)
	{
		printf("Попытайтесь отгадать число, не содержащее одинаковых цифр.  \n");
		scanf_s("%d", &P);
		for (i = n - 1; i >= 0; i--)
		{
			step = P % 10;
			P = P / 10;
			if ((step == arr[0]) || (step == arr[1]) || (step == arr[2]) || (step == arr[3]) || (step == arr[4]))
				cow++;
			if (step == arr[i])
				buffalo++;
		}
		if (buffalo == n)
		{
			printf("Вы отгадали!\n");
			break;
		}
		else
		{
			printf("Количество коров: %i\n", cow);
			printf("Количество быков: %i\n", buffalo);
			cow = 0;
			buffalo = 0;
			printf("Если хотите завершить попытку, введите символ !. Если хотите продолжить, просто нажмите Enter\n");
			c = getchar();
			c = getchar();
			if (c == '!')
			{
				printf("Программа остановлена \n");
				break;
			}
		}
	}
	system("pause");
}
