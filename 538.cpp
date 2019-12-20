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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) return root;
        if (root->right != NULL) {
            root->right = convertBST(root->right);
            TreeNode *node = root->right;
            while (node->left != NULL) node = node->left;
            root->val += node->val;
        }
        if (root->left != NULL) {
            TreeNode *node = root->left;
            while (node->right != NULL) node = node->right;
            node->val += root->val;
            root->left = convertBST(root->left);
        }
        return root;  
    }
};
