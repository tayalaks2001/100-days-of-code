// Question - 0/1 Knapsack

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int w){
	vector<vector<int> > dp(n+1, vector<int>(w+1,0));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=w; j++){
			if (weight[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				int val = dp[i-1][j-weight[i-1]] + value[i-1];
				dp[i][j] = max(val, dp[i-1][j]);
			}
		}
	}

	return dp[n][w];
}

int main() {
	int n,w;
	cin>>n>>w;
	vector<int> weight(n);
	vector<int> value(n);
	for (int i=0; i<n; i++){
		cin>>weight[i];
	}
	for (int i=0; i<n; i++){
		cin>>value[i];
	}

	cout<<knapsack(weight,value,n,w);
	return 0;
}
