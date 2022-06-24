#include<bits/stdc++.h>
using namespace std;

// Question - https://leetcode.com/problems/sort-colors/

void linearSort(vector<int> &v){
	int l = -1, h = v.size();

	for (int i = 0; i < v.size(); i++){
		if (v[i] == 0 and i > l){
			l++;
			int temp = v[i];
			v[i] = v[l];
			v[l] = temp;
		}
		else if (v[i] == 2 and i < h){
			h--;
			int temp = v[i];
			v[i] = v[h];
			v[h] = temp;
			i--;
		}
	}
}
