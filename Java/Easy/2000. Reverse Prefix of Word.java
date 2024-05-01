// https://leetcode.com/problems/reverse-prefix-of-word/description/


class Solution {
    public String reversePrefix(String word, char ch) {
        int rightIndex = word.indexOf(ch); 
        if (rightIndex == -1) {
            return word;
        }
        
        char[] wordChars = word.toCharArray();
        for (int i = 0; i <= rightIndex / 2; i++) {
            char tmp = wordChars[i];
            wordChars[i] = wordChars[rightIndex - i];
            wordChars[rightIndex - i] = tmp;
        }
        
        return new String(wordChars); 
    }
}
