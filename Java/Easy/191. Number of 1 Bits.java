// https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
    public int hammingWeight(int n) {
        int bit_count=0;
        while(n>0) {
            bit_count+=(n%2);
            n/=2;
        }
        return bit_count;
    }
}

