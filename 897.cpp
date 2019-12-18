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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) return NULL;
        return leftToRoot(root);
    }

    TreeNode *leftToRoot(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root->left == NULL) {
            root->right = leftToRoot(root->right);
            return root;
        }
        root->left = leftToRoot(root->left);
        root->right = leftToRoot(root->right);
        TreeNode *newRoot = root->left;
        TreeNode *curNode = newRoot;
        while (curNode->right != NULL) curNode = curNode->right;
        curNode->right = root;
        root->left = NULL;
        return newRoot;
    }
};
