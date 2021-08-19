#include<iostream>
using namespace std;
#include<list>


class Graph
{
private:
    int V;
     list<pair<int ,int>> l;
public:
    Graph(int V){
        this->V=V;
       
    };
    void addEdge(int u,int v){
        l.push_back(make_pair(u,V));
    }
    int findSet(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=findSet(parent[i],parent);
    }

    void Union_set(int x,int y,int rank[],int parent[]){
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);
        if(rank[s1]>rank[s2]){
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }else{
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
    }
    int UnlinkedCities(){
        int parent[V];
        int rank[V];
        for (int  i = 0; i < V; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        for (auto edge : l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=findSet(i,parent);
            int s2=findSet(j,parent);
            Union_set(s1,s2,rank,parent);

        }
        int ans=0;
        for (int i = 0; i < V; i++)
        {
            ans+=V-rank[findSet(i,parent)];
        }
       return ans/2; 
    }

};




int main(){



}