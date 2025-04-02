#ifndef STRUCT_HPP
#define STRUCT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <algorithm>

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
		cout << name << "\t\t" << phone << "\t\t" << address << "\t\t" << email << "\n";
	};
};
//bool flag resembles will array of structures be sorted by name (1 or true)  or by phone (0 or false) 
vector<int> IndexCreate(const vector<Contact>& con, bool flag);
void Print(const vector<Contact>& con, const vector<int>& ind);

bool compare(const Contact& c1, const Contact& c2, bool flag);

void InsertSortStruct(vector<Contact>& con, vector<int>& ind, bool flag);

#endif