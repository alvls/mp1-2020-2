#include <stdio.h>	
#define DENSITY_DVP 850
#define DENSITY_DSP 750
#define DENSITY_WOOD 690
void main()
{
	float h, w, d, k;
	float depth_1 = 0.005, depth_2 = 0.015 , depth_3 = 0.01, depth_4 = 0.015;// толщина полки depth_4 по условию задачи не дана.
	int count;
	int c;
	float locker_weigth;
	float V1, V2, V3, V4, V5;
	float W1, W2, W3, W4, W5;
	printf("enter numbers\n");
	k = scanf("%f %f %f", &h, &w, &d);
	while (k != 3 || h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90 )
	{	
		printf("not a number or numbers are wrong, try again\n");
			while((c = getchar()) != '\n' && c != EOF);
				{k = scanf("%f %f %f", &h, &w, &d);}		
	} 
	h = h/100;
	w = w/100;
	d = d/100;
	V1 = h*w*depth_1;
	V2 = 2*(h*d*depth_2);	
	V3 = 2*(w*d*depth_2);
	V4 = h*w*depth_3;
	count = h/(0.4);
	V5 = count*(d*w*depth_4);
	W1 = V1 * DENSITY_DVP;
	W2 = V2 * DENSITY_DSP;
	W3 = V3 * DENSITY_DSP;
	W4 = V4 * DENSITY_WOOD;
	W5 = V5 * DENSITY_DSP;
	locker_weigth = W1+W2+W3+W4+W5;
	printf("locker weigth is: %.2f", locker_weigth);
}