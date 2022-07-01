#include<bits/stdc++.h>
using namespace std;

// Question - https://leetcode.com/problems/single-number-iii/

vector<int> singleNumber(vector<int>& nums) {
        int xor_res = 0;
        int xorA = 0, xorB = 0;
        
        for (int i : nums){
            xor_res ^= i;
        }
        
        int pos = 0;
        while ((xor_res&1) == 0){
            xor_res >>= 1;
            pos++;
        }
        int mask = 1<<pos;
        for (int i : nums){
            if (i&mask)
                xorA ^= i;
            else
                xorB ^= i;
        }
        
        vector<int> res = {xorA, xorB};
        return res;
    }
