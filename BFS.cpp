#include<iostream>
using namespace std;
#include<list>
#include<queue>
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
    void BSF(int src){
        queue<int> q;
        bool *visited= new bool[V+1]{0};
        q.push(src);
        visited[src]=true;
        while (!q.empty())
        {
            int node = q.front();
            cout<<node<<"->";
            q.pop();
            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }   
            }
        }   
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.PrintAdjList();
    g.BSF(2);



}