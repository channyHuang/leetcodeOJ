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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        bool flag = true;
        if (root->left != NULL) {
            if (root->left->val >= root->val) return false;
            TreeNode *node = root->left;
            while (node->right != NULL) node = node->right;
            if (node->val >= root->val) return false;
            flag = isValidBST(root->left);
            if (!flag) return false;
        }
        if (root->right != NULL) {
            if (root->right->val <= root->val) return false;
            TreeNode *node = root->right;
            while (node->left != NULL) node = node->left;
            if (node->val <= root->val) return false;
            flag = isValidBST(root->right);
        }
        return flag;
    }
};
