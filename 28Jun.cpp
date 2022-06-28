// Question - 

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int ar[], int n, int k, int gap){
	int pos = ar[0], filled = 1;
	for (int i=1; i<n; i++){
		if (ar[i]-pos >= gap){
			filled++;
			pos = ar[i];
		}

		if (filled == k)
			return true;
	}

	return false;
}

int main() {
	int n,k;
	cin>>n>>k;
	int ar[n];
	for (int i=0; i<n; i++)
		cin>>ar[i];
	sort(ar, ar+n);
	
	int s = 1, e = (ar[n-1]-ar[0])/(k-1);
	int ans = 0;
	while (s <= e){
		int m = (s+e)/2;
		if (isFeasible(ar,n,k,m)){
			ans = m;
			s = m+1;
		}
		else
			e = m-1;
	}
	
	cout<<ans;
	return 0;
}
