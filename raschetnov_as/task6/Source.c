#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include "header_functions.h" 

void main()
{
	int amount;
	double number;
	int choice;
	int counter = 0;
	int menuChoice = 1;
	int modechoice;
	double infelicity = -1;
	void (*pointer_to_functions[5])(double*, int*, double*, int*) = { exponent, sine, cosine, squareRoot, arctg };
	while(menuChoice != 0)
	{
	  modeChoicer(&modechoice, &choice, &counter);
	  counter++;
	  pointer_to_functions[choice - 1](&number, &amount, &infelicity, &modechoice);
	  menuFunction(&menuChoice);
	}
}