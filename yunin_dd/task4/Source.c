//����������� ���������.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<limits.h>
	//���������� ��������.
#define SIZE_OF_ARRAY_OF_CHAR  100
#define SIZE_OF_ARRAY_OF_CODES  100
#define SIZE_OF_ARRAY_OF_SHRIX 15

	//���������� ���������� � �������.
char  names[][SIZE_OF_ARRAY_OF_CHAR] = { "���������� ������� \"����\"", "������ ������ \"���������\" 800�.",
		"������� 500�.\"���������� ��������\"", "������� \"����������\" 320�.", "������� ���� \"�������\" 900�.", "������ \"�������\" 900�.",
		"������� \"����������\" 130�.", "������ \"�������������\" 150�.", "��� \"����������\" 230�.", "��������� ����� \"����������\"",
		"������� � �������� \"�����\" 48�.", "������ ������� \"�����\" 500�.", "������ ��� ��������� \"�����\" 12�.", "���� \"�������������\" 70�.",
		"���������� ������� \"��������\" 1,5��.", "�������� ��� ����� ������ \"�����\" 900�.", "�������� �������� \"�����\" 400�.", "�������� ������� \"������ ����\" 100�.",
		"�������� \"������ �����\" 90�.", "������� \"������ �� �����\" 420�.", "���� � �������� \"�������\" 70�.", "������ \"�������\" 100�.",
		"������� \"�������\" 910�.","������� ���� \"�����\" 90�.","������� ���� \"�����\" 90�." };
char namesshtrixcodes[][SIZE_OF_ARRAY_OF_SHRIX] = { "\"0 0 0 0\"", "\"0 0 0 1\"", "\"0 0 0 2\"", "\"0 0 0 3\"", "\"0 0 0 4\"", "\"0 0 0 5\"", "\"0 0 0 6\"", "\"0 0 0 7\"", "\"0 0 0 8\"", "\"0 0 0 9\"",
			"\"0 0 1 0\"", "\"0 0 1 1\"", "\"0 0 1 2\"", "\"0 0 1 3\"","\"0 0 1 4\"", "\"0 0 1 5\"", "\"0 0 1 6\"", "\"0 0 1 7\"", "\"0 0 1 8\"", "\"0 0 1 9\"","\"0 0 2 0\"", "\"0 0 2 1\"","\"0 0 2 2\"",
			"\"0 0 2 3\"", "\"0 0 2 4\"" };
//int firstnum, secondnum, thirdnum, fournum;
//������� �������� ��������� �������������.
int InShtrixCode()
{
	int firstnum, secondnum, thirdnum, fournum, shtrix_code,count_of_var;
	printf("������� �����-���, ��������� �� 4 ���� �� \"0\" �� \"9\" � �������, ������ ����� ������� ����� ������.\n");
	printf("������� �����-��� ������:\n");
	count_of_var = scanf_s("%d %d %d %d", &firstnum, &secondnum, &thirdnum, &fournum);
	//��������, �� ��, ��� �������� � ��������� �� 0 �� 9(��������, � ������� �����)!
	if (count_of_var != 4)
	{
		shtrix_code = -2;
		return shtrix_code;
	}
	shtrix_code = firstnum * 1000 + secondnum * 100 + thirdnum * 10 + fournum * 1;
	return shtrix_code;
}
//������� �������� ���������� �� ����������� ����������.
void InInstruction()
{
	printf("\t����� ���������� � ���������-��������� ������� ������� ������������ \"����\"!\n");
	printf("��������� ������������, ������ ��� ����� ���������� ���������� �� ����������� ����������.\n");
	printf("\t\t\t���������� �� �����������:\n");
	printf("1.��� ������ ��� ����� ��������� ������ �������(�� ������������ � �����-����), �� ������ ������� ��� �� �����, ���� ������ \"5\".\n");
	printf("2.����� ���� ��� �� ���������� ������ �������, ��������� ��� ��������� ������ �����-��� ������, ������� �� ������ ������!\n");
	printf("3.����� ����� ��������� ������� �� ����� ��� ��������������� ���������� � ������:\n");
	printf("\t1.�����-��� ������.\n");
	printf("\t2.������������ ������.\n");
	printf("\t3.��������� �� ������� ������.\n");
	printf("\t4.������ �� �����.\n");
	printf("4.���� �������� �������� ����� � �������, ������� \"1\"\n");
	printf("\t\t\t������ ����������, ����� ��������� �������� ������ ������� � �������� �����-���� \"0 0 0 -1\"\n");
	printf("5.����� ����, ��� ��������� �������� ������, ��������� ��������� ��� �������� ���, ����� ����������� ������� \"1\"\n");
	printf("6.������ ��������� ������� �� ����� ���, �� ���� ����������� � �������\n");
	printf("�� ���� ��, ����� ���, ��������� ������������ ��������� �����������!\n");
}
//������� ������� � ������� ������ �������.
void PrintListProducts(int count_products)
{
	/*
	char nameproducts[][SIZE_OF_ARRAY_OF_CHAR] = { "���������� ������� \"����\", \"0 0 0 0\", 1000 ��.\"","\"0 0 0 1\", ������ ������ \"���������\" 800�., 15 ��.",
	"\"0 0 0 2\", ������� 500�.\"���������� ��������\", 25 ��.","\"0 0 0 3\", ������� \"����������\" 320�., 20 ��.","\"0 0 0 4\", ������� ���� \"�������\" 900�., 15 ��.",
	"\"0 0 0 5\", ������ \"�������\" 900�., 22 ��.","\"0 0 0 6\", ������� \"����������\" 130�., 9 ��.","\"0 0 0 7\", ������ \"�������������\" 150�., 13 ��.",
	"\"0 0 0 8\", ��� \"����������\" 230�., 7 ��.","\"0 0 0 9\", ��������� ����� \"����������\" , 45 ��.","\"0 0 1 0\", ������� � �������� \"�����\" 48�., 80 ��.",
	"\"0 0 1 1\", ������ ������� \"�����\" 500�., 15 ��.","\"0 0 1 2\", ������ ��� ��������� \"�����\" 12�., 23 ��.",
	"\"0 0 1 3\", ���� \"�������������\" 70�., 17 ��.","\"0 0 1 4\", ���������� ������� \"��������\" 1,5��., 5 ��.","\"0 0 1 5\", �������� ��� ����� ������ \"�����\" 900�., 18 ��.", 
	"\"0 0 1 6\", �������� �������� \"�����\" 400�., 9 ��.","\"0 0 1 7\", �������� ������� \"������ ����\" 100�., 17 ��.","\"0 0 1 8\", �������� \"������ �����\" 90�., 42 ��.",
	"\"0 0 1 9\", ������� \"������ �� �����\" 420�., 10 ��.","\"0 0 2 0\", ���� � �������� \"�������\" 70�., 29 ��.","\"0 0 2 1\", ������ \"�������\" 100�., 12 ��.", 
	"\"0 0 2 2\", ������� \"�������\" 910�., 11 ��.","\"0 0 2 3\", ������� ���� \"�����\" 90�., 8 ��.","\"0 0 2 4\", ������� ���� \"�����\" 90�., 7 ��." };
	*/
	int i;
	printf("� ���� ������ ����� ������������ �����-���� �������, ������������ �������, �� ���������� � ������������.\n");
	printf("\t\t\t������ �������:\n");
	for ( i = 0; i < count_products; i++)
	{
		printf("%d.%s %s\n",i, namesshtrixcodes[i],names[i]);
	}
	/*printf("0.������ �������� - ���������� ������� \"����\", \"0 0 0 0\", 1000 ��.\n");
	printf("1.������ ���������:\n	\"0 0 0 1\", ������ ������ \"���������\" 800�., 15 ��.\n");
	printf("\t\"0 0 0 2\", ������� 500�.\"���������� ��������\", 25 ��.\n");
	printf("\t\"0 0 0 3\", ������� \"����������\" 320�., 20 ��.\n");
	printf("\t\"0 0 0 4\", ������� ���� \"�������\" 900�., 15 ��.\n");
	printf("2.�������� ���������:\n");
	printf("\t\"0 0 0 5\", ������ \"�������\" 900�., 22 ��.\n");
	printf("\t\"0 0 0 6\", ������� \"����������\" 130�., 9 ��.\n");
	printf("\t\"0 0 0 7\", ������ \"�������������\" 150�., 13 ��.\n");
	printf("\t\"0 0 0 8\", ��� \"����������\" 230�., 7 ��.\n");
	printf("3.����������:\n");
	printf("\t\"0 0 0 9\", ��������� ����� \"����������\" , 45 ��.\n");
	printf("\t\"0 0 1 0\", ������� � �������� \"�����\" 48�., 80 ��.\n");
	printf("\t\"0 0 1 1\", ������ ������� \"�����\" 500�., 15 ��.\n");
	printf("\t\"0 0 1 2\", ������ ��� ��������� \"�����\" 12�., 23 ��.\n");
	printf("4.������� �����:\n");
	printf("\t\"0 0 1 3\", ���� \"�������������\" 70�., 17 ��.\n");
	printf("\t\"0 0 1 4\", ���������� ������� \"��������\" 1,5��., 5 ��.\n");
	printf("\t\"0 0 1 5\", �������� ��� ����� ������ \"�����\" 900�., 18 ��.\n");
	printf("\t\"0 0 1 6\", �������� �������� \"�����\" 400�., 9 ��.\n");
	printf("5.��������");
	printf("\t\"0 0 1 7\", �������� ������� \"������ ����\" 100�., 17 ��.\n");
	printf("\t\"0 0 1 8\", �������� \"������ �����\" 90�., 42 ��.\n");
	printf("\t\"0 0 1 9\", ������� \"������ �� �����\" 420�., 10 ��.\n");
	printf("\t\"0 0 2 0\", ���� � �������� \"�������\" 70�., 29 ��.\n");
	printf("6.����� � ������:\n");
	printf("\t\"0 0 2 1\", ������ \"�������\" 100�., 12 ��.\n");
	printf("\t\"0 0 2 2\", ������� \"�������\" 910�., 11 ��.\n");
	printf("\t\"0 0 2 3\", ������� ���� \"�����\" 90�., 8 ��.\n");
	printf("\t\"0 0 2 4\", ������� ���� \"�����\" 90�., 7 ��.\n");*/
}
void PrintCheckForUser()
{
	printf("��������� ������������, �� �������� ����������� ���� ������!\n");
	printf("�������� ���, ������� \"1\", ����� �������� ����� ������� � ���������� ���!\n");
}
//������� ������� � ���������.
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	//���������� ��������.
	int discount[SIZE_OF_ARRAY_OF_CODES] = { 0 };//������ ������ �� ������.
	int prize[SIZE_OF_ARRAY_OF_CODES] = { 3, 240, 320, 190, 300, 60, 35, 80, 200, 5, 37, 120, 50, 25, 470, 270,
		110, 90, 65, 200, 45, 100, 184, 80, 85 };//������ ��� �� ������.
	int num[SIZE_OF_ARRAY_OF_CODES] = { 0 };//������ ���������� ������� �� �������.
	int sum_thing[SIZE_OF_ARRAY_OF_CODES] = { 0 };//������ �������� ���� �� ������ �� �������.
	/*
	char  names[][SIZE_OF_ARRAY_OF_CHAR] = { "���������� ������� \"����\"", "������ ������ \"���������\" 800�.",
		"������� 500�.\"���������� ��������\"", "������� \"����������\" 320�.", "������� ���� \"�������\" 900�.", "������ \"�������\" 900�.",
		"������� \"����������\" 130�.", "������ \"�������������\" 150�.", "��� \"����������\" 230�.", "��������� ����� \"����������\"",
		"������� � �������� \"�����\" 48�.", "������ ������� \"�����\" 500�.", "������ ��� ��������� \"�����\" 12�.", "���� \"�������������\" 70�.",
		"���������� ������� \"��������\" 1,5��.", "�������� ��� ����� ������ \"�����\" 900�.", "�������� �������� \"�����\" 400�.", "�������� ������� \"������ ����\" 100�.",
		"�������� \"������ �����\" 90�.", "������� \"������ �� �����\" 420�.", "���� � �������� \"�������\" 70�.", "������ \"�������\" 100�.",
		"������� \"�������\" 910�.","������� ���� \"�����\" 90�.","������� ���� \"�����\" 90�." };
	*/
	// ���������� ����������.
	int shtrix_code, knop1, count_var, count_products = 25, i, ran, count_all = 0, sum_prize = 0;
	//shtrix_code - ����������, ���������� �� �����-��� ������.
	//knop1 - ����������-������ ��� �����������.
	//count_var - ����������, ������� ������� ���������� ������������ ����������.
	//count_products - ���������� �������, �������������� � ��������.
	//i - �������.
	//ran - ���������� ��� ������������ ������ �� ������.
	//count_all - ���������� ���� ������� � �������.
	//sum_prize - ����� ������� ��� ������.
	double sum_discount = 0, itog = 0;
	//sum_discount - �������� ����� ������.
	//itog - ����� � ������.
	InInstruction();
	printf("��������� ������������, ������ �� ������� ������ ������� �� �����?\n");//������ ������ ������ ������������, ����� ��� ����������!
	printf("����� �������� ������ �� ����� ������� \"1\".\n");
	count_var = scanf_s("%d", &knop1);
	if (count_var != 1)
	{
		printf("\t\t\t��������, ������ �����, ��������� ����!");
		return 0;
		system("pause");
	}
	while (knop1 != 1)
	{
		printf("��������� ������������, ������� ����� ������, �� ������� ������� �������� ����� �����, ������� \"1\"!\n");
		knop1 = 0;
		scanf_s("%d", &knop1);
	}
	PrintListProducts(count_products);
	for (i = 0; i < count_products; i++)
	{
		ran = rand() % 11;
		discount[i] = 5 * ran;
	}
	do
	{
		shtrix_code = InShtrixCode();
		if (shtrix_code == -2)
		{
			printf("��� �������� �����-���� ���� ������������ ������������ �������!\n");
			return 0;
			system("pause");
		}
		if ((shtrix_code >= 0) && (shtrix_code < 25))
		{
			for (i = 0; i < count_products; i++)
			{
				if (shtrix_code == i)
				{
					printf("����� ������ - %d\n", shtrix_code);
					printf("������������ ������ - %s\n", names[i]);
					printf("��������� �� ������� ������ - %d\n", prize[i]);
					printf("������ �� ����� - %d\n", discount[i]);
					printf("���� �� ������ �������� ����� � ��� ������� 1, ���� �� ������ ������� 0!\n");
					scanf_s("%d", &knop1);
					if (knop1 == 1)
					{
						num[i]++;
					}
					break;
				}
			}
		}
		else if (shtrix_code == -1)
		{
			;
		}
		else
		{
			printf("��������� ������������, ������ �����-���� ���!\n");
		}
	} while (shtrix_code != -1);
	PrintCheckForUser();
	scanf_s("%d", &knop1);
	for (i = 0; i < count_products; i++)
	{
		sum_thing[i] = num[i] * prize[i];
		if (num[i] != 0)
		{
			sum_discount += (((double)prize[i] / 100) * discount[i] * num[i]);
			count_all += num[i];
			sum_prize += num[i] * prize[i];

		}
	}
	if (count_all == 0)
	{
		printf("�� ������ �� ������, ������ � ��� ��� �� �����!\n");
		system("pause");
		return 0;
	}
	printf("�������� ���...\n");
	printf("\t\t\t���\n");
	for (i = 0; i < count_products; i++)
	{
		if (num[i] != 0)
		{
			printf("%s  ", names[i]);//������������ ������.
			printf("%d  ", prize[i]);//���� �� �����.
			printf("%d  ", num[i]);//���������� ������.
			printf("%d\n", sum_thing[i]);//�������� ����� �� �����.
		}
	}
	printf("����� ������ ������� %.2f ������ \n", sum_discount);
	itog = ((double)sum_prize) - sum_discount;
	printf("�������� ����� � ������ %.2f ������\n", itog);
	printf("\t\t\tC������ �� �������, ��������� ���!\n");
	printf("����������� ���, ���� �� ����� ���������� � �� �� ��������� ���������� �������� ������� \"1\", ���� �� ���������� � �� ��������� ���������� �������� ������� \"0\" \n");
	knop1 = 0;
	scanf_s("%d", &knop1);
	if (knop1 == 1)
	{
		main();
	}
	else
	{
		;
	}
	system("pause");
}