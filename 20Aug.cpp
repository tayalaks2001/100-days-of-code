// Question - https://leetcode.com/problems/longest-palindromic-subsequence/

int dp(const string& s, int l, int r) {
        if (l > r) return 0; // Return 0 since it's empty string
        if (l == r) return 1; // Return 1 since it has 1 character
        if (memo[l][r] != 0) return memo[l][r];
        if (s[l] == s[r])
            return memo[l][r] = dp(s, l+1, r-1) + 2;
        return memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
    
    int longestPalindromeSubseq(string s) {
        return dp(s, 0, s.size() - 1);
    }
