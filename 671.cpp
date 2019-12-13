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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) return -1;
        if (root->left == NULL) return -1;
        if (root->left->val != root->val && root->right->val != root->val) return min(root->left->val, root->right->val);
        int left, right;
        if (root->left->val != root->val) {
            left = root->left->val;
            right = findSecondMinimumValue(root->right);
            if (right == -1) return left;
            return min(left, right);
        }
        if (root->right->val != root->val) {
            left = findSecondMinimumValue(root->left);
            right = root->right->val;
            if (left == -1) return right;
            return min(left, right);
        }
        if (root->left->val == root->val && root->right->val == root->val) {
            left = findSecondMinimumValue(root->left);
            right = findSecondMinimumValue(root->right);
            if (left == -1) return right;
            if (right == -1) return left;
            return min(left, right);
        }
        return -1;
    }
};
