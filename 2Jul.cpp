#include<bits/stdc++.h>
using namespace std;

// Question - https://leetcode.com/problems/subarray-sums-divisible-by-k/

int subarraysDivByK(vector<int>& nums, int n) {
       unordered_map<int, int> mods;
        mods.clear();
        mods[0] = 1;
        nums[0] %= n;
        nums[0] += n;
        nums[0] %= n;
        mods[nums[0]] += 1;
        for (int i=1; i<nums.size(); i++){
            nums[i] %= n;
            nums[i] += n;
            nums[i] %= n;
            nums[i] += nums[i-1];
            nums[i] %= n;
            if (mods.find(nums[i]) != mods.end()){
                mods[nums[i]] += 1;
            }
            else{
                mods[nums[i]] = 1;
            }
        }

        int ans = 0;
        for (auto i : mods){
            int num = i.second;
            ans += num*(num-1)/2;
        }

        return ans; 
    }
