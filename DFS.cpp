#include<iostream>
using namespace std;
#include<map>
#include<list>

template<typename T>
class Graph
{
private:
    map<T,list<T>> adj;

public:
    void addEdge(T x,T y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void DFS_Helper(T src,map<T,bool> &visited){
        cout<<src<<" ";
         visited[src]=true;
         for (auto nbr : adj[src])
         {
             if (!visited[nbr])
             {
                 DFS_Helper(nbr,visited);
             }   
         }
    }

    void DFS(T src){
        map<T,bool> visited;
        for (auto p : adj)
        {
            T node =p.first;
            visited[node]=false;
        }      
        DFS_Helper(src,visited);  
    }
};
int main(){
    Graph<int> g;
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
    g.DFS(0);
}