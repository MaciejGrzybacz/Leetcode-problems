# https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
from typing import List


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        d = dict()
        for num in nums:
            if num in d.keys():
                d[num] += 1
            else:
                d[num] = 1
        max_occur = max(d.values())
        cnt = 0
        for num in d.keys():
            if d[num] == max_occur:
                cnt += max_occur
        return cnt
