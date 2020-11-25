#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10 //���-�� �������
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

int check_numbers[SIZE] = { 1001,1002,1003,1004,1005,1006,1007,1008,1009,1010 }; //���� �����-�����, ������ ����� �� 0
char products[SIZE][17] = { "������� 300�","����� ����","������� 150�","�������� 1��","����� Lays 90�", "�������","��� 150�","������ ����","�������","������ 220�" };//�������� ���������
int prices[SIZE] = { 350,27,156,30,75,60,130,27, 38, 80 }; //����
int kolvo_products[SIZE] = { 0 }; //���-�� ������� ��������
int sequence_ind[SIZE] = { 0 }; //������������������ �������� ��� ������������
int ch; //����� ���-�� ��������������� ���������
double sales_prices[SIZE] = { 0 }; //������ ��� �� �������(����������� �������� � ����� 5% ��� ������� ���������)

int scan_check(int code) //�������������� �����, ���������� ��� ������
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
			printf("������, ������ ���� ������ �� ����������, ���������� ��� ���\n");
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
	for (i = 0; i < SIZE; i++)
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

void sales() //��������� ������ + ���������� ������� ��� �� ��������
{
	srand(time(NULL));
	int k_sales;
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		k_sales = ((rand() % 11) * 5);
		sales_prices[i] = (100 - k_sales) * prices[i] / 100;
	}
}

void show_information(int ind) //����� ������������ ������� �������� ���� ��� ������ + ������ + ���� �� �������
{
	int size = sizeof(products[ind]) / sizeof(char);
	for (int i = 0; i < size; i++)
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
	printf("\n");
}

void print_check() //�������� ���
{
	int i = 0;
	int j = 0;
	printf("%-17s", "��������:");
	printf("%-20s", "���� ��� ������:");
	printf("%-20s", "���� �� �������:");
	printf("%-15s", "����������:");
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
	int code = 0;
	char c; //��� ������� �����
	int final_price = 0; //���� � ������ ������
	int total_price = 0; //���� ��� ������
	int index_products = -1; //������ ���������������� �������� � ������� �����-�����
	int choice; //����� ������������ � ������ ������ ����� � �������� �������

	sales();//��������� ������ ��� �� �������
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
	} while (choice != 2);
	printf("����� ��������� ������������ � �������� ��� ���, �������� ���������� 1234\n");
	while (code != 1234)
	{
		printf("������� �����-���:");
		scanf_s("%d", &code);
		if (code == 1234)
			break;
		index_products = scan_check(code);
		if (index_products == -1)
		{
			while ((c = getchar()) != '\n');
			continue;
		}
		kolvo_index_sequence(index_products); //�������� ������� ������, ����� ��������� ���-�� ����� �������� � ��������� ������� ���������� ���������
		total_price += prices[index_products];
		final_price += sales_prices[index_products];
		show_information(index_products);
		while ((c = getchar()) != '\n');
	}
	printf("\n");
	print_check();
	printf("\n");
	printf("����� ���������:%d�\n", total_price);
	printf("������:%d�\n", total_price - final_price);
	printf("� ������:%d�\n", final_price);
	system("pause");

}