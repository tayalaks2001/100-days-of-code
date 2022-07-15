// Question - https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
using namepsace std;

bool isPredecessor(string wordA, string wordB){
        if (wordB.size() - wordA.size() != 1)
            return false;
        
        int i = 0, j = 0;
        bool foundMismatch = false;
        
        while (i < wordA.size() and j < wordB.size()){
            if (wordA[i] != wordB[j]){
                if (foundMismatch)
                    return false;
                foundMismatch = true;
                j++;
            }
            else
                i++, j++;
        }
        
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        vector<string> sorted[16];
        for (string w : words)
            sorted[w.length()-1].push_back(w);
        unordered_map<string,int> dp;
        int maxLen = 1;
        for (int i=1; i<16; i++){
            for (string s1 : sorted[i]){
                for (string s2 : sorted[i-1]){
                    if (isPredecessor(s2, s1)){
                        if (dp.find(s2) != dp.end()){
                            dp[s1] = max(dp[s1], dp[s2]+1);
                        }
                        else{
                            dp[s1] = max(dp[s1], 2);
                        }
                        maxLen = max(maxLen, dp[s1]);
                    }
                }
            }
        }
        return maxLen;
    }
