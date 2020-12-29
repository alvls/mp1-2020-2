#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <string.h>
#include <omp.h> 

char path[100];
struct _finddata_t file;
intptr_t hFile;
int count = 0;

int history[22];    // FOR HISTORY LOG
int hsize = 0;
double timers[22];
int reverses[22];

void swap(struct  _finddata_t* a, struct  _finddata_t* b) { //SWAP
    struct _finddata_t c = *a;
    *a = *b;
    *b = c;
}

void print_time(double time) {
    time = time * 1000;   // get in ms

    if (time > 60000)   //  MORE THAN MIN
        printf("%d min %d sec\n", (int)time / 60000, (int)(time / 1000) % 60);
    else
        if (time > 1000)    //MORE THAN SEC
            printf("%d sec %d ms\n", (int)time / 1000, (int)(time) % 1000);
        else
            printf("%d ms\n", (int)time);
}

void Hystory() {
    for (int i = 0; i < hsize; i++) {
        switch (history[i]) {
        case 1:
            printf("Bubble     ");
            break;
        case 2:
            printf("Selection  ");
            break;
        case 3:
            printf("Insertion  ");
            break;
        case 4:
            printf("Merge      ");
            break;
        case 5:
            printf("Quick      ");
            break;
        case 6:
            printf("Shell      ");
            break;
        case 7:
            printf("Counting   ");
            break;
        }
        if(reverses[i] == 0)
            printf("(123)  ");
        else
            printf("(321)  ");
        print_time(timers[i]);
        printf("\n");
    }
}

void Bubble(struct _finddata_t* files, int n) {   //BUBBLE
    int f, i, j;
    for (i = n - 1; i != 0; i--) {
        f = 1;
        for (j = 0; j < i; j++)
            if (files[j].size > files[j + 1].size) {
                swap(files + j, files + j + 1);
                f = 0;
            }
        if (f)
            break;
    }
}

void Selection(struct _finddata_t* files, int n) {   //SELECTION
    int min, imin, i, j;
    for (i = 0; i < n; i++) {
        min = files[i].size;
        imin = i;
        for (j = i + 1; j < n; j++)
            if (files[j].size < min) {
                min = files[j].size;
                imin = j;
            }
        swap(files + imin, files + i);
    }
}

void Insertion(struct _finddata_t* files, int n) {   //INSERTION
    int i, j; struct _finddata_t first = files[0], x;
    for (i = 1; i < n; i++)     //find min
        if (files[i].size < files[0].size)
            files[0] = files[i];

    for (i = 1; i < n; i++) {   //sort
        x = files[i];
        for (j = i - 1; files[j].size > x.size; j--)
            files[j + 1] = files[j];
        files[j + 1] = x;
    }

    for (i = 1; i < n && files[i].size < first.size; i++) //put first
        files[i - 1] = files[i];

    files[i - 1] = first;
}

void merge(struct _finddata_t* files, int l, int mid, int r) { // For Merge
    int N = mid - l + 1, M = r - mid, k, i = 0, j = 0;
    struct _finddata_t *a = files + l, *b = files + mid + 1;
    struct _finddata_t *buff = (struct _finddata_t*)malloc(sizeof(struct _finddata_t) * (N + M));

    for (k = 0; k < N + M; k++)
        if ((i < N) && (j < M))
            if (a[i].size <= b[j].size) {
                buff[k] = a[i];
                i++;
            }
            else {
                buff[k] = b[j];
                j++;
            }
        else {
            if (i == N)
                for (; j < M; j++) {
                    buff[k] = b[j];
                    k++;
                }
            else
                for (; i < N; i++) {
                    buff[k] = a[i];
                    k++;
                }
        }

    for (k = 0; k < r - l + 1; k++) {
        files[l + k] = buff[k];
    }
    free(buff);
}

void Merge(struct _finddata_t* files, int l, int r) {    // Merge
    int mid;
    if (l < r) {
        mid = (l + r) / 2;
        Merge(files, l, mid);
        Merge(files, mid + 1, r);
        merge(files, l, mid, r);
    }
}

void Quick(struct _finddata_t* files, int n) {   //    Quick
    int i = 0, j = n - 1, p = files[n >> 1].size;
    do {
        while (files[i].size < p) i++;
        while (files[j].size > p) j--;
        if (i <= j) {
            swap(files + i, files + j);
            i++; j--;
        }
    } while (i <= j);

    if (j > 0) Quick(files, j + 1);
    if (n > i) Quick(files + i, n - i);
}

int increment(int inc[], int size) {   //  for Shell
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

    return s > 0 ? --s : 0;
}

void Shell(struct _finddata_t* files, int n) {    // SHELL 
    int inc, i, j, seq[40];
    int s;
    s = increment(seq, n);

    while (s >= 0) {
        inc = seq[s--];
        for (i = inc; i < n; i++) {
            struct _finddata_t temp = files[i];
            for (j = i - inc; (j >= 0) && (files[j].size > temp.size); j -= inc) {
                files[j + inc] = files[j];
            }
            files[j + inc] = temp;  
        }
    }
}

Counting(struct _finddata_t* files, int n) {     // COUNTING
    int min, max, i, k = 0, c;
    struct _finddata_t** buff;
    struct _finddata_t* copy;
    int* count;
    min = max = files[0].size;
    for (i = 1; i < n; i++) {
        if (files[i].size < min)
            min = files[i].size;
        if (files[i].size > max)
            max = files[i].size;
    }
    c = max - min + 1;          // POINTER TO FILES MATRIX 
    copy = (struct _finddata_t*)malloc(sizeof(struct _finddata_t) * n);
    buff = (struct _finddata_t**)malloc(sizeof(struct _finddata_t*) * c * n);
    count = (int*)malloc(sizeof(int) * c);
    
    for (i = 0; i < n; i++)
        copy[i] = files[i];
    for (i = 0; i < c; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        buff[n * (copy[i].size - min) + count[copy[i].size - min]++] = copy + i;
    
    for (i = 0; i < c; i++)
        for(int j = 0; j < count[i] ; j++)
            files[k++] = *buff[n * i + j];
    free(copy);
    free(count);
    free(buff);
}

void main() {
    struct _finddata_t *files, *copy;
    int sort = 0, reverse = 0, next = 0;
    double timer;

    printf("Enter path to directory: \n");
    fgets(path, 100, stdin);    //path processing
    path[strlen(path)-1] = 0;
    int i = 0;
    while (path[i] != 0) {
        if (path[i] == 92)
            path[i] = '/';
        i++;
    }
    strcat(path, "/*.*");

    if ((hFile = _findfirst(path, &file)) == -1L)
        printf("No files in current directory!\n"); //counting files
    else {
        do {
            count++;
        } while (_findnext(hFile, &file) == 0);
        _findclose(hFile);
        count -= 2;
        if (count < 1) {
            printf("No files in directory \n");
            return;
        }
        else {
            files = (struct _finddata_t*)malloc(sizeof(struct _finddata_t) * count);

            hFile = _findfirst(path, &file);
            _findnext(hFile, &file);            //  SKIP . AND ..
            _findnext(hFile, &file);

            printf("FILE  %28c  SIZE\n", ' ');
            for (int i = 0; i < count; i++) {
                printf("%-26.26s  %12d\n", file.name, file.size);
                files[i] = file;
                _findnext(hFile, &file);
            }
            _findclose(hFile);
        }
        printf("\ncount of files: %d \n\n", count);

        copy = (struct _finddata_t*)malloc(sizeof(struct _finddata_t) * count);
        for (int i = 0; i < count; i++)             //  COPY OF ARRAY
            copy[i] = files[i];

        do {
            if (hsize > 0) {
                system("cls");

                printf("History: \n");  // HISTORY PRINT
                Hystory();
                printf("\n");

                printf("FILE  %28c  SIZE\n", ' ');
                for (int i = 0; i < count; i++) { // LOAD COPY
                    files[i] = copy[i];
                    printf("%-26.26s  %12d\n", files[i].name, files[i].size);
                }
                printf("\n");
            }
            printf("Choose the sorting algorithm:\n");
            printf("1 Bubble Sort\n");
            printf("2 Selection Sort\n");
            printf("3 Insertion Sort\n");
            printf("4 Merge Sort\n");
            printf("5 Quicksort\n");
            printf("6 Shell\n");
            printf("7 Counting sort\n");
            scanf_s("%d", &sort);
            if (sort < 1 || sort > 7) {
                printf("Wrong enter \n");
                next = 0;
                continue;
            }
            history[hsize] = sort;  //  history

            printf("Order 123 (0) or 321(any other number): ");
            scanf_s("%d", &reverse);            // ORDER
            reverses[hsize] = reverse;

            timer = omp_get_wtime();     // start timer

            switch (sort) { // SORT
            case 1:
                Bubble(files, count);
                break;
            case 2:
                Selection(files, count);
                break;
            case 3:
                Insertion(files, count);
                break;
            case 4:
                Merge(files, 0, count - 1);
                break;
            case 5:
                Quick(files, count);
                break;
            case 6:
                Shell(files, count);
                break;
            case 7:
                Counting(files, count);
                break;
            }
            timer = omp_get_wtime() - timer;    // DETECT TIME
            system("cls");
            timers[hsize] = timer;
            hsize++;

            printf("FILE  %28c  SIZE\n", ' ');
            if (reverse)
                for (int i = count - 1; i >= 0; i--)
                    printf("%-26.26s  %12d\n", files[i].name, files[i].size);
            else
                for (int i = 0; i < count; i++)
                    printf("%-26.26s  %12d\n", files[i].name, files[i].size);

            printf("\nTime spend: ");
            print_time(timer);

            printf("\nExit - 0\nAgain - any other number\n");
            scanf_s("%d", &next);
        } while (next);
    }
    system("pause");
}
