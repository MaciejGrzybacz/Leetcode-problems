// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;
        int maxProduct = nums[0];
        int maxEndingOnIndex = nums[0];
        int minEndingOnIndex = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            int temp = maxEndingOnIndex;
            maxEndingOnIndex = Math.max(Math.max(maxEndingOnIndex * nums[i], minEndingOnIndex * nums[i]), nums[i]);
            minEndingOnIndex = Math.min(Math.min(temp * nums[i], minEndingOnIndex * nums[i]), nums[i]);
            maxProduct = Math.max(maxProduct, maxEndingOnIndex);
        }

        return maxProduct;
    }
}
