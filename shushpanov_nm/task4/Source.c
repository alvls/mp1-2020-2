#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<malloc.h>

char* name[300];
unsigned int price;
char* barcode[30];
unsigned int productCounter = 9;

struct product* productAdd(char* name, unsigned int price, char* barcode);
int productSearch(char* BARCODE, const struct product* massiv[]);
int productCheck(char* BARCODE, const struct product* massiv[]);
void viewCatalog(unsigned int productCounter, const struct product* massiv[]);

struct product
{
    char* name[100];
    unsigned int price;
    char* barcode[100];
    int sale;
};

struct product* productAdd(char* name, unsigned int price, char* barcode, int sale)
{
    struct product* massivProductList = malloc(sizeof(struct product));
    strcpy_s(massivProductList->name, 300, name);
    massivProductList->price = price;
    strcpy_s(massivProductList->barcode, 30, barcode);
    massivProductList->sale = sale;
    return massivProductList;
    free(massivProductList);
}

int productSearch(char* BARCODE, const struct product* massiv[])
{
    int res;
    int bool = 0;
    int resCheck = 0;
    while (bool != productCounter)
    {
        for (int i = 0; i < productCounter; i++)
        {
            res = strncmp(BARCODE, massiv[i]->barcode, 8);
            if (res == 0)
            {
                bool = productCounter;
                return i;
            }
            else if (res != 0)
            {
                bool++;
            }
        }
    }
}

int productCheck(char* BARCODE, const struct product* massiv[])
{
    int res;
    int resP = 0;
    int resM = 0;
    int bool = 0;
    while (bool != 1)
    {
        for (int i = 0; i < productCounter; i++)
        {
            if (strncmp(BARCODE, massiv[i]->barcode, 8) == 0)
            {
                bool = 1;
                resP++;
            }
            else
            {
                bool = 1;
                resM--;
            }
        }
    }
    if (resP > 0)
    {
        return resP;
    }
    else if (resM < 0)
    {
        return resM;
    }
}

void viewCatalog(unsigned int productCounter, const struct product* massiv[])
{
    printf("Каталог товара\n");
    printf("\n");
    printf("Наименование товара                                     | Цена руб. | Штрихкод  | Скидка %%\n");
    for (int i = 0; i < productCounter; i++)
    {
        printf("%-12s %-12d %-11s %d  \n", massiv[i]->name, massiv[i]->price, massiv[i]->barcode, massiv[i]->sale);
    }
}

void main() 
{
    setlocale(LC_ALL, "Rus");
    char BARCODE[100];
    float sum = 0, sumSale = 0;
    int productTotal[10] = {0}, checkBarcode = 1, productEnd, checkBarcodeResult;
    struct product* massiv[100];
    massiv[0] = productAdd("Моторное масло SHELL Helix HX8 Synthetic 5W-40 4л         ", 1800, "0001", 30);
    massiv[1] = productAdd("Моторное масло MOBIL Ultra 10W-40 4л                      ", 1000, "0002", 10);
    massiv[2] = productAdd("Моторное масло MOBIL Super 3000 X1 Diesel 5W-40 4л        ", 1900, "0003", 20);
    massiv[3] = productAdd("Моторное масло SHELL Helix HX7 10W-40 4л                  ", 1200, "0004", 15);
    massiv[4] = productAdd("Моторное масло GAZPROMNEFT Premium N 5W-40 4л             ", 1190, "0005", 0);
    massiv[5] = productAdd("Моторное масло Mannol Molibden Benzin 10W-40 4л           ", 939, "0006", 50);
    massiv[6] = productAdd("Моторное масло G-Energy SYNTHETIC SUPER START 5W-30 4л    ", 1300, "0007", 10);
    massiv[7] = productAdd("Моторное масло Rinkai 5w30 синтетическое, CF/SN/GF-5 4л   ", 1099, "0008", 25);
    massiv[8] = productAdd("Моторное масло ROLF Energy 10W-40 SL/CF 4л                ", 959, "0009", 65);
    printf("------Электронная касса------\n"); 
    printf("\n");
    viewCatalog(productCounter, massiv);
    printf("\n");
    char fail[2] = "0";
    checkBarcodeResult = productCheck(BARCODE, massiv);
    productEnd = strncmp(BARCODE, fail, 8);
    while (productEnd != 0)
    {
        printf("Введите штрихкод или 0 для показа чека!\n");
        printf("Штрихкод: ");
        gets(BARCODE);
        checkBarcodeResult = productCheck(BARCODE, massiv);
        if (checkBarcodeResult > 0)
        {
            printf("Вы выбрали: %s | Цена за единицу %d руб. | Скидка %d процентов \n", massiv[productSearch(BARCODE, massiv)]->name, massiv[productSearch(BARCODE, massiv)]->price, massiv[productSearch(BARCODE, massiv)]->sale);
            printf("\n");
            productTotal[productSearch(BARCODE, massiv)] ++;
        }
        else
        {
            printf("\n");
            printf("Товар не существует!\n");
            printf("\n");
        }
        productEnd = strncmp(BARCODE, fail, 8);
    }
    printf("\n");
    printf("------Чек------\n");
    printf("\n");
    printf("Наименование товара                                     | Цена руб. | Количество  | Цена со скидкой \n");
    for (int i = 0; i < productCounter; ) 
    {
        if (productTotal[i] > 0)
        {
            float finalPrice = (productTotal[i]) * ((massiv[i]->price) * (100 - (massiv[i]->sale)) / 100);
            printf("%-5s %-14d %-14d %0.1f\n", massiv[i]->name, massiv[i]->price, productTotal[i], finalPrice);
            i++;
        }
        else
        {
            i++;
        }
    }
    for (int j = 0; j < productCounter; j++)
    {
        sum = sum + ((productTotal[j]) * (massiv[j]->price));
    }
    for (int j = 0; j < productCounter; j++)
    {
        float finalPrice = (productTotal[j]) * ((massiv[j]->price) * (100 - (massiv[j]->sale)) / 100);
        sumSale = sumSale + (finalPrice);
    }
    printf("\n");
    printf("Общая сумма без скидки: %0.1f руб.\n", sum);
    printf("Общая скидка: %0.1f %%\n", 100 - (100 * sumSale) / sum);
    printf("Цена со скидкой: %0.1f руб.\n", sumSale);
    printf("\n");
    printf("Приходите к нам еще!\n");
    system("pause");
}