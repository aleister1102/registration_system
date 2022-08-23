#include "File.h"

CSVFile::CSVFile(string file)
{
	this->file = file;
}

vector<string> CSVFile::read()
{
	vector<string> records;
	f.open(file, FileMode::in);

	if (f.is_open())
	{
		// omitting the first line
		string line;
		getline(f, line);

		// read file's content
		while (!f.eof())
		{
			string line;
			getline(f, line);
			cout << line << endl;
			records.push_back(line);
		}
	}
	else {
		cout << file << " is not existed or can not be opened" << endl;
	}

	f.close();
	return records;
}

bool CSVFile::write(ios_base::openmode mode, vector<string> records)
{
	if (FileMode::out == mode)
		addFirstLineTo(records);
	
	f.open(file, mode);

	if (f.is_open()) {
		for (string record : records)
			f << record << endl;
	}
	else {
		cout << file << " is not existed or can not be opened" << endl;
		f.close();
		return false;
	}

	f.close();
	return true;
}

void CSVFile::addFirstLineTo(vector<string> &records) {
	f.open(file, FileMode::in);

	if (f.is_open()) {
		string fieldsLine;
		getline(f, fieldsLine);
		records.insert(records.begin(), fieldsLine);
	}

	f.close();
}