# https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        keyboard = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        
        if len(digits) == 0:
            return []
        
        result = list(keyboard[digits[0]])
        for digit in digits[1:]:
            result = [x + y for x in result for y in keyboard[digit]]
        
        return result