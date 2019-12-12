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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        if (root == NULL) return res;
        if (root->val >= L && root->val <=R) {
            res += root->val;
            res += rangeSumBST(root->left, L, R);
            res += rangeSumBST(root->right, L, R);
        }
        else if (root->val > R) res += rangeSumBST(root->left, L, R);
        else res += rangeSumBST(root->right, L, R);
        return res;
    }
};
