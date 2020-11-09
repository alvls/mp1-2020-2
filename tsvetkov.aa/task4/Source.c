#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define ALL 7
//объявил каждый штрих-код в отдельный массив как было указано в задании, хотя было бы проще занести их всех в один массив
char rx580[5] = { '1','2','4','3','\0' };
char gtx1050[5] = { '5','1','3','6','\0' };
char gtx1050ti[5] = { '5','1','2','8','\0' };
char rx460[5] = { '3','0','1','4','\0' };
char gtx1660[5] = { '8','3','9','1','\0' };
char gt710[5] = { '5','8','1','4','\0' };
char rtx3090[5] = { '2','6','3','1','\0' };
char names[ALL][20] = { "AMD RADEON RX580", "NVIDIA GTX1050", "NVIDIA GTX1050TI", "AMD RADEON RX460", "NVIDIA GTX1660", "NVIDIA GT710", "NVIDIA RTX3090" };
float prices[ALL] = { 19990 ,7650 ,13020 ,6340 ,19720 ,3220 ,190000 };//стоимость товара
int i = 0, j = 0;//счетчики для циклов
int kol[ALL] = { 0 };//массив для подсчитывания кол-ва товаров в корзине
float discount[ALL] = { 0.1,0.05,0.2,0.1,0.25,0.05,0.5 };//массив скидок на каждый товар

void console() // очистка консоли перед выводом чека
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}




void clean()//очистка потока воода
{

	int c;
	do
	{
		c = getchar();
	} while ((c != '\n') && (c != EOF));

}

int check(char vvod[])//проверка формата кода(4 символа от 0 до 9)
{
	int f = 0;
	if (strlen(vvod) == 4)//проверка на длинну введенной строки
	{
		for (i = 0; i < 4; i++)
			if ((vvod[i] >= '0') && (vvod[i] <= '9'))//проверка на правильность символов штрих-кода
				f = 1;
			else
			{
				f = 0;
				break;
			}

	}
	return(f);
}

void code(char vvod[])//cравнение введенного штрих-кода с базой данных и вывод информации товара
{
	int num = -1;//флажок функции
	if (strcmp(vvod, rx580) == 0)//сравниваю введенную строку со строками массивов штрих-кодов
	{
		kol[0]++;
		num = 0;
	}
	else
		if (strcmp(vvod, gtx1050) == 0)
		{
			kol[1]++;
			num = 1;
		}
		else
			if (strcmp(vvod, gtx1050ti) == 0)
			{
				kol[2]++;
				num = 2;
			}
			else
				if (strcmp(vvod, rx460) == 0)
				{
					kol[3]++;
					num = 3;
				}
				else
					if (strcmp(vvod, gtx1660) == 0)
					{
						kol[4]++;
						num = 4;
					}
					else
						if (strcmp(vvod, gt710) == 0)
						{
							kol[5]++;
							num = 5;
						}
						else
							if (strcmp(vvod, rtx3090) == 0)
							{
								kol[6]++;
								num = 6;
							}
	if (num == -1)//если совпадений нет
		printf("Кода %s нет в базе данных,попробуйте ввести заново\n", vvod);
	else//иначе выводим всю информацию
		printf("Видеокарта %-30s Цена(руб)=%.0f \nСкидка на товар составляет= %.0f%%\n", names[num], prices[num], (discount[num] * 100));

}

void timesec()//функция для вывода времени в чек
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	printf("%s", str);
}

void main()
{
l:
	setlocale(LC_ALL, "Russian");
	char vvod[10];//для вводимого штрих-кода
	int flag = -1;//флаг для проверки формата кода(возвращаемое значение функции check) и также для выбора создания нового чека в конце программы
	int n = 1;//для выбора режима (0-печать чека,1-добавление товара)
	char c = ' ';//для  более красивого оформления пробельный символ
	float fp = 0, fd = 0, pr = 0;//fp-стоимость покупки,fd-общая скидка,pr-для рассчета цены отдельной позиции товра с учетом скидки
	for (i = 0; i < ALL; i++)
		kol[i] = 0;//зануление перед новым чеком
	for (j = 0; j < 20; j++)//вывод на консоль информации по всем товарам
		printf("-");
	printf("Товары в наличии");
	for (j = 0; j < 20; j++)
		printf("-");
	printf("\n");
	printf("Штрих-код %6c Название %-20c Стоимость\n", c, c);
	printf("%-17s%s%19.0f\n", rx580, names[0], prices[0]);
	printf("%-17s%s%20.0f\n", gtx1050, names[1], prices[1]);
	printf("%-17s%s%19.0f\n", gtx1050ti, names[2], prices[2]);
	printf("%-17s%s%18.0f\n", rx460, names[3], prices[3]);
	printf("%-17s%s%21.0f\n", gtx1660, names[4], prices[4]);
	printf("%-17s%s%22.0f\n", gt710, names[5], prices[5]);
	printf("%-17s%s%22.0f\n", rtx3090, names[6], prices[6]);


	while (n != 0)
	{

		printf("Введите 1 для добавления товара или 0 для завершения покупок\n");
		scanf_s("%d", &n);
		if (n == 1)
		{
			printf("Введите штрих-код,состоящий из 4 цифр\n");
			clean();
			gets(vvod);

			flag = check(vvod);//проверка нна формат, если формат введенного кода верный сверяем его с базой кодов
			if (flag == 1)
				code(vvod);
			else
				printf("Формат штрих-кода неверен, попробуйте ввести его еще раз\n");

		}

	}
	if (n == 0)//печать чека
	{
		console();//чистим консоль
		flag = 0;
		for (i = 0; i < ALL; i++)//идем по массиву количеств каждого товара, если видм что нет ни одного то выводим предупреждение
			if (kol[i] > 0)
				flag = 1;
		if (flag == 0)
			printf("В корзине нет ни одного товара\n");
		else
		{
			for (j = 0; j < 22; j++)//оформление
				printf("-");
			printf("ЧЕК");
			for (j = 0; j < 23; j++)
				printf("-");
			printf("\n");
			for (i = 0; i < ALL; i++)//идем по массиву количеств и находим номера товраров с ненулевыми значениями, выводим их в чек
				if (kol[i] != 0)
				{
					pr = kol[i] * prices[i] * (1 - discount[i]);//стоимость со скидкой
					printf("%-20s X%-4d Цена(руб/шт)=%-4.0f \nСкидка=%.0f%% %7c Общая стоимость(руб)=%.0f\n", names[i], kol[i], prices[i], (discount[i] * 100), c, pr);
					fp += pr;//сумма покупки
					fd += prices[i] * kol[i] - pr;//общая скидка


				}
			for (j = 0; j < 48; j++)//оформление
				printf("-");
			printf("\n");
			printf("Сумма покупки(руб)=%.0f\nОбщая скидка(руб)=%.0f\n", fp, fd);//выводим в конце общую скидку и сумму покупки
			timesec();//выводим время

			for (j = 0; j < 48; j++)//оформление
				printf("-");
			printf("\n");




		}
		printf("Для создания нового чека нажмите 1, для выхода из программы нажмите любую клавишу\n");//предлагаем создать новый чек
		scanf_s("%d", &flag);
		if (flag == 1)
		{
			console();
			goto l;
		}


	}
}
