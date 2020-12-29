/*  + ����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� �����������/�������� �������.
������� ������:
    + ���� �� ����������, � ������� ���������� ������������� ����������.
    + ����� ����������.
�������� ������:
    + ��������������� ������ ���� ������ � ��������� �������.
    + ����� ����������.
    + ��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.
    + ��������� ������ ������������� ������ � ������������� ����������� ����������, ������� ��������:
    + ����������� ����� ���� �� ��������� ��������;
    + ����������� ������ ������ ����������;
    + ����������� ��������� ���������������� ������ ������ � ��������� �������.
C����� ������� ����������: ���������, �������, ���������, ��������, �����, �����, ��������� */

#define _CRT_SECURE_NO_WARNINGS

//����������� ���������
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //�������� �� ������� ���� � ����� input output
#include <omp.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //���������� ����� ��� ��������� �������� ����� (���� ����������, �� ��� ����, ����� ������������ ��� ������� ����� � �������� �������)

//��������, ���������� ���������� ���������� �� ������ �����
typedef struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
} oneinf;

//���������, ���������� ����� ���������� �� �����������
typedef struct fullinformationaboutsorts
{
    short typesort; //����� ����������
    short updown; //����������� ��� ��������
    int countoffiles; //���������� ������
    long double timer; //����� ����������
} fullinf; 

//���������� �������
int menu();
void polzsorttype(int i); //������� �� ����� ��������� ������������� ���������� (��� ������� � ������ �� ����� ����)
int getinform(); //����������� ��������� ���������� �� ������
char preobr(char* path); //��������������� ����, �������� �������������, � ����, ������� ����� ���������
int choiceyoursort(int count, oneinf* c_file); //��������� ��������� ���������� �� ����� ����
void printgran(int type, int i); //������ �����
void fullvivod(); //����� ���������� �� ���� �����������
void vozrandubyv(int a); //������� �� ����� ���������� ��� ����������: �� ����������� ��� ��������
void clearscreen(int x, int y); //������� ����� �� �����������
void pipetoxy(int x, int y); //����������� �� �����������
void bubblesort(int count, oneinf* c_file); //���������� ���������
void selectsort(int count, oneinf* c_file); //���������� �������
void insertsort(int count, oneinf* c_file); //���������� ���������
void mergesort(int left, int right, oneinf* c_file); //���������� ��������
void merge(int lefte, int right, oneinf* c_file); //������� ���� ��������
void quicksort(oneinf* c_file, int count); //�����=�������
int shellsort(int count, oneinf* c_file); //���������� �����
int increment(long inc[], int count); //�������������� ������� ��� ���������� �����
int countingsort(int count, oneinf* c_file); //���������� ���������
void vozrastanie(int count, oneinf* c_file); //���� ������������ ������ ���������� �� ��������, �� ��� ������� ���������� ������, ������� ��� ������������ �� ��������
void* checknull(void* arr) //�������� �� ����������� �������� ������������ ������
{
    if (arr == 0)
    {
        printf("��������� ������������. ���������� ������� ������ ����� ��� ����������.\n");
        system("pause");
        getinform();
        return;
    }
    return (arr);
}

//���������� ���������� ����������
fullinf* inf; //������ ���������� �� ������ �� ���������� 
long ind = 0; //���������� ���������� (��� ��������� ������)

void main()
{
    int vixod = -1;
    setlocale(LC_ALL, "Russian"); //��������� �������� �����
    SetConsoleCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    SetConsoleOutputCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    printf(" �����������! � - ���������, ��������� ��� ���������� ������.\n");
    while (vixod != 0)
    {
        vixod = menu();
    }
    system("cls");
    printf("\n");
    printgran(1, 73);
    printf("| �� ��������� ��� ���������� ����� ���������, ������� �� ������������! |\n");
    printgran(1, 73);
    free(inf);
    printf("\n ��������� �������� ������ �������������� �����:");
    for (int i = 0; i < 6; i++)
    {
        printf(" %d...", 5 - i);
        Sleep(900);
        clearscreen(48, 5);
    }
}

int menu()
{
    printgran(1, 61);
    printf("  ������ �� ���������� � ����. ��������, ��� ����� �������:\n\t(1) ������������� ����� � ����� �����\n\t(2) ������� ��� ����������, ���������� �� ����������\n\t(0) ����� �� ���������\n");
    printgran(1, 61);
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 2))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 0) || (vibor > 2))
        {
            printf("������ ������� �� ������������� ����������. ������� ����� �� 0 �� 2.\n");
            while (getchar() != '\n');
        }
    }
    c = getchar();
    switch (vibor)
    {
    case 1:
        system("cls");
        ind++;
        getinform();
        return 1;
    case 2:
        system("cls");
        fullvivod();
        return 2;
    case 0:
        return 0;
    default:
        printf("������, ��������� � ������� � ����");
        break;
    }
}

int getinform()
{
    oneinf* c_file; //� ���� ������� ��������� ��� � ������ ��� ��������� �����
    struct _finddata_t inf_file; //� ��� ��������� ����������� ��� ���������� �� ���������� �����
    intptr_t hFile;
    char path[FILENAME_MAX]; //����, ������� ��� ������������
    int count = 0; //������� ���������� ������
    
    inf = checknull(realloc(inf, ind * sizeof(fullinf)));
    printf("\n ������� ���� � ����� � �������:\n");
    fgets(path, FILENAME_MAX, stdin); //scanf_s � ������ ������ ����� ��������� ������
    system("cls");
    printf("\n �� ����� ����: %s\n", path);
    if (strlen(path) > 2)
    {
        preobr(path); //�������������� ��� ���������
        //printf("��� �������� �������������. �������� ������ ������������� � %s\n", path); //��� �������� �������������
    }
    if ((hFile = _findfirst(path, &inf_file)) == -1L) //��� ����� ���������� ����� ���� � ����� �������, � �� ����� � ����� ��� ������, ������ ��� � ����� ����� ���� ��� ����� . � ..
    {
        printf(" �������� ���� ������� �����������!\n");
        getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
        return;
    }
    else //�������� ������� ������ � ����������, ����� �������� ������ ���������� ������ ��� ����� � �������    
    {
        do
        {
            count++;
        } while (_findnext(hFile, &inf_file) == 0); //���� ����� � ����� �� ��������
        _findclose(hFile); 
    }
    count -= 2;
    c_file = checknull((oneinf*)malloc(count * sizeof(oneinf))); //������� �������� ���-�� ��-��� � �����, ����� �� �������� ����� ����� ��� realloc � �������� �� != NULL
    count = 0;
    hFile = _findfirst(path, &inf_file);
    do
    {
        if (count > 1) //�.�. 0 � 1 ���� . � ..
        {
            c_file[count - 2].size = inf_file.size;
            strcpy(c_file[count - 2].name, inf_file.name);
        }
        count++;
    } while (_findnext(hFile, &inf_file) == 0); //���� ����� � ����� �� ��������
    _findclose(hFile);
    count -= 2; //��� ��� � ����� ����� ���������� ������� ��� ����� . � ..
    inf[ind - 1].countoffiles = count;
    if (count == 0)
    {
        printf(" �� ����� ���� �� ������� �� ������ �����!\n"); //�� ������ ������������� �����, �� ������������ �� ����������, ��� � ����� ���������� ������� �����
        getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
        return;
    }
    else
    {
        choiceyoursort(count, c_file);
    }
}

int choiceyoursort(int count, oneinf* c_file)
{
    int vibor[3] = { 0 };
    long double t = 0;
    printf(" �� ������ ������� �������� ����������:\n\t(1) �� �����������\n\t(2) �� ��������\n");
    while ((vibor[0] < 1) || (vibor[0] > 2))
    {
        scanf_s("%d", &vibor[0]);
        if ((vibor[0] < 1) || (vibor[0] > 2))
        {
            printf(" ������ �������� ���������� �� ������������ ����������. ������� ����� �� 1 �� 2.\n");
            while (getchar() != '\n');
        }
    }
    clearscreen(0, 3);
    printf(" �� ������� ���������� �� ");
    if (vibor[0] == 1)
    {
        printf("�����������\n");
    }
    else
    {
        printf("��������\n");
    }
    inf[ind - 1].updown = vibor[0];
    printf("\n �� ������ ������� ���� �� 7 ����������:\n\t(1) ���������\n\t(2) �������\n\t(3) ���������\n\t(4) ��������\n\t(5) �����\n\t(6) �����\n\t(7) ���������\n");
    while ((vibor[1] < 1) || (vibor[1] > 7))
    {
        scanf_s("%d", &vibor[1]);
        if ((vibor[1] < 1) || (vibor[1] > 7))
        {
            printf(" ������ ���������� �� ������������� ����������. ������� ����� �� 1 �� 7.\n");
            while (getchar() != '\n');
        }
    }
    inf[ind - 1].typesort = vibor[1];
    clearscreen(0, 5);
    printf(" ��������� ����������: ");
    polzsorttype(vibor[1]);
    printf("\n");
    t = omp_get_wtime();
    switch (vibor[1])
    {
    case 1:
        bubblesort(count, c_file);
        break;
    case 2:
        selectsort(count, c_file);
        break;
    case 3:
        insertsort(count, c_file);
        break;
    case 4:
        mergesort(0, count - 1, c_file);
        break;
    case 5:
        quicksort(c_file, count - 1);
        break;
    case 6:
        shellsort(count, c_file);
        break;
    case 7:
        countingsort(count, c_file);
        break;
    default:
        printf(" ������, ��������� � ������� � ����������\n");
        break;
    }
    if (vibor[0] == 1)
    {
        vozrastanie(count, c_file);
    }
    inf[ind - 1].timer = omp_get_wtime() - t;;
    printf("\n ����� ������: %d\n\n ����� ����������: %.7lf (���)\n\n ��� ����� �������?\n\t(1)������� ��������������� �����\n\t(2)��������� � ����\n", count, inf[ind - 1].timer);
    while ((vibor[2] < 1) || (vibor[2] > 2))
    {
        scanf_s("%d", &vibor[2]);
        if ((vibor[2] < 1) || (vibor[2] > 2))
        {
            printf(" ������ ����� �� ������������ ����������. ������� 1 ��� 2.\n");
            while (getchar() != '\n');
        }
    }
    if (vibor[2] == 1)
    {
        clearscreen(0,11);
        printf("%33c������ ������\n", ' ');
        printgran(1, 80);
        printf(" ����� |%18c����%38c������\n", ' ', ' ');
        pipetoxy(60, 13);
        printgran(1, 80);
        for (int i = 0; i < count; i++)
        {
            printf("%6d | %-51s %13lu ����\n", i+1, c_file[i].name, c_file[i].size);
            pipetoxy(60, i + 15);
        }
        printgran(1, 80);
        system("pause");
    }
    free(c_file);
    system("cls");
}

/*����������*/

//1. ���������
void bubblesort(int count, oneinf* c_file)
{
    oneinf dop_file; //�������������� ���������� ��� ������������

    for (int i = 0; i < count; i++)
    {
        for (int j = count - 1; j > i; j--)
        {
            if (c_file[j - 1].size < c_file[j].size)
            {
                dop_file = c_file[j - 1];
                c_file[j - 1] = c_file[j];
                c_file[j] = dop_file;
            }
        }
    }
}

//2. �������
void selectsort(int count, oneinf* c_file)
{
    oneinf dop_file; //�������������� ���������� ��� ������������
    int i, j; //���������� ��� �����
    int k; //�������������� ���������� ��� ������������
    for (i = 0; i < count; i++)
    {
        k = i;
        dop_file = c_file[i];
        for (j = i + 1; j < count; j++)
        {
            if (c_file[j].size > dop_file.size)
            {
                k = j;
                dop_file = c_file[j];
            }
        }
        c_file[k] = c_file[i];
        c_file[i] = dop_file;
    }
}

//3. ���������
void insertsort(int count, oneinf* c_file)
{
    oneinf dop_file; //�������������� ���������� ��� ������������
    int j;
    for (int i = 0; i < count; i++)
    {
        dop_file = c_file[i];
        for (j = i - 1; (j >= 0) && (c_file[j].size < dop_file.size); j--)
        {
            c_file[j + 1] = c_file[j];
        }
        c_file[j + 1] = dop_file;
    }
}

//4. ��������
void mergesort(int left, int right, oneinf* c_file)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergesort(left, mid, c_file);
    mergesort(mid + 1, right, c_file);
    merge(left, right, c_file);
}

void merge(int left, int right, oneinf* c_file)
{
    int mid = (left + right) / 2;
    int i = left; //�������
    int k = 0; //�������
    int j = mid + 1; //�������
    oneinf* dop_file; //�������������� ���������� ��� ������������
    right += 1;
    dop_file = checknull(malloc((right) * sizeof(oneinf)));
    for (k = left; k < right; k++)
    {
        if ((i <= mid) && (j < right))
        {
            if (c_file[i].size >= c_file[j].size)
            {
                dop_file[k] = c_file[i];
                i++;
            }
            else
            {
                dop_file[k] = c_file[j];
                j++;
            }
        }
        else
        {
            if (i == mid + 1)
            {
                for (; j < right; j++, k++)
                {
                    dop_file[k] = c_file[j];
                }
            }
            else
            {
                for (; i < mid + 1; i++, k++)
                {
                    dop_file[k] = c_file[i];
                }
            }
        }
    }
    for (k = left; k < right; k++)
    {
        c_file[k] = dop_file[k];
    }
    free(dop_file);
}

//5. ����� = ������� ����������
void quicksort(oneinf* c_file, int count)
{
    int i = 0; //�������
    int j = count; //�������
    int mid = count / 2;
    _fsize_t sizemidelem = c_file[mid].size;
    oneinf dop_file; //�������������� ���������� ��� ������������ � ������� �� ��������
    do
    {
        while (c_file[i].size > sizemidelem)
        {
            i++;
        }
        while (c_file[j].size < sizemidelem)
        {
            j--;
        }
        if (i <= j)
        {
            dop_file = c_file[i];
            c_file[i] = c_file[j];
            c_file[j] = dop_file;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quicksort(c_file, j);
    if (count > i)
        quicksort(c_file + i, count - i);
}

//6. ���������� �����
int shellsort(int count, oneinf* c_file)
{
    oneinf dop_file; //�������������� ���������� ��� ������������
    long inc, i, j, seq[40];
    int s;
    s = increment(seq, count); // ���������� ������������������ ����������
    while (s >= 0) 
    {
        inc = seq[s--]; //���������� ��������� � ������������ inc[]
        for (i = inc; i < count; i++) 
        {
            dop_file = c_file[i];
            for ((j = i - inc); ((j >= 0) && (c_file[j].size < dop_file.size)); (j -= inc))
            {
                c_file[j + inc] = c_file[j];
            }
            c_file[j + inc] = dop_file;
        }
    }
}

int increment(long inc[], int count)
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
    } while (3 * inc[s] < count);

    return s > 0 ? --s : 0;
}

//7. ���������� ���������
int countingsort(int count, oneinf* c_file)
{
    int k = count - 1;
    oneinf dop_file; //�������������� ���������� ��� ������������
    _fsize_t* countequalsizes;
    _fsize_t minsize, maxsize, size; //����������� � ������������ �������� �������
    minsize = maxsize = c_file[0].size;
    for (int i = 0; i < count; i++)
    {
        if (c_file[i].size < minsize)
        {
            minsize = c_file[i].size;
        }
        if (c_file[i].size > maxsize)
        {
            maxsize = c_file[i].size;
        }
    }
    size = maxsize - minsize + 1;
    countequalsizes = checknull((_fsize_t*)malloc(size * sizeof(_fsize_t)));
    for (_fsize_t  i = 0; i < size; i++)
    {
        countequalsizes[i] = 0;
    }
    for (int i = 0; i < count; i++)
    {
        countequalsizes[c_file[i].size - minsize]++;
    }
    for (_fsize_t  i = 0; i < size; i++)
    {
        while (countequalsizes[i] > 0)
        {
            for (int j = k; j >= 0; j--)
            {
                if (c_file[j].size == minsize + i)
                {
                    dop_file = c_file[j];
                    c_file[j] = c_file[k];
                    c_file[k] = dop_file;
                    k--;
                    countequalsizes[i]--;
                }
            }
        }
    }
    free(countequalsizes);
}

//8. ���������� � �������� �������
void vozrastanie(int count, oneinf* c_file)
{
    int n = count / 2; //����������, ������������ ������� ��������� � 1/2 ����� ����� �������
    struct finddata dop_file; //�������������� ���������� ��� ������������
    for (int i = 0; i < n; i++)
    {
        dop_file = c_file[i];
        c_file[i] = c_file[count - i - 1];
        c_file[count - i - 1] = dop_file;
    }
}

/*�������������� �������*/

//������������� ���� ��� ���������
char preobr(char* path)
{
    int size = 0; //������ ����
    size = strlen(path);
    if (path[size - 3] != '\\') //������� � ������ '/' ��� ���������
    {
        size++;
        path[size - 2] = '\\';
    }
    if (path[size - 2] != '*') //������� � ������ *, ����� � ���� ����� ��������� ��� �����
    {
        size++;
        path[size - 2] = '*';
    }
    path[size - 1] = '\0'; //�������� ������
    for (int i = 0; i < size; i++)
    {
        if (path[i] == '\\') //������ ������� '/' ('//') ��� ���������
        {
            i++; //����� ���������� ����������� '/'
            if (path[i] == path[i - 1]) //���� ��� ���������� ������� '/', �� ������ ����������� �� �����, ��������� �� ��������� ������
                continue;
            size++;
            for (int j = size - 1; j > i - 1; j--) //����� ��������� '/' ������� ��� ������� �� 1 ������, ��� ���� ����������� �������������� ������� �� ��������� '/'
            {
                path[j] = path[j - 1];
                //printf("%s\n", path); //��� �������� �������������
            }
        }
    }
}

//����� ���������� �� ���� �����������
void fullvivod()
{
    if (ind == 0)
    {
        printf("\n");
        printgran(1, 42);
        printf("| ��������� �� ���������� �� ���� �����! |\n");
        printgran(1, 42);
        system("pause");
        system("cls");
        return;
    }
    printf("\n");
    printgran(1, 79);
    printf("  � | C��������� | �����������/�������� | ���������� ������ | ����� ���������� \n");
    printgran(1, 79);
    for (int i = 0; i < ind; i++)
    {
        printf("%3d%4c", i+1, ' ');
        polzsorttype(inf[i].typesort);
        printf("%8c", ' ');
        vozrandubyv(inf[i].updown);
        printf("%23d%14.7lf (���)", inf[i].countoffiles, inf[i].timer);
        pipetoxy(4, 4+i);
        pipetoxy(17, 4+i);
        pipetoxy(40, 4+i);
        pipetoxy(60, 4+i);
    }
    printgran(1, 79);
    system("pause");
    system("cls");
}

//������ �����
void printgran(int type, int i)
{
    if (type == 1)
    {
        for (int j = 0; j < i; j++)
            printf("-");
    }
    printf("\n");
}

//���������� ��������� ����������
void polzsorttype(int i)
{
    switch (i)
    {
    case 1:
        printf("���������");
        break;
    case 2:
        //
        printf("�������  ");
        break;
    case 3:
        //
        printf("���������");
        break;
    case 4:
        //
        printf("�������� ");
        break;
    case 5:
        //
        printf("�����    ");
        break;
    case 6:
        //
        printf("�����    ");
        break;
    case 7:
        //
        printf("���������");
        break;
    default:
        printf("������   ");
        break;
    }
}

//https://stackoverrun.com/ru/q/1628655
void clearscreen(int x, int y)
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { x, y };
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

//�������, ����������� | �� �������� �����������
void pipetoxy(int x, int y)
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(Console, pos);
    printf("|\n");
}

//������� ���������� �� ����������� ��� �������� � ����������
void vozrandubyv(int a)
{
    if (a == 1)
    {
        printf("�����������");
    }
    else
    {
        printf("��������   ");
    }
}

//�������������� ����������
/* int countingsort(int count, oneinf* c_file)
{
    int k;
    count++;
    oneinf* sortedarr = checknull(malloc((count) * sizeof(oneinf)));
    count--;
    for (int i = 0; i < count; i++)
        sortedarr[i].size = -1;
    for (int i = 0; i < count; i++)
    {
        k = 0;
        for (int j = 0; j < count; j++)
        {
            if (c_file[i].size < c_file[j].size)
            {
                k++;
            }
        }
        sortedarr[k] = c_file[i];
    }
    for (int i = 1; i < count; i++)
    {
        if (sortedarr[i].size == -1)
        {
            sortedarr[i].size = sortedarr[i - 1].size;
        }
    }
    k = 0;
    for (int i = 0; i < count; i++)
    {
        if (sortedarr[i].size == sortedarr[i + 1].size)
        {
            for (; k < count; k++)
            {
                if (sortedarr[i].size == c_file[k].size)
                {
                    sortedarr[i] = c_file[k];
                    k++;
                    break;
                }
            }
        }
        else
        {
            if ((i != 0) && (sortedarr[i].size == sortedarr[i - 1].size))
            {
                for (; k < count; k++)
                {
                    if (sortedarr[i].size == c_file[k].size)
                    {
                        sortedarr[i] = c_file[k];
                        k++;
                        break;
                    }
                }
            }
            k = 0;
        }
    }
    for (int i = 0; i < count; i++)
    {
        c_file[i] = sortedarr[i];
    }
    free(sortedarr);
}
*/
