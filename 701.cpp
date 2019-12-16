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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode *curNode = root;
        while (1) {
            if (curNode->val > val) {
                //left
                if (curNode->left == NULL) {
                    curNode->left = new TreeNode(val);
                    break;
                } else curNode = curNode->left;
            } else {
                //right
                if (curNode->right == NULL) {
                    curNode->right = new TreeNode(val);
                    break;
                } else curNode = curNode->right;
            }
        }
        return root;
    }
};
