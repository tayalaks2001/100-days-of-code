// Question - https://codeforces.com/contest/1704/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<int> infected(m);
        for (int i=0; i<m; i++)
            cin>>infected[i];
        sort(infected.begin(), infected.end());
        multiset<int> gaps;
        for (int i=1; i<m; i++){
            gaps.insert(infected[i] - infected[i-1]-1);
        }
        gaps.insert(n-infected[m-1]+infected[0]-1);
        int countSaved = 0;
        int i = 1;
        for (auto rit = gaps.rbegin(); rit != gaps.rend(); rit++){
            int val = *rit;
            if (val - i == 0)
                countSaved++;
            if (val - i <= 0)
                break;
            countSaved += (val-i);
            i += 4;
        }
        int ans = n-countSaved;
        cout<<ans<<endl;
    }
    
    return 0;
}

