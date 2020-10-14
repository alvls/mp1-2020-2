#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void main() {
	srand(time(NULL)); 
	int mod, n, x, i, a, min, max; 
	char c;

	printf("Chose mod (1,2): \n");
	scanf_s("%d", &mod);

	a = 0;//Number of attempts
	i = 1;//i = 0 means win

	if (mod == 1) {
		n = rand() % 1000 + 1; //generate number
		while (i) {
			printf("Your \n");
			scanf_s("%d", &x);
			i = (x < n) ? -1 : (x > n) ? 1 : 0; //classify answer
			switch (i) {
			case -1:
				printf("Too small \n");
				break;
			case 0:
				printf("Exactly \n");
				break;
			case 1:
				printf("Too big \n");
				break;
			}
			a++;
		}
	}
	else {
		printf("Chose number from 1 to 1000 \n");
		min = 1; max = 1000; c = ' ';

		while (c != '=') {
			n = rand() % (max - min + 1) + min;//Generate number from min to max
			printf("Your number is %d ?\n", n);;

			while (c = getchar() != '\n');//clear thread
			scanf_s("%c", &c); //read user answer

			switch (c) {
			case '>':
				min = n + 1;
				a++;
				break;
			case '=':
				printf("Easy \n");
			case '<':
				max = n - 1;
				a++;
				break;
			}
		}
	}

	printf("Number of attempts: %d \n", a);
	scanf_s("%d", &mod);
}