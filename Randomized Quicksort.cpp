// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

int randQuick(int[], int, int);
int randPart(int[],int, int);

int main()
{
    int arr_size;
    cin >> arr_size;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    randQuick(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i];
        cout << ";";
    }

    return 0;
}

int randQuick(int arr[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = randPart(arr, p, r);
        randQuick(arr, p, q - 1);
        randQuick(arr, q + 1, r);
    }
}

int randPart(int arr[], int p, int r)
{
    srand(time(NULL));
    int i = p + rand() % (r - p + 1);

    //cout << endl << i << endl;
    
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;

    int x = arr[r];
    int j = p - 1;
    for (int k = p; k <= r - 1; k++)
    {
        if (arr[k] <= x)
        {
            j += 1;
            temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
        }
    }

    temp = arr[j + 1];
    arr[j + 1] = arr [r];
    arr[r] = temp;

    return j + 1;

}