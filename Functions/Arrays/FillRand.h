#pragma once
#include<iostream>
using namespace std;

void FillRand(int arr[], const int n, int min = 0, int max = 100);	//��������� ������ ���������� �������. ������ ������ ����������� ���������� ������� �� 0-100, �� ��� ������������� ������������ ����� �������� ������� ��������� ��������� �����
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n, int min = 0, int max = 256);