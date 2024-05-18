# https://leetcode.com/problems/zigzag-conversion/description/

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n=len(s)
        s=list(s)
        rows=[[] for _ in range(numRows)]
        positions=[i for i in range(numRows)]+[i for i in range(numRows-2,0,-1)]
        m=len(positions)
        for i in range(n):
            rows[positions[i%m]].append(s[i])
        result=[]
        for row in rows:
            result+=row
        return ''.join(result)

            