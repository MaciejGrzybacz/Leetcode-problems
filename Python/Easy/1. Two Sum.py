# https://leetcode.com/problems/two-sum/description/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i, num in enumerate(nums):
            if num in d.keys():
                d[num]= d[num]+list([i])
            else:
                d[num]=list([i])
        for n in d.keys():
            if target-n==n:
                if len(d[n])>1:
                    return d[n][:2]
            else:
                if target-n in d.keys():
                    return [d[n][0],d[target-n][0]]