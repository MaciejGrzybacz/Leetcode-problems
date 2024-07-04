# https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

class Solution:
    def nThFibonacci(self, x: int) -> List[int]:
        fibs = []
        a, b = 0, 1
        while a <= x:
            fibs.append(a)
            a, b = b, a + b
        return fibs

    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        arr_set = set(arr)
        max_len = 0
        n = len(arr)
        indices = {x: i for i, x in enumerate(arr)}
        
        dp = {}
        
        for k in range(n):
            for j in range(k):
                if arr[k] - arr[j] in indices and indices[arr[k] - arr[j]] < j:
                    i = indices[arr[k] - arr[j]]
                    if (i, j) in dp:
                        dp[(j, k)] = dp[(i, j)] + 1
                    else:
                        dp[(j, k)] = 3
                    max_len = max(max_len, dp[(j, k)])
        
        return max_len if max_len >= 3 else 0

