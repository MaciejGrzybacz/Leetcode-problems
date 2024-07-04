# https://leetcode.com/problems/self-dividing-numbers/description/

class Solution:
    def selfDivisible(self, n: int) -> bool:
        for i in str(n):
            if i == '0' or n % int(i) != 0:
                return False
        else:
            return True

    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [x for x in range(left, right + 1) if self.selfDivisible(x)]