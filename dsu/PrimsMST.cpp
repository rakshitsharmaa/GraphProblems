#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Graph
{
private:
    //array of vectors of pair of int int
    vector<pair<int,int> > *l;
    int V;
public:
    Graph(int V){
        this->V=V;

    }
    void addEdge(int x,int y,int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int primMST(){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;


        bool *visited=new bool[V]{0};
        int ans=0;

        q.push({0,0});
        while (!q.empty())
        {
            auto best=q.top();
            q.pop();

            int to = best.second;
            int weight = best.first;
            if(visited[to]){
                continue;
            }
            ans+=weight;
            visited[to]=1;
            for (auto x : l[to])
            {
                if (visited[x.first]==0)
                {
                    q.push({x.second,x.first});
                }
                
            }
            
        }
        
        return ans;

    }

};





int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.primMST()<<endl;
    
}