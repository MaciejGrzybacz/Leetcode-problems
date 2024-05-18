# https://leetcode.com/problems/generate-parentheses/description/

class Solution:
    def addParenthesis(self, s: str) -> List[str]:
        return [s[:i] + '()' + s[i:] for i in range(len(s) + 1)]
    
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        if n == 1:
            return ["()"]
        
        result = set(["()"])
        for _ in range(1, n):
            new_result = set()
            for curr in result:
                new_result.update(self.addParenthesis(curr))
            result = new_result
        
        return list(result)