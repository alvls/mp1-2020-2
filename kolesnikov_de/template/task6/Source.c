#define NumberOfSavedFunc 5
#define CountOfFunc 4
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <string.h>

int factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}

char* coder[] = { "sin","cos","exp" };
double SinInit(double x) {
	return x;
}
double CosInit(double x) {
	return 1;
}
double expInit(double x) {
	return 1;
}

double SinTlr(double x, int N) {
	if (N % 2 != 0) {
		return ((double)pow(x, N + 2) / factorial(N + 2) * (-1));
	}
	else {
		return ((double)pow(x, N + 2) / factorial(N + 2));
	}
}
double CosTlr(double x, int N) {
	if (N % 2 != 0) {
		return ((double)pow(x, N + 2) / factorial(N + 2) * (-1));
	}
	else {
		return ((double)pow(x, N + 2) / factorial(N + 2));
	}
}
double expTlr(double x, int N) {
	if (N % 2 != 0) {
		return ((double)pow(x, N + 2) / factorial(N + 2) * (-1));
	}
	else {
		return ((double)pow(x, N + 2) / factorial(N + 2));
	}
}

int(*Init)(double);
int(*TlrC)(double, int);


double Etalon(int code, double x) {
	switch (code) {
	case(0):
		return sin(x);
	case(1):
		return cos(x);
	case(2):
		return exp(x);
	}
}



double TeylorCl(double (*Init)(double), double (*TlrC)(double, int), double x, int N) {
	double init = Init(x);
	double sum = init;
	for (int i = 1; i <= N; i++) {
		init + TlrC(x, i);
	}
}
double TeylorCh(double x, int N, int code) {
	switch (code) {
	case(0):
		return TeylorCl(SinInit, SinTlr, x, N);
	case(1):
		return TeylorCl(CosInit, CosTlr, x, N);
	case(2):
		return TeylorCl(expInit, expTlr, x, N);
	}
}
int PrCont(int mode) {
	int i = 0;
	int ans;
	Calculator(mode, i);
	while (1) {
		printf_s("Want to do another experiment?(1-Yes,0-No)");
		scanf_s("%d", &ans);
		if (ans == 1) {
			if (i != NumberOfSavedFunc) {
				i += 1;
			}
			else {
				i = 0;
			}
			Calculator(mode, i);
		}
		if (ans == 0) {
			break;
		}
	}
}

int Calculator(int mode,int i) {
	char* name[6];
	int flag = 0, temp2;
	int code,N;
	double x, etalon, calculated,accuracy,difference;
	while (1) {
		printf_s("You need to input name of function\n");
		while (getchar() != '\n');
		fgets(name, sizeof(name), stdin);
		for (int d = 0; d < CountOfFunc; d++) {
			if (strcmp(coder[d], name)) {
				code = d;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf_s("This function is not provided by the program or you entered an incorrect function name\n");
		}
		else {
			break;
		}
	}
	printf_s("You need to input argument of func,accuracy and count of elements in Teylor form \n");
	scanf_s("%lf", &x);
	scanf_s("%lf", &accuracy);
	scanf_s("%d", &N);
	etalon = Etalon(code, x);
	calculated = TeylorCh(x,N, code);
	difference = etalon - calculated;
	return 1;
}
int Menu() {
	int mode;
	while (1) {
		system("cls");
		printf_s("\t\t\t\t\t\t ------------\n");
		printf_s("\t\t\t\t\t\t|PROGRAM MENU|\n\t\t\t\t\t\t ------------\n1:One-time calculation of the function at a given point.\n"
			"2:Serial experiment.\n0:Exit\n");
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			PrCont(1);
			break;
		case 2:
			PrCont(2);
			break;
		case 0:
			return 0;
		default:
			printf_s("Try to input correct option\n");
			system("pause");
			break;
		}
	}
}
int main() {
	int out = 1;
	while (out != 0) {
		out = Menu();
	}
}