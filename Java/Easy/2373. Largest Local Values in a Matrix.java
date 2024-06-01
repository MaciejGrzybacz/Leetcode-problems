// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] newGrid = new int[n-2][n-2]; 

        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                int maxVal = 0;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        maxVal = Math.max(maxVal, grid[i + k][j + l]);
                    }
                }

                newGrid[i][j] = maxVal; 
            }
        }
        return newGrid; 
    }
}
