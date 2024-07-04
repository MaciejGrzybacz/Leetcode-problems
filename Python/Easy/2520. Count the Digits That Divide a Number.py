# https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

class Solution:
    def countDigits(self, num: int) -> int:
        return sum(1 for i in str(num) if num % int(i) == 0)
