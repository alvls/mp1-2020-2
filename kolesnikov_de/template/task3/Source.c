#define ARRLENGHT 5
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "Console.cpp"
int main() {
	textcolor(BLACK);
	textbackground(WHITE);
	textattr(CYAN);
	setwindow(32, 32);
	SMALL_RECT window;
	COORD buf;

	int number[ARRLENGHT] = { 0,0,0,0,0 }, trynumber[ARRLENGHT] = { 0,0,0,0,0 };
	int trnum, rebtime = 0, i, lenght, j, cows = 0, bulls = 0, code, tmp;
	srand(time(NULL));
	do {
		printf("Please input lenght of number(from 2 to 5)\n");
		scanf_s("%d", &lenght);
	} while ((lenght > 5) || (lenght < 2));
	//Generating number
	for (i = 0; i < lenght; i++) {
		number[i] = tmp = rand() % 9 + 1;
		while (1) {
			for (j = 0; j < i; j++) {
				if (number[j] == tmp) {
					number[i] = tmp = rand() % 9 + 1;
					break;
				}
			}
			if (j == i) {
				break;
			}
		}
	}

	while (1) {
		printf("Enter your number\n");
		scanf_s("%d", &trnum);
		for (i = 0; i < ARRLENGHT; i++) {
			trynumber[lenght - i - 1] = trnum % 10;
			trnum /= 10;
		}
		cows = 0;
		bulls = 0;
		for (i = 0; i < lenght; i++) {
			for (j = 0; j < lenght; j++) {
				if ((trynumber[i] == number[j]) && (i == j)) {
					bulls += 1;
					cows += 1;
				}
				else if (trynumber[i] == number[j]) {
					cows += 1;
				}
			}
		}
		GetWindow(&window, &buf);
		HideCursor();
		rebtime += 1;
		printf("Number of cows = %d,Number of bulls=%d\n", cows, bulls);
		if (bulls == lenght) {
			printf("And..You win!,You need %d try`s\n", rebtime);
			break;
		}
		printf("Do you want try again or quit?\n");
		printf("Input 1 for try again,2 for quit\n");
		scanf_s("%d", &code);
		if (code == 2) {
			break;
		}
	}

}