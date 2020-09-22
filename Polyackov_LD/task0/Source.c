//Определить, каково взаимное расположение двух окружностей на плоскости с заданными координатами центров и радиусами. 
//Исходные данные должны вводиться пользователем. Результат программа должна выводить на экран.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void main()
{
	//Выполняется забор нужной информации
	float xone, yone, rone, xtwo, ytwo, rtwo;//x1, y1 - координаты центра окружности 1; x2, y2 - координаты центра окружности 2; r1 и r2 - радиусы соответствующих окружностей;
	printf("Enter the coordinates of the center (x1;y1) of the first circle\n\t");
	scanf("%f %f",&xone,&yone);
	printf("Enter the radius of the first circle (necessarily >=0)\n\t");
	scanf("%f",&rone);
	printf("Enter the coordinates of the center (x2;y2) of the second circle\n\t");
	scanf("%f %f",&xtwo,&ytwo);
	printf("Enter the radius of the seсond circle (necessarily >=0)\n\t");
	scanf("%f",&rtwo);

	//Обработка полученной информации
	
	//0 блок - полное совпадание окружностей
	if ((xone==xtwo)&&(yone==ytwo)&&(rone==rtwo))
		{
		printf("Both circles are equal");
		goto l;
		}
	//1 блок - проверка на количество касаний
	if ((rone+rtwo)==sqrt((xone-xtwo)* (xone - xtwo)+(yone - ytwo)(yone - ytwo)))
	//2 блок - если касаний ноль, то проверка на включённость окружности в другую окружность / проверка на расположение в разных местах относительно друг друга

	//3 блок - если касание одно, то проверка внешнего и внутреннего касания

	//4 блок - если касаний два, то окружности просто пересекаются
l:	scanf("%f",&xone);
}