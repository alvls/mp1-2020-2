#include <stdio.h>
void main() {
	float pDCP=0.65, pDVP=0.82, pTree=0.9;
	float  w, d,m1,m2,m3,m4,m5,num;
	int h,m;
	float tDCP = 0.15, tDVP = 0.5, tTree = 1;
	while (1) {
		printf("Please Input:height depth width in cm\n");
		scanf_s("%i %f %f", &h, &d, &w);
		if ( (179<h)&(h<221)&(w<121)&(79<w))
		{
			break;
		}
		else
			printf("Please Input Correct Data!\n");
			continue;
	}
	num = h / 40;
	m1 = h * w*tDVP*pDVP; 
	m2 = 2 * h*d*tDCP*pDCP; 
	m3 = 2 * w*pDCP*tDCP*d; 
	m4 = 2 * h*tTree*pTree*w; 
	m5 =num*pDCP*tDCP*(d-tDVP)*(w-2*tDCP); //polka:width-2*width sidewall=2*tDCP,depth-width back wall=tDVP  
	m = (m1 + m2 + m3 + m4 + m5) / 1000;
	printf("Mass=%ikg",m);
}