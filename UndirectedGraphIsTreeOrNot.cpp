#include<iostream>
using namespace std;
#include<list>
#include<queue>
class Graph
{
private:
    list<int> *adjlist;
    int V;
public:
    Graph(int v){
        adjlist=new list<int>[v];
        V=v;
    }
    void addEdge(int u,int p){
        adjlist[u].push_back(p);
        adjlist[p].push_back(u);
    }
    bool isTree(){
        bool *visited=new bool[V];
        int *parent=new int[V];
       
        for (int i = 0; i < V; i++)
        {
            parent[i]=i;
            visited[i]=false;
        }
         queue<int> q;
        int src=0;
        q.push(src);
        visited[src]=true;
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            for (auto nbr : adjlist[node])
            {
                if (visited[nbr]&&parent[node]!=nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push(nbr);
                    parent[nbr]=node;
                }
            }
        }
        return true;
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    if (g.isTree())
    {
        cout<<"it is a tree"<<endl;
    }
    else
    cout<<"it is not a  tree"<<endl;
    
}