#include "Account.h"

Account::Account(string username, string password)
{
	this->username = username;
	this->password = password;
}
bool Account::isInside(vector<string> accounts)
{
	for (string account : accounts) {
		vector<string> splitedStrings = split(account, ",");

		if (username == splitedStrings.at(0) && password == splitedStrings.at(1))
			return true;
	}
	return false;
}

string Account::classname() {
	return "Account";
}
bool Account::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
	cout << "Type: " << this->classname() << endl;

	return true;
}

string Staff::classname() {
	return "Staff";
}
bool Staff::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
	cout << "Type: " << this->classname() << endl;

	CSVFile accountFile(AccountPath::staff);
	vector<string> staffAccounts = accountFile.read();

	bool isExisted = Account::isInside(staffAccounts);

	return isExisted;
}

string Student::classname() {
	return "Student";
}
bool Student::validate()
{
	cout << "Validating..." << endl;
	cout << "Account: " << username << ", " << password << endl;
	cout << "Type: " << this->classname() << endl;

	CSVFile accountFile(AccountPath::student);
	vector<string> studentAccounts = accountFile.read();

	bool isExisted = Account::isInside(studentAccounts);

	return isExisted;
}