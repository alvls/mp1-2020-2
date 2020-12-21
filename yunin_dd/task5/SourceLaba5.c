/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� �����������/�������� �������.

������� ������:
���� �� ����������, � ������� ���������� ������������� ����������.
����� ����������.
�������� ������:
��������������� ������ ���� ������ � ��������� �������.
����� ����������.
��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.

��������� ������ ������������� ������ � ������������� ����������� ����������, ������� ��������:
����������� ����� ���� �� ��������� ��������;
����������� ������ ������ ����������;
����������� ��������� ���������������� ������ ������ � ��������� �������.
C����� ������� ����������:
1.���������
2.�������
3.���������
4.��������
5.�����
6.�����
7.���������
*/
			//����������� ��� ������ ���������
#define _CRT_SECURE_NO_WARNINGS

			//����������� ���������.
#include<stdio.h>
#include<memory.h>
#include<locale.h>
#include<omp.h>
#include<string.h>
#include<io.h>
#include<stdlib.h>

			//���������.
#define SIZE_OF_PATH_FOR_DIRECT 256
#define SIZE_OF_HELP_ARR 10000

			//���������.
typedef struct data
{
	char name[SIZE_OF_PATH_FOR_DIRECT];
	unsigned long size;
}helpfile;
			//���������� ����������.
helpfile now_c_file[SIZE_OF_HELP_ARR];//� ���� ������� ��������� ��� � ������ ��� ��������� �����.
char forsortpath[SIZE_OF_PATH_FOR_DIRECT]; //������ �������� ���� ��� ������ ����� �� ���� �� ����� ����������/
			//���������� �������� �������.
void Menu();
void Instraction();
void GetData();
void ChangePath(char* path);
void ChoiceMetodSort(count_files);
void BubbleSortUp(int count_files);
void BubbleSortDown(int count_files);
void SelectSortUp(int count_files);
void SelectSortDown(int count_files);
void InsertSortUp(int count_files);
void InsertSortDown(int count_files);
void MergeSortUp(int left, int right, helpfile* now_c_file);
void MergeUp(int left, int right, helpfile* now_c_file);
void MergeSortDown(int left, int right, helpfile* now_c_file);
void MergeDown(int left, int right, helpfile* now_c_file);
void HoaraSort(helpfile* now_c_file, int count_files);
void SwapFileForSort(helpfile* now_c_file, int count_files);
int Increment(long inc[], int count_files);
void ShellSortUp(int count_files, helpfile* now_c_file);
void ShellSortDown(int count_files, helpfile* now_c_file);
void CountingSort(int count_files, helpfile* now_c_file);

			//������� �������.
void main()
{
	setlocale(LC_ALL, "Rus");
	printf("������������, ��������� ������������, ���� ��� ������ � ����� ���������!\n");
	Menu();
}

			//�������, ������ ���������� ���� ���������.
void Menu()
{
	int choice = -1;
	char clean;
	printf("� ��������� �������� ��������� �������:\n1.���������� ���������� �� ������������� �������.\n2.���������� � ������.\n0.����� �� ���������.\n");
	while ((choice < 0)||(choice > 2))
	{
		scanf_s("%d", &choice);
		if ((choice < 0) || (choice > 2))
		{
			printf("������, �� ��������� ������ ������������ �����, ������� \"1\",\"2\",\"0\"!\n");
		}
	}
	clean = gets(stdin);
	switch (choice)
	{
	case 1:
		Instraction();
	case 2:
		GetData();
	default:
		printf("��������� ��������� ���� ������!\n");
		system("pause");
		break;
	}
}

			//���������� �� ������������� ���������.
void Instraction()
{
	system("cls");
	printf("\t\t\t���������� �� �������������!\n");
	printf("������� �� ��������� � ����, ��� ����� ������� ���� �� �������:\n(1)���������� - ������, ��� �� ������ �������� � ��� ��� �������� ���������\n");
	printf("(2)���������� � ������ - �������� ������ ���������, ��� ����� ��������������� ������ � �������\n(0)����� �� ��������� - ���������� ������ � ���\n");
	printf("��� ������ (2) ��� ����� ������������� ����������� ������ ���� �� �����, ��� �� ������ ������������� �����,\n������ ��� ����� ������������ ����� ��� �� �������������:\n(1) - �� �����������\n(2) - �� ��������.\n");
	printf("����� ����� ����� ������������ ����� �� 7 ������ ����� ����������, ������� �� �������� ������������� ������ ������ ������.\n����� ������ ���� ����������, � ��� �� ������ �������� ������ ������������ ���� ������ � �� ������� �� ��������/�� �����������,\n� ��� �� ����� ����������  � �����, ������� ���� ��������� �� ����������.\n");
	printf("� ������� ����� ����� ��������� ��� ��������� ������������� ���� �� ������ ������ ������, ��������� ������ ����� ����������, ��������, ��� �� ��������� ������ � ����������.\n");
	printf("�� ���� ��, ������ ��������� ����������� ����������!\n");
	system("pause");
	system("cls");
	Menu();
}
			//��������� ���� �� ����� � �������.
void GetData()
{
	struct _finddata_t now_file;
	intptr_t hFile;
	char path[SIZE_OF_PATH_FOR_DIRECT]; //����, ������� ��� ����� ������������.
	int count_files = 0, i; //������� ���������� ������ � �����.	
	printf("��������� ������������, ������� ���� � ����� � �������:\n");
	fgets(path, SIZE_OF_PATH_FOR_DIRECT, stdin);
	ChangePath(path);
	if ((hFile = _findfirst(path, &now_file)) == -1L)//������ ������� ����������, ����� ���� � ����� ������ �������,  ������ ��� � ����� ����� ���� ��� ����� . � ..
	{
		printf("�������� ���� ������� �����������!����������, ��������� ����!\n");
		system("pause");
		GetData(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
	}
	else //�������� �����, ���������� �� � ������ � ��������� ������ ������ �� ��������
	{
		do
		{
			if (count_files > 1) //�.�. 0 � 1 ���� . � ..
			{
				now_c_file[count_files - 2/*�� ��������� ������ 2 �����*/].size = now_file.size;//�������� � ������ ������ �������� �����, ��� ��� ������������ �������������.
				strcpy(now_c_file[count_files - 2].name, now_file.name);//�������� �������� �������� ����� � ������ ��� ���������� ����������.
			}
			count_files++;
		} while ((_findnext(hFile, &now_file) == 0) && (count_files < SIZE_OF_HELP_ARR/*������������ ����������� ������*/)); //�� ���� �������, ���� ����� � ����� �� ��������
		_findclose(hFile);
		strcpy(forsortpath, path);//�������� ���� ��� ����� � ������� ��� ����������� �������������.
		count_files -= 2; //��� ��� � ����� ����� ���������� ������� ��� ����� . � ..
		if (count_files == 0)
		{
			printf("�� ����� ���� �� ������� �� ������ �����!���������� ��������� ����!\n"); //�� ������ ������������� �����, �� ������������ �� ����������, ��� � ����� ���������� ������� �����
			GetData(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
		}
		else
		{
			ChoiceMetodSort(count_files);
		}
	}
}
			//��������� ���� ��� ����� � �������.
void ChangePath(char* path)
{
	int size = strlen(path);//������� ����� ������ path.
	if (size < 3)
	{
		printf("��������� �������������, ������� �������� ����, ��������� ����!\n");
		GetData(); //����� ���� ������ ���������� ������� � ������ ������ �������� c:'\0'.
	}
	if (path[size - 3] != '\\') //������� � ������ '/' ��� ���������
	{
		size++;
		path[size - 2] = '\\';
	}
	if (path[size - 2] != '*') //������� � ������ *, ����� � ���� ����� ��������� ��� �����
	{
		size++;
		path[size - 2] = '*';
	}
	path[size - 1] = '\0'; //�������� ������
	for (int i = 0; i < size; i++)
	{
		if (path[i] == '\\') //������ ������� '/' ('//') ��� ���������
		{
			i++; //����� ���������� ����������� '/'
			if (path[i] == path[i - 1]) //���� ��� ���������� ������� '/', �� ������ ����������� �� �����, ��������� �� ��������� ������
				continue;
			size++;
			for (int j = size - 1; j > i - 1; j--) //����� ��������� '/' ������� ��� ������� �� 1 ������, ��� ���� ����������� �������������� ������� �� ��������� '/'
			{
				path[j] = path[j - 1];
				//printf("%s\n", path); //��� �������� �������������
			}
		}
	}
}
			//����� ������ ���������� � ��������� ������.
void ChoiceMetodSort(count_files)
{
	int choicesort = 0, choicemetod = 0, choiceaction = 0, countuser = 0;
	long double t0 = 0, t1 = 0;
	printf("������� ������� ����� �������� �� ������ ������������� �����:\n1.�� �����������.\n2.�� ��������.\n");
	while ((choicemetod < 1) || (choicemetod > 2))
	{
		scanf_s("%d", &choicemetod);
		if ((choicemetod < 1) || (choicemetod > 2))
		{
			printf("��������� ������������, �� ����� �������� ����������, ������� ����� \"1\" ��� \"2\"\n");
		}
	}
	printf("���� ������� ����� ����������.� ��������� �������������:\n1.���������.\n2.�������.\n3.���������.\n4.��������.\n5.�����.\n6.�����.\n7.���������.\n");
	while ((choicesort < 1) || (choicesort > 7))
	{
		scanf_s("%d", &choicesort);
		if ((choicesort < 1) || (choicesort > 7))
		{
			printf("��������� ������������, �� ����� �������� ����������, ������� ����� �� 1 �� 7\n");
		}
	}
	switch (choicemetod)
	{
	case 1:
		switch (choicesort)
		{
		case 1:
			t0 = omp_get_wtime();
			BubbleSortUp(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 2:
			t0 = omp_get_wtime();
			SelectSortUp(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 3:
			t0 = omp_get_wtime();
			InsertSortUp(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 4:
			t0 = omp_get_wtime();
			MergeSortUp(0, count_files - 1, now_c_file);
			t1 = omp_get_wtime() - t0;
			break;
		case 5:
			t0 = omp_get_wtime();
			HoaraSort(now_c_file, count_files);
			SwapFileForSort(now_c_file, count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 6:
			t0 = omp_get_wtime();
			ShellSortUp(count_files, now_c_file);
			t1 = omp_get_wtime() - t0;
			break;
		case 7:
			t0 = omp_get_wtime();
			CountingSort(count_files, now_c_file);
			t1 = omp_get_wtime() - t0;
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (choicesort)
		{
		case 1:
			t0 = omp_get_wtime();
			BubbleSortDown(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 2:
			t0 = omp_get_wtime();
			SelectSortDown(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 3:
			t0 = omp_get_wtime();
			InsertSortDown(count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 4:
			t0 = omp_get_wtime();
			MergeSortDown(0, count_files - 1, now_c_file);
			t1 = omp_get_wtime() - t0;
			break;
		case 5:
			t0 = omp_get_wtime();
			HoaraSort(now_c_file, count_files);
			t1 = omp_get_wtime() - t0;
			break;
		case 6:
			t0 = omp_get_wtime();
			ShellSortDown(count_files, now_c_file);
			t1 = omp_get_wtime() - t0;
			break;
		case 7:
			t0 = omp_get_wtime();
			CountingSort(count_files, now_c_file);
			SwapFileForSort(now_c_file, count_files);
			t1 = omp_get_wtime() - t0;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	system("cls");
	printf("\n%43c������ ������\n\n����%75c������\n----%75c------\n", ' ', ' ', ' ');
	for (int i = 0; i < count_files; i++) //. � .. �������� 0 � 1 �������, ������� �������� �� ������� �������
	{
		printf("%-70s %16lu ����\n", now_c_file[i].name, now_c_file[i].size);
	}
	printf("\n����� ������: %d\n", count_files);
	printf("����� ����������: %f (���)\n\n\n", t1);
	system("pause");
	system("cls");
	printf("��������� ������������, ������ �� �� ������������ ������ ����� ���������� ��� ����� ������ ������?\n");
	printf("������� \"1\" ��� ����, ����� ������������� ��� ������ � ������� ������� ������ ����������.\n������� \"2\" ��� ����, ����� ��������� ������ ���������.\n");
	while ((choiceaction < 1) || (choiceaction > 2))
	{
		scanf_s("%d", &choiceaction);
		if ((choiceaction < 1) || (choiceaction > 2))
		{
			printf("�� ����� �������� �����, ��������� ����!\n");
		}
	}
	if (choiceaction == 1)
	{
		system("cls");
		ChoiceMetodSort(count_files);
	}
	else
	{
		printf("��������� ��������� ���� ������!\n");
		system("pause");
		return;
	}
}
			//���������� ��������� �� �����������.
void BubbleSortUp(int count_files)
{
	helpfile dop_file_for_swap;
	//int exit = 0;

	for (int i = 0; i < count_files; i++)
	{
		for (int j = count_files - 1; j > i; j--)
		{
			//exit = 0;
			if (now_c_file[j - 1].size > now_c_file[j].size)
			{
				dop_file_for_swap = now_c_file[j - 1];
				now_c_file[j - 1] = now_c_file[j];
				now_c_file[j] = dop_file_for_swap;
				//exit = 1;
			}
		}
		//if (exit == 0)
		//{
			//break;
		//}
	}
}
			//���������� ��������� �� ��������.
void BubbleSortDown(int count_files)
{
	helpfile dop_file_for_swap;
	//int exit = 0;

	for (int i = 0; i < count_files; i++)
	{
		for (int j = count_files - 1; j > i; j--)
		{
			//exit = 0;
			if (now_c_file[j - 1].size < now_c_file[j].size)
			{
				dop_file_for_swap = now_c_file[j - 1];
				now_c_file[j - 1] = now_c_file[j];
				now_c_file[j] = dop_file_for_swap;
				//exit = 1;
			}
		}
		//if (exit == 0)
		//{
			//break;
		//}
	}
}
		//���������� ������� �� �����������.
void SelectSortUp(int count_files)
{
	helpfile dop_file_min;
	int k;
	for (int i = 0; i < count_files - 1/*������, �������� �� ���*/; i++)
	{
		dop_file_min = now_c_file[i];
		k = i;
		for (int j = i + 1; j < count_files; j++)
		{
			if (now_c_file[j].size < dop_file_min.size)
			{
				dop_file_min = now_c_file[j];
				k = j;
			}
		}
		now_c_file[k] = now_c_file[i];
		now_c_file[i] = dop_file_min;
	}
}
		//���������� ������� �� ��������.
void SelectSortDown(int count_files)
{
	helpfile dop_file_max;
	int k;
	for (int i = 0; i < count_files - 1/*������, �������� �� ���*/; i++)
	{
		dop_file_max = now_c_file[i];
		k = i;
		for (int j = i + 1; j < count_files; j++)
		{
			if (now_c_file[j].size > dop_file_max.size)
			{
				dop_file_max = now_c_file[j];
				k = j;
			}
		}
		now_c_file[k] = now_c_file[i];
		now_c_file[i] = dop_file_max;
	}
}
		//���������� ��������� �� �����������.
void InsertSortUp(int count_files)
{
	helpfile dop_file_elem;
	int i, j;
	for (i = 0; i < count_files; i++)
	{
		dop_file_elem = now_c_file[i];
		for (j = i - 1; (j >= 0) && (now_c_file[j].size > dop_file_elem.size); j--)
		{
			now_c_file[j + 1] = now_c_file[j];
		}
		now_c_file[j + 1] = dop_file_elem;
	}
}
			//���������� ��������� �� ��������.
void InsertSortDown(int count_files)
{
	helpfile dop_file_elem;
	int i, j;
	for (i = 0; i < count_files; i++)
	{
		dop_file_elem = now_c_file[i];
		for (j = i - 1; (j >= 0) && (now_c_file[j].size < dop_file_elem.size); j--)
		{
			now_c_file[j + 1] = now_c_file[j];
		}
		now_c_file[j + 1] = dop_file_elem;
	}
}
			//���������� �������� �� �����������.
void MergeSortUp(int left, int right, helpfile* now_c_file)
{
	int mid = (left + right) / 2;
	if (left == right)
	{
		return;
	}
	MergeSortUp(left, mid, now_c_file);
	MergeSortUp(mid + 1, right, now_c_file);
	MergeUp(left, right, now_c_file);
}
void MergeUp(int left, int right, helpfile* now_c_file)
{
	int mid = (left + right) / 2;
	int i = left;
	int k = 0;
	int j = mid + 1;
	helpfile* dop_file_for_swap;
	right += 1;
	dop_file_for_swap = malloc((right) * sizeof(helpfile));
	for (k = left; k < right; k++)
	{
		if ((i <= mid) && (j < right))
		{
			if (now_c_file[i].size <= now_c_file[j].size)
			{
				dop_file_for_swap[k] = now_c_file[i];
				i++;
			}
			else
			{
				dop_file_for_swap[k] = now_c_file[j];
				j++;
			}
		}
		else
		{
			if (i == mid + 1)
			{
				for (; j < right; j++, k++)
				{
					dop_file_for_swap[k] = now_c_file[j];
				}
			}
			else
			{
				for (; i < mid + 1; i++, k++)
				{
					dop_file_for_swap[k] = now_c_file[i];
				}
			}
		}
	}
	for (k = left; k < right; k++)
	{
		now_c_file[k] = dop_file_for_swap[k];
	}
	free(dop_file_for_swap);
}
			//���������� �������� �� ��������.
void MergeSortDown(int left, int right, helpfile* now_c_file)
{
	int mid = (left + right) / 2;
	if (left == right)
	{
		return;
	}
	MergeSortDown(left, mid, now_c_file);
	MergeSortDown(mid + 1, right, now_c_file);
	MergeDown(left, right, now_c_file);
}
void MergeDown(int left, int right, helpfile* now_c_file)
{
	int mid = (left + right) / 2;
	int i = left;
	int k = 0;
	int j = mid + 1;
	helpfile* dop_file_for_swap;
	right += 1;
	dop_file_for_swap = (malloc((right) * sizeof(helpfile)));
	for (k = left; k < right; k++)
	{
		if ((i <= mid) && (j < right))
		{
			if (now_c_file[i].size >= now_c_file[j].size)
			{
				dop_file_for_swap[k] = now_c_file[i];
				i++;
			}
			else
			{
				dop_file_for_swap[k] = now_c_file[j];
				j++;
			}
		}
		else
		{
			if (i == mid + 1)
			{
				for (; j < right; j++, k++)
				{
					dop_file_for_swap[k] = now_c_file[j];
				}
			}
			else
			{
				for (; i < mid + 1; i++, k++)
				{
					dop_file_for_swap[k] = now_c_file[i];
				}
			}
		}
	}
	for (k = left; k < right; k++)
	{
		now_c_file[k] = dop_file_for_swap[k];
	}
	free(dop_file_for_swap);
}
			//������� ����������.
void HoaraSort(helpfile* now_c_file, int count_files)
{
	int i = 0;
	int j = count_files;
	int mid = count_files / 2;
	unsigned long sizemidelem = now_c_file[mid].size;
	helpfile dop_file_for_swap;
	do
	{
		while (now_c_file[i].size > sizemidelem)//> ������ ���� 
		{
			i++;
		}
		while (now_c_file[j].size < sizemidelem)//< ������ ���� 
		{
			j--;
		}
		if (i <= j)
		{
			dop_file_for_swap = now_c_file[i];
			now_c_file[i] = now_c_file[j];
			now_c_file[j] = dop_file_for_swap;
			i++;
			j--;
		}
	} while (i <= j);
	if (0 < j)
		HoaraSort(now_c_file, j);
	if (i < count_files)
		HoaraSort(now_c_file + i, count_files - i);
}

			//�������� ����������.
void SwapFileForSort(helpfile* now_c_file, int count_files)
{
	int i;
	helpfile dop_file_for_swap;
	for (i = 0; i < (count_files / 2); i++)
	{
		dop_file_for_swap = now_c_file[i];
		now_c_file[i] = now_c_file[count_files - 1 - i];
		now_c_file[count_files - 1 - i] = dop_file_for_swap;
	}
}

			//��������������� ������� ��� ���������� �����.
int Increment(long inc[], int count_files)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < count_files);
	return s > 0 ? --s : 0;
}
			//���������� ����� �� �����������.
void ShellSortDown(int count_files, helpfile* now_c_file)
{
	long inc, i, j, seq[40];
	int s;
	helpfile dop_file_for_swap;
	s = Increment(seq, count_files);
	while (s >= 0)
	{
		// ���������� ��������� � ������������ inc[] 
		inc = seq[s--];

		for (i = inc; i < count_files; i++)
		{
			dop_file_for_swap = now_c_file[i];
			for (j = i - inc; (j >= 0) && (now_c_file[j].size < dop_file_for_swap.size); j -= inc)
				now_c_file[j + inc] = now_c_file[j];
			now_c_file[j + inc] = dop_file_for_swap;
		}
	}
}
			//���������� ����� �� ��������.
void ShellSortUp(int count_files, helpfile* now_c_file)
{
	long inc, i, j, seq[40];
	int s;
	helpfile dop_file_for_swap;
	s = Increment(seq, count_files);
	while (s >= 0)
	{
		// ���������� ��������� � ������������ inc[] 
		inc = seq[s--];

		for (i = inc; i < count_files; i++)
		{
			dop_file_for_swap = now_c_file[i];
			for (j = i - inc; (j >= 0) && (now_c_file[j].size > dop_file_for_swap.size); j -= inc)
				now_c_file[j + inc] = now_c_file[j];
			now_c_file[j + inc] = dop_file_for_swap;
		}
	}
}
			//���������� ���������.
void CountingSort(int count_files, helpfile* now_c_file)
{
	unsigned long min_size, max_size, size_of_arr;
	int i, k, j;
	int* count_arr;
	min_size = now_c_file[0].size;
	max_size = min_size;
	for (i = 0; i < count_files; i++)
	{
		if (now_c_file[i].size > max_size)
		{
			max_size = now_c_file[i].size;
		}
		if (now_c_file[i].size < min_size)
		{
			min_size = now_c_file[i].size;
		}
	}
	size_of_arr = max_size - min_size + 1;
	count_arr = (int*)malloc(sizeof(int) * size_of_arr);
	for (i = 0; i < size_of_arr; i++)
	{
		count_arr[i] = 0;
	}
	for (i = 0; i < count_files; i++)
	{
		count_arr[now_c_file[i].size - min_size]++;
	}
	k = 0;
	for (i = 0; i < size_of_arr; i++)
	{
		if (count_arr[i] > 0)
		{
			while (count_arr[i] > 0)
			{
				now_c_file[k].size = i + min_size;
				k++;
				count_arr[i]--;
			}
		}
	}
	free(count_arr);
}
