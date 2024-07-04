# https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/


class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        curr_set = set()
        curr_player = 1
        i=1
        while True:
            curr_set.add(curr_player)
            curr_player = (curr_player + i * k - 1) % n + 1
            if curr_player in curr_set:
                return [i for i in range(1, n + 1) if i not in curr_set]
            i += 1
        