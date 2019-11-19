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
    }
}

 /*
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return (root->val == sum ? 1 : 0);
        
        if (root->val == sum) return 1 + pathSumCont(root->left, 0) + pathSumCont(root->right, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
        else return pathSumCont(root->left, sum - root->val) + pathSumCont(root->right, sum - root->val) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathSumCont(TreeNode *root, int sum) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return (root->val == sum ? 1 : 0);

        if (root->val == sum) return 1 + pathSum(root->left, 0) + pathSum(root->right, 0);
        return pathSumCont(root->left, sum - root->val) + pathSumCont(root->right, sum - root->val);
    }
};
 */
