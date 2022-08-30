// Question - https://leetcode.com/problems/course-schedule-ii/

class Graph {
    int v;
    vector<vector<int> > m;
    
public:
    
    Graph(int v){
        this->v = v;
        m = vector<vector<int> >(v, vector<int>(0));
    }
    
    void addEdge(int from, int to){
        m[from].push_back(to);
    }
    
    bool helper(int node, vector<bool> &visited, vector<bool> &stack, vector<int> &ordering){
        stack[node] = true;
        visited[node] = true;
        for (int child : m[node]){
            if (stack[child])
                return true;
            else if (!visited[child] and helper(child,visited,stack,ordering))
                return true;
        }
        stack[node] = false;
        ordering.push_back(node);
        return false;
    }
}; 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for (int i=0; i<prerequisites.size(); i++){
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);
        vector<int> ordering;
        
        for (int i=0; i<numCourses; i++){
            if (!visited[i]){
                if (g.helper(i,visited,stack,ordering))
                    return vector<int>(0);
            }
        }
        
        reverse(ordering.begin(), ordering.end());
        return ordering;
    }
};
