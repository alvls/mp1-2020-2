#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define K 5
void main()
{
l:
	int arr[K] = { 0 };// ������ ��� �������� �����
	int i, n = 0, c = 0, j;//n-��� �������� ����������� ������������� �����,�-������������ ��� �������� ������� � ������ ����� �� ����� � ����� ����,i,j-��������
	int ch = 0, p = 0;//ch-���������� ��� ����� �������� �������������,p-���������� ��� ���� ����� ����������� �������������
	int bik = 0, kor = 0;//bik-���������� ����� ,kor-���������� �����

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	while (arr[0] == 0)
		arr[0] = rand() % 10;
	for (i = 1; i < K; i++)
	{
		c = rand() % 10;
		for (j = 0; j < i; j++)
			if (arr[j] == c)
			{
				i--;
				break;
			}
			else
				arr[i] = c;
	}
	printf("������� ����� ������������� �����\n");
	scanf_s("%d", &n);

	while (bik != n)
	{
		j = n;
		kor = 0;
		bik = 0;
		printf("����������� �������� ����� ����� n-������� ����� ��� ������� 1 ����� �������\n");
		scanf_s("%d", &ch);
		if (ch == 1)
			break;
		while (ch != 0)
		{
			p = ch % 10;
			j = j - 1;
			for (i = 0; i < n; i++)
				if (p == arr[i])
				{
					if (j == i)
						bik++;
					else
						kor++;
				}
			ch = ch / 10;
		}
		printf("���������� �����:%d.���������� �����: %d\n", kor, bik);
	}
	c = 0;
	for (i = 0; i < n; i++)
		c = c * 10 + arr[i];
	if (bik == n)
		printf("�����������,�� �������� ����� %d\n", c);
	else
		printf("���� �������� ����� %d\n", c);
	printf("������� 1 ����� ������ ����� ����, ������� 0 ����� ����� �� ����\n");
	scanf_s("%d", &c);
	if (c == 0)
		printf("�� ��������\n");
	if (c == 1)
		goto l;

	system("pause");

}