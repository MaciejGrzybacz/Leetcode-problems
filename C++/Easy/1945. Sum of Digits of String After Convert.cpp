// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

class Solution {
public:
    int makeSum(int n) {
        int result = 0;
        while (n > 0) {
            result += (n % 10);
            n /= 10;
        }
        return result;
    }
    
    int getLucky(string s, int k) {
        int result = 0;
        for (char c : s) {
            int val = (c - 'a' + 1);
            result += val<10 ? val : (val%10 + val/10);
        }
        
        for (int i = 0; i < k-1; i++) {
            result = makeSum(result); 
        }
        
        return result;
    }
};