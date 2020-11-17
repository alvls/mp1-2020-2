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

Cписок методов сортировки: пузырьком, выбором, вставками, слиянием, Хоара, Шелла, подсчетом
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //Отвечает за внешний ввод и вывод input output
#include <time.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //Используем здесь для поддержки русского языка (если конкретнее, то для того, чтобы пользователь мог вводить папки с русскими буквами)


#define SIZEOFARR 10000
#define SIZEOFPATH 256

//Объявление функций
void menu();
int getinform(); //Осуществлет получение информации по файлам
char preobr(char* path); //Преобразовывает путь, введённый пользователем, в путь, который нужен программе
void bubblesort(int count); //Сортировка пузырьком
void selectsort(int count); //Сортировка выбором
void insertsort(int count); //Сортировка вставками
void mergesort(int left, int right); //Сортировка слиянием
void merge(int lefte, int right); 
void quicksort(int count); //Хоара=быстрая
int shellsort(long size);
int countingsort(int n, int k);
int choiceyoursort(int count);

void vozrastanie(int count); //Если пользователь выбрал сортировку по убыванию, то эта функция отзеркалит массив, который уже отсортирован по убыванию

//Объявление структур
struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
};

struct timer
{
    long long start; //время начала сортировки
    double work; //время сортировки 
};
        
//Объявление глобальных переменных
struct  finddata c_file[SIZEOFARR]; //в этом массиве сохраняем имя и размер при обработке файла
char realpath[SIZEOFPATH]; //Хранит значение пути для выбора этого же пути на новой сортировке
//struct  finddata dop_file[SIZEOFARR]; //дополнительная память

void main()
{
    setlocale(LC_ALL, "Russian"); //Поддержка русского языка
    SetConsoleCP(1251); //Поддержка русского языка (чтобы путь можно было считать нормально)
    SetConsoleOutputCP(1251); //Поддержка русского языка (чтобы путь можно было считать нормально)
    menu();
    system("pause");
}//Реализовать вывод всех данных в виде таблицы

void menu()
{
    printf("Приветствую! Я - программа, созданная для сортировки файлов. Мой функционал:\n(1) Считать информацию\n(2) Получить инструкцию по работе с программой\n(3) Вывести всю информацию, полученную из сортировок\n(0) Выйти из программы\n");
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 3))
    {
        scanf_s("%d",&vibor);
        if ((vibor < 0) || (vibor > 3))
        {
            printf("Данная функция не предусмотрена программой. Введите число от 0 до 3.\n");
        }
    }
    c = getc(stdin);
    switch (vibor)
    {
    case 0:
        //Выйти из программы
        break;
    case 1:
        getinform();
        break;
    case 2:
        //Получить инструкцию по работе с программой
        break;
    case 3:
        //Вывести всю информацию, полученную из сортировок
        break;
    default:
        printf("Ошибка, связанная с выбором в меню");
        break;
    }
}

int getinform()
{
    
    struct _finddata_t inf_file; //в эту структуру сохраняется вся информация по найденному файлу
    intptr_t hFile;
    char path[SIZEOFPATH]; //путь, который ввёл пользователь
    int count = 0; //подсчёт количества файлов

    printf("\nВведите путь к папке с файлами:\n");
    fgets(path, SIZEOFPATH, stdin); //scanf_s в данном случае выдаёт множество ошибок
    preobr(path); //Преобразование для программы
    //printf("Для проверки разработчиком. Введённая строка преобразуется в %s\n", path); //для проверки разработчиком

    if ((hFile = _findfirst(path, &inf_file)) == -1L) //Эта штука показывает когда путь к папке неверен, а не когда в папке нет файлов, потому что в любой папке есть два файла . и ..
    {
        printf("Введённый путь написан неправильно!\n");
        getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
    }
    else //Получаем имена, записываем их в массив и сортируем массив файлов по размерам    
    {
        do {
            if (count > 1) //т.к. 0 и 1 были . и ..
            {
                c_file[count-2].size = inf_file.size;
                strcpy(c_file[count-2].name, inf_file.name);
            }
            count++;
        } while ((_findnext(hFile, &inf_file) == 0)&&(count<SIZEOFARR)); //пока файлы в папке не кончатся
        _findclose(hFile);
        strcpy(realpath, path);
        count -= 2; //Так как в любой папке существует минимум два файла . и ..
        if (count == 0)
        {
            printf("По этому пути не найдено ни одного файла!\n"); //Ни одного существенного файла, но пользователь не догадается, что в папке существуют скрытые файлы
            getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
        }
        else
        {
            choiceyoursort(count);
        }
    }
}

int choiceyoursort(int count)
{
    int vibor1 = 0, vibor2=0;
    int rezhim = 0;
    struct timer t;
    printf("Вы можете выбрать параметр сортировки:\n(1) По возрастанию\n(2) По убыванию\n");
    while ((vibor1 < 1) || (vibor1 > 2))
    {
        scanf_s("%d", &vibor1);
        if ((vibor1 < 1) || (vibor1 > 2))
        {
            printf("Данный параметр сортировки не предусмотрен программой. Введите число от 1 до 2.\n");
        }
    }
    printf("Вы выбрали сортировку по ");
    if (vibor1 == 1)
    {
        printf("возрастанию\n");
    }
    else
    {
        printf("убыванию\n");
    }
    printf("Вы можете выбрать одну из 7 сортировок:\n(1) Пузырьком\n(2) Выбором\n(3) Вставками\n(4) Слиянием\n(5) Хоара\n(6) Шелла\n(7) Подсчётом\n");
    while ((vibor2 < 1) || (vibor2 > 7))
    {
        scanf_s("%d", &vibor2);
        if ((vibor2 < 1) || (vibor2 > 7))
        {
            printf("Данная сортировка не предусмотрена программой. Введите число от 1 до 7.\n");
        }
    }
    switch (vibor2)
    {
    case 1:
        t.start = clock(); //Начало работы сортировки
        bubblesort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 2:
        t.start = clock(); //Начало работы сортировки
        selectsort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 3:
        t.start = clock(); //Начало работы сортировки
        insertsort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 4:
        t.start = clock(); //Начало работы сортировки
        mergesort(0, count-1);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 5:
        t.start = clock(); //Начало работы сортировки
        quicksort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 6:
        t.start = clock(); //Начало работы сортировки
        //
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    case 7:
        t.start = clock(); //Начало работы сортировки
        //
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //Время работы сортировки
        break;
    }
    if (vibor1 == 1)
    {
        vozrastanie(count);
    }
    system("cls");
    printf("\n%23cСписок файлов\n\nФайл%50cРазмер\n----%50c------\n", ' ', ' ', ' ');
    for (int i = 0; i < count; i++) //. и .. занимают 0 и 1 индексы, поэтому начинаем со второго индекса
    {
        printf("%-40s %14lu байт\n", c_file[i].name, c_file[i].size);
    }
    printf("\n\tВсего файлов: %d\n\t", count);
    if (t.work == 0)
        printf("Сортировка произошла слишком быстро, потому что в данной директории очень мало файлов\n");
    else
    {
        printf("Время сортировки: %f (сек)\n\n", t.work);
    }
}

/*Сортировки*/

//1. Пузырьком
void bubblesort(int count)
{
    struct finddata dop_file; //дополнительная переменная для перестановки

    for (int i = 0; i < count; i++) //. и .. занимают 0 и 1 индексы, поэтому начинаем со второго индекса
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
void selectsort(int count)
{
    struct finddata dop_file; //дополнительная переменная для перестановки
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
void insertsort(int count)
{
    struct finddata dop_file; //дополнительная переменная для перестановки
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
void mergesort(int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, right);
}

void merge(int left, int right)
{
    //якобы работающий код
    
}

//5. Хоара = быстрая сортировка
void quicksort(int count)
{
    int i = 0, j = count - 1;
    struct finddata dop_file, midelem; //дополнительная переменная для перестановки и элемент из середины
    midelem = c_file[count >> 1];
    do
    {
        while (c_file[i].size < midelem.size)
        {
            i++;
        }
        while (c_file[j].size > midelem.size)
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
        quicksort(j);
    if (count > i) 
        quicksort(c_file + i, count - i);
}

//6. Сортировка Шелла
int increment(long inc[], long size) 
{
    /*
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
    */
}

//template<class T>
shellsort(long size) 
{
    /*
    long inc, i, j, seq[40];
    int s;

    // вычисление последовательности приращений
    s = increment(seq, size);
    while (s >= 0) {
        // сортировка вставками с инкрементами inc[] 
        inc = seq[s--];

        for (i = inc; i < size; i++) {
            T temp = a[i];
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = temp;
        }
    }
    */
}

//7. Сортировка подсчётом
countingsort(int n, int k) 
{
    /* 
    int c[k + 1] = { 0 };
    for (int i = 0; i < n; i++) 
    {
        c[array[i]] = c[array[i]] + 1;
    }

    int b = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < c[i]; j++) 
        {
            array[b] = i;
            b = b + 1;
        }
    }
    */
}

//8. Сортировка в обратном порядке
void vozrastanie(int count)
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

//9. Преобразование 
char preobr(char* path)
{
    int size = 0; //размер пути
    size = strlen(path);
    if (size < 3)
    {
        printf("Слишком короткий путь!\n");
        getinform(); //потому что любой путь должен начинаться минимум с такого набора символов c:'\0'
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
