# https://leetcode.com/problems/merge-sorted-array/description/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        tmp = [None] * (m + n)
        i = 0
        j = 0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                tmp[i + j] = nums1[i]
                i += 1
            else:
                tmp[i + j] = nums2[j]
                j += 1
        while i < m:
            tmp[i + j] = nums1[i]
            i += 1
        while j < n:
            tmp[i + j] = nums2[j]
            j += 1
        for i in range(len(tmp)):
            nums1[i] = tmp[i]

