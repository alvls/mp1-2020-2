#include <stdio.h>
#include <math.h>
void main()
{
float  a, b, c, d, r1, r2;
printf("enter parameters of the first circle\n");
scanf("%f %f %f", &a, &b, &r1);
printf("enter parameters of the second circle\n");
scanf("%f %f %f", &c, &d, &r2);
	if((r1<=0)||(r2<=0))
		{printf("error");
		return;}
		else if((sqrt(pow((c-a),2)+pow((d-b),2)) == abs(r1-r2))&&(r1!=r2))// окружности касаются внутренним образом
			printf("one circle touches another inside of it");
		else if (sqrt(pow((c-a),2)+pow((d-b),2)) == (r1+r2))// окружности касаются внешним образом
			printf("one circle touches another outside of it");
		else if (sqrt(pow((c-a),2)+pow((d-b),2)) > (r1+r2))// окружности не касаются
			printf("circles don't touch each other");
		else if ((sqrt(pow((c-a),2)+pow((d-b),2)) == 0)&&(r1==r2))// окружности совпадают
			printf("they are the same circles");
		else if ((sqrt(pow((c-a),2)+pow((d-b),2)) > abs(r1-r2))&&(sqrt(pow((c-a),2)+pow((d-b),2)) <(r1+r2)))
			printf("circles touch each other twice");//окружности пересекаются
		else if (sqrt(pow((c-a),2)+pow((d-b),2)) < abs(r1-r2))
			printf("one circle inside of another");// одна окружность внутри другой
		
		

	
	
	





}