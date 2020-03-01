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
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL) return NULL;
        if (root->right) {
            bstToGst(root->right);
            TreeNode *node = root->right;
            while (node->left) node = node->left;
            root->val += node->val;
        }
        if (root->left == NULL) return root;
        {
            TreeNode *node = root->left;
            while (node->right) node = node->right;
            node->val += root->val;
            bstToGst(root->left);  
        }     
        return root; 
    }
};
