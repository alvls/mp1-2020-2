#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include "header_functions.h" 

void main()
{
	int amount;
	double number;
	int choice;
	int modechoice;
	double infelicity = 0;
	void (*pointer_to_functions[5])(double*, int*, double*, int*) = { exponent, sine, cosine, squareRoot, arctg };
	modeChoicer(&modechoice, &choice);
	pointer_to_functions[choice - 1](&number, &amount, &infelicity, &modechoice);
}