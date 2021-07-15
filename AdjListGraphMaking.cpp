#include<iostream>
using namespace std;
#include<list>


class Graph
{
private:
    list<int> *adj;
    int V;
public:
    Graph(int v){
        V=v;
        adj = new list<int>[v];
    }
    void addEdge(int u,int p){
        adj[u].push_back(p);
        adj[p].push_back(u);
    }
    void PrintAdjList(){
        for (int i = 0; i < V; i++)
        {
            cout<<i<<"->";
            for (auto node : adj[i])
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
        
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(4,1);
    g.addEdge(3,1);
    g.addEdge(1,1);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.PrintAdjList();


}