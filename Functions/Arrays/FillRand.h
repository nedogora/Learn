#pragma once
#include<iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 5;

void FillRand(int arr[], const int n, int min, int max);	//��������� ������ ���������� �������. ������ ������ ����������� ���������� ������� �� 0-100, �� ��� ������������� ������������ ����� �������� ������� ��������� ��������� �����
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int min = 0, int max = 100);