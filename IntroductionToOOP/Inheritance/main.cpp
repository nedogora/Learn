#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

#define tab "\t"

#define GetHumanParameters const char* surname, const char* name, int age, char sex
#define SetHumanParameters surname, name, age, sex

class Human
{
protected:
	char* surname;
	char* name;
	int age;
	char sex;

public:

	Human(GetHumanParameters)
	{
		this->surname = new char[strlen(surname) + 1];
		strcpy(this->surname, surname);
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
		this->sex = sex;

		//cout << "HConstructor:" << tab << this << endl;
	}

	~Human()
	{
		delete[] surname;
		delete[] name;
		//cout << "HDestructor:" << tab << this << endl;
	}

	void Print()
	{
		cout << "Surname: " << this->surname << tab << "Name: " << this->name << tab << "Age: " << this->age << tab << "Sex: " << this->sex << tab;
	}
};

class Student : public Human
{
	char* speciality;
	int year;

public:

	Student(GetHumanParameters, const char* speciality, int year) :Human(SetHumanParameters)
	{
		this->speciality = new char[strlen(speciality) + 1];
		strcpy(this->speciality, speciality);
		this->year = year;

		//cout << "SConstructor:" << tab << this << endl;
	}

	~Student()
	{
		delete[] speciality;
		//cout << "SDestructor:" << tab << this << endl;
	}

	void Print()
	{
		Human::Print();
		cout << "Speciality: " << this->speciality << tab << "Year: " << this->year << endl;
	}
};

class Teacher :public Human
{
	char* speciality;
	char* degree;
	int experience;

public:

	Teacher(GetHumanParameters, const char* speciality, const char* degree, int experience) :Human(SetHumanParameters)
	{
		this->speciality = new char[strlen(speciality) + 1];
		strcpy(this->speciality, speciality);
		this->degree = new char[strlen(degree) + 1];
		strcpy(this->degree, degree);
		this->experience = experience;

		//cout << "TConstructor:" << tab << this << endl;
	}

	~Teacher()
	{
		delete[] speciality;
		delete[] degree;
		//cout << "TDestructor:" << tab << this << endl;
	}

	void Print()
	{
		Human::Print();
		cout << "Speciality: " << this->speciality << tab << "Degree: " << this->degree << tab << "Experience: " << this->experience << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");

	Human h("Ivanov", "Ivan", 25, 'M');
	h.Print();
	cout << endl;

	Student s("Ivanova", "Olga", 20, 'W', "Designer", 2020);
	s.Print();

	Teacher t("Petrov", "Petr", 30, 'M', "Developer", "Master", 5);
	t.Print();
}