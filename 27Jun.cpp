// Question - You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int> ar, int n, int k, int numPages){
	int curr = 0, i = 0;
	for (; i<n; i++){
		if (ar[i] > numPages)
			return false;

		if (curr+ar[i] > numPages){
			curr = 0;
			k--;
		}
		curr += ar[i];
	}

	if (k > 0 or (k == 0 and curr == 0))
		return true;
	
	return false;
}

int minHighestPages(vector<int> num, int students){
	int sum = 0, ans = 0;
	for (int page : num)
		sum += page;
	int start = sum/students, end = sum;
	while (start <= end){
		int mid = (start+end)/2;
		if (isFeasible(num, num.size(), students, mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}

	return ans;
}
