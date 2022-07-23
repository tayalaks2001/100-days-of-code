// Question - reverse stack using one extra stack

#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int>& s){
    stack<int> temp;
    int n = s.size()-1;
    while (n > 0){
        int t = s.top();
        s.pop();
        for (int i = 0; i < n; i++){
            int val = s.top();
            s.pop();
            temp.push(val);
        }
        s.push(t);
        for (int i = 0; i < n; i++){
            int val = temp.top();
            temp.pop();
            s.push(val);
        }
        n--;
    }
}
