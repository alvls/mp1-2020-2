#include<stdio.h>
#include<math.h>
typedef double db;
int proverka(db acc, db x, db Teilor, db(*etalon)(db))
{
	db x1 = x;
	if (etalon != sqrt)
		x1 = etalon(x);
	else
		x1 = etalon(x + 1.0);
	x1 -= Teilor;
	if (x1 < 0.0)
		x1 *= -1.0;
	//printf("x1=%lf\n", x1);
	return (x1 > acc) ? 1 : 0;
}
db polinom(db acc, int count, db x, db(*etalon)(db))
{
	long long int i;
	long long fact = 1;//факториал
	long double Teilor;//значение ряда Тейлора
	int (*do_it)(db, db, db, db(*etalon)(db)) = proverka;
	db* elem;
	elem = (db*)malloc(sizeof(db) * (count + 1));
	elem[0] = 1;
	if (etalon == cos || etalon == sin)
	{
		const db x2 = x * x;//для умножения икс^k на икс во второй
		long long n;//для факториала
		if (etalon == cos)
		{
			x = 1;
			n = 0;
		}
		else
		{
			n = 1;
		}
		Teilor = x;
		if (acc != 0.0)
			for (i = 1; i < count && proverka(acc, x, Teilor, etalon); i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (long double)fact;
			}
		else
			for (i = 1; i < count; i++, n += 2)
			{
				x *= x2;
				fact = fact * (n + 1) * (n + 2);
				fact *= -1;
				Teilor = Teilor + x / (db)fact;
			}
	}
	else
	{
		Teilor = 1.0;
		const db x1 = x;
		if (etalon == exp)
		{
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++)
				{
					fact *= i;
					x *= x1;
					Teilor = Teilor + x / (long double)fact;
					//Teilor = Teilor + x / fact;
					printf("Teilor=%lf\n", Teilor);/////////////////////////////////////////////////////////////////////////
				}
			else
				for (i = 1; i <= count; i++)
				{
					//fact *= i;
					// x *= x1;
					elem[i] = (elem[i - 1] * x) / (i + 1);
					//Teilor = Teilor + elem[i];//x / (long double)fact;
				}
			for (i = 0; i <= count; i++)
				Teilor = Teilor + elem[i];
			free(elem);
		}
		else
		{
			long long difact = -1;//факториал удвоенного числа
			long long chet = 1;//идёт в знаменатель в виде 4 i-той степени
			long long znam;//штука, идущая в знаменатель
			long long fact2 = 1;//квадрат факториала
			long long n = 2;//для факториала
			//Full формула: ((-1)^i * (2i)! * x^i) / ((1-2i) * (i!)^2 * (4^i)), 0<=i<=n
//Small формула: (difact * x) / (znam * fact2 * chet);
			if (acc != 0.0)
				for (i = 1; i < count && do_it(acc, x, Teilor, etalon); i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					//Teilor += (x * difact) / (znam * fact2 * chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
			else
				for (i = 1; i < count; i++, n += 2)
				{
					x *= x1;
					difact = difact * n * (n - 1);
					znam = (-2) * i + 1;
					fact2 *= i;
					fact2 *= fact2;
					chet *= 4;
					//Teilor += (x * (long double)difact) / ((long double)znam * (long double)fact2 * (long double)chet);
					Teilor = Teilor + (x * difact) / (znam * fact2 * chet);
					difact *= -1;
				}
		}
	}
	return Teilor;
}
