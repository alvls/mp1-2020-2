#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
	setlocale(LC_ALL, "Russian");
	int mode;
	int repeat = 0;

	while (repeat != 2) 
	{
		system("cls");
		printf("����� 1: � ��������� �����, � �� ��� ����������\n");
		printf("����� 2: �� ����������� �����, � � ��� ��������\n");
		printf("��� ������ ���� �������� �����: ");
		scanf_s("%d", &mode);

		if (mode == 1)
		{

			system("cls");
			printf("�� ������� ����� 1, �������� ���� :)\n");

			srand(time(NULL));
			int num = rand() % 1000 + 1;
			int guess = 0;
			unsigned int i = 0;

			printf("� ������� ����� �� 1 �� 1000, ����������� ��� �������\n");

			while (guess != num)
			{
				printf("������� ���� �������������: ");
				scanf_s("%d", &guess);
				if (guess > num)
					printf("���������� ���-������ ��������\n");
				else if (guess < num)
					printf("���������� ���-������ ��������\n");

				i++;
			}
			printf("����������, �� �������!!!\n");
			printf("����� ����������� ������� = %d\n", i);


		}
		else if (mode == 2)
		{
			int num=0;
			int guess;
			unsigned int i = 0;
			int min = 1;
			char sign = ' ';
			int max = 1000;

			system("cls");
			printf("�� ������� ����� 2, �������� ���� :)\n");
			
			while ((num < 1) || (num > 1000))
			{
				printf("��������� ����� �� 1 �� 1000: ");
				scanf_s("%d",&num);
				
				if ((num < 1) || (num>1000))
				{
					printf("����� �� ������ � ������� ���������, ���������� ��� ���\n");
				}
			}
			

				while (sign != '=')
				{
					srand(time(NULL));
					guess = rand() % (max - min + 1) + min;
				l:	printf("���� ����� > < ��� = %d? ", guess);
					while (sign = getchar() != '\n');
					scanf_s("%c", &sign);


					switch (sign)
					{
					case '>':
						min = guess + 1; //����� ����� ��� ���������� �� �����������
						i++;
						break;
					case '<':
						max = guess - 1; //����� ����� ��� ���������� �� ����������� 
						i++;
						break;
					case '=':
						printf("����� �� ������� :)");
						break;

					default:
						printf("������������ ������\n");
						goto l;  //������� � ��������� > < =


					}

				}
				printf("� ������ � %d �������\n", i);
			
		}
		else
			printf("� �� ���� ������ ������, ���������� ��� �����\n");
		printf("��� �����? 1 = ��:) 2 = ���:( ");
		scanf_s("%d",&repeat);
	}
}