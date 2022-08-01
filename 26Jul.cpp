// Question - https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end){
            int mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            
            if (nums[start] < nums[end]){
                // sorted part
                if (target > nums[mid])
                    start = mid+1;
                else
                    end = mid-1;
            }
            else{
                // unsorted part
                if (target > nums[end]){
                    if (nums[mid] < nums[end]){
                        end = mid-1;
                    }
                    else{
                        end--;
                    }
                }
                else{
                    if (target > nums[mid]){
                        start = mid+1;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        
        return -1;
    }
