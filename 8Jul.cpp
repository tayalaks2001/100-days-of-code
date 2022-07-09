// Question -> n-Queen problem: given integer n, find number of ways n queens can be placed safely on an nxn chess board

#include<bits/stdc++.h>
#define p pair<int,int>
using namespace std;

bool isSafe(vector<p> placements, int row, int col){
	for (auto i : placements){
		if (i.first == row or i.second == col or abs(i.first-row) == abs(i.second-col))
			return false;
	}

	return true;
}

int countNQueenWays(int n, int row, int col, vector<p> placements){
	if (placements.size() == n)
		return 1;
	
	if (col == n)
		return 0;
	
	int numWays = 0;
	numWays += countNQueenWays(n, row, col+1, placements);
	if (isSafe(placements, row, col)){
		placements.push_back(make_pair(row,col));
		numWays += countNQueenWays(n, row+1, 0, placements);
	}

	return numWays;
}
