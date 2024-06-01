// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int maxWidth=0;
        for(int i=1; i<points.length; i++) {
            maxWidth=Math.max(points[i][0]-points[i-1][0],maxWidth);
        }
        return maxWidth;
    }
}