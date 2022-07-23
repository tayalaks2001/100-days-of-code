// Question - https://leetcode.com/problems/online-stock-span/

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int> > compare;
    StockSpanner() {
        compare.empty();
    }
    
    int next(int price) {
        int span = 1;
        while (!compare.empty() and compare.top().first <= price){
            span += compare.top().second;
            compare.pop();
        }
        compare.push(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
