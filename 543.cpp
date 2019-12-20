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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        int res = leftdepth + rightdepth;
        int tmp = diameterOfBinaryTree(root->left);
        if (res < tmp) res = tmp;
        tmp = diameterOfBinaryTree(root->right);
        if (res < tmp) res = tmp;
        return res;
    }

    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL) return 1 + maxDepth(root->right);
        if (root->right == NULL) return 1 + maxDepth(root->left);
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
