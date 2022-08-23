#include "Lib.h"
#include "File.h"
using namespace std;

int main()
{
	CSVFile file("data/users/sample.csv");
	//file.read();

	vector<string> records;
	records.push_back("Line");
	file.write(FileMode::out, records);

	return 0;
}