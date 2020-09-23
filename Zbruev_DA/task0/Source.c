#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	float x1, y1, r1, x2, y2, r2; 
	setlocale(LC_ALL, "Russian");
	printf("Введите координаты центра первой окружности и ее радиус, каждый раз нажимая Enter: ");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Введите координаты центра второй окружности и ее радиус, каждый раз нажимая Enter: ");
	scanf_s("%f%f%f", &x2, &y2, &r2);
	if ((r1 == r2) && ((y1 == y2) && (x1 == x2)))
	{
		printf("Окружности совпадают \n");
	}
	else
	  if ((pow((x2 - x1), 2) + pow((y2 - y1), 2)) < pow((r2 - r1), 2))
	   {
		  printf("одна окружность лежит внутри другой \n");
	   }
	  else    
	    if ((r1 + r2) < sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))
	     {
		    printf("окружности лежат вне друг друга \n");
	     }
		else
	      if ((r1 + r2) == (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))))
	       {
		      printf("окружности касаются друг друга извне \n");
	       }
	      else 
		    if (fabs(r1 - r2) == (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))))
		     {
			    printf("окружности касаются друг друга изнутри \n");
		     }
			else 
				printf("окружности пересекаются \n");
	system("pause");
}
