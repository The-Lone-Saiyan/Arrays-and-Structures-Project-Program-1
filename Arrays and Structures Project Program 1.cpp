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

// Calculates the average miles for each runner.
// Pre-Condition: Receives the raw miles for each runner and number of runners.
// Post-Condition: Average miles is calculated for each runner and put at the end of the row for that runner.
void RunnersAverages(double Miles[][Columns], int NumberofRows);

int main()
{
	string RunnerNames[MaxRows];
	double RunnerData[MaxRows][Columns];
	int NumberofRecords;
	NumberofRecords = RunnerArray(RunnerNames, RunnerData, MaxRows);

	for (int i = 0; i < NumberofRecords; i++)
	{
		cout << RunnerNames[i] << " ";
		for (int j = 0; j < Columns; j++)
		{
			cout << RunnerData[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}

int RunnerArray(string Names[], double Miles[][Columns], int MaxRows)
{
	ifstream myiFile;
	int Rows = 0;

	myiFile.open(FileName);

	if (!myiFile.is_open())
	{
		cout << "Could not open file.\n";

		return -1;
	}

	myiFile >> Names[Rows];
	while (!myiFile.eof() && !(Rows >= MaxRows))
	{
		for (int i = 0; i < Columns; i++)
		{
			myiFile >> Miles[Rows][i];
		}
		Rows++;
		myiFile >> Names[Rows];
	}
	myiFile.close();

	return Rows;
}

void RunnersAverages(double Miles[][Columns], int NumberofRows)
{
	double Sum = 0;
	for (int i = 0; i < NumberofRows; i++)
	{
		Sum = 0;
		for (int j = 0; j < Columns; j++)
		{
			Sum += Miles[i][j];
			Miles[i][Columns] = Sum / Columns;
		}
	}
}