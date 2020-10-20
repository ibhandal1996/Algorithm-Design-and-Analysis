//Iqbal Bhandal
//CSE 100

//I left the commented out code in because I make these small mistakes a lot and would
//like to see them when looking back at this code

#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
    bool FindVert(string vert1, list<string> temp);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    pair<string, string> ed(vert1,vert2);
    edges[ed] = weight;
}

bool Graph::FindVertex(string vert1) {
    for(list<string> :: iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        if(vert1 == *it)
        {
            return true;
        }
    }
        //else
        //{
            return false;
        //}
    //}  
}

bool Graph::FindVert(string vert1, list<string> temp)
{
    for(list<string> :: iterator it = temp.begin(); it != temp.end(); it++)
    {
        if (*it == vert1)
        {
            return true;
        }
    }
    //else
        //{
            return false;
        //}
    //}  
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    pair <string, string> finish(vert1, vert2);
    map<pair<string, string>, int> :: iterator it = edges.find(finish);
    if(it == edges.end())
    {
        return -1;
    }
    else 
    {
        return it->second;
    }
}

int Graph::IsReachable(string vert1, string vert2) {
    queue< pair<string,int> > i;
    list<string> j = vertices;
    pair<string, int> start(vert1, 0);
    i.push(start);
    j.remove(vert1);
    pair<string, int> temp;
    list<string> :: iterator it;
    map<pair<string, string>, int>::iterator m;
    do
    {
        temp = i .front();
        i.pop();
        if(temp.first == vert2)
        {
            return temp.second;
        }
        for(m = edges.begin(); m != edges.end(); m++)
        {
            //if (m->first.first == temp.first)
           // {
               // for(it = j.begin(); it != j.end(); it++)
               // {
                    if(FindVert(m->first.second, j) && m->first.first == temp.first/**it == m->first.second*/) 
                    {
                        pair<string, int> next(m->first.second, temp.second+1);
                        i.push(next);
                        j.remove(next.first);
                    }
                //}
           // }
        }
    }while(i.size() != 0);
    return -1;
}

int main() {
    Graph G;
    string i;
    int w;
    string i1;
    string i2;
    int num;
    string vert1;
    string vert2;

    cin >> i;

    do
    {
        G.vertices.push_back(i);
        cin >> i;
    }while(i != "END");

    cin >> i1;

    do
    {
        cin >> i2;
        cin >> w;
        G.AddEdge(i1,i2,w);
        cin >> i1;
    }while(i1 != "END");

    G.PrintOut();
    cin >>num;

    do
    {
        if(num == 1)
        {
            cin >> vert1;
            if(G.FindVertex(vert1) == true)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }

        if(num == 2)
        {
            cin >> vert1;
            cin >> vert2;
            int temp = G.FindEdgeCost(vert1, vert2);
            cout << temp << endl;
        }

        if(num == 3)
        {
            cin >> vert1;
            cin >> vert2;
            int temp1 = G.IsReachable(vert1, vert2);
            cout << temp1 << endl;
        }

        cin >> num;
    }while(num != 0);
}
