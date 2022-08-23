#pragma once
#include "Lib.h"
#include "File.h"
#include "Business.h"
using namespace std;

class AccountPath {
public:
	inline static string staff = "data/accounts/staff.csv";
	inline static string student = "data/accounts/student.csv";
};

class Account
{
protected:
	string username;
	string password;

public:
	Account(string, string);
	bool isInside(vector<string> accounts);

public:
	virtual string classname();
	virtual bool validate();
};

class Staff : public Account {
public:
	Staff(string username, string password) :
		Account(username, password) {}

public:
	string classname();
	bool validate();
};

class Student : public Account {
public:
	Student(string username, string password) :
		Account(username, password) {}
public:
	string classname();
	bool validate();
};