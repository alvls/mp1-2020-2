#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 11  //���������� ������
int setdlina(float n)//���������� ����� ������������� �����(� 2 ������� ����� �������)
{
	int B = n, i;
	for (i = 0; B > 0; i++)
		B = B / 10;
	return(i+3);
}
void probel_print(int n)//�������� ������ ����� �������� ��� ������������, n-����� ��������
{
	for (int i = 0; i < n; i++)//�������� �������
		printf(" ");
}
void clean(void)//������� ����� �����
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
float stoimost(int stoimost, int sale)//������� ��������� � ������ ������. ���������� stoimost - ��������� ������ ��� ������ 
{
	int s;
	s= (stoimost*((100-sale))/100);
	return (s);
}
void main()
{
	int kod, i,t,  flag=0, n, dlin, dlin2;//kod-� ��� ������������ ��� ������, ��������� �������������; i,t-��������; n-������������� ����� ���������� cena;
	//dlin-����������, � ������� ������������ ���������� ��������, ��� ����� ��� ������������ �������� ���������� cena �� ������� ����(��� ������������ ����)
	int dlina[3];//����� � ���������
	int count[N] = {0};//������ ���������, � �������� �������� ������������ ���������� ������� ������
	int sale[N] = { 40, 15, 15, 5, 10, 15, 10, 10, 20, 5, 5 };//������ ������
	float nach_stoimost[N] = { 1500, 3000, 250, 150, 800, 200, 150, 150, 1500, 600, 500 };
	char* tovar[N] = {"��������� ��� ��� 2113-2115", "����� ��������������� �� �������� ��� ��� 2113-2115", //������ � ���������� �������
		"����� ��������� ��� ��� 2113-2115", "������� ��� ��� 2113 - 2115", "������� ��� ������������� ��� 2109", "������ ����������� ����������� �������� ��� ��� 2109", 
		"�������� ��������� �������� ������", "����� ���������������", "�������� ��������� �� - 03", "��������� ������� ������ ��� ��� 2109 - 2115", 
		"��������� ������� �������� ��� ��� 2109 - 2115"};
	char* tovar_number[N] = {"1001", "2001", "3001", "3002", "3101", "3102", "4001", "4002", "4003", "5001", "5002"};//������ � ������ ������� ������
    float st[N];// ������ �������� ��������� ������� ������(�� ���� �����) � ������ ������
	float sum = 0, cena;//sum - ����������, � ������� ������������ ����� ����� �������; cena - �������� ��������� ������� ������ ���������� �� ���������� ����� ������
	setlocale(LC_ALL, "Russian");
	printf("���������� � �������: \n");
	for (i = 0; i < N; i++)
	{
		printf("%s ", tovar_number[i]);
		printf(" - ");// ����������� ���� ������ � �������� ������. ���������� ��� �������� ����������
		printf("%s \n", tovar[i]);
	}
	printf("������� �����-��� ������ (����������� �������������� ����� �� ������������� ������). ��� ��������� ���� ������� 0: \n");
	while (flag!=1)
	{
		scanf_s("%d", &kod);
		while (((kod < 1000) && (kod>0)) || (kod > 9999) || (kod<0))
		{
			clean();//������ ����� �����
			printf("������� ������������ �������� �����-���� ������, ����������� ������: \n");
			scanf_s("%d", &kod);
		}
		switch (kod)//� ���� ����� ���� �������������� ���� ������ � ����� �������� ������� � ����������� �� ���� ������
		{
		case 1001:
			i = 0;
			break;
		case 2001:
			i = 1;
			break;
		case 3001:
			i = 2;
			break;
		case 3002:
			i = 3;
			break;
		case 3101:
			i = 4;
			break;
		case 3102:
			i = 5;
			break;
		case 4001:
			i = 6;
			break;
		case 4002:
			i = 7;
			break;
		case 4003:
			i = 8;
			break;
		case 5001:
			i = 9;
			break;
		case 5002:
			i = 10;
			break;
		case 0:
			flag = 1;//������� �� �����
			break;
		default: 
			printf("������ ������ ��� � ��������, ����������� ������: \n");
			i = -1;
			break;
		}
		if ((flag != 1)&&(i>=0))//� ���� ����� �������� ����� ��������� �� �����, ���� ������� ��������� ������ � ������ ������, � ������ count ������������ ���������� ������� ������
		{
			st[i] = stoimost(nach_stoimost[i], sale[i]);//������ ����� � ������� - ���� ��� ������, ������ - ������ � %
			count[i]++;
			printf("%s\n", tovar[i]);
			printf("��������� ������: %5.2f", nach_stoimost[i]);
			printf(" ���\n");
			printf("��������� ������ � ������ ������: %5.2f", st[i]);
			printf(" ���\n");
		}
	}
	printf(" \n");
	printf("��� \n");
	for (i = 0; i < N; i++)//��������� ���
	{
		if (count[i] > 0)
		{
			printf("%s\n", tovar[i]);//�������� ������
			printf("��������� ������ �� �������: ");
			dlin2 = 70 - 33 - setdlina(nach_stoimost[i]);//70 - ����� ���� ������, 33 - ��������� ���������� ����� ������� "��������� ������ �� �������: " � " ���" 
			probel_print(dlin2);//�������� ������ ��� ������������ ����� ��������
			printf("%5.2f", nach_stoimost[i]);//�������� ��������� ������ ��� ������
			printf(" ���\n");
			dlina[0] = printf("��������� ������ �� �������: %5.2f", st[i]);//���������� ����� �������� ��������� ������� ������(�� ���� �����) � ������ ������
			dlina[1] = printf(" � %d", count[i]);//���������� ����� ������, ���������� ���� "�" � ���������� ������
			printf(" ��");
			cena = st[i] * count[i];
			n = cena;
			dlina[2] = setdlina(n);//���������� ����� ������ ���������� cena
			dlin = dlina[0] + dlina[1] + dlina[2] + 3 + 4;//���������� � ���������� dlin ����� ����� ��������. 3 - ����� ������ " ��", 4 - ����� ������ " ���"
			dlin = 70 - dlin;//��������� ����� ��������. 70 - ����� ���� ������ � ����� �� ������� ������, ����������� ������ � �������� ����� ����� ������(���� �� ����� * ����������)
			probel_print(dlin);//�������� ������ ��� ������������ ����� ��������
			printf("%6.2f", cena);
			printf(" ���\n");
			printf("������ �� �����: %d", sale[i]);
			printf(" %%\n");
			sum = sum + cena;//����������� �������� �������� ����� �������
			printf(" \n");
		}
	}
	printf(" \n");
	printf("�������� �����: %9.2f", sum);
	printf(" ������\n");
	system("pause");
}