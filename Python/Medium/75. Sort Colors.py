# https://leetcode.com/problems/sort-colors/description/

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = [0]*3
        for i in nums:
            count[i] += 1 
        index = 0
        for i in range(len(nums)):
            while count[index] == 0:
                index += 1
            nums[i] = index
            count[index] -= 1