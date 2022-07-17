// Question - https://online.codingblocks.com/app/player/209990/content/189057/5105/code-challenge

// Problem stmt - There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n;
	int *a = new int [n];
	for (int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;

	vector<pair<int,int>> v;
	v.push_back(make_pair(a[0],0));
	for (int i=1; i<k; i++){
		for (int j=v.size()-1; j>=0; j--){
			if (a[i] >= v[j].first)
				v.pop_back();
		}
		v.push_back(make_pair(a[i], i));
	}
	cout<<v[0].first<<" ";
	int s = 0;
	for (int i=k; i<n; i++){
		for (int j=s; j<v.size(); j++){
			if (v[j].second <= i-k)
				s++;
		}
		for (int j=v.size()-1; j>=s; j--){
			if (v[j].first < a[i])
				v.pop_back();
		}
		v.push_back(make_pair(a[i], i));
		cout<<v[s].first<<" ";
	}
	return 0;
}
