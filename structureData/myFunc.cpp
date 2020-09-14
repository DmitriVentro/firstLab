#include <iostream>
#include "MyFunc.h"
using namespace std;

void printArr(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void swapDiagonal(int** a, int N)
{
	int i = 0, j = 0, n = 1, tmp;

	while (i < N)
	{
		tmp = a[i][j];
		a[i][j++] = a[i][N - n];
		a[i++][N - n++] = tmp;
	}
}
