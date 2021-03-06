/*************************************************************************************************
*                                                                                                *
*                          ИНФОРМАТИКА И ВЫЧИСЛИТЕЛЬНАЯ ТЕХНИКА                                  *
*                                                                                                *
**************************************************************************************************
*    Prodgect type: ConsoleApplication                                                           *
*    Progect name:  Laba3                                                                        *
*    File name:     Laba3.sln                                                                    *
*    Language:      Cpp, MSVS 2017                                                               *
*    Programmes:    М3О-107Б-18                                                                  *
*                   Гордеев Никита                                                               *
*                   Топунова Алёна                                                               *
*    Modified by:   31.10.2018                                                                   *
*    Created:       14.11.2018                                                                   *
*    Comment:       Лабораторная работа №3                                                       *
*************************************************************************************************/
#include "pch.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
//файл в ресурсах или в исходном коде проекта
//                               НЕКОРЕКТНЫЕ ТЕСТЫ
//const char *FNAME = "Text File  found.txt";    //проверка существования файла		1
//const char *FNAME = "Text2.txt";				 //файл пуст						2
//const char *FNAME = "Text8.txt";				 //в файле не число					3
//const char *FNAME = "Text6.txt";				 //проверка привышения NMAX			4
//const char *FNAME = "Text9.txt";				 //неправильный ввод N				5
//const char *FNAME = "Text01.txt";				 //N = 0 (введённое пользователем)  5
//const char *FNAME = "Text0.txt";				 //N < 0 (введённое пользователем)	5
//const char *FNAME = "Text02.txt";				 //проверка существования вектора	2
//                               ТЕСТЫ РАБОТЫ ТАБЛИЦИ
//const char *FNAME = "Text0-1.txt";		  	 //проветка 1 элемент и он =-1
//const char *FNAME = "Text5.txt";               //проверка расширяемости таблици
//                               ТЕСТЫ ОСНОВНОЙ ЗАДАЧИ
//const char *FNAME = "Text3.txt";				 //1 элемент минимальный
//const char *FNAME = "Text10.txt";				 //рядовой случий
//const char *FNAME = "Text11.txt";				 //отрицательные результаты
const char *FNAME = "Text7.txt";				 //текуше решение

const int   NMAX = 10;						     //максимальный размер массива
int main(){
	int		N;									 //число элементов в массиве
	int		AVec[NMAX];							 //объявление массива
	int		i;									 //индексная переменная
	int		i1;									 //разряд текущего элемента
	int		Prod = 1;						     //результат умножения
	int		min;								 //минимальный элемент по модулю
	int		n=0;					 	         //индекс мин элемента
	double  SrSum=0;					         //среднее арифмитическое
	int		f;								     //вспомогательная переменная
	int		MAXP = 0;							 //порядок самого большого числа + 4

	/*------------------------------РАБОТА С ФАЙЛОМ-------------------------*/

	//объявление файловой переменной и открытие файла для чтения
	ifstream fin(FNAME);
	
	if (!fin)				   	   //файл не найден
	{
		cout << "File " << FNAME << " not found\n";
		fin.close();               //закрыть файл
		return 1;                  //выход по ошибке
	} // end if

	fin >> N;					   //чтение числа элементов массива из файла

	if (fin.eof()) 				   //файл пуст
	{
		cout << "File " << FNAME << " empty\n";
		fin.close();               //закрыть файл
		return 2;                  //выход по ошибке
	} // end if

	i = 0;						   //индекс элемента массива

	while (!fin.eof())             //заполнение массива
	{
		if (i < NMAX)			   //не вышли за граници массива
		{

			if (fin.fail())		   //в файле не число
			{
				cout << "ОШИБКА! Не удалось прочитать файл " << FNAME << endl;
				fin.close();       //закрыть файл
				return 3;          //выход по ошибке
			} // end if

			fin >> AVec[i];		   //чтение элемента массива
			i++;				   //переход к следующему элементу массива
		} // end if
		else					   //привышения NMAX
		{
			cout << "ОШИБКА! Количество элементов в файле" << FNAME
				 << " превышает максимально допустимое" << endl;
			fin.close();           //закрыть файл
			return 4;              //выход по ошибке
		} // end else
	} // end while

	if (i != N)					   //проверка коректнсти ввода N
	{
		cout << "\n\n\nЗначение N не совпадает с количеством введенных элементов !!!\n\n\n";
		fin.close();               //закрыть файл
		return 5;                  //выход по ошибке
	} // end if

	/*-------------------------------РЕШЕНИЕ ОСНОВНОЙ ЗАДАЧИ---------------------------*/

	for ( i = 0; i < N; i++)	   //поиск произведения нечотных элементов вектора
	{
		if(abs(AVec[i]%2)==1)
		Prod = Prod * AVec[i];
	} // end for

	//поиск индекса минимального элемента
	min = abs(AVec[0]);			   //1 элемент минимальный
	for (i = 0; i < N; i++)	  	   //поиск минимального элемента
	{
		if (abs(AVec[i]) < min)
		{
			min = abs(AVec[i]);			   //минимальный элемент
			n = i;				   //индекса минимального элемента
		} // end if
	} // end for

	for (i = 0; i <n; i++)		   // поиск cреднего арифмитического
	{
		SrSum = SrSum + AVec[i];   //сумма
	} // end for
	SrSum = SrSum / n;			   //cреднее арифмитическое

	//обьяснение значений переменных
	cout << "Exp1- The result of multiplying the nechotnyh elements of the vector" << endl;
	cout << "SrSum- The arithmetic mean of the elements located to the minimum modulo element"<<endl;

/*--------------------------------ОФОРМЛЕНИЕ ТАБЛИЦИ-------------------------------------------*/

	for (i = 0; i < N; i++)		   //поиск максимального разряда числа
	{
		int i1 = 0;
		//модуль текушего элемента
		f = abs(AVec[i]);
		while (f > 0)			   //нахождение разряда текущего элемента
		{
			f = f / 10;
			i1++;
		} // end while
		if (i1 > MAXP) MAXP = i1;  //максимальный разряд числа
	} // end for
	MAXP = MAXP + 4;			   //длинна строчки вектора

	//шапка
	cout << char(218);
	cout << setfill(char(196)) << setw(8) << char(194);
	for (i = 0; i < N; i++)
	{
		cout << setfill(char(196)) << setw(MAXP);
		if (i != N-1 ) cout << char(194); else cout << char(191) << endl;
	} // end for

	//1 строка 1 столбец
	cout << char(179) << "AVec=" << setfill(char(32)) << setw(2) << " ";

	//заполнение 1 строки 
	for (i = 0; i < N; i++)
	{
		cout << char(179) << setfill(char(32)) << setw(MAXP-2) << AVec[i] << " ";
	} // end for
	cout << char(179) << endl;

	//отчерк
	cout << char(195) << setfill(char(196)) << setw(8) << char(197);
	for (i = 0; i < N; i++)
	{
		cout << setfill(char(196)) << setw(MAXP);
		if (i != N-1 ) cout << char(193); else cout << char(180) << endl;
	} // end for

	//заполнение Prod
	cout << char(179) << "Exp1=" << setfill(char(32)) << setw(2) << " "
		 << char(179) << setfill(char(32)) << setw(N*MAXP - 2) << Prod << " " << char(179) <<endl;

	//отчерк
	cout << char(195) << setfill(char(196)) << setw(8) << char(197);
	for (i = 0; i < N*MAXP -1; i++)
	{
		cout << char(196);
	} // end for
	cout << char(180) << endl;

	//заполнение SrSum
	if(n!=0)					   //SrSum существует
	{
		cout << char(179) << "SrSum=" << setfill(char(32)) << setw(1) << " "
			 << char(179) << setfill(char(32)) << setw(N*MAXP - 2) << SrSum << " " << char(179) << endl;
	} // end if
	else		 			       //SrSum не существует
	{
		cout << char(179) << "SrSum=" << setfill(char(32)) << setw(1) << " "
			 << char(179) << setfill(char(32)) << setw(N*MAXP - 1) << "- " << char(179) << endl;
	} // end else

	//конец таблици
	cout << char(192);
	cout << setfill(char(196)) << setw(8);
	cout << char(193);
	for (i = 0; i < N* MAXP - 1; i++)
	{
		cout << char(196);
	} // end for
	cout << char(217) << endl;

	system("PAUSE");
	return 0;
}