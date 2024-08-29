#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int N);
int StringLength(char str[]);	// ���������� ������ ������ � ��������

void ToUpper(char str[]);	// ��������� ������ � ������� �������
void ToLower(char str[]);	// ��������� ������ � ������ �������
void Shrink(char str[]);	// ������� ������ ������� �� ������
bool isPalindrome(char str[]);	// ����������, �������� �� ������ �����������

bool isIntNumber(char str[]);	// ����������, �������� �� ������ ����� ������
int ToIntNumber(char str[]);	// �������� ������ � ����� �����

bool isBinNumber(char str[]);	// ����������, �������� �� ������ �������� ������
int degree(int n, int d);	//�������� ����� � �������
int BinToDec(char bin[]);	// ��������� �������� ����� � ����������

bool isHexNumber(char str[]);	// ����������, �������� �� ������ HEX ������
int HexToDec(char hex[]);	// ��������� HEX ����� � ����������

void ASCII()
{
	for (int i = 0; i < 256; i++) cout << i << '\t' << (char)i << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l','l','o', 0};
	//char str[]="Hello";

	const int SIZE = 20;
	char str[SIZE]{};

	cout << "������� ������: ";
	//cin >> str;

	/*
		SetConsoleCP(1251);	//cin ������������ ������� � ��������� CP-1251
		cin.getline(str, SIZE);
		SetConsoleCP(866);	//cout ����� �������� ������� ������ � ��������� CP-866
	*/
	InputLine(str, SIZE);
	cout << str << endl;

	cout << "Length: " << StringLength(str) << endl;

	//ASCII();
	/*cout << '�' - '�' << endl;
	cout << (int)'�' << '\t'  << (int)'�' << endl;*/

	cout << "\n----- To Upper -----" << endl;
	ToUpper(str);
	cout << str << endl;

	cout << "\n----- To Lower -----" << endl;
	ToLower(str);
	cout << str << endl;

	cout << "\n----- Shrink -----" << endl;
	Shrink(str);
	cout << str << endl;

	cout << "\nPalindrome: " << isPalindrome(str) << endl;
	cout << "\nIs Int Number: " << isIntNumber(str) << endl;

	cout << "\n----- String to Int -----" << endl;
	cout << str << " -> " << ToIntNumber(str) << endl;

	cout << "\nIs Bin Number: " << isBinNumber(str) << endl;

	cout << "\n----- Bin to Dec -----" << endl;
	cout << str << " -> " << BinToDec(str) << endl;

	cout << "\nIs Hex Number: " << isHexNumber(str) << endl;

	cout << "\n----- Hex to Dec -----" << endl;
	cout << str << " -> " << HexToDec(str) << endl;
}

void InputLine(char str[], const int N)
{
	SetConsoleCP(1251);
	cin.getline(str, N);
	SetConsoleCP(866);
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void ToUpper(char str[])
{
	for (int i = 0; str[i]; i++) if ((str[i] >= -32 && str[i] <= 0) || str[i] >= 97) str[i] -= 32;
}

void ToLower(char str[])
{
	/*for (int i = 0; str[i]; i++)
	{
		if (str[i] >= -64 && str[i] <= -33) str[i] += 32;
		if (str[i] >= 65 && str[i] <= 96) str[i] += 32;
	}*/

	for (int i = 0; str[i]; i++) if ((str[i] >= -64 && str[i] <= -33) || (str[i] >= 65 && str[i] <= 96)) str[i] += 32;
}

void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

bool isPalindrome(char str[])
{
	int n = StringLength(str);
	bool is_palindrome = true;

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i])
		{
			is_palindrome = false;
			break;
		}
	}
	return is_palindrome;
}

bool isIntNumber(char str[])
{
	bool isNumber = true;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			isNumber = false;
			break;
		}
	}
	return isNumber;
}

int ToIntNumber(char str[])
{
	if (isIntNumber(str) == false)
	{
		cout << "��� �� ����� �����" << endl;
		return 0;
	}

	int n = StringLength(str);
	int number = 0;

	for (int i = 0; i < n; i++)
	{
		number *= 10;
		number += ((int)str[i]) - 48;
	}
	return number;
}

bool isBinNumber(char str[])
{
	bool isNumber = true;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			isNumber = false;
			break;
		}
	}
	return isNumber;
}

int degree(int n, int d)
{
	if (d == 0) return 1;

	int result = 1;
	for (int i = 0; i < d; i++) result *= n;

	return result;
}

int BinToDec(char bin[])
{
	int capacity = StringLength(bin);
	int deg = capacity - 1;
	int num = 0;

	for (int i = 0; i < capacity; i++) num += degree(2, deg--) * (((int)bin[i]) - 48);
	return num;
}

bool isHexNumber(char str[])
{
	bool isHex = true;

	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
		{
			isHex = false;
			break;
		}
	}
	return isHex;
}

int HexToDec(char hex[])
{
	int capacity = StringLength(hex);
	int deg = capacity - 1;
	int num = 0;

	for (int i = 0; i < capacity; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9') hex[i] -= 48;
		if (hex[i] >= 'A' && hex[i] <= 'F') hex[i] -= 55;
		if (hex[i] >= 'a' && hex[i] <= 'f') hex[i] -= 87;

		num += degree(16, deg--) * (int)hex[i];
	}
	return num;
}