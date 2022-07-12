// Question - https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++; 
			int maxend = end;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step;
				maxend = max(maxend, i + nums[i]);
			}
            start = end + 1;
            end = maxend;
        }
		return step;
    }
