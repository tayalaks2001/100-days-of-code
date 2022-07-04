// Sudoku solver

#include<bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<int>> sudoku){
	for (int i=0; i<sudoku.size(); i++){
		for (int j=0; j<sudoku[0].size(); j++){
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isFeasible(vector<vector<int>> sudoku, int row, int col, int number){
	for (int i=0; i<sudoku.size(); i++){
		if (sudoku[i][col] == number)
			return false;
	}
	for (int i=0; i<sudoku[0].size(); i++){
		if (sudoku[row][i] == number)
			return false;
	}

	int boxRowL = (row/3)*3, boxColL = (col/3)*3;
	int boxRowR = boxRowL+3, boxColR = boxColL+3;
	for (int i = boxRowL; i < boxRowR; i++)
		for (int j = boxColL; j < boxColR; j++)
			if (sudoku[i][j] == number)
				return false;

	return true;
}

bool sudokuSolver(vector<vector<int>> sudoku, int row = 0, int col = 0){
	// base case - reached the end of the puzzle
	if (row == sudoku.size()){
		printSudoku(sudoku);
		return true;
	}

	// recursive cases
	int next_row = row, next_col = col;
	if (col == sudoku[0].size()-1){
		next_row++;
		next_col = 0;
	}
	else{
		next_col++;
	}

	if (sudoku[row][col] != 0){
		return sudokuSolver(sudoku, next_row, next_col);
	}

	for (int num = 1; num <= sudoku.size(); num++){
		if (isFeasible(sudoku, row, col, num)){
			sudoku[row][col] = num;
			if (sudokuSolver(sudoku, next_row, next_col))
				return true;
		}
	}
	
	return false;
}
