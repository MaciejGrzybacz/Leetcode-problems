// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calculateSums(TreeNode* root, int level, vector<int>& sums) {
        if (!root) return;
        if (level >= sums.size()) sums.resize(level + 1);
        sums[level] += root->val;
        calculateSums(root->left, level + 1, sums);
        calculateSums(root->right, level + 1, sums);
    }
    
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        calculateSums(root, 0, sums);
        
        if (sums.empty()) return -1; 
        
        auto max_element_iterator = max_element(sums.begin(), sums.end());
        int max_val = *max_element_iterator;
        int i = 0;
        while (sums[i] != max_val) {
            i++;
        }
        return i + 1;
    }
};