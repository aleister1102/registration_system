#include "Business.h"

void menu() {
	string option;

	while (true) {
		//system("cls");

		do {
			cout << "0. Exit" << endl;
			cout << "1. Login" << endl;
			cout << "Type your choice: ";
			getline(cin, option);
		} while (!validateOption(option, 1));

		if (option == "1")
			login();
		else if (option == "0")
			quit();
	}
}

bool validateOption(string option, int max) {
	regex pattern("[0-9]{1}");
	smatch match;
	bool isMatched = regex_search(option, match, pattern);

	if (isMatched) {
		int optionNumber = stoi(option);
		if (optionNumber > max)
			return false;
		return true;
	}
	else
		return false;
}

void login() {
	string option;
	Account* account = nullptr;

	do {
		cout << "0. Back" << endl;
		cout << "1. Staff" << endl;
		cout << "2. Student" << endl;
		cout << "Choose your role: ";
		getline(cin, option);
	} while (!validateOption(option, 3));

	if (option == "0") return;

	string username, password;
	tie(username, password) = getLoginInput();

	account = createAccount(option, username, password);

	account->validate();
}

tuple<string, string> getLoginInput() {
	string username, password;

	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	return make_tuple(username, password);
}

Account* createAccount(string option, string username, string password) {
	if (option == "1")
		return new Staff(username, password);
	else if (option == "2")
		return new Student(username, password);
	else
		return nullptr;
}

void quit() {
	cout << "See you again!" << endl;
	exit(0);
}