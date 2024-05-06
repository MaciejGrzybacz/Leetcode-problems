// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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
    void calculateSums(TreeNode* root, int level, vector<long long>& sums) {
        if (!root) return;
        if (level >= sums.size()) sums.resize(level + 1);
        sums[level] += root->val;
        calculateSums(root->left, level + 1, sums);
        calculateSums(root->right, level + 1, sums);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        calculateSums(root, 0, sums);
        sort(sums.begin(), sums.end(), greater<long long>());
        return (sums.size() >= k) ? sums[k - 1] : -1;
    }
};

