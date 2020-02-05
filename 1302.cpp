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
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0;
        int maxdeep = 1;
        deepSum(root, 1, sum, maxdeep);
        return sum;
    }

    void deepSum(TreeNode *root, int level, int &sum, int &maxdeep) {
        if (root->left == NULL && root->right == NULL) {
            if (maxdeep == level) sum += root->val;
            else if (maxdeep < level) {
                sum = root->val;
                maxdeep = level;
            }
            return;
        }
        if (root->left) {
            deepSum(root->left, level + 1, sum, maxdeep);
        }
        if (root->right) {
            deepSum(root->right, level + 1, sum, maxdeep);
        }
    }
};