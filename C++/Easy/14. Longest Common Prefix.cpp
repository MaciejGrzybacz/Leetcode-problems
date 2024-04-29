// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    bool same_letter(vector<string>& strs, size_t i) {
        char c=strs[0][i];
        for(auto str: strs) {
            if (str[i]!=c) {
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        size_t min_len=strs[0].length();
        for(auto str : strs) {
            min_len=std::min(min_len, str.length());
        }
        string result="";
        if(min_len==0) {
            return result;
        }
        for(size_t i=0; i<min_len; i++) {
            if(same_letter(strs,i)) {
                result+=strs[0][i];
            }
            else{
                break;
            }
        }
        return result;
    }
};