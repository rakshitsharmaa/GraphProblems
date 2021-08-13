#include<iostream>
using namespace std;
#include<map>
#include<list>
#include<string>
#include<vector>
#include<string.h>
#include<set>
void Dijkstra(int src,vector<int> dist,bool *visited,vector<int> *adj,vector<int> *wt){
    memset(visited,false,sizeof(visited));
    dist[src]=0;
    set<pair<int,int>> s;
    s.insert(make_pair(0,src));
    while (!s.empty())
    {
        auto p=*(s.begin());
        s.erase(s.begin());
        int node=p.second;
        int disance=p.first;
        for(auto child:adj[p.second]){
            if(dist[child]>disance+wt[node][child]){
                auto f=s.find(make_pair(dist[child],child));
                if (f!=s.end())
                {
                    s.erase(f);
                }
                
                dist[child]=disance+wt[node][child];
                s.insert(dist[child],child);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        map<string,int> m;
        int n;
        string s,s1,s2;
        cin>>n;
        vector<int> dist;
        bool visited[n];
       vector<int> adj[n+1];
        vector<int> wt[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin>>s;
            dist[i]=INT_MAX;
            int connections;
            cin>>connections;
            m.insert(make_pair(s,i));
            for (int j = 0; j < connections; j++)
            {
                int a,b;
                cin>>a>>b;
                adj[i].push_back(a);
                wt[i].push_back(b);
            }
        }
        int k;
        cin>>k;
        for(int l=0;l<k;l++){
            cin>>s1>>s2;
            Dijkstra(m[s1],dist,visited,adj,wt);
            cout<<dist[m[s2]]<<endl;
        }   
}
}
