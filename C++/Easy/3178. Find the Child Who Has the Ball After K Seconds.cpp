// https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/

class Solution {
public:
    int numberOfChild(int n, int k) {
        k = k % (2 * n - 2);
        return (k < n) ? k : 2 * n - k - 2;
    }
};