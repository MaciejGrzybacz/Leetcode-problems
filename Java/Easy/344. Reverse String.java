// https://leetcode.com/problems/reverse-string/description/

class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        for(int i = 0; i < n/2; i++) {
            char tmp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = tmp;
        }
    }
}