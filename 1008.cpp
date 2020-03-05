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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        if (len <= 0) return NULL;
        if (len == 1) return new TreeNode(preorder[0]);
        return bst(preorder, 0, len - 1);
    }

    TreeNode *bst(vector<int>& preorder, int st, int end) {
        if (st > end) return NULL;
        TreeNode *root = new TreeNode(preorder[st]);
        if (st == end) return root;
        int pos = st + 1;
        while (pos < preorder.size() && preorder[pos] <= preorder[st]) pos++;
        root->left = bst(preorder, st + 1, pos - 1);
        root->right = bst(preorder, pos, end);
        return root;
    }
};
