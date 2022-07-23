// Question - recursively reverse a stack

#include<bits/stdc++.h>
using namespace std;

void reverseRec(stack<int>& s){
    if (s.empty())
        return;
    
    int t = s.top();
    s.pop();
    reverseRec(s);
    stack<int> temp;
    while (!s.empty()){
        int val = s.top();
        s.pop();
        temp.push(val); 
    }
    s.push(t);
    while (!temp.empty()){
        int val = temp.top();
        temp.pop();
        s.push(val);
    }
}
