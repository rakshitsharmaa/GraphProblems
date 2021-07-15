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
    void bsfShortestPath(int src,int destination){
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        q.push(src);
        visited[src]=true;
        int *parent=new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i]=-1;
        }   
        while (!q.empty())
        {
            int node= q.front();
            q.pop();
            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }   
            }   
        } 
         cout<<dist[destination]<<endl;
         int temp=destination;
         while (temp!=-1)
         {
             cout<<temp<<"<-";
             temp=parent[temp];
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
    g.bsfShortestPath(1,4);
}