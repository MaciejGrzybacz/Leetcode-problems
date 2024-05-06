// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int max_len=1;
        int curr_len=1;
        for(int i=1; i<s.length(); i++) {
            max_len=max(max_len,curr_len);
            if(s[i]-s[i-1]==1) {
                curr_len++;
            } else {
                curr_len=1;
            }
        }
        return max(max_len,curr_len);
    }
};
