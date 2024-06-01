// https://leetcode.com/problems/path-with-maximum-gold/description/

class Solution {
    public int getMaximumGold(int[][] grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    maxGold = Math.max(maxGold, dfs(grid, i, j, 0));
                }
            }
        }
        return maxGold;
    }
    
    private int dfs(int[][] grid, int x, int y, int currentGold) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == 0) {
            return currentGold;
        }
        
        int collectedGold = grid[x][y];
        currentGold += collectedGold;
        
        int temp = grid[x][y];
        grid[x][y] = 0;
        
        int maxGold = currentGold;
        maxGold = Math.max(maxGold, dfs(grid, x + 1, y, currentGold)); 
        maxGold = Math.max(maxGold, dfs(grid, x - 1, y, currentGold)); 
        maxGold = Math.max(maxGold, dfs(grid, x, y + 1, currentGold)); 
        maxGold = Math.max(maxGold, dfs(grid, x, y - 1, currentGold)); 
        
        grid[x][y] = temp;
        
        return maxGold;
    }
}
