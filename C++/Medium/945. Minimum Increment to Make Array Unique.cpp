// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int i = 1; i<nums.size(); i++) {
            if(nums[i-1] >= nums[i]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                count += increment;
            }
        }

        return count;
    }
};