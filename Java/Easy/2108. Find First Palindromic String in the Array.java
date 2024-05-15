// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

class Solution {
    private boolean isPalindrome(String str) {
        int n=str.length();
        for(int i=0; i<n; i++) {
            if(str.charAt(i) != str.charAt(n-i-1)) {
                return false;
            }
        }
        return true;
    }
    public String firstPalindrome(String[] words) {
        for(String str: words) {
            if(isPalindrome(str))  {
                return str;
            }
        }
        return "";
    }
}