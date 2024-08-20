#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	cout << *&a << endl;
	
	short arr[] = { 3, 5, 8, 13, 21 };

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		//cout << arr[i] << '\t';
		cout << *(arr + i) << '\t';
	}
	cout << endl;
}