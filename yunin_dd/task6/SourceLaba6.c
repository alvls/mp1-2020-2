#define _USE_MATH_DEFINES
#define COUNT_NUM_FOR_BERNULLI 1000
//Подключение библиотек
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <locale.h>
			//Глобальные переменные
long double Bernulli_numbers[COUNT_NUM_FOR_BERNULLI] = { 0 };
//Объявление прототипов функций
int FirstFunctionMode();
double bink(int n, int k);
double bernulli(int n);
int CalculateAndPrintDataForCoth(double etal, double* tempmno, int countexperim, double x);
double CalculateCoth(double eta, double* temp, double x, double accu, int* i, int count);
int Menu();
int CalculateAndPrintDataForCh(double etal, double* tempmno, int countexperim, double x);
int CalculateAndPrintDataForSh(double etal, double* tempmno, int countexperim, double x);
//double bernulli(int n);
double MnozhitelFunctionCoth(double x, double i);
double FirstElemSh(double x);
double FirstElemCh(double x);
int CalculateAndPrintDataForExp(double etal, double* tempmno, int countexperim, double x);
int CalculateAndPrintDataForCos(double etal, double* tempmno, int countexperim, double x);
//double bink(int n, int k);
int ChoiceMode();
int SecondFunctionMode();
double MnozhitelFunctionCh(double x, long i);
double CalculateCh(double eta, double* temp, double x, double accu, int* i, int count);
double CalculateSh(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionSh(double x, long i);
//double FunctionPointer(double (*FunctionForT)(double, int, double, double, double*, int*));
double FirstElemCoth(double x);
double FirstElemCos(double x);
double FirstElemSin(double x);
double EtalonCh(double x);
double EtalonSh(double x);
double FirstElemExp(double x);
double FirstElementFunPointer(double x, double(*foo)(double));
double EtalonFunPointer(double x, double(*foo)(double));
double EtalonSin(double x);
double EtalonCos(double x);
double EtalonExp(double x);
double EtalonCoth(double x);
double CalculateSin(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionSin(double x, long i);
double CalculateCos(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionCos(double x, long i);
double CalculateExp(double eta, double* temp, double x, double accu, int* i, int count);
double MnozhitelFunctionExp(double x, long i);
int CalculateAndPrintDataForSin(double etal, double* tempmno, int countexperim, double x);
//double FunSin(double x, int count, double accu, double eta, double* res, int* i);
//sin,cos,exp,coth,ln(1+x),arctg,arcctg,sh,ch,arcsin,arccos
//попробовать (1+x)^1/2,tg,ctg,tan,cot
			//Главная функция
void Instraction()
{
	printf("\t\t\t\t\t\tИнструкция\n\tСначала программа вам выведет, как вы уже заметили, на выбор три команды:\n1) Инструкция\n2) Приступить к работе\n0) Выход из программы\n");
	printf("\tВыбор певрвого режима выдаст вам инструкцию, а потом автоматически переправит в пункт 2\n\tПри выборе нулевого режима программа звершит свою работу\n\tПри выборе второго режима программа переправитт вас в меню, где будут доступны следующие режимы:\n");
	printf("1)Единичный рассчёт функции\n2) Многоразовый рассчёт функции\n\tПри выборе певрого режима вам на выбор будут представлены 6 различных, для которых вы должны указать:\n1)Аргумент функции\n2)Количество членов в разложении\n3)Допустимую погрешность\n");
	printf("\tПосле этого программа вам выведет определённый набор данных, и предложит выйти из программы или рассчитать какую-то функцию ещё раз\n");
	printf("\tПри выборе Многоразового режима вам нужно будет ввести:\n1)Желаемую функцию\n2)Значение аргумента\n3)Количество экмперимнтов\n");
	printf("\tДальше вы увидеть на экране табличку выходных данных, где в каждой следующей строчке будет добавляться член в ряде Тейлора\nПосле этого программа предложит вам на выбор:\n0)Выйти из программы\n1)Рассчитать какую-нибудь функцию ещё раз\n");
}

void main()
{
	int choice = 0, vivod = 0;
	setlocale(LC_ALL, "Rus");
	//Функция, которая реализует инструкцию.
	//Функция, которая выводит ошибку.(проработать систему ошибок) не успел :(
	vivod = Menu();
	if (vivod == 1)
	{
		Instraction();
		system("pause");
		system("cls");
		printf("Теперь после ознакомления с инструкцией по использованию программы давайте приступать к работе!\n");
		choice = ChoiceMode();
	}
	else if (vivod == 2)
	{
		choice = ChoiceMode();
	}
	else
	{
		printf("Спасибо, за пользование моей программой. До свидания!\n");
		return;
		system("pause");
	}
	switch (choice)
	{
	case 1:
		vivod = FirstFunctionMode();
		break;
	case 2:
		vivod = SecondFunctionMode();
		break;
	}
	printf("\n\n\n\tПрограмма завершила рассчёт функции!\n");
	system("pause");
	system("cls");
	choice = -1;
	printf("Введите \"1\", если вы хотите продолжить работать с программой.\nВведите \"0\", если хотите завершить работу.\n");
	while ((choice < 0) || (choice > 1))
	{
		scanf_s("%d", &choice);
		if ((choice < 0) || (choice > 1))
		{
			printf("Такой функции не предоставлено, введите \"1\" - для продолжения работы программы, \"0\" - для завершения работы программы.\n");
		}
	}
	if (choice == 1)
	{
		system("cls");
		//ChoiceMode();
		main();
	}
	else
	{
		printf("Спасибо, за пользование моей программой. До свидания!\n");
		system("pause");
	}
}

int Menu()
{
	int choicemenu = -1;
	printf("\t\t\tДобро пожаловать в меню программы!\n");
	printf("В программе представлены следующие возможности:\n\t (1) Инструкция по использованию.\n\t (2) Приступить к работе. \n\t (0) Завершение Работы.\n ");
	printf("Введите номер: ");
	while ((choicemenu < 0) || (choicemenu > 2))
	{
		scanf_s("%d", &choicemenu);
		if ((choicemenu < 0) || (choicemenu > 2))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	return choicemenu;
}

int ChoiceMode()
{
	int choicemode = 0;
	printf("Уважаемый пользователь, вам предоставлены 2 режима:\n\t (1) Единичный рассчёт функции.\n\t (2) Многоразовый рассчёт функции.\n");
	printf("Введите номер: ");
	while ((choicemode < 1) || (choicemode > 2))
	{
		scanf_s("%d", &choicemode);
		if ((choicemode < 1) || (choicemode > 2))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	return choicemode;
}
//Функция, отвечающая за первый режим
int FirstFunctionMode()
{
	int choicefun = 0, countmem = 0, i = 0;
	double arg, accuracy = 0.0000001, result = 0, etalon = -1000, rasn, tempmn = 0, ymno;
	printf("Добро пожаловать в первый режим.\n");
	printf("В программе доступны следующие функции:\n(1) Sin(x) \n(2) Cos(x) \n(3) Exp(x) \n(4) Coth(x) \n(5) Sh(x) \n(6) Ch(x) \n");
	printf("Введите номер функции, значение которой вы хотите рассчитать:\n");
	while ((choicefun < 1) || (choicefun > 6))
	{
		scanf_s("%d", &choicefun);
		if ((choicefun < 1) || (choicefun > 6))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	printf("Введите значение аргумента для функции:\n");
	scanf_s("%lf", &arg);
	printf("Введите количесто членов в ряде:\n");
	while ((countmem < 1) || (countmem > 1000))
	{
		scanf_s("%d", &countmem);
		if ((countmem < 1) || (countmem > 1000))
		{
			printf("Введено неверное число!Повторите ввод.\n");
		}
	}
	printf("Введите точность вычисления для функции:\n");
	while (accuracy < 0.000001)
	{
		scanf_s("%lf", &accuracy);
		if (accuracy < 0.000001)
		{
			printf("Введено неверное значение!Повторите ввод.\n");
		}
	}
	switch (choicefun)
	{
	case 1:
		tempmn = FirstElementFunPointer(arg, FirstElemSin);
		etalon = EtalonFunPointer(arg, EtalonSin);
		result = CalculateSin(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Sin(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 2:
		tempmn = FirstElementFunPointer(arg, FirstElemCos);
		etalon = EtalonFunPointer(arg, EtalonCos);
		result = CalculateCos(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Cos(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 3:
		tempmn = FirstElementFunPointer(arg, FirstElemExp);
		etalon = EtalonFunPointer(arg, EtalonExp);
		result = CalculateExp(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Exp(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 4:
		tempmn = FirstElementFunPointer(arg, FirstElemCoth);
		etalon = EtalonFunPointer(arg, EtalonCoth);
		result = CalculateCoth(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Coth(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
		//tangens(arg, countmem, accuracy);
		break;
	case 5:
		tempmn = FirstElementFunPointer(arg, FirstElemSh);
		etalon = EtalonFunPointer(arg, EtalonSh);
		result = CalculateSh(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Sh(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	case 6:
		tempmn = FirstElementFunPointer(arg, FirstElemCh);
		etalon = EtalonFunPointer(arg, EtalonCh);
		result = CalculateCh(etalon, &tempmn, arg, accuracy, &i, countmem);
		printf("\t\t\t\t\t Табличка ваших введённых данных\n");
		printf("(1) Вы ввели функцию Ch(x)\n");
		printf("(2) Вы ввели аргумент x = %lf\n", arg);
		printf("(3) Вы ввели количество членов в формуле Тейлора countmem = %d\n", countmem);
		printf("(4) Вы ввели требуюмую погрешность accuracy = %lf\n", accuracy);
		break;
	}
	//printf("%lf\n", tempmn);
	//printf("%lf\n", etalon);
	rasn = fabs(result - etalon);
	printf("\t\t\t\t\tТаблица выходных данных\n");
	printf("(1) Вычисленное эталонное значение = %lf\n", etalon);
	printf("(2) Вычисленный результат = %lf\n", result);
	printf("(3 Разность между эталонным значением и вычесленным значением = %lf\n", rasn);
	printf("(4) Количество членов, используемых при разложении в формуле Тейлора = %d\n", i);
	return 1;
}

//double FunctionPointer(double x, int count, double accu, double eta, double* res, int* i, double(*FunctionForT)(double, int, double, double, double*, int*))
//{
//	FunctionForT(x, count, accu, eta, &res, &i);
//}
			//Все функции для подсчёта Exp для первого режима.
double CalculateExp(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, ymno;
	long j;
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionExp(x, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionExp(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (x / i);
	}
	return vivod;
}
double CalculateSh(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = ((x * M_PI) / 180);
	res = arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionSh(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionSh(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (((x * x)) / (2 * i * (2 * i + 1)));
		return vivod;
	}
}

double CalculateSin(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = ((x * M_PI) / 180);
	res = arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionSin(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionSin(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = ((-(x * x)) / (2 * i * (2 * i + 1)));
		return vivod;
	}
}

double CalculateCos(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = ((x * M_PI) / 180);
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionCos(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionCos(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = ((-(x * x)) / (2 * i * (2 * i - 1)));
	}
	return vivod;
}
double CalculateCh(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res, arg, ymno;
	long j;
	arg = ((x * M_PI) / 180);
	res = *temp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = *i;
		ymno = MnozhitelFunctionCh(arg, j);
		*temp *= ymno;
		res += *temp;
	}
	return res;
}
double MnozhitelFunctionCh(double x, long i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = (((x * x)) / (2 * i * (2 * i - 1)));
	}
	return vivod;
}
double EtalonFunPointer(double x, double(*foo)(double))
{
	double etalon;
	etalon = foo(x);
	return etalon;
}

double EtalonSin(double x)
{
	double arg, etalon;
	arg = ((x * M_PI) / 180);
	etalon = sin(arg);
	return etalon;
}
double EtalonCh(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	//printf("%lf\n", temp1);
	temp2 = exp(-x);
	//printf("%lf\n", temp2);
	etalon = ((temp1 + temp2) / 2);
	return etalon;
}
double EtalonSh(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	//printf("%lf\n", temp1);
	temp2 = exp(-x);
	//printf("%lf\n", temp2);
	etalon = (temp1 - temp2) / 2;
	return etalon;
}
double EtalonCos(double x)
{
	double arg, etalon;
	arg = ((x * M_PI) / 180);
	etalon = cos(arg);
	return etalon;
}

double EtalonExp(double x)
{
	double etalon;
	etalon = exp(x);
	return etalon;
}
double EtalonCoth(double x)
{
	double etalon, temp1, temp2;
	temp1 = exp(x);
	//printf("%lf\n", temp1);
	temp2 = exp(-x);
	//printf("%lf\n", temp2);
	etalon = ((temp1 + temp2) / (temp1 - temp2));
	return etalon;
}
double FirstElementFunPointer(double x, double(*foo)(double))
{
	double firstel;
	firstel = foo(x);
	return firstel;
}

double FirstElemSin(double x)
{
	double arg;
	arg = ((x * M_PI) / 180);
	return arg;
}
double FirstElemSh(double x)
{
	double arg;
	arg = x;
	return arg;
}
double FirstElemCh(double x)
{
	return 1;
}
//1 - sin, 2 - cos, 3 - ex, 4 - coth
double FirstElemCos(double x)
{
	return 1;
}

double FirstElemExp(double x)
{
	return 1;
}

double FirstElemCoth(double x)
{
	double arg;
	arg = ((x * M_PI) / 180);
	return (1 / x);
}

int SecondFunctionMode()
{
	int choicefunction = 0, countexp = 0, vivod;
	double arg, tempmn, etalon;
	printf("Добро пожаловать во второй режим!\n");
	printf("В программе доступны следующие функции:\n(1) Sin(x) \n(2) Cos(x) \n(3) Exp(x) \n(4) Coth(x) \n(5) Sh(x) \n(6) Ch(x) \n");
	printf("Введите номер функции, значение которой вы хотите рассчитать:\n");
	while ((choicefunction < 1) || (choicefunction > 6))
	{
		scanf_s("%d", &choicefunction);
		if ((choicefunction < 1) || (choicefunction > 6))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	printf("Введите значение аргумента для функции:\n");
	scanf_s("%lf", &arg);
	printf("Введите количество экспериментов, которое хотите провести:\n");
	while ((countexp < 1) || (countexp > 25))
	{
		scanf_s("%d", &countexp);
		if ((countexp < 1) || (countexp > 25))
		{
			printf("Введен неправильный номер!Повторите ввод.\n");
		}
	}
	switch (choicefunction)
	{
	case 1:
		tempmn = FirstElementFunPointer(arg, FirstElemSin);
		etalon = EtalonFunPointer(arg, EtalonSin);
		vivod = CalculateAndPrintDataForSin(etalon, &tempmn, countexp, arg);
		break;
	case 2:
		tempmn = FirstElementFunPointer(arg, FirstElemCos);
		etalon = EtalonFunPointer(arg, EtalonCos);
		vivod = CalculateAndPrintDataForCos(etalon, &tempmn, countexp, arg);
		break;
	case 3:
		tempmn = FirstElementFunPointer(arg, FirstElemExp);
		etalon = EtalonFunPointer(arg, EtalonExp);
		vivod = CalculateAndPrintDataForExp(etalon, &tempmn, countexp, arg);
		break;
	case 4:
		tempmn = FirstElementFunPointer(arg, FirstElemCoth);
		etalon = EtalonFunPointer(arg, EtalonCoth);
		vivod = CalculateAndPrintDataForCoth(etalon, &tempmn, countexp, arg);
		break;
	case 5:
		tempmn = FirstElementFunPointer(arg, FirstElemSh);
		etalon = EtalonFunPointer(arg, EtalonSh);
		vivod = CalculateAndPrintDataForSh(etalon, &tempmn, countexp, arg);
		break;
	case 6:
		tempmn = FirstElementFunPointer(arg, FirstElemCh);
		etalon = EtalonFunPointer(arg, EtalonCh);
		vivod = CalculateAndPrintDataForCh(etalon, &tempmn, countexp, arg);
		break;
	}

	return 1;
}

int CalculateAndPrintDataForSin(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	arg = ((x * M_PI) / 180);
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionSin(arg, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.10lf|%50.10lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}


//double CalculateCoth(double eta, double* temp, double x, double accu, int* i, int count)
//{
	/*double res = 0, arg, ymno1, ymno2, secondtemp, firsttemp;
	int j;
	arg = ((x * M_PI) / 180);
	secondtemp = FirstElemSh(x);
	firsttemp = FirstElemCh(x);
	res += firsttemp / secondtemp;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = (*i) ;
		ymno1 = MnozhitelFunctionSh(arg, j);
		ymno2 = MnozhitelFunctionCh(arg, j);
		firsttemp *= ymno1;
		secondtemp *= ymno2;
		res += firsttemp / secondtemp;
	}
	/*double res, arg, ymno, ymno1 ,temp1,temp2;
	int j;
	//arg = ((x * M_PI) / 180);
	arg = x;
	temp1 = 1;
	temp2 = 1;
	res = (temp1 + temp2) / (temp1 - temp2);
	for ( *i = 1; ((*i) < count) && fabs((res) - eta) > accu; (*i)++)
	{
		j = (*i);
		ymno = MnozhitelFunctionExp(arg, j);
		ymno1 = MnozhitelFunctionExp(-arg, j);
		temp1 *= ymno;
		temp2 *= ymno1;
		res = (temp1 + temp2) / (temp1 - temp2);
	}*/
	//return res;
//}

double MnozhitelFunctionCoth(double x, double i)
{
	double vivod;
	if (i == 0)
	{
		return 1;
	}
	else
	{
		vivod = ((-(x * x) * 4) / (2 * i * (2 * i - 1)));
		return vivod;
	}
}



int CalculateAndPrintDataForCos(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	arg = ((x * M_PI) / 180);
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionCos(arg, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForExp(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double arg, res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionExp(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}

int CalculateAndPrintDataForCh(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; (i < countexperim); i++)
	{
		ymno = MnozhitelFunctionCh(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}
int CalculateAndPrintDataForSh(double etal, double* tempmno, int countexperim, double x)
{
	long i, j;
	double  res = 0, ymno, rasn;
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; i < countexperim; i++)
	{
		ymno = MnozhitelFunctionSh(x, i);
		*tempmno *= ymno;
		res += *tempmno;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.10lf|%50.10lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}
double bink(int n, int k)
{
	double result = 1;
	for (unsigned i = 1; i <= n - k; i++)
		result *= (double)(k + i) / (double)(i);
	return result;
}
double bernulli(int n)
{
	if (n > 255)
		n = 255;
	double ber[256] = { 0 };
	ber[0] = 1.;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			ber[i] += bink(i + 1, j + 1) * ber[i - j];
		ber[i] *= (-1.) / (double)(i + 1);
	}
	return ber[n];
}

double CalculateCoth(double eta, double* temp, double x, double accu, int* i, int count)
{
	double res = 0, arg, ymno1, ymno2, ymno3, secondtemp, firsttemp;
	int j;
	arg = x;
	//arg = ((x * M_PI) / 180);
	res = 1 / arg;
	for (*i = 1; ((*i) < count) && fabs((res)-eta) > accu; (*i)++)
	{
		j = (*i);
		double berni = bernulli(2 * j) / bernulli(2 * j - 2);
		firsttemp = pow(-1, j - 1);
		secondtemp = pow(4, j);
		ymno1 = arg * arg / (2 * j * (2 * j - 1));
		ymno2 = berni * ymno1;
		ymno3 = firsttemp * secondtemp;
		res += ymno3 * ymno2;
	}
	return res;
}
int CalculateAndPrintDataForCoth(double etal, double* tempmno, int countexperim, double x)
{
	long i, j = 1;
	double arg, res = 0, ymno, rasn, berni, firsttemp, secondtemp;
	arg = ((x * M_PI) / 180);
	Bernulli_numbers[0] = 1; Bernulli_numbers[1] = 1 / 2; Bernulli_numbers[2] = 1 / 6; Bernulli_numbers[3] = 0; Bernulli_numbers[4] = -1 / 30;
	Bernulli_numbers[5] = 0; Bernulli_numbers[6] = 1 / 42; Bernulli_numbers[7] = 0; Bernulli_numbers[8] = -1 / 30; Bernulli_numbers[9] = 0;
	Bernulli_numbers[10] = 5 / 66; Bernulli_numbers[11] = 0; Bernulli_numbers[12] = -691 / 2730; Bernulli_numbers[13] = 0; Bernulli_numbers[14] = 7 / 6;
	Bernulli_numbers[15] = 0; Bernulli_numbers[16] = -3617 / 510; Bernulli_numbers[17] = 0; Bernulli_numbers[18] = 43867 / 798; Bernulli_numbers[19] = 0;
	Bernulli_numbers[20] = -174611 / 330; Bernulli_numbers[21] = 0; Bernulli_numbers[22] = 854513 / 138; Bernulli_numbers[23] = 0; Bernulli_numbers[24] = -236364091 / 2730;
	Bernulli_numbers[25] = 0; Bernulli_numbers[26] = 8553103 / 6; Bernulli_numbers[27] = 0; Bernulli_numbers[28] = -23749461029 / 870; Bernulli_numbers[29] = 0;
	Bernulli_numbers[30] = 8615841276005 / 14322; Bernulli_numbers[31] = 0; Bernulli_numbers[32] = -7709321041217 / 510; Bernulli_numbers[33] = 0; Bernulli_numbers[34] = 2577687858367 / 6;
	Bernulli_numbers[35] = 0; Bernulli_numbers[36] = -13711655205088.332; Bernulli_numbers[37] = 0; Bernulli_numbers[38] = 2929993913841559 / 6; Bernulli_numbers[39] = 0;
	Bernulli_numbers[40] = -19296579341940068.1486; Bernulli_numbers[41] = 0; Bernulli_numbers[42] = 841693047573682615; Bernulli_numbers[43] = 0; Bernulli_numbers[44] = -40338071854059455413.07;
	Bernulli_numbers[45] = 0; Bernulli_numbers[46] = 2115074863808199160560.14; Bernulli_numbers[47] = 0; Bernulli_numbers[48] = -120866265222965259346027.31; Bernulli_numbers[49] = 0;
	Bernulli_numbers[50] = 7500866746076964366855720.07;
	/*while ((arg > M_PI) || (arg < -M_PI))
	{
		if (arg > M_PI)
		{
			arg -= 2 * M_PI;
		}
		if (arg < -M_PI)
		{
			arg += 2 * M_PI;
		}
	}*/
	printf("\t\t\t\t\t\t\t\tТаблица Данных\n");
	printf("____________________________________________________________________________________________________________________________________\n");
	printf("|Номер эксперимента|                 Вычесленная оценка значения                |   Разница между оценкой и эталонным значением    |\n");
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	for (i = 0; i < countexperim; i++)
	{
		if (i == 0)
		{
			res = *tempmno;
			rasn = fabs(res - etal);
			printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
			continue;
		}
		int k = 2 * i;
		berni = Bernulli_numbers[k];
		ymno = arg * arg / (2 * j * (2 * j - 1));
		firsttemp = pow(-1, j - 1);
		secondtemp = pow(4, j);
		res += berni * ymno * firsttemp * secondtemp;
		j = i + 1;
		rasn = fabs(res - etal);
		printf("|%18d|%60.15lf|%50.15lf|\n", j, res, rasn);
	}
	printf("|__________________|____________________________________________________________|__________________________________________________|\n");
	printf("Эталонное значение = %lf\n", etal);
	//таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), 
	//вычисленную оценку значения функции, разницу между оценкой и эталонным значением.
	return 1;
}
