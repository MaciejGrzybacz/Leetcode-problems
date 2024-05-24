// https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string helper(string s) {
        string result="";
        int count=1;
        char curr_num=s[0];
        s+=" ";
        for(int i=0; i<s.length()-1; i++) {
            if(s[i]==s[i+1]) {
                count++;
            } else {
                result+=to_string(count);
                result+=curr_num;
                count=1;
                curr_num=s[i+1];
            }
        }
        return result;
    }
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        string result=countAndSay(n-1);
        return helper(result);
    }
};