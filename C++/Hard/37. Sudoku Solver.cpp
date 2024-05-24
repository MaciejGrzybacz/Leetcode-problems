// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
private:
    vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    bool isValid(vector<vector<char>>& board, int row, int col, char s) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == s || board[row][i] == s) {
                return false;
            }
        }
        int row_offset = (row / 3) * 3;
        int col_offset = (col / 3) * 3;
        for (int i = row_offset; i < row_offset + 3; i++) {
            for (int j = col_offset; j < col_offset + 3; j++) {
                if (board[i][j] == s) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (col == 9) {
            return solve(board, row + 1, 0);
        }
        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }
        for (int i = 0; i < 9; i++) {
            if (isValid(board, row, col, nums[i])) {
                board[row][col] = nums[i];
                if (solve(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};