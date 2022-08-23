#pragma once
#include "Lib.h"
using namespace std;

class Account;
class Staff;
class Student;

void menu();
bool validateOption(string, int);
void login();
tuple<string, string> getLoginInput();
Account* createAccount(string, string, string);
void quit();
vector<string> split(string, string);