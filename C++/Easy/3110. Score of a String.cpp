// https://leetcode.com/problems/score-of-a-string/description/

#include <cmath>

class Solution {
public:
    int scoreOfString(string s) {
        int result=0;
        for(int i=1; i<s.length(); i++) {
            result+=abs(static_cast<int>(s[i])-static_cast<int>(s[i-1]));
        }
        return result;
    }
};