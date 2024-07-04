# https://leetcode.com/problems/relative-sort-array/description/

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = Counter(arr1)
        first_part = [x for x in arr2 if x in count for _ in range(count[x])]
        second_part = sorted([x for x in arr1 if x not in first_part])
        return first_part+second_part