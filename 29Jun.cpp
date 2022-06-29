// Question - https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int search_helper(vector<int> nums, int l, int r, int target){
    if (l <= r){
        int mid = (l+r)/2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[l] <= nums[mid]){
            if (nums[mid] > target and target >= nums[l]){
                return search_helper(nums,l,mid-1,target);
            }
            else{
                return search_helper(nums, mid+1,r,target);
            }
        }
        else{
            if (nums[mid] < target and target <= nums[r]){
                return search_helper(nums, mid+1,r,target);
            }
            else{
                return search_helper(nums,l,mid-1,target);
            }
        }
    }
    else
        return -1;
}

int search(vector<int>& nums, int target) {
    int ans = search_helper(nums,0,nums.size()-1,target);
    return ans;
}