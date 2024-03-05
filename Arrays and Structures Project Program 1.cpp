#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MaxRows = 10;
const int Columns = 5;
const string FileName = "Runner Data.txt";

// Reads the names of runners from the file.
// Pre-Condition: Finds existing file and reads and stores names of runners.
// Post-Condition: Holds the names for the next function to use.
int RunnerArray(string Names[], double Miles[][Columns], int MaxRows);

int main()
{
	char RunnerNames[5];
	int RunnerData[5][7];
	RunnerArray(RunnerData, RunnerNames);
	

	return 0;
}

int RunnerArray(string Names[], double Miles[][Columns], int MaxRows)
{
	ifstream myiFile;
	int Rows = 0;

	myiFile.open("Runner Data.txt");

	if (!myiFile.is_open())
	{
		cout << "Could not open file.\n";

		return -1;
	}

	inFile >> Names[Rows];
}