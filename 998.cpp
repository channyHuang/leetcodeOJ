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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if (val > root->val) {
            node->left = root;
            return node;
        }
        TreeNode *curNode = root;
        while (1) {
            if (curNode->right == NULL) {
                curNode->right = node;
                break;
            }
            if (curNode->right->val < val) {
                node->left = curNode->right;
                curNode->right = node;
                break;
            }
            curNode = curNode->right;
        }
        return root;
    }
};
