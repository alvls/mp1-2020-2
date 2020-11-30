/*Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию/убыванию размера.

Входные данные:
Путь до директории, в которой необходимо отсортировать содержимое.
Метод сортировки.
Выходные данные:
Отсортированный список имен файлов с указанием размера.
Время сортировки.
Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.

Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает:
возможность ввода пути до заданного каталога;
возможность выбора метода сортировки;
возможность просмотра отсортированного списка файлов с указанием размера.
Cписок методов сортировки:
1.пузырьком
2.выбором
3.вставками
4.слиянием
5.Хоара
6.Шелла
7.подсчётом
*/
			//Необходимое для работы программы
#define _CRT_SECURE_NO_WARNINGS

			//Подключение библиотек.
#include<stdio.h>
#include<memory.h>
#include<locale.h>
#include<omp.h>
#include<string.h>
#include<io.h>
#include<stdlib.h>

			//Константы.
#define SIZE_OF_PATH_FOR_DIRECT 256
#define SIZE_OF_HELP_ARR 10000

			//Структуры.
typedef struct data
{
	char name[SIZE_OF_PATH_FOR_DIRECT];
	unsigned long size;
}helpfile;
			//Глобальные переменные.
helpfile now_c_file[SIZE_OF_HELP_ARR];//в этом массиве сохраняем имя и размер при обработке файла.
char forsortpath[SIZE_OF_PATH_FOR_DIRECT]; //Хранит значение пути для выбора этого же пути на новой сортировке/
			//Объявление протипов функций.
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

			//Главная функция.
void main()
{
	setlocale(LC_ALL, "Rus");
	printf("Здравствуйте, уважаемый пользователь, рады вас видеть в нашей программе!\n");
	Menu();
}

			//Функция, кторое показывает меню программы.
void Menu()
{
	int choice = -1;
	char clean;
	printf("В программе доступны следующие функции:\n1.Посмотреть инструкцию по использованию функции.\n2.Приступить к работе.\n0.Выход из программы.\n");
	while ((choice < 0)||(choice > 2))
	{
		scanf_s("%d", &choice);
		if ((choice < 0) || (choice > 2))
		{
			printf("Ошибка, вы пытаетесь ввести недопустипое число, введите \"1\",\"2\",\"0\"!\n");
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
		printf("Программа завершила свою работу!\n");
		system("pause");
		break;
	}
}

			//Инструкция по использованию программы.
void Instraction()
{
	system("cls");
	printf("\t\t\tИнструкция по использованию!\n");
	printf("Сначала вы попадаете в меню, где может выбрать одну из функций:\n(1)Инструкция - раздел, где вы можете почитать о том как работает программа\n");
	printf("(2)Приступить к работе - основной раздел программы, где будет реализовываться работа с данными\n(0)Выход из программы - завершение работы с ней\n");
	printf("При выборе (2) вам будет предоставлена возможность ввести путь до папки, где вы хотите отсортировать файлы,\nдальше вам будет предоставлен выбор как их отсортировать:\n(1) - по возрастанию\n(2) - по убыванию.\n");
	printf("После этого будет предоставлен выбор из 7 разных видов сортировки, которым вы захотите отсортировать массив разных файлов.\nПосле выбора вида сортировки, у вас на экране появится список наименований всех файлов и мх размера по убыванию/по возрастанию,\nа так же общее количество  и время, которое было потрачено на сортировку.\n");
	printf("И наконец после этого программа вам продложит отсортировать этот же массив файлов заново, используя другой метод сортировки, например, или же закончить работу с программой.\n");
	printf("На этом всё, желаем приятного пользования программой!\n");
	system("pause");
	system("cls");
	Menu();
}
			//Получение пути до папки с файлами.
void GetData()
{
	struct _finddata_t now_file;
	intptr_t hFile;
	char path[SIZE_OF_PATH_FOR_DIRECT]; //путь, который был введён пользователь.
	int count_files = 0, i; //подсчёт количества файлов в папке.	
	printf("Уважаемый пользователь, введите путь к папке с файлами:\n");
	fgets(path, SIZE_OF_PATH_FOR_DIRECT, stdin);
	ChangePath(path);
	if ((hFile = _findfirst(path, &now_file)) == -1L)//Данное условие показывает, когда путь к папке указан неверно,  потому что в любой папке есть два файла . и ..
	{
		printf("Введённый путь написан неправильно!Пожалуйста, повторите ввод!\n");
		system("pause");
		GetData(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
	}
	else //Получаем имена, записываем их в массив и сортируем массив файлов по размерам
	{
		do
		{
			if (count_files > 1) //т.к. 0 и 1 были . и ..
			{
				now_c_file[count_files - 2/*Не учитываем первые 2 файла*/].size = now_file.size;//Копируем в массив размер текущего файла, для его последующего использования.
				strcpy(now_c_file[count_files - 2].name, now_file.name);//Копируем название текущего файла в массив для дальнейшей сортировки.
			}
			count_files++;
		} while ((_findnext(hFile, &now_file) == 0) && (count_files < SIZE_OF_HELP_ARR/*Максимальное колтичество файлов*/)); //До того момента, пока файлы в папке не кончатся
		_findclose(hFile);
		strcpy(forsortpath, path);//Копируем путь для папки с файлами для дальнейшего использования.
		count_files -= 2; //Так как в любой папке существует минимум два файла . и ..
		if (count_files == 0)
		{
			printf("По этому пути не найдено ни одного файла!Пожалуйста повторите ввод!\n"); //Ни одного существенного файла, но пользователь не догадается, что в папке существуют скрытые файлы
			GetData(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
		}
		else
		{
			ChoiceMetodSort(count_files);
		}
	}
}
			//Изменения пути для папки с файлами.
void ChangePath(char* path)
{
	int size = strlen(path);//находим длину строки path.
	if (size < 3)
	{
		printf("Уважаемый потльзователь, слишком короткий путь, повторите ввод!\n");
		GetData(); //любой путь должен начинаться минимум с такого набора символов c:'\0'.
	}
	if (path[size - 3] != '\\') //Добавит в строку '/' для программы
	{
		size++;
		path[size - 2] = '\\';
	}
	if (path[size - 2] != '*') //Добавит в строку *, чтобы в этой папке проверить все файлы
	{
		size++;
		path[size - 2] = '*';
	}
	path[size - 1] = '\0'; //Обрезаем строку
	for (int i = 0; i < size; i++)
	{
		if (path[i] == '\\') //Создаём двойной '/' ('//') для программы
		{
			i++; //Чтобы пропустить вставленную '/'
			if (path[i] == path[i - 1]) //Если уже существует двойной '/', то ничего раздваивать не нужно, переходим на следующий символ
				continue;
			size++;
			for (int j = size - 1; j > i - 1; j--) //чтобы раздвоить '/' смещаем все символы на 1 вправо, при этом заканчиваем перезаписывать символы на найденном '/'
			{
				path[j] = path[j - 1];
				//printf("%s\n", path); //для проверки разработчиком
			}
		}
	}
}
			//Выбор метода сортировки и выведение данных.
void ChoiceMetodSort(count_files)
{
	int choicesort = 0, choicemetod = 0, choiceaction = 0, countuser = 0;
	long double t0 = 0, t1 = 0;
	printf("Давайте выберем каким способом вы хотите отсортировать файлы:\n1.По возрастанию.\n2.По убыванию.\n");
	while ((choicemetod < 1) || (choicemetod > 2))
	{
		scanf_s("%d", &choicemetod);
		if ((choicemetod < 1) || (choicemetod > 2))
		{
			printf("Уважаемый пользователь, вы ввели неверную информацию, введите цифру \"1\" или \"2\"\n");
		}
	}
	printf("Пора выбрать метод сортировки.В программе предоставлены:\n1.пузырьком.\n2.выбором.\n3.вставками.\n4.слиянием.\n5.Хоара.\n6.Шелла.\n7.подсчётом.\n");
	while ((choicesort < 1) || (choicesort > 7))
	{
		scanf_s("%d", &choicesort);
		if ((choicesort < 1) || (choicesort > 7))
		{
			printf("Уважаемый пользователь, вы ввели неверную информацию, введите цифру от 1 до 7\n");
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
	printf("\n%43cСписок файлов\n\nФайл%75cРазмер\n----%75c------\n", ' ', ' ', ' ');
	for (int i = 0; i < count_files; i++) //. и .. занимают 0 и 1 индексы, поэтому начинаем со второго индекса
	{
		printf("%-70s %16lu байт\n", now_c_file[i].name, now_c_file[i].size);
	}
	printf("\nВсего файлов: %d\n", count_files);
	printf("Время сортировки: %f (сек)\n\n\n", t1);
	system("pause");
	system("cls");
	printf("Уважаемый пользователь, хотите ли вы использовать другой метод сортировки для этого набора файлов?\n");
	printf("Введите \"1\" для того, чтобы отсортировать эти данные с помощью другого метода сортировки.\nВведите \"2\" для того, чтобы завершить работу программы.\n");
	while ((choiceaction < 1) || (choiceaction > 2))
	{
		scanf_s("%d", &choiceaction);
		if ((choiceaction < 1) || (choiceaction > 2))
		{
			printf("Вы ввели неверное число, повторите ввод!\n");
		}
	}
	if (choiceaction == 1)
	{
		system("cls");
		ChoiceMetodSort(count_files);
	}
	else
	{
		printf("Программа завершила свою работу!\n");
		system("pause");
		return;
	}
}
			//Сортировка Пузырьком По Возрастанию.
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
			//Сортировка Пузырьком По Убыванию.
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
		//Сортировка Выбором По Возрастанию.
void SelectSortUp(int count_files)
{
	helpfile dop_file_min;
	int k;
	for (int i = 0; i < count_files - 1/*Вопрос, работает ли так*/; i++)
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
		//Сортировка Выбором По Убыванию.
void SelectSortDown(int count_files)
{
	helpfile dop_file_max;
	int k;
	for (int i = 0; i < count_files - 1/*Вопрос, работает ли так*/; i++)
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
		//Сортировка Вставками По Возрастанию.
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
			//Сортировка Вставками По Убыванию.
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
			//Сортировка Слиянием По Возрастанию.
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
			//Сортировка Слиянием По Убыванию.
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
			//Быстрая Сортировка.
void HoaraSort(helpfile* now_c_file, int count_files)
{
	int i = 0;
	int j = count_files;
	int mid = count_files / 2;
	unsigned long sizemidelem = now_c_file[mid].size;
	helpfile dop_file_for_swap;
	do
	{
		while (now_c_file[i].size > sizemidelem)//> должно быть 
		{
			i++;
		}
		while (now_c_file[j].size < sizemidelem)//< должно быть 
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

			//Обратная Сортировка.
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

			//Вспомогательная Функция Для Сортировки Шелла.
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
			//Сортировка Шелла По Возрастанию.
void ShellSortDown(int count_files, helpfile* now_c_file)
{
	long inc, i, j, seq[40];
	int s;
	helpfile dop_file_for_swap;
	s = Increment(seq, count_files);
	while (s >= 0)
	{
		// сортировка вставками с инкрементами inc[] 
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
			//Сортировка Шелла По Убыванию.
void ShellSortUp(int count_files, helpfile* now_c_file)
{
	long inc, i, j, seq[40];
	int s;
	helpfile dop_file_for_swap;
	s = Increment(seq, count_files);
	while (s >= 0)
	{
		// сортировка вставками с инкрементами inc[] 
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
			//Сортировка Подсчётом.
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
