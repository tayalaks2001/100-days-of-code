// Question - https://online.codingblocks.com/app/player/209990/content/189057/4990/code-challenge

// Problem stmt - There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.
// Now, we are given two things:
// 1)The calling order in which all the processes are called.
// 2)The ideal order in which all the processes should have been executed.

// Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

// We have to find out the unit of time required to complete all the process such that a process is executed from the ideal order only when it exists at the same index in the calling order. We can push the first term from the calling order to the last thus rotating the order.

#include<bits/stdc++.h>
using namespace std;

int countTime(vector<int> actual, vector<int> ideal){
	int count = 0;
	int i=0, j=0, n=actual.size();

	while (j < n){
		while (actual[i] != ideal[j]){
			if (actual[i] != -1)
				count++;
			i++;
			if (i == n)
				i = 0;
		}
		count++;
		actual[i] = -1;
		j++;
	}

	return count;
}
