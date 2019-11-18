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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetricTree(root->left, root->right);
    }

    bool isSymmetricTree(TreeNode *a, TreeNode *b) {
        if (a == NULL) {
            if (b == NULL) return true;
            else return false;
        } else if (b == NULL) return false;
        else {
            if (a->val != b->val) return false;
            return (isSymmetricTree(a->left, b->right) && isSymmetricTree(a->right, b->left));
        }
    }

    bool isSameTree(TreeNode *a, TreeNode *b) {
        if (a == NULL) {
            if (b == NULL) return true;
            else return false;
        } else if (b == NULL) return false;
        else {
            if (a->val != b->val) return false;
            return (isSameTree(a->left, b->left) && isSameTree(a->right, b->right));
        }
    }
};
