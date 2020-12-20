#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  

int main(void)
{
    struct _finddata_t c_file;
    intptr_t hFile;
    char path[200];
    int count = 0;

    // Find first file in directory c:\temp
    if ((hFile = _findfirst("c:\\temp\\*.*", &c_file)) == -1L)
        printf("No files in current directory!\n");
    else
    {
        printf("Listing of .c files\n\n");
        printf("FILE         DATE %24c   SIZE\n", ' ');
        printf("----         ---- %24c   ----\n", ' ');
        do {
            char buffer[30];
            ctime_s(buffer, _countof(buffer), &c_file.time_write);
            if (count <= 20)
                printf("%-12.12s %.24s  %10ld\n", c_file.name, buffer, c_file.size);
            count++;
        } while (_findnext(hFile, &c_file) == 0);
        _findclose(hFile);
        printf("\ncount of files: %d", count);
    }
} 