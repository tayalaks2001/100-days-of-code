// Question - https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = 0;
        for (int n : nums){
            bits |= bits<<n;
            sum += n;
        }
        return (sum%2==0) and (bits[sum/2]);
    }
