#include "stdafx.h"
#include "WorkWithMemory.cpp"
#include "FillRand.h"
#include "Print.cpp"
#include "Add.cpp"
#include "Delete.cpp"

using std::cin;
using std::cout;
using std::endl;

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_3

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* Arr = Allocate<int>(n);

	FillRand(Arr, n);
	Print(Arr, n);

	Arr = Push_back(Arr, n, 111);
	Print(Arr, n);

	Arr = Push_front(Arr, n, 111);
	Print(Arr, n);

	Arr = Insert(Arr, n, 111, 3);
	Print(Arr, n);

	Arr = Pop_back(Arr, n);
	Print(Arr, n);

	Arr = Pop_front(Arr, n);
	Print(Arr, n);

	Arr = Erase(Arr, n, 2);
	Print(Arr, n);

	Clear(Arr);
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** Arr = Allocate<int>(rows, cols);

	FillRand(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Row Back -------" << endl;
	Arr = Push_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Row Front -------" << endl;
	Arr = Push_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert Row -------" << endl;
	Arr = Insert_row(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Row Back -------" << endl;
	Arr = Pop_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Row Front -------" << endl;
	Arr = Pop_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase Row -------" << endl;
	Arr = Erase_row(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	Clear(Arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** Arr = Allocate<int>(rows, cols);

	FillRand(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Col Back -------" << endl;
	Push_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Col Front -------" << endl;
	Push_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert Col -------" << endl;
	Insert_col(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Col Back -------" << endl;
	Pop_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Col Front -------" << endl;
	Pop_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase Col -------" << endl;
	Erase_col(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	Clear(Arr, rows);
#endif // DYNAMIC_MEMORY_3
}