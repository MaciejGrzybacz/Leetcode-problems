# https://leetcode.com/problems/triangle/description/
from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        d=dict()
        def f(triangle,d,row,col):
            if row==len(triangle):
                return 0
            if (row,col) in d:
                return d[(row,col)]
            d[(row,col)]=min(f(triangle,d,row+1,col),f(triangle,d,row+1,col+1))+triangle[row][col]
            return d[(row,col)]
        return f(triangle,d,0,0)
