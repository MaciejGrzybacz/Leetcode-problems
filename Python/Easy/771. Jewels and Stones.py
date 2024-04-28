# https://leetcode.com/problems/jewels-and-stones/description/

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        d=dict()
        for s in stones:
            if not s in d.keys():
                d[s]=1
            else:
                d[s]+=1
        return sum([d[x] for x in d.keys() if x in jewels])