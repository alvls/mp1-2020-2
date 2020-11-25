#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
#include <omp.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void showmenu() //вывод меню
{
	char* menu[] = { "Список сортировок:","1 - Пузырьком ", "2 - Выбором","3 - Вставками", "4 - Слиянием", "5 - Хоара", "6 - Шелла", "7 - Подсчётом" };
	int menu_size = sizeof(menu) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", menu[i]);
}
int menuchoice() //выбор из меню 
{
	int choice;
	printf("Введите номер нужной вам сортировки: ");
	scanf_s("%d", &choice);
	while (choice < 1 || choice > 7) //проверка правильности введенных пользователем данных
	{
		printf("Вы неправильно ввели номер сортировки, введите, пожалуйста, ещё раз: \n");
		scanf_s("%d", &choice);
	}
	return choice;
}
int counter(char path[]) //счетчик количества файлов
{
	struct _finddata_t c_file;
	intptr_t hFile;
	int count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("Неправильный путь к директории\n");
	else
	{
		do {
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
	}
	return count; //кол-во файлов 
}
//СОРТИРОВКИ............................//
void Bubble(struct _finddata_t c_file[], int k)
{
	int i, j;
	struct _finddata_t x;
	for (i = 0; i < k; i++)
	{
		for (j = k; j > i; j--)
		{
			if (c_file[j - 1].size > c_file[j].size)
			{
				x = c_file[j - 1];
				c_file[j - 1] = c_file[j];
				c_file[j] = x;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	double t1, t2; //для вемени сортировки 
	double time_sort;
	int sort; // выбор способа сортировки 
	int sort_way; // выбор возрастание/убывание 
	struct _finddata_t* files; //информация о файле 
	SetConsoleCP(1251); //Чтобы в пути могли быть названия папок на русском языке
	SetConsoleOutputCP(1251); //Чтобы в пути могли быть названия папок на русском языке
	printf("Введите путь до директории: \n");
	gets_s(path, 200);
	printf("\nВы ввели путь: %s\n", path);
	//strcat(path, "\*");



	if ((count = counter(path)) != 0)
	{
		files = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));
		//hFile = _findfirst(path, &files[0]);
		hFile = _findfirst(path, &c_file);
		printf("Список файлов в указанной папке (без сортировки)\n\n");
		printf("Имя файла      %16c     Размер\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do
			printf("%-12.12s  %10ld\n", c_file.name, c_file.size);
		while (_findnext(hFile, &c_file) == 0);
		printf("Количество файлов: %d\n", count);
		while (1)
		{
			showmenu();
			sort = menuchoice();
			printf("Если вы хотите, чтобы выши файлы были отсортированы по возрастанию размера - нажмите 1, если по убыванию - 2");
			scanf_s("%d", &sort_way);
			while ((sort_way < 1) || sort_way > 2) //проверка правильности введенных пользователем данных
			{
				printf("Вы неправильно ввели номер варианта сортировки, введите, пожалуйста, ещё раз \n");
				scanf_s("%i", &sort_way);
			}
			switch (sort) //сортировки 
			{
			case 1:
				t1 = omp_get_wtime();
				Bubble(files, count);
				t2 = omp_get_wtime();
				break;
			case 2:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			case 3:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			case 4:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			case 5:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			case 6:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			case 7:
				t1 = omp_get_wtime();

				t2 = omp_get_wtime();
				break;
			}
			if (sort_way == 1)
			{
				for (int i = 0; i < count; i++)
					printf("%-12.12s  %10ld\n", files[i].name, files[i].size);
			}
			if (sort_way == 2)
			{
				for (int i = count - 1; i >= 0; i--)
					printf("%-12.12s  %10ld\n", files[i].name, files[i].size);
			}
			time_sort = (double)(t2 - t1) / CLOCKS_PER_SEC;
			printf("Время на сортировку составило:\n %a \n", time_sort);
		}
		free(files); //освобождение динамической памяти 
	}
	system("pause");
}



/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <omp.h>

void showmenu() //вывод меню
{
	char* menu[] = { "Список сортировок:","1 - Пузырьком ", "2 - Выбором","3 - Вставками", "4 - Слиянием", "5 - Хоара", "6 - Шелла", "7 - Подсчётом" };
	int menu_size = sizeof(menu) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", menu[i]);
}
int menuchoice() //выбор из меню 
{
	int choice;
	printf("Введите номер нужной вам сортировки: ");
	scanf_s("%d", &choice);
	while (choice < 1 || choice > 7) //проверка правильности введенных пользователем данных
	{
		printf("Вы неправильно ввели номер сортировки, введите, пожалуйста, ещё раз: \n");
		scanf_s("%d", &choice);
	}
	return choice;
}

struct sort
{
	int size;
	char name[200];
};
struct sort files[3000];

int increment(long inc[], long size)
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
	} while (3 * inc[s] < size);
	return s > 0 ? --s : 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Bubble(struct sort files[], int k)
{
	int i, j;
	struct sort x;
	for (i = 0; i < k; i++)
	{
		for (j = k; j > i; j--)
		{
			if (files[j - 1].size > files[j].size)
			{
				x = files[j - 1];
				files[j - 1] = files[j];
				files[j] = x;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void selectSort(struct sort files[], int k) {
	int i, j, a;
	struct sort x;
	for (i = 0; i < k; i++) {
		a = i; x = files[i];
		for (j = i + 1; j < k + 1; j++)
			if (files[j].size< x.size) {
				a = j; x = files[j];
			}
		files[a] = files[i]; files[i] = x;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertSort(struct sort files[], int k)
{
	struct sort x;
	int i, j;
	for (i = 0; i < k + 1; i++)
	{
		x = files[i];
		for (j = i - 1; j >= 0 && files[j].size > x.size; j--)
			files[j + 1] = files[j];
		files[j + 1] = x;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void quickSort(struct sort files[], int k)
{
	long i = 0, j = k;
	struct sort x;
	long p;
	p = files[k >> 1].size;
	do
	{
		while (files[i].size < p) i++;
		while (files[j].size > p) j--;
		if (i <= j)
		{
			x = files[i];
			files[i] = files[j];
			files[j] = x;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(files, j);
	if (k > i) quickSort(files + i, k - i);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void shellSort(struct sort files[], int k)
{
	int inc, i, j, seq[40], s;
	struct sort x;
	s = increment(seq, k);
	while (s >= 0)
	{
		inc = seq[s--];
		for (i = inc; i < k + 1; i++)
		{
			x = files[i];
			for (j = i - inc; (j >= 0) && (files[j].size > x.size); j -= inc)
				files[j + inc].size = files[j].size;
			files[j + inc] = x;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge(struct sort files[], int lb, int split, int ub)
{
	struct sort* x;
	int pos1 = lb;
	int pos2 = split + 1;
	int pos3 = 0;
	x = (struct sort*)malloc((ub - lb + 1) * sizeof(struct sort));
	while (pos1 <= split && pos2 <= ub) {
		if (files[pos1].size < files[pos2].size)
			x[pos3++] = files[pos1++];
		else
			x[pos3++] = files[pos2++];
	}
	while (pos2 <= ub)
		x[pos3++] = files[pos2++];
	while (pos1 <= split)
		x[pos3++] = files[pos1++];
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
		files[lb + pos3] = x[pos3];
	free(x);
}void mergeSort(struct sort files[], int lb, int ub)
{
	int split;
	time_t start, end;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		mergeSort(files, lb, split);
		mergeSort(files, split + 1, ub);
		merge(files, lb, split, ub);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CountingSort(struct sort* files, int k)
{
	unsigned long max, min;
	int i, j, m = 0, * p;
	struct sort x;
	max = min = files[0].size;
	for (i = 0; i < k + 1; i++)
	{
		if (files[i].size > max)
			max = files[i].size;
		if (files[i].size < min)
			min = files[i].size;
	}
	max++;
	p = (int*)malloc(max * sizeof(int));
	memset(p, 0, max * sizeof(int));
	for (i = 0; i < k + 1; i++)
		p[files[i].size]++;
	for (i = min; i < max; i++)
	{
		if (p[i] != 0)
		{
			for (j = m; j < k + 1; j++)
				if (files[j].size == i)
				{
					x = files[j];
					files[j] = files[m];
					files[m] = x;
					m++;
				}
		}
	}
	free(p);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	setlocale(LC_ALL, "ru");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0, sort, i, flag, k;
	double t1, t2; //для вемени сортировки 
	double time_sort;
	int sort_way; // выбор возрастание/убывание 

	printf("Введите путь вида: с:\\..\\ \n");
	gets(path);
	strcat(path, "*");
	i = 0; flag = 1;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
	{
		printf("Неправильный путь к директории \n");
		flag = 0;
	}
	else
	{
		printf("Список файлов в указанной папке (без сортировки)\n\n");
		printf("Имя файла      %16c     Размер\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do {
				if (count <= 3000)
				{
					strcpy(files[i].name, c_file.name);
					files[i].size = c_file.size;
					printf("%-12.12s  %10ld\n", c_file.name, c_file.size);
					count++;
					i++;
				}
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\nКоличество файлов: %d\n", count);
		k = i - 1;
	}
	if (flag == 0)
		return(0);
	int choice;
	do
	{
		showmenu();
		sort = menuchoice();
		printf("Если вы хотите, чтобы выши файлы были отсортированы по возрастанию размера - нажмите 1, если по убыванию - 2\n");
		scanf_s("%d", &sort_way);
		while ((sort_way < 1) || sort_way > 2) //проверка правильности введенных пользователем данных
		{
			printf("Вы неправильно ввели номер варианта сортировки, введите, пожалуйста, ещё раз \n");
			scanf_s("%i", &sort_way);
		}
		switch (sort)
		{
		case 1:
			t1 = omp_get_wtime();
			Bubble(files, k);
			t2 = omp_get_wtime();
			break;
		case 2:
			t1 = omp_get_wtime();
			selectSort(files, k);
			t2 = omp_get_wtime();
			break;
		case 3:
			t1 = omp_get_wtime();
			insertSort(files, k);
			t2 = omp_get_wtime();
			break;
		case 4:
			t1 = omp_get_wtime();
			mergeSort(files, 0, k);
			t2 = omp_get_wtime();
			break;
		case 5:
			t1 = omp_get_wtime();
			quickSort(files, k);
			t2 = omp_get_wtime();
			break;
		case 6:
			t1 = omp_get_wtime();
			shellSort(files, k);
			t2 = omp_get_wtime();
			break;
		case 7:
			t1 = omp_get_wtime();
			CountingSort(files, k);
			t2 = omp_get_wtime();
			break;
		}
		if (sort_way == 1)
		{
			for (i = 0; i <= k; i++)
			{
				printf("%-12.12s     %i\n", files[i].name, files[i].size);
			}
		}
		if (sort_way == 2)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				printf("%-12.12s     %i\n", files[i].name, files[i].size);
			}
		}
		time_sort = (double)(t2 - t1) / CLOCKS_PER_SEC;
		printf("Время на сортировку составило:\n %a \n", time_sort);
	} while (1);
	system("pause");
}*/