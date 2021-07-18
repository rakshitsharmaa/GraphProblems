#include<iostream>
using namespace std;
#include<queue>
#include<list>
class Graph
{
private:
    list<int> *adjList;
    int v; 
public:
    Graph(int v){
        this->v=v;
        adjList=new list<int>[v];
    }
    void addEdge(int u,int p,bool directional=true){
        if(directional)
        adjList[u].push_back(p);
    }
    bool containCycleHelper(int src,bool *visited,bool *stack){
        visited[src]=true;
        stack[src]=true;
        for (auto nbr : adjList[src])
        {
            if(stack[nbr]){
                return true;
            }
           else if (!visited[nbr])
            {
              bool cycle_mila_kya=containCycleHelper(nbr,visited,stack);
                if (cycle_mila_kya)
                {
                    return true;
                }
            }
        }
        stack[src]=false;
        return false;
    }
    bool containCycle(){
        bool *visited=new bool[v];
        bool *stack=new bool[v];
        for (int  i = 0; i < v; i++)
        {
            visited[i]=stack[i]=false;
        }
        
        return containCycleHelper(0,visited,stack);
    }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
     g.addEdge(4,2);
    if (g.containCycle())
    {
        cout<<"cycle found"<<endl;
    }
    else
    cout<<"no cycle is found"<<endl;
    
}

