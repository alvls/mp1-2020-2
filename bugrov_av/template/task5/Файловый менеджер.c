/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� ����������� / �������� �������.

������� ������ :
���� �� ����������, � ������� ���������� ������������� ����������.
����� ����������.
�������� ������ :
��������������� ������ ���� ������ � ��������� �������.
����� ����������.
��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.

��������� ������ ������������� ������ � ������������� ����������� ����������, ������� �������� :
����������� ����� ���� �� ��������� ��������;
����������� ������ ������ ����������;
����������� ��������� ���������������� ������ ������ � ��������� �������.
C����� ������� ���������� :
���������
�������
���������
��������
�����
�����
���������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  // �� ���� �������
#include <time.h>  
#include <locale.h>
#include <omp.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
void bubble();
void choice();
void insert();
void merge();// � ����� ���������� ����� ��� ���������
void arr_merger();
void Hoar();
void Shell();// ��� ���������, ��� � ����
void counting();
int increment();
void printer();
void menu();
double worktime; //����� ������ ���������� (����� ����� lf)
typedef struct fileinf
{
    char name[_MAX_PATH];
    int size;
} fileinf;
int count = 0;
fileinf* manager();
fileinf min_finder();
int main(void)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    system("pause");
}
void printer(fileinf* list, int size)
{
    int i, a, a_clean, flag = 0;
    printf("������ ������������. ��� �� ������ ��� �������:\n1. �� �����������\n2. �� ��������\n");
    do {
        do
        {
            scanf("%d", &a);
        } while (getchar() != '\n');
        switch (a)
        {
        case 1:
            printf("��� �����");
            for (i = 0; i < 69; i++)
                printf(" ");
            printf("������\n");
            for (i = 0; i < size; i++)
            {
                printf("%-77s %d ����\n", list[i].name, list[i].size);
            }
            printf("\n����� ����������: %lf\n\n", worktime);
            break;
        case 2:
            printf("��� �����");
            for (i = 0; i < 69; i++)
                printf(" ");
            printf("������\n");
            for (i = size - 1; i >= 0; i--)
            {
                printf("%-77s %d ����\n", list[i].name, list[i].size);
            }
            printf("\n����� ����������: %lf\n\n", worktime);
            break;
        default:
            printf("�� ������� �� ��� ������, �������� ������\n");
            printf("�����������:\n1. �� �����������\n2. �� ��������\n");
            flag = 1;
        }
    } while (flag);
}
void menu()
{
    fileinf* list;
    setlocale(LC_ALL, "Russian");
    int a, a_clean, flag = 0;
    char answer;//����� �� ������ � ������ �� ���������
    printf("");
    list = manager();
    printf("\n");
    do
    {
        if (flag == 2)
            printf("�� ������ ����� ������� ����� ����������: \n");
        else
            printf("������� ����� - ����� ����������:\n");
        printf("1) C��������� ���������\n2) ���������� �������\n3) ���������� ���������\n4) ���������� ��������\n5) ���������� �����\n6) ���������� ����a\n7) ���������� ��������� \n8)������� ����������� �������\n");
        printf("��� �������� 0 ��� ������\n");
        do
        {
            a_clean = scanf("%i", &a);
        } while (getchar() != '\n'&& a_clean);
        if (a >= 0 && a <= 8)
            switch (a)
            {
            case 0:
                printf("�� �������, ��� ������ �����? y (���������� ���������) - ��, ����� ������ ������ - ���\n");
                scanf("%c", &answer);
                if (answer == 'y')
                {
                    printf("�� ��������! �������, �� �������� ��������!\n");
                    flag = 0;
                }
                else
                    flag = 2;
                break;
            case 1:
                printf("\n");
                bubble(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 2:
                printf("\n");
                choice(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 3:
                printf("\n");
                insert(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 4:
                printf("\n");
                merge(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 5:
                printf("\n");
                Hoar(list, 0, count - 1);
                printer(list, count);
                flag = 2;
                break;
            case 6:
                printf("\n");
                Shell(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 7:
                printf("\n");
                counting(list, count);
                printer(list, count);
                flag = 2;
                break;
            case 8:
                printf("\n");
                menu();
                break;
            }
        else
        {
            printf("������ �����, ������� ��� ���, ����������\n");
            flag = 2;
        }
    } while (flag!=0);
}
fileinf* manager()// ���������� ����������� ������ � �������� ������������� ������ � ��������, �������� �������������
{
    //setlocale(LC_ALL, "Russian");
    struct _finddata_t c_file;//���������, ��������� �� ������ ��������� (����������� ����������� �����)
    intptr_t hFile;//
    char path[255];
    int flag = 0;
    int tmp_count = 0;
    int i, j;
    fileinf* list;
    printf("������� ���� �� ��������, � ������� ����� �������� ��� �����.\n� ���� ��� �������� ������������ ���� ���� �������, ���� ���� �������� ����.\n� ����� ��������� ���� � ��������\n");
    do {
        gets(path);
        for (i = 0; i < 200 && path[i] != '\0'; i++)
        {
            if (path[i] == '/' && path[i + 1] != '/')
                path[i] = '\\';
        }
        if ((hFile = _findfirst(path, &c_file)) == -1L)// ������� ������ ���� �� ����� path, ����� ���������� � �� ����, ����� �� ������ ����, �� hFile ��� �������� - 1 � ���� ����
        {
            printf("�� ���������� ���� �� ���� ������� �� ������ �����!\n");
            printf("������� ���� ��� ���\n");
            flag = 1;
        }
        else
        {
            do
            {
                count++;
            } while (_findnext(hFile, &c_file) == 0);// ����� �������
            _findclose(hFile);// �������� ������
            count -= 2;
            list = (fileinf*)malloc(sizeof(fileinf) * count);
            if (list == 0)
                return;
            tmp_count = 0;
            hFile = _findfirst(path, &c_file);
            printf("��� �����");
            for (i = 0; i < 69; i++)
                printf(" ");
            printf("������\n");
            do
            {
                if (tmp_count >= 2)
                {
                    strcpy(list[tmp_count - 2].name, c_file.name);
                    list[tmp_count - 2].size = c_file.size;
                    printf("%-77s", list[tmp_count - 2].name);////////////////////////////////////////////////////////////////////////////////////////////////����� ��������, ���� ����� �����. ��, ����� �����))
                    printf(" %d\n", list[tmp_count - 2].size);
                }
                tmp_count++;
            } while (_findnext(hFile, &c_file) == 0);
            _findclose(hFile);
            return list;
        }
    } while (flag);
}
void bubble(fileinf* a, int size) // ��������
{
    fileinf k;// ��� �������� ������� ��������� �������
    int i, j;// ��������
    double t1, t2;//�����
    int met;
    t1 = omp_get_wtime();//����� �������
    for (i = 0; i < size; i++)
    {
        met = 0;
        for (j = 0; j < size-i-1; j++) 
            if (a[j + 1].size < a[j].size)
            {
                met++;
                k = a[j + 1];
                a[j + 1] = a[j];
                a[j] = k;
            }
        if (met == 0)
            break;
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void choice(fileinf* a, int size) // ��������
{
    fileinf k;// ��� �������� ������� ��������
    int min_ind;// ������ ������������ ��������
    int i, j;// ��������
    double t1, t2;//�����
    t1 = omp_get_wtime();
    for (i = 0; i < size; i++)
    { 
        min_ind = i; // ����������� ������� �������� ���������� ������
        k = a[min_ind]; //����������� �������������� ���������� �������� i-���� ��������
        for (j = i + 1; j < size; j++)	// ���� ������ ����������� ��������
            if (a[j].size < k.size) // ���������� ��������� ������� � min_ind-��
            {
                min_ind = j; // ������ ������ ����������� ��������
                k = a[min_ind]; // ������ �������� �, ����� ����� ���������� ����������
            }
        a[min_ind] = a[i];
        a[i] = k;
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������    
}
void insert(fileinf* a, int size) // ��������
{
    fileinf k;// ��� �������� ������� ��������� �������
    int i, j;// ��������
    double t1, t2;//�����
    fileinf tmp; // ��������� ���������� ��� �������� �������� ��������
    tmp = a[0];
    t1 = omp_get_wtime();
    a[0] = min_finder(a, size);
    for (i = 1; i < size; i++)
    {
        k = a[i];
        for (j = i - 1; a[j].size > k.size; j--)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
    for (j = 1; j < size && a[j].size < tmp.size; j++) // ���������� ����� �������� ��������
        a[j - 1] = a[j];
    a[j - 1] = tmp; // ������� �������� �������� �� ��������������� �����
    t2 = omp_get_wtime(); // �����
    worktime = t2 - t1;// ��������� ��������
}
fileinf min_finder(fileinf* a, int size) // ��������
{
    fileinf min;
    int i;
    min = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i].size < min.size)
            min = a[i];
    }
    return min;
}
void merge(fileinf* a, int size)//������-�� � �������� ����������� ���������� 
{
    double t1, t2;//�����
    int step = 1; // ��� ��������� ������������������
    fileinf* temp; // �������������� ������
    t1 = omp_get_wtime();
    temp = (int*)malloc(size * sizeof(fileinf));//�������� �������
    while (step < size) // ���� ��� ������ ����� �������
    {
        int ind = 0; // ������ ��������� �������
        int left = 0; // ����� ������� �������
        int mid = left + step; // �������� �������
        int right = left + step * 2; // ������ ������� �������
        int i; //  ������ ������� ����
        int j; // ������ ������� ����
        do
        {
            mid = mid < size ? mid : size; // ����������� ������� �� ������� �� ������� ������������������
            right = right < size ? right : size;
            for (i = left, j = mid; i < mid && j < right; ) // ���� i1 �� ����� �� �������� � i2 �� ����� �� �����
            {
                if (a[i].size < a[j].size)
                {
                    temp[ind++] = a[i++]; // ��������� ������� ��������������� �������
                } 
                else
                {
                    temp[ind++] = a[j++];
                }
            }
            // ��� i < mid ��� j < right - ������ ���� �� ������� ��� while ����� �����������
            while (i < mid)
                temp[ind++] = a[i++]; // ������� ���������� �������� ����������� ��������
            while (j < right)
                temp[ind++] = a[j++]; // � �������������� ������
            left += step * 2; // ������������ �� ��������� ����������� �������
            mid += step * 2;
            right += step * 2;
        } while (left < size); // ���� ����� ������� ������������ ������� - � �������� �����������������
        for (i = 0; i < size; i++) // ��������� ���������������� �������
            a[i] = temp[i];
        step *= 2; // ����������� � 2 ���� ��� ���������
    }
        free(temp);
        t2 = omp_get_wtime();// �����
        worktime = t2 - t1;// ��������� ��������
}
void Hoar(fileinf* a, int left, int right) // ��������
{
    double t1, t2;//�����
    int i = left, j = right;
    fileinf tmp;//����� ���� �������������� �������
    fileinf x;
    t1 = omp_get_wtime();
    x = a[(left + right) / 2];
    // �������� ������� �� ���������� ������� �� ��� �����, ���� �� ������� �� ��������� ������
    // �������� ����� ����� �� ����������� ��������� ������ �����. 
    // ��� ����� �������� ������� �������, ����� ���������, �� � ���������� �����
    do {
        while (a[i].size < x.size)
            i++;
        while (a[j].size > x.size)
            j--;

        if (i <= j)
        {
            if (i < j) //������������
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    // ����������� ������ ���������� � �������� �������
    if (i < right)
        Hoar(a, i, right);
    if (left < j)
        Hoar(a, left, j);
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
int increment(int inc[], int size) // ��������
{
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);
    return s > 0 ? --s : 0;// if (s>0) return --s; else return 0;
}
void Shell(fileinf* a, int size) // ��������
{
    int k;// ��� �������� ������� ��������� �������
    int i, j;// ��������
    double t1, t2;//�����
    fileinf tmp;// ��� �������
    int seq[40], inc;
    int s;
    t1 = omp_get_wtime();
    // ���������� ������������������ ����������
    s = increment(seq, size);
    while (s >= 0) {
        // ���������� ��������� � ������������ inc[] 
        inc = seq[s--];
        for (i = inc; i < size; i++) {
             tmp = a[i];
            for (j = i - inc; (j >= 0) && (a[j].size > tmp.size); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = tmp;
        }
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void counting(fileinf* a, int size) 
{
    double t1, t2;//�����
   // ���� ��������, ��� ������� ���������� ����� ���� �������� 30 ������ (� �������� ���� � ��������� �� ������ ������). ������ ���������, ��� � ���������
    int i, j;//��������
    int size_of_tmp; //���������� �������� (��� ������� ��������)
    int* count; //������ �������� ��������
    //int* counter;//������� ������� �������� �������� (��� ������������ � ������ �����), ��� �����������
    fileinf** _tmp;//������ ��������, � ������� ����� ��������� ���������
    const int nul = -1;//��� ����, ����� ����� ���� �� ��������
    int max = a[0].size, min = a[0].size, k = 0;// k ��� �������� �������
    t1 = omp_get_wtime();
    //nul.name = a[0].name;
    for (i = 0; i < size; i++)
        if (max < a[i].size)//������� ������������ �������
        {
            max = a[i].size;
        }
        else
            if (min > a[i].size)//������� ����������� �������
                min = a[i].size;
    size_of_tmp = max - min + 1;
    count = (int*)malloc(sizeof(int) * size_of_tmp);// ������ ��� ��������
    for (i = 0; i < size_of_tmp; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[a[i].size - min]++; // �������� ���������� �������� ������� �������
    }
    _tmp = (fileinf**)malloc(sizeof(fileinf*) * size_of_tmp);//������ �������� �������� �������� ������
    for (i = 0; i < size_of_tmp; i++)
        _tmp[i] = (fileinf*)malloc(sizeof(fileinf) * count[i]);//��� ������� ���������� ������� �������� ����� ������
    for (i = 0; i < size_of_tmp; i++)
        for (j = 0; j < count[i]; j++)
        {
            _tmp[i][j].size = nul; //���������
        }
    for (i = 0; i < size; i++)//�� size, �.�. ��������� ��� �������� �� �
    {
        j = 0;
        while (_tmp[a[i].size - min][j].size != nul)
            j++;
        _tmp[a[i].size - min][j] = a[i];//�������� ��������� ������� �� �������
    }
    //� �� ����, ��� � ���� ���������� ������� ����� �����, �� � �� ������� �� ������. ������, ������ ����� ������� ���� ����� ���������� ����� Shift+Enter
    /// <summary>
    ///
    /// </summary>
    /// <param name="a"></param>
    /// <param name="size"></param>
    k = 0;
    for (i = 0; i < size_of_tmp; i++)//������� ������� �� ���������� ��������� � ����������
        for (j = 0; j < count[i]; j++)//��������� �� �������, ����� �� ���������
        {
            a[k] = _tmp[i][j];
            k++;
        }
    for (i = 0; i < size_of_tmp; i++)
        free(_tmp[i]);
    free(count); 
    /*int min, max, i, k = 0, c;
    fileinf* buff;
    int* count;
    min = max = a[0].size;
    for (i = 1; i < size; i++) {
        if (a[i].size < min)
            min = a[i].size;
        if (a[i].size > max)
            max = a[i].size;
    }
    c = max - min + 1;          
    buff = (fileinf*)malloc(sizeof (fileinf) * c * size);
    count = (int*)malloc(sizeof(int) * c);
    for (i = 0; i < c; i++)
        count[i] = 0;
    for (i = 0; i <size; i++)
        buff[size * (a[i].size - min) + count[a[i].size - min]++] = a[i];
    for (i = 0; i < c; i++)
        for(int j = 0; j < count[i] ; j++)
            a[k++] = buff[size * i + j];            
    free(count);
    free(buff);*/
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
