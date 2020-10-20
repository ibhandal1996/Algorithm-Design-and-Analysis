//Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

void sort(int [], int, int, int);
void merge(int [], int, int, int, int);

int main()
{
    int arr_size;

    cin >> arr_size;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    sort(arr, 0, arr_size - 1, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << ";";
    }

    return 0;
}

void sort(int arr[], int l, int h, int size)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        sort(arr, l, m, size);
        sort(arr, m + 1, h, size);
        merge(arr, l, m, h, size);
    }
}

void merge(int arr[], int l, int m, int h, int size)
{
    int other_arr[size];
    int l1 = l, l2 = l, m1 = m + 1, h1 = h;
  
    while (l1 <= m && m1 <= h1)
    {
        if (arr[l1] <= arr[m1])
        {
            other_arr[l2] = arr[l1];
            l1++;
            l2++;
        }
        else
        {
            other_arr[l2] = arr[m1];
            m1++;
            l2++;
        }
    }

    while (l1 <= m)
    {
        other_arr[l2] = arr[l1];
            l1++;
            l2++;
    }

    while (m1 <= h1)
    {
        other_arr[l2] = arr[m1];
        m1++;
        l2++;
    }

    for (int i = l; i <= h; i++)
    {
        arr[i] = other_arr[i];
    }
}