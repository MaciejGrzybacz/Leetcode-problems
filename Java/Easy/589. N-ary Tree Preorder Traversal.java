// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

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
    public List<Integer> list = new ArrayList();
    public void preorderHelper(Node root) {
        if(root==null) {
            return;
        } else {
            list.add(root.val);
            for(Node child: root.children) {
                preorderHelper(child);
            }
        }
    }
    public List<Integer> preorder(Node root) {
        preorderHelper(root);
        return list;
    }
}