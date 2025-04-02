#ifndef STRUCT_HPP
#define STRUCT_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

struct S
{
	string surname;
	string name;
	string secondName;
	string number;

	S() {}

	template <typename T, size_t N>
	constexpr size_t size(const T(&)[N]) {
		return N;
	}

	S(string surname, string name, string secondName, string number) {
		this->surname = surname;
		this->name = name;
		this->secondName = secondName;
		this->number = number;
	}

	void print() {
		cout << surname << " \t" << name << " \t\t" << secondName << " \t" << number << " \n";
	}

};

void InsertSortStruct(S s[], int size);
void InsertSortStruct(S s[], int size, int key, bool asc);

bool compare(const S& s1, const S& s2);
bool compare(const S& s1, const S& s2, int key, bool asc);

int BinarySearchStruct(S s[], int size, int key, const string& ToFind);

//indexation

struct Contact

{
	string name;
	string phone;
	string address;
	string email;

	void print() {
		cout << name << "\t" << phone << "\t" << address << "\t" << email;
	};
};
#endif