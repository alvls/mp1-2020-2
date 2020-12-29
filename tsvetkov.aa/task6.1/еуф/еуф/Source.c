#include <stdio.h>  
#include <locale.h>
#include <math.h>
#include "Funct.h"


int mode()//������� ������ ������ ������
{
	int n;
	printf("�������� ����� ������:\n");
	printf("1.����������� ������ ������� � �������� �����.\n2.�������� �����������.\n0.�����.\n");
	scanf_s("%d", &n);
	return n;
}
int choice()//����� ������
{
	int n;
	printf("�������� �������:\n");
	printf("1.sin(x).\n2.cos(X)\n3.exp(x)\n4.sh(X)\n");
	scanf_s("%d", &n);
	return n;


}

void mode2(double ch[], double kx,int n)//����� �� ������� ���������� � ������ 2
{
	char c = ' ';
	double x;
	int i;
	printf("��������� �������� = %.15lf\n", kx);
	printf("����-�� ���������.    ������ �������� �������.    ������� ����� ��������� � ��������� ��������� �������.\n");
	for (i = 0; i < n; i++)
	{
		x = fabs(kx - ch[i]);
		printf("%-21d %-27.15lf %.15lf\n", i + 1, ch[i], x);
	}
}
void mode1(double kx, double y, int j, int n,int k)//����� �� ������� ���������� � ������ 1
{
	if (j == n)
		printf("������� �������� ���������� �� ���������� ���������� ���� ����� ���������.\n");
	if (j!=n)
		printf("������� �������� ���������� �� ���������� �������� ���� ��������.\n");
	
	printf("��������� �������� = %.*lf\n",k+1, kx);
	printf("����������� ������ �������� = %.*lf\n",k+1, y);
	printf("������� ����� ��������� � ��������� ��������� ������� = %.*lf\n", k+3,fabs(y - kx));
	printf("���������� ����������� ��������� = %d\n", j);



}
int menu()//����� ����������� �������� ����� �������� �������
{
	int n;
	printf("�������� ���������� ��������\n");
	printf("1.��������� ����� �������.\n0.�����\n");
	scanf_s("%d", &n);
	return n;

}
void clean()//������� ������ �����
{

	int c;
	do
	{
		c = getchar();
	} while ((c != '\n') && (c != EOF));

}




void main()
{
l:
	
	
	setlocale(LC_ALL, "Russian");
	double kx = 0;//��������� ��������
	double t=0,tmp;//t-���������� ��� ������� ��������,tmp-��������� ����������
	int m, r, n, k = 0;//m-����� ������,r-����� �������,n-����� ���������,k-������� ����� t(��������)
	double x=0;//�������� x

	m = mode();//����� ������
	if (m == 0)
		return;
	r = choice();//����� �������
	
	
	if (m== 1)
	{
		printf("������� �������� ���������� >= 0.000001\n");
		scanf_s("%lf", &t);
		clean();
		tmp = t;
		while (tmp != 1)//������� ������� t,������������ ��� ����� ���������� ������ ����������� �� ������� � ������ 1(���-�� ������ ����� �������)
		{
			tmp = tmp * 10;
			k++;
		}
		
	}
	printf("������� ����� ��������� ���� ��� ���������� ���������\n");
	scanf_s("%d", &n);
	printf("������� �������� x\n");
	scanf_s("%lf", &x);

	switch (r)//����� ������� �������� �������� 
	{
	case 1:
		kx = sin(x);
		funct(m, n, t, k,x, kx , siny);
		break;
	case 2:
		kx = cos(x);
		funct(m, n, t, k,x,kx,cosy);
		break;
	case 3:
		kx = exp(x);
		funct(m, n, t, k,x,kx,expy);
		break;
	case 4:
		kx= (exp(x) - exp(-x)) / 2;
		funct(m, n, t, k,x,kx,sinhy);
		break;



	}


	if (menu() == 1)//�������� ���� ������������ ����� ���� ������ ������� ����� �������
		goto l;
	else
		return;
}

