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
    int maxAncestorDiff(TreeNode* root) {
        vector<TreeNode *> path;
        path.resize(5005);
        path[0] = root;
        search(root, path, 0, root->val, root->val);
        return res;
    }

    void search(TreeNode *root, vector<TreeNode *> path, int pos, int maxn, int minn) {
        if (root == NULL) return;
        if (root->left) {
            if (abs(root->left->val - maxn) > res) res = abs(root->left->val - maxn);
            if (abs(root->left->val - minn) > res) res = abs(root->left->val - minn);
            path[pos + 1] = root->left;
            search(root->left, path, pos + 1, max(maxn, root->left->val), min(minn, root->left->val));
        }
        if (root->right) {
            if (abs(root->right->val - maxn) > res) res = abs(root->right->val - maxn);
            if (abs(root->right->val - minn) > res) res = abs(root->right->val - minn);
            path[pos + 1] = root->right;
            search(root->right, path, pos + 1, max(maxn, root->right->val), min(minn, root->right->val));
        }
    }

private:
    map<double, int> maps;
    int res;
};
