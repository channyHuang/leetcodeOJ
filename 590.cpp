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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node *curNode = st.top();
            st.pop();
            res.push_back(curNode->val);
            for (int i = 0; i < curNode->children.size(); i++) {
                st.push(curNode->children[i]);
            }
        }
        int len = res.size();
        for (int i = 0; i < len / 2; i++) {
            int tmp = res[i];
            res[i] = res[len - i - 1];
            res[len - i - 1] = tmp;
        }
        return res;
    }
};
