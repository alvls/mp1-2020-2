#define ARRLENGHT 5
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "Console.cpp"
int main() {
	//Decoration window
	setwindow(1280, 720);
	//Variable`s
	int number[ARRLENGHT] = { 0 }, trynumber[ARRLENGHT] = { 0 };
	int trnum, rebtime = 0, i, lenght, j, cows = 0, bulls = 0, code, tmp, theme;
	srand(time(NULL));
	//Theme
	printf("Enable Light Theme?(1-yes,2-no)\n");
	scanf_s("%d", &theme);
	if (theme == 1) {
		system("color F0");
	}
	//Main program
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
		printf("Enter your number,remember lenght of your number only %d\n",lenght);
		scanf_s("%d", &trnum);
		for (i = 0; i < lenght; i++) {
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
		rebtime += 1;
		printf("Number of cows = %d,Number of bulls=%d\n", cows, bulls);
		if (bulls == lenght) {
			textcolor(WHITE);
			textbackground(LIGHTGREEN);
			printf("And..You win!,You need %d try`s,close program to quit\n", rebtime);
			printf("\n");
			system("pause");
			return 0;
		}
		textcolor(WHITE);
		textbackground(RED);
		printf("Do you want try again or quit?\n");
		printf("Input 1 for try again,2 for quit\n");
		if (theme == 1) {
			textcolor(BLACK);
			textbackground(WHITE);
		}
		else {
			textcolor(WHITE);
			textbackground(BLACK);
		}
		do {
			scanf_s("%d", &code);
		} while ((code>2) ||(code<1));
		if (code == 2) {
			printf("Number is ");
			for (i = 0; i < lenght; i++) {
				printf("%d", number[i]);
			}
			printf("\n");
			system("pause");
			return 0;
		}
	}
}