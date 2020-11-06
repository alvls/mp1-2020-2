#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10 //кол-во товаров
/*
*
Разработать программу «Электронная касса».

Программа должна имитировать работу кассового аппарата по сканированию товаров и формированию чека за покупку.

Каждый товар идентифицируется штрих-кодом. Штрих-код хранится в виде массива из четырех символов. Каждый символ принимает значение от ‘0’ до ‘9’.

Один и тот же товар может сканироваться несколько раз, но в чек информация о каждом товаре входит в виде: «наименование – стоимость за единицу (для упрощения в рублях без копеек) – количество – общая стоимость за товар».

Чек состоит не менее чем из одной записи указанного вида. Чек дополнительно включает общую стоимость товаров в покупке, суммарную скидку и итоговую сумму к оплате (все в рублях).

Каждый товар описывается штрих-кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости. Скидки устанавливаются на каждый товар независимо (в диапазоне от 5% до 50% с шагом 5%).

Программа должна предоставлять следующие операции:

«сканировать» очередной товар,
вывести описание отсканированного товара,
добавить данные о товаре в чек,
сформировать чек за покупку,
рассчитать итоговую сумму к оплате.*/

int check_numbers[SIZE] = { 1001,1002,1003,1004,1005,1006,1007,1008,1009,1010 }; //поле штрих-кодов, может начинаться только с 1,2,..,9
char products[SIZE][17] = { "Колбаса 300г","Белый хлеб","Сосиски 150г","Картошка 1кг","Чипсы Lays 90г", "Сметана","Сыр 150г","Ржаной хлеб","Доширак","Творог" };//названия продуктов
int prices[SIZE] = { 350,27,156,30,75,60,130,27, 38, 80}; //цены
int kolvo_products[SIZE] = { 0 }; //кол-во каждого продукта
int sequence_ind[SIZE] = { 0 }; //последовательность индексов при сканировании
int ch; //общее кол-во отсканированных продуктов
double sales_prices[SIZE] = { 0 }; //массив цен со скидкой(формируется случайно с шагом 5% при запуске программы)

int scan_check(int code) //идентифицирует товар, возвращает его индекс
{
	int i = 0;
	int copy = check_numbers[SIZE - 1];
	check_numbers[SIZE - 1] = code;
	while (check_numbers[i] != code)
		i++;
	if (i == SIZE - 1)
	{
		if (copy != code)
		{
			printf("Ошибка, такого кода товара не существует, попробуйте еще раз\n");
			check_numbers[SIZE - 1] = copy;
			return -1;
		}
		else
		{
			return SIZE - 1;
		}
	}
	check_numbers[SIZE - 1] = copy;
	return i;
}

void kolvo_index_sequence(int i) //считает кол-во и запоминает последовательность отсканированных товаров
{
	kolvo_products[i]++;
	if (kolvo_products[i] > 1)
		return;
	sequence_ind[ch] = i;
	ch++;
}

void print_codes() //выводит на экран список товаров со штрих-кодами
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < SIZE; i++)
	{
		printf("%d ", check_numbers[i]);
		for (j = 0; j < 17; j++)
		{
			printf("%c", products[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void sales() //генерация скидки + заполнение массива цен со скидками
{
	srand(time(NULL));
	int k_sales;
	int i = 0;
	for (i=0; i < SIZE; i++)
	{
		k_sales = ((rand() % 11) * 5);
		sales_prices[i] = (100-k_sales) * prices[i] / 100;
	}
}

void show_information(int ind) //после сканирования выводит название цену без скидки + скидку + цену со скидкой
{
	int size = sizeof(products[ind]) / sizeof(char);
	for (int i = 0; i < size; i++)
	{
		printf("%c", products[ind][i]);
	}
	printf("Цена: %dр ", prices[ind]);
	if (prices[ind] > sales_prices[ind])
	{
		printf("Скидка:%.0lf%% ", 100.0 - sales_prices[ind] / prices[ind] * 100);
		printf("Цена со скидкой :%.1lfр", sales_prices[ind]);
	}
	printf("\n");
	printf("\n");
}

void print_check() //печатает чек
{
	int i = 0;
	int j = 0;
	printf("%-17s", "Название:");
	printf("%-20s","Цена без скидки:");
	printf("%-20s","Цена со скидкой:");
	printf("%-15s","Количество:");
	printf("Итого:");
	printf("\n");
	for (i; i < ch; i++)
	{
		for (j=0; j < 17; j++)
		{
			printf("%c", products[sequence_ind[i]][j]); //название
		}
		printf("%7.dр", prices[sequence_ind[i]]); //цена
		printf("%22.2lfр", sales_prices[sequence_ind[i]]); //цена со скидкой
		printf("%15.d", kolvo_products[sequence_ind[i]]); //кол-во продуктов
		printf("%13.lfр\n", sales_prices[sequence_ind[i]] * kolvo_products[sequence_ind[i]]); //общая стоимость данного продукта
	}
	
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int code = 0;
	char c; //для очистки ввода
	int final_price = 0; //цена с учетом скидок
	int total_price = 0; //цена без скидок
	int index_products = -1; //индекс отсканированного продукта в массиве штрих-кодов
	int choice; //выбор пользователя о выводе списка кодов и названий товаров
	sales(); //формирует массив цен со скидкой
	printf("Здравствуйте, Вас приветсвует программа-сканер, хотите ознакомиться со списком товаров и их штрих-кодами?1-Да 2-Нет\n");
	do {
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			print_codes();
			break;
		}
		else if (choice == 2)
			break;
		else
			printf("Ошибка ввода, попробуйте еще раз: ");
	}
	while (choice != 2);
	printf("Чтобы закончить сканирование и получить Ваш чек, напишите комбинацию 1234\n");
	while (code != 1234) 
	{
		
		printf("Введите штрих-код:");
		scanf_s("%d", &code);
		if (code == 1234)
			break;
		index_products = scan_check(code);
		if (index_products == -1)
		{
			while ((c = getchar()) != '\n');
			continue;
		}
		kolvo_index_sequence(index_products); //передаем функции индекс, чтобы посчитать кол-во этого продукта и запомнить порядок следования продуктов
		total_price += prices[index_products];
		final_price += sales_prices[index_products];
		show_information(index_products); 
		while ((c = getchar()) != '\n');
	}
	printf("\n");
	print_check();
	printf("\n");
	printf("Общая стоимость:%dр\n", total_price);
	printf("Скидка:%dр\n", total_price - final_price);
	printf("К оплате:%dр\n", final_price);
	system("pause");
	
}