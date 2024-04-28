# https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        helper=[0]*101
        for n in nums:
            helper[n]+=1
        counter=[0]*101

        for i in range(1,101):
            counter[i]=counter[i-1]+helper[i-1]

        result=[]
        for n in nums:
            result.append(counter[n])
        return result