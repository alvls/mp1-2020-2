#include "all.h"

/*Объявление глобальных переменных*/
function empty_function; //Указатель на выбранную пользователем функцию 
rezhimfunction regime_conditions; //Указатель на условия режима

int menu()
{
    int vibor = -1;
    printgran(60);
    printf("  Сейчас Вы находитесь в меню. Выберите, что нужно сделать:\n\t(1) Однократный расчет функции в заданной точке\n\t(2) Серийный эксперимент\n\t(0) Выйти из программы\n");
    printgran(60);
    while ((vibor < 0) || (vibor > 2))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 0) || (vibor > 2))
        {
            printf(" Данная функция не предусмотрена программой. Введите число от 0 до 2.\n");
            while (getchar() != '\n');
        }
    }
    if (vibor == 0)
    {
        return 0;
    }
    else
    {
        navigator(vibor);
        return(vibor);
    }
}

//Выбор функции
int choice_your_function()
{
    int vibor = -1;
    printgran(53);
    printf(" Вам доступен набор, состоящий из следующих функций:\n (1) sin(x),%4cгде x вводится в градусах\n (2) cos(x),%4cгде x вводится в градусах\n (3) arcsin(x), где |x|<1\n (4) arccos(x), где |x|<1\n (5) sinh(x)\n (6) cosh(x)\n (7) exp(x)\n", ' ', ' ');
    printgran(53);
    printf(" Введите номер функции, с которой Вы хотите работать:\n");
    while ((vibor < 1) || (vibor > 7))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 1) || (vibor > 7))
        {
            printf(" Данная функция не предусмотрена программой. Введите число от 1 до 7.\n");
            while (getchar() != '\n');
        }
    }
    return vibor;
}

//Выбор точки
double choice_your_dot(int vibor)
{
    double x;
    int prov = 0; //Проверка на правильность введённых данных
    printf("\n Задайте точку x, в которой необходимо вычислить значение (используйте символ \",\" в качестве разделителя):\n");
    while (prov != 1)
    {
        prov = scanf_s("%lf", &x);
        if ((prov != 1) || (((vibor == 3) || (vibor == 4)) && (fabs(x) >= 1)))
        {
            printf(" Введено недопустимое значение x. Попробуйте ещё раз.\n");
            prov = 0;
            while (getchar() != '\n');
        }
    }
    if ((vibor == 1) || (vibor == 2))
    {
        x = x * PI / 180; //Перевод из градусов в радианы, потому что в формуле Тейлора для функций sinx и cosx "x" рассматривается в радианах
        x = fmod(x, 2 * PI);
    }
    system("cls");
    return x;
}

//Важные данные
double your_function(double x, double etalon, int vibor)
{
    printf("\n Вы выбрали функцию \"");
    switch (vibor)
    {
    case 1:
        etalon = sin(x);
        empty_function = taylor_sin;
        printf("sin(x)\"\n\n Ряд Тейлора для этой функции: \n");
        printgran(63);
        printf("%15c3%4c5%4c7%20c2n-1\n%14cx%4cx%4cx%14cn-1%3cx%11c2n-1\n sin(x) = x - —— + —— - —— + ... + (-1)%3c* ———————— + o(x   )\n%14c3!%3c5!%3c7!%18c(2n-1)!\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(63);
        printf("\n Функция рассматривается в точке x = %f rad (преобразовано автоматически)", x);
        break;
    case 2:
        etalon = cos(x);
        empty_function = taylor_cos;
        printf("cos(x)\"\n\n Ряд Тейлора для этой функции: \n");
        printgran(63);
        printf("%15c2%4c4%4c6%20c2n-2\n%14cx%4cx%4cx%14cn-1   x%11c2n-2\n cos(x) = 1 - —— + —— - —— + ... + (-1)   * ——————— + o(x    )\n%14c2!%3c4!%3c6!%18c(2n-2)!\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(63);
        printf("\n Функция рассматривается в точке x = %f rad (преобразовано автоматически)", x);
        break;
    case 3:
        etalon = asin(x);
        empty_function = taylor_arcsin;
        printf("arcsin(x)\" , в которой |x| < 1 \n\n Ряд Тейлора для этой функции: \n");
        printgran(85);
        printf("%20c3%8c5%10c7%27c2n-1\n%17c1*x%4c1*3*x%4c1*3*5*x%10c1*3*5*...*(2n-3)*x%11c2n-1\n arcsin(x) = x + ———— + —————— + ———————— + ... + ——————————————————————— + o(x    )\n%17c2*3%4c2*4*5%4c2*4*6*7%10c2*4*6*...*(2n-2)*(2n-1)\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(85);
        printf("\n Функция рассматривается в точке x = %lf", x);
        break;
    case 4:
        etalon = acos(x);
        empty_function = taylor_arccos;
        printf("arccos(x)\" , в которой |x| < 1 \n\n Ряд Тейлора для этой функции: \n");
        printgran(91);
        printf("%25c3%8c5%10c7%27c2n-3\n%13cп%8c1*x%4c1*3*x%4c1*3*5*x%10c1*3*5*...*(2n-5)*x%12c2n-3\n arccos(x) = — - (x + ———— + —————— + ———————— + ... + ———————————————————————) + o(x    )\n%13c2%8c2*3%4c2*4*5%4c2*4*6*7%10c2*4*6*...*(2n-4)*(2n-3)\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(91);
        printf("\n Функция рассматривается в точке x = %lf", x);
        break;
    case 5:
        etalon = sinh(x);
        empty_function = taylor_sinh;
        printf("sinh(x)\"\n\n Ряд Тейлора для этой функции: \n");
        printgran(55);
        printf("%16c3%4c5%4c7%11c2n-1\n%15cx%4cx%4cx%11cx%11c2n-1\n sinh(x) = x + —— + —— + —— + ... + ——————— + o(x    )\n%15c3!%3c5!%3c7!%9c(2n-1)!\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(55);
        printf("\n Функция рассматривается в точке x = %lf", x);
        break;
    case 6:
        etalon = cosh(x);
        empty_function = taylor_cosh;
        printf("cosh(x)\"\n\n Ряд Тейлора для этой функции: \n");
        printgran(55);
        printf("%16c2%4c4%4c6%11c2n-2\n%15cx%4cx%4cx%11cx%11c2n-2\n cosh(x) = 1 + —— + —— + —— + ... + ——————— + o(x    )\n%15c2!%3c4!%3c6!%9c(2n-2)!\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(55);
        printf("\n Функция рассматривается в точке x = %lf", x);
        break;
    case 7:
        etalon = exp(x);
        empty_function = taylor_exp;
        printf("exp(x)\"\n\n Ряд Тейлора для этой функции: \n");
        printgran(41);
        printf("%15c2%4c3%10cn\n  x%11cx%4cx%10cx%7cn\n e  = 1 + x + —— + —— + ... + —— + o(x )\n%14c2!%3c3!%9cn!\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        printgran(41);
        printf("\n Функция рассматривается в точке x = %lf", x);
        break;
    default:
        printf(" Ошибка, связанная с выбором функции\n");
        exit(55);
    }
    return etalon;
}

//Навигатор
void navigator(int vibormenu)
{
    system("cls");
    double sum;
    empty_function = NULL;
    double etalon = -999999999.0; //Эталонное значение функции, полученное с использованием встроенных математических функций языка программирования С
    double eps = -999999999.0; //Точность вычисления
    int n = 0; //Число элементов ряда для выполнения расчета (от 1 до 1000).
    int vibor = choice_your_function(); //Выбор функции
    double x = choice_your_dot(vibor); //Точка, в которой необходимо вычислить значение
    etalon = your_function(x, etalon, vibor);
    switch (vibormenu) //В зависимости от выбора режима, происходит получение нужных данных и последующая передача этих данных в сумматор ряда Тейлора
    {
    case 1:
        regime_conditions = condition_one;
        printf("\n\n Задайте точность вычисления eps>= 0,000001 (используйте символ \",\" в качестве разделителя):\n");
        while (eps < 0.000001)
        {
            scanf_s("%lf", &eps);
            if (eps < 0.000001)
            {
                printf(" Введено недопустимое значение eps. Попробуйте ещё раз.\n");
                while (getchar() != '\n');
            }
        }
        clearscreen(0, 13);
        printf(" Заданная точность вычисления eps = %f\n", eps);
        printf("\n Задайте число элементов ряда для выполнения расчёта (1<=n<=1000):\n");
        while ((n < 1) || (n > 1000))
        {
            scanf_s("%d", &n);
            if ((n < 1) || (n > 1000))
            {
                printf(" Введено недопустимое значение n. Попробуйте ещё раз.\n");
                while (getchar() != '\n');
            }
        }
        clearscreen(0, 15);
        printf(" Заданное число элементов ряда для выполнения расчёта = %d\n\n", n);
        break;
    case 2:
        regime_conditions = condition_two;
        printf("\n\n Задайте число экспериментов (1<=n<=%d):\n", NMAX);
        while ((n < 1) || (n > NMAX))
        {
            scanf_s("%d", &n);
            if ((n < 1) || (n > NMAX))
            {
                printf(" Введено недопустимое значение n. Попробуйте ещё раз.\n");
                while (getchar() != '\n');
            }
        }
        clearscreen(0, 13);
        printf(" Заданное число экспериментов = %d\n\n", n);
        printf(" Эталонное значение: %lf\n\n", etalon);
        printgran(96);
        printf(" №  |%5cВычисленная оценка значения функции%5c| Разница между оценкой и эталонным значением\n", ' ', ' ');
        printgran(96);
        break;
    default:
        exit(55);
    }
    sum = summator(x, eps, n, etalon, empty_function, regime_conditions);
    if ((vibor == 3) || (vibor == 4))
    {
        printf(" Эталонное значение (в градусах):\n  %-.15lf\n\n", (etalon * 180 / PI));
        printf(" Вычисленная оценка значения функции (в градусах):\n  %-.15lf\n\n", (sum * 180 / PI));
        printf(" Разница между оценкой и эталонным значением (в градусах):\n  %-.15lf\n\n", (fabs(etalon-sum) * 180 / PI));
    }
    system("pause");
    system("cls");
}
