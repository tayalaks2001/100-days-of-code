// Question - Count of connected components in undirected graph

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    unordered_map<int,vector<int> > m;

public:

    Graph(int v){
        this->v = v;
    }

    void addEdge(int a, int b){
        m[a].push_back(b);
        m[b].push_back(a);
    }

    void bfs(int src, vector<bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()){
            int node = q.front();
            visited[node] = true;

            for (int nbr : m[node]){
                if (!visited[nbr]){
                    q.push(nbr);
                }
            }

            q.pop();
        }
    }

    int connectedComponents(){
        vector<bool> visited(v+1, false);
        int cc = 0;
        for (int i=1; i<=v; i++){
            if (!visited[i]){
                bfs(i,visited);
                cc++;
            }
        }
        return cc;
    }
};
