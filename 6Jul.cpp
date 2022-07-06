// Question - Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.

#include<iostream>
#include<vector>
using namespace std;

void func(vector<int> ar, vector<int>& foundAt, int target, int idx=0){
	if (idx == ar.size()){
		return;
	}

	if (ar[idx] == target){
		foundAt.push_back(idx);
	}
	func(ar, foundAt, target, idx+1);
}

int main() {
	int size;
	cin>>size;
	vector<int> v, foundAt;
	for (int i=0; i<size; i++){
		int val;
		cin>>val;
		v.push_back(val);
	}
	int target;
	cin>>target;
	func(v, foundAt, target);
	for (int i=0; i<foundAt.size(); i++)
		cout<<foundAt[i]<<" ";
	return 0;
}
