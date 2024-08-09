#include "FillRand.h"
#include "Print.h"
#include "Sort.h"
#include "Shift.h"
#include "Statistics.h"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double brr[n];
	char crr[n];

	FillRand(arr, n);
	Print(arr, n);

	FillRand(brr, n);
	Print(brr, n);
	
	FillRand(crr, n);
	Print(crr, n);

	/*cout << "\n////////////////////////Sort////////////////////////" << endl;
	Sort(arr, n);
	Print(arr, n);*/

	/*cout << "\n////////////////// Shift Left //////////////////" << endl;
	ShiftLeft(arr, n, 2);
	Print(arr, n);

	ShiftLeft(brr, n, 2);
	Print(brr, n);

	ShiftLeft(crr, n, 2);
	Print(crr, n);*/

	/*cout << "\n////////////////// Shift Right //////////////////" << endl;
	ShiftRight(arr, n, 2);
	Print(arr, n);

	ShiftRight(brr, n, 2);
	Print(brr, n);

	ShiftRight(crr, n, 2);
	Print(crr, n);*/


	cout << "\nSum: " << Sum(arr, n) << endl;
	cout << "Avg: " << Avg(arr, n) << endl;
	cout << "Min: " << MinValueIn(arr, n) << endl;
	cout << "Max: " << MaxValueIn(arr, n) << endl;
}