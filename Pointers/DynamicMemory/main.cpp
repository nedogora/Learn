#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'

void FillRand(int Arr[], const int n);
void FillRand(int** Arr, const int rows, const int cols, int min = 0, int max = 100);

void Print(int Arr[], const int n);
void Print(int** Arr, const int rows, const int cols);

int* Push_back(int* Arr, int &n, int number);	// Добавление элемента в конец массива
int* Push_front(int* Arr, int &n, int number);	// Добавление элемента в начало массива
int* Insert(int* Arr, int &n, int number, int index);	// Добавление элемента по индексу

int** Push_row_back(int** Arr, int& rows, const int cols);	// Добавление строки в конец массива
int** Push_row_front(int** Arr, int& rows, const int cols);	// Добавление строки в начало массива
int** Insert_row(int** Arr, int& rows, const int cols, int index);	// Добавление строки по индексу

void Push_col_back(int** Arr, const int rows, int& cols);	// Добавление столбца в конец массива
void Push_col_front(int** Arr, const int rows, int& cols);	// Добавление столбца в начало массива
void Insert_col(int** Arr, const int rows, int& cols, int index);	// Добавление столбца по индексу

int* Pop_back(int* Arr, int &n);	// Удаление последнего элемента массива
int* Pop_front(int* Arr, int &n);	// Удаление первого элемента массива
int* Erase(int* Arr, int &n, int index);	// Удаление элемента по индексу

int** Pop_row_back(int** Arr, int& rows, const int cols);	// Удаление последней строки массива
int** Pop_row_front(int** Arr, int& rows, const int cols);	// Удаление первой строки массива
int** Erase_row(int** Arr, int& rows, const int cols, int index);	// Удаление строки по индексу

void Pop_col_back(int** Arr, const int rows, int& cols);	// Удаление последнего столбца массива
void Pop_col_front(int** Arr, const int rows, int& cols);	// Удаление первого столбца массива
void Erase_col(int** Arr, const int rows, int& cols, int index);	// Удаление столбца по индексу

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
#define DYNAMIC_MEMORY_3

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* Arr = new int[n];

	FillRand(Arr, n);
	Print(Arr, n);

	Arr = Push_back(Arr, n, 10);
	Print(Arr, n);

	Arr = Push_front(Arr, n, 0);
	Print(Arr, n);

	Arr = Insert(Arr, n, 111, 3);
	Print(Arr, n);

	Arr = Pop_back(Arr, n);
	Print(Arr, n);

	Arr = Pop_front(Arr, n);
	Print(Arr, n);

	Arr = Erase(Arr, n, 3);
	Print(Arr, n);

	delete[] Arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** Arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new int[cols] {};
	}

	FillRand(Arr, rows, cols, 200, 300);
	Print(Arr, rows, cols);

	cout << "\n------- Push Back -------" << endl;
	Arr = Push_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Front -------" << endl;
	Arr = Push_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert -------" << endl;
	Arr = Insert_row(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Back -------" << endl;
	Arr = Pop_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Front -------" << endl;
	Arr = Pop_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase -------" << endl;
	Arr = Erase_row(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
#endif // DYNAMIC_MEMORY_2


	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** Arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new int[cols] {};
	}

	FillRand(Arr, rows, cols, 200, 300);
	Print(Arr, rows, cols);

	cout << "\n------- Push Back -------" << endl;
	Push_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Front -------" << endl;
	Push_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert -------" << endl;
	Insert_col(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Back -------" << endl;
	Pop_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Front -------" << endl;
	Pop_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase -------" << endl;
	Erase_col(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}

void FillRand(int Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void FillRand(int** Arr, const int rows, const int cols, int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = rand() % (max - min) + min;
		}
	}
}

void Print(int Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << '\t';
	}
	cout << endl;
}

void Print(int** Arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
}

int* Push_back(int* Arr, int &n, int number)
{
	int* new_Arr = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		new_Arr[i] = Arr[i];
	}

	new_Arr[n] = number;
	n++;

	delete[] Arr;
	return new_Arr;
}

int* Push_front(int* Arr, int &n, int number)
{
	int* new_Arr = new int[n + 1];

	new_Arr[0] = number;
	for (int i = 0; i < n; i++)
	{
		new_Arr[i + 1] = Arr[i];
	}

	n++;
	delete[] Arr;
	return new_Arr;
}

int* Insert(int* Arr, int &n, int number, int index)
{
	if (index > n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int* new_Arr = new int[n + 1];

	/*for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	new_Arr[index] = number;
	for (int i = index; i < n; i++) new_Arr[i + 1] = Arr[i];*/
	for (int i = 0; i < n; i++)
	{
		//(i < index ? new_Arr[i] : new_Arr[i + 1]) = Arr[i];
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = number;

	n++;
	delete[] Arr;
	return new_Arr;
}


int** Push_row_back(int** Arr, int& rows, const int cols)
{
	int** new_Arr = new int*[rows + 1];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i];
	new_Arr[rows] = new int[cols] {};

	rows++;
	delete[] Arr;
	return new_Arr;
}

int** Push_row_front(int** Arr, int& rows, const int cols)
{
	int** new_Arr = new int*[rows + 1];

	new_Arr[0] = new int[cols] {};
	for (int i = 0; i < rows; i++) new_Arr[i + 1] = Arr[i];

	rows++;
	delete[] Arr;
	return new_Arr;
}

int** Insert_row(int** Arr, int& rows, const int cols, int index)
{
	if (index > rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int** new_Arr = new int*[rows + 1];

	for (int i = 0; i < rows; i++)
	{
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = new int[cols] {};

	rows++;
	delete[] Arr;
	return new_Arr;
}


void Push_col_back(int** Arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)	Buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;
}

void Push_col_front(int** Arr, const int rows, int& cols)
{
	/*int** new_Arr = new int*[rows];


	for (int i = 0; i < rows; i++)
	{
		new_Arr[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++) new_Arr[i][j + 1] = Arr[i][j];
		delete[] Arr[i];
	}

	cols++;
	delete[] Arr;
	return new_Arr;*/

	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++) Buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;
}

void Insert_col(int** Arr, const int rows, int& cols, int index)
{
	if (index > cols)
	{
		cout << "Выход за пределы массива" << endl;
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++) Buffer[j] = Arr[i][j];
		for (int j = index; j < cols; j++) Buffer[j + 1] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;

	/*int** new_Arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		new_Arr[i] = new int[cols + 1];
		for (int j = 0; j < cols; j++) new_Arr[i][j < index ? j : j + 1] = Arr[i][j];
		new_Arr[i][index] = 0;
		delete[] Arr[i];
	}

	cols++;
	delete[] Arr;
	return new_Arr;*/
}


int* Pop_back(int* Arr, int &n)
{
	int* new_Arr = new int[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;
}

int* Pop_front(int* Arr, int &n)
{
	int* new_Arr = new int[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}

int* Erase(int* Arr, int &n, int index)
{
	if (index >= n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int* new_Arr = new int[--n];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < n; i++)new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}

int** Pop_row_back(int** Arr, int& rows, const int cols)
{
	delete[] Arr[rows - 1];
	int** new_Arr = new int*[--rows];

	for (int i = 0; i < rows-1; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;
}

int** Pop_row_front(int** Arr, int& rows, const int cols)
{
	delete[] Arr[0];
	int** new_Arr = new int*[--rows];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}

int** Erase_row(int** Arr, int& rows, const int cols, int index)
{
	if (index >= rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int** new_Arr = new int*[--rows];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}


void Pop_col_back(int** Arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}

void Pop_col_front(int** Arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j + 1];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}

void Erase_col(int** Arr, const int rows, int& cols, int index)
{
	if (index >= cols)
	{
		cout << "Выход за пределы массива" << endl;
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		int* Buffer = new int[cols - 1];
		for (int j = 0; j < index; j++) Buffer[j] = Arr[i][j];
		for (int j = index; j < cols; j++) Buffer[j] = Arr[i][j + 1];
		delete[]  Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}