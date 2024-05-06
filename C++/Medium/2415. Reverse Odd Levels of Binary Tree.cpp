// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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
    void invertTree(TreeNode* left, TreeNode* right, int level) {
        if (!left) {
            return;
        }
        if (level % 2 == 0) {
             swap(left->val, right->val);
        }
        invertTree(left->left, right->right, level + 1);
        invertTree(left->right, right->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        invertTree(root->left,root->right,2);
        return root;
    }
};