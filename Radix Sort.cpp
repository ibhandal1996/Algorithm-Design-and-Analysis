// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void radixSort(vector<int> [], int);

int main()
{
    int vect_size, input;
    
    cin >> vect_size;

    vector<int> vect[vect_size];

    for (int i = 0; i < vect_size; i++)
    {
        for (int j = 0; j < 10; j++) 
        {
            cin >> input;

            vect[i].push_back(input);
        }
    }

    radixSort(vect, vect_size);

    for (int i = 0; i < vect_size; i++)
    {
        for (vector<int>::iterator j =  vect[i].begin(); j != vect[i].end(); j++)
        {
            cout << *j;
            cout << ";";
        }
       cout << endl;
    }

    return 0;

}

void radixSort(vector<int> vect[], int vect_size)
{
    for(int i = 9; i >=0; i--)
    {
        vector<int> temp[vect_size];
        int temp1[10] = { 0 };

        for(int j = 0; j < vect_size; j++)
        {
            temp1[vect[j][i]] = temp1[vect[j][i]] + 1;
        }

        for (int k = 1; k < 10; k++)
        {
            temp1[k] = temp1[k] + temp1[k -1];
        }

        for (int j = vect_size - 1; j >= 0; j--)
        {
            temp[temp1[vect[j][i]] - 1] = vect[j];
           temp1[vect[j][i]] = temp1[vect[j][i]] - 1;
        }

       for(int k = 0; k < vect_size; k++)
        {
            vect[k] = temp[k];
        }

    }
}
