/*

36. Valid Sudoku

You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

	1. Each row must contain the digits 1-9 without duplicates.
	2. Each column must contain the digits 1-9 without duplicates.
	3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.


Example 1:
Input: board =
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board =
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: There are two 1's in the top-left 3x3 sub-box.


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<int, unordered_set<char>> rows, cols;
		map<pair<int, int>, unordered_set<char>> squares;

		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (board[r][c] == '.') continue;

				pair<int, int> squareKey = { r / 3, c / 3 };

				if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
					return false;
				}

				rows[r].insert(board[r][c]);
				cols[c].insert(board[r][c]);
				squares[squareKey].insert(board[r][c]);
			}
		}

		return true;
	}
};

void runExample(vector<vector<char>>& board, const string& label) {
	Solution solver;
	bool result = solver.isValidSudoku(board);

	// Print Label
	cout << "=== " << label << " ===\n";

	// Print Input
	cout << "Input: board = \n\n";
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			cout << board[r][c] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	// Print Output
	if (result) cout << "Output: true";
	else cout << "Output: false";
	cout << "\n\n";
}

int main() {
	vector<vector<char>> example1_board = {
		{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
		{'4', '.', '.', '5', '.', '.', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '.', '3'},
		{'5', '.', '.', '.', '6', '.', '.', '.', '4'},
		{'.', '.', '.', '8', '.', '3', '.', '.', '5'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '.', '.', '.', '.', '.', '2', '.', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '8'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	vector<vector<char>> example2_board = {
		{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
		{'4', '.', '.', '5', '.', '.', '.', '.', '.'},
		{'.', '9', '1', '.', '.', '.', '.', '.', '3'},
		{'5', '.', '.', '.', '6', '.', '.', '.', '4'},
		{'.', '.', '.', '8', '.', '3', '.', '.', '5'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '.', '.', '.', '.', '.', '2', '.', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '8'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	runExample(example1_board, "Example 1");
	runExample(example2_board, "Example 2");

	return 0;
}