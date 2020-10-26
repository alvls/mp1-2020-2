#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void rules() //функция вывода правил при необходимости
{
	int start = 0;
	printf("Правила:\n");
	printf("Пусть n = 4.\nПусть задумано число «3219».(ЗАДУМАННОЕ ЧИСЛО НЕ МОЖЕТ СОДЕРЖАТЬ ОДИНАКОВЫЕ ЦИФРЫ!\nИгрок ввел число «2310»\n");
	printf("Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции).\n");
	printf("Начнем игру? Введите 1 для начала игры: ");
	while (start != 1)
	{
		scanf_s("%d", &start);
		if (start == 1)
		{
			system("cls");
			return;
		}
		else
			printf("Ошибка ввода, попробуйте еще раз: ");

	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0; //размер числа
	int guess = 0; //пользовательсое предположение
	int array[5]; //массив с неповторяющимися числами
	int array_guess[5]; //массив из цифр пользовательского числа
	int candidate = 0; //кандитат на цифру в массиве неповторяющихся чисел 
	int i = 0; //счетчик
	int	j = 0; //счетчик
	int flag = 0;
	int choice = 0; // для выбора пользователем правил или нет
	int cow = 0; // коровы
	int	bull = 0; //быки
	int attempts = 0; //попытки
	int guess_size = 0; // кол-во цифр в введенном пользователем числе
	int clone_guess = 0; //клон введенного пользователем числа
	srand(time(NULL));

	printf("Добро пожаловать в игру Быки и Коровы\n");
	printf("Хотите ознакомиться с правилами игры? 1 = Да 2 = Нет\n");
	scanf_s("%i", &choice);
	
	if (choice == 1)
		rules();
	
	while (size < 2 || size > 5) // проверка на соответсвие правилам игры
	{
		printf("Введите длину числа от 2 до 5: ");
		scanf_s("%d", &size);
		if (size < 2 || size > 5)
			printf("Длина не соответствует диапозону, попробуйте еще раз\n");
	}

	system("cls");
	printf("Длина загаданного числа = %d\n", size);
	printf("Приятной игры:)\n");

	array[0] = rand() % 9 + 1; //исключаем случай 0 на первой позиции в числе

	for (i = 1; i < size; i++) //создание массива неповторяющихся чисел
	{
		candidate = rand() % 10;
		for(j=0;j < i;j++)
		{
			if (array[j] == candidate)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			array[i] = candidate;
		else
		{
			i--;
			flag = 0;
		}
	}


	//for (i = 0; i < size; i++) //вывод массива для возможности проверки генерации  
	//{
	//	printf("%d ",array[i]);
	//}
	//printf("\n");
	
	while (bull != size) //проверка на окочание игры
	{
		cow = 0;
		bull = 0;
		guess_size = 0;
		while (guess_size != size) //проверка на соответсвие размеру загаднного числа
		{
			printf("Введите догадку: ");
			scanf_s("%d", &guess);
			clone_guess = guess; //чтобы не изменять значение полученной переменной

			while (clone_guess != 0) //вычисление кол-ва цифр в введенном числе 
			{
				clone_guess /= 10;
				guess_size++;

			 }

			if (guess_size != size) //Вывод ошибки
			{
				printf("Ошибка ввода, Ваша догадка не равна размеру загаднного числа, попробуйте еще раз\n");
				guess_size = 0;
				continue;
			}

			clone_guess = guess; //вернуть клону значение guess

			for (i = size - 1; i >= 0; i--) //преобразование введенного числа в массив 
			{
				array_guess[i] = clone_guess % 10;
				clone_guess /= 10;
			}
		}
		
		
		printf("\nВаша догадка = %d\n", guess);

		for (i = 0; i < size; i++) //реализация игры
		{
			for (j = 0; j < size; j++)
			{
				if (array[i] == array_guess[j] && i != j)
					cow++;
				if (array[i] == array_guess[j] && i == j)
					bull++;
			}
		}

		printf("Коров = %d\n", cow);
		printf("Быков = %d\n", bull);
		attempts++;
		
		}

	printf("Поздравляю, Вы угадали!\n");
	printf("Количество затраченные попыток = %d\n", attempts);

	system("pause");
}