#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <string.h>
#include <windows.h>
#include <limits.h>
#include <omp.h>


#define N 8  //количество элементов в меню
struct File
{
    char* File_Name;//имя файла
    int File_long;//размер файла
};

void clean(void)//очищает поток ввода
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int setmin(struct File* arr, int size)//поиск минимума
{
    int tmp = INT_MAX, i;
    for (i = 0; i < size; i++)
    {
        if (arr[i].File_long < tmp)
            tmp = arr[i].File_long;
    }
    return tmp;
}

int setmax(struct File* arr, int size)//поиск максимума
{
    int tmp = INT_MIN, i;
    for (i = 0; i < size; i++)
    {
        if (arr[i].File_long > tmp)
            tmp = arr[i].File_long;
    }
    return tmp;
}

int increment(int inc[], int size) //вычисляем последовательность приращений (расстояний между елементами) для сортировки Шелла, используя формулу Сэджвика
{
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do {
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
    } while (3 * inc[s] < size);
    return (s > 0 ? --s : 0);
}

struct File* bubbleSort(struct File* arr, int size)//Сортировка пузырьком
{
    int i, j;
    struct File tmp;
    for (i = 0; i < size; i++)
    {            // i - номер прохода
        for (j = size - 1; j > i; j--)
        {     // внутренний цикл прохода
            if (arr[j - 1].File_long > arr[j].File_long)//сравнение длины, а меняем местами именно структуры
            {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return arr;
}

struct File* selectSort(struct File* arr, int size)//Сортировка выбором
{
    int i, j, k;
    struct File tmp;
    for (i = 0; i < size; i++) {   	// i - номер текущего шага
        k = i; tmp = arr[i];

        for (j = i + 1; j < size; j++)	// цикл выбора наименьшего элемента
            if (arr[j].File_long < tmp.File_long) {
                k = j;
                tmp = arr[j];	        // k - индекс наименьшего элемента
            }
        arr[k] = arr[i];
        arr[i] = tmp;   	// меняем местами элемент (с наименьшим размером файла) с элементом a[i]
    }
    return arr;
}

struct File* insertSortGuarded(struct File* arr, int size)//Сортировка вставками
{
    int i, j;
    struct File tmp_st;
    int tmp;
    int backup = setmin(arr, size);				// заменить на минимальный
    for (i = 1; i < size; i++) // отсортировать массив
    {
        tmp = arr[i].File_long;
        tmp_st = arr[i];
        for (j = i - 1; arr[j].File_long > tmp; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = tmp_st;
    }
    for (j = 1; j < size && arr[j].File_long < backup; j++)// 
        arr[j - 1] = arr[j];
    arr[j - 1].File_long = backup;// вставка элемента 
    return arr;
}

struct File* mergeSort(struct File* arr, int size)//сортировка слиянием без рекурсии
{
    int step = 1;  // шаг разбиения последовательности
    struct File* temp;
    temp = (struct File*)malloc(size * sizeof(struct File)); // дополнительный массив
    while (step < size)  // пока шаг меньше длины массива
    {
        int index = 0;    // индекс результирующего массива
        int l = 0;      // левая граница участка
        int m = l + step;  // середина участка
        int r = l + step * 2;  // правая граница участка
        do
        {
            m = m < size ? m : size;  // сортируемый участок не выходит за границы последовательности
            r = r < size ? r : size;
            int i1 = l, i2 = m; // индексы сравниваемых элементов
            for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
            {//
                if (arr[i1].File_long < arr[i2].File_long)
                {
                    temp[index++] = arr[i1++];
                } // заполняем участок результирующей последовательности
                else
                {
                    temp[index++] = arr[i2++];
                }
            }
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m)
                temp[index++] = arr[i1++]; // заносим оставшиеся элементы сортируемых участков
            while (i2 < r)
                temp[index++] = arr[i2++]; // в результирующий массив
            l += step * 2; // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        } while (l < size); // пока левая граница сортируемого участка - в пределах последоватльности
        for (int i = 0; i < size; i++) // переносим сформированный массив обратно в a
            arr[i] = temp[i];
        step *= 2; // увеличиваем в 2 раза шаг разбиения
    }
    free(temp);
    return (arr);
}

struct File* quickSort(struct File* arr, int left, int right)//Сортировка Хоара
{
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    struct File pivot = arr[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((arr[right].File_long >= pivot.File_long) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((arr[left].File_long <= pivot.File_long) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    arr[left] = pivot; // ставим разрешающий элемент на место
    pivot.File_long = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot.File_long) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(arr, left, pivot.File_long - 1);
    if (right > pivot.File_long)
        quickSort(arr, pivot.File_long + 1, right);
    return(arr);
}

struct File* shellSort(struct File* arr, int size)//сортировка шелла
{
    struct File temp;
    int inc, i, j, seq[40];
    int s;
    s = increment(seq, size);// вычисление последовательности приращений
    while (s >= 0)
    {
        inc = seq[s--];
        for (i = inc; i < size; i++)
        {
            temp = arr[i];
            for (j = i - inc; (j >= 0) && (arr[j].File_long > temp.File_long); j -= inc)
                arr[j + inc] = arr[j];
            arr[j + inc] = temp;
        }
    }
    return (arr);
}



struct File* countSort(struct File* arr, int size)//сортировка подсчетом
{     
    int min, max, i, j, pos = 0;
    struct File* sett;
    int* count;
    min = setmin(arr, size);//ищем минимальный размер файла
    max = setmax(arr, size);//ищем максимальный размер файла
    sett = (struct File*)malloc(sizeof(struct File) * (max - min + 1) * size);//массив для финальной сортировки массива структур arr
    count = (int*)malloc(sizeof(int) * (max - min + 1));//массив в котором хранится количество каждого числа из диапазона (max-min+1)

    for (i = 0; i < (max - min + 1); i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        sett[(count[arr[i].File_long - min]++) + size * (arr[i].File_long - min)] = arr[i];

    for (i = 0; i < (max - min + 1); i++)
        for (j = 0; j < count[i]; j++)
        {
            arr[pos] = sett[size * i + j];
            pos++;
        }
    free(count);
    free(sett);
    return arr;
    
}

void showmenu()
{
    char* menu[N] = { "Сортировка Хоара", "Сортировка пузырьком", "Сортировка вставками", "Сортировка слиянием", "Сортировка выбором", "Сортировка Шелла", "Сортировка подсчетом", "Выход" };//массив с названиями сортировок
    short int menu_number[N] = { 1, 2, 3, 4, 5, 6, 7, 0 };//массив с номерами каждого пункта меню
    int i, n = 8;
    for (i = 0; i < n; i++)
    {
        printf("%d", menu_number[i]);
        printf(". %s\n", menu[i]);
    }
    printf("Введите номер сортировки: ");
}


void main()

{
    int num, j = 0, k, flag=1;//num - номер пункта из меню
    struct _finddata_t c_file;
    struct File* Filearr;
    intptr_t hFile;
    char path[260];//путь, введенный пользователем
    int count = 0;//количество файлов в заданной папке
    int size, i = 0;//size - длина строки, введенной пользователем
    double t1, t2;//переменные для измерения времени работы функции
    char way[265] = { 0 };//итоговая строка
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (flag==1)
    {
        if (j == 0)//только в первый раз выводится это сообщение
            printf("введите путь до директории: ");
        else
            printf("Хотите сменить путь до дериктории? Если нет, введите 0: ");//выводится в дальнейшем
        j++;
        gets(path);
        
        size = strlen(path);
        if (size != 1)
        {
            for (i = 0; i < size; i++)//меняем в строке символ \ на /
            {
                if (path[i] == '\\')
                    path[i] = '/';
            }
            for (i = 0; i < size; i++)//переписываем строку, введенную пользователем, в итоговую строку
            {
                way[i] = path[i];
            }
            way[size] = '/';//эти 5 строчек - добавление к итоговой строке выражения "/*.*" и символа конца строки
            way[size + 1] = '*';
            way[size + 2] = '.';
            way[size + 3] = '*';
            way[size + 4] = '\0';
        }
        if ((hFile = _findfirst(way, &c_file)) == -1L)
            printf("Файлов не обнаружено! Попытайтесь ввести заново, сначала нажав Enter\n");
        else
        {
            showmenu();
            scanf_s("%d", &num);
            while ((num < 0) || (num > 7))//проверка на корректность введенного номера из меню
            {
                clean();
                printf("Введено некорректное значение, попытайтесь заново: ");
                scanf_s("%d", &num);
            }
            if (num == 0)
            {
                flag = 0;
                break;
            }
            count = 0;
            printf("Listing of .c files\n\n");
            printf("FILE SIZE\n", ' ');//
            printf("--------\n", ' ');//
            do {
                count++;
            } while (_findnext(hFile, &c_file) == 0);//считаем количество файлов
            _findclose(hFile);
            Filearr = (struct File*)malloc(sizeof(struct File) * count);//выделяем динамическую память
            hFile = _findfirst(way, &c_file);
            i = 0;
            do {//проходим по папке второй раз, перезаписывая информацию о файле в массив структур Filearr
                Filearr[i].File_long = c_file.size;
                Filearr[i].File_Name = (char*)malloc(sizeof(char) * 265);
                for (k = 0; k < 265; k++)
                    Filearr[i].File_Name[k] = c_file.name[k];//записываем имя файла в строку Filearr[i].File_Name посимвольно
                i++;
            } while (_findnext(hFile, &c_file) == 0);
            _findclose(hFile);

            switch (num)
            {
            case 1:
                printf("Сортировка Хоара\n");
                t1 = omp_get_wtime();
                Filearr = quickSort(Filearr, 0, count);
                t2 = omp_get_wtime();
                break;
            case 2:  
                printf("Сортировка пузырьком\n");
                t1 = omp_get_wtime();
                Filearr = bubbleSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 3:
                printf("Сортировка вставками\n");
                t1 = omp_get_wtime();
                Filearr = insertSortGuarded(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 4:
                printf("Сортировка слиянием\n");
                t1 = omp_get_wtime();
                Filearr = mergeSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 5:
                printf("Сортировка выбором\n");
                t1 = omp_get_wtime();
                Filearr = selectSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 6:
                printf("Сортировка Шелла\n");
                t1 = omp_get_wtime();
                Filearr = shellSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            case 7:
                printf("Сортировка подсчетом\n");
                t1 = omp_get_wtime();
                Filearr = countSort(Filearr, count);
                t2 = omp_get_wtime();
                break;
            }
            for(i=2; i<count; i++)//i=2, чтобы не печчатались файлы . и ..
                printf("%-12.12s %d байт\n", Filearr[i].File_Name, Filearr[i].File_long);
            printf("Время сортировки: %lf ", (t2 - t1));
            printf("секунд\n");
            for (i = 0; i < count; i++)
                free(Filearr[i].File_Name);
            free(Filearr);
        }
        clean();//снова чистим поток ввода, так как если цикл не завершится, необходимо будет считать путь до директории
    }
    system("pause");
}