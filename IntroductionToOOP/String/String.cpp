#include "String.h"

String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Constructor:" << tab << this << endl;
}

String::String(const char* s) : String(strlen(s) + 1)
{
	//this->size = strlen(s)+1;
	//this->str = new char[size]{};

	for (int i = 0; i < size; i++) this->str[i] = s[i];
	cout << "Constructor:" << tab << this << endl;
}

String::~String()
{
	delete[] str;
	cout << "Destructor:" << tab << this << endl;
}

////////////////////////////////////////////////////////

String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size]{};
	//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:" << tab << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
	other.size = 0;
	cout << "MoveConstructor:" << tab << this << endl;
}

////////////////////////////////////////////////////////

const char* String::GetStr() const
{
	return this->str;
}

char* String::GetStr()
{
	return this->str;
}

int String::GetSize() const
{
	return this->size;
}

////////////////////////////////////////////////////////

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	this->size = other.size;
	delete[] str;
	this->str = new char[size] {};

	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}

	cout << "CopyAssignment:" << tab << this << endl;
	return *this;
}

String& String::operator=(String&& other)
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

char String::operator[](int index) const
{
	if (index < 0 || index>this->size)throw std::exception("out of range in const[]");
	return this->str[index];
}

char& String::operator[](int index)
{
	if (index < 0 || index>this->size)throw std::exception("out of range in []");
	return this->str[index];
}

////////////////////////////////////////////////////////

void String::Print() const
{
	cout << this->str << endl;
}

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