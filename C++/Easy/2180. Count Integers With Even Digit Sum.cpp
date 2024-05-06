// https://leetcode.com/problems/count-integers-with-even-digit-sum/description/

class Solution {
public:
    int checkIfEven(int n) {
        int digit_count=0;
        while(n>0) {
            digit_count+=(n%10);
            n/=10;
        }
        return (digit_count+1)%2; //returns 1 if number is even, 0 otherwise
    }
    int countEven(int num) {
        int count=0;
        for(int i=1; i<=num; i++) {
            count+=checkIfEven(i);
        }
        return count;
    }
};