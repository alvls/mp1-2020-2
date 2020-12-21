#include <stdio.h>    
#include <math.h> 
#include <stdlib.h>
#include <time.h>  
#include <limits.h>
#include <locale.h>
#define N 6  //количество пунктов в меню
int col;//количество элементов ряда (выводится на экран)
int n;//число элементов в ряде, используется в функции sum 
long double argument(long double x)//так как тригонометрические функции периодические, то при помощи этой функции получаем x в интервале от -2Пи до 2 Пи (значения тригонометрических функций при этом не меняются). Без этой функции при х>32 пограмма перестает работать, т.к. идет переполнение переменной типа long double
{
    long double two_pi = 6.2831853071795865;//2 Пи
    int flag;
    if (x > 0)
        flag = 0;
    else
        if (x < 0)
        {
            flag = 1;
            x = fabs(x);//для уменьшения числа проверок
        }
    while (x > two_pi)
    {
        x = x - two_pi;
    }
    if (flag == 1)//если x отрицательный
        x = (-1) * x;
    return(x);
}
long double* exp_elem(int size, long double x, long double pogr)//Считает слагаемые ряда Тейлора для экспоненты. size - число элементов, pogr - точность вычислений, задается пользователем
{
    int i, k = 0;//k - нужен для вычесления элементов ряда (подробности ниже)
    long double* elem;
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 для добавления в конце массива элементо со значением 0 (как символ конца строки) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (elem[i - 1] * x) / (k + 1);//каждый следующий элемент вычисляется путем домножения предыдущего элемента на х/(к+1). k+1 заменяет вычисление факториала для каждого слагаемого
        k++;//
        if (pogr > fabs(elem[i]))//оценка поргешности
            break;
    }
    elem[i + 1] = 0;//0 как символ конца строки
    n = i;//size
    return elem;//возвращает массив подсчитанных элементов из ряда Тейлора
    free(elem);
}

long double* sin_elem(int size, long double x, long double pogr)//Считает слагаемые ряда Тейлора для синуса. size - число элементов, pogr - точность вычислений, задается пользователем
{
    int i, k = 1;//k - нужен для вычесления элементов ряда (подробности ниже)
    long double* elem;
    x = argument(x);
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 для добавления в конце массива элементо со значением 0 (как символ конца строки) 
    elem[0] = x;
    for (i = 1; i < size; i++)
    {
        elem[i] = (-1) * (elem[i - 1] * x * x) / ((k + 1) * (k + 2));//каждый следующий элемент вычисляется путем домножения предыдущего элемента на х^2/((к+1)*(k+2)). (к+1)*(k+2) заменяет вычисление факториала для каждого слагаемого
        k = k + 2;
        if (pogr > fabs(elem[i]))//оценка поргешности
            break;
    }
    elem[i + 1] = 0;//0 как символ конца строки
    n = i;
    return elem;//возвращает массив подсчитанных элементов из ряда Тейлора
    free(elem);
}

long double* cos_elem(int size, long double x, long double pogr)//Считает слагаемые ряда Тейлора для косинуса. size - число элементов, pogr - точность вычислений, задается пользователем
{
    int i, k = 0;//k - нужен для вычесления элементов ряда (подробности ниже)
    long double* elem;
    x = argument(x);
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 для добавления в конце массива элементо со значением 0 (как символ конца строки) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (-1) * (elem[i - 1] * x * x) / ((k + 1) * (k + 2));//каждый следующий элемент вычисляется путем домножения предыдущего элемента на х^2/((к+1)*(k+2)). (к+1)*(k+2) заменяет вычисление факториала для каждого слагаемого
        k = k + 2;
        if (pogr > fabs(elem[i]))//оценка поргешности
            break;
    }
    elem[i + 1] = 0;//0 как символ конца строки
    n = i;
    return elem;//возвращает массив подсчитанных элементов из ряда Тейлора
    free(elem);
}

long double* sqrt_elem(int size, long double x, long double pogr)//Считает слагаемые ряда Тейлора для косинуса. size - число элементов, pogr - точность вычислений, задается пользователем
{
    int i, k = 0;//k - нужен для вычесления элементов ряда (подробности ниже)
    long double* elem;
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 для добавления в конце массива элементо со значением 0 (как символ конца строки) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (elem[i - 1] * x* (0.5 - k)) / (k + 1);//каждый следующий элемент вычисляется путем домножения предыдущего элемента на х*(0.5 - k)/(к+1). (к+1) заменяет вычисление факториала для каждого слагаемого
        k++;
        if (pogr > fabs(elem[i]))//оценка поргешности
            break;
    }
    elem[i + 1] = 0;//0 как символ конца строки
    n = i;
    return elem;//возвращает массив подсчитанных элементов из ряда Тейлора
    free(elem);
}

long double sum(long double* (*fun)(int, long double, long double), long double x, long double pogr)//отдельная функция, суммирующая элементы ряда
{
    int i = 0;
    long double sum = 0;//значение функции
    long double* elem;//для хранения слагаемых формулы Тейлора
    elem = (long double*)malloc(sizeof(long double) * n);//n - число элементов в ряде (задается пользователем) 
    elem = fun(n, x, pogr);//указатель на одну из трех функций: exp_elem, sin_elem, cos_elem
    while ((elem[i] != 0) && (i < n))//пока не дойдет до символа 0 (вычислены все элементы для заданной точности) или пока не дойдет до последнего вычисленного элемента
    {
        sum = sum + elem[i];//сама операция суммирования
        i++;
    }
    col = i;//количество элементов ряда
    return sum;
}

long double tg1(long double* (*fun)(int, long double, long double), long double x, long double pogr)//здесь указатель на функцию не требуется, но для упрощения реализации 2-го режима он используется в данном случае
{
    int i = 2, size=n;//size - число элементов ряда
    long double s = x, s0 = tan(x);
    x = argument(x);
    while ((pogr < fabs(s - s0)) && (i < size))//первая проверка - оценка поргешности
    {
        n = i;//
        s = (sum(sin_elem, x, 0) / sum(cos_elem, x, 0));//вывести закономерность для элементов тангенса (как это было с синусом, косинусом, и экспонентой) нельзя. Поэтому используется частное приближенных значений синуса и косинуса
        i++;
    }
    col = i;//количество элементов ряда
    return s;
}

long double ctg1(long double* (*fun)(int, long double, long double), long double x, long double pogr)//здесь указатель на функцию не требуется, но для упрощения реализации 2-го режима он используется в данном случае
{
    int i = 2, size = n;//size - число элементов ряда
    long double s = 1/x, s0 = cos(x)/sin(x);
    x = argument(x);
    while ((pogr < fabs(s - s0)) && (i < size))//первая проверка - оценка поргешности
    {
        n = i;//
        s = (sum(cos_elem, x, 0) / sum(sin_elem, x, 0));//используется частное приближенных значений синуса и косинуса
        i++;
    }
    col = i;//количество элементов ряда
    return s;
}

void clean(void)//очищает поток ввода
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void showmenu()
{
    char* menu[N] = { "Экспонента в степени х", "Синус", "Косинус", "Тангенс", "Квадратный корень из 1+х", "Котангенс" };//массив с названиями функций
    short int menu_number[N] = { 1, 2, 3, 4, 5, 6 };//массив с номерами каждого пункта меню
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d", menu_number[i]);
        printf(". %s\n", menu[i]);
    }
    printf("Введите номер функции, приближенное значение которой хотите получить: ");
}

int setdlina(long double t)//возвращает длину вещественного числа(с 7 знаками после запятой)
{
    int B = t, i=0;
    while (B > 0)
    {
        B = B / 10;
        i++;
    }
    return(i + 8);//т.к. еще разделитель целой и дробной частей (,)
}
void probel_print(int t)//печатает нужное число пробелов для выравнивания, t-число пробелов
{
    for (int i = 0; i < t; i++)//печатаем пробелы
        printf(" ");
}
void main()
{
    int number, num_function, size, count, i, flag=0;//number - номер режима, num_function - номер функции из меню, size - число элементов ряда (задается пользователем), count - используется при выравнивании строк во 2 режиме; flag - показывает, считалось ли x с клавиатуры
    long double x = 0, pogr, etal, raznica, res;//pogr - точность вычислений, задается пользователем; etal - значение из эталонной функции; res - значение из собственной функции; raznica - модуль разницы между эталонным значением и результатом работы собственной функции
    long double (*function_elem)(long double, long double, int)= NULL;//указатель на одну из функций: exp_elem, sin_elem, cos_elem (2 режим)
    long double (*function_sum)(long double* (*fun)(int, long double, long double), long double, long double) = NULL;//указатель на функцию, производящую итоговый подсчет оценки (2 режим)
    setlocale(LC_ALL, "Russian");
    printf("В первом режиме производится однократный расчет функции в заданной точке.\n");
    printf("Во втором режиме производится серийный эксперимент.\n");
    printf("Введите номер режима цифрой: \n");
    scanf_s("%d", &number);
    while ((number != 1) && (number != 2))
    {
        clean();
        printf("Введено некорректное значение номера режима, попытайтесь заново: ");
        scanf_s("%d", &number);
    }
    showmenu();
    scanf_s("%d", &num_function);
    while ((num_function != 1) && (num_function !=2) && (num_function != 3) && (num_function != 4) && (num_function != 5) && (num_function != 6))//
    {
        clean();
        printf("Введено некорректное значение номера функции, попытайтесь заново: ");
        scanf_s("%d", &num_function);
    }
    if (number == 1)//первый режим
    {
        printf("Введите число элементов ряда: ");
        scanf_s("%d", &size);
        while (size <= 0)
        {
            clean();
            printf("Введено некорректное значение числа элементов ряда, попытайтесь заново: ");
            scanf_s("%d", &size);
        }
        printf("Введите x (в случае тригонометрических функций вводите значение в радианах).\n"); 
        printf("При этом отделяйте дробную часть запятой:");
        flag=scanf_s("%lf", &x);
        while (flag == 0)
        {
            clean();
            printf("Введено некорректное значение x, попытайтесь заново: ");
            flag=scanf_s("%lf", &x);
        }
        printf("Введите точность, с которой необходимо вычислить значение функции (при этом отделяйте дробную часть запятой): ");
        scanf_s("%lf", &pogr);
        while (pogr < 0)
        {
            clean();
            printf("Введено некорректное значение величины погрешности, попытайтесь заново: ");
            scanf_s("%d", &pogr);
        }
        n = size;
        printf("\n");
        printf("\n");
        switch (num_function)//вычисление и печать результатов
        {
        case 1://экспонента
            printf("Экспонента в степени х\n");
            res = sum(exp_elem, x, pogr);
            etal = exp(x);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));
            break;
        case 2://синус
            printf("Синус\n");
            res = sum(sin_elem, x, pogr);
            etal = sin(x);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));
            break;
        case 3://косинус
            printf("Косинус\n");
            res = sum(cos_elem, x, pogr);
            etal = cos(x);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));
            break;
        case 4://тангенс
            printf("Тангенс\n");
            res = tg1(cos_elem, x, pogr);
            etal = tan(x);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));//здесь указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            break;
        case 5://квадратный корень (допольнительно реализовано)
            printf("Квадратный корень из 1+х\n");
            res = sum(sqrt_elem, x, pogr);
            etal = sqrt(x+1);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));//здесь указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            break;
        case 6://котангенс
            printf("Котангенс\n");
            res = ctg1(cos_elem, x, pogr);
            etal = cos(x)/sin(x);
            printf("Оценкка = %lf\n", res);
            printf("Эталонное значение = %lf\n", etal);
            printf("Разница между оценкой и эталонным значением = %lf\n", fabs(res - etal));//здесь указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            break;
        }
        printf("Количество вычисленных элементов ряда = %d\n", col);
    }
    if (number == 2)//2 режим 
    {
        printf("Введите число экспериментов: ");
        scanf_s("%d", &size);
        while ((size <= 0) || (size>25))
        {
            clean();
            printf("Введено некорректное значение числа экспериментов, попытайтесь заново: ");
            scanf_s("%d", &size);
        }
        printf("Введите x (в случае тригонометрических функций вводите значение в радианах).\n");
        printf("При этом отделяйте дробную часть запятой:");
        flag = scanf_s("%lf", &x);
        while (flag == 0)
        {
            clean();
            printf("Введено некорректное значение x, попытайтесь заново: ");
            flag = scanf_s("%lf", &x);
        }
        printf("\n");
        printf("\n");
        switch (num_function)//передача через указатели на функции нужных функций
        {
        case 1://экспонента
            function_sum = sum;
            function_elem = exp_elem;
            etal = exp(x);
            printf("Экспонента в степени х\n");
            break;
        case 2://синус
            function_sum = sum;
            function_elem = sin_elem;
            etal = sin(x);
            printf("Синус\n");
            break;
        case 3://косинус
            function_sum = sum;
            function_elem = cos_elem;
            etal = cos(x);
            printf("Косинус\n");
            break;
        case 4://тангенс
            function_sum = tg1;
            function_elem = cos_elem;//в данном случае указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            etal = tan(x);
            printf("Тангенс\n");
            break;
        case 5://квадратный корень (допольнительно реализовано)
            function_sum = sum;
            function_elem = sqrt_elem;//в данном случае указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            etal = sqrt(x+1);
            printf("Квадратный корень из 1+х\n");
            break;
        case 6://Котангенс
            function_sum = ctg1;
            function_elem = cos_elem;//в данном случае указатель на функцию cos_elem не требуется, но для упрощения реализации 2-го режима он используется в данном случае
            etal = (cos(x) / sin(x));
            printf("Котангенс\n");
            break;
        }
        printf("эталонное значение: %lf\n", etal);
        printf("Номер эксперимента       Оценка значения функции         Разница между оценкой и эталонным значением\n");//заголовок
        for (i = 1; i <= size; i++)//обработка и печать результатов эксперимента 
        {
            count = 0;
            n = i;
            res = function_sum(function_elem, x, 0);
            raznica = fabs(etal - res);
            count=printf("%-2d %38.7lf", i, res);//выравнивание первых 2-х столбцов происходит автоматически, в count записывается длина напечатанной строки (с учетом пробелов)
            count = 83 - count - setdlina(raznica);//83 - длина всей строки, в count пишется число пробнлов, необходимое для выравнивания последнего столбца 
            if (fabs(raznica) < 1)
                count--;
            probel_print(count);
            printf("%.7lf\n", raznica);
        }
    }
    system("pause");
}