//Iqbal Bhandal
//CSE 100

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int arr_size;
    int l_search = 0;
    int i;
    int j = 0;

    cin >> arr_size;
    cin >> l_search;

    int arr[arr_size];
    
    for (i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] == l_search)
        {
            cout << i << endl;
            j = 1;
        }
    }

    if (j == 0)
    {
        cout <<"-1" << endl;
    }


    return(0);
}
