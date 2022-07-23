// Question - https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

vector<int> countTowers(vector<int> heights){
        vector<int> res(heights.size(),1);
        stack<pair<int,int>> compare({{heights[0],1}});

        for (int i = 1; i < heights.size(); i++){
            while (!compare.empty() and compare.top().first >= heights[i]){
                res[i] += compare.top().second;
                compare.pop();
            }
            compare.push({heights[i],res[i]});
        }

        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = countTowers(heights);
        reverse(heights.begin(), heights.end());
        vector<int> right = countTowers(heights);
        int maxArea = INT_MIN, n = heights.size();
        for (int i=0; i<n; i++){
            int totalCount = right[i]+left[n-i-1]-1;
            maxArea = max(heights[i]*totalCount, maxArea);
        }
        reverse(heights.begin(), heights.end());
        return maxArea;
    }
