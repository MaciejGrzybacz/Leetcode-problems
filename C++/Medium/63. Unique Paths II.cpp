// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<int> prev(n, 0), curr(n, 0);

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) {
            return 0;
        }

        prev[0] = 1;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j]) {
                    curr[j] = 0;
                } else {
                    if(i == 0 && j == 0) {
                        curr[j] = 1;
                    } else {
                        int left = (j > 0) ? curr[j-1] : 0;
                        int up = (i > 0) ? prev[j] : 0;
                        curr[j] = left + up;
                    }
                }
            }
            swap(curr, prev);
        }

        return prev[n-1];
    }
};
