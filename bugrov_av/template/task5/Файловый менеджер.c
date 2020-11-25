/*Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию / убыванию размера.

Входные данные :
Путь до директории, в которой необходимо отсортировать содержимое.
Метод сортировки.
Выходные данные :
Отсортированный список имен файлов с указанием размера.
Время сортировки.
Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.

Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает :
возможность ввода пути до заданного каталога;
возможность выбора метода сортировки;
возможность просмотра отсортированного списка файлов с указанием размера.
Cписок методов сортировки :
пузырьком
выбором
вставками
слиянием
Хоара
Шелла
подсчетом*/
/*#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  


// strcmp - */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  // из него функции
#include <time.h>  
#include <locale.h>
#include <omp.h>
#include <malloc.h>
#include <string.h>
void bubble();
void choice();
void insert();
void merge();// с этого начинается через три параметра
void arr_merger();
void Hoar();
void Shell();// два параметра, как и ниже
void counting();
int min_finder();//изменить тип, если массив будет из не целых элементов (да везде, во всех сортировках). Точно целый, пронесло
int increment();
void menu();
double worktime; //время работы сортировки (вывод через lf)
typedef struct fileinf
{
    char name[_MAX_PATH];
    int size;
} fileinf;
int count;
int main(void)
{
   // int size = 3010, a[3081];
   // int i;
    //setlocale(LC_ALL, "Russian");
    //menu();
   /* srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 3050;
    }
    Hoar(a, 0, size-1);//выбор проверки сортировки
    for (i=0; i<size; i++)
    printf("a[%d]=%d", i, a[i]);
    printf("worktime is %f\n", worktime);
    //printf("\n\n");*/
    system("pause");
}
void bubble(fileinf* a, int size) // работает
{
    int k;// для перемены местами элементов массива
    int i, j;// счётчики
    double t1, t2;//время
    int met;
    t1 = omp_get_wtime();//старт времени
    for (i = 0; i < size; i++)
    {
        met = 0;
        for (j = 0; j < size-i-1; j++) 
            if (a[j + 1].size < a[j].size)
            {
                met++;
                k = a[j + 1].size;
                a[j + 1].size = a[j].size;
                a[j].size = k;
            }
        if (met == 0)
            break;
    }
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
void choice(int a[], int size) // работает
{
    int k, min;// для перемены местами элементов массива
    int min_ind;// индекс минимального элемента
    int i, j;// счётчики
    double t1, t2;//время
    t1 = omp_get_wtime();
    for (i = 0; i < size; i++)
    { 
        min_ind = i; // присваиваем индексу минимума теперешний индекс
        k = a[min_ind]; //присваиваем дополнительной переменной значение i-того элемента
        for (j = i + 1; j < size; j++)	// цикл выбора наименьшего элемента
            if (a[j] < k) // сравниваем очередной элемент с min_ind-ым
            {
                min_ind = j; // меняем индекс наименьшего элемента
                k = a[min_ind]; // меняем значение к, чтобы более эффективно сравнивать
            }
        a[min_ind] = a[i];
        a[i] = k;
        //вместо свапа
    }
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
void insert(int a[], int size) // работает
{
    int k, min;// для перемены местами элементов массива
    int i, j;// счётчики
    double t1, t2;//время
    int tmp; // временная переменная для хранения нулевого элемента
    tmp = a[0];
    t1 = omp_get_wtime();
    a[0] = min_finder(a, size);
    for (i = 1; i < size; i++)
    {
        k = a[i];
        for (j = i - 1; a[j] > k; j--)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
    for (j = 1; j < size && a[j] < tmp; j++) // нахождение места нулевого элемента
        a[j - 1] = a[j];
    a[j - 1] = tmp; // вставка нулевого элемента на отсортированное место
    t2 = omp_get_wtime(); // финиш
    worktime = t2 - t1;// получение разности
}
int min_finder(int a[], int size) // работает
{
    int min;
    int i;
    min = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
void merge(int a[], int left, int right) // работает
{
    double t1, t2;//время
    int i; // начало первого пути
    int middle; // определяем середину последовательности
    int j; // начало второго пути
    int* tmp;
    t1 = omp_get_wtime();
    middle = (left + right) / 2;
    i = left;
    j = middle + 1; 
    tmp = (int*)malloc(right * sizeof(int)); // дополнительный массив
    if (left == right) return; // границы сомкнулись
    // рекурсивная сортировка с разделением на две половины
    merge(a, left, middle);
    merge(a, middle + 1, right);
    for (int step = 0; step < right - left + 1; step++) // для всех элементов дополнительного массива
    {   // запись в формируемую последовательность меньший из элементов двух путей или остаток первого пути если j > right
        if ((j > right) || ((i <= middle) && (a[i] < a[j])))
        {
            tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }
    }
    for (int step = 0; step < right - left + 1; step++)
        a[left + step] = tmp[step];
    free(tmp);
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
void Hoar(int a[], int left, int right) // работает
{
    double t1, t2;//время
    int i = left, j = right;
    int tmp, x;
    t1 = omp_get_wtime();
    x = a[(left + right) / 2];
    // алгоритм основан на разделении массива на две части, одна из которых не превышает вторую
    // элементы одной части не превосходят элементов другой части. 
    // для этого создаётся опорный элемент, лучше случайный, но и одинаковый пойдёт
    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j) //перестановка
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    // рекурсивные вызовы сортировки с разделом массива
    if (i < right)
        Hoar(a, i, right);
    if (left < j)
        Hoar(a, left, j);
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
int increment(int inc[], int size) // работает
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
    return s > 0 ? --s : 0;// if (s>0) return --s; else return 0;
}
void Shell(int a[], int size) // работает
{
    int k;// для перемены местами элементов массива
    int i, j;// счётчики
    double t1, t2;//время
    int tmp;
    int seq[40], inc;
    int s;
    t1 = omp_get_wtime();
    // вычисление последовательности приращений
    s = increment(seq, size);
    while (s >= 0) {
        // сортировка вставками с инкрементами inc[] 
        inc = seq[s--];
        for (i = inc; i < size; i++) {
             tmp = a[i];
            for (j = i - inc; (j >= 0) && (a[j] > tmp); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = tmp;
        }
    }
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
void counting(int a[], int size) // работает
{
    int i, size_of_count;
    int* count;
    int max = a[0], min = a[0], k=0;
    double t1, t2;//время
    t1 = omp_get_wtime();
    for (i = 0; i < size; i++)
        if (max < a[i])
            max = a[i];
        else
            if (min > a[i])
                min = a[i];
    size_of_count = max - min + 1;
    count = (int*)malloc(sizeof(int) * size_of_count);
    for (i = 0; i < size_of_count; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
        count[a[i] - min]++;
    for (i = 0; i < size_of_count; i++)
        while (count[i]--)
            a[k++] = min + i;
    free(count);
    t2 = omp_get_wtime();// финиш
    worktime = t2 - t1;// получение разности
}
/*void menu()
{
    fileinf* list;
    setlocale(LC_ALL, "Russian");
    int a, flag = 0;
    char answer;//ответ на вопрос о выходе из программы
    printf("");
    list = manager();
    //count = list / (sizeof(fileinf);
    do {
        printf("Выберите своего бойца - метод сортировки:\n");
        printf("1) Cортировка пузырьком\n2) Сортировка выбором\n3) Сортировка вставками\n4) Сортировка слиянием\n5) Сортировка Хоара\n6) Сортировка Шеллa\n7) Сортировка подсчётом\n");
        printf("Или выберите 0 для выхода\n");
        do
            a = getchar();
        while (a != EOF && a != '\n');
        a -= '0';
        if (a > 0 && a < 8)
            switch (a)
            {
            case 1:
                bubble(list, count);
                break;
            case 2:
                choice(list, count);
                break;
            case 3:
                insert(list, count);
                break;
            case 4:
                merge(list, 0, count-1);
                break;
            case 5:
                Hoar(list, 0, count - 1);
                break;
            case 6:
                Shell(list, count);
                break;
            case 7:
                counting(list, count);
                break;
            }
        else
            if (!a)
            {
                printf("\n");
                scanf("%c", &answer);
                if (answer == 'y')
                    printf("\n");
                else
                {
                    printf("\n");
                    flag = 1;
                }
            }
    } while (flag);   
}*/
/*fileinf* manager()// занимается нахождением файлов с заданной пользователем маской в каталоге, заданном пользователем
{
    struct _finddata_t c_file;//структура, состоящая из набора элементов (объединение разнотипных полей)
    intptr_t hFile;//
    char path[255];
    //char temp1, temp2;
    int tmp_count=0;
    int i, j;
    fileinf* list;
    // Find first file in directory c:\temp
    // _findfirst, _findnext, _findclose их стоит использовать
    printf("Введите путь до каталога, в котором нужно отыскать все файлы");
    fgets(path, 200, stdin);
    for (i = 0; i < 200 && path[i] != '\0'; i++)
    {
        if (path[i] == '/' && path[i + 1] != '/')
            path[i] = '\\';
    }
    path[i] = '*'; i++; path[i] = '\0';
    if ((hFile = _findfirst(path, &c_file)) == -1L)// Находит первый файл по имени path, кладёт информацию в си файл, елсли не найден файл, то hFile даёт значение - 1 в типе лонг
        printf("No files in current directory!\n");
    else
    {     /*(printf("Listing of files\n\n");
     printf("FILE         DATE %24c   SIZE\n", ' ');
     printf("----         ---- %24c   ----\n", ' ');*/
       /* do {
            /* char buffer[30];
             ctime_s(buffer, _countof(buffer), &c_file.time_write);// тайм-райт - время последнего изменения файла, ctime - извлечение времени файла;
             if (count <= 20)
                 printf("%-12.12s %.24s  %10ld\n", c_file.name, buffer, c_file.size);// c_file.size - узнать размер файла, c_file.name - узнать имя файла.*/
           /* count++;
        } while (_findnext(hFile, &c_file) == 0);// вызов функции
        _findclose(hFile);// закрытие поиска
        list = (fileinf*)malloc(sizeof(fileinf) * count);
        tmp_count = 0;
        do
        {
            strcpy(list[tmp_count].name, c_file.name);
            list[tmp_count++].size = c_file.size;
        } while (_findnext(hFile, &c_file) == 0);
        return list;
    }
}*/