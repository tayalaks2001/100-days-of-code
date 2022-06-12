// Question - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int minm = INT_MAX;
        while (start <= end){
            int mid = (start+end)/2;
            if (nums[mid] < minm)
                minm = nums[mid];
            
            if (nums[mid] > nums[end])
                start = mid+1;
            else
                end = mid-1;
            
        }
        
        return minm;
     }
