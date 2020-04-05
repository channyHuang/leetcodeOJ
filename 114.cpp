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
    void flatten(TreeNode* root) {
        TreeNode *curNode = root;
        while (curNode) {
            if (curNode->left) {
                TreeNode *nextNode = curNode->left;
                while (nextNode->right) nextNode = nextNode->right;
                nextNode->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = NULL;
            }
            curNode = curNode->right;
        }
        //return root;
    }
};
