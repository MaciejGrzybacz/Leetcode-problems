// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefixes = new int[n];
        int[] suffixes = new int[n];

        prefixes[0] = 1;
        suffixes[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefixes[i] = prefixes[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixes[i] = suffixes[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = prefixes[i] * suffixes[i];
        }

        return nums;
    }
}
