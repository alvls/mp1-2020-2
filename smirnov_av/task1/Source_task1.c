#include <stdio.h>
#include <locale.h>

/*Состав шкафа:
накладная задняя стенка из ДВП высотой h от 180 до 220 см, шириной w от 80 до 120 см и толщиной 5 мм,
две боковины из ДСП высотой h, глубиной d от 50 до 90 см и толщиной 15 мм,
накладные верхняя и нижняя крышки из ДСП шириной w, глубиной d и толщиной 15 мм,
две накладные двери из дерева высотой h, общей шириной w и толщиной 1 см,
внутренние полки в шкафу через каждый 40 см из ДСП.
Считая, что известны плотности ДСП, ДВП и дерева, найти массу шкафа в килограммах.
*/

void main()
{
	setlocale(LC_ALL, "Russian");
	const double p_dvp = 0.00082;	//кг/см^3  
	const double p_dsp = 0.00072;	//кг/см^3 
	const double p_wood = 0.00081;	//кг/см^3 
	double high, width, t_back = 0.5;	//Задняя стенка(ДВП) t_back(толщина задней стенки)
	double depth, t_side = 1.5, t_doors = 1;	//Боковины(ДСП) + двери(дерево)  t_side(толщина боковин) t_doors(толщина двери)
	double sum_m, m_back, m_side, m_roofs, m_doors, m_shelf;
	int quantity;

	printf("Введите высоту накладной задней стенки(180-220см) и ее ширину(80-120см): ");
	scanf_s("%lf %lf", &high, &width);

	if ((high <= 220) && (high >= 180) && (width >= 80) && (width <= 120))
	{
		printf("Введите глубину боковины(50-90см): ");
		scanf_s("%lf", &depth);
		if ((depth >= 50) && (depth <= 90))
		{
			quantity = (high - 3) / 41.5; //кол-во полок, которые влезут в шкаф (целое кол-во)
			m_back = p_dvp * high * width * t_back; //масса задней стенки 
			m_side = p_dsp * 2 * (high - 3) * depth * t_side; //масса боковин
			m_roofs = p_dsp * 2 * width * depth * t_side;
			m_doors = p_wood * high * width * t_doors; 
			m_shelf = p_dsp * quantity * (t_side * (width - 2 * t_side) * depth); 
			sum_m = m_back + m_side + m_roofs + m_doors + m_shelf;

			printf("Масса шкафа в кг = %lf", sum_m);
		}
		else printf("Глубина боковин вне диапозона");
	
	}
	else printf("Высота или ширина не входят в диапазон значений\n");

	scanf_s("%lf", &high);
}