// https://leetcode.com/problems/base-7/description/

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) {
            return "0";
        }
        string result="";
        string signum="";
        if(num<0) {
            signum="-";
            num*=-1;
        }
        while(num) {
            result=to_string(num%7)+result;
            num/=7;
        }
        return signum+result;
    }
};