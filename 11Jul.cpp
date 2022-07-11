// Question - https://leetcode.com/problems/palindromic-substrings/

#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
        int ans = 0;
        for (int mid = 0; mid < s.size(); mid++){
            int st = mid, e = mid;
            while (st >= 0 and e < s.size() and s[st] == s[e]){
                ans++;
                st--, e++;
            }
            st = mid, e = mid+1;
            while (st >= 0 and e < s.size() and s[st] == s[e]){
                ans++;
                st--, e++;
            }
        }
        return ans;
    }
