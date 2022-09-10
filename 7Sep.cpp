// Question - https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Finding connected comps given edge list, using DSU

vector<int> parent;
    
    int find(int n){
        if (parent[n] == -1)
            return n;
        
        return parent[n] = find(parent[n]);
    }
    
    void unionSet(int n1, int n2){
        int s1 = find(n1), s2 = find(n2);
        if (s1 != s2){
            parent[s1] = s2;   
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n,-1);
        int count = 0;
        for (auto e : edges){
            unionSet(e[0],e[1]);
        }
        for (int p : parent){
            count += (p == -1);
        }
        return count;
    }
