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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }

    void inorder(vector<int>& vec, TreeNode *node) {
        if (node == NULL) return;
        inorder(vec, node->left);
        vec.push_back(node->val);
        inorder(vec, node->right);

    }
};
