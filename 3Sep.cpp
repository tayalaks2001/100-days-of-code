// Question - https://leetcode.com/problems/set-mismatch/


// Interesting solution - constant size complexity
vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        
        for (int i=0; i<nums.size(); i++){
            int n = abs(nums[i])-1;
            if (nums[n] < 0){
                res.push_back(n+1);
            }
            else
                nums[n] *= -1;
        }
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > 0){
                res.push_back(i+1);
                break;
            }
        }
        
        return res;
    }
