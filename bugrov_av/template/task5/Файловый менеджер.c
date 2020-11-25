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
/*#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  


// strcmp - */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  // �� ���� �������
#include <time.h>  
#include <locale.h>
#include <omp.h>
#include <malloc.h>
#include <string.h>
void bubble();
void choice();
void insert();
void merge();// � ����� ���������� ����� ��� ���������
void arr_merger();
void Hoar();
void Shell();// ��� ���������, ��� � ����
void counting();
int min_finder();//�������� ���, ���� ������ ����� �� �� ����� ��������� (�� �����, �� ���� �����������). ����� �����, ��������
int increment();
void menu();
double worktime; //����� ������ ���������� (����� ����� lf)
typedef struct fileinf
{
    char name[_MAX_PATH];
    int size;
} fileinf;
int count;
int main(void)
{
   // int size = 3010, a[3081];
   // int i;
    //setlocale(LC_ALL, "Russian");
    //menu();
   /* srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 3050;
    }
    Hoar(a, 0, size-1);//����� �������� ����������
    for (i=0; i<size; i++)
    printf("a[%d]=%d", i, a[i]);
    printf("worktime is %f\n", worktime);
    //printf("\n\n");*/
    system("pause");
}
void bubble(fileinf* a, int size) // ��������
{
    int k;// ��� �������� ������� ��������� �������
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
                k = a[j + 1].size;
                a[j + 1].size = a[j].size;
                a[j].size = k;
            }
        if (met == 0)
            break;
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void choice(int a[], int size) // ��������
{
    int k, min;// ��� �������� ������� ��������� �������
    int min_ind;// ������ ������������ ��������
    int i, j;// ��������
    double t1, t2;//�����
    t1 = omp_get_wtime();
    for (i = 0; i < size; i++)
    { 
        min_ind = i; // ����������� ������� �������� ���������� ������
        k = a[min_ind]; //����������� �������������� ���������� �������� i-���� ��������
        for (j = i + 1; j < size; j++)	// ���� ������ ����������� ��������
            if (a[j] < k) // ���������� ��������� ������� � min_ind-��
            {
                min_ind = j; // ������ ������ ����������� ��������
                k = a[min_ind]; // ������ �������� �, ����� ����� ���������� ����������
            }
        a[min_ind] = a[i];
        a[i] = k;
        //������ �����
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void insert(int a[], int size) // ��������
{
    int k, min;// ��� �������� ������� ��������� �������
    int i, j;// ��������
    double t1, t2;//�����
    int tmp; // ��������� ���������� ��� �������� �������� ��������
    tmp = a[0];
    t1 = omp_get_wtime();
    a[0] = min_finder(a, size);
    for (i = 1; i < size; i++)
    {
        k = a[i];
        for (j = i - 1; a[j] > k; j--)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
    for (j = 1; j < size && a[j] < tmp; j++) // ���������� ����� �������� ��������
        a[j - 1] = a[j];
    a[j - 1] = tmp; // ������� �������� �������� �� ��������������� �����
    t2 = omp_get_wtime(); // �����
    worktime = t2 - t1;// ��������� ��������
}
int min_finder(int a[], int size) // ��������
{
    int min;
    int i;
    min = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
void merge(int a[], int left, int right) // ��������
{
    double t1, t2;//�����
    int i; // ������ ������� ����
    int middle; // ���������� �������� ������������������
    int j; // ������ ������� ����
    int* tmp;
    t1 = omp_get_wtime();
    middle = (left + right) / 2;
    i = left;
    j = middle + 1; 
    tmp = (int*)malloc(right * sizeof(int)); // �������������� ������
    if (left == right) return; // ������� ����������
    // ����������� ���������� � ����������� �� ��� ��������
    merge(a, left, middle);
    merge(a, middle + 1, right);
    for (int step = 0; step < right - left + 1; step++) // ��� ���� ��������� ��������������� �������
    {   // ������ � ����������� ������������������ ������� �� ��������� ���� ����� ��� ������� ������� ���� ���� j > right
        if ((j > right) || ((i <= middle) && (a[i] < a[j])))
        {
            tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }
    }
    for (int step = 0; step < right - left + 1; step++)
        a[left + step] = tmp[step];
    free(tmp);
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void Hoar(int a[], int left, int right) // ��������
{
    double t1, t2;//�����
    int i = left, j = right;
    int tmp, x;
    t1 = omp_get_wtime();
    x = a[(left + right) / 2];
    // �������� ������� �� ���������� ������� �� ��� �����, ���� �� ������� �� ��������� ������
    // �������� ����� ����� �� ����������� ��������� ������ �����. 
    // ��� ����� �������� ������� �������, ����� ���������, �� � ���������� �����
    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
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
void Shell(int a[], int size) // ��������
{
    int k;// ��� �������� ������� ��������� �������
    int i, j;// ��������
    double t1, t2;//�����
    int tmp;
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
            for (j = i - inc; (j >= 0) && (a[j] > tmp); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = tmp;
        }
    }
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
void counting(int a[], int size) // ��������
{
    int i, size_of_count;
    int* count;
    int max = a[0], min = a[0], k=0;
    double t1, t2;//�����
    t1 = omp_get_wtime();
    for (i = 0; i < size; i++)
        if (max < a[i])
            max = a[i];
        else
            if (min > a[i])
                min = a[i];
    size_of_count = max - min + 1;
    count = (int*)malloc(sizeof(int) * size_of_count);
    for (i = 0; i < size_of_count; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
        count[a[i] - min]++;
    for (i = 0; i < size_of_count; i++)
        while (count[i]--)
            a[k++] = min + i;
    free(count);
    t2 = omp_get_wtime();// �����
    worktime = t2 - t1;// ��������� ��������
}
/*void menu()
{
    fileinf* list;
    setlocale(LC_ALL, "Russian");
    int a, flag = 0;
    char answer;//����� �� ������ � ������ �� ���������
    printf("");
    list = manager();
    //count = list / (sizeof(fileinf);
    do {
        printf("�������� ������ ����� - ����� ����������:\n");
        printf("1) C��������� ���������\n2) ���������� �������\n3) ���������� ���������\n4) ���������� ��������\n5) ���������� �����\n6) ���������� ����a\n7) ���������� ���������\n");
        printf("��� �������� 0 ��� ������\n");
        do
            a = getchar();
        while (a != EOF && a != '\n');
        a -= '0';
        if (a > 0 && a < 8)
            switch (a)
            {
            case 1:
                bubble(list, count);
                break;
            case 2:
                choice(list, count);
                break;
            case 3:
                insert(list, count);
                break;
            case 4:
                merge(list, 0, count-1);
                break;
            case 5:
                Hoar(list, 0, count - 1);
                break;
            case 6:
                Shell(list, count);
                break;
            case 7:
                counting(list, count);
                break;
            }
        else
            if (!a)
            {
                printf("\n");
                scanf("%c", &answer);
                if (answer == 'y')
                    printf("\n");
                else
                {
                    printf("\n");
                    flag = 1;
                }
            }
    } while (flag);   
}*/
/*fileinf* manager()// ���������� ����������� ������ � �������� ������������� ������ � ��������, �������� �������������
{
    struct _finddata_t c_file;//���������, ��������� �� ������ ��������� (����������� ����������� �����)
    intptr_t hFile;//
    char path[255];
    //char temp1, temp2;
    int tmp_count=0;
    int i, j;
    fileinf* list;
    // Find first file in directory c:\temp
    // _findfirst, _findnext, _findclose �� ����� ������������
    printf("������� ���� �� ��������, � ������� ����� �������� ��� �����");
    fgets(path, 200, stdin);
    for (i = 0; i < 200 && path[i] != '\0'; i++)
    {
        if (path[i] == '/' && path[i + 1] != '/')
            path[i] = '\\';
    }
    path[i] = '*'; i++; path[i] = '\0';
    if ((hFile = _findfirst(path, &c_file)) == -1L)// ������� ������ ���� �� ����� path, ����� ���������� � �� ����, ����� �� ������ ����, �� hFile ��� �������� - 1 � ���� ����
        printf("No files in current directory!\n");
    else
    {     /*(printf("Listing of files\n\n");
     printf("FILE         DATE %24c   SIZE\n", ' ');
     printf("----         ---- %24c   ----\n", ' ');*/
       /* do {
            /* char buffer[30];
             ctime_s(buffer, _countof(buffer), &c_file.time_write);// ����-���� - ����� ���������� ��������� �����, ctime - ���������� ������� �����;
             if (count <= 20)
                 printf("%-12.12s %.24s  %10ld\n", c_file.name, buffer, c_file.size);// c_file.size - ������ ������ �����, c_file.name - ������ ��� �����.*/
           /* count++;
        } while (_findnext(hFile, &c_file) == 0);// ����� �������
        _findclose(hFile);// �������� ������
        list = (fileinf*)malloc(sizeof(fileinf) * count);
        tmp_count = 0;
        do
        {
            strcpy(list[tmp_count].name, c_file.name);
            list[tmp_count++].size = c_file.size;
        } while (_findnext(hFile, &c_file) == 0);
        return list;
    }
}*/