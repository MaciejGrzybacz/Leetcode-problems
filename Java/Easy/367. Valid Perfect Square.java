// https://leetcode.com/problems/valid-perfect-square/description/

class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 1) return true;
        
        long left = 1;
        long right = num / 2;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
}
