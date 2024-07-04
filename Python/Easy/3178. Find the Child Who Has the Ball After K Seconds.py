# https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/

class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        k = k % (2 * n - 2)
        return k if k < n else 2 * n - k - 2 