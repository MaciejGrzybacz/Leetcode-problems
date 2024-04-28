# https://leetcode.com/problems/rotate-array/description/

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        tmpnums = nums[-k % n:] + nums[:-k % n]
        for i in range(len(tmpnums)):
            nums[i] = tmpnums[i]
