// Question - In a given string, replace all occurrences of pi with 3.14

#include <bits/stdc++.h>
using namespace std;

void removePi(string s, int n, string &ans, int i = 0, bool start = false){
    if (i == n)
        return;
    
    if (start and s[i] == 'i'){
        // Replace pi
        ans.pop_back();
		ans += "3.14";
        start = false;
        removePi(s,n,ans,i+1,start);
    }
    else{
        if (s[i] == 'p')
            start = true;
        else
            start = false;
        
        // Continue with same letter
        ans += s[i];
        removePi(s,n,ans,i+1,start);
    }
}
