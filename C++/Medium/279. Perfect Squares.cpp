// https://leetcode.com/problems/perfect-squares/description/


class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return numSquaresHelper(n, memo);
    }

private:
    int numSquaresHelper(int n, vector<int>& memo) {
        if (n <= 3) return n;
        if (memo[n] != -1) return memo[n];

        int largest_square = sqrt(n);

        int min_squares = INT_MAX;

        for (int i = largest_square; i >= 1; --i) {
            min_squares = min(min_squares, 1 + numSquaresHelper(n - i * i, memo));
        }

        memo[n] = min_squares;

        return min_squares;
    }
};