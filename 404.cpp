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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return sumOfLeftLeaves(root->right);
        int res = 0;
        if (root->left->left == NULL && root->left->right == NULL) res = root->left->val;
        else res = sumOfLeftLeaves(root->left);
        return  res + sumOfLeftLeaves(root->right);
    }
};
