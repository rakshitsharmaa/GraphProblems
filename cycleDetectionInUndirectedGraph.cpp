#include<iostream>
using namespace std;
#include<list>
#include<queue>

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
    void addEdge(int u,int p){
        adjList[u].push_back(p);
        adjList[p].push_back(u);
    }
    bool containCycleHelper(int src,bool *visited,int parent){
        visited[src]=true;
        for (auto nbr : adjList[src])
        {
           if(!visited[nbr])
            {
                bool mila_kya=containCycleHelper(nbr,visited,src);
                if (mila_kya)
                {
                    return true;
                }
            }
            else  if (visited[nbr]&&parent!=nbr)
            {
                return true;
            }
        } 
        return false;
    }
    bool containCycle(){
        bool *visited=new bool[v];
        int parent=-1;
        for (int i = 0; i < v; i++)
        {
            visited[i]=false;
        }
        
        return containCycleHelper(0,visited,parent);
    }
};




int main(){
Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    if (g.containCycle())
    {
        cout<<"cycle found"<<endl;
    }
    else
    cout<<"no cycle found"<<endl;
}