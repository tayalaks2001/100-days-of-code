// Question - https://leetcode.com/problems/magnetic-force-between-two-balls/ 

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int>& position, int n, int k, int gap){
        int pos = position[0], filled = 1;
        for (int i=1; i<n; i++){
            if (position[i]-pos >= gap){
                filled++;
                pos = position[i];
            }

            if (filled == k)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 1, e = (position[n-1]-position[0])/(m-1);
        int ans = 0;
        while (s <= e){
            int mid = (s+e)/2;
            if (isFeasible(position,n,m,mid)){
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
        
        return ans;
    }
