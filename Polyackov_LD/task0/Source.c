//����������, ������ �������� ������������ ���� ����������� �� ��������� � ��������� ������������ ������� � ���������. 
//�������� ������ ������ ��������� �������������. ��������� ��������� ������ �������� �� �����.

//������������� ������ ���������

#include <stdio.h>
#include <math.h> //��� � �����, ����� ��� ���������� ����������� �����

void main()
{
	//���������� ����������

	double xone, yone, rone;//x1, y1 - ���������� ������ ���������� 1; r1 - ������ ������ ����������
	double xtwo, ytwo, rtwo;//x2, y2 - ���������� ������ ���������� 2; r2 - ������ ������ ����������
	double cline; //����� �����, ����������� ������ �����������
	int pos; //������� ������������ ������, ����� �������� � �������� ����
	//double pr;//���������� ��� ��� �������� � ��������� ������������� �������� - �� ��� ������
	
	//����� � �������� �������� ������������� �����, ����� ��������� �������� �������� �� ������� ����� ������������� �������� ���� ����������

	rone = -10;
	rtwo = -11;

	//���� ������ ����������

	printf("Warning! 1.5 != 1,5\n\n");

	printf("Enter the coordinates of the center of the first circle (x1;y1)\n\t"); //������� ���������� ������ ������ ����������
	scanf_s("%lf %lf",&xone,&yone);
	
	
	while (rone <= 0) //��������� ������� �������� �������, �������� ��� 0
		{
			printf("Enter the radius of the first circle (necessarily greater than zero)\n\t");
			scanf_s("%lf", &rone);
		}
	
	printf("Enter the coordinates of the center of the second circle (x2;y2)\n\t"); //������� ���������� ������ ������ ����������
	scanf_s("%lf %lf",&xtwo,&ytwo);
	
	while (rtwo <= 0) //��������� ������� �������� �������, �������� ��� 0
		{
			printf("Enter the radius of the second circle (necessarily greater than zero)\n\t");
			scanf_s("%lf", &rtwo);
		}
	
	//��������� ���������� ����������
	cline = sqrt((xone - xtwo) * (xone - xtwo) + (yone - ytwo)*(yone - ytwo));

	//������ ���� ����� ����� ��� ����� �������� - �� ��� ������
	
	system("cls"); //������� ��������� ������, ����� ������� �������� ���� ���������� ��� ������������ ������ 
	
	printf("Entered variable values\n"); //�������� �������� ����������
	printf("x1 = %lf\n", xone);
	printf("y1 = %lf\n", yone);
	printf("r1 = %lf\n", rone);
	printf("x2 = %lf\n", xtwo);
	printf("y2 = %lf\n", ytwo);
	printf("r2 = %lf\n", rtwo);
	printf("Length of the line connecting the centers of the circles = %lf\n\n", cline); //����� �����, ����������� ������ �����������

	//������������ ������������ �����������: 
	// pos=1 - ��������� ( �������� ��������������� ���������� ����� ) 
	// pos=2 - ������������ � ����� ����� ������� ������� ( cline=r1+r2 )
	// pos=3 - ������������ � ����� ����� ���������� ������� ( cline=|r1-r2|; ������ ������ ��� �� �� �������� �������� �������, �� ����� �� �������� ����� ������ ������� ���������� )
	// pos=4 - �� ������������ �����, ��� ��� ����������� � ������ ������ ������������ ���� ����� ( cline>r1+r2 )
	// pos=5 - ���� ���������� ������ ������ ( cline<|r1-r2|; ������ ����������; ��)
	// pos=6 - ������������ � ���� ������ (����� ������� ��� ���������� �������, ��� � � ������ ��������� ���������� pos; �� ������ ������ �������: |r1-r2|<cline<r1+r2)

	pos = 6; //��� ���������� ������� ����� �������� ���� ���������� ��������� �������, ���� pos ��������� ����� 6, �� ���������� ������������
		
	if ((xone == xtwo) && (yone == ytwo) && (rone == rtwo))
	{
		pos = 1;
	}
	
	//��� ��� ������ �������� ������ ��� int, �� ������� ������� ������� ��������

	if (rone > rtwo)
	{
		if (cline == (rone - rtwo))
		{
			pos = 3;
		}
		if (cline < (rone - rtwo))
		{
			pos = 5;
		}
	}
	if (rone < rtwo)
	{
		if (cline == (rtwo - rone))
		{
			pos = 3;
		}
		if (cline < (rtwo - rone))
		{
			pos = 5;
		}
	}

	if (cline == (rone + rtwo))
	{
		pos = 2;
	}
	if (cline > (rone + rtwo))
	{
		pos = 4;
	}

	//printf("pos = %d\n",pos); //�� ��� ������

	switch (pos)
	{
	case 1:
	{
		printf("The circles are equal"); //���������� ���������
		break;
	}
	case 2:
	{
		printf("Circles intersect at one point externally"); //���������� ������������ � ����� ����� ������� �������
		break;
	}
	case 3:
	{
		printf("Circles intersect at one point internally"); //���������� ������������ � ����� ����� ���������� �������
		break;
	}
	case 4:
	{
		printf("The circles are located in different places relative to each other"); //���������� ����������� � ������ ������ ������������ ���� �����
		break;
	}
	case 5:
	{
		printf("One circle inside another circle"); //���� ���������� ������ ������
		break;
	}
	case 6:
	{
		printf("The circles intersect at two points"); //���������� ������������ � ���� ������
		break;
	}
	}
	
	scanf_s("%lf",&xone); //����� ���� �������� � ������, ���� �� ���� ���� � �������� ��� ���������� ��������
}
