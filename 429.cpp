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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<Node *> vec;
        vec.push_back(root);
        {
            vector<int> subres;
            subres.push_back(root->val);
            res.push_back(subres);
        }
        int curPos = 0;
        int nextLevel = 1;
        while (curPos != vec.size()) {
            Node *node = vec[curPos];
            if (curPos == nextLevel) {
                vector<int> subres;
                for (int i = curPos; i < vec.size(); i++) {
                    subres.push_back(vec[i]->val);
                }
                res.push_back(subres);
                nextLevel = vec.size();
            }
            for (int i = 0; i < node->children.size(); i++) {
                vec.push_back(node->children[i]);
            }
            curPos++;
        }
        return res;
    }
};
