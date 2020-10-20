//Iqbal Bhandal
//CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

void binary_search(int [], int, int, int, int &);

int main()
{
    int arr_size;
    int b_search;
    int nf = 0;
    
    cin >> arr_size;
    cin >> b_search;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    binary_search(arr, arr_size - 1, b_search, 0, nf);

    if (nf == 0)
    {
        cout << "-1";
    }

    return 0;
}

void binary_search(int arr[], int i, int j, int k, int &nf)
{
    int middle;

    if (i >= k)
    {
        middle = k + (i - k) / 2 ;

        if (arr[middle] == j)
        {
            cout << middle;
            nf = 1;
        }

        if (arr[middle > j])
        {
            binary_search(arr, middle - 1, j, k, nf);
        }
        binary_search(arr, i, j, middle +1, nf);
    }

}
