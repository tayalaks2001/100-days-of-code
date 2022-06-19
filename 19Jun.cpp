#include<bits/stdc++.h>
using namespace std;


// -------- Question 1 - https://leetcode.com/problems/jump-game-ii


// very inefficient solution
int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[nums.size()-1] = 0;
        for(int i=nums.size()-2; i>=0; i--){
            for (int j=i+1; j<=i+nums[i]; j++){
                if (j >= nums.size())
                    break;
                dp[i] = min(dp[i], dp[j]);
            }
            if (dp[i] == INT_MAX)
                continue;
            dp[i] += 1;
        }
        return dp[0];
}



// -------- Question 2 - Take as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes

// helper func
string diff(char a, char b){
	string res;

	int diff = b-a;
	bool neg = false;
	if (diff < 0){
		neg = true;
		diff = (-1)*diff;
	}

	while (diff > 0){
		res.push_back('0' + diff%10);
		diff /= 10;
	}

	if (neg)
		res.push_back('-');
	
	reverse(res.begin(), res.end());
	return res;
}

// main func
void modifyString(string &s){
	int len = s.length();
	int i=0;
	while (i < len-1){
		string ins = diff(s[i], s[i+1]);
		len += ins.length();
		for (char ch : ins){
			s.insert(s.begin()+i+1, ch);
			i++;
		}
		i++;
	}
}
