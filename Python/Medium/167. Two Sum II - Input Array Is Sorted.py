# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
from astroid import List


class Solution:
    def binary_search(self, i,j,tab,x):
        if j<i: return -1
        else:
            m=(i+j)//2
            if tab[m]==x:
                return m
            elif tab[m]<x:
                return self.binary_search(m+1,j,tab,x)
            else:
                return self.binary_search(i,m-1,tab,x)

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i,n in enumerate(numbers):
            j= self.binary_search(i+1, len(numbers)-1, numbers, target-n)
            if j!=-1:
                return [i+1,j+1]