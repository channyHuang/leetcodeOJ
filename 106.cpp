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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inlen = inorder.size();
        int postlen = postorder.size();
        return buildSubTree(inorder, postorder, 0, inlen - 1, 0, postlen - 1);
    }

    TreeNode *buildSubTree(vector<int>& inorder, vector<int>& postorder, int inst, int inend, int postst, int postend) {
        if (inend < inst || postend < postst) return NULL;
        TreeNode *root = new TreeNode(postorder[postend]);
        int i;
        for (i = inst; i <= inend; i++) {
            if (inorder[i] == postorder[postend]) break;
        }
        root->left = buildSubTree(inorder, postorder, inst, i - 1, postst, postst + i - 1 - inst);
        root->right = buildSubTree(inorder, postorder, i + 1, inend, postst + i - 1 - inst + 1, postend - 1);
        return root;
    }
};
