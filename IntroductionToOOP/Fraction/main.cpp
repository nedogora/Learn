#include <iostream>
using namespace std;

#define delimiter cout << "\n=================================================================\n"
#define tab '\t'



class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	Fraction(int numerator = 0, int denominator = 1)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;

		cout << "Constructor:" << tab << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;

		cout << "Constructor:" << tab << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:" << tab << this << endl;
	}

	////////////////////////////////////////////////////////

	int GetI() const
	{
		return this->integer;
	}

	int GetN() const
	{
		return this->numerator;
	}

	int GetD() const
	{
		return this->denominator;
	}

	void SetI(int integer)
	{
		this->integer = integer;
	}

	void SetN(int numerator)
	{
		this->numerator = numerator;
	}

	void SetD(int denominator)
	{
		this->denominator = denominator;
	}

	////////////////////////////////////////////////////////

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;

		cout << "CopyConsrtyctor:" << tab << this << endl;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;

		cout << "CopyAssignment:" << tab << this << endl;
		return *this;
	}

	////////////////////////////////////////////////////////

	void Reduce()	//Сокращение дроби
	{
		int n = this->numerator;
		int d = this->denominator;

		while (n != 0 && d != 0)
		{
			if (n > d) n %= d;
			else d %= n;
		}
		n += d;

		this->numerator /= n;
		this->denominator /= n;
	}

	void ToProper()		//Перевод в правильную дробь
	{
		Reduce();
		if (numerator > denominator)
		{
			integer += numerator / denominator;
			numerator %= denominator;
		}
		else if (numerator == denominator)
		{
			integer = 1;
			numerator = 0;
		}
	}

	void ToImproper()	//Перевод в неправильную дробь
	{
		if (integer > 0)
		{
			numerator += denominator * integer;
			integer = 0;
		}
	}

	////////////////////////////////////////////////////////

	Fraction operator+(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator +" << tab << this << endl;
		return Temp;
	}

	Fraction operator-(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator -" << tab << this << endl;
		return Temp;
	}

	Fraction operator*(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = this->numerator * other.numerator;
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator *" << tab << this << endl;
		return Temp;
	}

	Fraction operator/(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = this->numerator * other.denominator;
		Temp.denominator = this->denominator * other.numerator;
		Temp.Reduce();

		cout << "Operator /" << tab << this << endl;
		return Temp;
	}

	////////////////////////////////////////////////////////

	void Print()
	{
		if (integer == 0) cout << numerator << "/" << denominator;
		else if (numerator == 0) cout << integer;
		else cout << integer << "(" << numerator << "/" << denominator << ")";
		cout << endl;
	}
};

//#define FIRST
//#define ARITHMETIC

void main()
{
	setlocale(LC_ALL, "");

#ifdef FIRST
	Fraction A(2, 4);
	A.Print();
	A.Reduce();
	A.Print();

	Fraction B(2, 9, 5);
	B.Print();
	B.ToProper();
	B.Print();

	Fraction C = A;
	C.Print();

	C = B;
	C.Print();
	C.ToImproper();
	C.Print();
#endif // FIRST

#ifdef ARITHMETIC
	Fraction A(1, 1, 3);
	A.Print();
	A.ToImproper();
	A.Print();
	delimiter;

	Fraction B(3, 4);
	B.Print();
	delimiter;

	Fraction C = A + B;
	C.Print();
	C.ToProper();
	C.Print();
	delimiter;

	Fraction D = A - B;
	D.Print();
	delimiter;

	Fraction E = A * B;
	E.Print();
	E.ToProper();
	E.Print();
	delimiter;

	Fraction F = A / B;
	F.Print();
	F.ToProper();
	F.Print();
	delimiter;
#endif // ARITHMETIC

	double a = 2;
	Fraction A;		//Default Constructor
	A.Print();
}