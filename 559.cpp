/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int res = 1;
        int len = root->children.size();
        for (int i = 0; i < len; i++) {
            int sublen = maxDepth(root->children[i]);
            if (res < sublen + 1) res = sublen + 1;
        }
        return res;
    }
};
