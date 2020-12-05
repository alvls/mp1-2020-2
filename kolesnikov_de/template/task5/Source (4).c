#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <omp.h>
#include <memory.h>
#include <string.h>
#include <limits.h>
#include <Windows.h>
#define CountSorts 7
//DATA
char path[FILENAME_MAX];
char oldpath[FILENAME_MAX];
int mode, countofsorts,flag = 1,alarm=1;
char temp;
char* Dialog[] = { "Please input path to catalog(format: disk:\\folders)\n","\t\t\t\t\tPlease input method of sort\n",
"Files sorted by size\n" };
char* SortList[] = { "SortBubble","SortSelection","SortInsert",
"SortMerge","SortShell","SortQuick","SortCouting" };
long double times[CountSorts];
int activation[CountSorts] = { 0 };
typedef
struct _S
{
	int size;
	char* name;
}S;

//Sorts
void merge(int lb, int ub, S* s) { //need memory fix 
	int split = (ub + lb) / 2;
	S* buffer;
	ub += 1;
	buffer = (S*)malloc((ub) * sizeof(S));
	int i = lb;
	int k = 0;
	int j = split + 1;
	for (k = lb; k < ub; k++)
	{
		if ((i <= split) && (j < ub))
		{
			if (s[i].size >= s[j].size)
			{
				buffer[k] = s[i];
				i++;
			}
			else
			{
				buffer[k] = s[j];
				j++;
			}
		}
		else
		{
			if (i == split + 1)
			{
				for (; j < ub; j++, k++)
				{
					buffer[k] = s[j];
				}
			}
			else
			{
				for (; i < split + 1; i++, k++)
				{
					buffer[k] = s[i];
				}
			}
		}
	}
	for (k = lb; k < ub; k++)
	{
		s[k] = buffer[k];
	}
	free(buffer);
}
void SortBubble(int count, S* s) {
	S buffer;
	for (int i = 0; i < count; i++)
	{
		for (int j = count - 1; j > i; j--)
		{
			if (s[j - 1].size < s[j].size)
			{
				buffer = s[j - 1];
				s[j - 1] = s[j];
				s[j] = buffer;
			}
		}
	}
}
void SortSelection(int count, S* s) {
	S buffer;
	int i, j;
	int k;
	for (i = 0; i < count; i++)
	{
		k = i;
		buffer = s[i];
		for (j = i + 1; j < count; j++)
		{
			if (s[j].size > buffer.size)
			{
				k = j;
				buffer = s[j];
			}
		}
		s[k] = s[i];
		s[i] = buffer;
	}
}
void SortInSert(int count, S* s) {
	S buffer;
	int j;
	for (int i = 0; i < count; i++)
	{
		buffer = s[i];
		for (j = i - 1; (j >= 0) && (s[j].size < buffer.size); j--)
		{
			s[j + 1] = s[j];
		}
		s[j + 1] = buffer;
	}
}
void SortMerge(int lb, int ub, S* s) {
	int split = (lb + ub) / 2;
	if (lb < ub) {
		split = (lb + ub) / 2;
		SortMerge(lb, split, s);
		SortMerge(split + 1, ub, s);
		merge(lb, ub, s);
	}
}
void SortShell(int count, S* s) {
	S buffer;
	long inc, i, j;
	long* seq = (long*)malloc(40 * sizeof(long));
	int k;
	k = increment(seq, count);
	while (k >= 0)
	{
		inc = seq[k--];
		for (i = inc; i < count; i++)
		{
			buffer = s[i];
			for ((j = i - inc); ((j >= 0) && (s[j].size < buffer.size)); (j -= inc))
			{
				s[j + inc] = s[j];
			}
			s[j + inc] = buffer;
		}
	}
	free(seq);
}
int increment(int inc[], int count) {
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
void SortQuick(S* s, int count) { //Hoara sort
	int i = 0;
	int j = count;
	int mid = count / 2;
	unsigned long size = s[mid].size;
	S buffer;
	do
	{
		while (s[i].size > size)
		{
			i++;
		}
		while (s[j].size < size)
		{
			j--;
		}
		if (i <= j)
		{
			buffer = s[i];
			s[i] = s[j];
			s[j] = buffer;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		SortQuick(s, j);
	if (count > i)
		SortQuick(s + i, count - i);
}
void SortCouting(int count, S* s) {
	int k = count - 1;
	S buffer;
	unsigned long* countequalsizes;
	unsigned long minsize, maxsize, size;
	minsize = maxsize = s[0].size;
	for (int i = 0; i < count; i++)
	{
		if (s[i].size < minsize)
		{
			minsize = s[i].size;
		}
		if (s[i].size > maxsize)
		{
			maxsize = s[i].size;
		}
	}
	size = maxsize - minsize + 1;
	countequalsizes = (unsigned long*)malloc(size * sizeof(unsigned long));
	for (_fsize_t i = 0; i < size; i++)
	{
		countequalsizes[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		countequalsizes[s[i].size - minsize]++;
	}
	for (_fsize_t i = 0; i < size; i++)
	{
		while (countequalsizes[i] > 0)
		{
			for (int j = k; j >= 0; j--)
			{
				if (s[j].size == minsize + i)
				{
					buffer = s[j];
					s[j] = s[k];
					s[k] = buffer;
					k--;
					countequalsizes[i]--;
				}
			}
		}
	}
	free(countequalsizes);
}

//Program
long double StartSort(int code, S* s, int size) {
	long double tt1, tt2;
	tt1 = omp_get_wtime();
	switch (code)
	{
	case 0:
		SortBubble(size, s);
		break;
	case 1:
		SortSelection(size, s);
		break;
	case 2:
		SortInSert(size, s);
		break;
	case 3:
		SortMerge(0, size - 1, s);
		break;
	case 4:
		SortShell(size, s);
		break;
	case 5:
		SortQuick(s, size - 1);
		break;
	case 6:
		SortCouting(size, s);
		break;
	default:
		break;
	}
	tt2 = omp_get_wtime();
	return(tt2 - tt1);
}
void Correctpath() {
	int i = 0;
	char temp;
	temp = path[i];
	while (temp != '\0') {
		if (temp == '\\') {
			path[i] = '/';
		}
		i++;
		temp = path[i];
	}
	path[i - 1] = '/';
	path[i] = '*';
	path[i + 1] = '.';
	path[i + 2] = '*';
	path[i + 3] = '\0';
}
int ScanMode(int count) {
	printf(Dialog[1]);
	printf("SortList:\n");
	for (int i = 0; i < count; i++) {
		printf("%d:%s", i + 1, SortList[i]);
		printf("\n");
	}
	scanf_s("%d", &mode);
	return (mode-1);
}
void StatSave(int mode, long double timer) {
	activation[mode] = 1;
	times[mode] = timer;
}
void ShowStat() {
	if (alarm == 1) {
		printf_s("First need to add correct path\n");
		system("pause");
		return;
	}
	system("cls");
	long double max = 0;
	long double min = 1000;
	long double buf;
	int minInd;
	int maxInd;
	int k = 1;
	int temp = CountSorts;
	oldpath[strlen(oldpath)-1] = 0;
	printf("List of sorts on catalog %s\n\n", oldpath);
	for (int i = 0; i < temp; i++) {
		if (activation[i] == 1) {
			buf = times[i];
			if (buf <= min) {
				min = buf;
				minInd = i;
			}
			if (buf >= max) {
				max = buf;
				maxInd = i;
			}
			printf("%d:%s\t%Lf\n", k, SortList[i], buf);
			k += 1;
			
		}
	}
	printf("\n");
	printf("Fastest sort is %s with time %Lf\n", SortList[minInd], min);
	printf("Slowest sort is %s with time %Lf\n", SortList[maxInd], max);
	system("pause");
	system("cls");
}
void ToScreen(long double time, int count, S* s,int mode) {
	StatSave(mode,time);
	system("cls");
	printf("\t\t\t\tSorted files\n");
	printf("NAME\r\t\t\t\t\t\tSIZE\n");
	if (flag == 1) {
		for (int i = 0; i < count; i++) {
			printf_s("%d:%0.44s\r\t\t\t\t\t\t%d\n", i + 1, s[i].name, s[i].size);
		}
	}
	if (flag == -1) {
		for (int i = count -1; i>-1; i--) {
			printf_s("%d:%0.44s\r\t\t\t\t\t\t%d\n", count - i, s[i].name, s[i].size);
		}
	}
	for (int i = 0; i < 26; i++) {
		printf_s("-");
	}
	printf_s("\n");
	printf("Time of sort is - %Lf\nFiles count - %d\n", time,count);
	system("pause");
	system("cls");
}
void FileScan() {
	for (int i = 0; i < (CountSorts-1); i++) {
		activation[i] = 0;
		times[i] = 0.0;
	}
	int tmode;
	int temp1;
	int sel,mode;
	long double time;
	printf(Dialog[0]);
	while (getchar() != '\n');
	fgets(path, FILENAME_MAX, stdin);
	if (strlen(path)<4) {
		alarm = 1;
		printf("The path is empty!\n");
		system("pause");
		return;
	}
	strcpy(oldpath, path);
	printf_s("Your path is %s\n", path);
	Correctpath();
	struct _finddata_t c_file;
	intptr_t hFile;
	int count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L) {
		printf("No files in current directory!\n");
		alarm = 1;
		system("pause");
		return;
	}
	else
	{
		alarm = 0;
		do {
			if (c_file.attrib & _A_SUBDIR)
				continue;
			count++;
		} while (_findnext(hFile, &c_file) == 0);
	}

	S* ss = (S*)malloc(count * sizeof(S));
	count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L) {
	}//"c:/temp/*.* -1 find not found
	else {
		do {
			if (c_file.attrib & _A_SUBDIR)
				continue;
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &c_file.time_write);
			temp1 = c_file.size;
			ss[count].size = temp1;
			ss[count].name = (char*)malloc(sizeof(char) * strlen(c_file.name));
			strcpy(ss[count].name, c_file.name);
			count++;
		} while (_findnext(hFile, &c_file) == 0);
	}
	_findclose(hFile);
	mode = ScanMode(CountSorts);
	time = StartSort(mode, ss, count);
	ToScreen(time, count, ss,mode);
	while (1) {
		printf("\t\t\t\t\tSelect action:\n1-Another Sort\n2-Compare Done Sorts\n3-Exit to menu\n");
		scanf_s("%d", &sel);
		switch (sel)
		{
		case 1:
			tmode = ScanMode(CountSorts);
			time = StartSort(tmode, ss, count);
			ToScreen(time, count, ss,tmode);
			break;
		case 2:
			ShowStat();
			break;
		case 3:
			free(ss);
			return;
		default:
			free(ss);
			return;
		}
	}

}
int Menu() {
	int mode;
	while (1) {
		system("cls");
		if (flag == 1) {
			printf_s("\t\t\t\t\t\t ------------\n");
			printf_s("\t\t\t\t\t\t|PROGRAM MENU|\n\t\t\t\t\t\t ------------\n1:Input path to catalog\n"
				"2:Compare the sorts,done with last location\n3:Sort in direct order(click to edit)\n0:Exit\n");
		}
		if (flag == -1) {
			printf_s("\t\t\t\t\t\t ------------\n");
			printf_s("\t\t\t\t\t\t|PROGRAM MENU|\n\t\t\t\t\t\t ------------\n1:Input path to catalog\n"
				"2:Compare the sorts,done with last location\n3:Sort in the reverse order(click to edit)\n0:Exit\n");
		}
		scanf_s("%d", &mode);
		switch (mode)
		{
		case 1:
			FileScan();
			break;
		case 2:
			ShowStat();
			break;
		case 3:
			if (flag == 1) {
				flag = -1;
			}
			else if (flag == -1) {
				flag = 1;
			}
			break;
		case 0:
			return 0;
		default:
			printf_s("Try to input correct option\n");
			system("pause");
			break;
		}
	}
}
int main(void){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int out = 1;
	while (out != 0) {
		out = Menu();
	}
}
