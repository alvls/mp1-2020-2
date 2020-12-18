#include "all.h"

double summator(double x, double eps, int n, double etalon, function func, rezhimfunction condition)
{
    double sum = func(1, 0, x); //Ряд Тейлора - это сумма определённых слагаемых, в эту переменную она и будет записываться 
    double present = sum; //Текущий элемент в ряде Тейлора
    int iteration = 2; //Количество итераций
    while ((condition(x, iteration, n, etalon, func, sum, eps)) == 1)
    {
        present = func(iteration, present, x);
        sum += present;
        iteration++;
    }
    return sum;
}

int condition_one(double x, int i, int n, double etalon, function func, double sum, double eps)
{
    if ((fabs(etalon - sum) > eps) && (i <= n))
    {
        return 1;
    }
    else
    {
        printgran(60);
        printf(" Эталонное значение:\n  %-.10lf\n\n Вычисленная оценка значения функции:\n  %-.10lf\n\n Разница между оценкой и эталонным значением:\n  %-.10lf\n\n Количество слагаемых, которое было вычислено: %d\n", etalon, sum, fabs(etalon - sum), i - 1);
        printgran(60);
        return 0;
    }
}

int condition_two(double x, int i, int n, double etalon, function func, double sum, double eps)
{
    printf("%3d |%44.20lf |%44.20lf\n", i - 1, sum, fabs(etalon - sum));
    if (i <= n)
    {
        return 1;
    }
    else
    {
        printgran(96);
        return 0;
    }
}

double taylor_sin(int n, double previous, double x)
{
    if (n == 1)
        return x;
    return (((-1) * previous * x * x) / ((2 * (double)n - 1) * (2 * (double)n - 2)));
}

double taylor_cos(int n, double previous, double x)
{
    if (n == 1)
        return 1;
    return (((-1) * previous * x * x) / ((2 * (double)n - 2) * (2 * (double)n - 3)));
}

double taylor_arcsin(int n, double previous, double x)
{
    if (n == 1)
        return x;
    return ((previous * x * x * (2 * (double)n - 3) * (2 * (double)n - 3)) / ((2 * (double)n - 2) * (2 * (double)n - 1)));
}

double taylor_arccos(int n, double previous, double x)
{
    if (n == 1)
        return (PI / 2);
    if (n == 2)
        return (-x);
    return ((previous * x * x * (2 * (double)n - 3) * (2 * (double)n - 3)) / ((2 * (double)n - 2) * (2 * (double)n - 1)));
}

double taylor_sinh(int n, double previous, double x)
{
    if (n == 1)
        return x;
    return ((previous * x * x) / ((2 * (double)n - 1) * (2 * (double)n - 2)));
}

double taylor_cosh(int n, double previous, double x)
{
    if (n == 1)
        return 1;
    return (((-1) * previous * x * x) / ((2 * (double)n - 2) * (2 * (double)n - 3)));
}

double taylor_exp(int n, double previous, double x)
{
    if (n == 1)
        return 1;
    return ((previous * x) / ((double)n - 1));
}
