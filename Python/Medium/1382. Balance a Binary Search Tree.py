# https://leetcode.com/problems/balance-a-binary-search-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def toList(self, root: TreeNode, lst: List[int]) -> None:
        if not root:
            return
        self.toList(root.left, lst)
        lst.append(root.val)
        self.toList(root.right, lst)

    def rebuiltTree(self, lst: List[int], left: int, right: int) -> TreeNode:
        if left > right:
            return None
        
        m = left + (right - left) // 2

        return TreeNode(lst[m], self.rebuiltTree(lst, left, m - 1), self.rebuiltTree(lst, m + 1, right))
 
    def balanceBST(self, root: TreeNode) -> TreeNode:
        lst = list()
        self.toList(root, lst)
        return self.rebuiltTree(lst, 0, len(lst) - 1)