# https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        s = set(nums)
        arr = list(s)
        arr.sort()
        for i in range(len(arr)):
            nums[i] = arr[i]
        return len(arr)




