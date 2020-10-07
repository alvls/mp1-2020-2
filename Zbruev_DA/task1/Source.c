#include <stdio.h>
#include <locale.h>
void clean(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);

}
void main()
{
	float h, w, d, DWP, DSP, WOOD, M;
	int k;//к-количество полок
	const float P_DVP = 820;//плотность
	const float P_DSP = 720;//плотность
	const float P_WOOD = 800;//плотность
	const float TDVP = 0.005;//буква T-толщина
	const float TDSP = 0.015;//буква T-толщина
	const float TWOOD = 0.01;//буква T-толщина
	const float H_Proem = 0.415;//считаем, что высота проема 40 см + толщина ƒ—ѕ
	setlocale(LC_ALL, "Russian");
	printf("¬ведите высоту шкафа h в сантиметрах в диапазоне от 180 до 220 см не включительно, отдел€€ дробную часть зап€той: ");
	scanf_s("%f", &h);
	while ((h > 220) || (h < 180))
	{
		clean();
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &h);
	}
	h = h / 100;
	printf("¬ведите ширину шкафа w в сантиметрах в диапазоне от 80 до 120 см не включительно, отдел€€ дробную часть зап€той: ");
	scanf_s("%f", &w);
	while ((w > 120) || (w < 80))
	{
		clean();
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &w);
	}
	w = w / 100;
	printf("¬ведите глубину шкафа d в сантиметрах в диапазоне от 50 до 90 см не включительно, отдел€€ дробную часть зап€той: ");
	scanf_s("%f", &d);
	while ((d > 90) || (d < 50))
	{
		clean();
		printf("¬ведено некорректное значание, попробуйте ввести заново: ");
		scanf_s("%f", &d);
	}
	d = d / 100;
	k = (h - 2 * TDSP)/ H_Proem;
	if (((h-2*TDSP) - k * H_Proem) != 0)
	{
		k = k + 1;
	}
	M = 2 * (h - 2 * TDSP) * d * TDSP * P_DSP + w * h * TDVP * P_DVP + 2 * w * d * TDSP * P_DSP + w * h * TWOOD * P_WOOD + k * d * (w - 2 * TDSP) * P_DSP * TDSP;
	printf("ћасса шкафа: %f", M);
	printf(" кг \n");
	system("pause");
}