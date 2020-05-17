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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool del = search(root, limit, root->val);
        if (del) return NULL;
        return root;
    }

    bool search(TreeNode *root, int limit, int curSum) {
        bool isLeaf = true;
        bool delleft = false, delright = false;
        if (root->left != NULL) {
            isLeaf = false;
            delleft = search(root->left, limit, curSum + root->left->val);
        } else delleft = true;
        if (root->right != NULL) {
            isLeaf = false;
            delright = search(root->right, limit, curSum + root->right->val);
        } else delright = true;

        if (isLeaf) {
            if (curSum < limit) return true;
            return false;
        }
        if (delleft && delright) return true;
        if (delleft) root->left = NULL;
        if (delright) root->right = NULL;
        return false;
    }
};
