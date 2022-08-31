// Question - Disjoint Set Union implementation

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
 
