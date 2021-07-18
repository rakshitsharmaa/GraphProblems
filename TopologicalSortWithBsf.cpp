#include<iostream>
using namespace std;
#include<list>
#include<map>
#include<queue>
class Graph
{
private:
    list<int> *adjList;
    int V;
public:
    Graph(int V){
        this->V=V;
        adjList=new list<int>[V];
    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);
    }
    void TopologicalSort(){
        int *indegree=new int[V];
        for (int i = 0; i < V; i++)
       {
           indegree[i]=0;       
       }

       for (int i = 0; i < V; i++)
       {
            for (auto p : adjList[i])
            indegree[p]++;
       }
       queue<int> q;
       for (int i = 0; i < V; i++)
       {
           if (indegree[i]==0)
           {
               q.push(i);   
           } 
       }
       while (!q.empty())
       {
           int node=q.front();
           cout<<node<<" ";
           q.pop();
            for (auto nbr : adjList[node])
            {
                indegree[nbr]--;
                if (indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            } 
       }   
    }
};


int main(){
Graph g(6);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(1,4);
g.addEdge(2,3);
g.addEdge(2,5);
g.addEdge(3,5);
g.addEdge(4,5);
g.TopologicalSort();

}