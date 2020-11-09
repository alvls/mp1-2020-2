/*Разработать программу «Электронная касса».

Программа должна имитировать работу кассового аппарата по сканированию товаров и формированию чека за покупку.
Каждый товар идентифицируется штрих-кодом. Штрих-код хранится в виде массива из четырех символов. Каждый символ принимает значение от ‘0’ до ‘9’.
Один и тот же товар может сканироваться несколько раз, но в чек информация о каждом товаре входит в виде: «наименование – стоимость за единицу 
(для упрощения в рублях без копеек) – количество – общая стоимость за товар». Чек состоит не менее чем из одной записи указанного вида. 
Чек дополнительно включает общую стоимость товаров в покупке, суммарную скидку и итоговую сумму к оплате (все в рублях). Каждый товар описывается 
штрих-кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости. Скидки устанавливаются на каждый товар независимо 
(в диапазоне от 5% до 50% с шагом 5%).
Программа должна предоставлять следующие операции:
    «сканировать» очередной товар,
    вывести описание отсканированного товара,
    добавить данные о товаре в чек,
    сформировать чек за покупку,
    рассчитать итоговую сумму к оплате.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>


#define ARR_SIZE 13 //Если что-то добавится, то нужно обязательно изменить данное значение  /*Размер массива*/
#define MAX_LENGTH_CODE 4 //Максимальное значение длины кода

//Объявление глобальных переменных
const char* code[ARR_SIZE] = { "0043","1004", "1982", "2002", "3072", "3717", "4598", "4880", "5740", "7572", "8554", "9203", "9735" };//Штрих-коды
const char* tovar[ARR_SIZE] = { "ОГУРЦЫ Гладкие, 1 кг", "ТОМАТЫ сливовидные, 600 г", "ЗЕЛЕНЬ Ассорти, 100 г", "Грибы ШАМПИНЬОНЫ, 250 г", "ТОМАТЫ солёные, красные, 800 г", "ЯБЛОКИ «Голден», 1 кг", "ГРАНАТ, 1 кг", "ГРЕЙПФРУТЫ, 1 кг", "ТЫКВА Мини, 1 кг", "Хлебцы ЩЕДРЫЕ, Гречневые, 100 г", "Вафли ЯШКИНО, 300 г", "Печенье ЮБИЛЕЙНОЕ, 112 г", "Печенье ЧОКО БОЙ (Орион), 45 г" }; //Наименования товаров
/*Длина строки для каждого товара не должна превышать 40 символов*/
const double price[ARR_SIZE] = { 59.90, 75.90, 39.90, 69.90, 89.90, 79.90, 89.90, 99.90, 69.90, 29.90, 49.90, 19.90, 39.90 }; //Цены товаров
int discount[ARR_SIZE] = { 0 }; //Скидка на товар
double pricewithdisc[ARR_SIZE] = { 0 }; //Цена с учётом скидки на товар
int kolvotovarov[ARR_SIZE] = { 0 }; //Количество товаров
int poryadokv4eke[ARR_SIZE] = { 0 }; //Порядок в чеке
int k = 0; //Переменная, в которой содержится информация для порядка товаров в чеке
int i = 0, j = 0; //Добавил в глобальные переменные, чтобы каждый раз не объявлять /*Счётчики для циклов*/

//Объявление функций
int convertcharinint(int intcode[ARR_SIZE]);  //Значения штрих-кодов хранятся в двумерном массиве char'ов - его обработка и сравнение с пользовательскими данными будет занимать много ресурсов, поэтому сразу преобразуем все штрих-коды в числовые значения
void setdiscounts(); //Задаёт значение скидкам + подсчитывает цену на товар с учётом скидки //Один раз на всю программу
void smartwhitespace(int size); //Умные отступы для столбца (именно для этой функции важно, что длина наименования товара не должна быть >40. Т.к. эти данные вводятся разработчиком, то вывод об ошибке не требуется)
void fullvivod(); //Выводит все данные по товарам в виде таблицы
void onevivod(int i); //Выводит один отсканированный товар + всю информацию по нему
void inputinf(int intcode[ARR_SIZE]); //Забирает и обрабатывает штрих-код
void print4ek(); //Выводит чек на экран
int menu(int intcode[ARR_SIZE]); //Меню для навигации по приложению
void printgran(); //Печатает недостающие границы для чека

void main()
{
    setlocale(LC_ALL, "Russian"); //Поддержка русского языка

    int intcode[ARR_SIZE] = {0}; //Объявил не в глобальных переменных, потому что этот массив не требовался и не давался в задаче /*Массив численных значений штрих-кодов*/
    convertcharinint(intcode); 

    setdiscounts(); 

    int vixod; //Проверка на выход из меню
    do
    {
        printf("\n");
        vixod = (menu(intcode));
    } while (vixod != 2);
    system("pause");
}

int menu(int intcode[ARR_SIZE])
{
    int c = 0;
    system("cls");
    fullvivod();
    printf("Выберите что нужно сделать:\n1. Сканировать новый товар\n2. Сформировать чек за покупку\n");
    scanf_s("%d", &c);
    switch (c)
    {
    case 1:
        printf("\n");
        inputinf(intcode);
        return 1;
    case 2:
        if (k != 0)
        {
            print4ek(); //Напечатать чек
            return 2;
        }
        else
        {
            printf("Товары не были выбраны. Невозможно сформировать чек за покупку\n\n\t");
            system("pause");
            return 0;
        }
    default:
        printf("Данная функция не предусмотрена в программе\n\n\t");
        system("pause");
        return 0;
    }
}

int convertcharinint(int intcode[ARR_SIZE])
{
    int stepdecyat;
    for (i = 0; i < ARR_SIZE; i++)
    {
        stepdecyat = 1;
        for (j = MAX_LENGTH_CODE; j > 0; j--)
        {
            intcode[i] += (code[i][j - 1] - '0') * stepdecyat;
            stepdecyat *= 10;
        }
    }
    return (intcode[ARR_SIZE]);
}

void setdiscounts()
{
    srand(time(NULL));
    for (i = 0; i < ARR_SIZE; i++)
    {
        discount[i] = 5 * (rand() % 10 + 1);
        /*
        //Либо так:
        printf("Введите значение скидки в диапазоне от 5% до 50% с шагом 5%:\n");
        scanf_s("%f",&discount[i]);
        */
        pricewithdisc[i] = price[i] - (price[i]) * (discount[i]) / 100;
    }
}

void smartwhitespace(int size) 
{
    if (size < 40)
        printf("\t");
    if (size < 32)
        printf("\t");
    if (size < 24)
        printf("\t");
    if (size < 16)
        printf("\t");
    if (size < 8)
        printf("\t");
}

void fullvivod()
{
    int size; //Информация по размеру строки
    printf("\n\t\t\tМагазин \"Магнит у дома\" предоставляет следующие товары:\n\n");
    printf(" Штрих-код\t\tНаименование товара\t\tРублей за шт.\tСкидка\tИтого рублей за шт.\n");
    for (i = 0; i < ARR_SIZE; i++)
    {
        printf("    "); //Пустота, искусственно созданная для красоты
        size = strlen(code[i]);
        for (j = 0; j < size; j++)
        {
            printf("%c", code[i][j]);
        }
        printf("\t");
        size = strlen(tovar[i]);
        for (j = 0; j < size; j++)
        {
            printf("%c", tovar[i][j]);
        }
        smartwhitespace(size);
        printf("%9.2f\t%4d%%\t%13.2f\n", price[i], discount[i], pricewithdisc[i]);
    }
    printf("\n");
}

void onevivod(int i)
{
    int size = strlen(tovar[i]); //Информация по размеру строки
    printf("\nВы выбрали товар \"");
    for (j = 0; j < size; j++)
    {
        printf("%c", tovar[i][j]);
    }
    printf("\".\nЦена товара: %.2f руб.\nСкидка на этот товар: %d%%\nЦена со скидкой: %.2f руб.\nТовар автоматически добавлен в корзину.\nВсего в корзине: %d шт.\n\n\t", price[i], discount[i], pricewithdisc[i], kolvotovarov[i]);
    system("pause");
}

void inputinf(int intcode[ARR_SIZE])
{
    int polzcode = 0; //Штрих-код, введённый пользователем
    printf("Введите штрих-код нужного Вам товара:\n");
    scanf_s("%d", &polzcode);
    for (i = 0; i < ARR_SIZE; i++)
        if (intcode[i] == polzcode)
            break;
    if (i == ARR_SIZE)
    {
        printf("Код введён неправильно, либо отсутствует в базе данных\n");
        inputinf(intcode);
    }
    else
    {
        if (k<ARR_SIZE)
        {
            poryadokv4eke[k] = i;
            for (j = 0; j < k; j++)
                if (poryadokv4eke[k] == poryadokv4eke[j])
                {
                    poryadokv4eke[k] = -1;
                    k--; //Тогда значение k не изменится
                }
            k++;
        }
        kolvotovarov[i]++; //Товар добавлен в корзину
        onevivod(i);
    }
}

void printgran()
{
    printf("|");
    for (int z = 0; z < 74; z++)
        printf(" ");
    printf("|\n");
}

void print4ek()
{
    double pricewithkolvoanddisc[ARR_SIZE] = { 0 };
    double itog = 0;
    double skidka = 0;
    system("cls");
    for (i = 0; i < ARR_SIZE; i++)
        pricewithkolvoanddisc[i] = kolvotovarov[i] * pricewithdisc[i];  
    for (i = 0; i < 76; i++)
        printf("_");
    printf("\n|\t\t\t\tКассовый чек\t\t\t\t   |\n|");
    printf("                |");
    for (i = 0; i < 42; i++) //Штрих-код чека
    {
        int r = rand() % 2;
        if (r == 0)
            printf("|");
        else
            printf(" ");
    }
    printf("|\t\t   |\n");
    printgran();
    for (i = 0; i < k; i++)
    {
        int c = poryadokv4eke[i] + 1; //Чтобы, если все товары не были куплены, 0 был показателем того, что нужно закончить вывод чека
        if (c == 0)
            break;
        c--; //Возвращаем диапазон значений для переменной с (от 0 до 12)
        int size = strlen(tovar[c]);
        printf("| ");
        for (j = 0; j < size; j++)
        {
            printf("%c", tovar[c][j]);
        }
        smartwhitespace(size + 2);
        printf("(%6.2f - %2d%%) x %3d = %8.2f\t   |\n", price[c], discount[c], kolvotovarov[c], pricewithkolvoanddisc[c]);
        itog += pricewithkolvoanddisc[c];
        skidka += price[c] * kolvotovarov[c] - pricewithkolvoanddisc[c];
        printgran();
    }
    printf("| ИТОГОВАЯ СУММА К ОПЛАТЕ: %8.3f руб.\t\t\t\t   |\n| Благодаря скидкам в нашем магазине, Вы сэкономили: %8.3f руб.\t   |\n", itog, skidka);
    printgran();
    printf("|\t\t     Спасибо за покупку! Приходите ещё!\t\t\t   |\n");
    for (i = 0; i < 76; i++)
        printf("_");
    printf("\n");
}
