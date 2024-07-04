# https://leetcode.com/problems/group-anagrams/description/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = dict()
        for s in strs:
            sorted_s = tuple(sorted(s))
            if sorted_s in d.keys():
                d[sorted_s].append(s) 
            else:
                d[sorted_s] = [s]
        return d.values()