#include "Account.h"

Account::Account(string username, string password)
{
	this->username = username;
	this->password = password;
}

string Account::classname() {
	return "Account";
}
void Account::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
}

string Staff::classname() {
	return "Staff";
}
void Staff::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
}

string Student::classname() {
	return "Student";
}

void Student::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
}

