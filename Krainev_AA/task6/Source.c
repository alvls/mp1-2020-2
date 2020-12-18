#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

float degreesToRadians(float degrees);
int choiceOfFunctionForDecomposition();
int choiceOfMode();
double getRealVariable();
void modeOne(void(*functionPointer)(double, double, long int), double rV, float etalon);
void modeTwo(void(*functionPointer)(double, double, long int), double rV, double etalon);
void sinX(double rV, double cA, long int nOF);
void cosX(double rV, double cA, long int nOF);
void expX(double rV, double cA, long int nOF);
void arcsinX(double rV, double cA, long int nOF);
double realVariable; //вещественная точка в которой высчитывается значение 
float calculationAccuracy; //точность вычисления (эпсилон)
long int numberOfElements; //число элементов ряда для выполнения расчета
main() {
	setlocale(LC_ALL, "RUS");
	printf("Добро пожаловать в программу, позволяющую выполнять расчет значений для некоторого набора функций в заданной точке\n");
	printf("с заданной погрешностью за счет разложения этих функций в ряд Тейлора!\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("Программа работает в 2 режимах\n");
	printf("_При работе в режиме 1 пользователь имеет возможность:_\n");
	printf("-> выбрать функцию,\n");
	printf("-> задать точку x, в которой необходимо вычислить значение,\n");
	printf("-> задать точность вычисления(>= 0.000001),\n");
	printf("-> задать число элементов ряда для выполнения расчета(N - от 1 до 1000).\n");
	printf("Расчет оценки значения выбранной функции выполняется либо до достижения заданной точности,\n");
	printf("либо до исчерпания введенного числа слагаемых.\n");
	printf("__По результатам расчета программа выведет следующую информацию:__\n");
	printf("-> эталонное значение(полученное с использованием встроенных математических функций языка программирования С),\n");
	printf("-> вычисленную оценку значения функции,\n");
	printf("-> разницу между оценкой и эталонным значением,\n");
	printf("-> количество слагаемых, которое было вычислено.\n");
	printf("__При работе в режиме 2 пользователь имеет возможность:__\n");
	printf("-> выбрать функцию,\n");
	printf("-> задать точку x, в которой необходимо вычислить значение,\n");
	printf("-> задать число экспериментов(NMax - от 1 до 25).\n");
	printf("_По результатам расчета программа выведет следующую информацию:_\n");
	printf("-> эталонное значение(полученное с использованием встроенных математических функций языка программирования С),\n");
	printf("-> таблицу из NMax строк со следующими столбцами : кол - во слагаемых(от 1 до NMax),\n");
	printf("-> вычисленную оценку значения функции, разницу между оценкой и эталонным значением.\n");
	printf("\n");
	printf("---------------------------------------------------------------------------------------------\n");
	int funcNum;
	int mode;
	void(*functionPointer)(double, double, long int) = NULL;
	mode = choiceOfMode();//выбираем режим работы
	funcNum = choiceOfFunctionForDecomposition(); //выбираем функцию 
	float rV;
	float cA;
	float nOF;
	rV = getRealVariable(); //получаем значение икс
	float etalon = 0;
	switch (funcNum) {
	case 1:
		functionPointer = sinX;
		rV = degreesToRadians(rV);
		printf("В радианах %f\n", rV);
		etalon = sin(rV);
		break;
	case 2:
		functionPointer = cosX;
		rV = degreesToRadians(rV);
		printf("В радианах %f\n", rV);
		etalon = cos(rV);
		break;
	case 3:
		functionPointer = expX;
		etalon = exp(rV);
		break;
	case 4:
		functionPointer = arcsinX;
		etalon = asin(rV);
		break;
	}
	if (mode == 1) {
		modeOne(functionPointer, rV, etalon);
	}
	if (mode == 2) {
		modeTwo(functionPointer, rV, etalon);
	}
	getchar();
}
void modeOne(void(*functionPointer)(double, double, long int), double rV, float etalon) {
	printf_s("Введите точность вычисления (эпсилон): ");
	scanf_s("%f", &calculationAccuracy);
	printf_s("Введите количество слагаемых: ");
	scanf_s("%li", &numberOfElements);
	printf_s("Эталонное значение (полученное с использованием встроенных математических функций языка программирования): %f\n", etalon);
	printf_s("Вычисленная оценка функции   Разница между оценкой и эталоном    Вычисленное число слагаемых\n");
	functionPointer(rV, calculationAccuracy, numberOfElements);
	printf("До встречи!\n");
	getchar();
}
void modeTwo(void(*functionPointer)(double, double, long int), double rV, double etalon) {
	long int i;
	int numberOfExperement;
	double cA = -0.000001;
	printf("Введите количество экспериментов от 1 до 25?\n");
	scanf_s("%i", &numberOfExperement);
	printf_s("Эталонное значение (полученное с использованием встроенных математических функций языка программирования): %f\n", etalon);
	printf("Вычисленная оценка функции   Разница между оценкой и эталоном    Вычисленное число слагаемых\n");
	for (i = 0; i < numberOfExperement; i++) {
		functionPointer(rV, calculationAccuracy, i + 1);
	}
	printf("До встречи!\n");
	getchar();
}
void sinX(double rV, double cA, long int nOF) {
	long int i;
	double sinInX = sin(rV);
	double function = rV;
	double delta = fabs(sinInX - function);
	double term = rV;
	for (i = 2; (i <= nOF) && (delta >= cA); i++){
		term = (-1) * term * rV * rV / ((2 * i - 1) * (2 * i - 2));
		function = function + term;
		delta = fabs(sinInX - function);
	}
	//printf("Вычисленная оценка функции   Разница между оценкой и эталоном    Вычисленное число слагаемых\n ");
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void cosX(double rV, double cA, long int nOF) {
	long int i;
	double cosInX = cos(rV);
	double function = 1;
	double delta = fabs(cosInX - function);
	double term = 1;
	for (i = 2; (i <= nOF) && (delta >= cA); i++){
		term = (-1) * term * rV * rV / ((2 * i - 2) * (2 * i - 3));
		function = function + term;
		delta = fabs(cosInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void expX(double rV, double cA, long int nOF) {
	long int i;
	double expInX = exp(rV);
	double function = 1;
	double delta = fabs(expInX - function);
	double term = 1;
	for (i = 2; (i <= nOF) && (delta >= cA); i++){
		term = term * rV / (i - 1);
		function = function + term;
		delta = fabs(expInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void arcsinX(double rV, double cA, long int nOF) {
	long int i;
	double arcsinInX = asin(rV);
	double function = rV;
	double delta = fabs(arcsinInX - function);
	double term = rV;
	for (i = 1; (i <= nOF) && (delta >= cA); i += 1){
		//term = term * ((rV * rV * (2 * i + 1) * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3)));
		term *= ((rV * rV) * (2 * i - 1) * (2 * i - 1)) / ((2 * i) * (2 * i + 1));
		function = function + term;
		delta = fabs(arcsinInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n", function, delta, i + 1);
}
float degreesToRadians(float degrees) { //преобразует градусы в радианы и возвращает значание икс в них
	float radians;
	radians = ((degrees * M_PI) / 180);
	return radians;
}
double getRealVariable() { //получаем иксик
	printf("Введите x (в градусах для тригонометрических функций), для вычисления в ней значени:\n");
	scanf_s("%lf", &realVariable);
	printf("Вы ввели %f\n", realVariable);
	return realVariable;
}
int choiceOfFunctionForDecomposition() { //выбирает функцию для разложения и возвразает ее номер: также делает проверку на ввод
	int choice;
	printf("Выберите нужную функцию: из представленного ниже:\n");
	printf("1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arcsin(x)\n");
	int z = 1;
	while (z != 0) { //проверка на неверно введенный пункт меню
		scanf_s("%i", &choice);
		if (choice > 4 || choice < 1) {
			printf("Такого нет в меню. Выберите заново!\n");
			z = 1;
		}
		else {
			z = 0;
		}
	}
	return choice;
}
int choiceOfMode() { //возвращает номер режима и делает проверку на ввод
	int choice;
	printf("Выберите нужный режим работы\n");
	printf("1.Однократный расчет функции в заданной точке\n2.Серийный эксперимент\n");
	int z = 1;
	while (z != 0) { //проверка на неверно введенный пункт меню
		scanf_s("%i", &choice);
		if (choice > 2 || choice < 1) {
			printf("Такого нет в меню. Выберите заново!\n");
			z = 1;
		}
		else {
			z = 0;
		}
	}
	return choice;
}