// Question - https://leetcode.com/problems/maximum-swap/

#include<bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
        vector<int> digs;
        vector<pair<int,int>> maxBefore(1, make_pair(INT_MIN, -1));
        
        int pos = 0;
        while (num > 0){
            int dig = num%10;
            digs.push_back(dig);
            if (pos > 0){
                if (maxBefore[pos-1].first >= digs[pos-1]){
                    maxBefore.push_back(maxBefore[pos-1]);
                }
                else{
                    maxBefore.push_back(make_pair(digs[pos-1], pos-1));   
                }
            }
            num /= 10;
            pos++;
        }
        
        for (int i=digs.size()-1; i>0; i--){
            if (digs[i] < maxBefore[i].first){
                digs[maxBefore[i].second] = digs[i];
                digs[i] = maxBefore[i].first;
                break;
            }
        }
        
        int ans = 0;
        for (int i=digs.size()-1; i>=0; i--){
            ans *= 10;
            ans += digs[i];
        }
        return ans;
    }
