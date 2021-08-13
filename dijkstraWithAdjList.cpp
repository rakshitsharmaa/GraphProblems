#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
private:
    map < T, list<pair<T, int> >> adjList;
public:
    void addEdge(T u, T v, int wt) {
        adjList[u].push_back(make_pair(v, wt));
        adjList[v].push_back(make_pair(u, wt));
    }

    void PrintAdjList() {
        for (auto node : adjList) {
            T key = node.first;
            cout << key << "->";
            for (auto l : node.second) {
                cout << "(" << l.first << ", " << l.second << ")";
            }
            cout << endl;
        }
    }
    void DijkstraSSSP(T src) {
        unordered_map<T, int> dist;
        for (auto a : adjList) {
            dist[a.first] = INT_MAX;
        }
        set < pair<int, T> >s; //int first bcoz sorting in set is in accordance with first element
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty()) {
            auto p = *(s.begin()); //s.begin() will give the pointer pointing to begining but * will give the value
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //itterate over the childeren of the current node
            for (auto child : adjList[node]) {
                if (nodeDist + child.second < dist[child.first]) {
                    //in set/priority queue updation is not possible
                    //so we deleate the old object and insert a new one
                    auto f = s.find({dist[child.first], child.first});
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    dist[child.first] = nodeDist + child.second;
                    s.insert({dist[child.first], child.first});

                }
            }

        }
        for (auto d : dist) {
            cout << d.first << "->" << d.second << endl;
        }
    }

};



int main() {
    Graph<int> g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 8, 6);
    g.addEdge(1, 2, 8);
    g.PrintAdjList();
    g.DijkstraSSSP(0);
}