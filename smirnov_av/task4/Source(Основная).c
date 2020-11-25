#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 14 //���-�� �������

/*
*
����������� ��������� ������������ �����.

��������� ������ ����������� ������ ��������� �������� �� ������������ ������� � ������������ ���� �� �������.

������ ����� ���������������� �����-�����. �����-��� �������� � ���� ������� �� ������� ��������. ������ ������ ��������� �������� �� �0� �� �9�.

���� � ��� �� ����� ����� ������������� ��������� ���, �� � ��� ���������� � ������ ������ ������ � ����: ������������� � ��������� �� ������� (��� ��������� � ������ ��� ������) � ���������� � ����� ��������� �� �����.

��� ������� �� ����� ��� �� ����� ������ ���������� ����. ��� ������������� �������� ����� ��������� ������� � �������, ��������� ������ � �������� ����� � ������ (��� � ������).

������ ����� ����������� �����-�����, �������������, ���������� �� ������� ������, ������� � ��������� �� ���������. ������ ��������������� �� ������ ����� ���������� (� ��������� �� 5% �� 50% � ����� 5%).

��������� ������ ������������� ��������� ��������:

������������� ��������� �����,
������� �������� ���������������� ������,
�������� ������ � ������ � ���,
������������ ��� �� �������,
���������� �������� ����� � ������.*/

char check_numbers[SIZE][4] = { "1501","1024","6035","7234","1952","1316","3721","1428","9430","1410","1854","2803","7421","0021"}; //�����-����
char products[SIZE][17] = { "������� 300�","����� ����","������� 150�","�������� 1��","����� lays 90�", "�������","��� 150�",
"������ ����","�������","������ 220�","������ mamba","����","���������","��������� �����"};//�������� ���������
int prices[SIZE] = { 350,27,156,30,75,60,130,27, 38, 80,50,200,56,60}; //����
int kolvo_products[SIZE] = { 0 }; //���-�� ������� ��������
int sequence_ind[SIZE] = { 0 }; //������������������ �������� ��� ������������
int ch; //����� ���-�� ��������������� ���������
double sales_prices[SIZE] = { 0 }; //������ ��� �� �������(����������� �������� � ����� 5% ��� ������� ���������)

int scan_check(char mas_code[]) //�������������� �����, ���������� ��� ������
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (mas_code[j] == check_numbers[i][j])
				flag++;
		}
		if (flag == 4)
			return i;
		flag = 0;
	}
	if (flag != 4)
	{
		printf("������ �����-���� �� �����������, ���������� ��� ���\n");
		return -1;
	}
}

void kolvo_index_sequence(int i) //������� ���-�� � ���������� ������������������ ��������������� �������
{
	kolvo_products[i]++;
	if (kolvo_products[i] > 1)
		return;
	sequence_ind[ch] = i;
	ch++;
}

void print_codes() //������� �� ����� ������ ������� �� �����-������
{
	int i = 0;
	int j = 0;
	int g = 0;
	for ( i = 0; i < SIZE; i++)
	{
		for (g = 0; g < 4; g++)
		{
			printf("%c", check_numbers[i][g]);
		}
		printf(" ");
		for (j = 0; j < 17; j++)
		{
			printf("%c", products[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void sales() //��������� ������ + ���������� ������� ��� �� ��������
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

void show_information(int ind) //����� ������������ ������� �������� ���� ��� ������ + ������ + ���� �� �������
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%c", products[ind][i]);
	}
	printf("����: %d� ", prices[ind]);
	if (prices[ind] > sales_prices[ind])
	{
		printf("������:%.0lf%% ", 100.0 - sales_prices[ind] / prices[ind] * 100);
		printf("���� �� ������� :%.1lf�", sales_prices[ind]);
	}
	printf("\n");
}

void print_check() //�������� ���
{
	int i = 0;
	int j = 0;
	printf("%-17s", "��������:");
	printf("%-20s","���� ��� ������:");
	printf("%-20s","���� �� �������:");
	printf("%-15s","����������:");
	printf("�����:");
	printf("\n");
	for (i; i < ch; i++)
	{
		for (j=0; j < 17; j++)
		{
			printf("%c", products[sequence_ind[i]][j]); //��������
		}
		printf("%7.d�", prices[sequence_ind[i]]); //����
		printf("%22.2lf�", sales_prices[sequence_ind[i]]); //���� �� �������
		printf("%15.d", kolvo_products[sequence_ind[i]]); //���-�� ���������
		printf("%13.lf�\n", sales_prices[sequence_ind[i]] * kolvo_products[sequence_ind[i]]); //����� ��������� ������� ��������
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	char code[4] = {"0"};
	int i = 0;
	int flag = 0;
	char c; //��� ������� �����
	int final_price = 0; //���� � ������ ������
	int total_price = 0; //���� ��� ������
	int index_products = -1; //������ ���������������� �������� � ������� �����-�����
	int choice;//����� ������������ � ������ ������ ����� � �������� �������

	sales(); //��������� ������ ��� �� �������
	printf("������������, ��� ����������� ���������-������, ������ ������������ �� ������� ������� � �� �����-������?1-�� 2-���\n");
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
			printf("������ �����, ���������� ��� ���: ");
	}
	while (choice != 2);
	printf("����� ��������� ������������ � �������� ��� ���, �������� 0000\n");
	while (flag != 4) 
	{
		printf("������� �����-���:");
		while ((c = getchar()) != '\n');
		flag = 0;
		for (i = 0; i < 4; i++)
		{
			scanf_s("%c", &code[i]);
			 if(code[i] == '0')
				flag++;
		}
		if (flag == 4)
			break;
		index_products = scan_check(code);
		if (index_products == -1)
			continue;
		kolvo_index_sequence(index_products);
		total_price += prices[index_products]; 
		final_price += sales_prices[index_products];
		show_information(index_products);
		printf("\n");
	}
	printf("\n");
	print_check();
	printf("\n");
	printf("����� ���������:%d�\n", total_price);
	printf("������:%d�\n", total_price - final_price);
	printf("� ������:%d�\n", final_price);
	system("pause");
}