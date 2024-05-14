# https://leetcode.com/problems/first-bad-version/description/

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left=1
        right=n
        while(left<right):
            m=(left+right)//2
            if(isBadVersion(m)):
                right=m
            else:
                left=m+1
        return left
        