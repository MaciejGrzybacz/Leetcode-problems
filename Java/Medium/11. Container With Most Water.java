// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
    public int maxArea(int[] height) {
        if (height.length < 2) {
            return 0;
        }
        int max_area = 0;
        int left = 0;
        int right = height.length - 1;
        while (left < right) {
            int curr_height = Math.min(height[left], height[right]);
            max_area = Math.max(max_area, (right - left) * curr_height);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
}
