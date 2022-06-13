// Question - https://leetcode.com/problems/continuous-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0){
            cout<<"error, invalid input!"<<endl;
            return false;
        }
        
        if (nums.size() < 2)
            return false;
        
        unordered_map<int, int> mods;
        mods[0] = -1;
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            sum = sum%k;
            
            if (mods.find(sum) != mods.end()) {
                if (i-mods[sum] > 1)
                    return true;
            }
            else
                mods[sum] = i;
        }
        
        return false;
    }

