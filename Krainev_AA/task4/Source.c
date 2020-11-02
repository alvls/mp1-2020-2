/*
* Программу реализовал через структуры. Скидка изначально уже есть у каждого товара, вводить ее не нужно.
* Созданы отдельные функции для печати каталога, поиска номера продукта в каталоге и для создания структуры 
* В процессе работы программы вводятся штрихкоды: для окончания работы(печати чека) нужно ввести 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<malloc.h>


char* name[30];
unsigned int price;
char* barcode[30];
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996

struct product* addProduct(char* name, unsigned int price, char* barcode);
int SearchProduct(char* BARCODE, const struct product* st[]);
void view_product_catalog(unsigned int product_counter, const struct product* st[]);


unsigned int product_counter = 5;//количество товара в каталоге

//объявляем структуру для товара
struct product {
    char* name[100]; //имя
    unsigned int price; //цена
    char* barcode[100]; //штрихкод (с очень большим запасом)
    int sale; //скидка
};

int main(void) {
    setlocale(LC_ALL, "Rus"); //подключаем русский яхык
    char* BARCODE[100];
    float sum = 0;//общая сумма покупки
    float sum_with_sale = 0;
    
    struct product* st[100];
    //список товара который обрабатывается в функции и создается структура.Пытался считывать из файла, но как-то не получилось.
    st[0] = addProduct("Апельсины", 180, "0001",5);
    st[1] = addProduct("Мандарины", 123, "0002",10);
    st[2] = addProduct("Груша", 129, "0003",0);
    st[3] = addProduct("Вода", 121, "0004",15);
    st[4] = addProduct("Лимонад", 128, "0005",0);
    
    int total_number_of_product[10] = {0};//в массиве будет храниться количество каждого выбранного товара: по умолчанию нули 
   
    printf("Добро пожаловать в программу 'Электронная касса'\n");
    view_product_catalog(product_counter, st);//ссылаемся на функцию вывода каталога и выводим его  
    
    printf("Введите штрихкод товара\n");
    gets(BARCODE);
    int End_Products; // нолик для печати чека!!!
    char fail[2] = "0";
    End_Products = strncmp(BARCODE, fail, 8);
    while (End_Products != 0) { //работате пока не будет 0 на входе 
        printf("Вы выбрали %-15s \t  цена за единицу %-15d скидка %-8d\t \n ", st[SearchProduct(BARCODE, st)]->name, st[SearchProduct(BARCODE, st)]->price, st[SearchProduct(BARCODE, st)]->sale);
        total_number_of_product[SearchProduct(BARCODE, st)] ++; // в массив который хранит количество  конкретного товара добавляется 1

        printf("Введите следуюший штрихкод  или 0 для показа чека\n");
        gets(BARCODE);
        End_Products = strncmp(BARCODE, fail, 8);
    }
    //чек «наименование – стоимость за единицу (для упрощения в рублях без копеек) – количество – общая стоимость за товар».
    printf("Чек \n");
    printf("Наименование товара  Цена за ед. рублей  Кол-во Стоимость со скидкой \n");
    for (int i = 0; i < product_counter; ) {
        
        if (total_number_of_product[i] > 0) {
            float final_price_with_sale = (total_number_of_product[i])*((st[i]->price)*(100-(st[i]->sale))/100);
            printf("%-20s %-20d %-6d %-3f\n", st[i]->name, st[i]->price, total_number_of_product[i],final_price_with_sale);
            i++;
        }
        else {
            i++;
        }
        
        
    }
    //цикл считает общую сумму товаров без скидки
    for (int j = 0; j < product_counter; j++) {
        sum = sum + ((total_number_of_product[j]) * (st[j]->price));
    }
    //тут считаем сумму товаров со скидкой
    for (int j = 0; j < product_counter; j++) {
        float final_price_with_sale = (total_number_of_product[j]) * ((st[j]->price) * (100 - (st[j]->sale)) / 100);
        sum_with_sale = sum_with_sale + (final_price_with_sale);
    }

    printf("Общая сумма без скидки:%f руб.\n", sum);
    printf("Общая скидка:%f %%\n", 100-(100*sum_with_sale)/sum);
    printf("Цена со скидкой:%f руб.\n",sum_with_sale);
    printf("До встречи!");

    //int res;
}


    

struct product* addProduct(char* name, unsigned int price, char* barcode,int sale) {
    struct product* res_st = malloc(sizeof(struct product));//не забыть потом освободить память!!!
    strcpy_s(res_st->name,30, name);
    res_st->price = price;
    strcpy_s(res_st->barcode, 30, barcode);
    res_st->sale = sale;
    return res_st;
}



//ищет среди массива структур по штрихкоду нужный продукт и возвращает номер: st[возвращаемый номер] 
//char* SearchProduct(char* BARCODE, const struct product* st[]) это если вернуть строку
int SearchProduct(char* BARCODE,const struct product * st[]) {
    char* selected_product;
    int res;
    int bool = 0;
    while (bool != product_counter) {
        for (int i = 0; i < product_counter; i++) {
            res = strncmp(BARCODE, st[i]->barcode, 8); //сравниваем char по первым 8 символам !!! НЕ ЗАБЫТЬ ПОСТАВИТЬ ВМЕСТО 8 нужное
            if (res == 0) {
                bool = product_counter;
                return i;//возвращает название продукта найденного (номер в каталоге)

            }
            if (res != 0) {
                bool++;
            }
        }
        
    }
}

//функция печатающая ассортимент товара
void view_product_catalog(unsigned int product_counter, const struct product* st[]) {
    printf("Каталог товара\n");
    for (int i = 0; i < product_counter; i++) {
        printf("%-12s \t цена %-5d  \t  штрихкод %-6s скидка  %-2d %% \n", st[i]->name, st[i]->price, st[i]->barcode, st[i]->sale);
    }
}


