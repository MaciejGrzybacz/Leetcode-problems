// https://leetcode.com/problems/image-smoother/description/

class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] newImg = new int[m][n]; 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cellCount = 0;
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        int ni = i + k;
                        int nj = j + l;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            cellCount++;
                        }
                    }
                }
                newImg[i][j] = sum / cellCount; 
            }
        }
        return newImg; 
    }
}
