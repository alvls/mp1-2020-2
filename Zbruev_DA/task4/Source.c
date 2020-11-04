#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 11
void clean(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
float stoimost(int stoimost, int sale)//считает стоимость с учетом скидки
{
	int s;
	s= (stoimost*((100-sale))/100);
	return (s);
}
void main()
{
	int kod, i, flag=0;
	int count[N] = {0};//массив счетчиков 53
	char* tovar[N] = {"Глушитель для ВАЗ 2113-2115                          ", "Набор синхронизаторов на передачи для ВАЗ 2113-2115  ", 
		"Свечи зажигания для ВАЗ 2113-2115                    ", "Поршень для ВАЗ 2113 - 2115                          ", 
		"Жиклеры для карбюраторных ВАЗ 2109                   ", "Датчик температуры охлаждающей жидкости для ВАЗ 2109 ", 
		"Форсунки омывателя лобового стекла                   ", "Набор предохранителей                                ", 
		"Бортовой компьютер БК - 03                           ", "Тормозные колодки задние для ВАЗ 2109 - 2115         ", 
		"Тормозные колодки передние для ВАЗ 2109 - 2115       "};
	char* tovar_number[N] = {"1001", "2001", "3001", "3002", "3101", "3102", "4001", "4002", "4003", "5001", "5002"};
    float st[N];
	float sum=0;
	setlocale(LC_ALL, "Russian");
	printf("Информация о товарах: \n");
	for (i = 0; i < N; i++)
	{
		printf("%s ", tovar_number[i]);
		printf(" - ");
		printf("%s \n", tovar[i]);
	}
	printf("Введите штрих-код товара (натуральное четырехзначное число): \n");
	while (flag!=1)
	{
		scanf_s("%d", &kod);
		while (((kod < 1000) && (kod>0)) || (kod > 9999) || (kod<0))
		{
			clean();
			printf("Введено некорректное значение штрих-кода товара, попытайтесь заново: ");
			scanf_s("%d", &kod);
		}
		switch (kod)
		{
		case 1001:
			st[0] = stoimost(1500, 40);
			count[0]++;
			break;
		case 2001:
			st[1] = stoimost(3000, 15);
			count[1]++;
			break;
		case 3001:
			st[2] = stoimost(250, 15);
			count[2]++;
			break;
		case 3002:
			st[3] = stoimost(150, 5);
			count[3]++;
			break;
		case 3101:
			st[4] = stoimost(800, 10);
			count[4]++;
			break;
		case 3102:
			st[5] = stoimost(200, 15);
			count[5]++;
			break;
		case 4001:
			st[6] = stoimost(150, 10);
			count[6]++;
			break;
		case 4002:
			st[7] = stoimost(150, 10);
			count[7]++;
			break;
		case 4003:
			st[8] = stoimost(1500, 20);
			count[8]++;
			break;
		case 5001:
			st[9] = stoimost(600, 5);
			count[9]++;
			break;
		case 5002:
			st[10] = stoimost(500, 5);
			count[10]++;
			break;
		case 0:
			flag = 1;
			break;
		default: 
			printf("Такого товара нет в каталоге, попытайтесь заново: \n");
		}
	}
	for (i = 0; i < N; i++)
	{
		if (count[i] > 0)
		{
			printf("%s", tovar[i]);
			printf("    %d  ", count[i]);

			printf("   %5.2f ", st[i]);
			printf(" рублей\n");
			sum = sum + count[i] * st[i];
		}
	}
	printf(" \n");
	printf("  Итоговая сумма: %9.2f", sum);
	printf(" рублей\n");
	system("pause");
}