#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define ALL 7
//������� ������ �����-��� � ��������� ������ ��� ���� ������� � �������, ���� ���� �� ����� ������� �� ���� � ���� ������
char rx580[5] = { '1','2','4','3','\0' };
char gtx1050[5] = { '5','1','3','6','\0' };
char gtx1050ti[5] = { '5','1','2','8','\0' };
char rx460[5] = { '3','0','1','4','\0' };
char gtx1660[5] = { '8','3','9','1','\0' };
char gt710[5] = { '5','8','1','4','\0' };
char rtx3090[5] = { '2','6','3','1','\0' };
char names[ALL][20] = { "AMD RADEON RX580", "NVIDIA GTX1050", "NVIDIA GTX1050TI", "AMD RADEON RX460", "NVIDIA GTX1660", "NVIDIA GT710", "NVIDIA RTX3090" };
float prices[ALL] = { 19990 ,7650 ,13020 ,6340 ,19720 ,3220 ,190000 };//��������� ������
int i = 0, j = 0;//�������� ��� ������
int kol[ALL] = { 0 };//������ ��� ������������� ���-�� ������� � �������
float discount[ALL] = { 0.1,0.05,0.2,0.1,0.25,0.05,0.5 };//������ ������ �� ������ �����

void console() // ������� ������� ����� ������� ����
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}




void clean()//������� ������ �����
{

	int c;
	do
	{
		c = getchar();
	} while ((c != '\n') && (c != EOF));

}

int check(char vvod[])//�������� ������� ����(4 ������� �� 0 �� 9)
{
	int f = 0;
	if (strlen(vvod) == 4)//�������� �� ������ ��������� ������
	{
		for (i = 0; i < 4; i++)
			if ((vvod[i] >= '0') && (vvod[i] <= '9'))//�������� �� ������������ �������� �����-����
				f = 1;
			else
			{
				f = 0;
				break;
			}

	}
	return(f);
}

void code(char vvod[])//c�������� ���������� �����-���� � ����� ������ � ����� ���������� ������
{
	int num = -1;//������ �������
	if (strcmp(vvod, rx580) == 0)//��������� ��������� ������ �� �������� �������� �����-�����
	{
		kol[0]++;
		num = 0;
	}
	else
		if (strcmp(vvod, gtx1050) == 0)
		{
			kol[1]++;
			num = 1;
		}
		else
			if (strcmp(vvod, gtx1050ti) == 0)
			{
				kol[2]++;
				num = 2;
			}
			else
				if (strcmp(vvod, rx460) == 0)
				{
					kol[3]++;
					num = 3;
				}
				else
					if (strcmp(vvod, gtx1660) == 0)
					{
						kol[4]++;
						num = 4;
					}
					else
						if (strcmp(vvod, gt710) == 0)
						{
							kol[5]++;
							num = 5;
						}
						else
							if (strcmp(vvod, rtx3090) == 0)
							{
								kol[6]++;
								num = 6;
							}
	if (num == -1)//���� ���������� ���
		printf("���� %s ��� � ���� ������,���������� ������ ������\n", vvod);
	else//����� ������� ��� ����������
		printf("���������� %-30s ����(���)=%.0f \n������ �� ����� ����������= %.0f%%\n", names[num], prices[num], (discount[num] * 100));

}

void timesec()//������� ��� ������ ������� � ���
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	printf("%s", str);
}

void main()
{
l:
	setlocale(LC_ALL, "Russian");
	char vvod[10];//��� ��������� �����-����
	int flag = -1;//���� ��� �������� ������� ����(������������ �������� ������� check) � ����� ��� ������ �������� ������ ���� � ����� ���������
	int n = 1;//��� ������ ������ (0-������ ����,1-���������� ������)
	char c = ' ';//���  ����� ��������� ���������� ���������� ������
	float fp = 0, fd = 0, pr = 0;//fp-��������� �������,fd-����� ������,pr-��� �������� ���� ��������� ������� ����� � ������ ������
	for (i = 0; i < ALL; i++)
		kol[i] = 0;//��������� ����� ����� �����
	for (j = 0; j < 20; j++)//����� �� ������� ���������� �� ���� �������
		printf("-");
	printf("������ � �������");
	for (j = 0; j < 20; j++)
		printf("-");
	printf("\n");
	printf("�����-��� %6c �������� %-20c ���������\n", c, c);
	printf("%-17s%s%19.0f\n", rx580, names[0], prices[0]);
	printf("%-17s%s%20.0f\n", gtx1050, names[1], prices[1]);
	printf("%-17s%s%19.0f\n", gtx1050ti, names[2], prices[2]);
	printf("%-17s%s%18.0f\n", rx460, names[3], prices[3]);
	printf("%-17s%s%21.0f\n", gtx1660, names[4], prices[4]);
	printf("%-17s%s%22.0f\n", gt710, names[5], prices[5]);
	printf("%-17s%s%22.0f\n", rtx3090, names[6], prices[6]);


	while (n != 0)
	{

		printf("������� 1 ��� ���������� ������ ��� 0 ��� ���������� �������\n");
		scanf_s("%d", &n);
		if (n == 1)
		{
			printf("������� �����-���,��������� �� 4 ����\n");
			clean();
			gets(vvod);

			flag = check(vvod);//�������� ��� ������, ���� ������ ���������� ���� ������ ������� ��� � ����� �����
			if (flag == 1)
				code(vvod);
			else
				printf("������ �����-���� �������, ���������� ������ ��� ��� ���\n");

		}

	}
	if (n == 0)//������ ����
	{
		console();//������ �������
		flag = 0;
		for (i = 0; i < ALL; i++)//���� �� ������� ��������� ������� ������, ���� ���� ��� ��� �� ������ �� ������� ��������������
			if (kol[i] > 0)
				flag = 1;
		if (flag == 0)
			printf("� ������� ��� �� ������ ������\n");
		else
		{
			for (j = 0; j < 22; j++)//����������
				printf("-");
			printf("���");
			for (j = 0; j < 23; j++)
				printf("-");
			printf("\n");
			for (i = 0; i < ALL; i++)//���� �� ������� ��������� � ������� ������ �������� � ���������� ����������, ������� �� � ���
				if (kol[i] != 0)
				{
					pr = kol[i] * prices[i] * (1 - discount[i]);//��������� �� �������
					printf("%-20s X%-4d ����(���/��)=%-4.0f \n������=%.0f%% %7c ����� ���������(���)=%.0f\n", names[i], kol[i], prices[i], (discount[i] * 100), c, pr);
					fp += pr;//����� �������
					fd += prices[i] * kol[i] - pr;//����� ������


				}
			for (j = 0; j < 48; j++)//����������
				printf("-");
			printf("\n");
			printf("����� �������(���)=%.0f\n����� ������(���)=%.0f\n", fp, fd);//������� � ����� ����� ������ � ����� �������
			timesec();//������� �����

			for (j = 0; j < 48; j++)//����������
				printf("-");
			printf("\n");




		}
		printf("��� �������� ������ ���� ������� 1, ��� ������ �� ��������� ������� ����� �������\n");//���������� ������� ����� ���
		scanf_s("%d", &flag);
		if (flag == 1)
		{
			console();
			goto l;
		}


	}
}
