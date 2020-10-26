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
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
const int col = 80;
const int row = 50;
void drawCow(HANDLE hWnd, int posx, int posy);
void cls2(HANDLE hConsole);

void drawCow(HANDLE wHnd, int posx, int posy){
    const int rowCow = 30;
    const int colCow = 30;
    int pictLetterCow[colCow][rowCow] = { //row-������  col - ������� // ������� ������ (��� ���������� ���������) +  loading (������������ ��� �������� ����)
        {0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0},
        {1,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0},
        {1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0},
        {1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1},
        {1,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,1},
    };
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(wHnd, &csbiInfo);
    CHAR_INFO picBufferCow[colCow * rowCow]; //���������� ����� ��� ������ ������

    for (int i = 0; i < colCow * rowCow; ++i) {
        picBufferCow[i].Char.AsciiChar = ' ';
        picBufferCow[i].Attributes = csbiInfo.wAttributes;
    }
    for (int i = 0; i < rowCow; i++) 
        for (int j = 0; j < colCow; j++) {
            if (pictLetterCow[i][j] == 1)
                picBufferCow[i * colCow + j].Attributes = 0;
        }
    
    //�������������� ��� ������
    SMALL_RECT writeArea = { posx, posy, posx + colCow, posy + rowCow };
    //��������� ���� ������ � ����� ������� 
    WriteConsoleOutput(wHnd, picBufferCow, { colCow,rowCow }, { 0,0 }, &writeArea);

}

int main() {

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

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

    //�������� ���������� ��� �������� ������ ������ 
    int Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11;
    int LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15;
    //����� ��������� ����� ������������� �������� ������ 
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
   // SetConsoleTitle(L"���� ���� � ������");
    SMALL_RECT windowSize = { 0,0, 1080, 360 };//���������� ������ ����
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);//������ ������� ����������� ����
    COORD bufferSize = { col * row };
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    //SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    CHAR_INFO consBuffer[col * row]; //�������� ������ �������
    int rX, rY; //������� ����� � ���� 
    for (int i = 0; i < 10; i++) {
        //cls2(wHnd, consBuffer, bufferSize);// ������� ���� (�� �����) 
        system("cls"); //��������� �������
        rX = 50;
        rY = 1;
        drawCow(wHnd, rX, rY);
        Sleep(400);
    }
    system("cls");
    SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    //
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("|         ����  ����    � ������            |\n");
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("����� ����������!\n");
    printf_s("������� ����:\n");
    printf_s("=>������ ��� ������(������� � ���������).\n");
    printf_s("=>����� �������� ����� ������������� ����� � n(�� 2 �� 5).\n");
    printf_s("=>��������� ����������� n - ������� ����� � ���������������� �������.\n");
    printf_s("=>����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������.\n");
    printf_s("=>��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����(�� ���� ���������� �����) \n=>� ������� ������� ������ �� ������� � ���������� �����(�� ���� ���������� �����).\n");
    printf_s("=>����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.\n");
    printf_s("\n");//������ ������
    printf_s("��� ������ ���� ������� Enter");
    getchar();
    //��� ���� ����� ����� ������ �� ����� ���� 
    SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    //�����������  ������� � ���� ��� ������� � ���������  ������ ������ ��� ������� (������� ���� int)
   // system("chcp 1251");
    system("cls");
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("|                ���� ��������              |\n");
    printf_s("+---------------------+-------------+-------+\n");
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
   /*printf_s("��������� ������� �����:\n");
   for (i = 0; i < n; i++) {
       //printf_s("random[%d]=%d\n", l, chislo[l]);
        printf_s("%d", chislo[i]);
    }*/


    printf_s("\n���������� ������� �����, ���������� �����������, ����� �� ����� ��� � n\n");
    while (n != l) { // n - ����� �����/l- ����� ����� (�� ���� �� ������� ���������� ���� ���� � ������ ��������)
        printf_s("\n������� ��� ����� ��� �������� (0-����� ��������� ����): ");
        scanf_s("%d", &chisloigroka);
        //�� ������� ��� ����� 0 ����� �������, �������
        if (chisloigroka == 0) {
            SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED );
            printf_s("�� �������. �����, ���������� �����������: ");
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
            printf_s("\n����� �����: %d", l); //
            f = 0;
            h = 0; //������
            for (i = 0; i < n; i++) {
                for (f = 0; f < n; f++) { //����� ������� ��� �����
                    if (chisloigroka1[i] == chislo[f]) //chisloigroka1 - ������ � ��� ��� ���� ����� //chislo - ������� ������� ���������
                        h++;
                }
                f++;
            }
            printf_s("\n����� �����: %d", h - l); // h-l ��� ��� �������� �� ����� ��������� ����� 
        }
    }
    if (n == l) {
        SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf_s("\n�����������, �� ������� �����!\n");
        printf_s("+---------------------+-------------+-------+\n");
        printf_s("|                  �� �������!               |\n");
        printf_s("+---------------------+-------------+-------+\n");
        getchar();
        getchar();
    }
    delete(chislo);//�������� ���������� ��� ������� ������ 
}
//������� ��� �������� ������ �������, ������� ������, ��� ������� �� ��������� 3 ����������: �� ���� ����� ������, ������� ��������� ������ ��� system("cls");
/*void cls2(HANDLE hConsole)
{
    //const int col = 30;
    //const int row = 20;
    CHAR_INFO consBuffer[col * row];
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(hConsole, &csbiInfo);

    for (int i = 0; i < col * row; ++i) {
        consBuffer[i].Char.UnicodeChar = ' ';
        consBuffer[i].Attributes = csbiInfo.wAttributes;
    }
    COORD charPosition = { 0,0 };
    SMALL_RECT writeArea = { 0,0,col - 1, row - 1 };
    COORD bufferSize = { col,row };
    WriteConsoleOutput(hConsole, consBuffer, bufferSize, charPosition, &writeArea);
}*/
