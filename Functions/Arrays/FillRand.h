#pragma once
#include<iostream>
using namespace std;

void FillRand(int arr[], const int n, int min = 0, int max = 100);	//Заполняет массив случайными числами. Обычно массив заполняется случайными числами от 0-100, но при необходимости пользователь может передать пределы генерации случайных чисел
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n, int min = 0, int max = 256);