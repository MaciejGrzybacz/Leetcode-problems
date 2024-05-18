// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            Map<Character, Integer> row = new HashMap<>();
            Map<Character, Integer> col = new HashMap<>();
            Map<Character, Integer> square = new HashMap<>();

            for (int j = 0; j < 9; j++) {
                if (!isValid(row, board[i][j])) {
                    return false;
                }

                if (!isValid(col, board[j][i])) {
                    return false;
                }

                int rowIndex = 3 * (i / 3);
                int colIndex = 3 * (i % 3);
                if (!isValid(square, board[rowIndex + j / 3][colIndex + j % 3])) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isValid(Map<Character, Integer> map, char c) {
        if (c != '.') {
            if (map.containsKey(c)) {
                return false;
            } else {
                map.put(c, 1);
            }
        }
        return true;
    }
}
