# https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)

        if n < 5:
            return 0 

        nums.sort()
        return min(nums[-4] - nums[0], nums[-3] - nums[1], nums[-2] - nums[2], nums[-1] - nums[3])
        