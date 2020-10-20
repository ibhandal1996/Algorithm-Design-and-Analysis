// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void POP(vector<vector<int>>, int, int);

int main()
{
    int arr_size, q;

    cin >> arr_size;

    int arr[arr_size + 1];

    for (int i = 0; i <= arr_size; i++)
    {
        cin >> arr[i];
    }

	int matrix[arr_size + 1][arr_size];

	for (int i = 0; i <= arr_size; i++)
	{
		matrix[i][i] = 0;
	}
	vector<vector<int> >sortedMatrix;
	sortedMatrix.resize(arr_size, vector<int>(arr_size + 1));

	for (int l = 2; l <= arr_size; l++)
	{
		int n = arr_size - l + 1;

		for (int i = 1; i <= n; i++)
		{
			int j = i + l - 1;
			matrix[i][j] = 2147483647;

			for (int k = i; k <= j - 1; k++)
			{
				q = matrix[i][k] + matrix[k + 1][j] + (arr[i -1] * arr[k] * arr[j]);
				
				if (q < matrix[i][j])
				{
					matrix[i][j] = q;
					sortedMatrix[i][j] = k;
				}
			}
		}
	}

	cout << matrix[1][arr_size];
	cout << endl;

	POP(sortedMatrix, 1, arr_size);

	cout << endl;

    return 0;

}

void POP(vector<vector<int>> sortedMatrix, int i, int arr_size)
{
	if(i == arr_size)
	{
		cout << "A";
		cout << i -1;
	}

	else
	{
		cout << "(";
		POP(sortedMatrix, i, sortedMatrix[i][arr_size]);
		cout << ".";
		POP(sortedMatrix, sortedMatrix[i][arr_size] + 1, arr_size);
		cout << ")";
	}
}