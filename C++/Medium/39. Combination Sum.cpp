// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void generateMultisets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int index, int target) {
        if (target == 0) {
            result.push_back(subset);
        } 
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] <= target) {
                subset.push_back(nums[i]);
                generateMultisets(nums, subset, result, i, target - nums[i]);
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> result;
        generateMultisets(candidates, subset, result, 0, target);
        return result;
    }
};
