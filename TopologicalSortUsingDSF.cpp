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
    }

    void DFS_Helper(T src,map<T,bool> &visited,list<T> &ordering){
        visited[src]=true;
        
        for (auto p : adjList[src])
        {
            if (!visited[p])
            {
                DFS_Helper(p,visited,ordering);
            }   
        }  
        ordering.push_front(src); 

    }

    void DFS(){
        map<T,bool> visited;
        for (auto p : adjList)
        {
            visited[p.first]=false;
        }
        list<T> ordering;
        for (auto p : adjList)
        {
            if (!visited[p.first])
            {
                DFS_Helper(p.first,visited,ordering);
            }   
        }    
        for (auto i : ordering)
        {
            cout<<i<<endl;
        }
        
    }
};

int main(){
Graph<string> g;
g.addEdge("python","pytorch");
g.addEdge("python","data processing");
g.addEdge("python","ML");
g.addEdge("data processing","ML");
g.addEdge("pytorch","DL");
g.addEdge("ML","DL");
g.addEdge("DL","face recogination");
g.addEdge("data set","face recogination");
g.DFS();
}