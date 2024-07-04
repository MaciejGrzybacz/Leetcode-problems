# https://leetcode.com/problems/jump-game/description/

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reachable = [True] + [False] * (n - 1)
        
        for i, num in enumerate(nums):
            if reachable[i]:
                for j in range(1, num + 1):
                    if i + j < n:
                        reachable[i + j] = True
                    if reachable[-1]:
                        return True
        
        return reachable[-1]
