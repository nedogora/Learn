#include<iostream>
using namespace std;

#define tab "\t"

#define FILLRAND
#define PRINT
#define SUM
#define AVG
#define MIN
#define MAX
#define SORT
#define SHIFTLEFT
#define SHIFTRIGHT

const int ROWS = 3;
const int COLS = 5;

void FillRand(int arr[], const int n, int min = 0, int max = 100);	//Заполняет массив случайными числами. Обычно массив заполняется случайными числами от 0-100, но при необходимости пользователь может передать пределы генерации случайных чисел
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int min = 0, int max = 100);

void Print(int arr[], const int n);		//Выводит массив на экран
void Print(double arr[], const int n);
void Print(char arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);

int Sum(int arr[], const int n);	//Возвращает сумму э-ов массива
double Sum(double arr[], const int n);
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);

double Avg(int arr[], const int n);		//Возвращает среднее арифметическое
double Avg(int arr[ROWS][COLS], const int ROWS, const int COLS);

int MinValueIn(int arr[], const int n);		//Мin значение
double MinValueIn(double arr[], const int n);
char MinValueIn(char arr[], const int n);
int MinValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);

int MaxValueIn(int arr[], const int n);		//Max значение
double MaxValueIn(double arr[], const int n);
char MaxValueIn(char arr[], const int n);
int MaxValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Sort(int arr[], const int n);	//Сортировка
void Sort(double arr[], const int n);
void Sort(char arr[], const int n);
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS);

void ShiftLeft(int arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов влево
void ShiftLeft(double arr[], const int n, int c);
void ShiftLeft(char arr[], const int n, int c);
void ShiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int c);

void ShiftRight(int arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов вправо
void ShiftRight(double arr[], const int n, int c);
void ShiftRight(char arr[], const int n, int c);
void ShiftRight(int arr[ROWS][COLS], const int ROWS, const int COLS, int c);

//#define ARRAYS_1
#define ARRAYS_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef ARRAYS_1
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

	/*	cout << "\n////////////////////////Sort////////////////////////" << endl;
		Sort(arr, n);
		Print(arr, n);

		Sort(brr, n);
		Print(brr, n);

		Sort(crr, n);
		Print(crr, n);
	*/

	/*	cout << "\n////////////////// Shift Left //////////////////" << endl;
		ShiftLeft(arr, n, 2);
		Print(arr, n);

		ShiftLeft(brr, n, 2);
		Print(brr, n);

		ShiftLeft(crr, n, 2);
		Print(crr, n);

	*/

	/*	cout << "\n////////////////// Shift Right //////////////////" << endl;
		ShiftRight(arr, n, 2);
		Print(arr, n);

		ShiftRight(brr, n, 2);
		Print(brr, n);

		ShiftRight(crr, n, 2);
		Print(crr, n);
	*/

	cout << "\nSum: " << Sum(arr, n) << endl;
	cout << "Avg: " << Avg(arr, n) << endl;
	cout << "Min: " << MinValueIn(arr, n) << endl;
	cout << "Max: " << MaxValueIn(arr, n) << endl;
#endif // ARRAYS_1

	
	int i_arr_2[ROWS][COLS]{};

	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

	cout << "Sum: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Avg: " << Avg(i_arr_2, ROWS, COLS) << endl;
	cout << "Min: " << MinValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Max: " << MaxValueIn(i_arr_2, ROWS, COLS) << endl;

	cout << "\n/////////// Sort ///////////" << endl;
	Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

	cout << "\n/////////// Shift Left ///////////" << endl;
	ShiftLeft(i_arr_2, ROWS, COLS, 2);
	Print(i_arr_2, ROWS, COLS);

	cout << "\n/////////// Shift Right ///////////" << endl;
	ShiftRight(i_arr_2, ROWS, COLS, 2);
	Print(i_arr_2, ROWS, COLS);
}

#ifdef FILLRAND

void FillRand(int arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}

void FillRand(double arr[], const int n, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = double(rand() % (max - min) + min) / 100;
	}
}

void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int min, int max)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (max - min) + min;
		}
	}
}

#endif // FILLRAND

#ifdef PRINT

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

#endif // PRINT

#ifdef SUM

int Sum(int arr[], const int n)
{
	int s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}

double Sum(double arr[], const int n)
{
	double s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}

int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int s = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			s += arr[i][j];
		}
	}

	return s;
}

#endif // SUM

#ifdef AVG

double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

double Avg(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

#endif // AVG


#ifdef MIN

int MinValueIn(int arr[], const int n)
{
	int min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

double MinValueIn(double arr[], const int n)
{
	double min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

char MinValueIn(char arr[], const int n)
{
	char min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

int MinValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[0][0];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
		}
	}

	return min;
}

#endif // MIN

#ifdef MAX

int MaxValueIn(int arr[], const int n)
{
	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

double MaxValueIn(double arr[], const int n)
{
	double max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}
char MaxValueIn(char arr[], const int n)
{
	char max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

int MaxValueIn(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = arr[0][0];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
	}

	return max;
}

#endif // MAX

#ifdef SORT

void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}

void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}
void Sort(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}

void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					int temp;
					if (arr[k][l] < arr[i][j])
					{
						temp = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = temp;
					}
				}
			}
		}
	}
}

#endif // SORT

#ifdef SHIFTLEFT

void ShiftLeft(int arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

void ShiftLeft(double arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

void ShiftLeft(char arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

void ShiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int c)
{
	for (int r = 0; r < ROWS; r++)
	{
		/*for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < COLS - 1; j++)
			{
				int temp = arr[r][j];
				arr[r][j] = arr[r][j + 1];
				arr[r][j + 1] = temp;
			}
		}*/
		ShiftLeft(arr[r], COLS, c);
	}
}

#endif // SHIFTLEFT

#ifdef SHIFTRIGHT

void ShiftRight(int arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

void ShiftRight(double arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

void ShiftRight(char arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

void ShiftRight(int arr[ROWS][COLS], const int ROWS, const int COLS, int c)
{
	ShiftLeft(arr, ROWS, COLS, COLS - c);
}

#endif // SHIFTRIGHT