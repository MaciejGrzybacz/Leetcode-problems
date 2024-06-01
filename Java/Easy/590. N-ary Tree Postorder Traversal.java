// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

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
    public void postorderHelper(Node root) {
        if(root==null) {
            return;
        } else {
            for(Node child: root.children) {
                postorderHelper(child);
            }
            list.add(root.val);
        }
    }
    public List<Integer> postorder(Node root) {
        postorderHelper(root);
        return list;
    }
}