#include<bits/stdc++.h>
using namespace std;

// Question - You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

int maxCircularSum(int n, vector<int> a){
	int maxSum = INT_MIN;
	for (int i=0; i<n-1; i++)
		a.push_back(a[i]);
	
	for (int i=1; i<2*n-1; i++)
		a[i] += a[i-1];
	
	for (int i=0; i<n; i++){
		for (int j=i; j<i+n; j++){
			int s = a[j];
			if (i != 0)
				s -= a[i-1];
			maxSum = max(maxSum, s);
		}
	}

	return maxSum;
}

