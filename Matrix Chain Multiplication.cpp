//Iqbal Bhandal
//CSE 100

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node 
{
	Node * l;
	Node * r;
	string b;
    int frequency;
	char c;
};

Node huffman(vector<Node> &, string []);
void printNode(Node*, string [], string);

int main() 
{
	int arr_size;
	Node n1;
    vector<Node> n;
    n1.l = NULL;
    n1.r = NULL;
    string str;

	cin >> arr_size;
    string arr[arr_size];
    
	for (int i = 0; i < arr_size; i++)
	{
		cin >> n1.frequency;
		n1.c = i + 1;
		n.push_back(n1);
	}

	Node root = huffman(n, arr);
	printNode(&root, arr, str);

	for (int i = 1; i <= arr_size; i++) 
    {
		cout << arr[i] << endl;
	}
	return 0;
}


Node huffman(vector<Node> &n, string arr[]) 
{
    int maxNumb, j;
	do
    {
		for (int i = 0; i < n.size() - 1; i++) 
        {
			Node * topNode = new Node;
			Node * lNode = new Node;
			Node * rNode = new Node;
            maxNumb = 2147483647;
	        j = 0;

	        for (int i = 0; i < n.size(); i++) 
            {
		        if (maxNumb > n[i].frequency)
                {
			        j = i;
			        maxNumb = n[i].frequency;
		        }
	        }	
	        *lNode = n[j];
	        n.erase(n.begin() + j);
            maxNumb = 2147483647;
	        j = 0;

            for (int i = 0; i < n.size(); i++) 
            {
		        if (maxNumb > n[i].frequency)
                {
			        j = i;
			        maxNumb = n[i].frequency;
		        }
	        }	
	        *rNode = n[j];
	        n.erase(n.begin() + j);
			topNode->r = rNode;
			topNode->l = lNode;
			topNode->frequency = lNode->frequency + rNode->frequency;
			n.push_back(*topNode);
		}
	}while (n.size() != 1);
	return n[0];
}

void printNode(Node * root, string arr[], string str) 
{
	struct Node * r = root;
	r->b = str;
	if (r->l == NULL && r->r == NULL) 
    {
		arr[r->c] = r->b;
	}

	else 
    {
		if (r->r) 
        {
			printNode(r->r, arr, str + "1");
		}
        if (r->l) 
        {
			printNode(r->l, arr, str + "0");
		}
	}
}
