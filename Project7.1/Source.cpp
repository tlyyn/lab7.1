#include <iostream>
#include <iomanip>
using namespace std;

void Init(int** arr, const int rowCount, const int colCount, const int Low = 4, const int High = 45);
void Print(int** arr, const int rowCount, const int colCount);
void Sort(int** arr, const int rowCount, const int colCount);
void Change(int** arr, const int row1, const int row2, const int colCount);
void Calc(int** arr, const int rowCount, const int colCount, int& Sum, int& Count);

int main()
{
	srand(time(0));

	int rowCount = 9, colCount = 7, S, C;
	int** Z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Z[i] = new int[colCount];

	Init(Z, rowCount, colCount);
	Print(Z, rowCount, colCount);

	Sort(Z, rowCount, colCount);
	Print(Z, rowCount, colCount);

	Calc(Z, rowCount, colCount, S, C);
	cout << "Sum = " << S << endl;
	cout << "Count = " << C << endl;
	Print(Z, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] Z[i];
	delete[] Z;

	return 0;
}

void Init(int** arr, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			arr[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** arr, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** arr, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++) {
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++) {
			if (arr[0][j1] < arr[0][j1 + 1] ||
				(arr[0][j1] == arr[0][j1 + 1] && arr[1][j1] > arr[1][j1 + 1]) ||
				(arr[0][j1] == arr[0][j1 + 1] && arr[1][j1] == arr[1][j1 + 1] && arr[2][j1] < arr[2][j1 + 1]))
				Change(arr, j1, j1 + 1, rowCount);
		}
	}
}

void Change(int** arr, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = arr[i][col1];
		arr[i][col1] = arr[i][col2];
		arr[i][col2] = tmp;
	}
}

void Calc(int** arr, const int rowCount, const int colCount, int& Sum, int& Count)
{
	Sum = 0;
	Count = 0;

	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (arr[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0))
			{
				Sum += arr[i][j];
				Count++;
				arr[i][j] = 0;
			}
}