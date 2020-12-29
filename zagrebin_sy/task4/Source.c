#include <stdio.h>
#define SIZE 5	// number of goods

char* codes[SIZE] =	   { "0000","1234",      "4321",  "0234",   "1515" };
char names[SIZE][10] = { "stop", "9 eggs " , "milk ", "bread ", "apple " };
double prices[SIZE] =  {  0,      99,          65,      35,       100 };
double discounts[SIZE] = { 0,     0.15,        0.1,     0,        0.15 };
char purchase[SIZE] = { 0 };
double bill = 0;
double discount = 0;


int find_item(char* code) {
	int j;
	for (int i = 0; i < SIZE; i++) {
		for (j = 0; j < 4; j++)
			if (code[j] != codes[i][j])
				break;
		if (j == 4)
			return i;
	}
	return -1;
}

void main() {
	char code[5];
	char ñ = 0;
	int res, next = 1;;

	while (next) {
		system("cls");
		printf("Welcome to Pyatorochka\n\n");
		for (int i = 0; i < SIZE; i++)
			printf("%-6.6s - %4.4s\n", names[i], codes[i]);
		
		gets(code);
		res = find_item(code);
		while (res) {
			if (res == -1)
				printf("No such item\n");
			else {
				purchase[res]++;
				bill += prices[res];
				discount += discounts[res] * prices[res];
				printf("%s count:%.2lf  price : %.2lf \n", names[res], discounts[res], prices[res] * (1 - discounts[res]));
			}
			gets(code);
			res = find_item(code);
		};
		system("cls");
		printf("Your bill:\n");
		for (int i = 0; i < SIZE; i++)
			if (purchase[i] != 0)
				printf("%s price: %.2lf  count: %d  full price: %.2lf\n", names[i], prices[i] * (1 - discounts[i]), purchase[i], prices[i] * (1 - discounts[i]) * purchase[i]);
		printf("\nTotal:\nfull price: %.2lf  discount: %.2lf  to pay: %.2lf", bill, discount, bill - discount);
		printf("\nHope to see you soon! Come back!\n");
		printf("\nEnter 0 to turn off the cashbox or any other number to continue\n");
		scanf_s("%d", &next);
	}
	system("pause");
}