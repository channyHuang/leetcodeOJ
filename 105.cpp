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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return build(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int stPre, int endPre, int stIn, int endIn) {
        if (stPre > endPre) return NULL;
        TreeNode *root = new TreeNode(preorder[stPre]);
        int idx = stIn;
        while (inorder[idx] != preorder[stPre]) idx++;
        root->left = build(preorder, inorder, stPre + 1, stPre + idx - stIn, stIn, idx - 1);
        root->right = build(preorder, inorder, endPre - (endIn - idx) + 1, endPre, idx + 1, endIn);
        return root;
    }
};
