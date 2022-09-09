// Question - https://leetcode.com/problems/number-of-islands/

#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>

class Solution {
public:
    int helper(vvc& grid, vvb &visited, int i, int j, int m, int n){
        if (i<0 or j<0 or i >= m or j >= n or visited[i][j])
            return 0;
        
        visited[i][j] = true;
        if (grid[i][j] == '0')
            return 0;
        helper(grid,visited,i+1,j,m,n);
        helper(grid,visited,i,j+1,m,n);
        helper(grid,visited,i-1,j,m,n);
        helper(grid,visited,i,j-1,m,n);
        return 1;
    }
    
    int numIslands(vvc& grid) {
        int m = grid.size(), n = grid[0].size();
        vvb visited(m, vector<bool>(n,false));
        int count = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!visited[i][j]){
                    count += helper(grid,visited,i,j,m,n); 
                }
            }
        }
        return count;
    }
};
