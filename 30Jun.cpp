#include<bits/stdc++.h>
using namespace std;

// Question - find pivot of rotated sorted array

//same as finding position of max element in rotated sorted array
int main() {
	int n;
	cin>>n;
	int nums[n];
	for (int i=0; i<n; i++)
		cin>>nums[i];

	int start = 0, end = n-1;
	int minm = 0;
	while (start <= end){
		int mid = (start+end)/2;
		if (nums[mid] < nums[minm])
			minm = mid;
		
		if (nums[mid] > nums[end])
			start = mid+1;
		else
			end = mid-1;
		
	}
	cout<<minm-1;
	return 0;
}
