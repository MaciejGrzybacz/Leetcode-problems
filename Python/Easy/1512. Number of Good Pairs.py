# https://leetcode.com/problems/number-of-good-pairs/description/

import math
class Solution:
    def k_by_n(self,n,k):
        return math.factorial(n)//math.factorial(n-k)//math.factorial(k)


    def numIdenticalPairs(self, nums: List[int]) -> int:
        d=dict()
        print(sorted(nums))
        for n in nums:
            if not n in d.keys():
                d[n]=1
            else:
                d[n]+=1
        s=0
        for n in d.keys():
            if d[n]>1:
               # print(self.k_by_n(d[n],2))
                s+=self.k_by_n(d[n],2)
        return s