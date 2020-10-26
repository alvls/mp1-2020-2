#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void rules() //������� ������ ������ ��� �������������
{
	int start = 0;
	printf("�������:\n");
	printf("����� n = 4.\n����� �������� ����� �3219�.(���������� ����� �� ����� ��������� ���������� �����!\n����� ���� ����� �2310�\n");
	printf("���������: ��� ��������(��� ����� : �2� � �3� � ������� �� �������� ��������) � ���� ����(���� ����� �1� ������� ������ �� �������).\n");
	printf("������ ����? ������� 1 ��� ������ ����: ");
	while (start != 1)
	{
		scanf_s("%d", &start);
		if (start == 1)
		{
			system("cls");
			return;
		}
		else
			printf("������ �����, ���������� ��� ���: ");

	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0; //������ �����
	int guess = 0; //��������������� �������������
	int array[5]; //������ � ���������������� �������
	int array_guess[5]; //������ �� ���� ����������������� �����
	int candidate = 0; //�������� �� ����� � ������� ��������������� ����� 
	int i = 0; //�������
	int	j = 0; //�������
	int flag = 0;
	int choice = 0; // ��� ������ ������������� ������ ��� ���
	int cow = 0; // ������
	int	bull = 0; //����
	int attempts = 0; //�������
	int guess_size = 0; // ���-�� ���� � ��������� ������������� �����
	int clone_guess = 0; //���� ���������� ������������� �����
	srand(time(NULL));

	printf("����� ���������� � ���� ���� � ������\n");
	printf("������ ������������ � ��������� ����? 1 = �� 2 = ���\n");
	scanf_s("%i", &choice);
	
	if (choice == 1)
		rules();
	
	while (size < 2 || size > 5) // �������� �� ����������� �������� ����
	{
		printf("������� ����� ����� �� 2 �� 5: ");
		scanf_s("%d", &size);
		if (size < 2 || size > 5)
			printf("����� �� ������������� ���������, ���������� ��� ���\n");
	}

	system("cls");
	printf("����� ����������� ����� = %d\n", size);
	printf("�������� ����:)\n");

	array[0] = rand() % 9 + 1; //��������� ������ 0 �� ������ ������� � �����

	for (i = 1; i < size; i++) //�������� ������� ��������������� �����
	{
		candidate = rand() % 10;
		for(j=0;j < i;j++)
		{
			if (array[j] == candidate)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			array[i] = candidate;
		else
		{
			i--;
			flag = 0;
		}
	}


	//for (i = 0; i < size; i++) //����� ������� ��� ����������� �������� ���������  
	//{
	//	printf("%d ",array[i]);
	//}
	//printf("\n");
	
	while (bull != size) //�������� �� �������� ����
	{
		cow = 0;
		bull = 0;
		guess_size = 0;
		while (guess_size != size) //�������� �� ����������� ������� ���������� �����
		{
			printf("������� �������: ");
			scanf_s("%d", &guess);
			clone_guess = guess; //����� �� �������� �������� ���������� ����������

			while (clone_guess != 0) //���������� ���-�� ���� � ��������� ����� 
			{
				clone_guess /= 10;
				guess_size++;

			 }

			if (guess_size != size) //����� ������
			{
				printf("������ �����, ���� ������� �� ����� ������� ���������� �����, ���������� ��� ���\n");
				guess_size = 0;
				continue;
			}

			clone_guess = guess; //������� ����� �������� guess

			for (i = size - 1; i >= 0; i--) //�������������� ���������� ����� � ������ 
			{
				array_guess[i] = clone_guess % 10;
				clone_guess /= 10;
			}
		}
		
		
		printf("\n���� ������� = %d\n", guess);

		for (i = 0; i < size; i++) //���������� ����
		{
			for (j = 0; j < size; j++)
			{
				if (array[i] == array_guess[j] && i != j)
					cow++;
				if (array[i] == array_guess[j] && i == j)
					bull++;
			}
		}

		printf("����� = %d\n", cow);
		printf("����� = %d\n", bull);
		attempts++;
		
		}

	printf("����������, �� �������!\n");
	printf("���������� ����������� ������� = %d\n", attempts);

	system("pause");
}