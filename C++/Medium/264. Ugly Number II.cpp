// https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> ugly_nums;
        ugly_nums.push_back(1);
        int two_pow = 0;
        int three_pow = 0;
        int five_pow = 0;
        for (int i = 0; i < n - 1; i++) {
            int next_ugly = std::min({ugly_nums[two_pow] * 2, ugly_nums[three_pow] * 3, ugly_nums[five_pow] * 5});
            ugly_nums.push_back(next_ugly);
            if (next_ugly == ugly_nums[two_pow] * 2) {
                two_pow += 1;
            }
            if (next_ugly == ugly_nums[three_pow] * 3) {
                three_pow += 1;
            }
            if (next_ugly == ugly_nums[five_pow] * 5) {
                five_pow += 1;
            }
        }
        return ugly_nums[n - 1];
    }
};