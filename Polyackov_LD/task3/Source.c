/*����������� ���������, ����������� ���� ����� � �������.
���������� (�������)

	������ ��� ������ (������� � ���������).
	����� �������� ����� ������������� ����� � n (�� 2 �� 5).
	��������� ����������� n-������� ����� � ���������������� �������.
	����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.
	��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� ����� (�� ���� ���������� �����) � 
	������� ������� ������ �� ������� � ���������� ����� (�� ���� ���������� �����).
	����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.

������

	����� n = 4.
	����� �������� ����� �3219�.
	����� ���� ����� �2310�.
	���������: ��� �������� (��� �����: �2� � �3� � ������� �� �������� ��������) � ���� ���� (���� ����� �1� ������� ������ �� �������).*/

//����������� ��������� 
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
//������ �������
#define ARRAY_SIZE 5

/*�� ������: ����� ��� ����� ���� ��������� � { }.
��� ������� ��� ��������, ������ ��� ������ ��������� ��������� �������� ����������� �����
� ��������������� �������� ������ �� ���, ��� ����� ���-�� ���������/������ */

//����� ������
int rules(int n)
{
	if ((n < 2) || (n > 5)) //��� ������� ����� �����, ����� ��������� � ������ ������ ������ �������, � ����� �������� ������ ��� �������� ���� � ������
	{
		system("cls");
		printf("������� ����:\n������ ��� ������ (������� � ���������).\n����� �������� ����� ������������� ����� � n (�� 2 �� 5).\n��������� ���������� n - ������� ����� � ���������������� �������.\n����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.\n��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����\n(�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� �����\n(�� ���� ���������� �����).\n����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.\n\n");
	}
	else
	{
		system("cls");
		printf("��������� ������� %d-������� �����\n", n);
		printf("������ - ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����\n��� - ������� ���� ������� � ����������� � �� ��������� � ���������� �����\n\n");

	}
}

//������� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	//���������� ����������

	int n; // ����� ������������� �����
	int mas[ARRAY_SIZE] = { 0 }; // ������ ��� �������� �����
	int polznum; //�����, �������� �������������
	int kolvopolzcifr; // ����� �����, ��������� �������������
	int polzmas[ARRAY_SIZE] = { 0 }; //���������������� ������ ����
	int i, j; //���������� ��� �����
	int bik; //���������� �����
	int cow; //���������� �����
	int pop; //���������� ������� �� ������ ������
	int konec = 0; //���������� ��� ��������� ����� ��������� ����
	int vibor; //���������� ��� ������� ������� ������������

	while (konec != 333) //��� ��� ������ - 333
	{
		//������������� ���������
		{
			printf("� ���, � ������� ����� �������� � ���� \"���� � ������\"!\n");
			vibor = 0;
			n = 0;
			while ((vibor < 1) || (vibor > 3))
			{
				printf("�� ������:\n1.������� � ���� \"���� � ������\"\n2.������ ������� ����\n3.����� �� ����\n");
				scanf_s("%d", &vibor);
				if ((vibor < 1) || (vibor > 3))
				{
					printf("������ ������� �����������\n");
					continue;
				}
				if (vibor == 3)
				{
					konec = 1;
					polznum = 0;
					break;
				}
				if (vibor == 2)
				{
					rules(0);
					vibor = 0; //����� ����� ������� � ����� while 
					continue;
				}
				if (vibor == 1)
				{
					printf("������, ������� ��������� � ����\n");
				}
			}

		}

		//����� �������� ��������� ���� � ����� ������������� ����� � n (�� 2 �� 5).
		{
			n = 0;
			if (konec != 1)
			{
				while ((n < 2) || (n > ARRAY_SIZE))
				{
					printf("�������� ����� ������������� ����� (�� 2 �� 5)\n");
					scanf_s("%d", &n);
					if ((n < 2) || (n > ARRAY_SIZE))
						printf("������ ������� �����������\n");
				}
			}
		}

		//��������� ����������� n-������� ����� � ���������������� �������.
		{
			if (konec != 1)
			{
				srand(time(NULL));
				for (i = 0; i < n; i++)
				{
					if (i != 0)
					{
						mas[i] = rand() % 10; //�������� �����, ��������� ����� ������
					}
					else
					{
						mas[i] = rand() % 9 + 1; //�������� ������ ����� � ��������� �� 1 �� 9, ��� ����� ����� ����� �� ���������� � "0"
					}

					//printf("����� %d: %d\n", i+1, mas[i]); //�������� ����������������� ����

					for (j = 0; j < i; j++)
					{
						if (mas[i] == mas[j])
						{
							i--; //� ����� � ��� ����������� i++, ��� ������� �������� �������� i ���������� ��� ����� ���������
							break;
						}
					}
				}
			}
		}

		//����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������. + ������� ����� � �����
		{
			if (konec != 1)
			{
				bik = 0;
				pop = 0;
				rules(n);
				//�������� ����������������� ���� (��� ������� ����������������)
				{
					printf("(������ ��� �������� ������������) ��������� ������� �����: ");
					for (int i = 0; i < n; i++)
						printf("%d", mas[i]);
					printf("\n");
				}
				while ((bik != n) && (konec != 1))
				{
					polznum = 0;
					while ((polznum < 1) || (polznum > 99999))
					{
						printf("������� ");
						if (pop != 0)
						{
							printf("����� ");
						}
						printf("%d-������� ����� ����� � ���������������� ������� (����� �������, ������� 1): ", n);
						scanf_s("%d", &polznum);
						if ((polznum < 1) || (polznum > 99999))
							printf("������ ������� �����������\n");

					}
					if (polznum == 1)
					{
						konec = 1;
						break;
					}
					//������ ������ �� ������, �������� �������������
					i = n - 1;
					kolvopolzcifr = 0;
					while (polznum > 0)
					{
						polzmas[i] = polznum % 10;
						//printf("����� %d: %d\n", i+1, polzmas[i]); //�������� ����������������� ����
						polznum = polznum / 10;
						//printf("���� �����: %d\n", polznum); //�������� ����������������� ����
						i--;
						kolvopolzcifr++;
					}
					if (kolvopolzcifr != n)
					{
						printf("�� ����� %d-������� ����� - ��� �� �������� %d-�������\n", kolvopolzcifr, n);
						continue;
					}
					bik = 0;
					cow = 0;
					for (i = 0; i < n; i++)
					{
						for (j = 0; j < n; j++)
						{
							if (mas[i] == polzmas[j])
							{
								if (i == j)
									bik++;
								else
									cow++;
							}
						}
					}
					printf("���������� ����� ��� ����� �����: %d\n", cow);
					printf("���������� ����� ��� ����� �����: %d\n\n", bik);
					pop++;
				}
				if ((bik == n)&&(konec!=1))
				{
					printf("����������, �� �������� ���������� �����!\n");
					printf("��������� ������� �����: ");
					for (i = 0; i < n; i++)
						printf("%d", mas[i]);
					printf("\n");
					printf("����������� ����� �������: %d\n", pop);
				}
				if (konec == 1)
				{
					printf("�� ���������������! � ��������� ��� � ��� ����� ���������!\n");
					printf("�� ��������� ������, � ����� ����������� �������: %d\n", pop);
				}
				
				
			}
		}
		if ((konec == 1)&&(polznum!=1))
		{
			printf("����� ����, ���� �� ���������� ������������ ����� ���������!\n");
			konec = 333; //��� ��� ������ �� ����������
		}
		else
		{
			vibor = 0;
			polznum = 0;//�� �������
			while ((vibor < 1) || (vibor > 2))
			{
				printf("�� ������ �������:\n\t1.�e������� � ����\n\t2.��������� ������ ����������\n");
				scanf_s("%d", &vibor);
				if ((vibor < 1) || (vibor > 2))
				{
					printf("������ ������� �����������\n");
					continue;
				}
				if (vibor == 1)
				{
					konec = 0;
					system("cls");
				}
				if (vibor == 2)
					konec = 333; //��� ��� ������ �� ���������
			}
		}
	}
	system("pause");
}