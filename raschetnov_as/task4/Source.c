#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
char* shopProducts[] = { "Milk", "Bread", "Cookies", "Butter", "Tea", "Candies", "Coffee", "Eggs", "Oranges", "Apples", "Cabbage" };
char* weekDays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int weekday = 0;
int q, c;
double shopSum = 0;
int number = INT_MIN;
int i;
void checkWeekdays()
{
	printf("\t\t\t\t\t\t\tWrong symbol or number is out of range, try again\n");
	printf("\t\t\t\t\t\t\tEnter today's day of week:\n");
	while ((c = getchar()) != '\n' && c != EOF);
	{
		printf("\t\t\t\t\t\t\t");
		q = scanf("%d", &weekday);
	}
}

void checkBarcodes()
{
	printf("\t\t\t\t\t\t\tWrong symbol, try again\n");
	printf("\t\t\t\t\t\t\tEnter barcode of the product or 0 to quit:\n");
	while ((c = getchar()) != '\n' && c != EOF);
	{
		printf("\t\t\t\t\t\t\t");
		q = scanf("%d", &number);
	}
}

void weekdaysList(int days[])
{
	int i;
	for(i = 0; i < 7; i++)
	  printf("\t\t\t\t\t\t\t%d stands for %s\n ", days[i], weekDays[i]);
}

void weekdaysFunction(int days[])
{
	int errorchecker = 0;
	weekdaysList(days);
	printf("\t\t\t\t\t\t\tEnter today's day of week:\n");
	printf("\t\t\t\t\t\t\t");
	q = scanf("%d", &weekday);
	while (q != 1 || weekday > 6 || weekday < 0)
	{
		checkWeekdays();
	}
	printf("\n");
	for (i = 0; i < 7; i++)
		if (weekday == days[i])
		{
			errorchecker = 1;
		}
	if (errorchecker == 1)
	{
		printf("\t\t\t\t\t\t\tToday is %s.\n", weekDays[weekday]);
		q = 0;
	}
}

void discountsList()
{
	switch (weekday)
	{
	case 0:
	{
		printf("\t\t\t\t\t\t\tMilk 20%% off, Cabbage 15%% off, Coffee 5%% off.\n");
		break;
	}

	case 1:
	{
		printf("\t\t\t\t\t\t\tIf you buy 2 coffee 1 more coffee for free.\n");
		break;
	}
	case 2:
	{
		printf("\t\t\t\t\t\t\tIf you buy products for more then 50$ you will get 10$ discount.\n");
		break;
	}
	case 3:
	{
		printf("\t\t\t\t\t\t\tEggs 20%% off, Apples 15%% off.\n");
		break;
	}
	case 4:
	{
		printf("\t\t\t\t\t\t\tIf you buy oranges you get apples for free(for one orange you will get one apple).\n");
		break;
	}
	case 5:
	{
		printf("\t\t\t\t\t\t\tCandies 10%% off, Cookies 10%% off, Tea 10%% off.\n");
		break;
	}
	case 6:
	{
		printf("\t\t\t\t\t\t\tBread 15%% off, Butter 5%% off.\n");
		break;
	}
	}
}

void productsList(int productsArray[], int priceArray[] )
{
	int i;
	printf("\t\t\t\t\t\t\tThere is a list of products we own in our shop.\n");
	printf("\t\t\t\t\t\t\tAlso, theres is a list of discounts for today:\n");
	printf("\n");
	discountsList();
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t\t\tChoose products by entering their barcodes using a table below:\n");
	printf("\n");
	for(i = 0; i < 10; i++)
	  printf("\t\t\t\t\t\t\t%d stands for %s\t\t%d$\n", productsArray[i], shopProducts[i], priceArray[i]);
}


int discounts(int countArray[], int priceArray[])
{
	switch (weekday)
	{
	case 0:
	{
		if (countArray[10] != 0)
			shopSum -= countArray[10] * priceArray[10] * 0.15;
		if (countArray[0] != 0)
			shopSum -= countArray[0] * priceArray[0] * 0.2;
		if (countArray[6] != 0)
			shopSum -= countArray[6] * priceArray[6] * 0.05;
		return shopSum;
		break;
	}
	case 1:
	{
		if (countArray[6] >= 2)
			countArray[6] += countArray[6] / 2;
		return countArray[6];
		break;
	}
	case 2:
	{
		if (shopSum >= 50)
			shopSum -= 10;
		return shopSum;
		break;
	}
	case 3:
	{
		if (countArray[7] != 0)
			shopSum -= countArray[7] * priceArray[7] * 0.2;
		if (countArray[9] != 0)
			shopSum -= countArray[9] * priceArray[9] * 0.15;
		break;
	}
	return shopSum;
	case 4:
	{
		if (countArray[8] != 0)
			countArray[9] += countArray[8];
		return countArray[9];
		break;
	}
	case 5:
	{
		if (countArray[2] != 0)
			shopSum -= countArray[2] * priceArray[2] * 0.1;
		if (countArray[5] != 0)
			shopSum -= countArray[5] * priceArray[5] * 0.1;
		if (countArray[4] != 0)
			shopSum -= countArray[4] * priceArray[4] * 0.1;
		return shopSum;
		break;
	}
	case 6:
	{
		if (countArray[1] != 0)
			shopSum -= countArray[1] * priceArray[1] * 0.15;
		if (countArray[3] != 0)
			shopSum -= countArray[3] * priceArray[3] * 0.05;
		return shopSum;
		break;
	}
	}
}

void printFunction(int countArray[], int priceArray[])
{
	int count = 0;
	printf("\t\t\t\t\t\t\tTotal list of products:\n");
	printf("\n");
	for (i = 0; i < 11; i++)
	{
		if (countArray[i] != 0)
		{
			printf("\t\t\t\t\t\t\t%s..........................x%d\n", shopProducts[i], countArray[i]);
		}
		if (countArray[i] == 0)
		{
			count++;
		}
	}
	printf("\n");
	printf("\t\t\t\t\t\t\tTotal sum of the products: %.2lf$", shopSum);
	printf("\n");
	if (count == 11)
		printf("\t\t\t\t\t\t\tYou didn't choose anything!");
}
void main()
{
	int exitProgram = 1;
	int days[] = { 0, 1, 2, 3, 4, 5, 6 };
	int productsArray[] = { 1235, 3452, 6782, 3257, 9945, 2140, 3360, 5429, 1239, 9510, 4285 };
	int priceArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int countArray[11];
while(exitProgram != 0)
{
	shopSum = 0;
	number = 1;
	weekdaysFunction(days);
	productsList(productsArray, priceArray);
	for (i = 0; i < 11; i++)
		countArray[i] = 0;
	while (number != 0)
	{
		printf("\t\t\t\t\t\t\tEnter barcode of the product ot press 1 to see the list of products again or 0 to finish your shopping:\n");
		printf("\t\t\t\t\t\t\t");
		q = scanf("%d", &number);
		while (q != 1)
		{
			checkBarcodes();
		}
		q = 0;
		printf("\n");
		for (i = 0; i < 11; i++)
			if (number == productsArray[i])
			{
				printf("\t\t\t\t\t\t\tProduct added to your cart: %s\n", shopProducts[i]);
				printf("\t\t\t\t\t\t\tPrice of the product: %d$\n", priceArray[i]);
				countArray[i]++;
				shopSum += priceArray[i];
				printf("\t\t\t\t\t\t\tTotal price: %.2lf$\n", shopSum);
				break;
			}
		if (number == 1)
			productsList(productsArray, priceArray);
		if (number != 0 && number != productsArray[i])
			printf("\t\t\t\t\t\t\tProduct wasn't found\n");
	}
	discounts(countArray, priceArray);
	printFunction(countArray, priceArray);
	printf("\t\t\t\t\t\t\tPress 1 to work with program or 0 to exit");
	scanf("%d", &exitProgram);
}
}
