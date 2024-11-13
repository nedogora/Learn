#pragma once
#include <iostream>
#include <string.h>
using namespace std;

#define tab "\t"

class String
{
	int size;
	char* str;

public:
	String(int size = 80);
	String(const char* s);

	~String();

	////////////////////////////////////////////////////////

	String(const String& other);
	String(String&& other);

	////////////////////////////////////////////////////////

	const char* GetStr() const;
	char* GetStr();
	int GetSize() const;

	////////////////////////////////////////////////////////

	String& operator=(const String& other);
	String& operator=(String&& other);

	char operator[](int index) const;
	char& operator[](int index);
	
	////////////////////////////////////////////////////////

	void Print() const;
};

String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);