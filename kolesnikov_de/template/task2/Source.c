#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main() {
	setlocale(LC_ALL, "rus");
	char mode,mark,correction, markold;
	int num, ran, numoftry = 0, prnum,left,right;
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
				printf("Ваше предположение:\n");
				scanf_s("%d", &num);
				if (num < 1001 & num > 0)
					break;
			}

			if (num > ran) {
				printf("Выше число больше\n");
				continue;

			}
			if (num < ran) {
				printf("Выше число меньше\n");
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
			if (num < 1001 | num > 0)
				break;
		}
		left = 0;
		right = 1000;
		num = 0;
		while (1) {
			num = (left + right) / 2;
			numoftry += 1;
			printf("Мы думаем ваше число = %d \n", num);
			printf("Впишите знак сравнения нашего числа и вашего \n");
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






	printf("Количество попыток = %d", numoftry);
}