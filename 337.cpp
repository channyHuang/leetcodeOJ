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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        
        //rob root
        int hasroot = root->val;
        if (root->left) {
            hasroot += rob(root->left->left);
            hasroot += rob(root->left->right);
        }
        if (root->right) {
            hasroot += rob(root->right->left);
            hasroot += rob(root->right->right);
        }
        //do not rob root
        int noroot = rob(root->left) + rob(root->right);
        return (hasroot > noroot ? hasroot : noroot);
    }
};
