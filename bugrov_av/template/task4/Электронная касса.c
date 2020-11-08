#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define line 4 // число символов в штрих-коде (4)
#define end 47 // наибольшее число  символов в строке (47)
#define strok 17 // число разных cтрок (17)
const unsigned etalon[strok] = { 9999, 1, 70, 6900, 1234, 2020, 6065, 5432, 2018, 6969, 2019, 1000, 1990, 7770, 1959, 1030, 1933};
const char stroka[strok][end] = { "Завершение ввода товаров", "Билет лотереи \"Pobed.net\"", "Фигурка Джеймса Бонда","Клубника (упаковка)", "Генератор паролей карманный", "Маски медицинские (упаковка)", "Пенсионная скидка", "Дневник школьный" , "Футбольный мячик от Жака Фреско", "Огурец длинный", "Гречка (упаковка)", "Бумага туалетная (упаковка)", "Водка \"Прощай, товарищ!\"", "Топор \"Раскольников\"", "Кукуруза (упаковка)", "БП с изображением говядины", "Картина маленькая"}; // число строк х число символов
char strih[line]; //очередной поступаемый штрих-код
unsigned short pens = 0;//чтобы someone смог почувствовать себя старым
float kol_vo[strok]; //количество единиц товара
float prise[strok] = { 0.0, 100.0, 77.0, 249.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 500.0};// временные цены на товары данных штрих-кодов
const float standprise[strok] = { 0.0, 100.0, 77.0, 249.0, 144.0, 112.0, 0, 120.0, 480.0, 69.0, 58.0, 36.0, 259.0, 866.0, 96.0, 6.0, 500.0}; // неизменяемые цены на товары
int skidka[strok]; // размер скидки в целых числах процентов
float sum = 0.0; // итоговая сумма
unsigned short j = 0;
void nul() // обнуление глобальной переменной
{
	j = 0;
}
void stringp(i) // вывод строки
{
	while (stroka[i][j] != '\0')
	{
		printf("%c", stroka[i][j]);
		j++;
	}
	nul();
}
unsigned translator() //споиск штрих-кода
{
	int i = 0, t;// параметр массива
	unsigned kod;//преобразованный штрих-код
	unsigned plus;//вспомогательная переменная для преобразования штрих-кода
	do {
		kod = 0;
		do scanf("%c%c%c%c", &strih[0], &strih[1], &strih[2], &strih[3]);
		while (getchar() != '\n');
		for (i = 0; i < line; i++)
		{
			plus = 1;
			if (strih[i] - '0' < 10 && strih[i] - '0' >= 0)
			{
				for (t = line - 1; t > i; t--)
					plus *= 10;
				plus = plus * (strih[i] - '0');
				kod += plus;
			}
			else
			{
				kod = 0;
				plus = 2;
				break;
			}
		}
		i = 0;
		if (kod == 0)
		{
			i = strok;
			plus = 1;
		}
		for (i; i < strok; i++)
			if (kod == etalon[i])
			{
				plus = 2;
				stringp(i);
				printf("\n");
				break;
			}
			else
				plus = 1;
		if (plus != 2)
		{
			printf("Такого штрих-кода нет в базе данных, повторите ввод\n");
			strih[0] = 'j';
		}
	} while (strih[0] - '0' >= 10 || strih[0] - '0' < 0 || strih[1] - '0' >= 10 || strih[1] - '0' < 0 || strih[2] - '0' >= 10 || strih[2]- '0' < 0 || strih[3] - '0' >= 10 || strih[3] - '0' < 0);
	return kod;
}
void codes()// вывод доступных штрих-кодов 
{
	int i = 0;
	setlocale(LC_ALL, "Russian");
	printf("Код %u - ", etalon[i]);
	stringp(i);
	printf("\n");
	i++;
	printf("Код 000%u - ", etalon[i]);
	stringp(i);
	printf("\n");
	i++;
	printf("Код 00%u - ", etalon[i]);
	stringp(i);
	printf("\n");
	i++;
	for (i; i < strok; i++)
	{
		printf("Код %u - ", etalon[i]);
		stringp(i);
		printf("\n");
	}
	printf("\n");
	printf("Любой код, содержащий не цифры, означает ввод штрих-кода заново\n");
	printf("Вводите только сочетания по 4 символа, в конце ввода каждого сочетания нажимайте Enter\n\n");
	printf("Если вы ознакомились с информацией и готовы вводить штрих-коды, нажмите на любую клавишу");
	getch();
	system("CLS");
}
float sale(t) // создание скидки
{
	float k;
	float a[25];
	int i;
	int n;
	for (i = 0; i < 25; i++)
	{
		n = rand() % 11;
		a[i] = n;
		if (a[i] != 0.0)
			a[i] *= 5.0;
		else
		{
			a[24] = 0.0;
			break;
		}
	}
	i = 24;
	prise[t] *= (1.0 - (a[i] / 100.0));
	skidka[t] = a[i];
}
void summator(kod) // получение количества товаров
{
	int i;
	switch (kod)
	{
	case 1:
		i = 1;
		kol_vo[i]++;
		break;
	case 70:
		i = 2;
		kol_vo[i]++;
		break;
	case 6900:
		i = 3;
		kol_vo[i]++;
		break;
	case 1234:
		i = 4;
		kol_vo[i]++;
		break;
	case 2020:
		i = 5;
		kol_vo[i]++;
		break;
	case 6065:
		i = 6;
		pens++;
		break;
	case 5432:
		i = 7;
		kol_vo[i]++;
		break;
	case 2018:
		i = 8;
		kol_vo[i]++;
		break;
	case 6969:
		i = 9;
		kol_vo[i]++;
		break;
	case 2019:
		i = 10;
		kol_vo[i]++;
		break;
	case 1000:
		i = 11;
		kol_vo[i]++;
		break;
	case 1990:
		i = 12;
		kol_vo[i]++;
		break;
	case 7770:
		i = 13;
		kol_vo[i]++;
		break;
	case 1959:
		i = 14;
		kol_vo[i]++;
		break;
	case 1030:
		i = 15;
		kol_vo[i]++;
		break;
	case 1933:
		i = 16;
		kol_vo[i]++;
		break;
	}
}
void check() // формирование чека
{
	int i;
	system("CLS");
	printf("Чек за покупки в магазине \"Сфинкс\"\n\n");
	for (i = 0; i < strok; i++)
	{
		if (kol_vo[i])
		{
			stringp(i);
			printf(" %0.0f шт.\n", kol_vo[i]);
			if ((standprise[i] - prise[i]) != 0)
			{
				printf("  Цена товара без скидки: %0.0f руб\n", standprise[i]);
				printf("  Цена товара со скидкой: %0.2f руб\n", prise[i]);
			}
			else 
			{
				printf("  Цена товара: %0.0f руб.\n", standprise[i]);
			}
			printf("  Стоимость товара: %0.2f руб\n", prise[i] * kol_vo[i]);
			sum = sum + prise[i] * kol_vo[i];
		}
	}
}
void main() // здесь и производится сборка фрагментов
{
	int i, t;
	unsigned kod;
	float a = 0;
	setlocale(LC_ALL, "Russian");
	codes();
	srand(time(NULL));
	for (i = 0; i < strok; i++)
		if (i != 6)
			sale(i);
	do
	{
		kod = translator();
		summator(kod);
	} while (kod!=9999);
	system("color F0");
	check();
	if (pens)
	{
		printf("\nПенсионная скидка - 5%% от всей суммы\n");
		printf("  Она составила %0.2f руб\n\n", 0.05*sum);
		sum *= 0.95;
	}
	printf("Сейчас рандомная скидка на товары:\n");
	for (i = 1; i < strok; i++)
	{
		if (skidka[i] != 0)
		{
			stringp(i);
			printf(". Скидка составляет %d%%\n", skidka[i]);
		}
	}
	printf("\nИтоговая сумма: ");
	printf("%0.2f руб\n", sum);
	printf("Спасибо за покупки в нашем магазине!\n");
	system("pause");
}