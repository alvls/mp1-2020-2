# include <stdio.h>
# include <math.h>
# include <locale.h>
# include <stdlib.h>

void main()
{
l:
	srand(time(NULL));
	int num = rand() % 1000 + 1;
	int r = 0, r1 = 0, n = 0, ch = 0, k = 0;// n-����� �������,r-������ ������,ch-����� �������� �������������� � 1-� ������ � 2-� �������,k-������ �� ������ ������,r1 ����� ������ � ����� ����
	char c;// ���������� ���  ������ �������� ������������� � 1-� ������
	int left = 1, right = 1000, mid;// ����� �������,������ �������,��������- ���������� ��� ������ 2-��� ������
	setlocale(LC_ALL, "Russian");
	printf("�������� ����� ���������\n");
	printf("1-��� ����������� �����, 2- ��� ����������� �����, 0- ��� ������ �� ���������\n");
	scanf_s("%d", &r);
	if (r == 0)
	{
		printf("�� ��������\n");
		system("pause");
		exit(0);
	}
	if (r == 1)
	{
		printf("��������� ������� �����,���� ������-�������� ��� ����� � ������� ��������� ����������\n");
		printf("����������� ������� �����\n");
		while (ch != num)
		{
			scanf_s("%d", &ch);
			if (ch < num)
				printf("���������� ����� ������\n");
			if (ch > num)
				printf("���������� ����� ������\n");
			n++;

		}
		if (ch == num)
			printf("�������\n");
		printf("���������� ������� ����� %d\n", n);
		system("pause");
	}
	if (r == 2)
	{
		printf("���� ������:�������� �����,������ ��������� ���������� �������.��� ����� ��� ���� ������ ��������� � ���� <\n ���� ���������� ����� ������, > ���� ���������� ����� \n ������ � = ���������� ����� ������� � ������, ������������ �����������\n");
		printf("�������� ����� �� 1 �� 1000\n");
		scanf_s("%d", &ch);
		while (k == 0)
		{
			if ((ch < 1) || (ch > 1000))
			{
				printf("���������� ������ �����  ��� ���\n");
				scanf_s("%d", &ch);
			}
			else
				k = 1;
		}

		while (left <= right)
		{
			n++;
			mid = (left + right) / 2;
			printf("����� %d\n", mid);
			scanf_s(" %c", &c);
			if (c == '=')
			{
				printf("������� ����� ����� %d\n", mid);
				printf("����� ������� ����� %d\n", n);
				break;
			}
			if (c == '<')
				right = mid - 1;
			if (c == '>')
				left = mid + 1;
		}
		system("pause");
	}
	printf("������ �� ������� ��� ���?(�������� 1 ��� ������,�������� 2 ��� �����������)\n");
	scanf_s("%d", &r1);
	if (r1 == 1)
	{
		printf("�� ��������\n");
		system("pause");
		exit(0);
	}
	if (r1 == 2)
		goto l;


}