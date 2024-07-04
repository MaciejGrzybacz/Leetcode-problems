# https://leetcode.com/problems/jump-game-ii/description/

# could be solved more efficiently in the way similar to problem 55 but I wanted to practise memoization
class Solution:
    def solve(self, nums, index, memo):
        if index in memo:
            return memo[index]

        if index >= len(nums) - 1:
            return 0

        current_min = float('inf')
        for i in range(1, nums[index] + 1):
            if index + i < len(nums):
                current_min = min(current_min, 1 + self.solve(nums, index + i, memo))
        
        memo[index] = current_min
        return current_min

    def jump(self, nums: List[int]) -> int:
        memo = dict()
        return self.solve(nums, 0, memo)
