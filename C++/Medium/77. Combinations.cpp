// https://leetcode.com/problems/combinations/description/

class Solution {
public:
    void backtrack( vector<vector<int>>& result, vector<int>& curr, int n, int k, int curr_index){
        if(curr.size()==k) {
            result.push_back(curr);
            return;
        }
        for(int i=curr_index; i<=n; i++) {
            curr.push_back(i);
            backtrack(result,curr,n,k,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result,current,n,k,1);
        return result;
    }
};