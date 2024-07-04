// https://leetcode.com/problems/construct-the-rectangle/description/

class Solution {
    public int[] constructRectangle(int area) {
        int x = (int) Math.sqrt(area);
        for (int i = x; i > 0; i--) {
            if (area % i == 0) {
                return new int[]{area / i, i};
            }
        }
        return new int[]{};
    }
}
