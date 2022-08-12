// Question - https://leetcode.com/problems/unique-binary-search-trees/

#include<bits/stdc++.h>
using namespace std;

int catalanNumber(int n, vector<int> &dp){
        if(dp[n] != 0)
            return dp[n];
        
        for (int i=0; i<n; i++){
            dp[n] += catalanNumber(i,dp)*catalanNumber(n-i-1,dp);
        }
        return dp[n];
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        return catalanNumber(n,dp);
    }
