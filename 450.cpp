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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->right) {
            TreeNode *node = root->right;
            while (node->left != NULL) {
                node = node->left;
            }
            node->left = root->left;
            root->left = NULL;
            root = root->right;
        } else {
            root = root->left;
        }
        return deleteNode(root, key);
    }


};
