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
		this->size = strlen(s)+1;
		this->str = new char[size]{};

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
		this->str = new char[size]{};

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

	const char* GetStr() const
	{
		return this->str;
	}
	
	char* GetStr() 
	{
		return this->str;
	}

	int GetSize() const
	{
		return this->size;
	}

	////////////////////////////////////////////////////////

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		this->size = other.size;
		delete[] str;
		this->str = new char[size]{};

		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}

		cout << "CopyAssignment:" << tab << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		if (this == &other) return *this;
		delete[] str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		
		cout << "MoveAssignment:" << tab << this << endl;
		return *this;
	}

	/*String operator+(String& other)
	{
		String temp = this->size + other.size + 1;

		for (int i = 0; i < this->size; i++) temp.str[i] = this->str[i];
		for (int i = this->size; i < temp.size; i++) temp.str[i] = other.str[i - this->size];

		return temp;
	}*/

	char operator[](int index) const
	{
		if (index < 0 || index>this->size)throw std::exception("out of range in const[]");
		return this->str[index];
	}

	char& operator[](int index) 
	{
		if (index < 0 || index>this->size)throw std::exception("out of range in []");
		return this->str[index];
	}

	////////////////////////////////////////////////////////

	void Print() const
	{
		cout << this->str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String temp = left.GetSize() + right.GetSize() - 1;
	for (int i = 0; i < left.GetSize(); i++) temp[i] = left[i];
	//for (int i = left.GetSize()-1; i < temp.GetSize(); i++) temp[i] = right[i - left.GetSize()+1];
	for (int i = 0; i < right.GetSize(); i++) temp[i + left.GetSize() - 1] = right[i];
	return temp;
}

ostream& operator<<(ostream& os, const String& obj)
{
	//for (int i = 0; obj.GetStr()[i]; i++) cout << obj.GetStr()[i];
	return os << obj.GetStr();
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