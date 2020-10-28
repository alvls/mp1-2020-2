#include <stdio.h>
#define SIZE 4

int codes[SIZE]= { 1234, 4321, 234, 1515};
double prices[SIZE] = { 99, 65, 35, 100 };
double discounts[SIZE] = { 0.15, 0.1, 0, 0.15 };
char purchase[SIZE] = {0};
double bill = 0;
double discount = 0;

void info(int code) {
	int res = 0;
	int i;
	for (i = 0; i < SIZE; i++) {
		if (codes[i] == code) {
			res = 1;
			purchase[i]++;
			bill += prices[i];
			discount += discounts[i] * prices[i];
			break;
		}
	}	
	if (res == 1) {
		switch (i) {
		case 0:
			printf("9 eggs ");
			break;
		case 1:
			printf("milk ");
			break;
		case 2:
			printf("bread ");
			break;
		case 3:
			printf("apple ");
			break;
		}
		printf("discount:%.2lf  price : %.2lf \n", discounts[i], prices[i] * (1-discounts[i]));
	}
	else
		printf("No such item \n");
}

void main() {
	int code;

	printf("Welcome to Pyatorochka \nType 0 to exit \n");
	scanf_s("%d", &code);
	while (code) {
		info(code);
		scanf_s("%d", &code);
		
	}

	printf("Your bill: \n");
	for (int i = 0; i < SIZE; i++)
		if (purchase[i] != 0) {
			switch (i) {
			case 0:
				printf("9 eggs ");
				break;
			case 1:
				printf("milk ");
				break;
			case 2:
				printf("bread ");
				break;
			case 3:
				printf("apple ");
				break;
			}
		printf("price: %.2lf  count: %d  full price: %.2lf\n", prices[i] * (1-discounts[i]), purchase[i], prices[i] * (1 - discounts[i])* purchase[i]);
		}
	printf("Total: full price: %.2lf  discount: %.2lf  to pay: %.2lf", bill, discount, bill-discount);
	scanf_s("%d", &code);
}
