# https://leetcode.com/problems/ugly-number-iii/description/

class Solution:
    def lcm(self, x, y):
        return x * y // math.gcd(x, y)

    def f(self, k: int, a: int, b: int, c: int) -> int:
        ab = lcm(a, b)
        ac = lcm(a, c)
        bc = lcm(b, c)
        abc = lcm(ab, c)
        return (k // a) + (k // b) + (k // c) - (k // ab) - (k // ac) - (k // bc) + (k // abc)

    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        left, right = 1, 2 * 10**9  
        while left < right:
            mid = (left + right) // 2
            if self.f(mid, a, b, c) < n:
                left = mid + 1
            else:
                right = mid
        return left