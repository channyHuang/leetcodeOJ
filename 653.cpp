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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        return find(root, root, k);
    }

    bool find(TreeNode *node, TreeNode *root, int k) {
        if (node == NULL) return false;
        int t = k - node->val;
        if (findOne(root, t) != NULL && findOne(root, t) != node) return true;
        if (find(node->left, root, k)) return true;
        if (find(node->right, root, k)) return true;
        return false;
    }

    TreeNode* findOne(TreeNode *root, int t) {
        if (root == NULL) return NULL;
        if (root->val == t) return root;
        else if (root->val > t) return findOne(root->left, t);
        return findOne(root->right, t);
    }
};
