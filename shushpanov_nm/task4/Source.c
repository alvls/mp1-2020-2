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
    printf("������� ������\n");
    printf("\n");
    printf("������������ ������                                     | ���� ���. | ��������  | ������ %%\n");
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
    massiv[0] = productAdd("�������� ����� SHELL Helix HX8 Synthetic 5W-40 4�         ", 1800, "0001", 30);
    massiv[1] = productAdd("�������� ����� MOBIL Ultra 10W-40 4�                      ", 1000, "0002", 10);
    massiv[2] = productAdd("�������� ����� MOBIL Super 3000 X1 Diesel 5W-40 4�        ", 1900, "0003", 20);
    massiv[3] = productAdd("�������� ����� SHELL Helix HX7 10W-40 4�                  ", 1200, "0004", 15);
    massiv[4] = productAdd("�������� ����� GAZPROMNEFT Premium N 5W-40 4�             ", 1190, "0005", 0);
    massiv[5] = productAdd("�������� ����� Mannol Molibden Benzin 10W-40 4�           ", 939, "0006", 50);
    massiv[6] = productAdd("�������� ����� G-Energy SYNTHETIC SUPER START 5W-30 4�    ", 1300, "0007", 10);
    massiv[7] = productAdd("�������� ����� Rinkai 5w30 �������������, CF/SN/GF-5 4�   ", 1099, "0008", 25);
    massiv[8] = productAdd("�������� ����� ROLF Energy 10W-40 SL/CF 4�                ", 959, "0009", 65);
    printf("------����������� �����------\n"); 
    printf("\n");
    viewCatalog(productCounter, massiv);
    printf("\n");
    char fail[2] = "0";
    checkBarcodeResult = productCheck(BARCODE, massiv);
    productEnd = strncmp(BARCODE, fail, 8);
    while (productEnd != 0)
    {
        printf("������� �������� ��� 0 ��� ������ ����!\n");
        printf("��������: ");
        gets(BARCODE);
        checkBarcodeResult = productCheck(BARCODE, massiv);
        if (checkBarcodeResult > 0)
        {
            printf("�� �������: %s | ���� �� ������� %d ���. | ������ %d ��������� \n", massiv[productSearch(BARCODE, massiv)]->name, massiv[productSearch(BARCODE, massiv)]->price, massiv[productSearch(BARCODE, massiv)]->sale);
            printf("\n");
            productTotal[productSearch(BARCODE, massiv)] ++;
        }
        else
        {
            printf("\n");
            printf("����� �� ����������!\n");
            printf("\n");
        }
        productEnd = strncmp(BARCODE, fail, 8);
    }
    printf("\n");
    printf("------���------\n");
    printf("\n");
    printf("������������ ������                                     | ���� ���. | ����������  | ���� �� ������� \n");
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
    printf("����� ����� ��� ������: %0.1f ���.\n", sum);
    printf("����� ������: %0.1f %%\n", 100 - (100 * sumSale) / sum);
    printf("���� �� �������: %0.1f ���.\n", sumSale);
    printf("\n");
    printf("��������� � ��� ���!\n");
    system("pause");
}