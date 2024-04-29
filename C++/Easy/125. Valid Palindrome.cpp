// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() < 2) {
            return true;
        }
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
        int n = s.length();

        for(int i = 0; i < n/2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
