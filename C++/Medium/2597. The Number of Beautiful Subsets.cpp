// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

class Solution {
public:
    Solution() : cnt(1001, 0) {}
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        backtrack(nums,0, k);
        return count-1;
    }

private:
    vector<int> cnt;
    int count = 0;

    void backtrack(vector<int>& nums, int index, int k) {
        if (index == nums.size()) {
            count++;
            return;
        }
        
        backtrack(nums, index + 1, k);

        int x = nums[index];
        bool can_include = true;
        if (x - k >= 0 && cnt[x - k] > 0) {
            can_include = false;
        }
        if (x + k <= 1000 && cnt[x + k] > 0) {
            can_include = false;
        }

        if (can_include) {
            cnt[x]++;
            backtrack(nums, index + 1, k);
            cnt[x]--;
        }
    }
};