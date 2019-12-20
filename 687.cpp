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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        if (root->left == NULL) return max(longestRoot(root) - 1, longestUnivaluePath(root->right));
        if (root->right == NULL) return max(longestRoot(root) - 1, longestUnivaluePath(root->left));
        int left = 0, right = 0;
        if (root->val == root->left->val) left = longestRoot(root->left);
        if (root->val == root->right->val) right = longestRoot(root->right);
        int res = left + right;
        res = max(res, longestUnivaluePath(root->left));
        res = max(res, longestUnivaluePath(root->right));
        return res;
    }

    int longestRoot(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL) {
            if (root->right->val != root->val) return 1;
            return 1 + longestRoot(root->right);
        }
        if (root->right == NULL) {
            if (root->left->val != root->val) return 1;
            return 1 + longestRoot(root->left);
        }
        if (root->left->val != root->val && root->right->val != root->val) return 1;
        if (root->left->val != root->val) return 1 + longestRoot(root->right);
        if (root->right->val != root->val) return 1 + longestRoot(root->left);
        int left = longestRoot(root->left);
        int right = longestRoot(root->right);
        return left >= right ? 1 + left : 1 + right;
    }
};
