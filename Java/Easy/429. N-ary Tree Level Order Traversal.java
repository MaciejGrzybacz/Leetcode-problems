// https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levels=new ArrayList();
    public void helper(Node root, int level) {
        if(root==null) {
            return;
        } else {
            if(level==levels.size()) {
                levels.add(new ArrayList<Integer>());
            }
            levels.get(level).add(root.val);
            for(Node child: root.children) {
                helper(child, level+1);
            }
        }
    }
    public List<List<Integer>> levelOrder(Node root) {
        helper(root,0);
        return levels;
    }
}