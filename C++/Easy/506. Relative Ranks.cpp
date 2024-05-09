// https://leetcode.com/problems/relative-ranks/description/


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> indices(score.size());
        for (int i = 0; i < score.size(); ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        
        unordered_map<int, string> rank_map = {
            {1, "Gold Medal"},
            {2, "Silver Medal"},
            {3, "Bronze Medal"}
        };
        for (int i = 3; i < score.size(); ++i) {
            rank_map[i + 1] = to_string(i + 1);
        }
        
        vector<string> result(score.size());
        for (int i = 0; i < score.size(); ++i) {
            result[indices[i]] = rank_map[i + 1];
        }
        
        return result;
    }
};