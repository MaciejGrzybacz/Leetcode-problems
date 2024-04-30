// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
    public int trap(int[] height) {
         int n = height.length;
        if (n == 0) return 0;

        int left = 0;
        int right = n - 1; 
        int leftMax = 0; 
        int rightMax = 0; 
        int totalWater = 0; 

        while (left < right) {
            leftMax=Math.max(leftMax,height[left]);
            rightMax = Math.max(rightMax, height[right]);

            if (leftMax < rightMax) {
                totalWater+=(leftMax-height[left]);
                left++;
            } else {
                totalWater+=(rightMax-height[right]);
                right--;
            }
        }
        return totalWater;
    }
}
