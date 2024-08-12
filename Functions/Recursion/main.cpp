/*
1. Factorial(); // ���������� ��������� �����
2. Power(); // �������� ����� � �������
3. Fibonacci(); //������� �� ����� ��� ��������� �� ���������� �������
4. Fibonacci(); // ������� �� ����� �������� ���������� ������ �� ���� ���������

��� ������� ������ ���� ����������� �����c����
*/
#include <iostream>
using namespace std;

#define tab '\t'

//#define FACTORIAL
//#define POWER

int Factorial(int n);
double Power(double n, double d);
void Fibonacci(int n, int a = 0, int b = 1);
int Fibonacci(int n, int a = 0, int b = 1);

void main()
{
	setlocale(LC_ALL, "");

#ifdef FACTORIAL
	int n;

	cout << "������� �����: "; cin >> n;
	cout << n << "! = " << Factorial(n) << endl;
#endif // FACTORIAL

#ifdef POWER
	double n, d;

	cout << "������� �������� �������: "; cin >> n;
	cout << "������� ���������� �������: "; cin >> d;
	cout << n << " ^ " << d << " = " << Power(n, d) << endl;
#endif // POWER

	int n;
	cout << "������� �����: "; cin >> n;
	Fibonacci(n);
	cout << endl;
}

int Factorial(int n)
{
	if (n == 0) return 0;
	if (n == 1) return n;
	return n *= Factorial(n - 1);
}

double Power(double n, double d)
{
	if (d == 0) return 1;
	if (d < 0)
	{
		n = 1 / n;
		n *= (-1);
	}
	
	return n * Power(n, d - 1);
}

void Fibonacci(int n, int a, int b)
{
	if (a > n) return;
	cout << a << tab;
	Fibonacci(n, b, a + b);
}

int Fibonacci(int n, int a, int b)
{
	if (n == 0) return 0;
	cout << a << tab;
	Fibonacci(n - 1, b, a + b);
}