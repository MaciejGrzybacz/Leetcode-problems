// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase(); 
        StringBuilder filtered = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (Character.isLetterOrDigit(ch)) {
                filtered.append(ch);
            }
        }
        
        int n = filtered.length();
        for (int i = 0; i < n / 2; i++) {
            if (filtered.charAt(i) != filtered.charAt(n - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}