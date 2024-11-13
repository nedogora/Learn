#include "String.h"

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