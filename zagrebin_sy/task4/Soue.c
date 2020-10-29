#include <stdio.h>

void main() {

	char code[4] = {'q','q','q','q'};

	scanf_s("%c%c%c%c", &code[0], &code[1], &code[2], &code[3]);
	printf("%c%c%c%c", &code[0], &code[1], &code[2], &code[3]);
	scanf_s("%c%c%c%c", &code[0], &code[1], &code[2], &code[3]);
}