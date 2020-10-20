// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

void EBUCR(int [], int);

int main()
{
    int arr_size;

    cin >> arr_size;

    int arr[arr_size];

    for (int i = 1; i <= arr_size; i++)
    {
        cin >> arr[i];
    }

    EBUCR(arr, arr_size);

    return 0;

}

void EBUCR(int arr[], int arr_size)
{
    int r[arr_size], s[arr_size];

    r[0] = 0;

    for (int j = 1; j <= arr_size; j++)
    {
        int q = -2147483646;

        for (int i = 1; i <= j; i++)
        {
            if( q < (arr[i] + r[j-i]))
            {
                q = arr[i] + r[j-i];
                s[j] = i;
            }
        }

        r[j] = q;
    }

    cout << r[arr_size];
    cout << endl;

    while (arr_size > 0)
        {
            cout << s[arr_size];
            cout << " ";
            arr_size = arr_size - s[arr_size];
        }
        
    cout << "-1";
    cout << endl;

}