// Iqbal Bhandal
// CSE 100 LAB 00

#include <iostream>
#include <cstdlib>
using namespace std;

void insSort(int [], int);

int main()
{
    int a_Size;

    cin >> a_Size;

    int arr[a_Size];

    for (int i = 0; i < a_Size; i++)
    {
        cin >> arr[i];
    }

    insSort(arr, a_Size);

    for (int i = 0; i < a_Size; i++)
    {
        cout << arr[i] << ";";
    }

    return 0;
}

void insSort(int arr[], int a_Size)
{
    for (int i = 1; i < a_Size; i++)
    {
        int j = arr[i];
        int k = i - 1;

        while (k >= 0 && j > arr[k])
        {
            arr[k + 1] = arr[k];
            k = k - 1;
        }
        arr [k + 1] = j;
    }
}