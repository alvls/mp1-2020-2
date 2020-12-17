#include <math.h>
#include "Types.h"
void head(double x, operation funk)
{
	int i;
	printf("======================== РЕЗУЛЬТАТ =========================\n");
	printf("\nЭталонное значение, вычисленное профессионалами: ");
	if (funk == sqrt)
		printf("%lf\n\n", funk(x + 1.0));
	else
		printf("%lf\n\n", funk(x));
	printf("ЧИСЛО СЛАГАЕМЫХ");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("ЗНАЧЕНИЕ РЯДА");
	for (i = 0; i < 5; i++)
		printf(" ");
	printf("МОДУЛЬ РАЗНОСТИ");
	printf("\n");
	for (i = 0; i < 23; i++)
		printf(" ");
	printf("ТЕЙЛОРА");
	for (i = 0; i < 8; i++)
		printf(" ");
	printf("РЯДА И ЭТАЛОНА");
	printf("\n");
}
void printer(int count, db x, db Teilor, operation etalon)////////////////////////////////////////////сделать отступы
{
	long long i;
	db module;// модуль разности эталонного значения и оценки значения функции
	int sec = count;//для расчёта отступа
	long long secT = Teilor;//для больших значений суммы получить хороший пробел
	int mod_gap;//пробел для модуля
	if (etalon != sqrt)
		module = etalon(x);
	else
		module = etalon(1 + x);
	module -= Teilor;
	if (module < 0.0)
		module *= -1;
	for (i = 0; i < 5; i++)
		printf(" ");
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%d", count);/////////////////////////////////сделано написание count
	for (sec = 0; sec < 5 - i; sec += 2)
		printf(" ");
	if (!(sec % 2))
		printf(" ");
	sec = 10;
	i = 1;
	while (secT >= 100000)
	{
		secT /= 10;
		if (i % 2)
			sec--;
		i++;
	}
	mod_gap = sec;
	if (Teilor < 0.0)
		sec--;
	for (i = 0; i < sec; i++)
		printf(" ");
	secT = (int)Teilor;
	for (i = 0; secT > 0; i++)
		secT /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%0.6lf", Teilor);/////////////////////////////////сделано написание Teilor
	sec = (int)module;
	for (i = 0; i < mod_gap - 2; i++)
		printf(" ");
	for (i = 0; sec > 0; i++)
		sec /= 10;
	for (sec = 0; sec <= 3 - i; sec += 2)
		printf(" ");
	printf("%-1.6lf", module);///////////////////////////////сделано полностью написание
	printf("\n");
}