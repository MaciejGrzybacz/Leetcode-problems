// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 class Solution {
    private int res = 0;

    public int distributeCoins(TreeNode root) {
        solve(root);
        return res;
    }

    private int solve(TreeNode root) {
        if (root == null)
            return 0;
        int left = solve(root.left);
        int right = solve(root.right);
        res += Math.abs(left + right + root.val - 1);

        return left + right + root.val - 1;
    }
}

