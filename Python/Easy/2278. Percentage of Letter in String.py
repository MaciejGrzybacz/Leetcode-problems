# https://leetcode.com/problems/percentage-of-letter-in-string/description/

class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return sum([1 for x in s if x==letter])*100//len(s) if len(s) else 0