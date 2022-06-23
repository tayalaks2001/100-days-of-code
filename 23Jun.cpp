#include<bits/stdc++.h>
using namespace std;

// Question - You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

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
