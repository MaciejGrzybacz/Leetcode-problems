// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0],  maxEndingOnIndex = nums[0];
        for(int i=1; i<nums.length; i++) {
            maxEndingOnIndex=Math.max(maxEndingOnIndex+nums[i],nums[i]);
            maxSum=Math.max(maxSum,maxEndingOnIndex);
        }
        return maxSum;
    }
}