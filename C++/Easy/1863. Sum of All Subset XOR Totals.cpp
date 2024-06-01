// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int mask = pow(2, n) - 1; mask > 0; mask--) {
            int tmpResult = 0;
            int tmp = mask;

            for (int i = 0; i < n; i++) {
                if (tmp % 2 == 1) {
                    tmpResult ^= nums[i];
                }
                tmp /= 2;
            }

            result += tmpResult;
        }

        return result;
    }
};