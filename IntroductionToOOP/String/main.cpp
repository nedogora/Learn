#include <iostream>
#include <string.h>
using namespace std;

#define tab "\t"

class String
{
	char* str;
	int size;

public:
	String(int size = 80)
	{
		this->str = new char[size] {};
		this->size = size;
		cout << "Constructor:" << tab << this << endl;
	}

	String(const char* s)
	{
		this->size = strlen(s);
		this->str = new char[size + 1]{};

		for (int i = 0; i < size; i++) this->str[i] = s[i];
		cout << "Constructor:" << tab << this << endl;
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:" << tab << this << endl;
	}

	////////////////////////////////////////////////////////

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size + 1]{};

		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:" << tab << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << tab << this << endl;
	}

	////////////////////////////////////////////////////////

	char* GetStr()
	{
		return this->str;
	}

	int GetSize()
	{
		return this->size;
	}

	////////////////////////////////////////////////////////

	String& operator=(const String& other)
	{
		this->size = other.size;
		delete[] str;
		this->str = new char[size + 1]{};

		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}

		cout << "CopyAssignment:" << tab << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		
		cout << "MoveAssignment:" << tab << this << endl;
		return *this;
	}

	String operator+(String& other)
	{
		String temp;
		temp.size = this->size + other.size + 1;

		for (int i = 0; i < this->size; i++) temp.str[i] = this->str[i];
		for (int i = this->size; i < temp.size; i++) temp.str[i] = other.str[i - this->size];

		return temp;
	}

	////////////////////////////////////////////////////////

	void Print()
	{
		cout << this->str << endl;
	}
};

ostream& operator<<(ostream& os, /*const*/ String& obj)
{
	for (int i = 0; i < obj.GetSize(); i++) cout << obj.GetStr()[i];
	cout << endl;

	return os;
}

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

}