// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> d;
        int n = nums.size();
        int left = 0, right = 0;
        int max_len = 0;

        while (right < n) {
            d[nums[right]]++;
            int curr_min = d.begin()->first;
            int curr_max = d.rbegin()->first;
            
            while (curr_max - curr_min > limit) {
                d[nums[left]]--;
                if (d[nums[left]] == 0) {
                    d.erase(nums[left]);
                }
                left++;
                if (!d.empty()) {
                    curr_min = d.begin()->first;
                    curr_max = d.rbegin()->first;
                }
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};