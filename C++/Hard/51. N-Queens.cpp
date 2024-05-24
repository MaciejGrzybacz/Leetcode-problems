// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<string> convert(vector<pair<int, int>> positions) {
        int n = positions.size();
        vector<string> board(n, string(n, '.')); 
        for (const auto& pos : positions) {
            int row = pos.first;
            int col = pos.second;
            board[row][col] = 'Q'; 
        }
        return board;
    }
    bool verify(vector<pair<int, int>>& positions) {
        int n = positions.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (positions[i].first == positions[j].first || positions[i].second == positions[j].second) {
                    return false;
                }
                if (abs(positions[i].first - positions[j].first) == abs(positions[i].second - positions[j].second)) {
                    return false;
                }
            }
        }
        return true;
    }
    void backtracking(vector<vector<pair<int, int>>>& valid,vector<pair<int, int>>& current, int index,  int n) {
        if(index==n) {
            valid.push_back(current);
            return;
        }
        for(int i = 0; i < n; i++) {
            current.push_back(make_pair(index, i));
            if(verify(current)) {
                backtracking(valid,current, index+1, n);
            }
            current.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> valid;
        vector<pair<int, int>> current;
        backtracking(valid,current,0,n);
        vector<vector<string>> result;
        for(auto board: valid) {
            result.push_back(convert(board));
        }
        return result;
    }
};