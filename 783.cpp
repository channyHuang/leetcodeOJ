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
    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        int res = 0, tmp = 0;
        if (root->right != NULL) {
            TreeNode *node = root->right;
            while (node->left) node = node->left;
            if (res == 0) res = abs(root->val, node->val);
            else res = min(res, abs(root->val, node->val));
            tmp = minDiffInBST(root->right);
            if (tmp != 0 && res > tmp) res = tmp;
        }
        if (root->left != NULL) {
            TreeNode *node = root->left;
            while (node->right) node = node->right;
            if (res == 0) res = abs(root->val, node->val);
            else res = min(res, abs(root->val, node->val));
            tmp = minDiffInBST(root->left);
            if (tmp != 0 && res > tmp) res = tmp;
        }
        return res;
    }

    int abs(int a, int b) {
        return (a >= b ? a - b : b - a);
    }
};
