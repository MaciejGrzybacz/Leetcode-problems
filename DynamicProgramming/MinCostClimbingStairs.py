# https://leetcode.com/problems/min-cost-climbing-stairs/
from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def minCost(i):
            if i>=len(cost):
                return 0
            return min(minCost(i+1)+cost[i],minCost(i+2)+cost[i])
        minCost(0)


cost = [1,100,1,1,1,100,1,1,100,1]

s=Solution()
print(s.minCostClimbingStairs(cost))