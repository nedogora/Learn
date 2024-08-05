#include <iostream>
using namespace std;

//#define FACTORIAL
#define DEGREE

int factorial(int n);
double deg(double n, double d);

void main()
{
	setlocale(LC_ALL, "");

#ifdef FACTORIAL

	int n;
	cout << "¬ведите число: "; cin >> n;
	cout << n << "! = " << factorial(n) << endl;

#endif // FACTORIAL

#ifdef DEGREE

	double n, d;

	cout << "¬ведите число: "; cin >> n;
	cout << "¬ведите степень: "; cin >> d;

	cout << n << " ^ " << d << " = " << deg(n, d) << endl;

#endif // DEGREE

}

int factorial(int n)
{
	int f = 1;
	for (int i = 1; i <= n; i++) f *= i;
	return f;
}

double deg(double n, double d)
{
	if (d == 0) return 1;

	double r = 1;

	if (d < 0)
	{
		n = 1 / n;
		d *= (-1);
	}

	for (int i = 0; i < d; i++) r *= n;

	return r;
}