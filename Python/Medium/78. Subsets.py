# https://leetcode.com/problems/subsets/description/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums)==0:
            return [[]]
        subs=self.subsets(nums[:-1])

    
        return subs + [[nums[-1]] + y for y in subs]