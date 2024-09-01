#include <iostream>
#include <cmath>
using namespace std;

class Point
{
	double x;
	double y;

public:
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;

		cout << "Constructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	double GetX() const
	{
		return this->x;
	}

	double GetY() const
	{
		return this->y;
	}

	void SetX(double x)
	{
		this->x = x;
	}

	void SetY(double y)
	{
		this->y = y;
	}

	double Distance(const Point& other)
	{
		return (pow((other.x - this->x), 2) + pow((other.y - this->y), 2))*0.5;
	}

};

double Distance(const Point& A, const Point& B)
{
	return (pow((B.GetX() - A.GetX()), 2) + pow((B.GetY() - A.GetY()), 2))*0.5;
}

void main()
{
	setlocale(LC_ALL, "");

	Point A(2, 3);
	Point B(5, 8);

	cout << A.Distance(B)<<endl;
	cout << Distance(A, B) << endl;
}