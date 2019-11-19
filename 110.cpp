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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int hleft = height(root->left);
        int hright = height(root->right);

        if (hleft == -1 || hright == -1) return false;
        if (hleft - hright == 1 || hright - hleft == 1 || hleft == hright) return true;
        return false; 
    }

    int height(TreeNode *node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;

        //if (node->left == NULL) return 1 + height(node->right);
        //if (node->right == NULL) return 1 + height(node->left);;
        
        int hleft = height(node->left);
        int hright = height(node->right);

        if (hleft == -1 || hright == -1) return -1;
        if (hleft - hright >= 2 || hright - hleft >= 2) return -1;
        return (hleft > hright ? hleft + 1 : hright + 1);
    }
};
