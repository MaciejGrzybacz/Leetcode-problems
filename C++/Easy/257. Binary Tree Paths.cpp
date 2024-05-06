// https://leetcode.com/problems/binary-tree-paths/description/

class Solution {
public:
    void binaryTreePathsHelper(TreeNode* root, vector<string>& paths, string actual_path) {
        if (!root) {
            return;
        }
        
        actual_path += to_string(root->val);
        
        if (!root->left && !root->right) {
            paths.push_back(actual_path);
        } else {
            actual_path += "->";
            binaryTreePathsHelper(root->left, paths, actual_path);
            binaryTreePathsHelper(root->right, paths, actual_path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        binaryTreePathsHelper(root, paths, "");
        return paths;
    }
};
