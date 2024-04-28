# https://leetcode.com/problems/majority-element/description/

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = dict()
        for num in nums:
            if num in d.keys():
                d[num] += 1
            else:
                d[num] = 1
        max_count = -1
        max_val = None
        for key in d.keys():
            if d[key] > max_count:
                max_count = d[key]
                max_val = key
        return max_val
