// https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result {0};
        if(n==0) {
            return result;
        }
        int curr_bit_count=0;
        for(int i=1; i<=n; i++) {
            curr_bit_count=result[i/2] + ((i % 2 == 0) ? 0 : 1);
            result.push_back(curr_bit_count);
        }
        return result;
    }
};