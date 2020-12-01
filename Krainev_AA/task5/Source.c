#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
#include <dos.h>
#include <string.h>
#include <omp.h>

char directoryPath[300];

int userInterface();
void showMenu();
int getNumberOfMenu(const int numberOfItemsInTheMenu);
float getTime(double  timeOne, double  timeTwo, int selectMenuItem);
struct informationAboutOneFile* gettingInformationFromADirectory();
void showMenuSoarting();
void bubbleSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
void selectionSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
void insertSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
void Merge(struct informationAboutOneFile* soartingInformation, int left, int right);
void mergeSort(struct informationAboutOneFile* soartingInformation, int left, int right);
void quickSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
void shellSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
int incrementS(long inc[], int count);
void countingSort(struct informationAboutOneFile* soartingInformation, long int numberOfFiles);
void printAllSort(struct informationAboutSoarting* soartingInformation, const int getCountFromCounter);


struct informationAboutSoarting {
    float timeOfSoarting; //время сортировки
}soartingInformation[7];

typedef struct oneFileInformation { //https://www.rpi.edu/dept/cis/software/g77-mingw32/include/io.h

    unsigned	attrib;		/* Attributes, see constants above. */
    time_t		time_create;
    time_t		time_access;	/* always midnight local time */
    time_t		time_write;
    _fsize_t	size;
    char		name[FILENAME_MAX];	/* may include spaces. */
} informationAboutOneFile;

struct { // без дескриптора так как используем шаблон структуры один раз
    long int NumberOfFiles;
} informationAboutDirectory;


int counter(char* directoryPath) //счетчик количества файлов
{
    informationAboutDirectory.NumberOfFiles = 0;
    struct _finddata_t sortableFile;
    intptr_t hFile;
    if ((hFile = _findfirst(directoryPath, &sortableFile)) == -1L) {
        return informationAboutDirectory.NumberOfFiles;
    }
    else
    {
        do {
            informationAboutDirectory.NumberOfFiles++;
        } while (_findnext(hFile, &sortableFile) == 0);
        _findclose(hFile);
    }
    return informationAboutDirectory.NumberOfFiles; //кол-во файлов
}

struct informationAboutOneFile* gettingInformationFromADirectory() { //крч функция отвечает за получение информации от директории и всякое такое
    intptr_t hFile; //memsize тип intptr_t хранит в себе  hFile
    struct _finddata_t sortableFile; //сортируемый sortableFile.name sortableFile.size sortableFile.time

    printf("Введите путь до  директория (например : C:\\\\temp\\\\*.*) : \n");
    gets_s(directoryPath, FILENAME_MAX);

    printf("Выбранный каталог %s\n", directoryPath);
    strcat(directoryPath, "*");//приклеим в конец адреса звездочку
    printf("Выбранный каталог со звездочкой %s\n", directoryPath);

    if ((hFile = _findfirst(directoryPath, &sortableFile)) == -1L) {
        printf("Ввели неверный адрес для директории!\n");
        gettingInformationFromADirectory();//вызываем пока не получим верный адресс
        return;
    }
    //иначе подсчитаем сколько там файлов и позже учтем: 2 файла нужно вычесть, так как они содержатся в каждой папочке
    else {
        printf("-------------------------------------------------------\n");
        printf("|  Список файлов в указанной папке (без сортировки)   |\n");
        printf("-------------------------------------------------------\n");
        printf("Имя файла         Дата и время создания %16c   Размер\n", ' ');
        printf("----         ---- %24c   ----\n", ' ');
        int getfromcounter = counter(directoryPath);
        do {
            char buffer[30];
            ctime_s(buffer, _countof(buffer), &sortableFile.time_write);
            int count = 0;
            if (count <= getfromcounter)
                printf("%-14.14s %-5.22s      %16ld\n", sortableFile.name, buffer, sortableFile.size);
            count++;
        } while (_findnext(hFile, &sortableFile) == 0);
    }
    //пока не закрываем 
    informationAboutOneFile* FileInformation_one;

    FileInformation_one = (informationAboutOneFile*)malloc(informationAboutDirectory.NumberOfFiles * sizeof(informationAboutOneFile));

    hFile = _findfirst(directoryPath, &FileInformation_one[0]);
    for (int i = 1; i < informationAboutDirectory.NumberOfFiles; i++)
        _findnext(hFile, &FileInformation_one[i]);
    printf("\nЧисло файлов в выбранном каталоге: %d\n", informationAboutDirectory.NumberOfFiles);
    return FileInformation_one;
}

void main() {
    setlocale(LC_ALL, "Rus"); //подключаем русский язык
    printf("Добро пожаловать в программу для сортировки файлов Файловый менеджер!\n");
    printf("Вам будет предложено ввести путь к директории, выбрать метод и способ сортировки.\n");
    printf("Программа выведет время сортировки и список отсортированных файлов по размеру.\n");
    printf("Также вы сможете поменять метод сортировки и вывести информацию по всем сортировкам.\n");
    printf("Если вы отсортируете 2 или более раза файлы одной сортировой: будет сохранено последнее время.\n");
    printf("----------------------------------------------------------------------------------------\n");
    if (userInterface() == 5) {
        printf("До свидания!\n");
        return;
    }
    printAllSort(soartingInformation, counter(directoryPath));
    printf("До свидания!\n");
    getchar();
}

char* menu[] = {
    "1. Сортировка пузырьком",
    "2. Сортировка выбором",
    "3. Сортировка вставками",
    "4. Сортировка слиянием",
    "5. Сортировка Хоара",
    "6. Сортировка Шелла",
    "7. Сортировка подсчетом",
    "8. Выход из программы",
};
const int numberOfItemsInTheMenu = sizeof(menu) / sizeof(char*);//количество пунктов в меню
void retrievingInformationAboutFiles(hFile);

int increase, decrease;
int userInterface() {
    informationAboutOneFile* FileInformation_one_user;
    FileInformation_one_user = (informationAboutOneFile*)malloc(counter(directoryPath) * sizeof(informationAboutOneFile));
    FileInformation_one_user = gettingInformationFromADirectory();
    int getCountFromCounter = counter(directoryPath);
    int continueORstop = 1;
    while (continueORstop == 1) {
        showMenu();

        int choiceMenu = getNumberOfMenu(numberOfItemsInTheMenu);
        if (choiceMenu == 8) {
            return(5);
        }
        int sortByMethod = sortingMethod();
        double timeOne, timeTwo;
        double redTime;

        switch (choiceMenu) {
        case 1:
            timeOne = omp_get_wtime();
            bubbleSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки пузырьком: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;

        case 2:
            timeOne = omp_get_wtime();
            selectionSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;

        case 3:
            timeOne = omp_get_wtime();
            insertSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;
        case 4:
            timeOne = omp_get_wtime();
            mergeSort(FileInformation_one_user, 0, getCountFromCounter - 1);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;
        case 5:
            timeOne = omp_get_wtime();
            quickSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;
        case 6:
            timeOne = omp_get_wtime();
            shellSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;
        case 7:
            timeOne = omp_get_wtime();
            countingSort(FileInformation_one_user, getCountFromCounter);
            timeTwo = omp_get_wtime();
            printf("Время сортировки выбором: %f сек.\n", getTime(timeOne, timeTwo, choiceMenu));
            break;

        case 8:
            return;
        }
        if (sortByMethod == 1) {
            for (int i = 0; i < counter(directoryPath); i++)
                printf("%-12.12s %10i байт\n", FileInformation_one_user[i].name, FileInformation_one_user[i].size);
        }
        if (sortByMethod == 2) {
            for (int i = counter(directoryPath) - 1; i >= 0; i--)
                printf("%-12.12s %10i байт\n", FileInformation_one_user[i].name, FileInformation_one_user[i].size);
        }
        printf("Желаете отсортировать данную папку другим методом?\n 1 - Да.\n 2-Нет.\n");
        scanf_s("%d", &continueORstop);
        if (continueORstop == 2) {
            int stop = 0;
            return stop;
        }
    }

}

void printAllSort(struct informationAboutSoarting* soartingInformation, const int getCountFromCounter) {
    printf("Перед вами данные о всех сортировках: если время 0 сек., то сортировка данным методом не производилась \n");
    printf("Название  сортировки      |Время \n");
    printf("пузырьком                  %f\n", soartingInformation[1].timeOfSoarting);
    printf("Выбором                    %f\n", soartingInformation[2].timeOfSoarting);
    printf("Сортировка вставками       %f\n", soartingInformation[3].timeOfSoarting);
    printf("Слиянием                   %f\n", soartingInformation[4].timeOfSoarting);
    printf("Хоара                      %f\n", soartingInformation[5].timeOfSoarting);
    printf("Шелла                      %f\n", soartingInformation[6].timeOfSoarting);
    printf("Подсчетом                  %f\n", soartingInformation[7].timeOfSoarting);
}
int sortingMethod() { //где increase - возрастание,  decrease - убывание

    showMenuSoarting();
    int increase = 1;
    int decrease = 2;
    int method;
    scanf_s("%d", &method);
    if (method == 1)
        return increase;
    if (method == 2)
        return decrease;
}
//далее крч сортировок куча
////////////////////////////////////////////////////////////////////////////////////////////////
void bubbleSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles) {
    long int i, j;
    informationAboutOneFile c;
    for (i = 0; i < numberOfFiles; i++) {
        for (j = numberOfFiles - 1; j > i; j--) {
            if (FileInformation_one[j - 1].size > FileInformation_one[j].size) {
                c = FileInformation_one[j - 1];
                FileInformation_one[j - 1] = FileInformation_one[j];
                FileInformation_one[j] = c;
            }
        }
    }
}
void selectionSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles) {
    informationAboutOneFile  c;

    int i, j, k;
    for (i = 0; i < numberOfFiles; i++)
    {
        k = i;
        c = FileInformation_one[i];
        for (j = i + 1; j < numberOfFiles; j++)
        {
            if (FileInformation_one[j].size < c.size)
            {
                k = j;
                c = FileInformation_one[j];
            }
        }
        FileInformation_one[k] = FileInformation_one[i];
        FileInformation_one[i] = c;
    }
}
void insertSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles)
{
    int i, j;
    informationAboutOneFile  c;
    for (i = 1; i < numberOfFiles; i++)
    {
        c = FileInformation_one[i];
        for (j = i - 1; j >= 0 && (FileInformation_one[j].size > c.size); j--)
            FileInformation_one[j + 1] = FileInformation_one[j];
        FileInformation_one[j + 1] = c;
    }
}
void mergeSort(informationAboutOneFile* FileInformation_one, int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergeSort(FileInformation_one, left, mid);
    mergeSort(FileInformation_one, mid + 1, right);
    Merge(FileInformation_one, left, right);
}
void Merge(informationAboutOneFile* FileInformation_one, int left, int right)
{
    int mid = (left + right) / 2;
    int k, i = left;
    int j = mid + 1;
    informationAboutOneFile* tmp_arr;
    right += 1;
    tmp_arr = (informationAboutOneFile*)malloc(right * sizeof(informationAboutOneFile));
    for (k = left; k < right; k++) {
        if ((i <= mid) && (j < right)) {
            if (FileInformation_one[i].size <= FileInformation_one[j].size) {
                tmp_arr[k] = FileInformation_one[i];
                i++;
            }
            else {
                tmp_arr[k] = FileInformation_one[j];
                j++;
            }
        }
        else {
            if (i == mid + 1) {
                for (; j < right; j++, k++) {
                    tmp_arr[k] = FileInformation_one[j];
                }
            }
            else {
                for (; i < mid + 1; i++, k++) {
                    tmp_arr[k] = FileInformation_one[i];
                }
            }
        }
    }
    for (k = left; k < right; k++) {
        FileInformation_one[k] = tmp_arr[k];
    }
    free(tmp_arr);
}
void quickSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles)
{
    int i = 0;
    int j = numberOfFiles - 1;
    int mid = numberOfFiles / 2;
    informationAboutOneFile* sredn;
    sredn = FileInformation_one[mid].size;
    informationAboutOneFile dop;
    do
    {
        while (FileInformation_one[i].size < sredn)
            i++;
        while (FileInformation_one[j].size > sredn)
            j--;
        if (i <= j)
        {
            dop = FileInformation_one[i];
            FileInformation_one[i] = FileInformation_one[j];
            FileInformation_one[j] = dop;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quickSort(FileInformation_one, j + 1);
    if (numberOfFiles > i)
        quickSort(FileInformation_one + i, numberOfFiles - i);
}
void shellSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles)
{
    informationAboutOneFile dop; // дополнительная переменная для перестановки
    long inc, i, j, seq[40];
    int s;
    s = incrementS(seq, numberOfFiles); // вычисление последовательности приращений
    while (s >= 0)
    {
        inc = seq[s--]; //сортировка вставками с инкрементами inc[]
        for (i = inc; i < numberOfFiles; i++)
        {
            dop = FileInformation_one[i];
            for ((j = i - inc); ((j >= 0) && (FileInformation_one[j].size > dop.size)); (j -= inc))
            {
                FileInformation_one[j + inc] = FileInformation_one[j];
            }
            FileInformation_one[j + inc] = dop;
        }
    }
}
int incrementS(long inc[], int count)
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
void countingSort(informationAboutOneFile* FileInformation_one, long int numberOfFiles)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int size = 0;
    int max = FileInformation_one[0].size;
    int min = FileInformation_one[0].size;
    int* sizes;
    informationAboutOneFile temp;

    for (i = 0; i < numberOfFiles; i++)
    {
        if (max < FileInformation_one[i].size)
            max = FileInformation_one[i].size;
        if (min > FileInformation_one[i].size)
            min = FileInformation_one[i].size;
    }
    size = max - min + 1;
    sizes = (int*)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        sizes[i] = 0;
    for (i = 0; i < numberOfFiles; i++)
        sizes[FileInformation_one[i].size - min]++;
    for (i = 0; i < size; i++)
    {
        while (sizes[i] > 0)
        {
            for (j = 0; j < numberOfFiles; j++)
            {
                if (FileInformation_one[j].size == min + i)
                {
                    temp = FileInformation_one[j];
                    FileInformation_one[j] = FileInformation_one[k];
                    FileInformation_one[k] = temp;
                    k++;
                    sizes[i]--;
                }
            }
        }
    }
    free(sizes);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void showMenu() { //выводит меню в консоль
    printf("\n \t Меню\n");
    for (int i = 0; i < numberOfItemsInTheMenu; i++) {
        printf("%s\n", menu[i]);
    }
}
int getNumberOfMenu(const int numberOfItemsInTheMenu) {
    int selectedMenuItem;
    int userEnteredTheNumber;
    scanf_s("%d", &selectedMenuItem);
    while (selectedMenuItem<1 || selectedMenuItem>numberOfItemsInTheMenu) {
        printf("Такого пункта нет в меню: повторите ввод заново!\n"); // выводим сообщение об ошибке
        scanf_s("%d", selectedMenuItem); // считываем строку повторно
    }
    return selectedMenuItem;//возвращаем выбранный пункт в меню
}
void showMenuSoarting() {
    printf("\n1.По возрастанию \n2.По убыванию\n");
    printf("Каким способом желаете отсортировать?\n");
}
float getTime(double  timeOne, double  timeTwo, int selectMenuItem) {
    float sortingTime = timeTwo - timeOne;
    soartingInformation[selectMenuItem].timeOfSoarting = sortingTime;//СОХРАНИМ В СТРУКТУРУ О СОРТИРОВКАХ ЗА СКОЛЬКО ВРЕМЯ ВЫБРАННАЯ СОРТИРОВКА ОТСОРТИРОВАЛА ФАЙЛ
    return sortingTime;
}