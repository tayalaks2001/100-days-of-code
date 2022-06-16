// Question - You are provided n numbers of array. You need to find the maximum length of bitonic subarray.
// A subarray A[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.


#include<bits/stdc++.h>
using namespace std;

int lengthBitonicSubarray(int n, vector<int> arr){
    // Length of increasing subarray
    // ending at all indices
    int inc[n];
     
    // Length of decreasing subarray
    // starting at all indices
    int dec[n];
    
    int i, max;
 
    inc[0] = 1;
    dec[n-1] = 1;
 
    // Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
 
    // Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
 
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
 
    return max;
}



// Alternative attempt - unsuccessful, not sure why
int lengthBitonicSubarray2(int n, vector<int> a){
	bool increasing = true;
	int cl = 1, ml = INT_MIN;
	for (int i=1; i<n; i++){
		if (a[i] > a[i-1]){
			if (increasing){
				cl++;
			}
			else{
				ml = max(cl, ml);
				cl = 2;
				increasing = true;
			}
		}
		else{
			increasing = false;
			cl++;
		}
	}
	ml = max(cl, ml);
	return ml;
}
