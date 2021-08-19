#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
class DSU
{
private:
    int *parent;
    int *rank;
public:
   DSU(int n){
       parent=new int[n];
       rank=new int[n];
       for (int i = 0; i < n; i++)
       {
           rank[i]=1;
           parent[i]=-1;
       }
   }
       int findSet(int i){
           if(parent[i]==-1)
           return i;

           return parent[i]=findSet(parent[i]);
       }

       void Unite(int x,int y){
           int s1=findSet(x);
           int s2=findSet(y);
           if (rank[s1]>rank[s2])
           {
               parent[s2]=s1;
               rank[s1]+=rank[s2];
           }else{
               parent[s1]=s2;
               rank[s2]+=rank[s1];
           }   
       }
};

class Graph
{
private:
    vector<vector<int> > edgeList;
    int V;
public:
    Graph(int V){
        this->V=V;
    }
    void addEdge(int x,int y,int w){
        edgeList.push_back({w,x,y});
    }

    int KruksalMst(){
        sort(edgeList.begin(),edgeList.end());
        int ans=0;
        DSU s(V);
        for (auto edge : edgeList)
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(s.findSet(x)!=s.findSet(y)){
                s.Unite(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.KruksalMst();

}