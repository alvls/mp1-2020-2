#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>
#define SIZE 100
#define kol_tov 10 //количество слов
#define name_max 25 //максимальная длина наименовария товара
#define _CRT_SECURE_NO_WARNINGS

//делаем глобальные массивы, чтобы их было видно в функциях 
int shtrihkod[kol_tov] = { 2389,1850,3251,6751,9662,5739,1617,2864,5824,8703 }; //штрихкоды
int prices[kol_tov] = { 120,100,80,90,150,20,160,100,40,50 }; //цены товаров
int sale[kol_tov] = { 5,10,15,5,20,0,20,15,0,5 };//скидки на товары 
char name_tovar[kol_tov][name_max] = { "Тетрадка 96 листов", "Тетрадка 48 листов", "Синяя ручка", "Чёрная ручка","Набор карандашей","Ластик","Набор цветных ручек", "Набор стикеров","Линейка 15 см.","Линейка 20 см." }; //наименования товаров 
int kol_tovar[kol_tov] = { 0 }; //массив кол-ва раз сканирования одного товара
int prise_itog = 0; //итоговая цена без скидки
int prise_itog_sale = 0; //итоговая цена со скидкой 

void show_menu() //показывает список имеющихся товаров и их штрихкоды 
{
	for (int i = 0; i < kol_tov; i++)
	{
		printf("%d ", shtrihkod[i]);
		for (int j = 0; j < name_max; j++)
			printf("%c", name_tovar[i][j]);
		printf("\n");
	}
	printf("\nВведите 0 для печати чека!\n");
}
int scaner() //сканирует штрихкод //сравнивает с массивом имеющихся штрихкодов //считает сколько раз отсканирован товар 
{
	int tovar;
	printf("\nВведите штрихкод товара ");
	scanf_s("%d", &tovar);
	if (tovar != 0)
	{
		int k = 0; //счётчик совпадения цифр штрихкода, введенного пользователем и штрихкода имеющегося товара
		for (int i = 0; i < kol_tov; i++)
		{
			if (tovar == shtrihkod[i])
			{
				kol_tovar[i] += 1; //счётчик кол-ва сканирований одного товара 
				return i;
			}
		}
	}
	else
		return -1;
}
void information(int nomer_tovara) //  штрихкод / наименование товара / цена / скидка / цена со скидкой / кол-во отсканированных раз
{
	printf("%d ", shtrihkod[nomer_tovara]);
	for (int j = 0; j < name_max; j++)
	{
		printf("%c", name_tovar[nomer_tovara][j]);
	}
	printf(" Цена: %d руб./шт. ", prices[nomer_tovara]);
	printf("Скидка: %d%% Цена со скидкой: %d руб./шт. Кол-во:%d \n", sale[nomer_tovara], (prices[nomer_tovara]- prices[nomer_tovara]*sale[nomer_tovara]/100), kol_tovar[nomer_tovara]);
}

void chek()
{
	printf("\n           ЧЕК\n");
	for (int i = 0; i < kol_tov; i++)
	{
		if (kol_tovar[i] != 0)
		{
			printf("%d ", shtrihkod[i]);
			for (int j = 0; j < name_max; j++)
			{
				printf("%c", name_tovar[i][j]);
			}
			printf("%5d руб./шт. ", prices[i]);
			printf("скидка: %3d%% %5d шт. %6d руб.\n", sale[i],  kol_tovar[i], ((prices[i] - prices[i] * sale[i] / 100) * kol_tovar[i]));
			prise_itog += (prices[i]*kol_tovar[i]);
			prise_itog_sale += ((prices[i] - prices[i] * sale[i] / 100)* kol_tovar[i]);
		}
	}
	printf("\nЦЕНА БЕЗ СКИДКИ: %d", prise_itog);
	printf("\nСКИДКА: %d", (prise_itog-prise_itog_sale));
	printf("\n\nИТОГ: %d\n", prise_itog_sale);
}
int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		system("cls");
		int tovar=0;
		show_menu();
		while (tovar != -1)
		{
			tovar = scaner(); //т.к. scaner возвращает номер товара в списке
			if (tovar == -1)
				break;
			information(tovar); //информация о товаре, с который совпал штрихкод, введённый пользователем
		}
		chek();	system("pause");
	}	
}
