#include<bits/stdc++.h>
using namespace std;


// Question 1 - Calculate factorial for very large numbers (tested till 10000)

vector<int> largeFactorial(int n){
	vector<int> result(1, 1);
	int carry = 0;

	for (int num=2; num<=n; num++){
		carry = 0;
		for (int i=0; i<result.size(); i++){
			result[i] = result[i]*num + carry;
			carry = result[i]/10;
			result[i] %= 10;
		}
		while (carry != 0){
			result.push_back(carry%10);
			carry /= 10;
		}
	}

	// result contains digits of answer, with result[0] being units digit, result[1] being tens digit and so on
	return result;
}



// Question 2 - Search for target in row and column-wise sorted array (https://leetcode.com/problems/search-a-2d-matrix-ii)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = 0, col = matrix[0].size()-1;
        
        while (row <= matrix.size()-1 and col >= 0){
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] > target){
                col--;
            }
            else{
                row++;
            }
        }
        
        return false;
}
