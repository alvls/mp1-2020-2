#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define K 5
void main()
{
l:
	int arr[K] = { 0 };// массив для создания числа
	int i, n = 0, c = 0, j;//n-для указания разрядности загадываемого числа,с-используется для создания массива и вывода числа на экран в конце игры,i,j-счетчики
	int ch = 0, p = 0;//ch-переменная для чисел вводимых пользователем,p-переменная для цифр числа вводимогомо пользователем
	int bik = 0, kor = 0;//bik-количество быков ,kor-количество коров

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	while (arr[0] == 0)
		arr[0] = rand() % 10;
	for (i = 1; i < K; i++)
	{
		c = rand() % 10;
		for (j = 0; j < i; j++)
			if (arr[j] == c)
			{
				i--;
				break;
			}
			else
				arr[i] = c;
	}
	printf("Введите длину загадываемого числа\n");
	scanf_s("%d", &n);

	while (bik != n)
	{
		j = n;
		kor = 0;
		bik = 0;
		printf("Попытайтесь отгадать число введя n-значное число или введите 1 чтобы сдаться\n");
		scanf_s("%d", &ch);
		if (ch == 1)
			break;
		while (ch != 0)
		{
			p = ch % 10;
			j = j - 1;
			for (i = 0; i < n; i++)
				if (p == arr[i])
				{
					if (j == i)
						bik++;
					else
						kor++;
				}
			ch = ch / 10;
		}
		printf("Количество коров:%d.Количество быков: %d\n", kor, bik);
	}
	c = 0;
	for (i = 0; i < n; i++)
		c = c * 10 + arr[i];
	if (bik == n)
		printf("Поздравляем,вы отгадали число %d\n", c);
	else
		printf("было загадано число %d\n", c);
	printf("Нажмите 1 чтобы начать новую игру, нажмите 0 чтобы выйти из игры\n");
	scanf_s("%d", &c);
	if (c == 0)
		printf("До свидания\n");
	if (c == 1)
		goto l;

	system("pause");

}