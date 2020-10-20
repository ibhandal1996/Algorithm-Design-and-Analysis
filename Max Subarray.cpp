// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

int max(int[], int, int);
int max_cross(int[], int, int, int);

int main()
{
    int arr_size;

    cin >> arr_size;

    int arr[arr_size];

    for(int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    cout << max(arr, 0, arr_size - 1);
    return 0;

}

int max(int arr[], int l, int h)
{
    int m, max_l, max_r, max_c;

    if (l == h)
    {
        return arr[h];
    }

    if (l != h)
    {
        m = (l + h) / 2;

        max_l = max(arr, l, m);
        max_r = max(arr, m + 1, h);
        max_c = max_cross(arr, l, m, h);

        if (max_r <= max_l && max_c <= max_l)
        {
            return max_l;
        }
        else if (max_l <= max_r && max_c <= max_r)
        {
            return max_r;
        }
        else 
        {
            return max_c;
        }
    }
}

int max_cross(int arr[], int l, int m, int h)
{
    int sn1 = -2147483646;
    int sn2 = -2147483646;
    int j = 0;
    int k = 0;
    int cross;

    for (int i = m; i >= l; i--)
    {
        j += arr[i];
        if (sn1 < j)
        {
            sn1 = j;
        }
    }

    for (int a = m + 1; a <= h; a++)
    {
        k += arr[a];
        if(sn2 < k)
        {
            sn2 = k;
        }
    }

    cross = sn1 + sn2;

    return cross;

}