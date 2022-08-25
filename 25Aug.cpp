// Question - https://leetcode.com/problems/house-robber-ii/

vector<int> dp;
    
    int helper(vector<int> &nums, int i){
        if (i == nums.size())
            return 0;
        
        if (dp[i] != -1)
            return dp[i];    
    
        if (i == nums.size()-1)
            return nums[i];
        
        return dp[i] = max(nums[i] + helper(nums,i+2), helper(nums,i+1));
    }
    
    int rob(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        dp = vector<int> (nums.size(),-1);
        dp[nums.size()-1]= 0;
        int m1 = helper(nums,0);
        dp = vector<int> (nums.size(),-1);
        int m2 = helper(nums,1);
        return max(m1,m2);
    }
