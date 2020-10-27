#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void main() {
	srand(time(NULL));

	int arr[5] = {-1,-1,-1,-1,-1};
	int n=0, x, found;
	char c;
	int i, j, att = 0;

	int e[5];
	int en;

	int cows, bulls = 0;


	while (n < 2 || n>5) {//get length
		printf("Enter number between 2 and 5 \n");
		scanf_s("%d", &n);
	}

	for (i = 0; i < n; i++) {//generate number
		do {//find if already used
			found = 0;
			x = rand() % 10;
			for (j = 0; j < n; j++)
				if (arr[j] == x)
					found = 1;
		} while (found);
		arr[i] = x;
	}

	while (bulls != n) {
		bulls = 0;
		cows = 0;
		att++;
		printf("Enter your number \n");//get user number
		while (c = getchar() != '\n');
		scanf_s("%d", &en);
		for (i = n - 1; i >= 0; i--) {
			e[i] = en % 10;
			en /= 10;
		}

		for (i = 0; i < n; i++) {//find coincidences
			for (j = 0; j < n; j++)
				if (arr[j] == e[i]) {
					if (i == j) {
						bulls++;
					}
					else {
						cows++;
					}
				}
		}
		printf("You got %d cows and %d bulls \n", cows, bulls);
	}
	printf("Finally you win. You spent %d attempts \n", att);
	scanf_s("%d", &x);
}
