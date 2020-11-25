/*
* Программу реализовал через структуры. Скидка изначально уже есть у каждого товара, вводить ее не нужно.
* Созданы отдельные функции для печати каталога, поиска номера продукта в каталоге и для создания структуры
* В процессе работы программы вводятся штрихкоды: для окончания работы(печати чека) нужно ввести 0
* Не до конца понял выражение "суммарная скидка". Сделал именно сумарную скидку в процентах, если нужно - исправлю.
* При начале работы программы высвечивается каталог товара: для удобства тестировки.
*/
//подключаем нужные библиотеки 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<malloc.h>


char* name[30];
unsigned int price;
char* barcode[30];
#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996

//объявляем функции 
struct product* addProduct(char* name, unsigned int price, char* barcode);
int SearchProduct(char* BARCODE, const struct product* st[]);
void view_product_catalog(unsigned int product_counter, const struct product* st[]);


unsigned int product_counter = 5;//количество товара в каталоге:если меняем число товаров, то и меняем здесь константу!

//объявляем структуру для товара
struct product {
    char name[100]; //имя товара
    unsigned int price; //цена
    char barcode[100]; //штрихкод (размер с очень большим запасом:вдруг далее будет очень большой ассортимент)
    int sale; //переменная для хранения скидки на товар (по условию кратна 5)
};

struct product* res_st;
struct product* addProduct(char* name, unsigned int price, char* barcode, int sale) {
    free(res_st);
    struct product* res_st = malloc(sizeof(struct product));//выдыляем память для структуры
    strcpy_s(res_st->name, 30, name);//копируем получаемое название из каталога товара в структуру 
    res_st->price = price; //копируем получаемую цену
    strcpy_s(res_st->barcode, 30, barcode);//копируем получаемый штрихкод
    res_st->sale = sale;//копируем получаемую скидку 
    return res_st;
}




int main(void) {
    setlocale(LC_ALL, "Rus"); //подключаем русский яхык
    char BARCODE[100]; //для хранения штрихкода, который вводит пользователь 
    float sum = 0;//общая сумма покупки
    float sum_with_sale = 0;// общая сумма покупок со скидкой 

    struct product* st[100]; //объявляем массив структур 


    //список товара который обрабатывается в addProduct (каталог товара)

    st[0] = addProduct("Апельсины", 180, "0001", 5);
    st[1] = addProduct("Мандарины", 123, "0002", 10);
    st[2] = addProduct("Груша", 129, "0003", 0);
    st[3] = addProduct("Вода", 121, "0004", 15);
    st[4] = addProduct("Лимонад", 128, "0005", 0);
    free(res_st);
    int total_number_of_product[10] = { 0 };//в массиве будет храниться количество каждого выбранного товара: по умолчанию нули.размер массива=
    //= количество товаров в каталоге 
    while (1) {
        printf("Добро пожаловать в программу 'Электронная касса'\n"); //приветственная надпись 
        view_product_catalog(product_counter, st);//ссылаемся на функцию вывода каталога и выводим его  

        //далее реализована сама работа кассы 
        printf("Введите штрихкод товара\n");//запрашиваем штрихкод  товара 
        gets(BARCODE);//получаем его

        int End_Products; // нолик для печати чека!!!
        char fail[2] = "0";//сравниваем введеные "строки"с этим ноликом, чтобы знать когда печатать чек.
        End_Products = strncmp(BARCODE, fail, 8); //сравние через функцию strncmp
        //далее у нас реализован цикл пока на входе не появится 0
        while (End_Products != 0) {
            //печатаем информацию о товаре: у функции SearchProduct получаем номер в каталоге и по нему печатаем нужный элемент в структуре st[]
            if ((SearchProduct(BARCODE, st)) != (-1)) {
                printf("Вы выбрали  \t  Цена за единицу \t   скидка \t \n");
                printf("%-15s \t  %-20d  %-10d %\n", st[SearchProduct(BARCODE, st)]->name, st[SearchProduct(BARCODE, st)]->price, st[SearchProduct(BARCODE, st)]->sale);
                total_number_of_product[SearchProduct(BARCODE, st)] ++; //плюсуем 1  в массив который хранит количество  конкретного товара 
                printf("Введите следуюший штрихкод  или 0 для показа чека\n");//опять запрашиваем штрихкод у кассира
            }
            if ((SearchProduct(BARCODE, st)) == (-1)) {
                printf("Вы ввели товар, которого нет в каталоге, повторите ввод заново\n");
            }
            gets(BARCODE);//получаем его
            End_Products = strncmp(BARCODE, fail, 8); //сравниваем с 0 
        }
        //Далее реализуем печать чека в виде:
        //чек «наименование – стоимость за единицу (для упрощения в рублях без копеек) – количество – общая стоимость за товар».
        printf("---------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------\n");
        printf("Чек \n");//заголовок чека
        printf("Наименование товара  Цена за ед. рублей  Кол-во Стоимость со скидкой \n");
        for (int i = 0; i < product_counter; ) {//пробегаемся по всему каталогу 

            if (total_number_of_product[i] > 0) {//если  i-ый элемент в массиве, который хранит количество выбранных продуктов, не равен 0,
                //то высчитываем итоговую скидку и печатаем информацию о товаре 
                float final_price_with_sale = (total_number_of_product[i]) * ((st[i]->price) * (100 - (st[i]->sale)) / 100);
                printf("%-20s %-20d %-6d %-3f\n", st[i]->name, st[i]->price, total_number_of_product[i], final_price_with_sale);
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
        printf("Общая скидка:%f %%\n", 100 - (100 * sum_with_sale) / sum);
        printf("Цена со скидкой:%f руб.\n", sum_with_sale);
        printf("До встречи!");
        getchar();
        system("cls");//очищаем экран перед следующим покупателем
    }
}

//ищет среди массива структур по штрихкоду нужный продукт и возвращает номер: st[возвращаемый номер] 
//char* SearchProduct(char* BARCODE, const struct product* st[]) это если вернуть строку
int SearchProduct(char* BARCODE, const struct product* st[]) {
    //char* selected_product;//
    int res;
    int bool = 0;//считаем количество который уже сравнили 
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
    return -1;//возвращаем минус один если продукт не найден в каталоге
}

//функция печатающая ассортимент товара
void view_product_catalog(unsigned int product_counter, const struct product* st[]) {
    printf("Каталог товара\n");
    for (int i = 0; i < product_counter; i++) {
        printf("%-12s \t цена %-5d  \t  штрихкод %-6s скидка  %-2d %% \n", st[i]->name, st[i]->price, st[i]->barcode, st[i]->sale);
    }
}