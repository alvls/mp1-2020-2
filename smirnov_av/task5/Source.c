#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <omp.h>

char path[256]; 

struct info //структура для хранения информации по каждой сортировке
{
	char* name;
	double time;
};

void print_main_menu() 
{
	printf("1.Ввести путь до директории\n");
	printf("2.Виды сортировок\n");
	printf("3.Инструкция по использованию\n");
	printf("0.Выход\n");
}

void create_copy(struct _finddata_t* copy_files, struct _finddata_t* files,int count) //копирует в copy_files files
{
	int i = 0;
	for (i = 0; i < count; i++)
		copy_files[i] = files[i];
}

void get_path()
{
	int i = 0;
	while ((getchar()) != '\n');
	printf("Введите путь до директории:");
	gets_s(path, 256);
	for (i = 0; i < 255; i++)
		if (path[i] == "\\")
			path[i] = "/";
	strcat(path, "/");
	strcat(path, "*");
}

void print_sorts()
{
	printf("Программа предоставляет следующие виды сортировок:\n");
	printf("1.Пузырьком\n");
	printf("2.Выбором\n");
	printf("3.Вставками\n");
	printf("4.Слиянием\n");
	printf("5.Хоара\n");
	printf("6.Шелла\n");
	printf("7.Подсчетом\n");
}

void guid()
{
	printf("Основные функции:\n");
	printf("1.В главном меню введите \"1\"\n");
	printf("2.Введите путь до директории в виде:\"диск:\\название папки\\название папки\\...\\конечная папка\"\n");
	printf("3.Выберите сортировку и вывод файлов по возрастанию или убыванию размера\n");
	printf("Дополнительные функции:\n");
	printf("В конце программа выведет таблицу с результатами измерений\n");
	printf("Дополнительная информация:\n");
	printf("Ограничено использование смен сортировки(максимум 14)\n");
	printf("После вывода информации по выбранной сортировке будет написано количество оставшихся смен сортировок\n");
}

int count_files(char* path)//считает кол-во файлов
{
	int count = 0;
	struct _finddata_t c_file;
	intptr_t hFile;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		return -1;
	else
	{
		do {
			if (c_file.attrib & _A_SUBDIR)
				continue;
			count++;
		} while (_findnext(hFile, &c_file) == 0);
	}
	_findclose(hFile);
	return count;
}

void BubbleSort(struct _finddata_t* copy_files, int count)
{
	struct _finddata_t temp;
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if (copy_files[j].size < copy_files[j - 1].size)
			{
				temp = copy_files[j];
				copy_files[j] = copy_files[j - 1];
				copy_files[j - 1] = temp;
			}
		}
	}
}

void SelectSort(struct _finddata_t* copy_files, int count)
{
	struct _finddata_t temp;
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < count; i++)
	{
		k = i;
		temp = copy_files[i];
		for (j = i+1; j < count; j++)
		{
			if (copy_files[j].size < temp.size)
			{
				k = j;
				temp = copy_files[j];
			}
		}
		copy_files[k] = copy_files[i];
		copy_files[i] = temp;
	}
}

void InsertSort(struct _finddata_t* copy_files, int count)
{
	struct _finddata_t temp;
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++)
	{
		temp = copy_files[i];
		for (j = i - 1; j >= 0 && temp.size < copy_files[j].size; j--)
			copy_files[j + 1] = copy_files[j];
		copy_files[j + 1] = temp;
	}
}

void merge(struct _finddata_t* copy_files, int left, int middle, int right)
{
	int pos1 = left;
	int pos2 = middle + 1;
	int pos3 = 0;
	int size = right - left + 1;
	struct _finddata_t* temp = (struct _finddata_t*)malloc(sizeof(struct _finddata_t) * (size));
	while (pos1 <= middle && pos2 <= right)
	{
		if (copy_files[pos1].size < copy_files[pos2].size)
			temp[pos3++] = copy_files[pos1++];
		else
			temp[pos3++] = copy_files[pos2++];
	}
	while (pos2 <= right)
		temp[pos3++] = copy_files[pos2++];
	while (pos1 <= middle)
		temp[pos3++] = copy_files[pos1++];
	for (pos3 = 0;  pos3< size; pos3++)
		copy_files[left + pos3] = temp[pos3];

	free(temp);
}

void MergeSort(struct _finddata_t* copy_files,int left,int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + right) / 2;
		MergeSort(copy_files, left, middle);
		MergeSort(copy_files, middle + 1, right);
		merge(copy_files,left,middle,right);
	}
}

void QuickSort(struct _finddata_t* copy_files, int count)
{
	int i=0;
	int j = count - 1;
	struct _finddata_t temp;
	struct _finddata_t mid;
	mid = copy_files[count >> 1];

	do {
		while (copy_files[i].size < mid.size)
			i++;
		while (copy_files[j].size > mid.size)
			j--;
		if (i <= j)
		{
			temp = copy_files[i];
			copy_files[i] = copy_files[j];
			copy_files[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		QuickSort(copy_files, j);
	if (count > i)
		QuickSort(copy_files + i, count - i);
}

int increment(long inc[], int count)
{
	int p1;
	int p2;
	int p3;
	int	s;

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

void ShellSort(struct _finddata_t* copy_files, int count)
{
	struct _finddata_t temp;
	int inc;
	int i;
	int j;
	int seq[40] = {0};
	int s;

	s = increment(seq, count);
	while (s >= 0)
	{
		inc = seq[s--];

		for (i = inc; i < count; i++)
		{
			temp = copy_files[i];
			for (j = i - inc; (j >= 0) && (copy_files[j].size > temp.size); j -= inc)
				copy_files[j + inc] = copy_files[j];
			copy_files[j + inc] = temp;
		}
	}
}

void CountingSort(struct _finddata_t* copy_files,int count)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int size = 0;
	int max = copy_files[0].size;
	int min = copy_files[0].size;
	int* sizes;
	struct _finddata_t temp;

	for (i = 0; i < count; i++)
	{
		if (max < copy_files[i].size)
			max = copy_files[i].size;
		if (min > copy_files[i].size)
			min = copy_files[i].size;
	}
	size = max - min + 1;
	sizes = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		sizes[i] = 0;
	for (i = 0; i < count; i++)
		sizes[copy_files[i].size - min]++;
	for (i = 0; i < size; i++)
	{
		while (sizes[i] > 0)
		{
			for (j = 0; j < count; j++)
			{
				if (copy_files[j].size == min + i)
				{
					temp = copy_files[j];
					copy_files[j] = copy_files[k];
					copy_files[k] = temp;
					k++;
					sizes[i]--;
				}
			}
		}
	}
	free(sizes);
}

void main(void)
{
	int count_of_sorts = 0; //кол-во использованныъ сортировок(для заполнения структуры sorts) 
	int choice = 0;//выбор сортировки
	int ch1 = 0; //используется для запроса смены сортировки
	int pm1 =0;//выбор в меню
	int type = 0;//вид сортировки по позрастанию или убыванию
	int count_of_files = 0;
	int attempts = 14;
	int i = 0;
	int j = 0;
	struct info* sorts = (struct info*)malloc(sizeof(struct info) * 14); // 14 потому что вряд ли кто-то будет использовать каждую сортировку по 2 раза или не каждую, но большое кол-во раз(можно увеличить)
	int count = -1; //используется для проверки на наличие файлов в директории и правильности указанного пути
	double t1, t2;
	struct _finddata_t* files; //основная структура, куда считываются все данные с файлов
	struct _finddata_t* copy_files;//структура, которая используется в сортировках(копия files)
	intptr_t hFile;
	setlocale(LC_ALL, "Russian");	
	print_main_menu();
	scanf_s("%d", &pm1);
	system("cls");
	while (pm1 != 0)
	{
		switch (pm1) //меню
		{
		case 1:
			while (count == -1)
			{
				get_path();
				count = count_files(path);
				if (count == -1)
				{
					printf("Ошибка ввода пути или в директории отсутствуют файлы, попробуйте еще раз, для ввода пути нажмите Enter");
					path[0] = '\0';
				}
			}
			files = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));
			hFile = _findfirst(path, &files[0]);
			printf("Listing of .c files\n\n");
			printf("FILE         DATE %24c   SIZE\n", ' ');
			printf("----         ---- %24c   ----\n", ' ');
			do {
				if (files[i].attrib & _A_SUBDIR)
					continue;
				char buffer[30];
				ctime_s(buffer, _countof(buffer), &files[i].time_write);
				printf("%-12.12s %.24s %10ld\n", files[i].name, buffer, files[i].size);
				i++;
				count_of_files++;
			} while (_findnext(hFile, &files[i]) == 0);
			_findclose(hFile);
			copy_files = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));//выделяем память для клона структур файлов
			do {
				create_copy(copy_files, files, count);
				printf("Выберите сортировку:\n");
				printf("1-Пузырьком\n");
				printf("2-Выбором\n");
				printf("3-Вставками\n");
				printf("4-Слиянием\n");
				printf("5-Хоара\n");
				printf("6-Шелла\n");
				printf("7-Подсчетом\n");
				scanf_s("%d", &choice);
				while ((choice > 7) || (choice < 1))
				{
					printf("Ошбика выбора сортировки, попробуйте еще раз: ");
					scanf_s("%d", &choice);
				}
				system("cls");
				switch (choice) //сортировки
				{
				case 1:
					printf("Вы выбрали сортировку \"Пузырьком\"\n");
					t1 = omp_get_wtime();
					BubbleSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Пузырьком";
					sorts[count_of_sorts].time = t2-t1;
					break;
				case 2:
					printf("Вы выбрали сортировку \"Выбором\"\n");
					t1 = omp_get_wtime();
					SelectSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Выбором";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				case 3:
					printf("Вы выбрали сортировку \"Вставками\"\n");
					t1 = omp_get_wtime();
					InsertSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Вставками";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				case 4:
					printf("Вы выбрали сортировку \"Слиянием\"\n");
					t1 = omp_get_wtime();
					MergeSort(copy_files, 0, count - 1);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Слиянинем";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				case 5:
					printf("Вы выбрали сортировку \"Хоара\"\n");
					t1 = omp_get_wtime();
					QuickSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Хоара";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				case 6:
					printf("Вы выбрали сортировку \"Шелла\"\n");
					t1 = omp_get_wtime();
					ShellSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Шелла";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				case 7:
					printf("Вы выбрали сортировку \"Подсчетом\"\n");
					t1 = omp_get_wtime();
					CountingSort(copy_files, count);
					t2 = omp_get_wtime();
					sorts[count_of_sorts].name = (char*)malloc(sizeof(char) * 15);
					sorts[count_of_sorts].name = "Подсчетом";
					sorts[count_of_sorts].time = t2 - t1;
					break;
				}
				printf("Выберите тип сортировки:1-По возрастанию 2-По убыванию\n");
				scanf_s("%d", &type);
				while (type != 1 && type != 2)
				{
					printf("Ошибка выбора типа сортировки, попробуйте еще раз: ");
					scanf_s("%d", &type);
				}
				printf("Listing of .c files\n\n");
				printf("FILE       %10c    SIZE\n", ' ');
				printf("----       %10c    ----\n", ' ');
				if (type == 1)
				{
					for (i = 0; i < count; i++)
						printf("%-12.12s %15ld\n", copy_files[i].name, copy_files[i].size);
				}
				else if (type == 2)
				{
					for (i = count - 1; i >= 0; i--)
						printf("%-12.12s %15ld\n", copy_files[i].name, copy_files[i].size);
				}
				printf("Время сортировки составило:%lf (сек)\n", (t2 - t1));
				printf("Количество файлов:%d\n", count_of_files);
				attempts--;
				printf("Количество оставшихся попыток сменить сортировку:%d\n", attempts);
				if (attempts == 0)
				{
					printf("Попытки смены сортировок закончились\n");
					ch1 = 2;
				}
				else
				{
					printf("Хотите изменить сортировку?1-Да 2-Нет\n");
					scanf_s("%d", &ch1);
				}
				while (ch1 != 1 && ch1 != 2)
				{
					printf("Ошибка ввода попробуйте еще раз\n");
					scanf_s("%d", &ch1);
				}
				count_of_sorts++;
			} while (ch1 != 2);
			printf("Сортировка:   Время(сек):\n");
			for (i = 0; i < count_of_sorts; i++)
				printf("%-12.12s  %lf\n", sorts[i].name, sorts[i].time);
			printf("Для завершения работы программы введите 0\n");
			scanf_s("%d", &pm1);
			while (pm1 != 0)
			{
				printf("Ошибка, введите 0");
				scanf_s("%d", &pm1);
			}
			break;
		case 2:
			print_sorts();
			printf("Для возвращения в главное меню введите 0\n");
			scanf_s("%d", &pm1);
			system("cls");
			if (pm1 == 0)
			{
				print_main_menu();
				scanf_s("%d", &pm1);
			}
			break;
		case 3:
			guid();
			printf("Для возвращения в главное меню введите 0\n");
			scanf_s("%d", &pm1);
			if (pm1 == 0)
			{
				print_main_menu();
				scanf_s("%d", &pm1);
			}
			break;
		case 0:
			return;
		default:
			printf("Ошибка выбора в меню, попробуйте еще раз\n");
			print_main_menu();
			scanf_s("%d", &pm1);
			system("cls");
			break;
		}
	}
	system("pause");
}