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
    int res;

    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        res = 0;
        search(root, 0);
        return res;
    }

    void search(TreeNode *root, int curnum) {
        if (root == NULL) return;
        curnum <<= 1;
        curnum += root->val;
        if (root->left == NULL && root->right == NULL) {
            res += curnum;
            return;
        }
        if (root->left != NULL) {
            search(root->left, curnum);
        }
        if (root->right != NULL) {
            search(root->right, curnum);
        }
    }
};
