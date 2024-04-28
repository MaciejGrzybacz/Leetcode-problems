# https://leetcode.com/problems/is-subsequence/description/

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s=="":
            return True

        i=0
        for l in t:
            if i==len(s):
                return True
            if s[i]==l:
                i+=1
        return i==len(s)