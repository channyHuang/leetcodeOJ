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
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;
        return sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right) + ((root->val & 1) ? 0 : sumGrandParent(root));
    }

    int sumGrandParent(TreeNode *root) {
        int res = 0;
        if (root->left) {
            if (root->left->left) res += root->left->left->val;
            if (root->left->right) res += root->left->right->val;
        }
        if (root->right) {
            if (root->right->left) res += root->right->left->val;
            if (root->right->right) res += root->right->right->val;
        }
        return res;
    }
};