
// Question - https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target = 0) {
     	vector<vector<int>> result;
        result.clear();
        
        if (nums.size() < 3)
            return result;
        
        
        int one = 0, two = 0, three = 0;
        int prevOne = INT_MIN, prevTwo = INT_MIN;
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++){
            one = nums[i];
            if (one == prevOne)
                continue;
            
            int start = i+1, end = nums.size()-1;
            while (start < end){
                two = nums[start], three = nums[end];
                if (one == prevOne and two == prevTwo){
                    start++;
                    continue;
                }
                int sum = one + two + three;
                if (sum == target){
                    vector<int> ele;
                    ele.push_back(one);
                    ele.push_back(two);
                    ele.push_back(three);
                    result.push_back(ele);
                    
                    prevOne = one, prevTwo = two;
                    start++;
                    end--;
                }
                else if (sum > target)
                    end--;
                else
                    start++;
            }
        }
        
        return result;
    }
