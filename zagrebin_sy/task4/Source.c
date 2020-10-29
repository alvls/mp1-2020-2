#include <stdio.h>
#define SIZE 4

int codes[SIZE] = { 1234, 4321, 234, 1515};
char names[SIZE][10] = { "9 eggs " , "milk ", "bread ", "apple " };
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
		printf("%s count:%.2lf  price : %.2lf \n",names[i], discounts[i], prices[i] * (1-discounts[i]));
	}
	else
		printf("No such item \n");
}

void main() {
	int code;

	printf("Welcome to Pyatorochka \nType -1 to exit \n");
	scanf_s("%d", &code);
	while (code != -1) {
		info(code);
		scanf_s("%d", &code);
	}

	printf("Your bill: \n");
	for (int i = 0; i < SIZE; i++)
		if (purchase[i] != 0)
		printf("%s price: %.2lf  count: %d  full price: %.2lf\n", names[i], prices[i] * (1-discounts[i]), purchase[i], prices[i] * (1 - discounts[i])* purchase[i]);
	printf("Total: full price: %.2lf  discount: %.2lf  to pay: %.2lf", bill, discount, bill-discount);
	scanf_s("%d", &code);
}
