#include<iostream>
using namespace std;
#include<string>
#include<list>
#include<map>
template<typename T>
class Graph
{
private:
    map<T,list<T>> adjList; //for weighted graph use map<T,list<pair<T,int>>>
public:
    Graph(){
    }
    void addEdge(T u,T v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void print(){
        for (auto row : adjList)
        {
            T key=row.first;
            cout<<key<<" ";
            for (auto element : row.second)
            {
                cout<<element<<",";
            }
            cout<<endl;   
        }
    }
};
int main(){
    Graph<string> g;
    g.addEdge("delhi","chandigarh");
    g.addEdge("delhi","mirzapur");
    g.addEdge("delhi","vasaipur");
    g.addEdge("delhi","Saharanpur");
    g.addEdge("delhi","Pandit deen dayal upadhaya");
    g.addEdge("delhi","Prayagraj");
    g.addEdge("delhi","srinagar");
    g.addEdge("delhi","baraMulla");
    g.print();
}