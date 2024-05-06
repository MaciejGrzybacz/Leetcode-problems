// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Convert nums to unordered_set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};