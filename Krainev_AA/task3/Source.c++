//����������� ���������, ����������� ���� ����� � �������.

//����������(�������)
//������ ��� ������(������� � ���������).
//����� �������� ����� ������������� ����� � n(�� 2 �� 5).
//��������� ����������� n - ������� ����� � ���������������� �������.
//����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������.
//��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����(�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� �����(�� ���� ���������� �����).
//����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.
//������
//����� n = 4.
//����� �������� ����� �3219�.
//����� ���� ����� �2310�.
//���������: ��� ��������(��� ����� : �2� � �3� � ������� �� �������� ��������) � ���� ����(���� ����� �1� ������� ������ �� �������).
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
#include"Console.cpp"
#define _CRT_SECURE_NO_WARNINGS



int main()
{
    setlocale(LC_ALL, "Rus");//���������� ������� ���� 
    // ��������� ��������� 
    int n; //����� ����� [2,5]
    int* chislo;//��������� �� ������ (������ ������ ������������ �����)
    int random;// ���������� ��� ���������� ����� 
    int i; // ��� ������
    int doing;//������� ����������
    int j = 0; // ��� ������
    int chisloigroka; //����� ������� ������ ������������
    int chisloigroka1[5]; // ������ ���� ����������� ����������� ����� 
    int l = 0; // ����
    int f, h; // h - ������  m f - ��� ����� 
    int z = 0;// ���������������. ������������ ��� �������� ������� 
    int pomog = 0;
    //int true = 1;
    //int false = 0;


    //�����������  ������� � ���� ��� ������� � ���������  ������ ������ ��� ������� (������� ���� int)
    system("chcp 1251");
    system("cls");
    printf("������� ����� ����� n\n");
    scanf_s("%d", &n);

    chislo = (int*)malloc(n * sizeof(int));


    srand(time(NULL));
    // ��������������� ��� ������� ��������� printf("����� n � ������� �����:%i\n", n);

    random = rand() % 9 + 1; //�������� ���������� �����
    chislo[0] = random; //������ �����  � ������� � ��������� �� 1 �� 9

    /// ����� � ��� ����������� ������ ���������� ���������������� �������  
    for (int i = 1; i < n;) { //���� �������� ��������� �����
        //random = rand() % 9; //�������� ���������� ����� �� 0 �� 9
        doing = 1;
        random = rand() % 10;
        for (int j = 1; j < n; j++) { //���� �������� ������� �� ����������
            if (chislo[j] == random || chislo[0] == random) { //������� ����������
                doing = 0;//������� ���� �� ���� ����������
                //break;//������������, �������� ���-�� ��������
            }
            //else {
                //continue; //���� ������� ���, ��������� � ��������� ��������
            //}
        }
        if (doing == 1) {
            chislo[i] = random;// ������������ ���������� ����� �������� �������
            i++;
        }


    }
    //���� ��� �������
    printf("��������� ������� �����:\n");
    for (i = 0; i < n; i++) {
        //printf_s("random[%d]=%d\n", l, chislo[l]);
        printf_s("%d",chislo[i]);
    }


    printf("\n���������� ������� �����, ���������� �����������, ����� �� ����� ��� � n\n");
    while (n != l) { // n - ����� �����/l- ����� ����� (�� ���� �� ������� ���������� ���� ���� � ������ ��������)
        printf("\n������� ��� ����� ��� �������� (0-����� ��������� ����): ");
        scanf_s("%d", &chisloigroka);
        //�� ������� ��� ����� 0 ����� �������, �������
        if (chisloigroka == 0) {
            printf("�� �������. �����, ���������� �����������: ");
            for (i = 0; i < n; i++) {
                printf_s("%d", chislo[i]);
            }
            getchar();
            getchar();
           
            break;
        }
        else {
            //����������� ���������� ����� � ������
            z = (n - 1);//��� �������� �������: ������ ����������� � ����� ��� ��� ��������� � ��������� ����� ����� 
            while (chisloigroka > 0) {
                chisloigroka1[z] = chisloigroka % 10;
                chisloigroka = chisloigroka / 10;
                z--;
            }
            //��� �������;
            /*printf("���������� ����� ");
            for (i = 0; i < n; i++)
            printf("%d", chisloigroka1[i]);
            */


            l = 0; //��� ����� 
            for (i = 0; i < n; i++) {
                if (chisloigroka1[i] == chislo[i]) { //������� ����� 
                    l++;
                }
            }
            printf("\n����� �����: %d", l); //
            f = 0;
            h = 0; //������
            for (i = 0; i < n; i++) {
                for (f = 0; f < n; f++) { //����� ������� ��� �����
                    if (chisloigroka1[i] == chislo[f]) //chisloigroka1 - ������ � ��� ��� ���� ����� //chislo - ������� ������� ���������
                        h++;
                }
                f++;
            }
            printf("\n����� �����: %d", h - l); // h-l ��� ��� �������� �� ����� ��������� ����� 
        }
    }
    if (n == l) {
        printf("\n�����������, �� ������� �����!");
        getchar();
        getchar();
    }





}
