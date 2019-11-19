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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else if (root->left == NULL && root->right == NULL) return 1;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth == 0) return rightDepth + 1;
        else if (rightDepth == 0) return leftDepth + 1;
        else return (leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1);
    }
};
