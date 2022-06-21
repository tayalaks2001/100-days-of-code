#include<bits/stdc++.h>
using namespace std;

// Question - https://leetcode.com/problems/furthest-building-you-can-reach/

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (ladders >= heights.size()-1)
            return heights.size()-1;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while (ladders > 0){
            if (i == heights.size()-1)
                return heights.size()-1;
            
            if (heights[i+1] > heights[i]){
                pq.push(heights[i+1]-heights[i]);
                ladders--;
            }
            i++;
        }
        
        for (; i<heights.size()-1; i++){
            int jump = heights[i+1] - heights[i];
            
            if (jump < 0)
                continue;
            
            if (!pq.empty() and jump > pq.top()){
                bricks -= pq.top();
                pq.pop();
                pq.push(jump);
                if (bricks < 0)
                    return i;
            }
            else if (bricks >= jump){
                bricks -= jump;
            }
            else
                return i;
        }
        
        return heights.size()-1;
    }


