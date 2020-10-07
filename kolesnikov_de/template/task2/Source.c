#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main() {
	setlocale(LC_ALL, "rus");
	char mark, out;
	int num, ran, left, right, mode;
	int numoftry = 0;
	while (1) {
		printf("Input mode\n");
		scanf_s("%d", &mode);
		if (mode == 2 || mode == 1)
			break;
	}
	if (mode == 1) {
		srand(time(NULL));
		ran = rand() % (1000 - 1) + 1;
		while (1) {
			numoftry += 1;
			while (1) {
				printf("Your quess:\n");
				scanf_s("%d", &num);
				if ((num < 1001) && (num > 0))
					break;
			}

			if (num < ran) {
				printf("The hidden number is greater than your\n");
				continue;
			}
			if (num > ran) {
				printf("The hidden number is less than your\n");
				continue;
			}
			else {
				printf("You got it!\n");
				break;

			}
		}
	}
	else {
		while (1) {
			printf("Please input your number\n");
			scanf_s("%d", &num);
			if ((num < 1001) && (num > 0))
				break;
		}
		left = 0;
		right = 1000;
		num = 0;
		while (1) {
			num = (left + right) / 2;
			numoftry += 1;
			printf("We think your number is %d\n", num);
			printf("Enter a sign comparing your number and ours\n");
			do {
				scanf_s("%c", &mark);
			} while (mark == '\n');

			if (mark == '>') {
				left = (left + right) / 2;
				continue;
			}
			if (mark == '<') {
				right = ((left + right) / 2);
				continue;
			}
			if (mark == '=') {
				printf("We guessed right!\n");
				break;
			}
		}
	}
	printf("Number of try`s = %d\n", numoftry);
	printf("Exit the program?\n");
	do {
		scanf_s("%c", &out);
	} while (out == '\n');
	if (out == 'yes')
		return;
}
