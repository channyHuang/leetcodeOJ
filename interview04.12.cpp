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
        if (root ==  nullptr) return 0;
        int res = 0;

        res += pathSumRoot(root, sum);
        if (root->left != nullptr) {
            res += pathSum(root->left, sum); 
        }
        if (root->right != nullptr) {
            res += pathSum(root->right, sum);
        }
        return res;
    }

    int pathSumRoot(TreeNode* root, int sum) {
        if (root ==  nullptr) return 0;
        int res = 0;
        if (root->val == sum) {
            res = 1;
        }
        res += pathSumRoot(root->left, sum - root->val) + pathSumRoot(root->right, sum - root->val);
        return res;
    }
};

