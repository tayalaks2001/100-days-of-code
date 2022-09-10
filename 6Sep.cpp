// Question - https://leetcode.com/problems/graph-valid-tree/submissions/\

#define vi vector<int>
#define vb vector<bool>
class Solution {
public:
    vi parent;
    
    int find(int n){
        while (parent[n] != -1)
            n = parent[n];
        return n;
    }
    
    bool unionSet(int n1, int n2){
        int s1 = find(n1), s2 = find(n2);
        if (s1==s2)
            return false;
        parent[s2] = s1;
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n,-1);
        for (auto e : edges){
            if (!unionSet(e[0],e[1]))
                return false;
        }
        int count = 0;
        for (int i : parent){
            if (i == -1)
                count++;
        }
        return count==1;
    }
};
