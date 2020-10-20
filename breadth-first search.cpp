//Iqbal Bhandal
//CSE 100

#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int main()
{
    int vert_size, edge_size, vert1, vert2, weight, min;
    priority_queue<pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>> > Queue1; //“inefficient” priority queue
    Queue1.push(pair <int, int> (0,0));
    cin >> vert_size;
    cin >> edge_size;

    vector<pair <int, int>> next[edge_size];
    int traversed[edge_size];

    for(int i = 0; i < edge_size; i++)
    {
        cin >> vert1;
        cin >> vert2;
        cin >> weight;
        next[vert1].push_back(make_pair(vert2,weight));
        next[vert2].push_back(make_pair(vert1,weight));
        traversed[i] = 0;
    }
    
    int vertKey[vert_size];
    int vertPie[vert_size];

    for(int i = 0; i < vert_size; i++)
    {
        vertKey[i] = 2147483647; 
        vertPie[i] = 0;
    }
    
    do
    {
        min = Queue1.top().second;
        Queue1.pop();
        //pop() removes the element on top of the priority_queue and reduces size by 1
        traversed[min] = 1;
        for(int i = 0; i < next[min].size(); i++)
        {          
            if(traversed[next[min][i].first] == 0 && next[min][i].second < vertKey[next[min][i].first]) 
            {
                Queue1.push(pair <int, int> (next[min][i].second, next[min][i].first));
                vertPie[next[min][i].first] = min;
                vertKey[next[min][i].first] = next[min][i].second;
            }
        }
        
    }while(Queue1.empty() == false);

    for(int i = 1; i < vert_size; i++)
    {
        cout << vertPie[i];
        cout << endl;
    }
    
    return 0;
}