#pragma once
#include "Lib.h"
using namespace std;

class Account
{
protected:
	string username;
	string password;

public:
	Account(string, string);

public:
	virtual string classname();
	virtual void validate();
};

class Staff : public Account {
public:
	Staff(string username, string password) :
		Account(username, password) {}

public:
	string classname();
	void validate();

};

class Student : public Account {
public:
	Student(string username, string password) :
		Account(username, password) {}
public:
	string classname();
	void validate();
};