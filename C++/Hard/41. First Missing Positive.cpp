// https://leetcode.com/problems/first-missing-positive/description/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return (nums[0] == 1) ? 2 : 1;
        }
        int pivot = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] < n) {
                pivot = nums[i];
                break;
            }
        }
        // We didn't find any number in <1,n>, so we can return 1.
        if (pivot == 0) {
            return 1;   
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = pivot;
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]) - 1;
            if (nums[num] > 0) {
                nums[num] *= -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

