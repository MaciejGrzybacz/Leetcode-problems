# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)==0:
            return 0
        d=dict()
        for x in set(list(s)):
            d[x]=0
        i, j = 0, 0
        max_len=0
        while j<len(s):
            if d[s[j]]==0:
                d[s[j]]+=1
                j+=1
            else:
                max_len=max(max_len,j-i)
                d[s[i]]-=1
                i+=1
        return max(max_len,j-i)


