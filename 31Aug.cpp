// Question - Minimum spanning tree - implementation for Kruskal's and Prim's algos

#include<bits/stdc++.h>
using namespace std;

class Edge {

public:

    int a,b,wt;

    Edge(int a, int b, int wt){
        this->a = a;
        this->b = b;
        this->wt = wt;
    }

    // bool operator<(const Edge e) {
    //     return (wt < e.wt);
    // }

    // bool operator>(const Edge e) {
    //     return (wt > e.wt);
    // }
};

bool operator< (const Edge e1, const Edge e2){
    return e1.wt < e2.wt;
}

bool operator== (const Edge e1, const Edge e2){
    return e1.a==e2.a and e1.b==e2.b and e1.wt==e2.wt;
}

class Graph {

public:

    int v;
    unordered_map<int,vector<pair<int,int> > > m;
    vector<Edge> edgeList;

    Graph(int v){
        this->v = v;
    }

    void addEdge(int a, int b, int wt){
        m[a].push_back({b,wt});
        m[b].push_back({a,wt});
        edgeList.push_back(Edge(a,b,wt));
    }

    int totalEdgeWeight(){
        int totalWt = 0;
        for (Edge e : edgeList){
            totalWt += e.wt;
        }
        return totalWt;
    }

    void printGraphI(){
        for (auto edge : edgeList){
            cout<<"Edge between "<<edge.a<<" and "<<edge.b<<" having weight "<<edge.wt<<endl;
        }
        cout<<endl;
    }

    void printGraphII(){
        for (int i=1; i<=v; i++){
            for (pair<int,int> p : m[i]){
                cout<<"Edge between "<<i<<" and "<<p.first<<" having weight "<<p.second<<endl;
            }
        }
        cout<<endl;
    }
};

class DSU {
    int v;
    vector<int> parent;

public:

    DSU(int v){
        this->v = v;
        parent = vector<int> (v,-1);
    }

    int find(int child){
        if (parent[child] == -1)
            return child;

        return parent[child] = find(parent[child]);
    }

    bool union_set(int n1, int n2){
        int s1 = find(n1), s2 = find(n2);

        if (s1 != s2){
            parent[s2] = s1; 
            return true;
        }

        return false;
    }
};


Graph kruskalMST(Graph g){
    if (g.v <= 2)
        return g;

    Graph mst(g.v);
    vector<Edge> edgeListCopy(g.edgeList.begin(), g.edgeList.end());
    sort(edgeListCopy.begin(), edgeListCopy.end());

    DSU dsu(g.v);
    for (Edge e : edgeListCopy){
        if (dsu.union_set(e.a, e.b)){
            mst.addEdge(e.a, e.b, e.wt);
        }
    }

    return mst;
}

Graph primsMST(Graph g){
    if (g.v <= 2)
        return g;

    Graph mst(g.v);
    multiset<Edge> activeEdges;
    unordered_set<int> visited;

    visited.insert(1);
    for (pair<int,int> p : g.m[1]){
        activeEdges.insert(Edge(1,p.first,p.second));
    }

    while (!activeEdges.empty()){
        Edge e = *activeEdges.begin();
        if (visited.find(e.b) == visited.end()){
            visited.insert(e.b);
            for (pair<int,int> p : g.m[e.b]){
                activeEdges.insert(Edge(e.b,p.first,p.second));
            }
            mst.addEdge(e.a, e.b, e.wt);
        }
        activeEdges.erase(activeEdges.begin());
    }

    return mst;
}

// alternative Prims MST implementation using DSU
Graph primsMSTII(Graph g){
    if (g.v <= 2)
        return g;

    Graph mst(g.v);
    multiset<Edge> activeEdges;
    unordered_set<int> visited;

    visited.insert(1);
    for (pair<int,int> p : g.m[1]){
        activeEdges.insert(Edge(1,p.first,p.second));
    }

    DSU dsu(g.v);

    while (!activeEdges.empty()){
        Edge e = *activeEdges.begin();
        if (dsu.union_set(e.a,e.b)){
            mst.addEdge(e.a, e.b, e.wt);
            for (pair<int,int> p : g.m[e.b]){
                activeEdges.insert(Edge(e.b,p.first,p.second));
            }
        }
        activeEdges.erase(activeEdges.begin());
    }

    return mst;
}

int main(){
    Graph g(5);
    g.addEdge(1,2,1);
    g.addEdge(3,4,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(4,5,6);
    g.addEdge(2,3,2);
    g.addEdge(2,4,1);
    g.printGraphI();
    Graph mst = primsMST(g);
    mst.printGraphI();
    cout<<"weight of edges in MST: "<<mst.totalEdgeWeight()<<endl;


    return 0;
}
