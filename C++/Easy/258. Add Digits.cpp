// https://leetcode.com/problems/add-digits/description/

class Solution {
public:
    int makeSum(int n) {
        int result=0;
        while(n>0) {
            result+=(n%10);
            n/=10;
        }
        return result;
    }
    int addDigits(int num) {
        while(num>9) {
            num=makeSum(num);
        }
        return num;
    }
};
