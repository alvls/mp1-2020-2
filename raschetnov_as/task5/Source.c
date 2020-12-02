#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <memory.h>
#include <time.h>
int choice;
int selection = 0;
struct filesInformation
{
    int size;
    char name[30];
    char editDate[24];
};
struct filesInformation* information;

char stringHelper[256];


int programMenu();
void mainMenuChoiceInfo();
void programAbilities();
void sortingMethods();
void sortingPreference();
void sortingMethodChoice(int AmountOfFiles);
void elementsSwap(int* element1, int* element2);
void bubbleSort(int AmountOfFiles);
void printFunction1(int AmountOfFiles);
void printChoice(int AmountOfFiles);
void printFunction2(int AmountOfFiles);
void furtherOptions();
void insertionSort(int AmountOfFiles);
void selectionSort(int AmountOfFiles);
void mergeSort(int l, int AmountOfFiles);
void merge(int l, int m, int AmountOfFiles);
void quickSort(int low, int AmountOfFiles);
int partition(int low, int AmountOfFiles);


void printChoice(int AmountOfFiles)
{
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printFunction1(AmountOfFiles);
        break;
    }
    case 2:
    {
        printFunction2(AmountOfFiles);
        break;
    }
    }
}

void furtherOptions()
{
    printf("What do you want to do next ?\n");
    printf("1. Change folder's path\n");
    printf("2. Change sorting method\n");
    printf("3. Change how you want to sort files (by ascending or by descending)\n");
    printf("4. Exit\n");
}


void printFunction1(int AmountOfFiles)
{
    int i;
    printf("Listing of files:\n\n");
    printf("FILE   %30cDATE %30c SIZE\n", ' ', ' ');
    printf("----   %30c---- %30c ----\n", ' ', ' ');
    for (i = 0; i < AmountOfFiles; i++)
        printf("%-36s %-35.24s %d\n", information[i].name, information[i].editDate, information[i].size);
}

void printFunction2(int AmountOfFiles)
{
    int i;
    printf("Listing of files:\n\n");
    printf("FILE   %30cDATE %30c SIZE\n", ' ', ' ');
    printf("----   %30c---- %30c ----\n", ' ', ' ');
    for (i = AmountOfFiles - 1; i >= 0; i--)
        printf("%-36s %-35.24s %d\n", information[i].name, information[i].editDate, information[i].size);
}

void sortingPreference()
{
    printf("Choose how you want to sort files:\n");
    printf("1. By ascending.\n");
    printf("2. By descending.\n");
}

void elementsSwap(int* element1, int* element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void bubbleSort(int AmountOfFiles)
{
    int i;
    if (AmountOfFiles == 1)
        return;
    for (i = 0; i < AmountOfFiles - 1; i++)
        if (information[i].size > information[i + 1].size)
        {
            elementsSwap(&information[i].size, &information[i + 1].size);
            strcpy(stringHelper, information[i + 1].name);
            strcpy(information[i + 1].name, information[i].name);
            strcpy(information[i].name, stringHelper);
            strcpy(stringHelper, information[i + 1].editDate);
            strcpy(information[i + 1].editDate, information[i].editDate);
            strcpy(information[i].editDate, stringHelper);
        }
    bubbleSort(AmountOfFiles - 1);
}

void selectionSort(int AmountOfFiles)
{
    int i, j, minIndex;
    for (i = 0; i < AmountOfFiles - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < AmountOfFiles; j++)
            if (information[j].size < information[minIndex].size)
                minIndex = j;
        elementsSwap(&information[minIndex].size, &information[i].size);
        strcpy(stringHelper, information[minIndex].name);
        strcpy(information[minIndex].name, information[i].name);
        strcpy(information[i].name, stringHelper);
        strcpy(stringHelper, information[minIndex].editDate);
        strcpy(information[minIndex].editDate, information[i].editDate);
        strcpy(information[i].editDate, stringHelper);
    }
}

void insertionSort(int AmountOfFiles)
{
    int i = 0;
    int last = information[AmountOfFiles - 1].size;
    int j = AmountOfFiles - 2;
    if (AmountOfFiles <= 1)
        return;
    insertionSort(AmountOfFiles - 1);
    while (j >= 0 && information[j].size > last)
    {
        information[j + 1].size = information[j].size;
        strcpy(stringHelper, information[j + 1].name);
        strcpy(information[j + 1].name, information[j].name);
        strcpy(information[j].name, stringHelper);
        strcpy(stringHelper, information[j + 1].editDate);
        strcpy(information[j + 1].editDate, information[j].editDate);
        strcpy(information[j].editDate, stringHelper);
        j--;
    }
    information[j + 1].size = last;
}

void mergeSort(int l, int AmountOfFiles)
{
    if (l < AmountOfFiles) {
        int m = l + (AmountOfFiles - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, AmountOfFiles);
        merge(l, m, AmountOfFiles);
    }
}

void merge(int l, int m, int AmountOfFiles)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = AmountOfFiles - m;
    int* L;
    int* R;
    L = (int*)malloc(sizeof(int) * n1);
    R = (int*)malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++)
        L[i] = information[l + i].size;
    for (j = 0; j < n2; j++)
        R[j] = information[m + 1 + j].size;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            information[k].size = L[i];
            strcpy(stringHelper, information[k].name);
            strcpy(information[k].name, information[i].name);
            strcpy(information[i].name, stringHelper);
            strcpy(stringHelper, information[k].editDate);
            strcpy(information[k].editDate, information[i].editDate);
            strcpy(information[i].editDate, stringHelper);
            i++;
        }
        else {
            information[k].size = R[j];
            strcpy(stringHelper, information[k].name);
            strcpy(information[k].name, information[i].name);
            strcpy(information[i].name, stringHelper);
            strcpy(stringHelper, information[k].editDate);
            strcpy(information[k].editDate, information[i].editDate);
            strcpy(information[i].editDate, stringHelper);
            j++;
        }
        k++;
    }
    while (i < n1) {
        information[k].size = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        information[k].size = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

int partition(int low, int AmountOfFiles)
{
    int pivot = information[AmountOfFiles].size;
    int i = (low - 1);
    int j;
    for (j = low; j <= AmountOfFiles - 1; j++)
    {
        if (information[j].size < pivot)
        {
            i++;
            elementsSwap(&information[i].size, &information[j].size);
            strcpy(stringHelper, information[i].name);
            strcpy(information[i].name, information[j].name);
            strcpy(information[j].name, stringHelper);
            strcpy(stringHelper, information[i].editDate);
            strcpy(information[i].editDate, information[j].editDate);
            strcpy(information[j].editDate, stringHelper);

        }
    }
    elementsSwap(&information[i + 1].size, &information[AmountOfFiles].size);
    strcpy(stringHelper, information[i].name);
    strcpy(information[i].name, information[j].name);
    strcpy(information[j].name, stringHelper);
    strcpy(stringHelper, information[i].editDate);
    strcpy(information[i].editDate, information[j].editDate);
    strcpy(information[j].editDate, stringHelper);
    return (i + 1);
}

void quickSort(int low, int AmountOfFiles)
{
    if (low < AmountOfFiles)
    {
        int pi = partition(low, AmountOfFiles);
        quickSort(low, pi - 1);
        quickSort(pi + 1, AmountOfFiles);
    }
}

void sortingMethodChoice(int AmountOfFiles)
{
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        bubbleSort(AmountOfFiles);
        break;
    }
    case 2:
    {
        insertionSort(AmountOfFiles);
        break;
    }
    case 3:
    {
        selectionSort(AmountOfFiles);
        break;
    }
    case 4:
    {
        mergeSort(0, AmountOfFiles);
        break;
    }
    case 5:
    {
        quickSort(0, AmountOfFiles);
        break;
    }
    }
}

void sortingMethods()
{
    printf("Choose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. QuickSort\n");
}

void mainMenuChoiceInfo()
{
    printf("1. What this program can do.\n");
    printf("2. Sort files.\n");
    printf("3. Exit.\n\n");
}

void programAbilities()
{
    printf("This program is supposed to sort files by ascending or by descending using different sorting methods.\n");
    printf("All you have to do is choose sorting method, choose how you want to sort them (by ascending or by descending) and then enter path to the your PC'sfolder.\n\n");
    programMenu();
}
int programMenu()
{
    mainMenuChoiceInfo();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        programAbilities();
        break;
    }
    case 2:
    {
        printf("\n");
        break;
    }
    case 3:
    {
        break;
    }
    }
    return choice;
}

void stringEditor(char* string, char* stringcopy, int stringcopylen)
{
    int i = 0, k = 0;
    char* slashes = "\\";
    slashes = (char*)malloc(sizeof(char) * 4);
    for (i = 0; i < stringcopylen; i++)
        stringcopy[i] = 0;
    char* stringPointer;
    stringPointer = strtok(string, slashes);
    while (stringPointer != NULL)
    {
        strcat(stringcopy, stringPointer);
        strcat(stringcopy, "\\\\");
        stringPointer = strtok(NULL, slashes);
    }
    strcat(stringcopy, "*.*");
    free(slashes);
}

void main()
{
    int i = 0;
    int stringcopylen = 256;
    int AmountOfFiles = 0;
    int counter = 0;
    char* string;
    char* stringcopy;
    struct _finddata_t file;
    intptr_t hFile;
    string = (char*)malloc(sizeof(char*) * 256);
    stringcopy = (char*)malloc(sizeof(char*) * 256);
    printf("Greetings. This program will help you sort your files. Choose one of the following options below.\n\n");
    programMenu();
    if (choice == 3)
        return;
    while (selection != 4)
    {
        i = 0;
        AmountOfFiles = 0;
        selection = 0;
        printf("Enter path to a folder\n");
        getchar();
        gets(string);
        stringEditor(string, stringcopy, stringcopylen);
        printf("\n");
        if ((hFile = _findfirst(stringcopy, &file)) == -1L)
            printf("No files in current directory!\n");
        else
        {
            do
            {
                AmountOfFiles++;
            } while (_findnext(hFile, &file) == 0);
            _findclose(hFile);
            while (selection != 1 && selection != 4)
            {
                i = 0;
                information = (struct filesInformation*)malloc(sizeof(struct filesInformation) * AmountOfFiles);
                hFile = _findfirst(stringcopy, &file);
                do
                {
                    char buffer[30];
                    ctime_s(buffer, _countof(buffer), &file.time_write);
                    information[i].size = file.size;
                    strcpy(information[i].name, file.name);
                    strcpy(information[i].editDate, buffer);
                    i++;
                } while (_findnext(hFile, &file) == 0);
                _findclose(hFile);
                selection = 0;
                sortingMethods();
                sortingMethodChoice(AmountOfFiles);
                while (selection != 1 && selection != 2 && selection != 4)
                {
                    sortingPreference();
                    printChoice(AmountOfFiles);
                    printf("\n");
                    furtherOptions();
                    scanf("%d", &selection);
                }
            }
            free(information);
        }
    }
    free(string);
    free(stringcopy);
}
