#pragma once
#include "stdafx.h"

void FillRand(int Arr[], const int n, int min = 0, int max = 100);
void FillRand(float Arr[], const int n, int min = 0, int max = 100);
void FillRand(double Arr[], const int n, int min = 0, int max = 100);
void FillRand(char Arr[], const int n);

void FillRand(int** Arr, const int rows, const int cols, int min = 0, int max = 100);
void FillRand(float** Arr, const int rows, const int cols, int min = 0, int max = 100);
void FillRand(double** Arr, const int rows, const int cols, int min = 0, int max = 100);
void FillRand(char** Arr, const int rows, const int cols);