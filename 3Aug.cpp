// Question - https://codeforces.com/contest/1713/problem/B

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int prev = INT_MIN, curr;
        bool increasing = true;
        bool isMinPermutation = true;
        for (int i=0; i<n; i++){
            cin>>curr;
            if (curr > prev){
                if (!increasing){
                    // break
                    isMinPermutation = false;
                }
            }
            else if (curr < prev){
                increasing = false;
            }
            prev = curr;
        }
        if (isMinPermutation)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
 
    return 0;
}

