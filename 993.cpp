/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;
        int depth[105] = {0};
        int parent[105] = {0};
        depth[root->val] = 1;
        parent[root->val] = -1;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (node->left != NULL) {
                depth[node->left->val] = depth[node->val] + 1;
                parent[node->left->val] = node->val;
                st.push(node->left);
            }
            if (node->right != NULL) {
                depth[node->right->val] = depth[node->val] + 1;
                parent[node->right->val] = node->val;
                st.push(node->right);
            }
            if (depth[x] != 0 && depth[y] != 0) {
                if (depth[x] != depth[y]) return false;
                else if (parent[x] == parent[y]) return false;
                return true;
            }
        } 
        return false;
    }
};
