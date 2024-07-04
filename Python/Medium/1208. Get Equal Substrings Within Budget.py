# https://leetcode.com/problems/get-equal-substrings-within-budget/description


class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        diffs = [abs(ord(s[i]) - ord(t[i])) for i in range(n)]

        i, j = 0, 0
        current_cost = 0
        max_len = 0

        while j < n:
            if current_cost + diffs[j] <= maxCost:
                current_cost += diffs[j]
                max_len = max(max_len, j - i + 1)
                j += 1
            else:
                current_cost -= diffs[i]
                i += 1

        return max_len
