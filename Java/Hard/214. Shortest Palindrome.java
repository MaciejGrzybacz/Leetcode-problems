// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
    private boolean isPalindrome(String s, int start, int end) {
        int i = start, j = end - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
    private int longestPalindromeStartingAtZero(String s) {
        if (s == null || s.length() == 0) {
             return 0;
        }

        int maxLen = 1; 
        int end = s.length();

        while (end > maxLen) {
            if (isPalindrome(s, 0, end)) {
                maxLen = end; 
                break; 
            }
            end--;
        }
        return maxLen;
    }
    public String shortestPalindrome(String s) {
        int endOfPalindrome=longestPalindromeStartingAtZero(s);

        String toBeReversed=s.substring(endOfPalindrome,s.length());

        StringBuilder sb = new StringBuilder(toBeReversed);
        String reversed= sb.reverse().toString();
        
        return reversed+s;
    }
}