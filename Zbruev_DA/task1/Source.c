#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{ 
	float h, w, d, DWP, DSP, WOOD, M;
	int k;//к-количество полок
	const float P_DVP = 820;
	const float P_DSP = 720;
	const float P_WOOD = 800;
	const float TDVP = 0.005;
	const float TDSP = 0.015;
	const float TWOOD = 0.01;
	const float H_Proem = 41.5;//считаем, что высота проема 40 см
	setlocale(LC_ALL, "Russian");
	printf("¬ведите высоту шкафа h в метрах: ");
	scanf_s("%f", &h);
	while ((h > 220) || (h < 180))
	{
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &h);
	}
	printf("¬ведите ширину шкафа w в метрах: ");
	scanf_s("%f", &w);
	while ((w > 120) || (w < 80))
	{
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &w);
	}
	printf("¬ведите глубину шкафа d в метрах: ");
	scanf_s("%f", &d);
	while ((d > 90) || (d < 50))
	{
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &d);
	}
	if (c = fmod(c, 3);)
		k = h / H_Proem;
	else 
	    k = 1 + (h / H_Proem);
	M = 2 * (h - 2 * TDSP) * d * TDSP * P_DSP + w * h * TDVP * P_DVP + 2 * w * d * TDSP * TDSP + w * h * TWOOD * P_WOOD + k * d * (w - 2 * TDSP) * P_DSP;
	printf("ћасса шкафа: %f", M);
	printf(" кг");
	system("pause");
}