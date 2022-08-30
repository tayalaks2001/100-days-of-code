// Question - Dijkstra's algorithm implementation

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    unordered_map<int,vector<pair<int,int> > > m;

public:

    Graph(int v){
        this->v = v;
    }

    void addEdge(int a, int b, int wt){
        m[a].push_back({b,wt});
        m[b].push_back({a,wt});
    }

    vector<int> dijkstra(int src){
        vector<int> dist(v+1,INT_MAX);
        set<pair<int,int> > visited;

        dist[src] = 0;
        visited.insert({0,src});

        while (!visited.empty()){
            int curr = visited.begin()->first;
            int node = visited.begin()->second;

            for(auto neighbor : m[node]){
                if (curr + neighbor.second < dist[neighbor.first]){
                    auto it = visited.find({dist[neighbor.first],neighbor.first});
                    if (it != visited.end()){
                        visited.erase(it);
                    }
                    dist[neighbor.first] = curr + neighbor.second;
                    visited.insert({dist[neighbor.first], neighbor.first});
                }
            }
            visited.erase(visited.begin());
        }

        return dist;
    }
};



int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        for (int i=0; i<m; i++){
            int a,b,wt;
            cin>>a>>b>>wt;
            g.addEdge(a,b,wt);
        }
        int src;
        cin>>src;
        vector<int> res = g.dijkstra(src);
        for (int i=1; i<=n; i++){
            if (i == src)
                continue;
            if (res[i] == INT_MAX)
                res[i] = -1;
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
