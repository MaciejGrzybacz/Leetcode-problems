# https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        return [item for pair in zip([x for x in nums if x > 0], [x for x in nums if x < 0]) for item in pair]