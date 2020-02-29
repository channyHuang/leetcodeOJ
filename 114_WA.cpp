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
            if (curNode->right) {
                TreeNode *nextNode = curNode;
                while (nextNode->left) nextNode = nextNode->left;
                nextNode->left = curNode->right;
                curNode->right = NULL;
            }
            curNode = curNode->left;
        }
        //return root;
    }
};
