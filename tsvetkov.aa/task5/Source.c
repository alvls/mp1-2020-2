#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
#include <windows.h>
#include <omp.h>

char a[80];//строка адреса директории
int count = 0;//количество файлов в директории

//очитска консоли
void console() // очистка консоли перед выводом чека
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
//функция для считывания и обработки адреса вводимого пользователем
void vvod()
{
	printf("Введите адрес файла\n");
	int i = 0;
	gets(a);
	while (a[i] != '\0')
	{
		if (a[i] == '\\')
			a[i] = '/';
		i++;
	}
	a[i++] = '/';
	a[i++] = '*';
	a[i++] = '.';
	a[i++] = '*';
	a[i] = '\0';
}
//структура для записи информации файлов
struct info
{
	int size;
	char name[70];
};
//запись информации о файлах в массив структур
void obrabotka(struct info file[])
{
	int i = 0;
	struct _finddata_t c_file;
	intptr_t hFile;
	if ((hFile = _findfirst(a, &c_file)) != -1L)
		if (_findnext(hFile, &c_file) == 0)
			if (_findnext(hFile, &c_file) != 0)
				printf("No files in current directory!\n");
			else
			{

				do {
					char buffer[30];
					ctime_s(buffer, _countof(buffer), &c_file.time_write);

					//count++;
					file[i].size = c_file.size;
					strcpy(file[i].name, c_file.name);
					i++;
				} while (_findnext(hFile, &c_file) == 0);
				_findclose(hFile);
			}



}
//подсчет количества файлов директории
void counts()
{

	struct _finddata_t c_file;
	intptr_t hFile;
	if ((hFile = _findfirst(a, &c_file)) != -1L)
		if (_findnext(hFile, &c_file) == 0)
			if (_findnext(hFile, &c_file) != 0)

				printf("Файлов не обнаружено!\n");


			else
			{

				do {
					char buffer[30];
					ctime_s(buffer, _countof(buffer), &c_file.time_write);

					count++;
				} while (_findnext(hFile, &c_file) == 0);
				_findclose(hFile);

			}


}
//составное меню из 2 частей
int menu1()
{
	int n;

	printf("Выберите дальнешее действие\n");
	printf("1.Ввести адрес\n2.Выйти\n");
	scanf_s("%d", &n);
	return n;


}
int menu2()
{
	int n;
	printf("Выберите дальнешее действие\n");
	printf("1.Вывести список файлов\n2.Отсортировать файлы пузырьком\n3.Отсортировать файлы выбором\n4.Отсортировать файлы вставками\n5.Отсортировать файлы слиянием\n6.Отсортировать файлы сортировкой Хоара");
	printf("\n7.Отсортировать файлы сортировкой Шелла\n8.Отсортировать файлы подсчетом\n0.Выйти из программы\n");
	scanf_s("%d", &n);
	return n;



}
//вывод файлов директории на консоль
void print(struct info file[])
{
	int i = 0;
	printf("\nНайдено файлов: %d\n", count);
	printf("FILE         %64c   SIZE\n", ' ');
	printf("----         %64c   ----\n", ' ');
	for (i = 0; i < count; i++)
	{

		printf("%-70s          %d\n", file[i].name, file[i].size);
		// printf("%d\n", file[i].size);
	}

}
//сортировка слиянием
void merge(struct info file[], int left, int right, int mid)
{

	int k = right - left + 1;
	int pos1 = left;
	int pos2 = mid + 1;
	int pos3 = 0;
	struct info* tmp;
	tmp = (struct info*)malloc(k * sizeof(struct info));
	while ((pos1 <= mid) && (pos2 <= right))
	{
		if (file[pos1].size < file[pos2].size)
			tmp[pos3++] = file[pos1++];
		else
			tmp[pos3++] = file[pos2++];
	}
	while (pos2 <= right)
		tmp[pos3++] = file[pos2++];
	while (pos1 <= mid)
		tmp[pos3++] = file[pos1++];
	for (pos3 = 0; pos3 < right - left + 1; pos3++)
		file[left + pos3] = tmp[pos3];
	free(tmp);
}
void mergesort(struct info file[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left == right)
		return;
	mergesort(file, left, mid);
	mergesort(file, mid + 1, right);
	merge(file, left, right, mid);
}
//cортировка пузырьком
void bubble(struct info file[], int size)
{
	int i, j, k = 0;
	struct info tmp;
	if (k != -1)
		for (i = 0; i < size; i++)
			for (j = size - 1; j > i; j--)
				if (file[j].size < file[j - 1].size)
				{
					tmp = file[j];
					file[j] = file[j - 1];
					file[j - 1] = tmp;
					k = j;
				}
				else
					k = -1;
}
//сортировка выбором
void choice(struct info file[], int size)
{
	int i, j, k;
	struct info tmp;
	for (i = 0; i < size; i++)
	{
		tmp = file[i]; k = i;
		for (j = i + 1; j < size; j++)
			if (file[j].size < tmp.size)
			{
				k = j;
				tmp = file[j];
			}
		file[k] = file[i];
		file[i] = tmp;
	}
}
//сортировка вставками
void vstavka(struct info file[], int size)
{
	int i, j;
	struct info tmp;
	struct info min;
	min = file[0];
	for (i = 1; i < size; i++)
		if (file[0].size > file[i].size)
			file[0] = file[i];
	for (i = 1; i < size; i++)
	{
		tmp = file[i];

		for (j = i - 1; file[j].size > tmp.size; j--)
			file[j + 1] = file[j];

		file[j + 1] = tmp;
	}


	for (j = 1; j < size && file[j].size < min.size; j++)
		file[j - 1] = file[j];


	file[j - 1] = min;
}


//сортировка хоара
void quick_sort(struct info file[], int left, int right)
{
	struct info tmp;
	struct info mid;

	mid = file[(left + right) / 2];
	int i = left, j = right;
	while (i < j)
	{
		while (file[i].size < mid.size) i++;
		while (file[j].size > mid.size) j--;
		if (i <= j)
		{
			tmp = file[i];
			file[i] = file[j];
			file[j] = tmp;
			i++;
			j--;
		}

	}
	if (left < j)
	{
		quick_sort(file, left, j);
	}
	if (i < right)
	{
		quick_sort(file, i, right);
	}
}
//сортировка шелла
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
	if (s > 0)
		return  --s;
	else
		return 0;
}


void shellSort(struct info file[], int size)
{
	long inc, i, j, seq[40];
	int s;
	struct info tmp;

	// вычисление последовательности приращений
	s = increment(seq, size);
	while (s >= 0) {
		// сортировка вставками с инкрементами inc[] 
		inc = seq[s--];

		for (i = inc; i < size; i++) {
			tmp = file[i];
			for (j = i - inc; (j >= 0) && (file[j].size > tmp.size); j -= inc)
				file[j + inc] = file[j];
			file[j + inc] = tmp;
		}
	}
}
//сортировка подсчетом,работает если разница размеров файлов не очень велика,внутри есть проверка на возможность такой сортировки, если она невозможна,пользователь может выбрать другой способ
int score(struct info file[], int size)
{
	int i;
	int check = 0;
	int  min, max;
	int k, x = 0;
	struct info* count;
	min = max = file[0].size;
	for (i = 1; i < size; i++)
	{
		if (file[i].size < min)
			min = file[i].size;
		else if (file[i].size > max)
			max = file[i].size;
	}
	k = max - min + 1;
	count = (struct info*)malloc(k * sizeof(struct info));
	if (count == 0)
	{
		printf("Сортировка не может быть выполнена,выберите другой тип\n");
		check = -1;
		return check;

	}
	for (int i = 0; i < k; i++)
		count[i].size = 0;
	for (i = 0; i < size; i++)
	{
		count[file[i].size - min].size++;
		strcpy(count[file[i].size - min].name, file[i].name);
	}
	for (i = 0; i < k; i++)
		while (count[i].size > 0)
		{
			file[x].size = min + i;
			strcpy(file[x++].name, count[i].name);
			count[i].size--;
		}
	free(count);
	return check;

}





//очитска потока ввода
void clean()//очистка потока воода
{

	int c;
	do
	{
		c = getchar();
	} while ((c != '\n') && (c != EOF));

}
void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	setlocale(LC_ALL, "Russian");
	printf("Добро пожаловать\n");
	//k:

		//count = 0;
	int i = 0; int n, p, left = 0, right;//n,p-для выбора редима меню//right/left границы для некоторых сортировок
	double tt1, tt2;//время
	n = menu1();
	if (n == 2)//выбор выхода
		return;
	if (n == 1)//ввести адрес
	{
	k:
		count = 0;//обнуление количества вайлов
		console();//чистка консоли
		clean();//очистка потока ввода
		vvod();//вызов функции ввода
		counts();//подсчет количества
		right = count - 1;
		if (count != 0)
		{

			struct info* file = (struct info*)malloc(count * sizeof(struct info));
			obrabotka(file);//заполнение массива структур
		l:
			p = menu2();//значение выбора меню


			switch (p)
			{
			case 1: print(file); break;//вывод файлов без сортировки
			case 2://пузырьком

				tt1 = omp_get_wtime();
				bubble(file, count);
				tt2 = omp_get_wtime();
				print(file);
				break;
			case 3://выбором
				tt1 = omp_get_wtime();
				choice(file, count);
				tt2 = omp_get_wtime();
				print(file);
				break;
			case 4://вставками

				tt1 = omp_get_wtime();
				vstavka(file, count);
				tt2 = omp_get_wtime();
				print(file);
				break;

			case 5://слиянием

				tt1 = omp_get_wtime();
				mergesort(file, left, right);
				tt2 = omp_get_wtime();
				print(file);
				break;
			case 6://быстрая сортировка

				tt1 = omp_get_wtime();
				quick_sort(file, left, right);
				tt2 = omp_get_wtime();
				print(file);
				break;
			case 7://сортировка шелла
				tt1 = omp_get_wtime();
				shellSort(file, count);
				tt2 = omp_get_wtime();
				print(file);
				break;
			case 8://подсчетом
				tt1 = omp_get_wtime();
				n = score(file, count);
				tt2 = omp_get_wtime();
				if (n == 0)//проверка на возможность такой сортировки
					print(file);
				else goto l;
				break;
			case 0://выход

				return;
				break;


			}
			if (p != 1)//вывод времени если не был выбран вывод файлов без сортировки
				printf("Время сортировки составило=%lf\n", tt2 - tt1);
			n = menu1();//вывод повторного меню
			if (n == 2)
				return;
			else
			{
				console();
				goto k;
			}

		}
		else//если файлов не найдено
			n = menu1();
		if (n == 2)
			return;
		else
		{
			console();
			goto k;
		}













	}
}