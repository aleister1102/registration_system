#pragma once
#include "Lib.h"
using namespace std;

class FileMode {
public:
	inline static ios_base::openmode in = ios_base::in;
	inline static ios_base::openmode out = ios_base::out;
	inline static ios_base::openmode app = ios_base::app;
};

class File {
	virtual vector<string> read() = 0;
	virtual bool write(ios_base::openmode mode, vector<string> records) = 0;
};

class CSVFile : public File
{
private:
	fstream f;
	string file;
public:
	CSVFile(string file);
public:
	vector<string> read();
	bool write(ios_base::openmode mode, vector<string> records);
	void addFirstLineOfFileTo(vector<string>& records);
};
