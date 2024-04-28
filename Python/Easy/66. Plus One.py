# https://leetcode.com/problems/plus-one/description/

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits=[0]+digits
        rest=1
        i=len(digits)-1
        while rest:
            rest, digits[i]=(digits[i]+rest)//10,(digits[i]+rest)%10
            i-=1
        if digits[0]==0:
            digits=digits[1:]
        return digits