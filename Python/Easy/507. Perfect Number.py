# https://leetcode.com/problems/perfect-number/description/

class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        return num > 1 and sum(i + (num // i if i != 1 else 0) for i in range(1, int(num**0.5) + 1) if num % i == 0) == num