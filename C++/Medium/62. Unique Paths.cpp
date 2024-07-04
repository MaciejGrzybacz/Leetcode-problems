// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                curr[j] = curr[j - 1] + prev[j];
            }
            swap(curr, prev);
        }
        return prev[n - 1];
    }
};