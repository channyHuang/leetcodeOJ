/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        search(root, cnt, -100000);
        return cnt;
    }

    void search(TreeNode *root, int &cnt, int curMax) {
        if (root == nullptr) return;
        if (root->val >= curMax) cnt++;
        curMax = max(root->val, curMax);
        search(root->left, cnt, curMax);
        search(root->right, cnt, curMax);
    }
};
