// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
private:
    void backtrack(vector<int>& candidates,  vector<vector<int>>& combinations, vector<int>& current, int index, int target) {
        if(target == 0) {
            combinations.push_back(current);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if(candidates[i] > target) {
                break; 
            }

            current.push_back(candidates[i]);
            backtrack(candidates, combinations, current, i + 1, target - candidates[i]);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> curr_combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, combinations, curr_combination, 0, target);
        return combinations;
    }
};