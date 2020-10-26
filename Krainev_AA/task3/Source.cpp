//Разработать программу, реализующую игру «Быки и коровы».

//Требования(правила)
//Играют два игрока(человек и компьютер).
//Игрок выбирает длину загадываемого числа – n(от 2 до 5).
//Компьютер «задумывает» n - значное число с неповторяющимися цифрами.
//Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами.
//Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров) и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков).
//Игрок делает попытки, пока не отгадает всю последовательность или не сдастся.
//Пример
//Пусть n = 4.
//Пусть задумано число «3219».
//Игрок ввел число «2310».
//Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции).
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
    int pictLetterCow[colCow][rowCow] = { //row-строки  col - столбцы // рисунок корова (бык некрасивый получался) +  loading (искуственный вид загрузки игры)
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
    CHAR_INFO picBufferCow[colCow * rowCow]; //символьный буфер для печати коровы

    for (int i = 0; i < colCow * rowCow; ++i) {
        picBufferCow[i].Char.AsciiChar = ' ';
        picBufferCow[i].Attributes = csbiInfo.wAttributes;
    }
    for (int i = 0; i < rowCow; i++) 
        for (int j = 0; j < colCow; j++) {
            if (pictLetterCow[i][j] == 1)
                picBufferCow[i * colCow + j].Attributes = 0;
        }
    
    //прмоугольничек для коровы
    SMALL_RECT writeArea = { posx, posy, posx + colCow, posy + rowCow };
    //переносим блок данных в буфер консоли 
    WriteConsoleOutput(wHnd, picBufferCow, { colCow,rowCow }, { 0,0 }, &writeArea);

}

int main() {

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    setlocale(LC_ALL, "Rus");//подключаем русский язык 
    // объявляем перменные 
    int n; //длина числа [2,5]
    int* chislo;//указатель на массив (размер вводит пользователь далее)
    int random;// переменная для рандомного числа 
    int i; // для циклов
    int doing;//булевая переменная
    int j = 0; // для циклов
    int chisloigroka; //число которое вводит пользователь
    int chisloigroka1[5]; // массив куда сохранятеся угадываемое число 
    int l = 0; // быки
    int f, h; // h - коровы  m f - для цикла 
    int z = 0;// вспомогательная. используется для перебора массива 
    int pomog = 0;

    //название переменных для удобного выбора цветов 
    int Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11;
    int LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15;
    //далее реализуем вывод привественной картинки коровы 
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
   // SetConsoleTitle(L"Игра быки и коровы");
    SMALL_RECT windowSize = { 0,0, 1080, 360 };//координаты вершин окна
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);//задаем размеры консольного окна
    COORD bufferSize = { col * row };
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    //SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    CHAR_INFO consBuffer[col * row]; //создание буфера консоли
    int rX, rY; //вершина блока в окне 
    for (int i = 0; i < 10; i++) {
        //cls2(wHnd, consBuffer, bufferSize);// очистка окна (см конец) 
        system("cls"); //системная очистка
        rX = 50;
        rY = 1;
        drawCow(wHnd, rX, rY);
        Sleep(400);
    }
    system("cls");
    SetConsoleTextAttribute(wHnd, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    //
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("|         Игра  быки    и коровы            |\n");
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("Добро пожаловать!\n");
    printf_s("Правила игры:\n");
    printf_s("=>Играют два игрока(человек и компьютер).\n");
    printf_s("=>Игрок выбирает длину загадываемого числа – n(от 2 до 5).\n");
    printf_s("=>Компьютер «задумывает» n - значное число с неповторяющимися цифрами.\n");
    printf_s("=>Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами.\n");
    printf_s("=>Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров) \n=>и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков).\n");
    printf_s("=>Игрок делает попытки, пока не отгадает всю последовательность или не сдастся.\n");
    printf_s("\n");//пустая строка
    printf_s("Для начала игры нажмите Enter");
    getchar();
    //ход игры будет белым цветом на синем фоне 
    SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    //организация  массива и ввод его размера и выделение  нужной памяти для массива (элемент типа int)
   // system("chcp 1251");
    system("cls");
    printf_s("+---------------------+-------------+-------+\n");
    printf_s("|                Игра началась              |\n");
    printf_s("+---------------------+-------------+-------+\n");
    printf("Введите длину числа n\n");
    scanf_s("%d", &n);

    chislo = (int*)malloc(n * sizeof(int));


    srand(time(NULL));
    // вспомогательная для отладки программы printf("Число n в массиве равно:%i\n", n);

    random = rand() % 9 + 1; //создание случайного числа
    chislo[0] = random; //первая цифра  в массиве в диапозоне от 1 до 9

    /// Далее у нас заполняется массив рандомными неповторяющимися числами  
    for (int i = 1; i < n;) { //цикл создания случайных чисел
        //random = rand() % 9; //создание случайного цифры от 0 до 9
        doing = 1;
        random = rand() % 10;
        for (int j = 1; j < n; j++) { //цикл проверки массива на совпадение
            if (chislo[j] == random || chislo[0] == random) { //условие совпадения
                doing = 0;//Найдено хотя бы одно совпадение
                //break;//Оптимизируем, сокращая кол-во итераций
            }
            //else {
                //continue; //если повтора нет, переходим к следующей итерации
            //}
        }
        if (doing == 1) {
            chislo[i] = random;// присваивание рандомного числа элементу массива
            i++;
        }


    }
   //блок для отладки
   /*printf_s("Компьютер загадал число:\n");
   for (i = 0; i < n; i++) {
       //printf_s("random[%d]=%d\n", l, chislo[l]);
        printf_s("%d", chislo[i]);
    }*/


    printf_s("\nПопробуйте угадать число, загаданное компьютером, такой же длины что и n\n");
    while (n != l) { // n - длина числа/l- число быков (то есть до момента угадывания всех цифр с точной позицией)
        printf_s("\nВведите это число без пробелов (0-чтобы завершить игру): ");
        scanf_s("%d", &chisloigroka);
        //по условию при вводе 0 игрок сдается, поэтому
        if (chisloigroka == 0) {
            SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED );
            printf_s("Вы сдались. Число, загаданное компьютером: ");
            for (i = 0; i < n; i++) {
                printf_s("%d", chislo[i]);
            }
            getchar();
            getchar();

            break;
        }
        else {
            //преобразуем полученное число в массив
            z = (n - 1);//для перебора массива: массив заполняется с конца так как заполняем с последней цифры числа 
            while (chisloigroka > 0) {
                chisloigroka1[z] = chisloigroka % 10;
                chisloigroka = chisloigroka / 10;
                z--;
            }
            //для отладки;
            /*printf("Полученное число ");
            for (i = 0; i < n; i++)
            printf("%d", chisloigroka1[i]);
            */


            l = 0; //для быков 
            for (i = 0; i < n; i++) {
                if (chisloigroka1[i] == chislo[i]) { //условие быков 
                    l++;
                }
            }
            printf_s("\nЧисло быков: %d", l); //
            f = 0;
            h = 0; //коровы
            for (i = 0; i < n; i++) {
                for (f = 0; f < n; f++) { //далее условие для коров
                    if (chisloigroka1[i] == chislo[f]) //chisloigroka1 - массив с чис кот ввел игрок //chislo - которое загадал компьютер
                        h++;
                }
                f++;
            }
            printf_s("\nЧисло коров: %d", h - l); // h-l так как вычитаем из коров совпавших быков 
        }
    }
    if (n == l) {
        SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_GREEN);
        printf_s("\nПоздравляем, Вы угадали число!\n");
        printf_s("+---------------------+-------------+-------+\n");
        printf_s("|                  До встречи!               |\n");
        printf_s("+---------------------+-------------+-------+\n");
        getchar();
        getchar();
    }
    delete(chislo);//удаление выделенной для массива памяти 
}
//функция для очищения буфера консоли, вылазет ошибка, что функция не принимает 3 аргунмента: не смог найти почему, поэтому использую вместо нее system("cls");
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
