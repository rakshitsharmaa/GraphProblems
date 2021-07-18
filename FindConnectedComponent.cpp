#include<iostream>
using namespace std;
#include<map>
#include<list>
template<typename T>
class Graph
{
private:
    map<T,list<T>> adjList;
public:
    void addEdge(T u,T v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void Print(){
        for (auto node : adjList)
        {
            T element=node.first;
            cout<<element<<"->";
            for (auto l : node.second)
            {
                cout<<l<<" ";
            }   
            cout<<endl;
        }
    }
    void DFS_Helper(T node,map<T,bool> &visited){
        visited[node]=true;
        for (auto nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                DFS_Helper(nbr,visited);
            }
            
            
        }
        
    }
    void DFS_connectedComponentFinder(){
        map<T,bool> visited;
        for (auto node : adjList)
        {
            visited[node.first]=false;  
        }
        int counts=0;
        for (auto n : adjList)
        {
            if (!visited[n.first])
            {
                DFS_Helper(n.first,visited);
                counts++;
            }
            
        }
        cout<<counts<<endl;
        
    }
};





int main(){
Graph<int> g;
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(0,4);
g.addEdge(5,6);
g.addEdge(5,8);
g.addEdge(5,9);
g.addEdge(12,13);
g.addEdge(12,15);
g.addEdge(12,17);
g.addEdge(12,19);
g.addEdge(12,21);
g.addEdge(12,96);
// g.Print();
g.DFS_connectedComponentFinder();
}