// https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> current_permutation;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, current_permutation, used, permutations);
        return permutations;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& current_permutation, vector<bool>& used, vector<vector<int>>& permutations) {
        if (current_permutation.size() == nums.size()) {
            permutations.push_back(current_permutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }

            used[i] = true;
            current_permutation.push_back(nums[i]);
            backtrack(nums, current_permutation, used, permutations);
            current_permutation.pop_back();
            used[i] = false;
        }
    }
};