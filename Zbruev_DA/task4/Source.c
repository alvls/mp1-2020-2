#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 4
void clean(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
float stoimost(int stoimost, int sale)//считает стоимость с учетом скидки
{
	int s;
	s= (stoimost*((100-sale))/100);
	return (s);
}
void main()
{
	//int kod[N];
	int kod;
	float s;
	setlocale(LC_ALL, "Russian");
	printf("Информация о товарах \n- ");
	printf("1001 - Глушитель для ВАЗ 2113-2115 \n- ");
	printf("2001 - Набор синхронизаторов на передачи для ВАЗ 2113-2115 \n- ");
	printf("3001 - Свечи зажигания для ВАЗ 2113-2115 \n- ");
	printf("3002 - Поршень для ВАЗ 2113-2115 \n- ");
	printf("3101 - Жиклеры для карбюраторных ВАЗ 2109 \n- ");
	printf("3102 - Датчик температуры охлаждающей жидкости для ВАЗ 2109 \n- ");
	printf("4001 - Форсунки омывателя лобового стекла \n- ");
	printf("4002 - Набор предохранителей \n- ");
	printf("4003 - Бортовой компьютер БК-03 \n- ");
	printf("5001 - Тормозные колодки задние для ВАЗ 2109-2115 \n- ");
	printf("5002 - Тормозные колодки передние для ВАЗ 2109-2115 \n ");
	printf("Введите штрих-код товара (натуральное четырехзначное число): ");
	scanf_s("%d", &kod);
	while ((kod < 1000) || (kod > 9999))
	{
		clean();
		printf("Введено некорректное значение штрих-кода товара, попытайтесь заново: ");
		scanf_s("%d", &kod);
	}
	switch (kod)
	{
	case 1001:
		printf("- Глушитель для ВАЗ 2113-2115    %5.2f", stoimost(1500, 40));
		printf(" рублей\n");
		break;
	case 2001:
		printf("- Набор синхронизаторов на передачи для ВАЗ 2113-2115    %5.2f\n ", stoimost(3000, 15));
		printf(" рублей\n");
		break;
	case 3001:
		printf("- Свечи зажигания для ВАЗ 2113-2115    %5.2f\n ", stoimost(250, 15));
		printf(" рублей\n");
		break;
	case 3002:
		printf("- Поршень для ВАЗ 2113-2115    %5.2f\n ", stoimost(150, 5));
		printf(" рублей\n");
		break;
	case 3101:
		printf("- Жиклеры для карбюраторных ВАЗ 2109    %5.2f\n ", stoimost(800, 10));
		printf(" рублей\n");
		break;
	case 3102:
		printf("- Датчик температуры охлаждающей жидкости для ВАЗ 2109    %5.2f\n ", stoimost(200, 15));
		printf(" рублей\n");
		break;
	case 4001:
		printf("- Форсунки омывателя лобового стекла    %5.2f\n ", stoimost(150, 10));
		printf(" рублей\n");
		break;
	case 4002:
		printf("- Набор предохранителей    %5.2f\n ", stoimost(150, 10));
		printf(" рублей\n");
		break;
	case 4003:
		printf("- Бортовой компьютер БК-03    %5.2f\n ", stoimost(1500, 20));
		printf(" рублей\n");
		break;
	case 5001:
		printf("- Тормозные колодки задние для ВАЗ 2109-2115    %5.2f\n ", stoimost(600, 5));
		printf(" рублей\n");
		break;
	case 5002:
		printf("- Тормозные колодки передние для ВАЗ 2109-2115    %5.2f\n ", stoimost(500, 5));
		printf(" рублей\n");
		break;
	} 
	system("pause");
}