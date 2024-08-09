#pragma once
#include<iostream>
using namespace std;

//Циклически сдвигает массив на заданное к-во э-ов влево
void ShiftLeft(int arr[], const int n, int c);	
void ShiftLeft(double arr[], const int n, int c);
void ShiftLeft(char arr[], const int n, int c);

//Циклически сдвигает массив на заданное к-во э-ов вправо
void ShiftRight(int arr[], const int n, int c);
void ShiftRight(double arr[], const int n, int c);
void ShiftRight(char arr[], const int n, int c);