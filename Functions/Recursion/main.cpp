#include <iostream>
using namespace std;

#define tab '\t'

int Factorial(int n);	// Факториал числа
double Power(double n, double d);	// Возвденеие числа в степень
void FibonacciTo(int n, int a = 0, int b = 1);	// Выводи на экран ряда Фибоначчи до указанного предела
void Fibonacci(int n, int a = 0, int b = 1);	// Вывод на экран заданного количества членов из ряда Фибоначчи

//#define FACTORIAL
#define POWER
//#define FIBONACCI

void main()
{
	setlocale(LC_ALL, "");

#ifdef FACTORIAL
	int n;

	cout << "Введите число: "; cin >> n;
	cout << n << "! = " << Factorial(n) << endl;
#endif // FACTORIAL

#ifdef POWER
	double n, d;

	cout << "Введите основане степени: "; cin >> n;
	cout << "Введите показатель степени: "; cin >> d;
	cout << n << " ^ " << d << " = " << Power(n, d) << endl;
#endif // POWER

#ifdef FIBONACCI
	int n;
	cout << "Введите максимальное значение: "; cin >> n;
	FibonacciTo(n);
#endif // FIBONACCI

	main();
}

int Factorial(int n)
{
	/*if (n == 0) return 1;
	//if (n == 1) return n;
	return n *= Factorial(n - 1);*/
	return n == 0 ? 1 : n * Factorial(n - 1);
}

double Power(double n, double d)
{
	/*if (d == 0) return 1;
	if (d < 0)
	{
		n = 1 / n;
		d *= (-1);
	}

	return n * Power(n, d - 1);*/
	//cout << n << tab << d << endl;
	return d == 0 ? 1 : (d < 0 ? 1 / n * Power(1 / n, -d - 1) : n * Power(n, d - 1));
}

void FibonacciTo(int n, int a, int b)
{
	if (a > n) return;
	cout << a << tab;
	FibonacciTo(n, b, a + b);
}

void Fibonacci(int n, int a, int b)
{
	if (n == 0) return;
	cout << a << tab;
	Fibonacci(n - 1, b, a + b);
}