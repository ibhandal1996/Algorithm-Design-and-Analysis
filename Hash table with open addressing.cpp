// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

void bucketSort(double [], int);
 
int main()
{
    int arr_size;

    cin >> arr_size;

    double arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    bucketSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

void bucketSort(double arr[], int arr_size)
{
    vector<double> B[arr_size];
    int n = 0;
    
    for (int i = 0; i < arr_size; i++)
    {
       int k = arr_size * arr[i];
       B[k].push_back(arr[i]);
    }
 
    for (int i = 0; i < arr_size; i++)
    {
       sort(B[i].begin(), B[i].end());
    }

    for (int i = 0; i < arr_size; i++)
    {  
        for (int j = 0; j < B[i].size(); j++)
        {
          arr[n] = B[i][j];
          n++;
        }
    }
}