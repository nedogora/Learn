#pragma once
#include<iostream>
using namespace std;

//Возвращает сумму э-ов массива
int Sum(int arr[], const int n);	
double Sum(double arr[], const int n);

double Avg(int arr[], const int n);		//Возвращает среднее арифметическое

//Мin значение
int MinValueIn(int arr[], const int n);
double MinValueIn(double arr[], const int n);
char MinValueIn(char arr[], const int n);

//Max значение
int MaxValueIn(int arr[], const int n);
double MaxValueIn(double arr[], const int n);
char MaxValueIn(char arr[], const int n);