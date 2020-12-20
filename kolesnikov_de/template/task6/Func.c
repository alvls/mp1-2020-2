#include <math.h>
const double PI = 3.141592653589793;
char* coder[] = { "sin","cos","exp","ctg" };
char* WarningM[] = { "","","","Number of elements > 12 may cause errors, x in range (-pi;pi)\n" };
//Bernulli numbers alg.


unsigned int fact(int x){
	unsigned int x0 = x;;
	if (x <= 1)
		return 1;
	else {
		unsigned int fact = 1;
		for (; x != 0; x--) {
			fact *= x0;
			x0--;
		}
		return fact;
	}
}
long double Bern(int twiseN) {
	return fact(twiseN) / ((double)pow((2 * PI), twiseN));
}
//Setting functions init data and teylor alg.
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
	return (1 / x);
}



double SinTlr(double x, int N, double pr) {
	double temp1 = pr * x * x;
	int ran = 2 * N;
	double temp2 = temp1 / (ran - 2);
	double temp3 = (temp2 / (ran - 1));
	if ((N - 1) % 2 != 0) {
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
	if ((N - 1) % 2 == 0) {
		return temp3;
	}
	else {
		return -temp3;
	}
}
double expTlr(double x, int N, double pr) {
	double temp1 = pr * x;
	double temp3 = (temp1 / (N - 1));
	return temp3;
}
double ctgTlr(double x, int N, double pr) {
	N--;
	int temp4 = 2 * N;
	double temp1 = (double)pow(x, (temp4 - 1)) * (double)pow(2, temp4) * Bern(temp4);
	double temp3 = (temp1 / fact(temp4));
	if (N == 1) {
		return (-x / 3);
	}
	else {
		return -temp3;
	}

}

double Etalon(int code, double x) {
	switch (code) {
	case(0):
		return sin(x);
	case(1):
		return cos(x);
	case(2):
		return exp(x);
	case(3):
		return ((double)cos(x) / (double)sin(x));
	}
}
