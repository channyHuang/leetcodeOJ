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
    int sum;

    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *root, int val) {
        if (root == NULL) return;
        val = val * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += val;
        }
        
        dfs(root->left, val);
        dfs(root->right, val);
    }
};
