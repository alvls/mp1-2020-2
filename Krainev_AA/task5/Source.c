/*Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию / убыванию размера.

Входные данные :
Путь до директории, в которой необходимо отсортировать содержимое.
Метод сортировки.
Выходные данные :
Отсортированный список имен файлов с указанием размера.
Время сортировки.
Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.

Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает :
возможность ввода пути до заданного каталога;
возможность выбора метода сортировки;
возможность просмотра отсортированного списка файлов с указанием размера.
Cписок методов сортировки :
1) Пузырьком
2) Выбором
3) Вставками
4) Слиянием
5) Хоара
6) Шелла
7) Подсчетом*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
#include <dos.h>
#include <string.h>
//меню
char* menu[] = {
	"1. Сортировка пузырьком",
	"2. Сортировка выбором",
	"3. Сортировка вставками",
	"4. Сортировка слиянием",
	"5. Сортировка Хоара",
	"6. Сортировка Шелла",
	"7. Сортировка подсчетом",
	"8. Выход",
};
const int numberOfItemsInTheMenu = sizeof(menu) / sizeof(char*);//количество пунктов в меню
void retrievingInformationAboutFiles(hFile);

void showMenu() { //выводит меню в консоль
	system("cls");
	printf("\t Меню\n");
	for (int i = 0; i < numberOfItemsInTheMenu; i++) {
		printf("%s\n", menu[i]);
	}
}

int selectMenu(const int numberOfItemsInTheMenu) {
	//считывает пункт меню с проверкой на неверно введенный символ или пункт 
	//будем считывать строку чтобы предотвратить некорректный ввод 
	int selectedMenuItem;
	char userEnteredTheNumber[50];
	gets_s(userEnteredTheNumber, 50); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(userEnteredTheNumber, "%d", &selectedMenuItem) != 1 || selectedMenuItem < 1 || selectedMenuItem > numberOfItemsInTheMenu) {
		printf("Такого пункта нет в меню: повторите ввод заново!\n"); // выводим сообщение об ошибке
		scanf("%s", userEnteredTheNumber); // считываем строку повторно
	}
	return selectedMenuItem;//возвращаем выбранный пункт в меню
}
//Сортировка пузырьком
void bubbleSort() {

}
//Сортировка выбором 
void selectionSort() {

}
//Сортировка вставками
void insertionSort() {

}
//Сортировка слиянием
void mergeSort() {

}
//Сортировка Хоара
void quickSort() {

}
//Сортировка Шелла
void shellSort() {

}
//Сортировка подсчетом
void  countingSort() {

}



//ввод пути директория 
char directoryPath[250];
char enteringDirectoryPath() {
	printf("Введите путь до  директория (например : C:\\\\temp\\\\*.*) : \n");
	gets_s(directoryPath, 250);
	printf("Выбранный каталог %s\n", directoryPath);
	strcat(directoryPath, "*");//приклеим в конец адреса звездочку
	return directoryPath;
}
//получение иноформации о файлах
struct ftime {
	unsigned ft_tsec : 5; /* секунды */
	unsigned ft_min : 6; /* минуты */
	unsigned ft_hour : 5; /* часы */
	unsigned ft_day : 5; /* дни */
	unsigned ft_month : 4; /* месяцы */
	unsigned ft_year : 7; /* годы с 1980 */
};
//получение иноформации о файлах
void retrievingInformationAboutFiles(directoryPath) {//получение иноформации о файлах
	struct _finddata_t sortableFile; //сортируемый sortableFile.name sortableFile.size sortableFile.time
	printf("Выбранный каталог 1232113 %s\n", directoryPath);
	intptr_t hFile; //memsize тип intptr_t хранит в себе указатель hFile
	//char path[200];//для хранения 
	int numberOfFiles = 0; //счетчик 
	//int fd;
	if ((hFile = _findfirst(directoryPath, &sortableFile)) == -1L)//-1L ЕСЛИ НЕ БУДЕТ РАБОТАТЬ
		//если ф. _findfirst возвратит -1: в выбранной директории нет файло. Если 0 то есть.
		printf("В выбранной папке нет файлов или адрес указан неверно!\n");
	else
	{
		printf("Список файлов в указанной папке (без сортировки)\n\n");
		printf("Имя файла         Дата и время создания создания %16c   Размер\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do { // делаем пока есть файлики в директории
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &sortableFile.time_write);
			if (numberOfFiles<=200)
				
				printf("%-14.14s %-5.22s      %16ld\n", sortableFile.name, buffer ,sortableFile.size);
			numberOfFiles ++;







			char bufferTime[30];//для хранения даты и времени создания файла
			// _countof(buffer) выполняет вычисление количества элементов в статическом массиве buffer[30].
			struct ftime p;
			int fd;
			//fd= open("TEST.TST")
			//getftime(hFile, &fd);
			//printf("%d", p.ft_year + 1980);
			//ctime_s(bufferTime, _countof(bufferTime), &sortableFile.time_write);//Преобразуют значение времени в строку и настраивают 
			//его в соответствии с параметрами локального часового пояса
		} while (_findnext(hFile, &sortableFile) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", numberOfFiles);
	}

}

int main() {
	//system("pause");
	setlocale(LC_ALL, "Rus"); //подключаем русский яхык
	enteringDirectoryPath();
	printf("Выбранный каталог %s\n", directoryPath);
	retrievingInformationAboutFiles(directoryPath);
	//showMenu();
	//selectMenu(numberOfItemsInTheMenu);
	//int selectedMenuItem;
	//void retrievingInformationAboutFiles(hFile);
	/*do {
		showMenu();

		selectedMenuItem = selectMenu(numberOfItemsInTheMenu); // получаем номер выбранного пункта меню

		switch (selectedMenuItem) {
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}

		if (selectedMenuItem != 8)
			system("pause");
	} while (selectedMenuItem != 8); //выход если выбран 8 пункт в меню
	*/
}