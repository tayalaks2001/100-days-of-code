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

// attempt at O(n) solution - doesn't work
// Problem is because we limit the size to n while traversing, any unnecessary prefix limits till where we can go later
// Example -> 1 2 3 -4 1
// the prefix 1 2 3 -4 has sum positive, which is why i don't start new sum
// But if I did, I could get the array -> 1 1 2 3
// basically in this when size exceeds n, I just restart new count from current pos. This needs to change to start from the pos of the last negative number
int maxCircularSum2(int n, vector<int> a){
    for (int i=0; i<n-1; i++)
        a.push_back(a[i]);
    int cs = 0, ms = INT_MIN, currStart = 0;
    
    for (int i=0; i<2*n-1; i++){
        if (currStart >= n)
            break;
        
        if (i-currStart >= n){
            cs = 0;
            currStart = i;
        }
        cs += a[i];
        ms = max(ms, cs);
        if (cs <= 0){
            cs = 0;
            currStart = i+1;
        }
    }
	return ms;
}

