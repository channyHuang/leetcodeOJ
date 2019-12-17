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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curNode = root;
        if (curNode->val == p->val || curNode->val == q->val) return curNode;
        if (curNode->val > p->val) {
            if (curNode->val > q->val) {
                return lowestCommonAncestor(curNode->left, p, q);
            } else return curNode;
        } else {
            if (curNode->val < q->val) {
                return lowestCommonAncestor(curNode->right, p, q);
            } else return curNode;
        }
        return curNode;
    }
};
