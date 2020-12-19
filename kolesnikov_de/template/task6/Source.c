#define NumberOfSavedFunc 5
#define CountOfFunc 4
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define FuncNameLen 6
int countT = 1;

char* coder[] = { "sin","cos","exp","ctg" };
double SinInit(double x) {
	return x;
}
double CosInit(double x) {
	return 1;
}
double expInit(double x) {
	return 1;
}
double ctgInit(double x) {
	return (1/x);
}

double SinTlr(double x, int N,double pr) {
	double temp1 = pr * x * x;
	int ran = 2 * N;
	double temp2 = temp1 / (ran - 2);
	double temp3 = (temp2 / (ran-1));
	if ((N-1) % 2 != 0) {
		return -temp3;
	}
	else {
		return temp3;
	}
}
double CosTlr(double x, int N, double pr) {
	double temp1 = pr * x * x;
	int ran = 2 * N;
	double temp2 = temp1 / (ran - 2);
	double temp3 = (temp2 / (ran - 3));
	if ((N-1) % 2 == 0) {
		return temp3;
	}
	else {
		return -temp3;
	}
}
double expTlr(double x, int N, double pr) {
	double temp1 = pr * x;
	double temp3 = (temp1 / (N-1));
	return temp3;
}
double ctgTlr(double x, int N, double pr) {
	double temp1 = pr * x;
	double temp3 = (temp1 / (N - 1));
	return temp3;
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
	case(4):
		return (cos(x) / sin(x));
	}
}


void TeylorCl(double (*Init)(double), double (*TlrC)(double, int), double x, int N, double accuracy,double etalon,int mode,double CalcT2[]) {
	double sum = Init(x);
	double pr=sum;
	double temp1;
	int i = 2;
	if (mode == 2) {
		CalcT2[0] = sum;
	}
	while (fabs(sum - etalon) > accuracy) {
		temp1= TlrC(x, i, pr);
		sum += temp1;
		pr = fabs(temp1);
		if (mode == 2) {
			CalcT2[(i-1)] = sum;
		}
		i += 1;
		if (i >= N) {
			break;
		}
	}
	countT = i;
	if (mode == 1) {
		CalcT2[0] = sum;
	}
}
void TeylorCh(double x, int N, int code,double accuracy,double etalon,int mode,double CalcT2[]) {
	switch (code) {
	case(0):
		TeylorCl(SinInit, SinTlr, x, N,accuracy,etalon,mode,CalcT2);
		break;
	case(1):
		TeylorCl(CosInit, CosTlr, x, N, accuracy,etalon,mode,CalcT2);
		break;
	case(2):
		 TeylorCl(expInit, expTlr, x, N, accuracy,etalon,mode,CalcT2);
		 break;
	case(3):
		TeylorCl(ctgInit, ctgTlr, x, N, accuracy, etalon, mode, CalcT2);
		break;
	}
}
int PrCont(int mode) {
	int i = 0;
	int ans;
	Calculator(mode, i);
	while (1) {
		printf_s("Want to do another experiment?(1-Yes,0-No)\n");
		scanf_s("%d", &ans);
		if (ans == 1) {
			if (i != NumberOfSavedFunc) {
				i += 1;
			}
			else {
				i = 0;
			}
			Calculator(mode);
		}
		if (ans == 0) {
			break;
		}
	}
}
void ShowInfo(double etalon, double x, int N,char name[],double Result[],int mode) {
	printf_s("Name of your func is = %s\n", name);
	printf_s("Etalon value is %lf\n", etalon);
	if (mode == 1) {
		printf_s("Calculated value is %lf\n", Result[0]);
		printf_s("For calculating used %d elements in Teylor form\n", countT);
	}
	if (mode == 2) {
		printf_s("Count of Teylor form elsements\r\t\t\t\tResult\n");
		for (int i = 1; i < countT; i++) {
			printf_s("%d\r\t\t\t\t\t %lf\n",i, Result[i-1]);
		}
		
	}
	printf_s("In point %lf\n", x);
}
int Calculator(int mode) {
	char name[FuncNameLen];
	int flag = 0, temp2;
	int code,N;
	double x, etalon, calculated,accuracy,difference;
	while (1) {
		printf_s("You need to input name of function\n");
		while (getchar() != '\n');
		fgets(name, sizeof(name), stdin);
		for (int i = 0; i < FuncNameLen; i++) {
			if (name[i] == '\n') {
				name[i] = 0;
				break;
			}
		}
		for (int d = 0; d < CountOfFunc; d++) {
			if (strcmp(coder[d], name)==0) {
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
	if (mode == 2) {
		double* CalcT2 = (double*)malloc(sizeof(double) * N);
		TeylorCh(x, N, code, accuracy, etalon, mode, CalcT2);
		ShowInfo(etalon, x, N, name, CalcT2,mode);
		free(CalcT2);
	}
	if (mode == 1) {
		double* CalcT2 = (double*)malloc(sizeof(double));
		TeylorCh(x, N, code, accuracy, etalon, mode, CalcT2);
		ShowInfo(etalon,x, N, name, CalcT2,mode);
		free(CalcT2);
	}
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