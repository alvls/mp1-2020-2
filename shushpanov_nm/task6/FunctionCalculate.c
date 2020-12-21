#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double FunctionBernoulli(int n);
double FunctionBink(long int i, long int j);
long int FunctionFactorial(long int x);

double FunctionSin(long int numberOfElements, double x, double referenceValue, double calculationAccuracy)
{
	int i;
	double function = x, term = x;
	for (i = 2; (i <= numberOfElements) && (fabs(x - referenceValue) > calculationAccuracy); i++)
	{
		term *= (-1) * x * x / ((2 * i) * (2 * i - 1));
		function += term;
	}
	printf("%10d %33.10lf %28.10lf\n", i - 1, function, fabs(referenceValue - function));
}

double FunctionCos(long int numberOfElements, double x, double referenceValue, double calculationAccuracy)
{
	int i;
	double function = 1, term = 1;
	for (i = 2; (i <= numberOfElements) && (fabs(x - referenceValue) >= calculationAccuracy); i++)
	{
		term *= (-1) * x * x / ((2 * i - 2) * (2 * i - 3));
		function += term;
	}
	printf("%10d %33.10lf %28.10lf\n", i - 1, function, fabs(referenceValue - function));
}

double FunctionExpiration(long int numberOfElements, double x, double referenceValue, double calculationAccuracy)
{
	int i;
	double function = x, term = 1;
	for (i = 2; (i <= numberOfElements) && (fabs(x - referenceValue) >= calculationAccuracy); i++)
	{
		term *= x / (i - 1);
		function += term;
	}
	printf("%10d %33.10lf %28.10lf\n", i - 1, function, fabs(referenceValue - function));
}

double FunctionHyporbolicTangentWithE(long int numberOfElements, double x, double referenceValue, double calculationAccuracy)
{
	int i;
	double function = x, term = 1;
	for(i = 2; (i <= numberOfElements) && (fabs(x - referenceValue) > calculationAccuracy); i++)
	{
		term *= ((exp(2 * x) + 1) / (exp(2 * x) - 1));
		function += term;
	}
	printf("%10d %33.10lf %28.10lf\n", i - 1, function, fabs(referenceValue - function));
}


//Работает странно, долго считает
double FunctionHyporbolicTangentWithBernoulli(long int numberOfElements, double x, double referenceValue, double calculationAccuracy)
{
	int i;
	double function = 1, term = 1, termSum = 0;
	for (i = 2; (i <= numberOfElements) && (fabs(x - referenceValue) > calculationAccuracy); i++)
	{
		term = (pow(2, 2 * i) * (pow(2, 2 * i) - 1) * FunctionBernoulli(2 * i) * pow(x, 2 * i - 1)) / FunctionFactorial(2 * i);
		termSum += term;
	}
	function = sinh(termSum) / cosh(termSum);
	printf("%10d %33.10lf %28.10lf\n", i - 1, function, fabs(referenceValue - function));
}

long int FunctionFactorial(long int x)
{
	if (x == 0 || x == 1)
	{
		return 1;
	}
	else
	{
		return x * FunctionFactorial(x - 1);
	}
}

double FunctionBink(long int i, long int j) 
{
	return 1.0 * FunctionFactorial(i) / FunctionFactorial(j) / FunctionFactorial(i - j);
}

double FunctionBernoulli(int n) 
{
	int j;
	double sum = 0;
	if (n <= 0)
	{
		return 1;
	}
	else 
	{
		for (j = 1; j <= n; j++)
		{
			sum += FunctionBink(n + 1, j + 1) * FunctionBernoulli(n - j);
		}
		return -1.0 / (n + 1) * sum;
	}
}