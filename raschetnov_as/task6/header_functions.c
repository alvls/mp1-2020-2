#define _CRT_SECURE_NO_WARNINGS
#include "header_functions.h"
#include <stdio.h>
#include <math.h>

void numberCheckerNoRestrictions(double* number)
{
	int checker = 0;
	int c;
	printf("Enter function point:\n");
	checker = scanf("%lf", number);
	while (checker != 1)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("Enter function point:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%lf", number);
		}
	}
}

void modeChoicer(int* modechoice, int* choice)
{
	printf("This program is supposed to find function value in some point using Taylor's series for that.\n");
	printf("Program has 2 modes:\n\n");
	printf("Mode 1: You have to enter point you want to find function value in, number of elements in Taylor's series and infelecity between reference and evaluation (evalution will be found by Taylor's series).\n\n");
	printf("Mode 2: You have to enter point you want to find function value in and number of elements in Taylor's series between 1 and 25.\n\n");
	printf("In mode 1 you will receive reference of function value, evaluation, difference between reference and evaluation, number of elements in Taylor's series that were used (if infelecity you entered was reacdhed before number of elements in Taylor's series are gone).\n\n");
	printf("In mode 2 you will receive evaluation of function value and spreadsheet that contains these columns: number of elements in talor's series, evaluation of function value, difference between reference and evaluation on each step of Talor's series.\n\n");
	modeChoicerInputControl(modechoice);
	menuChoicer(choice);
}

void modeChoicerInputControl(int* modechoice)
{
	int checker = 0;
	int c;
	printf("Choose program mode:\n");
	checker = scanf("%d", modechoice);
	while (checker != 1 || *modechoice < 1 || *modechoice > 2)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("Choose program mode:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%d", modechoice);
		}
	}
}

void amountCheckerNoRestrictions1(int* amount)
{
	int checker = 0;
	int c;
	printf("Enter amount of sum elements in range of 1 to 1000:\n");
	checker = scanf("%d", amount);
	while (checker != 1 || *amount < 1 || *amount > 1000)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("Enter amount of sum elements in range of 1 to 1000:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%d", amount);
		}
	}
}

void amountCheckerNoRestrictions2(int* amount)
{
	int checker = 0;
	int c;
	printf("Enter amount of sum elements in range of 1 to 25:\n");
	checker = scanf("%d", amount);
	while (checker != 1 || *amount < 1 || *amount > 25)
	{
		printf("You entered wrong symbol, try again\n");
		printf("Enter amount of sum elements in range of 1 to 25:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%d", amount);
		}
	}
}

void infelicityCheckerNoRestrictions(double* infelicity)
{
	int checker = 0;
	int c;
	printf("Enter enfelecity:\n");
	checker = scanf("%lf", infelicity);
	while (checker != 1 || *infelicity < 0.000001)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("Enter enfelecity:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%lf", infelicity);
		}
	}
}

void numberCheckerAbsLessThenOneOrSame(double* number)
{
	int checker = 0;
	int c;
	printf("Enter function point in range of |point| <= 1:\n");
	checker = scanf("%lf", number);
	while (checker != 1 || *number > 1 || *number < -1)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("Enter function point in range of |point| <= 1:\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%lf", number);
		}
	}
}

void printOutputMode1(double sum, double i, double reference)
{
	printf("\n");
	printf("Reference: %lf\n", reference);
	printf("Number of elements in a sum: %.0lf\n", i);
	printf("Evaluation: %lf\n", sum);
	printf("Difference: %lf\n", fabs(reference - sum));
}

void printOutputMode2(double sum, double i, double reference, int printcounter)
{
	if (printcounter == 0)
	{
		printf("\nNumber of elements in a sum		Evaluation		Difference\n");
		printf("---------------------------		----------		----------\n");
	}
	printf("%-40.0lf", i);
	printf("%-24lf", sum);
	printf("%lf\n", fabs(reference - sum));
}
void menuChoicer(int* choice)
{
	int i;
	int size;
	char* functions[] = { "exp(x)", "sin(x)", "cos(x)", "(1+x)^1/2", "arctg(x)" };
	size = sizeof(functions) / sizeof(char*);
	for (i = 0; i < size; i++)
		printf("%d.%s\n", i + 1, functions[i]);
	printf("\n");
	menuChoicerInputControl(choice);
}

void menuChoicerInputControl(int* choice)
{
	int checker = 0;
	int c;
	printf("What function do you need ?\n");
	checker = scanf("%d", choice);
	while (checker != 1 || *choice < 1 || *choice > 5)
	{
		printf("You entered wrong symbol, try again:\n");
		printf("What function do you need ?\n");
		while ((c = getchar()) != '\n' && c != EOF);
		{
			checker = scanf("%d", choice);
		}
	}
}


void arctg(double* number, int* amount, double* infelicity, int* modechoice)
{
	double i;
	double sequenceBegginer;
	double sum;
	int printcounter = 0;
	double reference;
	numberCheckerAbsLessThenOneOrSame(number);
	if (*modechoice == 1)
		amountCheckerNoRestrictions1(amount);
	else
		amountCheckerNoRestrictions2(amount);
	if (*modechoice == 1)
		infelicityCheckerNoRestrictions(infelicity);
	sequenceBegginer = *number;
	sum = *number;
	reference = atan(*number);
	if (*modechoice == 2)
		printOutputMode2(sum, 1, reference, printcounter);
	for (i = 1; i < *amount && fabs(reference - sum) >= *infelicity; i++)
	{
		sequenceBegginer = sequenceBegginer * (-(*number * *number) * (2 * i - 1) / (2 * i + 1));
		sum += sequenceBegginer;
		if (*modechoice == 2)
		{
			printcounter++;
			printOutputMode2(sum, i + 1, reference, printcounter);
		}
	}
	if (*modechoice == 1)
		printOutputMode1(sum, i, reference);
}

void squareRoot(double* number, int* amount, double* infelicity, int* modechoice)
{
	double i;
	double sequenceBegginer = 1;
	double sum = 1;
	int printcounter = 0;
	double reference;
	numberCheckerAbsLessThenOneOrSame(number);
	if (*modechoice == 1)
		amountCheckerNoRestrictions1(amount);
	else
		amountCheckerNoRestrictions2(amount);
	if (*modechoice == 1)
		infelicityCheckerNoRestrictions(infelicity);
	reference = sqrt(1 + *number);
	if (*modechoice == 2)
		printOutputMode2(sum, 1, reference, printcounter);
	for (i = 1; i < *amount && fabs(reference - sum) >= *infelicity; i++)
	{
		sequenceBegginer = sequenceBegginer * (*number * (3 - 2 * i) / (2 * i));
		sum += sequenceBegginer;
		if (*modechoice == 2)
		{
			printcounter++;
			printOutputMode2(sum, i + 1, reference, printcounter);
		}
	}
	if (*modechoice == 1)
		printOutputMode1(sum, i, reference);
}

void cosine(double* number, int* amount, double* infelicity, int* modechoice)
{
	double i;
	double sequenceBegginer = 1;
	double sum = 1;
	int printcounter = 0;
	double reference;
	numberCheckerNoRestrictions(number);
	if (*modechoice == 1)
		amountCheckerNoRestrictions1(amount);
	else
		amountCheckerNoRestrictions2(amount);
	if (*modechoice == 1)
		infelicityCheckerNoRestrictions(infelicity);
	reference = cos(*number);
	if (*modechoice == 2)
		printOutputMode2(sum, 1, reference, printcounter);
	for (i = 1; i < *amount && fabs(reference - sum) >= *infelicity; i++)
	{
		sequenceBegginer = sequenceBegginer * (-(*number * *number) / (2 * i * (2 * i - 1)));
		sum += sequenceBegginer;
		if (*modechoice == 2)
		{
			printcounter++;
			printOutputMode2(sum, i + 1, reference, printcounter);
		}
	}
	if (*modechoice == 1)
		printOutputMode1(sum, i, reference);
}

void sine(double* number, int* amount, double* infelicity, int* modechoice)
{
	double i;
	double sequenceBegginer;
	double sum;
	int printcounter = 0;
	double reference;
	numberCheckerNoRestrictions(number);
	if (*modechoice == 1)
		amountCheckerNoRestrictions1(amount);
	else
		amountCheckerNoRestrictions2(amount);
	if (*modechoice == 1)
		infelicityCheckerNoRestrictions(infelicity);
	sequenceBegginer = *number;
	sum = *number;
	reference = sin(*number);
	if (*modechoice == 2)
		printOutputMode2(sum, 1, reference, printcounter);
	for (i = 1; i < *amount && fabs(reference - sum) >= *infelicity; i++)
	{
		sequenceBegginer = sequenceBegginer * (-(*number * *number) / (2 * i * (2 * i + 1)));
		sum += sequenceBegginer;
		if (*modechoice == 2)
		{
			printcounter++;
			printOutputMode2(sum, i + 1, reference, printcounter);
		}
	}
	if (*modechoice == 1)
		printOutputMode1(sum, i, reference);
}

void exponent(double* number, int* amount, double* infelicity, int* modechoice)
{
	int i;
	double sequenceBegginer = 1;
	double sum = 1;
	int printcounter = 0;
	double reference;
	numberCheckerNoRestrictions(number);
	if (*modechoice == 1)
		amountCheckerNoRestrictions1(amount);
	else
		amountCheckerNoRestrictions2(amount);
	if (*modechoice == 1)
		infelicityCheckerNoRestrictions(infelicity);
	reference = exp(*number);
	if (*modechoice == 2)
		printOutputMode2(sum, 1, reference, printcounter);
	for (i = 1; i < *amount && reference - sum >= *infelicity; i++)
	{
		sequenceBegginer = sequenceBegginer * *number / i;
		sum += sequenceBegginer;
		if (*modechoice == 2)
		{
			printcounter++;
			printOutputMode2(sum, i + 1, reference, printcounter);
		}
	}
	if (*modechoice == 1)
		printOutputMode1(sum, i, reference);
}