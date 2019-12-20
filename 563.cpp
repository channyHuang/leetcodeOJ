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
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        add(root);
        return count(root);
    }

    int count(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        int left = count(root->left);
        int right  = count(root->right);
        int res = left + right;
        if (root->left == NULL) res += (root->right->val >= 0 ? root->right->val : -root->right->val);
        else if (root->right == NULL) res += (root->left->val >= 0 ? root->left->val : -root->left->val);
        else res += (root->left->val >= root->right->val ? root->left->val - root->right->val : root->right->val - root->left->val);
        return res;
    }

    void add(TreeNode *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        add(root->left);
        add(root->right);
        if (root->left != NULL) root->val += root->left->val;
        if (root->right != NULL) root->val += root->right->val;
    }
};
