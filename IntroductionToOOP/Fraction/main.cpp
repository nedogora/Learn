#include <iostream>
using namespace std;

#define delimiter cout << "\n=================================================================\n"
#define tab '\t'

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;

		cout << "Default Constructor:" << tab << this << endl;
	}

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;

		cout << "Constructor:" << tab << this << endl;
	}

	Fraction(double number)
	{
		this->integer = (int)number;
		number -= this->integer;
		this->numerator = number * 100;
		this->denominator = 100;
		this->Reduce();

		cout << "Constructor:" << tab << this << endl;
	}

	Fraction(int numerator, int denominator)
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

	Fraction& Reduce()	//Сокращение дроби
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

		return *this;
	}

	Fraction& ToProper()		//Перевод в правильную дробь
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

		return *this;
	}

	Fraction& ToImproper()	//Перевод в неправильную дробь
	{
		if (integer > 0)
		{
			numerator += denominator * integer;
			integer = 0;
		}
		return *this;
	}

	Fraction Inverted()
	{
		Fraction inverted = *this;
		inverted.ToImproper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	////////////////////////////////////////////////////////

	/*Fraction operator+(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator +" << tab << this << endl;
		return Temp;
	}*/

	/*Fraction operator-(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator -" << tab << this << endl;
		return Temp;
	}*/

	/*Fraction operator*(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = this->numerator * other.numerator;
		Temp.denominator = this->denominator * other.denominator;
		Temp.Reduce();

		cout << "Operator *" << tab << this << endl;
		return Temp;
	}*/

	/*Fraction operator/(Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		Fraction Temp;
		Temp.numerator = this->numerator * other.denominator;
		Temp.denominator = this->denominator * other.numerator;
		Temp.Reduce();

		cout << "Operator /" << tab << this << endl;
		return Temp;
	}*/

	////////////////////////////////////////////////////////

	Fraction& operator+=(Fraction other)
	{
		/*this->ToImproper();
		other.ToImproper();

		this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;
		this->ToProper();
		this->Reduce();

		cout << "Operator +=" << tab << this << endl;
		return *this;*/

		cout << "Operator +=" << endl;
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction other)
	{
		/*this->ToImproper();
		other.ToImproper();

		this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;
		this->ToProper();
		this->Reduce();

		cout << "Operator -=" << tab << this << endl;
		return *this;*/

		cout << "Operator -=" << endl;
		return *this = *this - other;
	}

	Fraction& operator*=(const Fraction& other)
	{
		/*this->ToImproper();
		other.ToImproper();

		this->numerator = this->numerator * other.numerator;
		this->denominator = this->denominator * other.denominator;
		this->ToProper();
		this->Reduce();

		cout << "Operator *=" << tab << this << endl;
		return *this;*/

		cout << "Operator *=" << endl;
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction other)
	{
		/*this->ToImproper();
		other.ToImproper();

		this->numerator = this->numerator * other.denominator;
		this->denominator = this->denominator * other.numerator;
		this->ToProper();
		this->Reduce();

		cout << "Operator /=" << tab << this << endl;
		return *this;*/

		cout << "Operator /=" << endl;
		return *this = *this / other;
	}

	////////////////////////////////////////////////////////

	Fraction& operator++()
	{
		this->integer++;
		cout << "Operator ++" << tab << this << endl;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		this->integer++;
		cout << "Operator ++" << tab << this << endl;
		return old;
	}


	Fraction& operator--()
	{
		this->integer--;
		cout << "Operator --" << tab << this << endl;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction old = *this;
		this->integer--;
		cout << "Operator --" << tab << this << endl;
		return old;
	}

	////////////////////////////////////////////////////////

	/*explicit*/ operator int()
	{
		return this->integer;
	}

	/*explicit*/ operator double()
	{
		double value = this->integer + (double)this->numerator / this->denominator;
		return value;
	}


	////////////////////////////////////////////////////////

	void Print()
	{
		/*if (integer == 0) cout << numerator << "/" << denominator << endl;
		else if (numerator == 0) cout << integer;
		else cout << integer << "(" << numerator << "/" << denominator << ")";
		cout << endl;*/

		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		//else cout << integer << "(" << numerator << "/" << denominator << ")";
		cout << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	/*Fraction Temp;
	Temp.SetN(left.GetN() * right.GetD() + right.GetN() * left.GetD());
	Temp.SetD(left.GetD() * right.GetD());
	Temp.Reduce();
	Temp.ToProper();

	return Temp;*/

	cout << "Operator +" << endl;

	return Fraction
	(
		left.GetN() * right.GetD() + right.GetN() * left.GetD(),
		left.GetD() * right.GetD()
	).ToProper().Reduce();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	/*Fraction Temp;
	Temp.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
	Temp.denominator = this->denominator * other.denominator;
	Temp.Reduce();

	cout << "Operator -" << tab << this << endl;
	return Temp;*/

	cout << "Operator -" << endl;

	return Fraction
	(
		left.GetN() * right.GetD() - right.GetN() * left.GetD(),
		left.GetD() * right.GetD()
	).ToProper().Reduce();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	cout << "Operator *" << endl;

	return Fraction
	(
		left.GetN() * right.GetN(),
		left.GetD() * right.GetD()
	).ToProper().Reduce();
}

Fraction operator/(Fraction left, Fraction right)
{
	/*left.ToImproper();
	right.ToImproper();

	cout << "Operator /" << endl;

	return Fraction
	(
		left.GetN() * right.GetD(),
		left.GetD() * right.GetN()
	).ToProper().Reduce();*/

	cout << "Operator /" << endl;
	return left * right.Inverted();
}

////////////////////////////////////////////////////////

bool operator==(Fraction left, Fraction right)
{
	left.ToImproper().Reduce();
	right.ToImproper().Reduce();

	cout << "Operator ==" << endl;

	return (left.GetN() == right.GetN() && left.GetD() == right.GetD());
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	/*left.ToImproper();
	right.ToImproper();

	cout << "Operator !=" << endl;

	return !(left.GetN() == right.GetN() && left.GetD() == right.GetD());*/

	cout << "Operator !=" << endl;
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	left.SetN(left.GetN() * right.GetD());
	right.SetN(right.GetN() * left.GetD());
	left.SetD(left.GetD() * right.GetD());
	right.SetD(right.GetD() * left.GetD());

	cout << "Operator >" << endl;

	return (left.GetN() > right.GetN());
}

bool operator<(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	left.SetN(left.GetN() * right.GetD());
	right.SetN(right.GetN() * left.GetD());
	left.SetD(left.GetD() * right.GetD());
	right.SetD(right.GetD() * left.GetD());

	cout << "Operator <" << endl;

	return (left.GetN() < right.GetN());
}

bool operator>=(Fraction left, Fraction right)
{
	/*left.ToImproper();
	right.ToImproper();

	left.SetN(left.GetN() * right.GetD());
	right.SetN(right.GetN() * left.GetD());
	left.SetD(left.GetD() * right.GetD());
	right.SetD(right.GetD() * left.GetD());

	cout << "Operator >=" << endl;

	return (left.GetN() >= right.GetN());*/

	cout << "Operator >=" << endl;
	return !(left < right);
}

bool operator<=(Fraction left, Fraction right)
{
	/*left.ToImproper();
	right.ToImproper();

	left.SetN(left.GetN() * right.GetD());
	right.SetN(right.GetN() * left.GetD());
	left.SetD(left.GetD() * right.GetD());
	right.SetD(right.GetD() * left.GetD());

	cout << "Operator <=" << endl;

	return (left.GetN() <= right.GetN());*/

	cout << "Operator <=" << endl;
	return !(left > right);
}

////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const Fraction& obj)
{
	/*if (obj.GetI() == 0)
		cout << obj.GetN() << "/" << obj.GetD();
	else if (obj.GetN() == 0)
		cout << obj.GetI();
	else
		cout << obj.GetI() << "(" << obj.GetN() << "/" << obj.GetD() << ")";*/

	if (obj.GetI()) cout << obj.GetI();
	if (obj.GetN())
	{
		if (obj.GetI()) cout << "(";
		cout << obj.GetN() << "/" << obj.GetD();
		if (obj.GetI()) cout << ")";
	}
	else if (obj.GetI() == 0) cout << 0;
	//cout << endl;
	
	return os;
}

istream& operator>> (istream& is, Fraction& obj)
{
	int i, n, d;
	cout << "Integer: ";
	is >> i;
	cout << "Numerator: ";
	is >> n;
	cout << "Denominator: ";
	is >> d;

	obj.SetI(i);
	obj.SetN(n);
	obj.SetD(d);
	return is;
}

//#define FIRST
//#define ARITHMETIC
//#define CONSTRUCTORS_CHECK
//#define COMPARISON
//#define COMPOUND_ASSIGNMENTS
//#define INCREMENT_DECREMENT
//#define STREAM_OPERATORS
#define CONVERSIONS_1
//#define CONVERSIONS_2

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
	Fraction A(2, 3, 4);
	A.Print();
	delimiter;

	Fraction B(3, 4, 5);
	B.Print();
	delimiter;

	Fraction C = A + B;
	C.Print();
	delimiter;

	Fraction D = B - A;
	D.Print();
	delimiter;

	Fraction E = A * B;
	E.Print();
	delimiter;

	Fraction F = A / B;
	F.Print();
	delimiter;
#endif // ARITHMETIC

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default Constructor
	A.Print();

	Fraction B = 3;	//Single argument constructor
	B.Print();

	Fraction C(1, 2);
	C.Print();

	Fraction D(2, 3, 4);
	D.Print();
#endif // CONSTRUCTORS_CHECK

#ifdef COMPARISON
	Fraction A(1, 2);
	Fraction B(5, 10);

	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 10)) << endl;
	cout << (A <= B) << endl;
#endif // COMPARISON

#ifdef COMPOUND_ASSIGNMENTS
	Fraction A(4, 3);
	Fraction B(3, 4);

	A += B;
	A.Print();
	delimiter;

	A -= B;
	A.Print();
	delimiter;

	A *= B;
	A.Print();
	delimiter;

	A /= B;
	A.Print();
#endif // COMPOUND_ASSIGNMENTS

#ifdef INCREMENT_DECREMENT
	Fraction A(3, 4);
	++A;
	A.Print();
	delimiter;

	--A;
	A.Print();
#endif // INCREMENT_DECREMENT

#ifdef STREAM_OPERATORS
	Fraction A(2, 3, 4);
	cout << A << endl;
	cin >> A;
	cout << A << endl;
#endif // STREAM_OPERATORS

#ifdef CONVERSIONS_1
	Fraction A = 2.75;
	cout << A << endl;
#endif // CONVERSIONS_1

#ifdef CONVERSIONS_2
	Fraction A(2, 3, 4);
	int a = A;
	cout << a << endl;

	double b = double(A);
	cout << b << endl;

	
#endif // CONVERSIONS_2

}