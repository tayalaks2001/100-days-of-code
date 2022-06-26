// Question - binary search: lower and upper bound

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int target){
	int start = 0, end = v.size()-1;
	int ans = -1;
	while (start <= end){
		int mid = (start+end)/2;
		if (v[mid] > target){
			end = mid-1;
		}
		else{
			if (ans == -1 or v[ans] < v[mid])
				ans = mid;
			start = mid+1;
		}
	}

	return ans;
}

int upperBound(vector<int> v, int target){
	int start = 0, end = v.size()-1;
	int ans = -1;
	while (start <= end){
		int mid = (start+end)/2;
		if (v[mid] <= target){
			start = mid+1;
		}
		else{
			if (ans == -1 or v[ans] > v[mid])
				ans = mid;
			end = mid-1;
		}
	}

	return ans;
}
