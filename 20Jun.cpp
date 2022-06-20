// Question - You have a string consisting of only 'a' and 'b' as the characters. Perfectness of a string is described as the maximum length substring of equal characters. You are given a number k which denotes the maximum number of characters you can change. Find the maximum perfectness you can generate by changing no more than k characters.


#include<bits/stdc++.h>
using namespace std;

// helper function
int helper(string s, char ch, int k){
	int l = 0, r = 0;
	int currChanges = 0;
	int maxLen = 0;

	while (r < s.length()){
		if (s[r++] != ch)
			currChanges++;
		
		if (currChanges > k){
			while (l < r and s[l] == ch)
				l++;
			currChanges--;
			l++;
		}

		maxLen = max(maxLen, r-l);
	}
	
	return maxLen;
}

// main function
int getMaxLen(string s, int maxChanges){
	// first do for 'a', then do for 'b'
	//return max of both
	int maxA = helper(s, 'a', maxChanges);
	int maxB = helper(s, 'b', maxChanges);

	return max(maxA, maxB);
}
