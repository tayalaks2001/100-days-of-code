// Question - https://codeforces.com/contest/1713/problem/C

#include <bits/stdc++.h>
#define MAX_N 100000
#define MAX_SQ 300000
using namespace std;
 
 
int main() {
    int lim = sqrt(MAX_SQ)+1;
    vector<int> squares(lim);
    for (int i=0; i<lim; i++){
        squares[i] = i*i;
    }
    vector<vector<int>> pairs(MAX_N, vector<int>(0));
    for (int i=0; i<MAX_N; i++){
        int start = lower_bound(squares.begin(), squares.end(), i) - squares.begin();
        for (int j = start; j<squares.size(); j++){
            if (i == 99998 and squares[j]-i == 0){
                cout<<"FOUND: "<<j<<squares[j]<<endl;
            }
            pairs[i].push_back(squares[j]-i);
        }
    }
 
    // int idx = find(pairs[99998].begin(), pairs[99998].end(), 0) - pairs[99998].begin();
    // cout<<pairs[99998].size()<<" "<<idx<<endl;
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<int> res(n,-1);
        bool impossible = false;
        for (int num = n-1; num >= 0; num--){
            if(res[num] != -1)
                continue;
            int idx = lower_bound(pairs[num].begin(), pairs[num].end(), n-1) - pairs[num].begin();
            if (idx == pairs[num].size())
                idx--;
            // if (num == 99998)
            //     cout<<idx<<" "<<pairs[num][idx]<<endl;
            while (idx >= 0 and pairs[num][idx] > n-1)
                idx--;
            // if (num == 99998)
            //     cout<<idx<<" "<<pairs[num][idx]<<endl;
            for (int i = idx; i >= 0; i--){
                if (res[pairs[num][i]] == -1){
                    res[num] = pairs[num][i];
                    res[pairs[num][i]] = num;
                    break;
                }
            }
            if (res[num] == -1){
                impossible = true;
                break;
            }
        }
        
        if (impossible){
            cout<<"-1"<<endl;
        }
        else{
            for (int i : res){
                cout<<i<<" ";
            }
            cout<<endl;
        }
 
        // cout<<"first ele: "<<res[0]<<endl;
        // cout<<sqrt(res[0])<<endl;
    }
 
    return 0;
}
