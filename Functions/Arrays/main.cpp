#include "FillRand.h"
#include "Print.h"
#include "Print.cpp"
#include "Sum.h"
#include "Sum.cpp"
#include "Avg.h"
#include "Avg.cpp"
#include "MinValueIn.h"
#include "MinValueIn.cpp"
#include "MaxValueIn.h"
#include "MaxValueIn.cpp"
#include "Sort.h"
#include "Sort.cpp"
#include "ShiftLeft.h"
#include "ShiftLeft.cpp"
#include "ShiftRight.h"
#include "ShiftRight.cpp"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	char arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	//cout << "\nShift Left:" << endl;
	//ShiftLeft(arr, n, 5);

	//Print(arr, n);

	cout << "\nShift Right:" << endl;
	ShiftRight(arr, n, 2);

	Print(arr, n);

	cout << "\nSum: " << Sum(arr, n) << endl;
	cout << "Avg: " << Avg(arr, n) << endl;
	cout << "Min: " << MinValueIn(arr, n) << endl;
	cout << "Max: " << MaxValueIn(arr, n) << endl;

	int i_arr_2[ROWS][COLS];

	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

	cout << "\nSum: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Avg: " << Avg(i_arr_2, ROWS, COLS) << endl;
	cout << "Min: " << MinValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Max: " << MaxValueIn(i_arr_2, ROWS, COLS) << endl;

	ShiftLeft(i_arr_2, ROWS, COLS, 2);
	Print(i_arr_2, ROWS, COLS);

	ShiftRight(i_arr_2, ROWS, COLS, 2);
	Print(i_arr_2, ROWS, COLS);
}