// Question - https://online.codingblocks.com/app/player/209990/content/189054/5298/code-challenge

// Problem statement - Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

#include<bits/stdc++.h>
#define p pair<int,int>
using namespace std;

class Graph {
    unordered_map<int,unordered_set<int> > m;

public:

    Graph(int n){
        for (int i=1; i<=n; i++){
            int lim = min(n,i+6);
            for (int j=i+1; j<=lim; j++){
                m[i].insert(j);
            }
        }
    }

    void addSnakesAndLadders(vector<p> snakes, vector<p> ladders){
        for (p combo : snakes){
			m[combo.first].clear();
			m[combo.first].insert(combo.second);
        }
        for (p combo : ladders){
            int lim = max(1,combo.first-6);
            for (int start=lim; start<combo.first; start++)
                m[start].insert(combo.second);
			m[combo.first].clear();
			m[combo.first].insert(combo.second);
        }
    }

    int bfs(int source, int dest){
        unordered_map<int,int> dist;
        for (int i=source+1; i<=dest; i++)
            dist[i] = INT_MAX;
        dist[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (int i : m[node]){
				if (dist[i] == INT_MAX){
					q.push(i);
				}
				dist[i] = min(dist[i], dist[node] + 1);
            }
        }

        return dist[dest];
    }

	void printGraph(){
		for (auto i : m){
			cout<<i.first<<": ";
			for (int j : i.second){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}

};

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,l,s;
        cin>>n>>l>>s;
        Graph g(n);
        vector<p> snakes(s);
        vector<p> ladders(l);
        for (int i=0; i<l; i++){
            cin>>ladders[i].first>>ladders[i].second;
        }
        for (int j=0; j<s; j++){
            cin>>snakes[j].first>>snakes[j].second;
        }
        g.addSnakesAndLadders(snakes,ladders);
		// g.printGraph();
        cout<<g.bfs(1,n)<<endl;
    }
    return 0;
}
