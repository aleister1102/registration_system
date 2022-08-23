#pragma once
#include "Lib.h"
#include "Account.h"
using namespace std;

void menu();
bool validateOption(string, int);
void login();
tuple<string, string> getLoginInput();
Account* createAccount(string, string, string);
void quit();