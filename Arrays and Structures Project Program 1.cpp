#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MaxRows = 10;
const int Columns = 7;
const string FileName = "Runner Data.txt";

// Reads the names of runners from the file.
// Pre-Condition: Finds existing file and reads and stores names of runners.
// Post-Condition: Holds the names for the next function to use.
int RunnerArray(string Names[], double Miles[][Columns], int MaxRows);

// Calculates the total and average miles for each runner.
// Pre-Condition: Receives the raw miles for each runner and number of runners.
// Post-Condition: Total and average miles is calculated for each runner and put at the end of the row for that runner.
void RunnersAveragesandTotal(double Miles[][Columns], double Averages[], double Total[], int NumberofRows);

// Outputs on the screen the Names, Miles, Total Miles, and Average Miles for each runner.
// Pre-Condition:
// Post-Condition:
void Output(string RunnerNames[], double RunnerData[][Columns], double Total[], double Averages[], int NumberofRecords);

void Labels(string RunnerNames[], double Miles[][Columns], double Averages[], double Total[], int NumberofRecords);

int main()
{
	string RunnerNames[MaxRows];
	double RunnerData[MaxRows][Columns];
	double Averages[MaxRows];
	double Total[MaxRows];
	int NumberofRecords;
	NumberofRecords = RunnerArray(RunnerNames, RunnerData, MaxRows);
	RunnersAveragesandTotal(RunnerData, Total, Averages, NumberofRecords);
	//Output(RunnerNames, RunnerData, Total, Averages, NumberofRecords);
	Labels(RunnerNames, RunnerData, Total, Averages, NumberofRecords);

	return 0;
}

int RunnerArray(string Names[], double Miles[][Columns], int MaxRows)
{
	ifstream myiFile;
	int Rows = 0;

	myiFile.open(FileName);

	if(!myiFile.is_open())
	{
		cout << "Could not open file.\n";

		return -1;
	}

	myiFile >> Names[Rows];
	while(!myiFile.eof() && !(Rows >= MaxRows))
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

void RunnersAveragesandTotal(double Miles[][Columns], double Total[], double Averages[], int NumberofRows)
{
	double Sum = 0;
	for (int i = 0; i < NumberofRows; i++)
	{
		Sum = 0;
		for (int j = 0; j < Columns; j++)
		{
			Sum = Sum + Miles[i][j];
		}
		Total[i] = Sum;
		Averages[i] = Sum / Columns;
	}
}

void Output(string RunnerNames[], double RunnerData[][Columns], double Total[], double Averages[], int NumberofRecords)
{
	for (int i = 0; i < NumberofRecords; i++)
	{
		cout << RunnerNames[i] << " ";
		for (int j = 0; j < Columns; j++)
		{
			cout << RunnerData[i][j] << " ";
		}
		cout << Total[i] << " " << Averages[i];
		cout << endl;
	}
}

void Labels(string RunnerNames[], double RunnerData[][Columns], double Total[], double Averages[], int NumberofRecords)
{
	//cout << fixed << setprecision(2) << showpoint;
	cout << "Runner   Day 1  Day 2  Day 3  Day 4  Day 5  Day 6  Day 7  Total  Average" << endl;
	for (int i = 0; i < NumberofRecords; i++)
	{
		cout << left << setw(10) <<  RunnerNames[i];
		for (int j = 0; j < Columns; j++)
		{
			cout << left << setw(7) << RunnerData[i][j];
		}
			cout << left << setw(7) << Total[i] << left << setw(7) << Averages[i] << endl;
	}
}
