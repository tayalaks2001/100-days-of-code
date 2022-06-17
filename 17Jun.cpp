// Question - provided an array of numbers, arrange them in a way that yields the largest value.

// Sample Input
// 1
// 4
// 54 546 548 60

// Sample Output
// 6054854654

#include<bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2){
	string combo1 = s1+s2, combo2 = s2+s1;
	if (combo1 > combo2)
		return true;
	return false;
}

int main() {
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<string> a(n, "");
		for (int i=0; i<n; i++)
			cin>>a[i];
		sort(a.begin(), a.end(), compare);
		for (string s : a)
			cout<<s;
		cout<<endl;
	}
	return 0;
}
