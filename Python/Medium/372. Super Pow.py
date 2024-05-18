# https://leetcode.com/problems/super-pow/description/

class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        pows=[(a**i)%1337 for i in range(0,11)]
        result=1
        for n in b[:-1]:
            result*=pows[int(n)]
            result**=10
            result%=1337
        result*=pows[int(b[-1])]
        return result%1337

