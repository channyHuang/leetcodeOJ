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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (same(s, t)) return true;
        if (isSubtree(s->left, t)) return true;
        if (isSubtree(s->right, t)) return true;
        return false;
    }

    bool same(TreeNode *a, TreeNode *b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;
        if (a->val != b->val) return false;
        return (same(a->left, b->left) && same(a->right, b->right));
    }
};
