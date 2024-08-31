#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int N);
int StringLength(char str[]);	// Возвращает длинну строки в символах

void ToUpper(char str[]);	// Переводит строку в верхний регистр
void ToLower(char str[]);	// Переводит строку в нижний регистр
void Shrink(char str[]);	// Удаляет лишние пробелы из строки
void RemoveSymbol(char str[], char symbol);
bool isPalindrome(char str[]);	// Определяет, является ли строка палиндромом

bool isIntNumber(char str[]);	// Определяет, является ли строка целым числом
int ToIntNumber(char str[]);	// Переводи строку в целое число

bool isBinNumber(char str[]);	// Определяет, является ли строка двоичным числом
int degree(int n, int d);	//Возводит число в степень
int BinToDec(char bin[]);	// Переводит двоичное число в десятичное

bool isHexNumber(char str[]);	// Определяет, является ли строка HEX числом
int HexToDec(char hex[]);	// Переводит HEX число в десятичное

void ASCII()
{
	for (int i = 0; i < 256; i++) cout << i << '\t' << (char)i << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l','l','o', 0};
	//char str[]="Hello";

	const int SIZE = 256;
	//char str[SIZE] = {};
	char str[SIZE] = "Аргентина манит негра";

	cout << "Введите строку: ";
	//cin >> str;

	/*
		SetConsoleCP(1251);	//cin воспринимает символы в кодировке CP-1251
		cin.getline(str, SIZE);
		SetConsoleCP(866);	//cout можут выводить символы только в кодировке CP-866
	*/
	//InputLine(str, SIZE);
	cout << str << endl;

	cout << "Length: " << StringLength(str) << endl;

	//ASCII();
	/*cout << 'а' - 'А' << endl;
	cout << (int)'А' << '\t'  << (int)'а' << endl;*/

	cout << "\n----- To Upper -----" << endl;
	//ToUpper(str);
	cout << str << endl;

	cout << "\n----- To Lower -----" << endl;
	//ToLower(str);
	cout << str << endl;

	cout << "\n----- Shrink -----" << endl;
	//Shrink(str);
	cout << str << endl;

	cout << "\nPalindrome: " << isPalindrome(str) << endl;
	cout << str << endl;
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
	for (int i = 0; str[i]; i++)str[i] = toupper(str[i]);
	//for (int i = 0; str[i]; i++) if ((str[i] >= -32 && str[i] <= 0) || str[i] >= 97) str[i] -= 32;
}

void ToLower(char str[])
{
	/*for (int i = 0; str[i]; i++)
	{
		if (str[i] >= -64 && str[i] <= -33) str[i] += 32;
		if (str[i] >= 65 && str[i] <= 96) str[i] += 32;
	}*/

	for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
	//for (int i = 0; str[i]; i++) if ((str[i] >= -64 && str[i] <= -33) || (str[i] >= 65 && str[i] <= 96)) str[i] += 32;
}

void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

void RemoveSymbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

bool isPalindrome(char str[])
{
	int n = StringLength(str);
	bool is_palindrome = true;

	char* buffer = new char[n + 1] {};
	for (int i = 0; str[i]; i++) buffer[i] = str[i];

	RemoveSymbol(buffer, ' ');
	ToLower(buffer);

	n = strlen(buffer);
	for (int i = 0; i < n; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			is_palindrome = false;
			break;
		}
	}

	delete[] buffer;
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
		cout << "Это не целое число" << endl;
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
	if (isBinNumber(bin) == false) return 0;
	int capacity = StringLength(bin);
	//int deg = capacity - 1;
	int num = 0;
	int weight = 1;

	//for (int i = 0; i < capacity; i++) num += degree(2, deg--) * (((int)bin[i]) - 48);
	for (int i = 0; i < capacity; i++, weight *= 2) num += (bin[capacity - 1 - i] - '0') * weight;
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
	/*if (isHexNumber(hex) == false) return 0;

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
	return num;*/

	if (isHexNumber(hex) == false) return 0;

	int capacity = StringLength(hex);
	//int deg = capacity - 1;
	int num = 0;
	int weight = 1;

	for (int i = capacity - 1; i >= 0; i--, weight *= 16)
	{
		if (hex[i] >= '0' && hex[i] <= '9') hex[i] -= 48;
		if (hex[i] >= 'A' && hex[i] <= 'F') hex[i] -= 55;
		if (hex[i] >= 'a' && hex[i] <= 'f') hex[i] -= 87;

		//num += degree(16, deg--) * (int)hex[i];
		num += (hex[i]) * weight;
	}
	return num;
}