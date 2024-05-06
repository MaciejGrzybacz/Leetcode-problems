// https://leetcode.com/problems/single-number-ii/description/

class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            twos |= ones & num;
            ones ^= num;
            int commonBitMask = ~(ones & twos);
            ones &= commonBitMask;
            twos &= commonBitMask;
        }
        return ones;
    }
}
