/*����������� ��������� ������������ �����.

��������� ������ ����������� ������ ��������� �������� �� ������������ ������� � ������������ ���� �� �������.
������ ����� ���������������� �����-�����. �����-��� �������� � ���� ������� �� ������� ��������. ������ ������ ��������� �������� �� �0� �� �9�.
���� � ��� �� ����� ����� ������������� ��������� ���, �� � ��� ���������� � ������ ������ ������ � ����: ������������� � ��������� �� ������� 
(��� ��������� � ������ ��� ������) � ���������� � ����� ��������� �� �����. ��� ������� �� ����� ��� �� ����� ������ ���������� ����. 
��� ������������� �������� ����� ��������� ������� � �������, ��������� ������ � �������� ����� � ������ (��� � ������). ������ ����� ����������� 
�����-�����, �������������, ���������� �� ������� ������, ������� � ��������� �� ���������. ������ ��������������� �� ������ ����� ���������� 
(� ��������� �� 5% �� 50% � ����� 5%).
��������� ������ ������������� ��������� ��������:
    ������������� ��������� �����,
    ������� �������� ���������������� ������,
    �������� ������ � ������ � ���,
    ������������ ��� �� �������,
    ���������� �������� ����� � ������.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>


#define ARR_SIZE 13 //���� ���-�� ���������, �� ����� ����������� �������� ������ ��������  /*������ �������*/
#define MAX_LENGTH_CODE 4 //������������ �������� ����� ����

//���������� ���������� ����������
const char* code[ARR_SIZE] = { "0043","1004", "1982", "2002", "3072", "3717", "4598", "4880", "5740", "7572", "8554", "9203", "9735" };//�����-����
const char* tovar[ARR_SIZE] = { "������ �������, 1 ��", "������ �����������, 600 �", "������ �������, 100 �", "����� ����������, 250 �", "������ ������, �������, 800 �", "������ �������, 1 ��", "������, 1 ��", "����������, 1 ��", "����� ����, 1 ��", "������ ������, ���������, 100 �", "����� ������, 300 �", "������� ���������, 112 �", "������� ���� ��� (�����), 45 �" }; //������������ �������
/*����� ������ ��� ������� ������ �� ������ ��������� 40 ��������*/
const double price[ARR_SIZE] = { 59.90, 75.90, 39.90, 69.90, 89.90, 79.90, 89.90, 99.90, 69.90, 29.90, 49.90, 19.90, 39.90 }; //���� �������
int discount[ARR_SIZE] = { 0 }; //������ �� �����
double pricewithdisc[ARR_SIZE] = { 0 }; //���� � ������ ������ �� �����
int kolvotovarov[ARR_SIZE] = { 0 }; //���������� �������
int poryadokv4eke[ARR_SIZE] = { 0 }; //������� � ����
int k = 0; //����������, � ������� ���������� ���������� ��� ������� ������� � ����
int i = 0, j = 0; //������� � ���������� ����������, ����� ������ ��� �� ��������� /*�������� ��� ������*/

//���������� �������
int convertcharinint(int intcode[ARR_SIZE]);  //�������� �����-����� �������� � ��������� ������� char'�� - ��� ��������� � ��������� � ����������������� ������� ����� �������� ����� ��������, ������� ����� ����������� ��� �����-���� � �������� ��������
void setdiscounts(); //����� �������� ������� + ������������ ���� �� ����� � ������ ������ //���� ��� �� ��� ���������
void smartwhitespace(int size); //����� ������� ��� ������� (������ ��� ���� ������� �����, ��� ����� ������������ ������ �� ������ ���� >40. �.�. ��� ������ �������� �������������, �� ����� �� ������ �� ���������)
void fullvivod(); //������� ��� ������ �� ������� � ���� �������
void onevivod(int i); //������� ���� ��������������� ����� + ��� ���������� �� ����
void inputinf(int intcode[ARR_SIZE]); //�������� � ������������ �����-���
void print4ek(); //������� ��� �� �����
int menu(int intcode[ARR_SIZE]); //���� ��� ��������� �� ����������
void printgran(); //�������� ����������� ������� ��� ����

void main()
{
    setlocale(LC_ALL, "Russian"); //��������� �������� �����

    int intcode[ARR_SIZE] = {0}; //������� �� � ���������� ����������, ������ ��� ���� ������ �� ���������� � �� ������� � ������ /*������ ��������� �������� �����-�����*/
    convertcharinint(intcode); 

    setdiscounts(); 

    int vixod; //�������� �� ����� �� ����
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
    printf("�������� ��� ����� �������:\n1. ����������� ����� �����\n2. ������������ ��� �� �������\n");
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
            print4ek(); //���������� ���
            return 2;
        }
        else
        {
            printf("������ �� ���� �������. ���������� ������������ ��� �� �������\n\n\t");
            system("pause");
            return 0;
        }
    default:
        printf("������ ������� �� ������������� � ���������\n\n\t");
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
        //���� ���:
        printf("������� �������� ������ � ��������� �� 5% �� 50% � ����� 5%:\n");
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
    int size; //���������� �� ������� ������
    printf("\n\t\t\t������� \"������ � ����\" ������������� ��������� ������:\n\n");
    printf(" �����-���\t\t������������ ������\t\t������ �� ��.\t������\t����� ������ �� ��.\n");
    for (i = 0; i < ARR_SIZE; i++)
    {
        printf("    "); //�������, ������������ ��������� ��� �������
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
    int size = strlen(tovar[i]); //���������� �� ������� ������
    printf("\n�� ������� ����� \"");
    for (j = 0; j < size; j++)
    {
        printf("%c", tovar[i][j]);
    }
    printf("\".\n���� ������: %.2f ���.\n������ �� ���� �����: %d%%\n���� �� �������: %.2f ���.\n����� ������������� �������� � �������.\n����� � �������: %d ��.\n\n\t", price[i], discount[i], pricewithdisc[i], kolvotovarov[i]);
    system("pause");
}

void inputinf(int intcode[ARR_SIZE])
{
    int polzcode = 0; //�����-���, �������� �������������
    printf("������� �����-��� ������� ��� ������:\n");
    scanf_s("%d", &polzcode);
    for (i = 0; i < ARR_SIZE; i++)
        if (intcode[i] == polzcode)
            break;
    if (i == ARR_SIZE)
    {
        printf("��� ����� �����������, ���� ����������� � ���� ������\n");
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
                    k--; //����� �������� k �� ���������
                }
            k++;
        }
        kolvotovarov[i]++; //����� �������� � �������
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
    printf("\n|\t\t\t\t�������� ���\t\t\t\t   |\n|");
    printf("                |");
    for (i = 0; i < 42; i++) //�����-��� ����
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
        int c = poryadokv4eke[i] + 1; //�����, ���� ��� ������ �� ���� �������, 0 ��� ����������� ����, ��� ����� ��������� ����� ����
        if (c == 0)
            break;
        c--; //���������� �������� �������� ��� ���������� � (�� 0 �� 12)
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
    printf("| �������� ����� � ������: %8.3f ���.\t\t\t\t   |\n| ��������� ������� � ����� ��������, �� ����������: %8.3f ���.\t   |\n", itog, skidka);
    printgran();
    printf("|\t\t     ������� �� �������! ��������� ���!\t\t\t   |\n");
    for (i = 0; i < 76; i++)
        printf("_");
    printf("\n");
}
