#include <stdio.h>    
#include <math.h> 
#include <stdlib.h>
#include <time.h>  
#include <limits.h>
#include <locale.h>
#define N 6  //���������� ������� � ����
int col;//���������� ��������� ���� (��������� �� �����)
int n;//����� ��������� � ����, ������������ � ������� sum 
long double argument(long double x)//��� ��� ������������������ ������� �������������, �� ��� ������ ���� ������� �������� x � ��������� �� -2�� �� 2 �� (�������� ������������������ ������� ��� ���� �� ��������). ��� ���� ������� ��� �>32 �������� ��������� ��������, �.�. ���� ������������ ���������� ���� long double
{
    long double two_pi = 6.2831853071795865;//2 ��
    x = fmod(x, two_pi);
    return(x);
}
long double* exp_elem(int size, long double x, long double pogr)//������� ��������� ���� ������� ��� ����������. size - ����� ���������, pogr - �������� ����������, �������� �������������
{
    int i, k = 0;//k - ����� ��� ���������� ��������� ���� (����������� ����)
    long double* elem;
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 ��� ���������� � ����� ������� �������� �� ��������� 0 (��� ������ ����� ������) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (elem[i - 1] * x) / (k + 1);//������ ��������� ������� ����������� ����� ���������� ����������� �������� �� �/(�+1). k+1 �������� ���������� ���������� ��� ������� ����������
        k++;//
        if (pogr > fabs(elem[i]))//������ �����������
            break;
    }
    elem[i + 1] = 0;//0 ��� ������ ����� ������
    n = i;//size
    return elem;//���������� ������ ������������ ��������� �� ���� �������
    free(elem);
}

long double* sin_elem(int size, long double x, long double pogr)//������� ��������� ���� ������� ��� ������. size - ����� ���������, pogr - �������� ����������, �������� �������������
{
    int i, k = 1;//k - ����� ��� ���������� ��������� ���� (����������� ����)
    long double* elem;
    x = argument(x);
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 ��� ���������� � ����� ������� �������� �� ��������� 0 (��� ������ ����� ������) 
    elem[0] = x;
    for (i = 1; i < size; i++)
    {
        elem[i] = (-1) * (elem[i - 1] * x * x) / ((k + 1) * (k + 2));//������ ��������� ������� ����������� ����� ���������� ����������� �������� �� �^2/((�+1)*(k+2)). (�+1)*(k+2) �������� ���������� ���������� ��� ������� ����������
        k = k + 2;
        if (pogr > fabs(elem[i]))//������ �����������
            break;
    }
    elem[i + 1] = 0;//0 ��� ������ ����� ������
    n = i;
    return elem;//���������� ������ ������������ ��������� �� ���� �������
    free(elem);
}

long double* cos_elem(int size, long double x, long double pogr)//������� ��������� ���� ������� ��� ��������. size - ����� ���������, pogr - �������� ����������, �������� �������������
{
    int i, k = 0;//k - ����� ��� ���������� ��������� ���� (����������� ����)
    long double* elem;
    x = argument(x);
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 ��� ���������� � ����� ������� �������� �� ��������� 0 (��� ������ ����� ������) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (-1) * (elem[i - 1] * x * x) / ((k + 1) * (k + 2));//������ ��������� ������� ����������� ����� ���������� ����������� �������� �� �^2/((�+1)*(k+2)). (�+1)*(k+2) �������� ���������� ���������� ��� ������� ����������
        k = k + 2;
        if (pogr > fabs(elem[i]))//������ �����������
            break;
    }
    elem[i + 1] = 0;//0 ��� ������ ����� ������
    n = i;
    return elem;//���������� ������ ������������ ��������� �� ���� �������
    free(elem);
}

long double* sqrt_elem(int size, long double x, long double pogr)//������� ��������� ���� ������� ��� ��������. size - ����� ���������, pogr - �������� ����������, �������� �������������
{
    int i, k = 0;//k - ����� ��� ���������� ��������� ���� (����������� ����)
    long double* elem;
    elem = (long double*)malloc(sizeof(long double) * (size + 1));//size+1 ��� ���������� � ����� ������� �������� �� ��������� 0 (��� ������ ����� ������) 
    elem[0] = 1;
    for (i = 1; i < size; i++)
    {
        elem[i] = (elem[i - 1] * x* (0.5 - k)) / (k + 1);//������ ��������� ������� ����������� ����� ���������� ����������� �������� �� �*(0.5 - k)/(�+1). (�+1) �������� ���������� ���������� ��� ������� ����������
        k++;
        if (pogr > fabs(elem[i]))//������ �����������
            break;
    }
    elem[i + 1] = 0;//0 ��� ������ ����� ������
    n = i;
    return elem;//���������� ������ ������������ ��������� �� ���� �������
    free(elem);
}

long double sum(long double* (*fun)(int, long double, long double), long double x, long double pogr)//��������� �������, ����������� �������� ����
{
    int i = 0;
    long double sum = 0;//�������� �������
    long double* elem;//��� �������� ��������� ������� �������
    elem = (long double*)malloc(sizeof(long double) * n);//n - ����� ��������� � ���� (�������� �������������) 
    elem = fun(n, x, pogr);//��������� �� ���� �� ���� �������: exp_elem, sin_elem, cos_elem
    while ((elem[i] != 0) && (i < n))//���� �� ������ �� ������� 0 (��������� ��� �������� ��� �������� ��������) ��� ���� �� ������ �� ���������� ������������ ��������
    {
        sum = sum + elem[i];//���� �������� ������������
        i++;
    }
    col = i;//���������� ��������� ����
    return sum;
}

long double tg1(long double* (*fun)(int, long double, long double), long double x, long double pogr)//����� ��������� �� ������� �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
{
    int i = 2, size=n;//size - ����� ��������� ����
    long double s = x, s0 = tan(x);
    x = argument(x);
    while ((pogr < fabs(s - s0)) && (i < size))//������ �������� - ������ �����������
    {
        n = i;//
        s = (sum(sin_elem, x, 0) / sum(cos_elem, x, 0));//������� �������������� ��� ��������� �������� (��� ��� ���� � �������, ���������, � �����������) ������. ������� ������������ ������� ������������ �������� ������ � ��������
        i++;
    }
    col = i;//���������� ��������� ����
    return s;
}

long double ctg1(long double* (*fun)(int, long double, long double), long double x, long double pogr)//����� ��������� �� ������� �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
{
    int i = 2, size = n;//size - ����� ��������� ����
    long double s = 1/x, s0 = cos(x)/sin(x);
    x = argument(x);
    while ((pogr < fabs(s - s0)) && (i < size))//������ �������� - ������ �����������
    {
        n = i;//
        s = (sum(cos_elem, x, 0) / sum(sin_elem, x, 0));//������������ ������� ������������ �������� ������ � ��������
        i++;
    }
    col = i;//���������� ��������� ����
    return s;
}

void clean(void)//������� ����� �����
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void showmenu()
{
    char* menu[N] = { "���������� � ������� �", "�����", "�������", "�������", "���������� ������ �� 1+�", "���������" };//������ � ���������� �������
    short int menu_number[N] = { 1, 2, 3, 4, 5, 6 };//������ � �������� ������� ������ ����
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d", menu_number[i]);
        printf(". %s\n", menu[i]);
    }
    printf("������� ����� �������, ������������ �������� ������� ������ ��������: ");
}

int setdlina(long double t)//���������� ����� ������������� �����(� 7 ������� ����� �������)
{
    int B = t, i=0;
    while (B > 0)
    {
        B = B / 10;
        i++;
    }
    return(i + 8);//�.�. ��� ����������� ����� � ������� ������ (,)
}
void probel_print(int t)//�������� ������ ����� �������� ��� ������������, t-����� ��������
{
    for (int i = 0; i < t; i++)//�������� �������
        printf(" ");
}
void main()
{
    int number, num_function, size, count, i, flag=0;//number - ����� ������, num_function - ����� ������� �� ����, size - ����� ��������� ���� (�������� �������������), count - ������������ ��� ������������ ����� �� 2 ������; flag - ����������, ��������� �� x � ����������
    long double x = 0, pogr, etal, raznica, res;//pogr - �������� ����������, �������� �������������; etal - �������� �� ��������� �������; res - �������� �� ����������� �������; raznica - ������ ������� ����� ��������� ��������� � ����������� ������ ����������� �������
    long double (*function_elem)(long double, long double, int)= NULL;//��������� �� ���� �� �������: exp_elem, sin_elem, cos_elem (2 �����)
    long double (*function_sum)(long double* (*fun)(int, long double, long double), long double, long double) = NULL;//��������� �� �������, ������������ �������� ������� ������ (2 �����)
    setlocale(LC_ALL, "Russian");
    printf("� ������ ������ ������������ ����������� ������ ������� � �������� �����.\n");
    printf("�� ������ ������ ������������ �������� �����������.\n");
    printf("������� ����� ������ ������: \n");
    scanf_s("%d", &number);
    while ((number != 1) && (number != 2))
    {
        clean();
        printf("������� ������������ �������� ������ ������, ����������� ������: ");
        scanf_s("%d", &number);
    }
    showmenu();
    scanf_s("%d", &num_function);
    while ((num_function != 1) && (num_function !=2) && (num_function != 3) && (num_function != 4) && (num_function != 5) && (num_function != 6))//
    {
        clean();
        printf("������� ������������ �������� ������ �������, ����������� ������: ");
        scanf_s("%d", &num_function);
    }
    if (number == 1)//������ �����
    {
        printf("������� ����� ��������� ����: ");
        scanf_s("%d", &size);
        while (size <= 0)
        {
            clean();
            printf("������� ������������ �������� ����� ��������� ����, ����������� ������: ");
            scanf_s("%d", &size);
        }
        printf("������� x (� ������ ������������������ ������� ������� �������� � ��������).\n"); 
        printf("��� ���� ��������� ������� ����� �������:");
        flag=scanf_s("%lf", &x);
        while (flag == 0)
        {
            clean();
            printf("������� ������������ �������� x, ����������� ������: ");
            flag=scanf_s("%lf", &x);
        }
        printf("������� ��������, � ������� ���������� ��������� �������� ������� (��� ���� ��������� ������� ����� �������): ");
        scanf_s("%lf", &pogr);
        while (pogr < 0)
        {
            clean();
            printf("������� ������������ �������� �������� �����������, ����������� ������: ");
            scanf_s("%d", &pogr);
        }
        n = size;
        printf("\n");
        printf("\n");
        switch (num_function)//���������� � ������ �����������
        {
        case 1://����������
            printf("���������� � ������� �\n");
            res = sum(exp_elem, x, pogr);
            etal = exp(x);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));
            break;
        case 2://�����
            printf("�����\n");
            res = sum(sin_elem, x, pogr);
            etal = sin(x);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));
            break;
        case 3://�������
            printf("�������\n");
            res = sum(cos_elem, x, pogr);
            etal = cos(x);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));
            break;
        case 4://�������
            printf("�������\n");
            res = tg1(cos_elem, x, pogr);
            etal = tan(x);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));//����� ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            break;
        case 5://���������� ������ (�������������� �����������)
            printf("���������� ������ �� 1+�\n");
            res = sum(sqrt_elem, x, pogr);
            etal = sqrt(x+1);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));//����� ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            break;
        case 6://���������
            printf("���������\n");
            res = ctg1(cos_elem, x, pogr);
            etal = cos(x)/sin(x);
            printf("������� = %lf\n", res);
            printf("��������� �������� = %lf\n", etal);
            printf("������� ����� ������� � ��������� ��������� = %lf\n", fabs(res - etal));//����� ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            break;
        }
        printf("���������� ����������� ��������� ���� = %d\n", col);
    }
    if (number == 2)//2 ����� 
    {
        printf("������� ����� �������������: ");
        scanf_s("%d", &size);
        while ((size <= 0) || (size>25))
        {
            clean();
            printf("������� ������������ �������� ����� �������������, ����������� ������: ");
            scanf_s("%d", &size);
        }
        printf("������� x (� ������ ������������������ ������� ������� �������� � ��������).\n");
        printf("��� ���� ��������� ������� ����� �������:");
        flag = scanf_s("%lf", &x);
        while (flag == 0)
        {
            clean();
            printf("������� ������������ �������� x, ����������� ������: ");
            flag = scanf_s("%lf", &x);
        }
        printf("\n");
        printf("\n");
        switch (num_function)//�������� ����� ��������� �� ������� ������ �������
        {
        case 1://����������
            function_sum = sum;
            function_elem = exp_elem;
            etal = exp(x);
            printf("���������� � ������� �\n");
            break;
        case 2://�����
            function_sum = sum;
            function_elem = sin_elem;
            etal = sin(x);
            printf("�����\n");
            break;
        case 3://�������
            function_sum = sum;
            function_elem = cos_elem;
            etal = cos(x);
            printf("�������\n");
            break;
        case 4://�������
            function_sum = tg1;
            function_elem = cos_elem;//� ������ ������ ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            etal = tan(x);
            printf("�������\n");
            break;
        case 5://���������� ������ (�������������� �����������)
            function_sum = sum;
            function_elem = sqrt_elem;//� ������ ������ ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            etal = sqrt(x+1);
            printf("���������� ������ �� 1+�\n");
            break;
        case 6://���������
            function_sum = ctg1;
            function_elem = cos_elem;//� ������ ������ ��������� �� ������� cos_elem �� ���������, �� ��� ��������� ���������� 2-�� ������ �� ������������ � ������ ������
            etal = (cos(x) / sin(x));
            printf("���������\n");
            break;
        }
        printf("��������� ��������: %lf\n", etal);
        printf("����� ������������       ������ �������� �������         ������� ����� ������� � ��������� ���������\n");//���������
        for (i = 1; i <= size; i++)//��������� � ������ ����������� ������������ 
        {
            count = 0;
            n = i;
            res = function_sum(function_elem, x, 0);
            raznica = fabs(etal - res);
            count=printf("%-2d %38.7lf", i, res);//������������ ������ 2-� �������� ���������� �������������, � count ������������ ����� ������������ ������ (� ������ ��������)
            count = 83 - count - setdlina(raznica);//83 - ����� ���� ������, � count ������� ����� ��������, ����������� ��� ������������ ���������� ������� 
            if (fabs(raznica) < 1)
                count--;
            probel_print(count);
            printf("%.7lf\n", raznica);
        }
    }
    system("pause");
}