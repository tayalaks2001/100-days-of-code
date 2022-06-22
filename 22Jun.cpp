#include<bits/stdc++.h>
using namespace std;

// Basic sorting algos

int* insSort(int* ar, int n){
	for (int i=1; i<n; i++){
		int index=i;
		for (int j=0; j<i; j++){
			if (ar[i] < ar[j]){
				index = j;
				break;
			}
		}
		int ele = ar[i];
		for (int j=i; j>index; j--){
			ar[j] = ar[j-1];
		}
		ar[index] = ele;
	}

	return ar;
}

int* selSort(int *ar, int n){
	for (int i=0; i<n-1; i++){
		int minm = INT_MAX, index = -1;
		for (int j=i; j<n; j++){
			if (minm > ar[j]){
				minm = ar[j];
				index = j;
			}
		}
		int temp = ar[i];
		ar[i] = minm;
		ar[index] = temp;
	}

	return ar;
}

void bubbleSort(vector<int> &v){
	int n = v.size();
	for (int iter = 1; iter < n; iter++){
		for (int i=1; i <= n - iter; i++){
			if (v[i-1] > v[i]){
				int temp = v[i-1];
				v[i-1] = v[i];
				v[i] = temp;
			}
		}
	}
}
