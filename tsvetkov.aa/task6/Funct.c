#include "Funct.h"
#include <math.h>
double siny(double x, int i)//��������� ��� ������
{
	double y;
	y = (pow(-1, i) * (pow(x, 2 * i + 1) / factorial(2 * i + 1)));
	return y;
}
double cosy(double x, int i)//��������� ��� ��������
{
	double y;
	y = (pow(-1, i) * (pow(x, 2 * i) / factorial(2 * i)));
	return y;
}
double expy(double x, int i)//��������� ��� exp
{
	double y;
	y = (pow(x, i) / factorial(i));
	return y;
}
double sinhy(double x, int i)//��������� ��� ������.������
{
	double y;
	y = (pow(x, 2 * i + 1) / factorial(2 * i + 1));
	return y;
}
double factorial(int n)//������� ���������� ����������,������� ����������� ��� ����� �������
{
	if (n == 0 || n == 1) return 1;
	return (n * factorial(n - 1));
}
void funct(int m, int n, double t, int k, double x, double kx, double (*fun)(double, int))//������� �������� ������� � ����� x, ������������ ��������� �� ������� ��������� ��������� ����, � ����������� �� ������ ������� ���������� ������������ ������� �������� ���������� � ������� �������
{//m-�����,n-���-�� ���������,t-�������� ��������,k-������� t,x-����� � ������� ���� ���������
	double* ch;//������ ��� ������ 2,���������� �������� ������� �� ������ ����



	ch = (double*)malloc(n * sizeof(double));

	double  y = 0, yx = 0;//y-�������� ������� �� �������,yx-�������� ����� ���� �������(���������)
	int i, j = 0;//��������,j- ������������ ������� ���� ��������� ��������� � ������ 1



	for (i = 0; i < n; i++)
	{
		yx = fun(x, i);
		if (m == 2)
		{
			y = y + yx;
			ch[i] = y;

		}

		if (m == 1)
		{

			if (fabs(yx) < t)
				break;
			else
			{
				y = y + yx;
				j++;
			}
		}

	}

	if (m == 2)
		mode2(ch, kx, n);
	if (m == 1)
		mode1(kx, y, j, n, k);
	if (m == 2)
		free(ch);
}