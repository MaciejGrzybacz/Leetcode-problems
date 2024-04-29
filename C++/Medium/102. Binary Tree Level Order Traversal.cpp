// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    std::vector<TreeNode*> add_level(const std::vector<TreeNode*>& prev) {
        std::vector<TreeNode*> curr;
        for(auto node: prev) {
            if(node->left) {
                curr.push_back(node->left);
            }
            if(node->right) {
                curr.push_back(node->right);
            }
        }
        return curr;
    }

    std::vector<int> to_nums(const std::vector<TreeNode*>& nodes) {
        std::vector<int> result;
        for(auto node: nodes) {
            result.push_back(node->val);
        }
        return result;
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::vector<TreeNode*> prev;
        if(!root) {
            return result;
        }
        prev.push_back(root);
        while(!prev.empty()) {
            result.push_back(to_nums(prev));
            prev = add_level(prev);
        }
        return result;
    }
};