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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) return NULL;
        return remove(root, target);
    }

    TreeNode *remove(TreeNode *root, int target) {
        if (root == NULL) return NULL;
        
        if (root->left != NULL) root->left = remove(root->left, target);
        if (root->right != NULL) root->right = remove(root->right, target);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == target) return NULL;
            else return root;
        }
        return root;
    }
};
