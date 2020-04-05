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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        for (int i = 0; i < left.size(); i++) {
            res.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            res.push_back(right[i]);
        }
        res.push_back(root->val);
        return res;
    }
};
