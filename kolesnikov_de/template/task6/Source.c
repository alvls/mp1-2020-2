#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "windows.h"
#include "Func.h"
#define FuncNameLen 6
#define CountOfFunc 4
int countT = 1; //count of elements in teylor form


extern char* coder[];
extern char* WarningM[];

int(*Init)(double);
int(*TlrC)(double, int);


void TeylorCl(double (*Init)(double), double (*TlrC)(double, int), double x, int N, double accuracy,double etalon,int mode,double CalcT2[],double CalcAc[]) {
	double sum = Init(x);
	double pr=sum;
	double temp1;
	double temp2;
	int i = 2;
	if (mode == 2) {
		CalcT2[0] = sum;
		CalcAc[0] = fabs(sum - etalon);
	}
	while (i <= N) {
		if (mode == 1) {
			if (fabs(sum - etalon) <= accuracy) {
				break;
			}
		}
		temp1= TlrC(x, i, pr);
		sum += temp1;
		pr = fabs(temp1);
		if (mode == 2) {
			CalcT2[(i-1)] = sum;
			CalcAc[(i-1)] = fabs(sum - etalon);
		}
		i += 1;
	}
	countT = i;
	if (mode == 1) {
		CalcT2[0] = sum;
		CalcAc[0] = fabs(sum - etalon);
	}
}
void TeylorCh(double x, int N, int code,double accuracy,double etalon,int mode,double CalcT2[], double CalcAc[]) {
	switch (code) {
	case(0):
		TeylorCl(SinInit, SinTlr, x, N,accuracy,etalon,mode,CalcT2,CalcAc);
		break;
	case(1):
		TeylorCl(CosInit, CosTlr, x, N, accuracy,etalon,mode,CalcT2,CalcAc);
		break;
	case(2):
		 TeylorCl(expInit, expTlr, x, N, accuracy,etalon,mode,CalcT2, CalcAc);
		 break;
	case(3):
		TeylorCl(ctgInit, ctgTlr, x, N, accuracy, etalon, mode, CalcT2, CalcAc);
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
			Calculator(mode);
		}
		if (ans == 0) {
			break;
		}
	}
}
void ShowInfo(double etalon, double x, int N,char name[],double Result[],int mode, double CalcAc[]) {
	system("cls");
	printf_s("Name of your func is = %s\n", name);
	printf_s("Etalon value is %lf\n", etalon);
	if (mode == 1) {
		printf_s("Calculated value is %lf\n", Result[0]);
		printf_s("For calculating used %d elements in Teylor form\n", countT);
		printf_s("The accuracy is %lf\n", CalcAc[0]);

	}
	if (mode == 2) {
		printf_s("Count of Teylor form elements\r\t\t\t\t\tResult\r\t\t\t\t\t\t\tAccuracy\n");
		for (int i = 1; i < countT; i++) {
			printf_s("%d\r\t\t\t\t\t%lf\r\t\t\t\t\t\t\t%lf\n",i, Result[i-1],CalcAc[i-1]);
		}
		
	}
	printf_s("In point %lf\n", x);
}
void Warning(int code) {
	printf_s("%s", WarningM[code]);
}
int Calculator(int mode) {
	char name[FuncNameLen];
	int flag = 0, temp2;
	int code,N;
	double x, etalon, calculated,accuracy=0,difference;
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
	Warning(code);
	if (mode == 1) {
		printf_s("You need to input argument of func,accuracy and count of elements in Teylor form \n");
	}
	if (mode == 2) {
		printf_s("You need to input argument of func and count of elements in Teylor form \n");
	}
	scanf_s("%lf", &x);
	if (mode == 1) {
		scanf_s("%lf", &accuracy);
	}
	printf_s("Remeber, count is only integer!\n");
	scanf_s("%d", &N);
	etalon = Etalon(code, x);
	if (mode == 2) {
		double* CalcT2 = (double*)malloc(sizeof(double) * N);
		double* CalcAc = (double*)malloc(sizeof(double) * N);
		TeylorCh(x, N, code, accuracy, etalon, mode, CalcT2,CalcAc);
		ShowInfo(etalon, x, N, name, CalcT2,mode, CalcAc);
		free(CalcT2);
		free(CalcAc);
	}
	if (mode == 1) {
		double* CalcT2 = (double*)malloc(sizeof(double));
		double* CalcAc = (double*)malloc(sizeof(double));
		TeylorCh(x, N, code, accuracy, etalon, mode, CalcT2, CalcAc);
		ShowInfo(etalon,x, N, name, CalcT2,mode, CalcAc);
		free(CalcT2);
		free(CalcAc);
	}
	return 1;
}
int Menu() {
	int mode;
	printf_s("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf_s("\t\t\t\tThis program performs the expansion in a Maclaurin series\n");
	printf_s("\t\t\t\t\t\tLet`s get started!");
	Sleep(3000);
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