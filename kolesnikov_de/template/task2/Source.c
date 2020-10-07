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
		printf("Введите режим\n");
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
				printf("Ваша догадка:\n");
				scanf_s("%d", &num);
				if ((num < 1001) && (num > 0))
					break;
			}

			if (num < ran) {
				printf("Загаданное число больше\n");
				continue;
			}
			if (num > ran) {
				printf("Загаданное число меньше\n");
				continue;
			}
			else {
				printf("Вы угадали!\n");
				break;

			}
		}
	}
	else {
		while (1) {
			printf("Введите выше число\n");
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
			printf("Мы думаем ваше число = %d \n", num);
			printf("Впишите знак сравнения вашего числа и нашего \n");
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
				printf("\nМы угадали!\n");
				break;
			}
		}
	}
	printf("Количество попыток = %d\n", numoftry);
	printf("Выйди из программы?\n");
	do {
		scanf_s("%c", &out);
	} while (out == '\n');
	if (out == 'да')
		return;
}