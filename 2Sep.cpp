// Question - https://codeforces.com/contest/1717/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        vector<int> b(n+1);

        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=0; i<n; i++)
            cin>>b[i];
        a[n] = a[0];
        b[n] = b[0];
        bool can = true;
        for (int i=0; i<n; i++){
            if (a[i] > b[i]){
                can = false;
                break;
            }
            if (a[i] < b[i] and b[i] > (b[i+1]+1)){
                can = false;
                break;
            }
        }
        if (can)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}

