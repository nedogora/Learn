#include <iostream>
using namespace std;

//#define Addition
#define Substraction

void main()
{
	setlocale(LC_ALL, "");

	const int M = 3;	//���������� �����
	const int N = 3;	//���������� ��������
	int Arr[M][N] = {};
	int Brr[M][N] = {};
	int Crr[M][N] = {};	//���������

	//����������� ���������� �������
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Arr[i][j] = rand() % 10;
			Brr[i][j] = rand() % 10;
		}
	}

	//�����
	cout << "������� �:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "������� B:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Brr[i][j]  << "  ";
		}
		cout << endl;
	}
	cout << endl;

#ifdef Addition

	//��������
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Crr[i][j] = (Arr[i][j] + Brr[i][j]);
		}
	}

#endif // Addition

#ifdef Substraction

	//���������
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Crr[i][j] = (Arr[i][j] - Brr[i][j]);
		}
	}

#endif // Substraction

	//����� ����������:
	cout << "������� C:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Crr[i][j] << "  ";
		}
		cout << endl;
	}
}