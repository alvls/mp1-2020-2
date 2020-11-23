/*  + Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию/убыванию размера.
Входные данные:
    + Путь до директории, в которой необходимо отсортировать содержимое.
    + Метод сортировки.
Выходные данные:
    + Отсортированный список имен файлов с указанием размера.
    + Время сортировки.
    + Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.
    + Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает:
    + возможность ввода пути до заданного каталога;
    + возможность выбора метода сортировки;
    + возможность просмотра отсортированного списка файлов с указанием размера.
Cписок методов сортировки: пузырьком, выбором, вставками, слиянием, Хоара, Шелла, подсчетом */

#define _CRT_SECURE_NO_WARNINGS

//Подключение библиотек
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //Отвечает за внешний ввод и вывод input output
#include <omp.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //Используем здесь для поддержки русского языка (если конкретнее, то для того, чтобы пользователь мог вводить папки с русскими буквами)

//Стуктура, содержащая полученную информацию по одному файлу
typedef struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
} oneinf;

//Структура, содержащая общую информацию по сортировкам
typedef struct fullinformationaboutsorts
{
    short typesort; //Метод сортировки
    short updown; //Возрастание или убывание
    int countoffiles; //Количество файлов
    long double timer; //Время сортировки
} fullinf; 

//Объявление функций
int menu();
void polzsorttype(int i); //Выводит на экран выбранную пользователем сортировку (для таблицы и работы во время кода)
int getinform(); //Осуществлет получение информации по файлам
char preobr(char* path); //Преобразовывает путь, введённый пользователем, в путь, который нужен программе
int choiceyoursort(int count, oneinf* c_file); //Позволяет построить сортировку на любой вкус
void printgran(int type, int i); //Рисует грани
void fullvivod(); //Вывод информацию по всем сортировкам
void vozrandubyv(int a); //Выводит на экран информацию для сортировки: по возрастанию или убыванию
void clearscreen(int x, int y); //Очищает экран по координатам
void pipetoxy(int x, int y); //Перемещение по координатам
void bubblesort(int count, oneinf* c_file); //Сортировка пузырьком
void selectsort(int count, oneinf* c_file); //Сортировка выбором
void insertsort(int count, oneinf* c_file); //Сортировка вставками
void mergesort(int left, int right, oneinf* c_file); //Сортировка слиянием
void merge(int lefte, int right, oneinf* c_file); //Слияние двух массивов
void quicksort(oneinf* c_file, int count); //Хоара=быстрая
int shellsort(int count, oneinf* c_file); //Сортировка Шелла
int increment(long inc[], int count); //Дополнительная функция для сортировки Шелла
int countingsort(int count, oneinf* c_file); //Сортировка подсчётом
void vozrastanie(int count, oneinf* c_file); //Если пользователь выбрал сортировку по убыванию, то эта функция отзеркалит массив, который уже отсортирован по убыванию
void* checknull(void* arr) //Проверка на возможность выделить динамическую память
{
    if (arr == 0)
    {
        printf("Произошло переполнение памяти. Нет возможности продолжить работу программы.\n");
        system("pause");
        exit(55);
    }
    return (arr);
}

//Объявление глобальных переменных
fullinf* inf; //Полная информация по каждой из сортировок 
long ind = 0; //Количество сортировок (для выделения памяти)

void main()
{
    int vixod = -1;
    setlocale(LC_ALL, "Russian"); //Поддержка русского языка
    SetConsoleCP(1251); //Поддержка русского языка (чтобы путь можно было считать нормально)
    SetConsoleOutputCP(1251); //Поддержка русского языка (чтобы путь можно было считать нормально)
    printf(" Приветствую! Я - программа, созданная для сортировки файлов.\n");
    while (vixod != 0)
    {
        vixod = menu();
    }
    system("cls");
    printf("\n");
    printgran(1, 73);
    printf("| Мы стараемся над улучшением нашей программы, следите за обновлениями! |\n");
    printgran(1, 73);
    free(inf);
    printf("\n Программа завершит работу самостоятельно через:");
    for (int i = 0; i < 6; i++)
    {
        printf(" %d...", 5 - i);
        Sleep(900);
        clearscreen(48, 5);
    }
}

int menu()
{
    printgran(1, 61);
    printf("  Сейчас Вы находитесь в меню. Выберите, что нужно сделать:\n\t(1) Отсортировать файлы в новой папке\n\t(2) Вывести всю информацию, полученную из сортировок\n\t(0) Выйти из программы\n");
    printgran(1, 61);
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 2))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 0) || (vibor > 2))
        {
            printf("Данная функция не предусмотрена программой. Введите число от 0 до 2.\n");
            while (getchar() != '\n');
        }
    }
    c = getchar();
    switch (vibor)
    {
    case 1:
        system("cls");
        ind++;
        getinform();
        return 1;
    case 2:
        system("cls");
        fullvivod();
        return 2;
    case 0:
        return 0;
    default:
        printf("Ошибка, связанная с выбором в меню");
        break;
    }
}

int getinform()
{
    oneinf* c_file; //в этом массиве сохраняем имя и размер при обработке файла
    struct _finddata_t inf_file; //в эту структуру сохраняется вся информация по найденному файлу
    intptr_t hFile;
    char path[FILENAME_MAX]; //путь, который ввёл пользователь
    int count = 0; //подсчёт количества файлов
    
    inf = checknull(realloc(inf, ind * sizeof(fullinf)));
    printf("\n Введите путь к папке с файлами:\n");
    fgets(path, FILENAME_MAX, stdin); //scanf_s в данном случае выдаёт множество ошибок
    system("cls");
    printf("\n Вы ввели путь: %s\n", path);
    if (strlen(path) > 2)
    {
        preobr(path); //Преобразование для программы
        //printf("Для проверки разработчиком. Введённая строка преобразуется в %s\n", path); //для проверки разработчиком
    }
    if ((hFile = _findfirst(path, &inf_file)) == -1L) //Эта штука показывает когда путь к папке неверен, а не когда в папке нет файлов, потому что в любой папке есть два файла . и ..
    {
        printf(" Введённый путь написан неправильно!\n");
        getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
        return;
    }
    else //Получаем сколько файлов в директории, чтобы выделить нужное количество памяти под имена и размеры    
    {
        do
        {
            count++;
        } while (_findnext(hFile, &inf_file) == 0); //пока файлы в папке не кончатся
        _findclose(hFile); 
    }
    count -= 2;
    c_file = checknull((oneinf*)malloc(count * sizeof(oneinf))); //Сначала посчитал кол-во эл-тов в папке, чтобы не вызывать очень много раз realloc и проверку на != NULL
    count = 0;
    hFile = _findfirst(path, &inf_file);
    do
    {
        if (count > 1) //т.к. 0 и 1 были . и ..
        {
            c_file[count - 2].size = inf_file.size;
            strcpy(c_file[count - 2].name, inf_file.name);
        }
        count++;
    } while (_findnext(hFile, &inf_file) == 0); //пока файлы в папке не кончатся
    _findclose(hFile);
    count -= 2; //Так как в любой папке существует минимум два файла . и ..
    inf[ind - 1].countoffiles = count;
    if (count == 0)
    {
        printf(" По этому пути не найдено ни одного файла!\n"); //Ни одного существенного файла, но пользователь не догадается, что в папке существуют скрытые файлы
        getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
        return;
    }
    else
    {
        choiceyoursort(count, c_file);
    }
}

int choiceyoursort(int count, oneinf* c_file)
{
    int vibor[3] = { 0 };
    long double t[2] = { 0 };
    printf(" Вы можете выбрать параметр сортировки:\n\t(1) По возрастанию\n\t(2) По убыванию\n");
    while ((vibor[0] < 1) || (vibor[0] > 2))
    {
        scanf_s("%d", &vibor[0]);
        if ((vibor[0] < 1) || (vibor[0] > 2))
        {
            printf(" Данный параметр сортировки не предусмотрен программой. Введите число от 1 до 2.\n");
            while (getchar() != '\n');
        }
    }
    clearscreen(0, 3);
    printf(" Вы выбрали сортировку по ");
    if (vibor[0] == 1)
    {
        printf("возрастанию\n");
    }
    else
    {
        printf("убыванию\n");
    }
    printf("\n Вы можете выбрать одну из 7 сортировок:\n\t(1) Пузырьком\n\t(2) Выбором\n\t(3) Вставками\n\t(4) Слиянием\n\t(5) Хоара\n\t(6) Шелла\n\t(7) Подсчётом\n");
    while ((vibor[1] < 1) || (vibor[1] > 7))
    {
        scanf_s("%d", &vibor[1]);
        if ((vibor[1] < 1) || (vibor[1] > 7))
        {
            printf(" Данная сортировка не предусмотрена программой. Введите число от 1 до 7.\n");
            while (getchar() != '\n');
        }
    }
    clearscreen(0, 5);
    printf(" Выбранная сортировка: ");
    polzsorttype(vibor[1]);
    inf[ind - 1].typesort = vibor[1];
    inf[ind - 1].updown = vibor[0];
    printf("\n");
    switch (vibor[1])
    {
    case 1:
        t[0] = omp_get_wtime();
        bubblesort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 2:
        t[0] = omp_get_wtime();
        selectsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 3:
        t[0] = omp_get_wtime();
        insertsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 4:
        t[0] = omp_get_wtime();
        mergesort(0, count - 1, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 5:
        t[0] = omp_get_wtime();
        quicksort(c_file, count - 1);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 6:
        t[0] = omp_get_wtime();
        shellsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 7:
        t[0] = omp_get_wtime();
        countingsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    default:
        printf(" Ошибка, связанная с выбором в сортировки\n");
        break;
    }
    if (vibor[0] == 1)
    {
        vozrastanie(count, c_file);
    }
    inf[ind - 1].timer = t[1];
    printf("\n Всего файлов: %d\n\n", count);
    if (t[1] == 0)
        printf(" Сортировка произошла слишком быстро, потому что в данной директории очень мало файлов\n");
    else
    {
        printf(" Время сортировки: %.7lf (сек)\n\n", t[1]);
    }
    printf(" Что нужно сделать?\n\t(1)Вывести отсортированные файлы\n\t(2)Вернуться в меню\n");
    while ((vibor[2] < 1) || (vibor[2] > 2))
    {
        scanf_s("%d", &vibor[2]);
        if ((vibor[2] < 1) || (vibor[2] > 2))
        {
            printf(" Данный выбор не предусмотрен программой. Введите 1 или 2.\n");
            while (getchar() != '\n');
        }
    }
    if (vibor[2] == 1)
    {
        clearscreen(0,11);
        printf("%33cСписок файлов\n", ' ');
        printgran(1, 80);
        printf(" Номер |%18cФайл%38cРазмер\n", ' ', ' ');
        pipetoxy(60, 13);
        printgran(1, 80);
        for (int i = 0; i < count; i++)
        {
            printf("%6d | %-51s %13lu байт\n", i+1, c_file[i].name, c_file[i].size);
            pipetoxy(60, i + 15);
        }
        printgran(1, 80);
        system("pause");
    }
    free(c_file);
    system("cls");
}

/*Сортировки*/

//1. Пузырьком
void bubblesort(int count, oneinf* c_file)
{
    oneinf dop_file; //дополнительная переменная для перестановки

    for (int i = 0; i < count; i++)
    {
        for (int j = count - 1; j > i; j--)
        {
            if (c_file[j - 1].size < c_file[j].size)
            {
                dop_file = c_file[j - 1];
                c_file[j - 1] = c_file[j];
                c_file[j] = dop_file;
            }
        }
    }
}

//2. Выбором
void selectsort(int count, oneinf* c_file)
{
    oneinf dop_file; //дополнительная переменная для перестановки
    int i, j; //Переменные для цикла
    int k; //дополнительная переменная для перестановки
    for (i = 0; i < count; i++)
    {
        k = i;
        dop_file = c_file[i];
        for (j = i + 1; j < count; j++)
        {
            if (c_file[j].size > dop_file.size)
            {
                k = j;
                dop_file = c_file[j];
            }
        }
        c_file[k] = c_file[i];
        c_file[i] = dop_file;
    }
}

//3. Вставками
void insertsort(int count, oneinf* c_file)
{
    oneinf dop_file; //дополнительная переменная для перестановки
    int j;
    for (int i = 0; i < count; i++)
    {
        dop_file = c_file[i];
        for (j = i - 1; (j >= 0) && (c_file[j].size < dop_file.size); j--)
        {
            c_file[j + 1] = c_file[j];
        }
        c_file[j + 1] = dop_file;
    }
}

//4. Слиянием
void mergesort(int left, int right, oneinf* c_file)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergesort(left, mid, c_file);
    mergesort(mid + 1, right, c_file);
    merge(left, right, c_file);
}

void merge(int left, int right, oneinf* c_file)
{
    int mid = (left + right) / 2;
    int i = left; //счётчик
    int k = 0; //счётчик
    int j = mid + 1; //счётчик
    oneinf* dop_file; //дополнительная переменная для перестановки
    right += 1;
    dop_file = checknull(malloc((right) * sizeof(oneinf)));
    for (k = left; k < right; k++)
    {
        if ((i <= mid) && (j < right))
        {
            if (c_file[i].size >= c_file[j].size)
            {
                dop_file[k] = c_file[i];
                i++;
            }
            else
            {
                dop_file[k] = c_file[j];
                j++;
            }
        }
        else
        {
            if (i == mid + 1)
            {
                for (; j < right; j++, k++)
                {
                    dop_file[k] = c_file[j];
                }
            }
            else
            {
                for (; i < mid + 1; i++, k++)
                {
                    dop_file[k] = c_file[i];
                }
            }
        }
    }
    for (k = left; k < right; k++)
    {
        c_file[k] = dop_file[k];
    }
    free(dop_file);
}

//5. Хоара = быстрая сортировка
void quicksort(oneinf* c_file, int count)
{
    int i = 0; //счётчик
    int j = count; //счётчик
    int mid = count / 2;
    _fsize_t sizemidelem = c_file[mid].size;
    oneinf dop_file; //дополнительная переменная для перестановки и элемент из середины
    do
    {
        while (c_file[i].size > sizemidelem)
        {
            i++;
        }
        while (c_file[j].size < sizemidelem)
        {
            j--;
        }
        if (i <= j)
        {
            dop_file = c_file[i];
            c_file[i] = c_file[j];
            c_file[j] = dop_file;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quicksort(c_file, j);
    if (count > i)
        quicksort(c_file + i, count - i);
}

//6. Сортировка Шелла
int shellsort(int count, oneinf* c_file)
{
    oneinf dop_file; //дополнительная переменная для перестановки
    long inc, i, j, seq[40];
    int s;
    s = increment(seq, count); // вычисление последовательности приращений
    while (s >= 0) 
    {
        inc = seq[s--]; //сортировка вставками с инкрементами inc[]
        for (i = inc; i < count; i++) 
        {
            dop_file = c_file[i];
            for ((j = i - inc); ((j >= 0) && (c_file[j].size < dop_file.size)); (j -= inc))
            {
                c_file[j + inc] = c_file[j];
            }
            c_file[j + inc] = dop_file;
        }
    }
}

int increment(long inc[], int count)
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

//7. Сортировка подсчётом
int countingsort(int count, oneinf* c_file)
{
    int k = count - 1;
    oneinf dop_file; //дополнительная переменная для перестановки
    _fsize_t* countequalsizes;
    _fsize_t minsize, maxsize, size; //Минимальное и максимальное значение размера
    minsize = maxsize = c_file[0].size;
    for (int i = 0; i < count; i++)
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
    countequalsizes = checknull((_fsize_t*)malloc(size * sizeof(_fsize_t)));
    for (_fsize_t i = 0; i < size; i++)
    {
        countequalsizes[i] = 0;
    }
    for (int i = 0; i < count; i++)
    {
        countequalsizes[c_file[i].size - minsize]++;
    }
    for (_fsize_t i = 0; i < size; i++)
    {
        while (countequalsizes[i] > 0)
        {
            for (int j = k; j >= 0; j--)
            {
                if (c_file[j].size == minsize + i)
                {
                    dop_file = c_file[j];
                    c_file[j] = c_file[k];
                    c_file[k] = dop_file;
                    k--;
                    countequalsizes[i]--;
                }
            }
        }
    }
    free(countequalsizes);
}

//8. Сортировка в обратном порядке
void vozrastanie(int count, oneinf* c_file)
{
    int n = count / 2; //переменная, определяющая сколько элементов в 1/2 части всего массива
    struct finddata dop_file; //дополнительная переменная для перестановки
    for (int i = 0; i < n; i++)
    {
        dop_file = c_file[i];
        c_file[i] = c_file[count - i - 1];
        c_file[count - i - 1] = dop_file;
    }
}

/*Дополнительные функции*/

//Преобразовать путь для программы
char preobr(char* path)
{
    int size = 0; //размер пути
    size = strlen(path);
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

//Вывод информацию по всем сортировкам
void fullvivod()
{
    if (ind == 0)
    {
        printf("\n");
        printgran(1, 42);
        printf("| Программа не обработала ни одну папку! |\n");
        printgran(1, 42);
        system("pause");
        system("cls");
        return;
    }
    printf("\n");
    printgran(1, 79);
    printf("  № | Cортировка | Возрастание/убывание | Количество файлов | Время сортировки \n");
    printgran(1, 79);
    for (int i = 0; i < ind; i++)
    {
        printf("%3d%4c", i+1, ' ');
        polzsorttype(inf[i].typesort);
        printf("%8c", ' ');
        vozrandubyv(inf[i].updown);
        printf("%23d%14.7lf (сек)", inf[i].countoffiles, inf[i].timer);
        pipetoxy(4, 4+i);
        pipetoxy(17, 4+i);
        pipetoxy(40, 4+i);
        pipetoxy(60, 4+i);
    }
    printgran(1, 79);
    system("pause");
    system("cls");
}

//Рисует грани
void printgran(int type, int i)
{
    if (type == 1)
    {
        for (int j = 0; j < i; j++)
            printf("-");
    }
    printf("\n");
}

//Показывает выбранную сортировку
void polzsorttype(int i)
{
    switch (i)
    {
    case 1:
        printf("Пузырьком");
        break;
    case 2:
        //
        printf("Выбором  ");
        break;
    case 3:
        //
        printf("Вставками");
        break;
    case 4:
        //
        printf("Слиянием ");
        break;
    case 5:
        //
        printf("Хоара    ");
        break;
    case 6:
        //
        printf("Шелла    ");
        break;
    case 7:
        //
        printf("Подсчётом");
        break;
    default:
        printf("Ошибка   ");
        break;
    }
}

//https://stackoverrun.com/ru/q/1628655
void clearscreen(int x, int y)
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { x, y };
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

//Функция, размещающая | по заданымм координатам
void pipetoxy(int x, int y)
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(Console, pos);
    printf("|\n");
}

//Выводит информацию по возрастанию или убыванию в сортировке
void vozrandubyv(int a)
{
    if (a == 1)
    {
        printf("Возрастание");
    }
    else
    {
        printf("Убывание   ");
    }
}

/* //Дополнительная сортировка
int countingsort(int count, oneinf* c_file)
{
    int k;
    count++;
    oneinf* sortedarr = checknull(malloc((count) * sizeof(oneinf)));
    count--;
    for (int i = 0; i < count; i++)
        sortedarr[i].size = -1;
    for (int i = 0; i < count; i++)
    {
        k = 0;
        for (int j = 0; j < count; j++)
        {
            if (c_file[i].size < c_file[j].size)
            {
                k++;
            }
        }
        sortedarr[k] = c_file[i];
    }
    for (int i = 1; i < count; i++)
    {
        if (sortedarr[i].size == -1)
        {
            sortedarr[i].size = sortedarr[i - 1].size;
        }
    }
    k = 0;
    for (int i = 0; i < count; i++)
    {
        if (sortedarr[i].size == sortedarr[i + 1].size)
        {
            for (; k < count; k++)
            {
                if (sortedarr[i].size == c_file[k].size)
                {
                    sortedarr[i] = c_file[k];
                    k++;
                    break;
                }
            }
        }
        else
        {
            if ((i != 0) && (sortedarr[i].size == sortedarr[i - 1].size))
            {
                for (; k < count; k++)
                {
                    if (sortedarr[i].size == c_file[k].size)
                    {
                        sortedarr[i] = c_file[k];
                        k++;
                        break;
                    }
                }
            }
            k = 0;
        }
    }
    for (int i = 0; i < count; i++)
    {
        c_file[i] = sortedarr[i];
    }
    free(sortedarr);
}
*/