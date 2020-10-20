// Iqbal Bhandal
// CSE 100

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	int n, hashSize;

	cin >> hashSize;

	list<int> hash[hashSize]; 
	char input[100];

	do
    {
		string hashTab(input);

		if (hashTab.size() == 0) 
		{
			continue;
		}

		if (hashTab.substr(0, 1) == "e") 
        {
			return 0;
		}

		if (hashTab.substr(0, 1) == "o") 
        {
            for (int i = 0; i < hashSize; i++) 
        	{
		        cout << i << " : ";
		        for (list<int>::iterator it = hash[i].begin(); it != hash[i].end(); it++)
		            {
			            cout << *it;
			            if (++it != hash[i].end())
				        cout << "->";
				        it--;
		            }
		        cout << endl;
	        }

	        cout << "++++++++++++++++++++\n";
			continue;
		}
        
		stringstream k(hashTab.substr(2, hashTab.size() - 1));
		if (!(k >> n)) 
		{
			n = -1;
		}

		if (hashTab.substr(0, 1) == "s") 
        {
			bool occurs = false;
	        int count = 0;
	        int A = n % hashSize;

	        for (list<int>::iterator it = hash[A].begin(); it != hash[A].end(); it++)
	        {   
		        if (*it == n)
		        {
			        cout << n << " : " << "FOUND AT " << A << "," << count << endl;
			        cout << "++++++++++++++++++++\n";
			        occurs = true;
			        break;
		        }
		        count++;
	        }

	        if (occurs == false)
	        {
		        cout << n << " : " << "NOT FOUND\n";
		        cout << "++++++++++++++++++++\n";
	        }

	        occurs = false;
		}

		if (hashTab.substr(0, 1) == "d") 
        {
			bool occurs = false;
	        int A = n % hashSize;

	        for (list<int>::iterator it = hash[A].begin(); it != hash[A].end(); it++)
	        {
		        if (*it == n)
		        {
			        hash[A].erase(it);
			        cout << n << " : " << "DELETED\n";
			        cout << "++++++++++++++++++++\n";
			        occurs = true;
			        break;
		        }
	        }

	        if (occurs == false)
	        {
		        cout << n << " : " << "DELETE FAILED\n";
		        cout << "++++++++++++++++++++\n";
	        }

	        occurs = false;
		}

        if (hashTab.substr(0, 1) == "i") 
        {
				int A = n % hashSize;
	            hash[A].push_front(n);   
		}

	}while (cin.getline(input, 100));

}
