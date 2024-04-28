# https://leetcode.com/problems/reverse-string/description/

class Solution:
    def reverseString(self, s: List[str]) -> None:
        n = len(s) - 1
        i = 0
        while i <= n - i:
            s[i], s[n - i] = s[n - i], s[i]
            i += 1
