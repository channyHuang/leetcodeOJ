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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathSumContainRoot(root, sum, true) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathSumContainRoot(TreeNode *root, int sum, bool containRoot = false) {
        if (root == NULL) return 0;
        if (containRoot) {
            if (root->val == sum) return 1 + pathSumContainRoot(root->left, 0, true) + pathSumContainRoot(root->right, 0, true);
            else return pathSumContainRoot(root->left, sum - root->val, true) + pathSumContainRoot(root->right, sum - root->val, true);
        }
        if (root->val == sum) {
            return 1 + pathSumContainRoot(root->left, 0) + pathSumContainRoot(root->right, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
        } else {
            return pathSumContainRoot(root->left, sum - root->val, true) + pathSumContainRoot(root->right, sum - root->val, true) 
            + pathSum(root->left, sum) + pathSum(root->right, sum);
        }
    }
};
