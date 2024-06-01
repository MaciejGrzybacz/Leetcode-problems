# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        curr_val = nums[0]
        curr_val_count = 1
        offset = 0
        for i in range(1, len(nums)):
            if nums[i] == curr_val:
                if curr_val_count < 2:
                    curr_val_count += 1
                    nums[i - offset] = nums[i]
                else:
                     offset += 1
            else:
                curr_val = nums[i]
                curr_val_count = 1
                nums[i - offset] = nums[i] 

        return len(nums) - offset