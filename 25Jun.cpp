#include<bits/stdc++.h>
using namespace std;

// Question - Imagine typing in some numbers into a seven segment display, as used on a pocket calculator. Then turn the screen upside down. Sometimes it looks like a word.

Words are spelled with the following letters:
0 = O
1 = I
2 = Z
3 = E
4 = h
5 = s
6 = g
7 = L
8 = B

hello -> 07734

For example, the number 376006 becomes “Google”. A word can be contained within a larger number - for example, 937600654 also contains “google”.

Given a number and a list of valid words, return true if any contiguous sequence of numbers can be flipped to create a valid word.



// main function
string checkForValidWord(int input, vector<string> validWords){
	if (validWords.size() == 0)
		return false;

	unordered_map<int, char> encoding = {0:’o’, 1:’i’, 2:’s’, 3:’e’, 4:’h’, 5:’s’, 6:’g’, 7:’l’, 8:’b’, 9:’?’};
	
	string encodedNum;
	if (input == 0){
		encodedNum.push_back(encoding[0]);
	}
	else{
		while (input > 0){
			int currDigit = input%10;
			input = input/10;
			char alphabet = encoding[currDigit];
			encodedNum.push_back(alphabet);
		}
	}
	
	int currMaxLength = INT_MIN;
	string longestWordFound = “”;
	for (string validWord : validWords){
		if (encodedNum.find(validWord) != string::npos){
			if (validWord.size() > currMaxLength){
				currMaxLength = validWord.size();
				longestWordFound = validWord;
			}
		}
	}

	return longestWordFound;
}

