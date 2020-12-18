#ifndef _0_MAIN_H_
#define _0_MAIN_H_

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979323846
#define NMAX 25

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include <locale.h>
#include <math.h>
#include <windows.h> //ƒл€ clearscreen

//ќбъ€вление типа указатель на функцию

typedef double (*function)(int, double, double);
typedef int (*rezhimfunction)(double, int, int, double, function, double, double);

#endif // !MAIN_H_
