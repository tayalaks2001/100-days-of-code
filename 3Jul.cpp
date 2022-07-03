//Question - Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

#include<bits/stdc++.h>
using namespace std;

void generateParantheses(int n, int open, int closed, string s){
	// base case
	if (open == n){
		while (closed < n){
			s.push_back(')');
			closed++;
		}
		cout<<s<<endl;
		return;
	}

	//recursive cases
	if (open > closed and open < n){
		// add closing bracket
		s.push_back(')');
		generateParantheses(n, open, closed+1, s);
		// add opening bracket
		s.pop_back();
		s.push_back('(');
		generateParantheses(n, open+1, closed, s);
	}
	else if (open == closed){
		s.push_back('(');
		generateParantheses(n, open+1, closed, s);
	}
}
