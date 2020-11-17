/*Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию/убыванию размера.
Входные данные:
    + Путь до директории, в которой необходимо отсортировать содержимое.
    + Метод сортировки.

Выходные данные:
    + Отсортированный список имен файлов с указанием размера.
    + Время сортировки.

Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.
Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает:
    + возможность ввода пути до заданного каталога;
    + возможность выбора метода сортировки;
    + возможность просмотра отсортированного списка файлов с указанием размера.

Cписок методов сортировки: пузырьком, выбором, вставками, слиянием, Хоара, Шелла, подсчетом
*/

#define _CRT_SECURE_NO_WARNINGS

//Подключение библиотек
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //Отвечает за внешний ввод и вывод input output
#include <omp.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //Используем здесь для поддержки русского языка (если конкретнее, то для того, чтобы пользователь мог вводить папки с русскими буквами)

//Стуктура, содержащая полученную информацию
typedef struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
} structinf;

//Объявление функций
int menu();
int getinform(); //Осуществлет получение информации по файлам
char preobr(char* path); //Преобразовывает путь, введённый пользователем, в путь, который нужен программе
void bubblesort(int count, structinf* c_file); //Сортировка пузырьком
void selectsort(int count, structinf* c_file); //Сортировка выбором
void insertsort(int count, structinf* c_file); //Сортировка вставками
void mergesort(int left, int right, structinf* c_file); //Сортировка слиянием
void merge(int lefte, int right, structinf* c_file);
void quicksort(structinf* c_file, int count); //Хоара=быстрая
int shellsort(long size, structinf* c_file);
int countingsort(int n, int k, structinf* c_file);
int choiceyoursort(int count, structinf* c_file);
void vozrastanie(int count, structinf* c_file); //Если пользователь выбрал сортировку по убыванию, то эта функция отзеркалит массив, который уже отсортирован по убыванию
void instruction(); // Инструкция к программе
void fullvivod(); //Вывод информацию по всем сортировкам
void printgran(int type, int i); //Рисует грани
void polzsort(int i); //Выводит на экран выбранную пользователем сортировку (для таблицы и работы во время кода)

//Объявление глобальных переменных
char lastpath[FILENAME_MAX]; //Хранит значение пути для выбора этого же пути на новой сортировке

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
    printgran(1, 73);
    printf("| Мы стараемся над улучшением нашей программы, следите за обновлениями! |\n");
    printgran(1, 73);
    system("pause");
}

int menu()
{
    printgran(1, 61);
    printf("  Сейчас Вы находитесь в меню. Выберите, что нужно сделать:\n\t(1) Отсортировать файлы в новой папке\n\t(2) Вывести всю информацию, полученную из сортировок\n\t(3) Получить инструкцию по работе с программой\n\t(0) Выйти из программы\n");
    printgran(1, 61);
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 3))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 0) || (vibor > 3))
        {
            printf("Данная функция не предусмотрена программой. Введите число от 0 до 3.\n");
        }
    }
    c = getc(stdin); //Очистка потока ввода
    switch (vibor)
    {
    case 1:
        getinform();
        break;
    case 2:
        fullvivod();
        break;
    case 3:
        instruction();
        break;
    case 0:
        return 0;
    default:
        printf("Ошибка, связанная с выбором в меню");
        break;
    }
}

int getinform()
{
    structinf* c_file; //в этом массиве сохраняем имя и размер при обработке файла
    struct _finddata_t inf_file; //в эту структуру сохраняется вся информация по найденному файлу
    intptr_t hFile;
    char path[FILENAME_MAX]; //путь, который ввёл пользователь
    int count = 0; //подсчёт количества файлов

    system("cls");
    printf("\n Введите путь к папке с файлами:\n");
    fgets(path, FILENAME_MAX, stdin); //scanf_s в данном случае выдаёт множество ошибок
    printf("\n Вы ввели путь: %s\n", path);
    preobr(path); //Преобразование для программы
    //printf("Для проверки разработчиком. Введённая строка преобразуется в %s\n", path); //для проверки разработчиком
    if ((hFile = _findfirst(path, &inf_file)) == -1L) //Эта штука показывает когда путь к папке неверен, а не когда в папке нет файлов, потому что в любой папке есть два файла . и ..
    {
        printf(" Введённый путь написан неправильно!\n");
        getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
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
    c_file = (structinf*)malloc(count * sizeof(structinf));
    if (c_file == NULL)
    {
        printf(" Слишком много файлов в директории! Невозможно выделить нужное количество памяти для хранения информации.\n");
        getinform();
    }
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
    strcpy(lastpath, path);
    count -= 2; //Так как в любой папке существует минимум два файла . и ..
    if (count == 0)
    {
        printf(" По этому пути не найдено ни одного файла!\n"); //Ни одного существенного файла, но пользователь не догадается, что в папке существуют скрытые файлы
        getinform(); //Функция нужна для получения информации по файлам, поэтому нужно добиваться верных данных до тех пор, пока не введут верные данные
    }
    else
    {
        choiceyoursort(count, c_file);
    }
}

int choiceyoursort(int count, structinf* c_file)
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
        }
    }
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
        }
    }
    printf(" Выбранная сортировка: \"");
    polzsort(vibor[1]);
    printf("\"\n");
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
        quicksort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 6:
        t[0] = omp_get_wtime();
        //
        t[1] = omp_get_wtime() - t[0];
        break;
    case 7:
        t[0] = omp_get_wtime();
        //
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
    printf("\n Всего файлов: %d\n\n", count);
    if (t[1] == 0)
        printf(" Сортировка произошла слишком быстро, потому что в данной директории очень мало файлов\n");
    else
    {
        printf(" Время сортировки: %.7lf (сек)\n\n", t[1]);
    }
    printf(" Что нужно сделать?\n\t(1)Вывести отсортированные файлы\n\t(2)Вернуться в меню\n");
    while ((vibor[2] < 1) || (vibor[2] > 7))
    {
        scanf_s("%d", &vibor[2]);
        if ((vibor[2] < 1) || (vibor[2] > 7))
        {
            printf(" Данный выбор не предусмотрен программой. Введите 1 или 2.\n");
        }
    }
    if (vibor[2] == 1)
    {
        printgran(1, 60);
        printf("%23cСписок файлов\n", ' ');
        printgran(1, 60);
        printf("Файл%50cРазмер\n", ' ');
        printgran(1, 60);
        for (int i = 0; i < count; i++) //. и .. занимают 0 и 1 индексы, поэтому начинаем со второго индекса
        {
            printf("%-40s %14lu байт\n", c_file[i].name, c_file[i].size);
        }
    }
    printf("В таблицу будет добавлен разделитель между столбцами\n");//Не забыть
    system("pause");
    free(c_file);
    system("cls");
}

/*Сортировки*/

//1. Пузырьком
void bubblesort(int count, structinf* c_file)
{
    structinf dop_file; //дополнительная переменная для перестановки

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
void selectsort(int count, structinf* c_file)
{
    structinf dop_file; //дополнительная переменная для перестановки
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
void insertsort(int count, structinf* c_file)
{
    structinf dop_file; //дополнительная переменная для перестановки
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
void mergesort(int left, int right, structinf* c_file)
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

void merge(int left, int right, structinf* c_file)
{
    //якобы работающий код
    int mid = (left + right) / 2;
    int i = 0, k = 0; //счётчики
    int j = mid + 1; //счётчик
    structinf* dop_file; //дополнительная переменная для перестановки
    dop_file = (structinf*)malloc(right*sizeof(structinf));
    for (k = left; k <= right; k++)
    {
        if ((i < mid) && (j < right))
        {
            if (c_file[i].size <= c_file[j].size)
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
            if (i == mid)
            {
                for (; j < right; j++, k++)
                {
                    dop_file[k] = c_file[j];
                }
            }
            else
            {
                for (; i < mid; i++, k++)
                {
                    dop_file[k] = c_file[i];
                }
            }
        }
    }
    for (k = left; k <= right; k++)
    {
        c_file[k] = dop_file[k];
    }
    free(dop_file);
}

//5. Хоара = быстрая сортировка
void quicksort(structinf* c_file, int count)
{
    int i = 0, j = count - 1;
    structinf dop_file, midelem; //дополнительная переменная для перестановки и элемент из середины
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
        quicksort(c_file, j);
    if (count > i)
        quicksort(c_file + i, count - i);
}

//6. Сортировка Шелла
int increment(long inc[], long size, structinf* c_file)
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

shellsort(long size, structinf* c_file)
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
countingsort(int n, int k, structinf* c_file)
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
void vozrastanie(int count, structinf* c_file)
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

//Преобразовать путь для программы
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

// Инструкция к программе
void instruction() 
{
    printf("Скоро в программе.\n");
}

//Вывод информацию по всем сортировкам
void fullvivod()
{
    printf("Скоро в программе.\n");
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
void polzsort(int i)
{
    switch (i)
    {
    case 1:
        printf("Пузырьком");
        break;
    case 2:
        //
        printf("Выбором");
        break;
    case 3:
        //
        printf("Вставками");
        break;
    case 4:
        //
        printf("Слиянием");
        break;
    case 5:
        //
        printf("Хоара");
        break;
    case 6:
        //
        printf("Шелла");
        break;
    case 7:
        //
        printf("Подсчётом");
        break;
    default:
        printf("Такой сортировки нет\n");
        break;
    }
}
