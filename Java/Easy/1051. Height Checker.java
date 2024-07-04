// https://leetcode.com/problems/height-checker/description/

class Solution {
    public int heightChecker(int[] heights) {
        int[] expected = heights.clone();
        Arrays.sort(expected);
        int counter=0;
        for(int i = 0; i < heights.length; i++) {
            if(heights[i] == expected[i]) {
                continue;
            }
            counter++;
        }
        return counter;
    }
}