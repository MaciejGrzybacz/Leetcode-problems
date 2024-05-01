// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

class Solution {
    public TreeNode makeTree(int left, int right, int[] nums) {
        if (left > right) {
            return null;
        }
        int mid = (right + left) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = makeTree(left, mid - 1, nums);
        root.right = makeTree(mid + 1, right, nums);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        return makeTree(0, nums.length - 1, nums);
    }
}
