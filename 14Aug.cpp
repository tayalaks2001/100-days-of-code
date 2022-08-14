// Question - https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n+1,-1);
        for (int i : nums){
            if (res[i] == -1)
                res[i] = 0;
            else if (res[i] == 0)
                res[i] = 1;
        }
        int count = 0;
        for (int i=1; i<=n; i++){
            if (res[i] == 1)
                res[count++] = i;
        }
        res.erase(res.begin()+count, res.end());
        return res;
    }
