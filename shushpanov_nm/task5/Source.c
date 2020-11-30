#define _CRT_SECURE_NO_WARNINGS
#define PATH_SIZE 256
#define ARRAY_SIZE 9999
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <io.h>
#include <string.h>
#include <omp.h>
#include <locale.h>

typedef struct finddata
{
	_fsize_t size;
	char name[FILENAME_MAX];
}
dataArray;

typedef struct sortTime
{
	double sortingTime;
};

char* menu[] = { "1. Выбрать католог", "2. Выход из программы" };
char* menuSort[] = { "1. Пузырьком", "2. Выбором", "3. Вставками", "4. Слиянием", "5. Хоара", "6. Шелла", "7. Подсчетом" };
char* increaseOrDecrease[] = { "1. Возрастания", "2. Убывания" };
int ShowMenu();
int ChoiceMenu();
int ChoiceIncreaseOrDecrease();
char ChangePath(char* path);
double CalculateTime(double endTime, double startTime);
int ShowSort(int count);
int SelectCatalog();
void BubbleSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease);
void SelectSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease);
void InsertSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease);
void MergeSort(int left, int right, dataArray* c_file, int sortingIncreaseOrDecrease);
void Merge(int left, int right, dataArray* c_file, int sortingIncreaseOrDecrease);
void QuickSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease);
int Increment(long inc[], int count);
int ShellSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease);
int CountingSort(int count, dataArray* c_file, int sortingIncreaseOrDecrease);
int size_menu = sizeof(menu) / sizeof(char*);
int size_menuSort = sizeof(menuSort) / sizeof(char*);
int size_increaseOrDecrease = sizeof(increaseOrDecrease) / sizeof(char*);
struct  finddata c_file[ARRAY_SIZE];
char pathSorting[PATH_SIZE];

int ShowMenu()
{
	int i = 0, choice;
	printf("Меню файлового менеджера: \n");
	for (i = 0; i < size_menu; i++)
	{
		printf("%s", menu[i]);
		printf("\n");
	}
	choice = ChoiceMenu();
	switch (choice)
	{
	case 1:
	{
		system("cls");
		SelectCatalog();
		return 1;
	}
	case 2:
	{
		system("cls");
		return 2;
	}
	default:
	{
		break;
	}
	}
}

int ChoiceMenu()
{
	int choice = 0;
	printf("Введите номер: ");
	scanf("%d", &choice);
	return choice;
}

int ChoiceIncreaseOrDecrease()
{
	int sortingIncreaseOrDecrease;
	printf("Введите номер: ");
	scanf("%d", &sortingIncreaseOrDecrease);
	return sortingIncreaseOrDecrease;
}

char ChangePath(char* path)
{
	int sizePath = 0, i, j;
	sizePath = strlen(path);
	if (path[sizePath - 3] != '\\')
	{
		sizePath++;
		path[sizePath - 2] = '\\';
	}
	if (path[sizePath - 2] != '*')
	{
		sizePath++;
		path[sizePath - 2] = '*';
	}
	path[sizePath - 1] = '\0';
	for (i = 0; i < sizePath; i++)
	{
		if (path[i] == '\\')
		{
			i++;
			if (path[i] == path[i - 1])
				continue;
			sizePath++;
			for (j = sizePath - 1; j > i - 1; j--)
			{
				path[j] = path[j - 1];
			}
		}
	}
}

double CalculateTime(double endTime, double startTime)
{
	struct sortTime time;
	double times = endTime - startTime;
	return;
}

int ShowSort(int count)
{
	int i, choiceSort, repeatSort, sortingIncreaseOrDecrease, sortingID;
	double time, endTime, startTime;
	char* typeSortingID[] = { 0 };
	printf("\nКак будем сортировать? Методом... \n");
	for (i = 0; i < size_increaseOrDecrease; i++)
	{
		printf("%s", increaseOrDecrease[i]);
		printf("\n");
	}
	sortingIncreaseOrDecrease = ChoiceIncreaseOrDecrease();
	sortingID = sortingIncreaseOrDecrease - 1;
	printf("\nМетоды сортировки: \n");
	for (i = 0; i < size_menuSort; i++)
	{
		printf("%s", menuSort[i]);
		printf("\n");
	}
	printf("\n");
	choiceSort = ChoiceMenu();
	switch (choiceSort)
	{
		case 1:
		{
			system("cls");
			startTime = omp_get_wtime();
			BubbleSort(c_file, count, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Пузырьком (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 2:
		{
			system("cls");
			startTime = omp_get_wtime();
			SelectSort(c_file, count, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Выбором (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 3:
		{
			system("cls");
			startTime = omp_get_wtime();
			InsertSort(c_file, count, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Вставками (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 4:
		{
			system("cls");
			startTime = omp_get_wtime();
			MergeSort(0, count, c_file, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Слиянием (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 5:
		{
			system("cls");
			startTime = omp_get_wtime();
			QuickSort(c_file, count - 1, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Хоара (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 6:
		{
			system("cls");
			startTime = omp_get_wtime();
			ShellSort(c_file, count, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Шелла (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		case 7:
		{
			system("cls");
			startTime = omp_get_wtime();
			CountingSort(count, c_file, sortingIncreaseOrDecrease);
			endTime = omp_get_wtime();
			printf("Сортировка: Подсчетом (Методом: %s)\n", increaseOrDecrease[sortingID]);
			break;
		}
		default:
		{
			printf("\nТакого пункта в меню не существует!\n\n");
			break;
		}
	}
	if (choiceSort >= 1 && choiceSort <= 7)
	{
		time = CalculateTime(endTime, startTime);
		printf("Файлы каталога:\n\n");
		printf("Файл            %49c Размер (байт)\n", ' ');
		printf("-----------------           %36c --------------\n", ' ');
		for (int i = 1; i < count; i++)
		{
			printf("%-61s %15ld \n", c_file[i].name, c_file[i].size);
		}
		printf("\nКоличество файлов в каталоге: %d\n", count - 2);
		printf("Время сортировки: %f секунд.\n\t\n", time);
		printf("Хотите отсортировать снова?\n1. Да \n2. Нет\nВведите номер: ");
		scanf("%d", &repeatSort);
		switch (repeatSort)
		{
			case 1:
			{
				system("cls");
				ShowSort(count);
				return;
			}
			case 2:
			{
				system("cls");
				return;
			}
			default:
			{
				printf("\nТакого пункта меню не существует!\n\n");
				break;
			}
		}
	}
}

int SelectCatalog()
{
	struct _finddata_t dataFile;
	intptr_t hFile;
	int count = 0, i = 0;
	char path[PATH_SIZE];

	printf("Пример пути: C:\\Users\\user\\Desktop\\Task5\n");
	printf("Введите путь к каталогу: ");
	gets(stdin);
	fgets(path, PATH_SIZE, stdin);
	ChangePath(path);
	if ((hFile = _findfirst(path, &dataFile)) == -1L)
	{
		printf("Не найдены файлы в каталоге или путь введен неверно!\n");
		printf("\n");
		ShowMenu();
	}
	else
	{
		printf("Файлы каталога:\n\n");
		printf("Файл            %49c Размер (байт)\n", ' ');
		printf("-----------------           %36c --------------\n", ' ');
		do
		{
			if (count > 1)
			{
				c_file[count - 2].size = dataFile.size;
				strcpy(c_file[count - 2].name, dataFile.name);
				printf("%-61s %15ld \n", dataFile.name, dataFile.size);
			}
			count++;
		} while ((_findnext(hFile, &dataFile) == 0) && (count < ARRAY_SIZE));
	}
	count -= 2;
	printf("\nКоличество файлов в каталоге: %d\n", count);
	_findclose(hFile);
	strcpy(pathSorting, path);
	ShowSort(count, c_file);
}

void main()
{
	int done = 0;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Добро пожаловать в файловый менеджер!\n\n");
	while (done != 2)
	{
		done = ShowMenu();
	}
	printf("Счастливо! Спасибо что воспользовались нашей программой!\n\n");
	system("pause");
}

void BubbleSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease)
{
	int i, j, n;
	dataArray additionalElement;
	if (sortingIncreaseOrDecrease == 2)
	{
		for (i = 0; i < count; i++)
		{
			n = i;
			additionalElement = c_file[i];
			for (j = i + 1; j < count; j++)
			{
				if (c_file[j].size > additionalElement.size)
				{
					additionalElement = c_file[j];
					n = j;
				}
			}
			c_file[n] = c_file[i];
			c_file[i] = additionalElement;
		}
	}
	else if (sortingIncreaseOrDecrease == 1)
	{
		for (i = 0; i < count--; i++)
		{
			additionalElement = c_file[i];
			n = i;
			for (int j = i + 1; j < count; j++)
			{
				if (c_file[j].size < additionalElement.size)
				{
					additionalElement = c_file[j];
					n = j;
				}
			}
			c_file[n] = c_file[i];
			c_file[i] = additionalElement;
		}
	}
}

void SelectSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease)
{
	int i, j, k;
	dataArray additionalElement;
	if (sortingIncreaseOrDecrease == 2)
	{
		for (i = 0; i < count; i++)
		{
			k = i;
			additionalElement = c_file[i];
			for (j = i + 1; j < count; j++)
			{
				if (c_file[j].size > additionalElement.size)
				{
					additionalElement = c_file[j];
					k = j;
				}
			}
			c_file[k] = c_file[i];
			c_file[i] = additionalElement;
		}
	}
	else if (sortingIncreaseOrDecrease == 1)
	{
		for (i = 0; i < count - 1; i++)
		{
			additionalElement = c_file[i];
			k = i;
			for (j = i + 1; j < count; j++)
			{
				if (c_file[j].size < additionalElement.size)
				{
					additionalElement = c_file[j];
					k = j;
				}
			}
			c_file[k] = c_file[i];
			c_file[i] = additionalElement;
		}
	}
}

void InsertSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease)
{
	int i, j;
	dataArray additionalElement;
	for (i = 0; i < count; i++)
	{
		additionalElement = c_file[i];
		if (sortingIncreaseOrDecrease == 2)
		{
			for (j = i - 1; (j >= 0) && (c_file[j].size < additionalElement.size); j--)
			{
				c_file[j + 1] = c_file[j];
			}
		}
		else if (sortingIncreaseOrDecrease == 1)
		{
			for (j = i - 1; (j >= 0) && (c_file[j].size > additionalElement.size); j--)
			{
				c_file[j + 1] = c_file[j];
			}
		}
		c_file[j + 1] = additionalElement;
	}
}

void MergeSort(int left, int right, dataArray* c_file, int sortingIncreaseOrDecrease)
{
	int mid = (left + right) / 2;
	if (left == right)
	{
		return;
	}
	MergeSort(left, mid, c_file, sortingIncreaseOrDecrease);
	MergeSort(mid + 1, right, c_file, sortingIncreaseOrDecrease);
	Merge(left, right, c_file, sortingIncreaseOrDecrease);
}

void Merge(int left, int right, dataArray* c_file, int sortingIncreaseOrDecrease)
{
	int mid = (left + right) / 2, i = left, k = 0, j = mid + 1;
	dataArray* additionalElement;
	right += 1;
	additionalElement = malloc((right) * sizeof(dataArray));
	for (k = left; k < right; k++)
	{
		if ((i <= mid) && (j < right))
		{
			if (sortingIncreaseOrDecrease == 2)
			{
				if (c_file[i].size >= c_file[j].size)
				{
					additionalElement[k] = c_file[i];
					i++;
				}
				else
				{
					additionalElement[k] = c_file[j];
					j++;
				}
			}
			else if (sortingIncreaseOrDecrease == 1)
			{
				if (c_file[i].size <= c_file[j].size)
				{
					additionalElement[k] = c_file[i];
					i++;
				}
				else
				{
					additionalElement[k] = c_file[j];
					j++;
				}
			}
		}
		else
		{
			if (i == mid + 1)
			{
				for (; j < right; j++, k++)
				{
					additionalElement[k] = c_file[j];
				}
			}
			else
			{
				for (; i < mid + 1; i++, k++)
				{
					additionalElement[k] = c_file[i];
				}
			}
		}
	}
	for (k = left; k < right; k++)
	{
		c_file[k] = additionalElement[k];
	}
	free(additionalElement);
}

void QuickSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease)
{
	int i = 0, j = count, mid = count / 2;
	_fsize_t midSize = c_file[mid].size;
	dataArray additionalElement;
	do
	{
		if (sortingIncreaseOrDecrease == 2)
		{
			while (c_file[i].size > midSize)
			{
				i++;
			}
			while (c_file[j].size < midSize)
			{
				j--;
			}
		}
		else if (sortingIncreaseOrDecrease == 1)
		{
			while (c_file[i].size < midSize)
			{
				i++;
			}
			while (c_file[j].size > midSize)
			{
				j--;
			}
		}
		if (i <= j)
		{
			additionalElement = c_file[i];
			c_file[i] = c_file[j];
			c_file[j] = additionalElement;
			i++;
			j--;
		}
	}
	while (i <= j);
	if (j > 0)
		QuickSort(c_file, j, sortingIncreaseOrDecrease);
	if (count > i)
		QuickSort(c_file + i, count - i, sortingIncreaseOrDecrease);
}

int Increment(long inc[], int count)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < count);
	return s > 0 ? --s : 0;
}

int ShellSort(dataArray* c_file, int count, int sortingIncreaseOrDecrease)
{
	dataArray additionalElement;
	long inc, i, j, seq[40];
	int s;
	s = Increment(seq, count);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < count; i++)
		{
			additionalElement = c_file[i];
			if (sortingIncreaseOrDecrease == 2)
			{
				for ((j = i - inc); ((j >= 0) && (c_file[j].size < additionalElement.size)); (j -= inc))
				{
					c_file[j + inc] = c_file[j];
				}
			}
			else if (sortingIncreaseOrDecrease == 1)
			{
				for ((j = i - inc); ((j >= 0) && (c_file[j].size > additionalElement.size)); (j -= inc))
				{
					c_file[j + inc] = c_file[j];
				}
			}
			c_file[j + inc] = additionalElement;
		}
	}
}

int CountingSort(int count, dataArray* c_file, int sortingIncreaseOrDecrease)
{
	int k = count - 1, i, j;
	dataArray additionalElement;
	_fsize_t* countSize;
	_fsize_t minsize, maxsize, size;
	minsize = maxsize = c_file[0].size;
	for (i = 0; i < count; i++)
	{
		if (c_file[i].size < minsize)
		{
			minsize = c_file[i].size;
		}
		if (c_file[i].size > maxsize)
		{
			maxsize = c_file[i].size;
		}
	}
	size = maxsize - minsize + 1;
	countSize = (_fsize_t*)malloc(size * sizeof(_fsize_t));
	for (_fsize_t i = 0; i < size; i++)
	{
		countSize[i] = 0;
	}
	for (i = 0; i < count; i++)
	{
		countSize[c_file[i].size - minsize]++;
	}
	for (_fsize_t i = 0; i < size; i++)
	{
		while (countSize[i] > 0)
		{
			for (j = k; j >= 0; j--)
			{
				if (c_file[j].size == minsize + i)
				{
					additionalElement = c_file[j];
					c_file[j] = c_file[k];
					c_file[k] = additionalElement;
					k--;
					countSize[i]--;
				}
			}
		}
	}
	if (sortingIncreaseOrDecrease == 1)
	{
		for (i = 0; i < (count / 2); i++)
		{
			additionalElement = c_file[i];
			c_file[i] = c_file[count - 1 - i];
			c_file[count - 1 - i] = additionalElement;
		}
	}
	free(countSize);
}