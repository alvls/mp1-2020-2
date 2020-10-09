#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void main()
{
	setlocale(LC_ALL, "Russian");
	int mode;
	int repeat = 0;

	while (repeat != 2) 
	{
		system("cls");
		printf("Режим 1: Я загадываю число, а Вы его угадываете\n");
		printf("Режим 2: Вы загадываете число, а я его угадываю\n");
		printf("Для начала игры выберите режим: ");
		scanf_s("%d", &mode);

		if (mode == 1)
		{

			system("cls");
			printf("Вы выбрали режим 1, приятной игры :)\n");

			srand(time(NULL));
			int num = rand() % 1000 + 1;
			int guess = 0;
			unsigned int i = 0;

			printf("Я загадал число от 1 до 1000, попытайтесь его угадать\n");

			while (guess != num)
			{
				printf("Введите ваше предположение: ");
				scanf_s("%d", &guess);
				if (guess > num)
					printf("Попробуйте что-нибудь поменьше\n");
				else if (guess < num)
					printf("Попробуйте что-нибудь побольше\n");

				i++;
			}
			printf("Поздравляю, Вы угадали!!!\n");
			printf("Число затраченных попыток = %d\n", i);


		}
		else if (mode == 2)
		{
			int num=0;
			int guess;
			unsigned int i = 0;
			int min = 1;
			char sign = ' ';
			int max = 1000;

			system("cls");
			printf("Вы выбрали режим 2, приятной игры :)\n");
			
			while ((num < 1) || (num > 1000))
			{
				printf("Загадайте число от 1 до 1000: ");
				scanf_s("%d",&num);
				
				if ((num < 1) || (num>1000))
				{
					printf("Число не входит в границу диапозона, попробуйте еще раз\n");
				}
			}
			

				while (sign != '=')
				{
					srand(time(NULL));
					guess = rand() % (max - min + 1) + min;
				l:	printf("Ваше число > < или = %d? ", guess);
					while (sign = getchar() != '\n');
					scanf_s("%c", &sign);


					switch (sign)
					{
					case '>':
						min = guess + 1; //чтобы числа при угадывании не повторялись
						i++;
						break;
					case '<':
						max = guess - 1; //чтобы числа при угадывании не повторялись 
						i++;
						break;
					case '=':
						printf("Ванга за работой :)");
						break;

					default:
						printf("Недопустимый символ\n");
						goto l;  //возврат к сравнению > < =


					}

				}
				printf("Я угадал с %d попыток\n", i);
			
		}
		else
			printf("Я не знаю такого режима, попробуйте еще разок\n");
		printf("Еще разок? 1 = ДА:) 2 = НЕТ:( ");
		scanf_s("%d",&repeat);
	}
}