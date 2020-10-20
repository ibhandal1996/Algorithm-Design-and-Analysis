// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

void heapsort(int[], int, int);

int main()
{
    int arr_size;
    cin >> arr_size;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    for (int i = (arr_size / 2) - 1; i >= 0; i--)
    {
        heapsort(arr, arr_size, i);
    }
    
    for (int i = arr_size - 1; i >=0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapsort(arr, i, 0);
    }

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i];
        cout << ";";
    }

    return 0;
}

void heapsort(int arr[], int size, int i)
{
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;
    int large = i;

    if (size > l && arr[large] < arr[l])
    {
        large = l;
    }

    if (size > r && arr[large] < arr [r])
    {
        large = r;
    }

    if (large != i)
    {
        int temp = arr[i];
        arr[i] = arr[large];
        arr[large] = temp;

        heapsort(arr, size, large);
    }
}