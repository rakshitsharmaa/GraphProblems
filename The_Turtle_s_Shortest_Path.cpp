// #include<iostream>
// using namespace std;
// #include<vector>
// #include<map>
// #include<set>
// vector<int> adj[100005];
// int dist[100005];
// vector<int> wt[1000005];
// set<pair<int,int>> s;
// void Initialize(int src,int n){
// for (int i = 0; i < n; i++)
// {
//     dist[i]=INT_MAX;
// }
// }
// void dijkstra(int src){

    
//     dist[src]=0;
//     s.insert(make_pair(dist[src],src));
//     while (!s.empty())
//     {
//         auto node=*(s.begin());
//         int distt=node.first;
//         int p=node.second;
//         s.erase(s.begin());
//         for(auto nbr:adj[p]){
//             if (dist[nbr]>dist[p]+wt[p][nbr])
//             {
//                 auto f=s.find(make_pair(dist[nbr],nbr));
//                 if (f!=s.end())
//                 {
//                     s.erase(f);
//                 }
                
//                 dist[nbr]=dist[p]+wt[p][nbr];
//                 s.insert(make_pair(dist[nbr],nbr));
//             }
            
//         }
//     }
    
// }

// void solve(){
// int n;
// cin>>n;
// map<string,int> m;
// for (int i = 0; i < n; i++)
// {
//     string s;
//     cin>>s;
//     m[s]=i;
//     int nbr;
//     cin>>nbr;
//     for (int j = 0; j < nbr; j++)
//     {
//         int p,q;
//         cin>>p>>q;
//         adj[i].push_back(p-1);
//         wt[i].push_back(q);
//     }
    
// }
// int r;
//     cin>>r;
//     for (int i = 0; i < r; i++)
//     {
//         string s1,s2;
//         cin>>s1>>s2;
//         Initialize(m[s1],n);
//         dijkstra(m[s1]);
//         cout<<dist[m[s2]]<<endl;
//     }
//     for (int i = 0; i < 100005; i++)
//     {
//         adj[i].clear();
//         wt[i].clear();
//     }
    
// }
// int main(){
//     int t;
//     cin>>t;
//     while (t--)
//     {
//         solve();
//     }
    
// }



#include <iostream>
using namespace std;
#include<map>
#include<vector>
#include<set>
#define maxV 100005
vector<int> adj[maxV];
vector<int> wt[maxV];
int dist[maxV];
set<pair<int,int>> sett;
void Initialize(int src,int n){
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
}
void relax(int node){
	for(int i=0;i<adj[node].size();i++){
		if(dist[adj[node][i]]>wt[node][i]+dist[node]){
            auto f=sett.find(make_pair(dist[adj[node][i]],adj[node][i]));
            if(f!=sett.end()){
                sett.erase(f);
            }
			dist[adj[node][i]]=wt[node][i]+dist[node];
            sett.insert(make_pair(dist[adj[node][i]],adj[node][i]));
		}
	}
	
}
void Dijkstra(int src){
	dist[src]=0;
	
	sett.insert(make_pair(dist[src],src));
	
	
	while(!sett.empty()){
		auto node=*(sett.begin());
		sett.erase(sett.begin());
		relax(node.second);
	}
}
void solve(){
	int n,a,b,k;
	string s1,s2;
	cin>>n;
	map<string,int> m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		m[s]=i;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>b;
			adj[i].push_back(a-1);
			wt[i].push_back(b);
		}
	}
	int p;
	cin>>p;
	for(int i=0;i<p;i++){
		cin>>s1>>s2;
		Initialize(m[s1],n);
		Dijkstra(m[s1]);
		cout<<dist[m[s2]]<<endl;
	}
	for(int i=0;i<n;i++){
		adj[i].clear();
		wt[i].clear();
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}